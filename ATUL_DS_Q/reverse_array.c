/*1.Basic Input/Output: Write a program to dynamically allocate memory for an array of n integers,
 take input from the user, and print the elements in reverse order*/

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

    // print array entered
    printf("Array entered: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");


    // print array in reverse order
    printf("Array in reverse order: ");
    for(int i = n-1; i >= 0; i--)       //make sure for n - 1
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
    free(arr);
 }