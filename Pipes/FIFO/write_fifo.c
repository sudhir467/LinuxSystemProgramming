/*FIFO implemeting transfer of data, this are also called as namepipe*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    // fifo file path
    char *myfifo = "/tmp/myfifo";
    char arr[80];

    /*Creating FIFO or name pipe*/
    mkfifo(myfifo, 0660);

    // open FIFO for write only
    fd = open(myfifo, O_WRONLY);

    while (1)
    {
        printf("\n Enter string to be sent via fifo \n");
        fgets(arr, 80, stdin);
        // write to the input of array on FIFO and close it
        write(fd, arr, strlen(arr) + 1);
    }
    close(fd);
    return 0;
}