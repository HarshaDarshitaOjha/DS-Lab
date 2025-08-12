/*WAP to represent the polynomial of single variable using 1-D array and perform the addition
of two polynomial equations*/
#include <stdio.h>

int main() {
    int deg1, deg2, maxDeg;
    int poly1[50] = {0}, poly2[50] = {0}, sum[50] = {0};
    int i;

    // Input for first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter the coefficients from highest degree to constant term:\n");
    for (i = deg1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // Input for second polynomial
    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter the coefficients from highest degree to constant term:\n");
    for (i = deg2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    // Find maximum degree
    maxDeg = (deg1 > deg2) ? deg1 : deg2;

    // Addition of polynomials
    for (i = 0; i <= maxDeg; i++) {
        sum[i] = poly1[i] + poly2[i];
    }

    // Display first polynomial
    printf("\nFirst Polynomial: ");
    for (i = deg1; i >= 0; i--) {
        if (poly1[i] != 0) {
            printf("%d", poly1[i]);
            if (i > 0) printf("x^%d", i);
            if (i > 0 && poly1[i - 1] >= 0) printf(" + ");
        }
    }

    // Display second polynomial
    printf("\nSecond Polynomial: ");
    for (i = deg2; i >= 0; i--) {
        if (poly2[i] != 0) {
            printf("%d", poly2[i]);
            if (i > 0) printf("x^%d", i);
            if (i > 0 && poly2[i - 1] >= 0) printf(" + ");
        }
    }

    // Display sum polynomial
    printf("\nSum of Polynomials: ");
    for (i = maxDeg; i >= 0; i--) {
        if (sum[i] != 0) {
            printf("%d", sum[i]);
            if (i > 0) printf("x^%d", i);
            if (i > 0 && sum[i - 1] >= 0) printf(" + ");
        }
    }

    printf("\n");
    return 0;
}
