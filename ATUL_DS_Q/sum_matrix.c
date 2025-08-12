/*Matrix Addition: Dynamically allocate two matrices of the same size and find their sum using a dynamically
allocated result matrix.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    int **m1 = (int **)malloc(row * sizeof(int *));
    int **m2 = (int **)malloc(row * sizeof(int *));
    int **sum = (int **)malloc(row * sizeof(int *));

    for(int i = 0; i < row; i++)
    {
        m1[i] = (int *)malloc(col * sizeof(int));
        m2[i] = (int *)malloc(col * sizeof(int));
        sum[i] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter elements for matrix 1:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter m1[%d][%d]: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter elements for matrix 2:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter m2[%d][%d]: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    // Calculate the sum of the two matrices
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    printf("Sum of the matrices:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    free(m1);
    free(m2);
    free(sum);
    
    return 0;    
    
}