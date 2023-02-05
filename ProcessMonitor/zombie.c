/* Demonstrate zombie Process */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    pid_t id;
    printf("Parent Process: Executed by parent process before fork()- PID=(%d)\n",getpid());
    id= fork(); // from this point of code, the child and parent process both execute
    if(id<0)
    {
        printf("\n fork failed \n");
        exit(-1);
    }
    if(id>0)
    {
        sleep(15);
        printf("\n Parent process: I Have created child process with ID=(%d)\n",id);
        printf("\n Parent process exited \n");
    }else
    {
        sleep(5);
        printf("\n child process id is (%d)\n",getpid());
        printf("\n the creator of child process is (%d) \n",getppid());
    }

    return 0;
}