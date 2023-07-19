/*Find the largest element using Dynamic Memory allocation*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    float *element;
    printf("\n Enter the number of values required:\n  ");
    scanf("%d", &n);
    element = (float *)calloc(n, sizeof(float)); // Memory allocated
    if (element == NULL)
    {
        printf("No memory allocated");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        printf("The initial values are:%f\n", *(element+i);
    }

    for (i = 0; i < n; i++)
    {
        printf("Number %d:", i + 1);
        scanf("%f", element + i);
    }

    for (i = 0; i < n; i++)
    {
        if (*element < *(element + i))
        {
            *element = *(element + i);
        }
    }
    printf("The largest element is: %.2f \n\n", *element);
    
    free(element);
    return 0;
   
}