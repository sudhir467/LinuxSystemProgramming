/*This program is to use all the system call in one*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include<malloc.h>
#include<unistd.h>

void main()
{
    int fd, sz;
    char buf[100];
   
    fd=open("name.txt",O_RDWR |O_CREAT| O_TRUNC, 0774);
    if(fd < 0)
    {
        printf("\n Open systemcall failed with error num: (%d)\n",errno);
        perror("ERROR:");
    }else{
        printf("\n Open systemcall successfull\n");
    }
    strcpy(buf,"Hai");
    sz=write(fd,buf,strlen(buf));

    close(fd);


    
}