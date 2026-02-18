#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid1, pid2;


    pid1 = fork();

    if (pid1 == 0) {

        fork();
        fork();

        printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    }
    else {


        pid2 = fork();

        if (pid2 == 0) {


            fork();

            printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
        }
        else {

            wait(NULL);
            wait(NULL);

            printf("Parent Process ID: %d\n", getpid());
        }
    }

    return 0;
}
