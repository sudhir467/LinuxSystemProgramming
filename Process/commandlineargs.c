/* Demo program to show the command line arguments of process*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc, char *argv[])
{
    int count = 0;
    printf("\n Demonstrate the command line arguments");
    printf("\n the value of argc is (%d)",argc);

    while(count<argc)
    {
        printf("\n (%d) th string is (%s) \n", count,argv[count]);
        count++;
    }

}