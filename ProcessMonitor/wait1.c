/* Program to demonstrate wait and exit */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t cpid;
    int status = 0;
    cpid=fork();
    if(cpid == -1)
    {
        exit(-1); /*Terminate child*/
    }

    if(cpid == 0)
    {
        printf("\n child executing first its pid =(%d) \n", getpid());
        sleep(20);
        printf("child pid = %d \n", getpid());
        exit(1);
    }else
    {
        printf("\n Parent executing before wait() \n");
        //cpid=wait(NULL);
        cpid=wait(&status);
        printf("\n wait() in parent done \n Parent pid = %d \n",getpid());
        printf("\n cpid returned is (%d)\n ", cpid);
        printf("\n status is (%d) \n", status);
    }
    return 0;

}
