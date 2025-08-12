/*3.2 WAP to perform addition of two given sparse matrix in 3–tuple format.*/

#include <stdio.h>

int main() {
    int m, n;
    int s1[100][3], s2[100][3], sum[200][3];
    int i, j, k;

    // Input dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Input first sparse matrix in 3-tuple format
    int t1;
    printf("\nEnter number of non-zero elements in first matrix: ");
    scanf("%d", &t1);
    s1[0][0] = m;
    s1[0][1] = n;
    s1[0][2] = t1;

    printf("Enter row, column, value for first matrix:\n");
    for (i = 1; i <= t1; i++) {
        scanf("%d %d %d", &s1[i][0], &s1[i][1], &s1[i][2]);
    }

    // Input second sparse matrix in 3-tuple format
    int t2;
    printf("\nEnter number of non-zero elements in second matrix: ");
    scanf("%d", &t2);
    s2[0][0] = m;
    s2[0][1] = n;
    s2[0][2] = t2;

    printf("Enter row, column, value for second matrix:\n");
    for (i = 1; i <= t2; i++) {
        scanf("%d %d %d", &s2[i][0], &s2[i][1], &s2[i][2]);
    }

    // Addition
    i = 1; // pointer for s1
    j = 1; // pointer for s2
    k = 1; // pointer for sum

    while (i <= t1 && j <= t2) {
        // Compare positions
        if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2];
            i++;
        }
        else if (s2[j][0] < s1[i][0] || (s2[j][0] == s1[i][0] && s2[j][1] < s1[i][1])) {
            sum[k][0] = s2[j][0];
            sum[k][1] = s2[j][1];
            sum[k][2] = s2[j][2];
            j++;
        }
        else { // same position → add values
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2] + s2[j][2];
            i++;
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i <= t1) {
        sum[k][0] = s1[i][0];
        sum[k][1] = s1[i][1];
        sum[k][2] = s1[i][2];
        i++;
        k++;
    }
    while (j <= t2) {
        sum[k][0] = s2[j][0];
        sum[k][1] = s2[j][1];
        sum[k][2] = s2[j][2];
        j++;
        k++;
    }

    // First row of sum (metadata)
    sum[0][0] = m;
    sum[0][1] = n;
    sum[0][2] = k - 1;

    // Display Result
    printf("\nResultant Sparse Matrix (3-Tuple Format):\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sum[i][0], sum[i][1], sum[i][2]);
    }

    return 0;
}
