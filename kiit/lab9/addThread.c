#include <stdio.h>
#include <pthread.h>

int arr[6] = {10, 20, 30, 40, 50, 60};
int sum1 = 0, sum2 = 0;

void *firstHalf(void *arg)
{
    for(int i = 0; i < 3; i++)
        sum1 += arr[i];

    printf("Sum of first half = %d\n", sum1);
}

void *secondHalf(void *arg)
{
    for(int i = 3; i < 6; i++)
        sum2 += arr[i];

    printf("Sum of second half = %d\n", sum2);
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, firstHalf, NULL);
    pthread_create(&t2, NULL, secondHalf, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    int total = sum1 + sum2;

    printf("Total Sum = %d\n", total);

    return 0;
}
