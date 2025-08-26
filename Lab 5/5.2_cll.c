/*5.2 Write a program to create a circular linked list and display the elements of the list.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;

node* head = NULL;

node* createnode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

void printlist(node* head)
{
    node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // stop when we circle back

    printf("(back to head)\n");

}

int main()
{
    
    node* node0 = createnode(0);
    node* head = node0;
    node* node1 = createnode(1);
    node* node2 = createnode(2);
    node* node3 = createnode(3);
    node* node4 = createnode(4);
    node* node5 = createnode(5);

    node0 -> next = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node0;

    printlist(node0);

    return 0;
}