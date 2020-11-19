#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N_OF_THREADS 5

int nums[1000];
int result = 0, thread = 0;
int final[5];

void* sum(void* arg) {

    thread++;
    for (int i = thread * (1000 / 5); i < (thread + 1) * (1000 / 5); i++) {
        result += nums[i];
    }
    final[thread] = result;
    pthread_exit(NULL);
}

int main() {

    pthread_t threads[N_OF_THREADS];

    int status, i;

    for (int i = 1; i <= 1000; i++) {

        nums[i] = i;

    }

    for (int i = 0; i < N_OF_THREADS; i++) {

        printf("Main. Creating thread %d\n", i);

        status = pthread_create(&threads[i], NULL, sum, (void*)NULL);

        printf("Results: %d\n", final[i]);

        if (status) {

            printf("Error %d\n", status);

            exit(-1);

        }

    }

    int sum = 0;

    for (int i = 0; i < N_OF_THREADS; i++)
        sum += final[i];

    printf("Final: %d\n", sum);

    exit(NULL);

}