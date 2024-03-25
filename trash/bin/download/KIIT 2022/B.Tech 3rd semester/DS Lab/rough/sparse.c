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

    // Count the number of nonzero elements in the matrix
    int numNonZero = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (matrix[i][j] != 0)
            {
                numNonZero++;
            }
        }
    }

    // Create a 3-tuple representation using a 2-D array
    int sparseMatrix[numNonZero + 1][3]; // Add an extra row for metadata
    sparseMatrix[0][0] = numRows;
    sparseMatrix[0][1] = numCols;
    sparseMatrix[0][2] = numNonZero;

    int currentIndex = 1;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[currentIndex][0] = i;
                sparseMatrix[currentIndex][1] = j;
                sparseMatrix[currentIndex][2] = matrix[i][j];
                currentIndex++;
            }
        }
    }

    // Display the 3-tuple representation
    printf("\n3-Tuple Representation:\n");
    for (int i = 0; i <= numNonZero; i++)
    {
        printf("(%d, %d, %d)\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}
