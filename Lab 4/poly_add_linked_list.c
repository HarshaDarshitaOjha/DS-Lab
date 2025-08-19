/* 4.3 Write a program to represent the polynomial equation of single variable using single 
linked list and perform the addition of two polynomial equations. */

#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct node {
    int coeff;
    int pow;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int coeff, int pow) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->next = NULL;
    return newnode;
}

// Function to insert node at end of polynomial
void insertNode(struct node** poly, int coeff, int pow) {
    struct node* newnode = createNode(coeff, pow);

    if (*poly == NULL) {
        *poly = newnode;
        return;
    }

    struct node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Function to display polynomial
void display(struct node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            insertNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else {  // powers equal
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0)  // avoid zero terms
                insertNode(&result, sum, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // If remaining terms in poly1
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    // If remaining terms in poly2
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Main function
int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* sum = NULL;

    int n1, n2, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coeff and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertNode(&poly1, coeff, pow);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coeff and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertNode(&poly2, coeff, pow);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}
