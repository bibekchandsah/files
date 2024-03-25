// WAP to represent a given sparse matrix in 3-tuple format using 2-D array.

#include <stdio.h>
int main()
{
    int matrix[100][100];
    int numRows, numCols;

    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &numRows, &numCols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}