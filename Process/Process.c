/* This is only a example program to demonstrate the different memory segment of a process*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* function declaration*/
int add_num(int num1, int num2);

void main(void)
{
    int num1, num2, sum;
    char *pstr;
    char *buf = "welcome"; // welcome string is stored in text segment, where as variable pointer buf is stored in stack frame of main
    char stack_buf[20] = { "stackData"}; // stack_buf is stored frame and it contains value "stackData"

    buf[0]='n'; // This will cause segmentation fault, as buf[0] tries to write to text segment,which is read only
    strcpy(stack_buf,"newString");

    num1=10;
    num2=20;
    sum= add_num(num1,num2);
    printf("\n the result of add is (%d) \n",sum);

    num1=100;
    num2=200;
    sum=add_num(num1,num2);
    printf("\n the result of add is (%d) \n",sum);

    pstr=malloc(20); //heap segment, pstr points to 20 bytes on heap,but location of pstr is part of stack fram of main()
    strcpy(pstr,"Hello");
    printf("\n string stored is (%s) \n", pstr);
}

/*Function argument num1,num2 stored on stack*/
int add_num(int num1,int num2)
{
    int res=0; // stack frame of add_num function-stack segment
    static int count=0; /* stroed in initialised data segment*/
    count=count+1;
    res=num1+num2;
    printf("\n number of times the function add_num called is (%d) \n", count);
    return(res);

}


