/*Matrix Input & Output: Dynamically allocate memory for an m × n matrix using pointers. Take input from the user
and print the matrix in matrix form*/

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
    // Using a pointer to a pointer
    int **m = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++)
    {
        // Allocate memory for each row
        m[i] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter elements: \n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter matrix[%d][%d]: ", i,j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Matrix entered: \n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d, ", m[i][j]);
        }
        printf("\n");
    }

    free(m);
    return 0;
}