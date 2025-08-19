/* 4.1 Write a program to create a single linked list of n nodes and perform the following menu-based operations on it using function:
    i. Insert a node at specific position
    ii. Deletion of an element from specific position
    iii. Count nodes
    iv. Traverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Function to create initial linked list
void createlist(int n) {
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int data;
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    struct node* temp = head;
    for (int i = 2; i <= n; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;
    }
}

// Traverse function
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at a specific position
void insertatposition(int data, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if (position < 1) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    if (position == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        struct node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range.\n");
            free(newnode);
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Node inserted at position %d.\n", position);
    traverse();
}

// Delete at a specific position
void deleteatposition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
        printf("Node at position 1 deleted.\n");
        traverse();
        return;
    }

    struct node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted.\n", position);
    traverse();
}

// Count nodes
int countnodes() {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main Menu
int main() {
    int choice, n, data, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    traverse();

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at position\n");
        printf("2. Delete at position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertatposition(data, position);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteatposition(position);
                break;

            case 3:
                printf("Number of nodes = %d\n", countnodes());
                break;

            case 4:
                traverse();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}