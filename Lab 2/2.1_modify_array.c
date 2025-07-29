/*2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using
function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    // Menu based operations
    printf("Menu:\n");
    printf("a - Insert an element at a specific position\n");
    printf("b - Delete an element from a specific position\n");
    printf("c - Search for an element using linear search\n");
    printf("d - Traverse the array\n");
    printf("Choose an operation (a/b/c/d): ");
    char choice;
    scanf(" %c", &choice);

    switch (choice)
    {
        case 'a':
            printf("You chose to insert an element.\n");
            break;
        case 'b':
            printf("You chose to delete an element.\n");
            break;
        case 'c':
            printf("You chose to search for an element.\n");
            break;
        case 'd':
            printf("You chose to traverse the array.\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    printf("\n");

    if(choice == 'a')
    {
        // a - insert a given element at specific position
        int element0, position0;
        printf("Enter the element to insert and the position: ");
        scanf("%d %d", &element0, &position0);
        if (position0 < 0 || position0 > n)
        {
            printf("Invalid position!\n");
        }
        else
        {
            for (int i = n; i > position0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[position0] = element0;
            n++;
            printf("Element inserted successfully.\n");
        }
        printf("Array after insertion:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");    
    }

    else if(choice == 'b')
    {
        // b - delete an element from a specific position
        int element1, position1;
        printf("Enter the position of the element to delete: ");
        scanf("%d", &position1);
        if (position1 < 0 || position1 >= n)
        {
            printf("Invalid position!\n");
        }
        else
        {
            for (int i = position1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            printf("Element deleted successfully.\n");
        }
        printf("Array after deletion:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    else if(choice == 'c')
    {
        // c - linear search to search an element
        int element2;
        printf("Enter the element to search: ");
        scanf("%d", &element2);
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == element2)
            {
                found = 1;
                printf("Element %d found at position %d.\n", element2, i);
                break;
            }
        }
        if (!found)
        {
            printf("Element %d not found in the array.\n", element2);
        }
    }

    else if (choice == 'd')
    {
        // d - traversal of the array
        printf("Array elements:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;


}