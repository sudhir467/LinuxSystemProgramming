/* This program is to demonstrate read syscall*/ 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd,sz;
    char buf[20]={0};

    fd=open("input.txt",O_RDONLY);
    if(fd < 0)
    {
        perror("ERROR:");
        exit(1);
    }
    sz=read (fd,buf,10);
    printf("call 1 - called read. fd= %d, %d bytes were read. \n",fd,sz);
    buf[sz] ='\0';
    printf("Read bytes are as follows: \n <%s>\n",buf);
    printf("\n Next set of bytes read from file, it is continous\n");

    sz=read(fd, buf,11);
    printf("call 2- called read. fd =%d , %d bytes were read.\n", fd,sz);
    buf[sz]='\0';
    printf("Read bytes are as follows : \n <%s>\n", buf);

    sz=read(fd, buf,10);
    printf("call 3- called read. fd =%d , %d bytes were read.\n", fd,sz);
    if(sz==0)
    {
        printf("EOF Reached \n");
    }

    close(fd);

}