#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid, at, bt, rt, ct, tat, wt;
    struct process *next;
};

struct process *head = NULL;

void add(int id, int a, int b) {
    struct process *n;
    n = (struct process *)malloc(sizeof(struct process));
    n->pid = id;
    n->at = a;
    n->bt = b;
    n->rt = b;
    n->next = head;
    head = n;
}

struct process* shortest(int t) {
    struct process *p = head;
    struct process *s = NULL;
    int min = 9999;

    while (p != NULL) {
        if (p->at <= t && p->rt > 0 && p->rt < min) {
            min = p->rt;
            s = p;
        }
        p = p->next;
    }
    return s;
}

int main() {
    int n, i, time = 0, done = 0;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        int at, bt;
        printf("Enter arrival time and burst time of P%d: ", i);
        scanf("%d %d", &at, &bt);
        add(i, at, bt);
    }

    while (done < n) {
        struct process *p = shortest(time);

        if (p != NULL) {
            p->rt--;
            time++;

            if (p->rt == 0) {
                done++;
                p->ct = time;
                p->tat = p->ct - p->at;
                p->wt = p->tat - p->bt;
                awt += p->wt;
                atat += p->tat;
            }
        } else {
            time++;
        }
    }

    printf("\nPID AT BT CT TAT WT\n");
    struct process *t = head;
    while (t != NULL) {
        printf("%d  %d  %d  %d  %d   %d\n",
               t->pid, t->at, t->bt, t->ct, t->tat, t->wt);
        t = t->next;
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}
