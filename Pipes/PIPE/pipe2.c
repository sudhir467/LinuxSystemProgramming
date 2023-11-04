/*Pipe communication between parent and child using pipes*/
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 50

int main(int argc, char *argv[])
{
    int pfd[2], loop = 0;
    char buf[BUF_SIZE] = {};
    ssize_t numRead;

    /*pipe file descriptors*/
    if (pipe(pfd) == -1)
    {
        exit(-1);
    }

    switch (fork())
    {
    case -1:
        exit(1);

    case 0:
        if (close(pfd[1]) == -1)
        {
            exit(-1);
        }

        for (;;)
        {
            /*Read data from pipe, echo on stdout*/
            strcpy(buf, "");
            numRead = read(pfd[0], buf, BUF_SIZE);
            if (numRead == -1)
            {
                exit(-1);
            }

            if (numRead == 0)
            {
                printf("\n child: parent closed write end \n");
                break;
            }
            printf("\n child process: data received in child process is(%s) \n", buf);
            printf("\n child process:closing read end \n");
            close(pfd[0]);
            sleep(10);
        }
        if (close(pfd[0]) == -1)
        {
            exit(-1);
        }
        break;

    default:
        if (close(pfd[0]) == -1)
        {
            exit(-1);
        }

        printf("\n Parent: sending user input string to child process-(%s)\n", argv[1]);
        write(pfd[1], argv[1], strlen(argv[1]));
        sleep(2);
        if(close(pfd[1])==-1)
        {
            exit(-1);
        }
        printf("\n parent:closed write end \n");
        wait(NULL);
        exit(0);
    }
}