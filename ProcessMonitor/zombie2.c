/*Demonstrate Zombie process*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    pid_t id;
    printf("Parent process: Executed by parent process before fork()- PID=(%d) \n",getpid());
    id=fork();
    if(id<0)
    {
        printf("\n fork failed \n");
        exit(-1);
    }
    if(id>0)
    {
        sleep(10);
        printf("\n run ps aux | grep Z \n");
        waitpid(id, NULL, 0);
        printf("\n Parent process: I have created child process with ID= (%d) \n", id);
        sleep(6);
        printf("\n Parent process exited \n");
    }else
    {
        sleep(5);
        printf("\n child process id is (%d)\n ", getpid());
        printf("\n the creator of child process is (%d) \n",getpid());
    }
    return 0;
}