/*Read sys call on fifo*/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;
    // fifo file path
    char *myfifo = "/tmp/myfifo";
    char str1[80];

    // open FIFO for read only
    fd1 = open(myfifo, O_RDONLY);

    while (1)
    {
        read(fd1,str1,80);
        printf("User1:%s\n",str1);
        
    }
    close(fd1);
    return 0;
}