/*Maximum Element: Allocate memory dynamically for an array of n integers. Find and print the maximum and minimum 
elements without sorting the array.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter sizr of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for(int i = 0; i < n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
        if(min > arr[i])
        {
            min = arr[i];
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    free(arr); // Free the allocated memory
    return 0;
}