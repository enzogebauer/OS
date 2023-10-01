#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 200

// grupo:
// Enzo Bacelar Conte Gebauer
// Francielle Andrade Cardoso
// Matheus Sá Cardoso

int global = 0;
// pthread_mutex_t mutex;
pthread_t threads[NUM_THREADS];

void *incrementa(void *arg)
{
    int threadId = *((int *)arg);
    // pthread_mutex_lock(&mutex);
    int a = global;
    a++;
    struct timespec sleepTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = 100000000; // Sleep for 100 milliseconds (100 million nanoseconds)
    nanosleep(&sleepTime, NULL);   // POSIX nanosleep function
    global = a;
    printf("Thread %d: a = %d\n", threadId, a);
    // pthread_mutex_unlock(&mutex);
    return NULL;
}

void *decrementa(void *arg)
{
    int threadId = *((int *)arg);
    // pthread_mutex_lock(&mutex);
    int a = global;
    a--;
    struct timespec sleepTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = 100000000; // Sleep for 100 milliseconds (100 million nanoseconds)
    nanosleep(&sleepTime, NULL);   // POSIX nanosleep function
    global = a;
    printf("Thread %d: a = %d\n", threadId, a);
    // pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    int threadArgs[NUM_THREADS];
    // pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        threadArgs[i] = i;
        if (i % 2 == 0)
        {
            if (pthread_create(&threads[i], NULL, incrementa, &threadArgs[i]) != 0)
            {
                fprintf(stderr, "Failed to create thread %d\n", i);
                return 1;
            }
        }
        else
        {
            if (pthread_create(&threads[i], NULL, decrementa, &threadArgs[i]) != 0)
            {
                fprintf(stderr, "Failed to create thread %d\n", i);
                return 1;
            }
        }
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // pthread_mutex_destroy(&mutex);

    return 0;
}
