/*This program is to create the thread create and exit- pthread_exit(0) 
does not terminate the thread func, where as if we use exit(0) it will*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void *threadfunc(void *arg)
{
    char *str = (char *)arg;
    printf("Threadfunc: arguments passed to thread are: %s, pid=(%d) \n", str, getpid());
    (void)sleep(15);
    printf("\n threadfunc:exiting now \n");
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t t1;
    void *res;
    int s;
    s = pthread_create(&t1, NULL, threadfunc, "Hello world");
    if (s != 0)
    {
        perror("Thread create error");
    }
    printf("main thread: Message from main(), pid=(%d)\n", getpid());
    sleep(5);
    printf("\n main thread exiting now \n");
    //exit(0);
    pthread_exit(0);
}