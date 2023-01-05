#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int sz,fd;
    char buf[100];

    strcpy(buf, "This is example of O_TRUNC: sample file write2 using append flag\n");

    fd=open("input.txt",O_WRONLY | O_TRUNC);
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
