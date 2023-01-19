/* Demo of Commandline arguments for the process*/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("argc= %d \n",argc);
    printf("lets see what is in argv[] \n");

    for(i=0;i<argc; i++)
    {
        printf("argv[%d] = %s \n", i,argv[i]);
    }

    return 0;
}