// Wap to calculate the sum of n numbers of an array entered by the user using dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    int *ptr;
    int sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &num);
    ptr = (int *)malloc(sizeof(int) * num);
    printf("Enter %d elements:", num);
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < num; ++i)
    {
        sum = sum + ptr[i];
    }
    printf("the sum is :- %d", sum);
}
