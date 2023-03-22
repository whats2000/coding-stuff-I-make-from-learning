#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

void printList(Node* head);
void freeList(Node*);
void insert_increase_list(Node** head, int val);

int main() {
    Node* head = NULL;
    Node* temp;
    int data;

    int arr[] = {22, 20, 23, 3, 18, 6, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        int data = arr[i];
        insert_increase_list(&head, data);
    }

    printList(head);
    freeList(head);
    return 0;
}

void freeList(Node* head) {
    Node* temp;
    for (temp = head; temp != NULL; temp = head) {
        head = head->next;
        free(temp);
    }
}

void printList(Node* head) {
    Node* temp;
    for (temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

/*TO-DO*/
void insert_increase_list(Node** head, int val) {
    Node *target, *prevptr;
    Node* newptr = (Node*)malloc(sizeof(Node));
    newptr->data = val;
    newptr->next = NULL;

    if (*head == NULL) {
        *head = newptr;
    } else if (val < (*head)->data) {
        newptr->next = *head;
        *head = newptr;
    } else {
        for (target = *head; target != NULL;) {
            prevptr = target;
            target = target->next;
            if (val < target->data) {
                newptr->next = target;
                prevptr->next = newptr;
                return;
            }

            if (target->next == NULL) {
                target->next = newptr;
                return;
            }
        }
    }
}
