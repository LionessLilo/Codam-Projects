#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NBR_THREADS 2

/*
We are using the example of two students wanting to write on a whiteboard with
one marker. Each student needs to look at what was written on the board and 
increment it by one. 

Whiteboard = shared resources
Marker = mutex
Students = threads
*/


typedef struct s_mutex
{
    int             *ptr_whiteboard; // Both threads use this
    pthread_mutex_t *ptr_marker;     //This is the mutex
}                   t_mutex;


void    *writing(void *arg);

int main(void)
{
    t_mutex         mutex_info;
    int             whiteboard;
    int             status_code;            // mutex_init returns a status code
    int             i;
    int             j;
    int             maths_repeat;
    pthread_mutex_t marker;
    pthread_t       students[NBR_THREADS];

    mutex_info.ptr_marker = &marker;
    whiteboard = 0;
    mutex_info.ptr_whiteboard = &whiteboard;
    maths_repeat = 3;

    status_code = pthread_mutex_init(&marker, NULL); // Returns a status code
    if (status_code != 0)
        printf("Could not initialise mutex");
    for (j = 0; j < maths_repeat; j++)
    {
        for (i = 0; i < NBR_THREADS; i++)
            pthread_create(&students[i], NULL, (void *)writing, &mutex_info);
        for (i = 0; i < NBR_THREADS; i++)
            pthread_join(students[i], NULL);
    }
    return 0;
}

void    *writing(void *thread_arg)
{
    t_mutex         *mutex_info;
    unsigned long   thread_id;
    int             temp;

    mutex_info = (t_mutex *)thread_arg;
    thread_id = pthread_self();
    pthread_mutex_lock(mutex_info->ptr_marker);
    usleep(1000000);
    *(mutex_info->ptr_whiteboard) += 1;
    printf("Thread %lu printed %d\n", thread_id, *(mutex_info->ptr_whiteboard));
    pthread_mutex_unlock(mutex_info->ptr_marker);
}