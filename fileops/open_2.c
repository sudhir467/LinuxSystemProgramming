#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>

int main(){
    int fd;
    fd= open("newfile.log", O_RDWR| O_CREAT,0774);
    if (fd == -1)
    {
        printf("\n The error is = %d \n",errno);
        perror("ERROR:");
    }else
    {
        printf(" \n The open () system call successfully\n");
    }
}

