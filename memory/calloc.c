/*Dynamic memory allocation using calloc */

#include <stdio.h>
#include <stdlib.h>

typedef struct user
{
    int sal;
    int id;
} user;

void main(void)
{
    user *puser = NULL;
    int count = 10;

    puser = (user *)calloc(10, sizeof(user));

    if (puser == NULL)
    {
        printf("\n calloc failed\n");
        exit(-1);
    }

    printf("\n calloc success \n");

    for (count = 0; count < 10; count++)
    {
        puser[count].id = count;
        puser[count].sal = count + 100;
    }

    for (count = 0; count < 10; count++)
    {
        printf("\n user [%d] id= (%d)", count, puser[count].id);
        printf("\n user [%d] salary=(%d)\n", count, puser[count].sal);
    }

    free(puser);
}