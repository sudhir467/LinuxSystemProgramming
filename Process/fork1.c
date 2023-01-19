/* This program is to demonstrate fork system call */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t id;
    printf("Parent process: Executed by parent process before fork()- PID=(%d )\n", getpid());
    id = fork(); // from this point of code we have parent and child process
    if (id < 0)
    {
        printf("\n fork failed \n");
        exit(-1);
    }

    if (id > 0)
    {
        printf("\n Parent process: I have created child process with id : (%d) \n", id);
    }
    else
    {
        printf("\n I am child process, id value is:(%d) \n", id);
        printf("\n child process id is: (%d)\n", getpid());
        printf("\n The creator of child process is (%d) \n", getppid());
    }

    return 0;
}