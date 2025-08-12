/*Transpose of a Matrix: Dynamically allocate an m × n matrix. Store its transpose in another 
dynamically allocated n × m matrix. Print both.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    // Dynamically allocate memory for the original matrix
    int **m = (int **)malloc(row * sizeof(int *));

    // Allocate memory for each row of the matrix
    for(int i = 0; i < row; i++)
    {
        m[i] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter elements for matrix: \n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Matrix entered: \n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Dynamically allocate memory for the transposed matrix
    int **trans = (int **)malloc(col * sizeof(int *));      // row as col and col as row

    for(int i = 0; i < col; i++)
    {
        trans[i] = (int *)malloc(row * sizeof(int));
    }

    printf("Transposed Matrix: \n");
    // Calculate the transpose of the matrix
    for(int i = 0; i < col; i++)        // Iterate over columns of the original matrix
    {
        for(int j = 0; j < row; j++)    // Iterate over rows of the original matrix
        {
            printf("%d ", m[j][i]);  // Transpose is m[j][i]
        }
        printf("\n");
    }

    free(m);
    free(trans);

    return 0;

}