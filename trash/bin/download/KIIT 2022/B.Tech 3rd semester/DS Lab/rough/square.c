// Write a program to perform the following operations on a given square matrix using functions:
// i.   Find the no.of nonzero elements
// ii.  Display upper triangular matrix
// iii. Display the elements of just above and below the main diagonal
#include <stdio.h>

// Function to find the number of nonzero elements
int countNonZero(int mat[][10], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mat[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int mat[][10], int size)
{
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j >= i)
            {
                printf("%d ", mat[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to display elements just above and below the main diagonal
void displayNearDiagonal(int mat[][10], int size)
{
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == i - 1 || j == i + 1)
            {
                printf("%d ", mat[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int size;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int matrix[10][10];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int nonzeroCount = countNonZero(matrix, size);
    printf("Number of nonzero elements: %d\n", nonzeroCount);

    displayUpperTriangular(matrix, size);

    displayNearDiagonal(matrix, size);

    return 0;
}
