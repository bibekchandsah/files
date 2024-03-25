#include <stdio.h>
#include <stdlib.h>
// write a program to allocate memory of size n, where n is entered by the user.
int main()
{
    int *ptr;
    int number;
    printf("enter number : ");
    scanf("%d", &number);
    ptr = (int *)calloc(number, sizeof(int));
    for (int i = 0; i < number; i++)
    {
        printf("%d\n", ptr[i]);
    }
    printf("\n");
    ptr = realloc(ptr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%u\n", ptr[i]);
    }
    free(ptr);
    return 0;
}
