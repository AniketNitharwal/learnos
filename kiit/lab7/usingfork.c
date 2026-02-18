#include <stdio.h>
#include <unistd.h>
int main () {
int pid = fork ();
if ( pid == 0) {
printf (" This ␣is␣ Child ␣ Process \n");
} else if (pid > 0) {
printf (" This ␣is␣ Parent ␣ Process \n");
} else {
printf (" Fork ␣ Failed \n");
}
return 0;
}
