/*Resizing an Array: Dynamically allocate an array of n integers. Later, increase its size to n + m using realloc()
and take more inputs. Print all elements.*/

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

    int m;
    printf("Enter number of additional elements to add: ");
    scanf("%d", &m);

    // Resize the array to hold n + m elements
    arr = (int *)realloc(arr, (n + m) * sizeof(int));

    for (int i = n; i < n + m; i++)
    {
        printf("Enter additional element %d: ", i - n + 1);
        scanf("%d", &arr[i]);
    }

    printf("All elements in the resized array: ");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", arr[i]);
    }
}