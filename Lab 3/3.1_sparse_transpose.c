// WAP to transpose sparse matrix
// The transpose of a sparse matrix is obtained by swapping its rows and columns.

#include <stdio.h>

int main() {
    int m, n, i, j, count = 0;

    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    int matrix[m][n];

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Convert to sparse (3-tuple) format
    int sparse[100][3]; // row, col, value
    sparse[0][0] = m;
    sparse[0][1] = n;

    count = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
            }
        }
    }
    sparse[0][2] = count;

    // Display original sparse matrix
    printf("\nOriginal Sparse Matrix (3-Tuple Format):\n");
    for (i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    // Transpose by swapping rows & columns
    int transpose[100][3];
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    int k = 1;
    for (i = 0; i < n; i++) {
        for (j = 1; j <= count; j++) {
            if (sparse[j][1] == i) { // match column number
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }

    // Display transpose sparse matrix
    printf("\nTranspose Sparse Matrix (3-Tuple Format):\n");
    for (i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}
