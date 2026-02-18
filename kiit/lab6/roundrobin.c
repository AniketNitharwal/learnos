#include <stdio.h>

int main() {
    int n, i, tq, time = 0, done = 0;
    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                flag = 1;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    done++;
                }
            }
        }
        if (flag == 0)
            time++;
    }

    printf("\nPID AT BT CT TAT WT\n");
    for (i = 0; i < n; i++) {
        printf("P%d  %d  %d  %d  %d   %d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    float awt = 0, atat = 0;
    for (i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}
