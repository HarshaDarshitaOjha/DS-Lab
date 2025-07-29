/*2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.*/

#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the number of rows and columns of the sparse matrix: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Matrix 
    printf("Matrix entered:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Count non-zero elements and prepare 3-tuple representation
    int nonzero_count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonzero_count++;
            }
        }
    }

    // Create a 3-tuple representation
    int tuple[nonzero_count + 1][3];
    tuple[0][0] = m; // Number of rows
    tuple[0][1] = n; // Number of columns
    tuple[0][2] = nonzero_count; // Number of non-zero elements

    int index = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                tuple[index][0] = i; // Row index
                tuple[index][1] = j; // Column index
                tuple[index][2] = matrix[i][j]; // Value
                index++;
            }
        }
    }

    // Display the 3-tuple representation
    printf("3-tuple representation of the sparse matrix:\n");
    for (int i = 0; i <= nonzero_count; i++)
    {
        printf("%d %d %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }

    return 0;

}