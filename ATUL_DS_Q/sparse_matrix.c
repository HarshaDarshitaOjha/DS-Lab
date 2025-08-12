/*Sparse Matrix Storage: Dynamically allocate a 2D matrix. Count the number of zero elements and 
determine if it is a sparse matrix (more than half elements are zero)*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    // Dynamically allocate memory for a 2D array (matrix)
    int **matrix = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter elements of the matrix:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int zero_count = 0;
    
    // Count the number of zero elements
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] == 0)
            {
                zero_count++;
            }
        }
    }

    // Check if it is a sparse matrix
    if(zero_count > (row * col) / 2)
    {
        printf("The matrix is a sparse matrix.\n");
    }
    else
    {
        printf("The matrix is not a sparse matrix.\n");
    }

    // Free allocated memory
    for(int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}