// inserting of element at end
#include <stdio.h>
int main()
{
    int array[50];
    printf("enter the size of array :- ");
    int size;
    scanf("%d", &size);
    printf("enter the %d element in array :- ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("the entered element of array are :- ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nenter the number you want to insert in array :- ");
    int number;
    scanf("%d", &number);
    array[size] = number; // storing value at last
    size++;               // increasing the size of array after new element insertion
    printf("the new array is :- ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}