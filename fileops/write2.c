#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<malloc.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int fd, sz;
    char buf[100];
    strcpy(buf,"Sample file write \n");
    fd=open("new_write.txt", O_WRONLY | O_CREAT, 0774);
    if(fd<0)
    {
        perror("Error occured during open");
        exit(1);
    }
    printf("length of buf is (%d)", (int)strlen(buf));
    sz=write(fd,buf,strlen(buf));
    printf("\n write() returned %d \n",sz);
    close(fd);
}