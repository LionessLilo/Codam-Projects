#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NBR_THREADS 3


void    *print(void *arg)
{
    unsigned long thread_id;

    thread_id = pthread_self();
    usleep(2000000);
    printf("Hi from thread %d with ID %lu!\n", *(int*)arg, (unsigned long)thread_id);
    return NULL;
}

int main(void)
{
    pthread_t       threads[NBR_THREADS];
    unsigned int    i;
    int             args[NBR_THREADS];

    for (i = 0; i < NBR_THREADS; i++)
    {
        args[i] = i;
        pthread_create(&threads[i], NULL, (void *)print, &args[i]);
    }
    for (i = 0; i < NBR_THREADS; i++)
        pthread_join(threads[i], NULL);
    return 0;
}