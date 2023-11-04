/*Implementing pipes for sending data between processes*/
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd[2];
    char buff[50];
    char data[50] = {};

    // open a pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    // Fd[0] contains descriptor to read end of plate, fd[1] contains descriptor to write of the pipe
    sprintf(buff, "PIPE data flow demo:");

    // write to the pipe
    write(fd[1], buff, strlen(buff));
    printf("\n");

    // reading pipe and storing data in data buffer

    read(fd[0], data, 5);
    printf("%s\n", data);

    read(fd[0], data, 5);
    printf("%s \n", data);

    read(fd[0], data, 10);
    printf("%s \n", data);
}