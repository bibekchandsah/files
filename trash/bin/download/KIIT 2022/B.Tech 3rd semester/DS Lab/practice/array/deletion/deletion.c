// deletion from specific position
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
    printf("\nat which position you want to delete element :- ");
    int position;
    scanf("%d", &position);
    for (int i = position - 1; i < size - 1; i++) // for postion to size in increasing manner
    {
        array[i] = array[i + 1]; // swapping value i.e. deletion
    }
    size--; // decreasing the array size
    printf("the modified array is :- ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}