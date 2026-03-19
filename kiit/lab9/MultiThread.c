#include <stdio.h>
#include <pthread.h>

int arr[] = {38,27,43,3,9,82,10};

typedef struct {
    int left;
    int right;
} Range;

void merge(int l, int m, int r)
{
    int i=l, j=m+1, k=0;
    int temp[100];

    while(i<=m && j<=r)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=m)
        temp[k++] = arr[i++];

    while(j<=r)
        temp[k++] = arr[j++];

    for(i=l, k=0; i<=r; i++, k++)
        arr[i] = temp[k];
}

void *mergeSort(void *arg)
{
    Range *range = (Range*)arg;
    int l = range->left;
    int r = range->right;

    if(l < r)
    {
        int m = (l+r)/2;

        pthread_t t1, t2;

        Range left = {l,m};
        Range right = {m+1,r};

        pthread_create(&t1,NULL,mergeSort,&left);
        pthread_create(&t2,NULL,mergeSort,&right);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        merge(l,m,r);
    }
}

int main()
{
    int n = 7;

    Range range = {0,n-1};

    pthread_t t;

    pthread_create(&t,NULL,mergeSort,&range);
    pthread_join(t,NULL);

    printf("Sorted Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
