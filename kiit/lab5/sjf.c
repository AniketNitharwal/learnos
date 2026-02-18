#include <stdio.h>

struct process {
    int pid;
    int burst;
    int waiting;
    int turnaround;
};

int main() {
    int n, i, j;
    struct process p[10], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    // Sorting by burst time (SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].burst > p[j].burst) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting = 0;
    for (i = 1; i < n; i++) {
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    printf("\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].burst,
               p[i].waiting, p[i].turnaround);
    }

    return 0;
}

