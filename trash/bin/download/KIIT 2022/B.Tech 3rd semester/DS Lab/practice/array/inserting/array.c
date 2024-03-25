#include <stdio.h>
int main()
{
    int array[50], size;
    // size = sizeof(array) / sizeof(array[0]);
    printf("enter the size of array :- ");
    scanf("%d", &size);
    while (size > 50)
    {
        printf("try to enter the size less that 50. \n");
        printf("enter the size of array :- ");
        scanf("%d", &size);
    }
    if (size <= 0)
    {
        printf("invalid input\n");
    }
    else
    {
        printf("enter the %d array :- ", size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &array[i]);
        }
        printf("the entered element of array is :- ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
    }
    return 0;
}