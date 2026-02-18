#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int burst;
    int waiting;
    int turnaround;
    struct process *next;
};

int main() {
    int n, i;
    struct process *head = NULL, *temp = NULL, *newnode = NULL;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        newnode = (struct process *)malloc(sizeof(struct process));

        newnode->pid = i;
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &newnode->burst);

        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    int time = 0;
    temp = head;

    while (temp != NULL) {
        temp->waiting = time;
        temp->turnaround = temp->waiting + temp->burst;
        time += temp->burst;
        temp = temp->next;
    }

    printf("\nPID\tBT\tWT\tTAT\n");
    temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\t%d\n",
               temp->pid, temp->burst,
               temp->waiting, temp->turnaround);
        temp = temp->next;
    }

    return 0;
}

