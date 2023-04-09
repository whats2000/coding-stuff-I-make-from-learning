#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} ListNode;

void create_two_nodes(ListNode** list, int value_1, int value_2) {
    ListNode* head = NULL;

    head = (ListNode*)malloc(sizeof(ListNode));
    head->data = value_1;
    head->link = (ListNode*)malloc(sizeof(ListNode));
    head->link->data = value_2;
    head->link->link = NULL;

    *list = head;
}

void print_list(ListNode* head) {
    ListNode* temp;
    for (temp = head; temp != NULL; temp = temp->link)
        printf("%d ", temp->data);

    printf("\n");
}

int main(int argc, char** argv) {
    ListNode* ptr = NULL;
    create_two_nodes(&ptr, 1, 2);

    print_list(ptr);
    return 0;
}