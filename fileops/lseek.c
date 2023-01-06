#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int sz,seek_pos=0;
    char buf[100];

    int fd=open("input.txt", O_RDWR);
    if(fd<0)
    {
        perror("Error occured during open");
        exit(1);
    }
    seek_pos=lseek(fd,0,SEEK_SET);
    printf("\n Initial offset position:(%d) \n", seek_pos);

    seek_pos=lseek(fd,2,SEEK_SET);
    printf("\n offset position: (%d) \n", seek_pos);

    seek_pos=lseek(fd,6,SEEK_CUR);
    printf("\n offset position: (%d) \n", seek_pos);

    sz=read(fd,buf,10);
    printf("\n read bytes from the file lseek is =(%d) \n",sz);
    buf[sz]='\0';
    printf("Read bytes are as follows:\n %s \n",buf);

    seek_pos= lseek(fd,0,SEEK_END);
    printf("\n offset position after (SEEK_END + 0):(%d) \n",seek_pos);

    strcpy(buf,"New string appended after SEEK_END \n");
    sz=write(fd,buf,strlen(buf));

    close(fd);

}