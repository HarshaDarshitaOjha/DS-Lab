/* 5.1 Write a program to create a double linked list and perform the following menu-based
    operations on it:
    i. insert an element at specific position - done
    ii. delete an element from specific position
    iii. Traverse the list
*/

// double LL has prev ptr and next ptr

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node* head = NULL;

node* createnode(int data)
{
    // allocate memory for 1 new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}

// Function to insert at position
void insertatposition(int data, int pos)    // double pointer as we may chenge the head
{
    node* newnode = createnode(data);    // creates new data called data

    // if inserting in the beginning
    if(pos == 1)
    {
        newnode -> next = head;    // newnode's next points to old head
        if (head != NULL)      // if old head exists
        {
            head -> prev = newnode;  // point head ptr to prev of new node
        }
        head = newnode;    // update head to new node
        return;
    }

    // introduce temp ptr from head 
    node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)   // loop to reach one node before pos i.e. if NULL is not yet reached
    {
        temp = temp -> next;    // when reached, temp ptr shifted to next node
    }

    if (temp == NULL)   // if NULL reached before temp reaches pos
    {
        printf("Position out of range!\n");
        free(newnode);  // free memory
        return;
    }

    newnode -> next = temp -> next; // insert newnode after temp ptr which is it at pos
    newnode -> prev = temp;
    
    if (temp -> next != NULL)
    {
        temp -> next -> prev = newnode;  // fix both backward and forward links
    }
    temp -> next = newnode;
}

void deleteatposition(int pos)
{
    if (head == NULL)
    {
        printf("List is empyty\n");
        return;
    }

    node* temp = head;  // temp ptr from head

    // if deleting the first node
    if(pos == 1)
    {
        head = temp -> next;  // head moved to next node
        if(head != NULL)    // if head exists
        {
            head -> prev = NULL;  // prev of head is NULL
        }
        free(temp);
        return;
    }

    // traverse to node to be deleted
    for(int i = 1; temp != NULL && i < pos; i++)
    {
        temp = temp -> next;
    }
    if(temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    // unlink node
    if(temp -> next != NULL)    // if its not last node
    {
        temp -> next -> prev = temp -> prev;    // next node's prev points to temp's prev
    }
    if(temp -> prev != NULL)    // if its not first node
    {
        temp -> prev -> next = temp -> next;    // prev node's next points temp's next
    }

    free(temp);
}

void traverse()
{
    node* temp = head;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main()
{
    node* node0 = createnode(3);
    node* node1 = createnode(5);
    node* node2 = createnode(7);
    node* node3 = createnode(9);
    node* node4 = createnode(11);

    node0 -> next = node1;
    node0 -> prev = NULL;
    
    node1 -> next = node2;
    node1 -> prev = node0;
    
    node2 -> next = node3;
    node2 -> prev = node1;
    
    node3 -> next = node4;
    node3 -> prev = node2;
    
    node4 -> next = NULL;
    node4 -> prev = node3;

    head = node0;

    printf("Original: \n");
    traverse();
    
    int choice, data, pos;
    while(1)
    {
        printf("\n---Menu---\n");
        printf("1. Insert at position\n");
        printf("2. Delete at position\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter posotion to insert: ");
                scanf("%d", &pos);
                insertatposition(data, pos);
                traverse();
                break;
            }
            case 2:
            {
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteatposition(pos);
                traverse();
                break;
            }
            case 3:
            {
                traverse();
                break;
            }
            case 4:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("Invalide choice\n");
                break;
            }
        }
    }
    
    return 0;
}