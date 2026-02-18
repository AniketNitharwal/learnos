#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main () {
int pid = fork ();
if ( pid == 0) {
printf (" Child ␣ running \n");
} else {
wait ( NULL ); // parent waits
printf (" Parent ␣ running ␣ after ␣ child \n");
}
return 0;
}
