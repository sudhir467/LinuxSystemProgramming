/*dup () system call -application*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
    int fd;
    int newfd;
    fd= open("newfile.log", O_RDWR | O_CREAT,0767);
    if(fd == -1)
    {
        printf("\n open() was failed- errno = (%d) \n",errno);
        perror("ERROR:");
        exit(1);
    }
    else
    {
        printf("open() system call executed successfully , initial fd value:(%d) \n",fd);

    }
 newfd= dup (fd);
 printf("\n new fd value after dup() is (%d) \n",newfd);
 write(newfd,"writing using new fd, but will be written to old fd's file \n",60);
 
}