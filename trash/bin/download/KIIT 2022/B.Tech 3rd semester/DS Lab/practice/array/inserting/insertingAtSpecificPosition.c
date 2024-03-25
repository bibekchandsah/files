// inserting element at specific position
#include <stdio.h>
int main()
{
    int array[50], size;
    printf("enter the size of array :- ");
    scanf("%d", &size);
    // loop body is executed at least once, regardless of the condition.
    // It checks the condition after executing the loop body.
    do
    {
        printf("enter the size of array (0 to 50) :- ");
        scanf("%d", &size);
    } while (size <= 0 || size > 50);

    printf("Enter the %d element of array :- ", size);
    // loop is used when you know in advance how many times you want to iterate.
    // The loop initializes a variable, checks a condition, and increments (or decrements) the variable after each iteration.
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("the entered element is :- ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    int number, position;
    printf("\nenter the number you want to insert in array :- ");
    scanf("%d", &number);
    do
    {
        printf("enter the position you want to insert in array :- ");
        scanf("%d", &position);
        if (position < 0 || position > size)
        {
            printf("invalid position number.\n");
        }
    } while (position < 0 || position > size);

    for (int i = size - 1; i >= position - 1; i--) // start from last to specific position in the decreasing manner
    {
        array[i + 1] = array[i]; // swapping the value
    }
    array[position - 1] = number; // assigning new value
    size++;                       // increasing the array size
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}