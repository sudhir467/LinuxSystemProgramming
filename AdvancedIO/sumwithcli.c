/* Sum of two numbers using command line arguments*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, sum = 0;
    printf("argc: %d \n", argc);
    printf("lets see in argv[]\n");

    if (argc > 1)
    {
        for (i = 1; i < argc; i++)
        {
            printf("argv[%d]=%s \n", i, argv[i]);
            sum += atoi(argv[i]);
        }
        printf("Total= %d \n", sum);
    }

    return 0;
}