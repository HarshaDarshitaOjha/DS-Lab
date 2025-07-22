// 1.1 Write a program to read two numbers and compare the numbers using function call by address.
#include <stdio.h>

void compare(int *a, int *b)
{
    if(*a > *b)
        printf("%d is greater than %d\n", *a, *b);
    else if (*a < *b)
        printf("%d is greater than %d\n", *b, *a);
    else
        printf("Both numbers are equal: %d\n", *a);
}

int main()
{
    int x, y;
    printf("Enter first number:");
    scanf("%d", &x);
    printf("Enter second number:");
    scanf("%d", &y);

    compare(&x, &y);
    return 0;
}