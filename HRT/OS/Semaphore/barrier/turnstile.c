// C program to demonstrate working of Semaphores
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10
sem_t mutexStart, mutexEnd, barrier;

typedef struct ThreadInfo {
    int programCounter;
    int threadIndex;
} ThreadInfo;

int getSemValue(sem_t *mutex) {
    int semValue = -1e9;
    sem_getvalue(mutex, &semValue);
    return semValue;
}

int counter = 0;
int mutexStartCounter = 0;
int mutexEndCounter = 0;

void *thread(void *arg) {
    ThreadInfo *info = (ThreadInfo *)arg;
    // int info = (int)arg;
    int currThread = info->threadIndex;
    int currProcessNo = info->programCounter;

    printf("Rendezvous thread: %d Process Num: %d\n", currThread,
           currProcessNo);

    sem_wait(&mutexStart);
    mutexStartCounter = mutexStartCounter + 1;
    sem_post(&mutexStart);

    // printf("mutexStartCounter: %d Thread: %d Process Num: %d\n",
    //    mutexStartCounter, currThread, currProcessNo);
    if (mutexStartCounter == N) {
        sem_post(&barrier);
    }

    sem_wait(&barrier);
    sem_post(&barrier);

    // Critical
    counter += 1;
    printf("Counter: %d Thread: %d Process Num: %d\n", counter, currThread,
           currProcessNo);

    sem_wait(&mutexEnd);
    mutexEndCounter++;
    sem_post(&mutexEnd);
    free(arg);
}

int main() {
    sem_init(&mutexStart, 0, 1);
    sem_init(&mutexEnd, 0, 1);
    sem_init(&barrier, 0, 0);
    pthread_t threads[N];

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < N; i++) {
            ThreadInfo *info = (ThreadInfo *)malloc(sizeof(ThreadInfo));
            info->programCounter = j;
            info->threadIndex = i;
            pthread_create(&threads[i], NULL, thread, (void *)info);
        }

        for (int i = 0; i < N; i++)
            pthread_join(threads[i], NULL);
        printf("Counter: %d\n", counter);
        counter = 0;
        mutexStartCounter = 0;
        mutexEndCounter = 0;
    }

    sem_destroy(&mutexStart);
    sem_destroy(&mutexEnd);
    sem_destroy(&barrier);
    return 0;
}