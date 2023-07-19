/* Dynamic Memory allocation using malloc*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, *ptr, sz, ints;
    printf("Enter the total number of values:");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int)); // Dynamic memory allocation using malloc

    if (ptr == NULL)
    {
        printf("\n malloc failed\n");
        exit(1);
    }
    else
    {
        printf("\n malloc success\n");
    }

    ints = sizeof(int);
    printf("Size of the int: %d \n", ints);
    printf("Address of the pointer:%ls \n", ptr);

    sz = sizeof(ptr);
    printf("Size of the ptr: %d \n", sz);

    printf("\n Enter the values: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    printf("Entered values are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \n", *(ptr + i));
    }

    free(ptr);
}
