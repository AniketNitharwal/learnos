#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // Child Process
        printf("1. Hello from child\n");
    }
    else if (pid > 0) {
        // Parent Process waits for child
        wait(NULL);
        printf("2. Child has terminated\n");
    }
    else {
        printf("Fork failed\n");
    }

    return 0;
}
