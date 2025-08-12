/*Matrix Multiplication: Dynamically allocate two matrices (size m × n and n × p). Perform multiplication
and store the result in another dynamically allocated matrix*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row1, col1, row2, col2;
    printf("Enter rows for first matrix: ");
    scanf("%d", &row1);
    printf("Enter columns for first matrix: ");
    scanf("%d", &col1);
    printf("Enter rows for second matrix: ");
    scanf("%d", &row2);
    printf("Enter columns for second matrix: ");
    scanf("%d", &col2);

    if (col1 != row2)
    {
        printf("Matrix multiplication not possible.");
        return 0;
    }

    // Dynamically allocate memory for the matrices
    int **m1 = (int **)malloc(row1 * sizeof(int *));
    int **m2 = (int **)malloc(row2 * sizeof(int *));
    int **result = (int **)malloc(row1 * sizeof(int *));

    // Allocate memory for each row of the matrices
    for(int i = 0; i < row1; i++)
    {
        m1[i] = (int *)malloc(col1 * sizeof(int));
    }

    for(int i = 0; i < row2; i++)
    {
        m2[i] = (int *)malloc(col2 * sizeof(int));
    }

    for(int i = 0; i < row1; i++)
    {
        result[i] = (int *)malloc(col2 * sizeof(int));
    }

    // Input elements for the matrices
    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
            printf("Enter m1[%d][%d]: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            printf("Enter m2[%d][%d]: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    // Initialize the result matrix
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            result[i][j] = 0;               // Initialize to zero
            for(int k = 0; k < col1; k++)   // Perform multiplication
            {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Result: \n");
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    free(m1);
    free(m2);
    free(result);

    return 0;
}