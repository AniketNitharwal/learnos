#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int read_count = 0;

void *reader(void *arg) {
    pthread_mutex_lock(&mutex);
    read_count++;
    printf("Reader %ld is reading\n", (long)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *writer(void *arg) {
    pthread_mutex_lock(&mutex);
    printf("Writer %ld is writing\n", (long)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&r1, NULL, reader, (void*)1);
    pthread_create(&r2, NULL, reader, (void*)2);
    pthread_create(&w1, NULL, writer, (void*)1);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}
