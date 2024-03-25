// inserting element at start
#include <stdio.h>
int main()
{
    int array[25];
    printf("enter the size of array :- ");
    int size;
    scanf("%d", &size);
    while (size > 25)
    {
        printf("invalid input\n");
        printf("enter the size of array :- ");
        scanf("%d", &size);
    }
    if (size <= 0)
    {
        printf("invalid input \n");
    }
    else
    {
        printf("enter %d element :- ", size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &array[i]);
        }
        printf("entered element are :- ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\nenter the element you want to insert :- ");
        int number;
        scanf("%d", &number);
        for (int i = size - 1; i >= 0; i--) // starting from last position to first position in decreasing manner
        {
            array[i + 1] = array[i]; // swapping value till first
        }
        array[0] = number; // assigning new value to first
        size++;            // increasing the size of array
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
    }
}