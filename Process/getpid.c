/* This program is to get the process id of process*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main(void)
{
    printf("\n Process Id is (%d) \n", getpid());
    printf("\n Process ID of creator(parent) is (%d) \n",getppid());
    sleep(5);
}