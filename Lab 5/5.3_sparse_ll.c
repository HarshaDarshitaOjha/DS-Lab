/* 5.3 Write a program to represent the given sparse matrix using header single linked list and
display it. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row;
    int col;
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createnode(int r, int c, int d)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> row = r;
    newnode -> col = c;
    newnode -> data = d;
    newnode -> next = NULL;
    return newnode;
}

Node* createsparse(int matrix[10][10], int r, int c)
{
    Node* head = createnode(r, c, 0);
    Node* temp = head;

    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if (matrix[i][j] != 0)
            {
                Node* newnode = createnode(i, j, matrix[i][j]);
                temp -> next = newnode;
                temp = newnode;
                count++;
            }
        }
    }

    head -> data = count;
    return head;
}

void printsparse (Node* head)
{
    printf("Sparse matrix representation (row, col, data): \n");
    printf("Rows = %d, Cols = %d, Non-zeros = %d\n", head->row, head->col, head->data);

    while (head != NULL)
    {
        printf("(%d, %d, %d)\n", head -> row, head -> col, head -> data);
        head = head -> next;
    }    
}

int main()
{
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of cols: ");
    scanf("%d", &cols);

    int matrix[10][10];
    printf("Enter the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Node* head = createsparse(matrix, rows, cols);
    printsparse(head);

    return 0;
}