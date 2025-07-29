/*2.2 Write a program to perform the following operations on a given square matrix using functions:
i. Find the no.of nonzero elements
ii. Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);
    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count non-zero elements
    int nonzero_count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonzero_count++;
            }
        }
    }
    printf("Number of non-zero elements: %d\n", nonzero_count);

    // Display upper triangular matrix
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
                printf("%d ", matrix[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }

    // Display elements just above and below the main diagonal
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n - 1; i++)
    {
        printf("Above: %d, Below: %d\n", matrix[i][i + 1], matrix[i + 1][i]);
    }

    return 0;
}