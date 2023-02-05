/* Program to demonstrate wait and exit*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t cpid;
    pid_t cpid2;
    int status = 0;
    cpid = fork();
    if (cpid == -1)
    {
        exit(-1);
    }

    if (cpid == 0)
    {
        printf("\n child1 executing its pid = (%d)\n", getpid());
        sleep(10);
        printf("child1 exited \n");
        exit(0);
    }
    else
    {
        cpid2 = fork();
        if (cpid2 == -1)
        {
            exit(-1);
        }

        if(cpid2==0)
        {
            printf("\n child2 executing its pid= (%d) \n", getpid());
            sleep(5);
            printf("child2 exited \n");
            exit(1);
        }

        printf("\n Parent executing before wait() Parent pid is (%d)\n",getpid());
        cpid= wait(&status);
        printf("\n cpid returned is (%d) \n",cpid);
        printf("\n status is (%d)\n", status);

        cpid = wait(&status);
        printf("\n cpid returned is (%d) \n",cpid);
        printf("\n status is (%d) \n", status);
        printf("\n Parent exited \n");
    }

    return 0;
}