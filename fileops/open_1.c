/* This program is to demonstrate open syscall*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

void main()
{
    int fd;
    fd= open("startup.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("\n open was failed- errno = (%d)\n",errno);
        perror("ERROR:");
    }
    else
    {
        printf("\n open() systemcall executed successfully \n");
    }
}