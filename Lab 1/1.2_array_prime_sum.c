// 1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of
// all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>

int prime(int num)
{
    if (num < 2) 
    {
        printf("%d is not a prime number.\n", num);
        return 0;
    }
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) 
            return 0; // Not prime
    }
    return 1; // Prime

}

int sum_of_primes(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (prime(arr[i]))              // when have to use here, dont make void function
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation for an array of n integers
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of prime elements
    int sum = sum_of_primes(arr, n);
    printf("Sum of prime elements: %d\n", sum);

    // De-allocate the memory
    free(arr);
    
    return 0;
}