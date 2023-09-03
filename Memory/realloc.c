/*This program is to demonstrate the realloc memory allocation*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i, n1, n2;
    printf("Enter the number required:\n");
    scanf("%d" ,&n1);
    ptr = (int *)malloc(n1 * sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated \n");
        exit(1);
    }

    for(int i=0;i<n1;i++)
    {
        printf(" The Initial values of the memory are:%d \n",*(ptr+i));
    }

    for(i = 0; i < n1; ++i)
    {
      printf("%pc\n",ptr + i);  
    }

    //Reallocating the new memory
    printf("Enter the new memory required:\n");
    scanf("%d",&n2);

    ptr=(int*)realloc(ptr,sizeof(n2));
    

    for(i=0;i<n2;i++)
    {
    printf("%pc \n",ptr+i);
    }

    free(ptr);
    return 0;
}
