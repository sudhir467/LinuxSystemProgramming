/*
dup2()- systemcall has more control over the duplicating file descriptor of users choice
*/

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

void main()
{
    int fd;
    fd=open("newfile.log", O_RDWR | O_CREAT,0767);
    if(fd == -1)
    {
        printf("open() call error : (%d)", errno);
        perror("ERROR:");
    }
    else
    {
        printf("\n open syscall() executed successfully \n");
    }

    // int dup2(int oldfd, int newfd);
    // after this call old and new fd point to the same file newfile.log
    dup2(fd,1);

    printf("\n output not written to screen rather written to file using dup2() \n");
}