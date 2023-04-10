#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} DoublyNode;

void insert_node(DoublyNode* head, DoublyNode* newptr) {
    newptr->prev = head;
    newptr->next = head->next;
    if (head->next != NULL) {
        head->next->prev = newptr;
    }
    head->next = newptr;
}

void delete_node(DoublyNode* head, DoublyNode* deleteptr) {
    if (head == deleteptr) {
        printf("Deletion of head node not permitted.\n");
    } else {
        deleteptr->prev->next = deleteptr->next;
        deleteptr->next->prev = deleteptr->prev;
        free(deleteptr);
    }
}

void print_list(DoublyNode* head) {
    DoublyNode* current = head->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    DoublyNode* head = (DoublyNode*)malloc(sizeof(DoublyNode));
    head->data = -1;
    head->prev = NULL;
    head->next = NULL;

    DoublyNode* new_node1 = (DoublyNode*)malloc(sizeof(DoublyNode));
    new_node1->data = 1;

    DoublyNode* new_node2 = (DoublyNode*)malloc(sizeof(DoublyNode));
    new_node2->data = 2;

    DoublyNode* new_node3 = (DoublyNode*)malloc(sizeof(DoublyNode));
    new_node3->data = 3;

    insert_node(head, new_node1);
    insert_node(head, new_node2);
    insert_node(head, new_node3);

    print_list(head);  // should print "3 2 1"

    delete_node(head, new_node2);

    print_list(head);  // should print "3 1"

    delete_node(head, head);

    free(head);
    free(new_node1);
    free(new_node3);

    return 0;
}