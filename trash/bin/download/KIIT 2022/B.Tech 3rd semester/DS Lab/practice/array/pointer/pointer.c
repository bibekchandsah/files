#include <stdio.h>
int main()
{
    int array[40];
    // int array[40] = {1, 2};
    int *pointer;
    pointer = array;
    // pointer = &array[40];
    // *pointer = array[40];
    printf("enter the size of array :- ");
    int size;
    scanf("%d", &size);
    printf("enter %d element :- ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
        // scanf("%d", &pointer[i]);
        // scanf("%d", (array + i));
        // scanf("%d", (i + array));
        // scanf("%d", (pointer + i));
        // scanf("%d", (i + pointer));
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        // printf("%d ", pointer[i]);
        // printf("%d ", *(pointer + i));
        // printf("%d ", *(i + pointer));
        // printf("%d ", i[pointer]);
        // printf("%d ", i[array]);
    }
}