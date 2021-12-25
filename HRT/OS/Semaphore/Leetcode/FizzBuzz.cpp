#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

int n;
sem_t runFizz, runBuzz, runFizzBuzz, runNumber;
bool writeFizzBuzz;

// ~FizzBuzz() {
//     sem_destroy(&runFizz);
//     sem_destroy(&runBuzz);
//     sem_destroy(&runFizzBuzz);
// }

// printFizz() outputs "fizz".
void *fizz(void *arg) {
    while (true) {
        sem_wait(&runFizz);
        if (!writeFizzBuzz)
            return arg;
        // printFizz();
        printf("Fizz\n");
        // cout << "Fizz" << endl;
        sem_post(&runNumber);
    }
}

// printBuzz() outputs "buzz".
void *buzz(void *arg) {
    while (true) {
        sem_wait(&runFizz);
        printf("writeFizzBuzz: %d\n", writeFizzBuzz);
        if (!writeFizzBuzz)
            return arg;

        printf("Buzz\n");
        // cout << "Buzz" << endl;
        sem_post(&runNumber);
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void *fizzbuzz(void *arg) {
    while (true) {
        sem_wait(&runFizz);
        if (!writeFizzBuzz)
            return arg;
        // printFizzBuzz();
        printf("FizzBuzz\n");
        // cout << "FizzBuzz" << endl;
        sem_post(&runNumber);
    }
}

// printNumber(x) outputs "x", where x is an integer.
void *number(void *arg) {
    for (int i = 1; i <= n; i++) {
        printf("beg %d\n", i);
        sem_wait(&runNumber);

        if (i % 15 == 0) {
            sem_post(&runFizzBuzz);
        } else if (i % 5 == 0) {
            sem_post(&runBuzz);
        } else if (i % 3 == 0) {
            sem_post(&runFizz);
        } else {
            // cout << i << endl;
            printf("%d\n", i);
            sem_post(&runNumber);
        }
    }

    sem_wait(&runNumber);
    printf("Number waited\n");
    writeFizzBuzz = false;
    sem_post(&runFizzBuzz);
    sem_post(&runFizz);
    sem_post(&runBuzz);
    printf("Number thread done\n");
}

void createThreads() {
    pthread_t fizzThread, buzzThread, fizzBuzzThread, numberThread;
    pthread_create(&fizzThread, NULL, fizz, NULL);
    pthread_create(&buzzThread, NULL, buzz, NULL);
    pthread_create(&fizzBuzzThread, NULL, fizzbuzz, NULL);
    pthread_create(&numberThread, NULL, number, NULL);

    pthread_join(fizzThread, NULL);
    pthread_join(buzzThread, NULL);
    pthread_join(fizzBuzzThread, NULL);
    pthread_join(numberThread, NULL);
}

int main() {
    n = 1;
    sem_init(&runFizz, 0, 0);
    sem_init(&runBuzz, 0, 0);
    sem_init(&runFizzBuzz, 0, 0);
    sem_init(&runNumber, 0, 1);
    writeFizzBuzz = true;
    createThreads();

    sem_destroy(&runFizz);
    sem_destroy(&runBuzz);
    sem_destroy(&runFizzBuzz);
    return 0;
}
