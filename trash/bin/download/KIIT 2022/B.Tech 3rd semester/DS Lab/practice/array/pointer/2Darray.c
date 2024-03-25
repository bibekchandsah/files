#include <stdio.h>
int main()
{
    int array[2][3];
    // int array[][3] = {};
    // int array[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // int array[2][3] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array) / sizeof(array[0][0]);
    printf("enter %d element :- ", size);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("the entered element is :- \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    printf("first row and first column element is :- %d", array[0][0]);
}