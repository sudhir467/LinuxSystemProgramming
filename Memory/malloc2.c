/*Dynamic memory allocation using malloc*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i, n;
    int *ptr = NULL;

    printf("Enter total number of values:");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("\n malloc failed \n");
    }
    else
    {
        printf("\n malloc successfull \n ");
    }

    printf("\n Enter the value \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    printf("The entered values are: \n");

    for (i = 0; i < n; i++)
    {
        printf("%d \n", *(ptr + i));
    }

    free(ptr);
}
