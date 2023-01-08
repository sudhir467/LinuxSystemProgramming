/* dup () systemcall - application to write the output to a file instead of screen*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{
    int fd;
    fd = open("newFile.log", O_RDWR | O_CREAT, 0767);
    if(fd == -1)
    {
        printf("\n open() was failed - errno =(%d) \n",errno);
        perror("ERROR:");
    }
    else
    {
        printf("open() system call executed successfully \n");
    }

close(1);
dup(fd);

printf("\n output not written to screen, rather written to file using dup() system call \n");

}