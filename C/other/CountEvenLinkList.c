#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} ListNode;

void create_ten_nodes(ListNode** list, int value[]) {
    ListNode* head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));

    ListNode* current = head;

    for (int i = 0; i <= 9; i++) {
        current->data = value[i];

        if (i <= 8) {
            current->link = (ListNode*)malloc(sizeof(ListNode));
            current = current->link;
            continue;
        }

        current->link = NULL;
    }

    *list = head;
}

int count_even_nodes(ListNode* head) {
    int count = 0;

    while (head != NULL) {
        if (head->data % 2 == 0)
            count++;

        head = head->link;
    }

    return count;
}

void print_list(ListNode* head) {
    ListNode* temp;
    for (temp = head; temp != NULL; temp = temp->link)
        printf("%d ", temp->data);

    printf("\n");
}

int main(int argc, char** argv) {
    ListNode* ptr = NULL;
    int num_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    create_ten_nodes(&ptr, num_arr);

    print_list(ptr);
    printf("Even nodes count: %d", count_even_nodes(ptr));
    return 0;
}