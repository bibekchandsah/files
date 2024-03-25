#include <stdio.h>
int main()
{
    int array[50], size;
    printf("enter the size of array :- ");
    scanf("%d", &size);
    printf("enter %d element :- ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("the entered element is :- ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    size--; // decreasing the size of array
    printf("\nthe modified array is :- ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}