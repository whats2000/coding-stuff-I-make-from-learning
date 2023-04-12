#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coefficient;
    int exponent;
    struct node* next;
} PolyNode;

void insert(PolyNode** head, int coefficient, int exponent) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = *head;
    *head = newNode;
}

PolyNode* add_polynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    PolyNode** tail = &result;

    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            insert(tail, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insert(tail, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insert(tail, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        tail = &((*tail)->next);
    }

    while (poly1) {
        insert(tail, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
        tail = &((*tail)->next);
    }

    while (poly2) {
        insert(tail, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
        tail = &((*tail)->next);
    }

    return result;
}

void print_polynomial(PolyNode* poly) {
    while (poly) {
        printf("%dX^%d ", poly->coefficient, poly->exponent);
        if (poly->next) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    // Create the first polynomial: 3X^2 + 2X + 1
    PolyNode* poly1 = NULL;
    insert(&poly1, 3, 2);
    insert(&poly1, 2, 1);
    insert(&poly1, 1, 0);
    printf("Poly1: ");
    print_polynomial(poly1);

    // Create the second polynomial: 4X^3 + 5X^2 + 6X + 7
    PolyNode* poly2 = NULL;
    insert(&poly2, 4, 3);
    insert(&poly2, 5, 2);
    insert(&poly2, 6, 1);
    insert(&poly2, 7, 0);
    printf("Poly2: ");
    print_polynomial(poly2);

    // Add the two polynomials together
    PolyNode* result = add_polynomials(poly1, poly2);
    printf("Result: ");
    print_polynomial(result);

    return 0;
}
