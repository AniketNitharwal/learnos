#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[50] = "Hello from Parent!";
    char read_msg[50];


    pipe(fd);


    pid = fork();

    if(pid > 0) {
        close(fd[0]);
        write(fd[1], write_msg, strlen(write_msg)+1);
        close(fd[1]);
    }
    else if(pid == 0) {

        close(fd[1]);
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}
