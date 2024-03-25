// deletion at start
#include <stdio.h>
int main()
{
    int array[50];
    printf("enter the size of array :- ");
    int size;
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
    for (int i = 0; i < size - 1; i++) // from starting to end in increasing manner
    {
        array[i] = array[i + 1]; // swapping the value
    }
    size--; // decreasing the size of array
    printf("\n the modified array is :- ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}