/*Sum & Average: Dynamically allocate an array of n integers. Read the values, calculate the sum and average,
and print them.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    // number of elements
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // dynamically allocate memory for n integers
    int *arr = (int *)malloc(n * sizeof(int));

    // enter elements into array
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int avg = 0;

    // calculate sum and average
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = sum / n;

    printf("Sum: %d\n", sum);
    printf("Average: %d\n", avg);

    free(arr);
    return 0;
}