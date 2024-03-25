#include <stdio.h>
int main()
{
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *pointer;

    pointer = &array[0][0];
    // pointer = array[0];
    // pointer = array[0][0] ==> X ==> it returns value not address
    // pointer = array ==> X ==> applied to only 1D array bcz it returns the address of only one row

    printf("%d\n", array); // address of 1st row
    // printf("%d\n", pointer);      // address of 1st row
    // printf("%d\n", *array);       // address of 1st row
    // printf("%d\n", &array);       // address of 1st row
    // printf("%d\n", array[0]);     // address of 1st row
    // printf("%d\n", &array[0][0]); // address of 1st row

    printf("%d\n", array + 1); // address of 2nd row
    // printf("%d\n", *(array + 1)); // address of 2nd row
    // printf("%d\n", array[1]);     // address of 2nd row
    // printf("%d\n", &array[1]);    // address of 2nd row
    // printf("%d\n", &array[1][0]); // address of 2nd row

    printf("%d\n", *(array + 1) + 2);    // address of 2nd row 3rd column i.e. [1][2]
    printf("%d\n", array[1] + 1);        // address of 2nd row 2nd column i.e. [1][1]
    printf("%d\n", &array[1] + 1);       // address of 2nd row 2nd column i.e. [2][0] ==> base address of array[1] + size of array i.e. (3 column * 4 byte)
    printf("%d\n", *(*(array + 1) + 2)); // value of 2nd row 3rd column i.e. [1][2]
    printf("%d\n", *(array[1] + 2));     // value of 2nd row 3rd column i.e. [1][2]
    // printf("%d\n", *(array[i] + j)); // value of nth row & nth column i.e. [i][j]
    printf("%d\n", array[1][2]);         // value of 2nd row 3rd column i.e. [1][2]
    printf("%d\n", array[2][0]);         // value of 3rd row 1st column i.e. [2][0]
    printf("%d\n", *(*(array + 2) + 0)); // value of 3rd row 1st column i.e. [2][0]
    // printf("%d\n", *(*(array + i) + j)); // value of nth row & nth column i.e. [i][j]
    printf("%d\n", *(*array + 1)); // value of 1st row 2nd column i.e. [0][1]
    printf("%d\n", **array);       // value of 1st row 1st column i.e. [0][0]
    // printf("%d\n", **pointer);   // ==> X invalid

    int size = sizeof(array) / sizeof(array[0][0]);
    printf("enter %d element :- ", size);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // printf("%d\t", *(array + i) + j); // address
            printf("%d\t", *(*(array + i) + j)); // value
            // printf("%d\t", array[i] + j); // address
            // printf("%d\t", *(array[i] + j)); // value
        }
        printf("\n");
    }
    printf("%d\n", **array);       // value of 1st row 1st column i.e. [0][0]
    printf("%d\n", *(*array + 0)); // value of 1st row 2nd column i.e. [0][0]
    printf("%d\n", *(*array + 1)); // value of 1st row 2nd column i.e. [0][1]
    printf("%d\n", *(*array + 2)); // value of 1st row 2nd column i.e. [0][1]
}