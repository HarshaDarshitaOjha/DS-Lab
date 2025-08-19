/* 4.2 In addition to 4.1, perform following operations using function on the single linked list:
    i. search an element in the list
    ii. sort the list in ascending order
    iii. reverse the list
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

// Traverse
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

// Search an element
void search(int key) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Sort the list (ascending)
void sortlist() {
    if (head == NULL || head->next == NULL) {
        printf("List too small to sort.\n");
        return;
    }

    struct node* i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
    traverse();
}

// Reverse the list
void reverselist() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed.\n");
    traverse();
}

// Main Menu
int main() {
    int choice, n, data, position, key;

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
        printf("5. Search element\n");
        printf("6. Sort list (ascending)\n");
        printf("7. Reverse list\n");
        printf("8. Exit\n");
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
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 6:
                sortlist();
                break;

            case 7:
                reverselist();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}