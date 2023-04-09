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

int is_identical(ListNode* head_a, ListNode* head_b) {
    while (head_a != NULL && head_b != NULL) {
        if (head_a->data != head_b->data)
            return 0;

        head_a = head_a->link;
        head_b = head_b->link;
    }

    return (head_a == NULL && head_b == NULL);
}

void print_list(ListNode* head) {
    ListNode* temp;
    for (temp = head; temp != NULL; temp = temp->link)
        printf("%d ", temp->data);

    printf("\n");
}

int main(int argc, char** argv) {
    ListNode *ptr_a = NULL, *ptr_b = NULL, *ptr_c = NULL;
    int num_arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    create_ten_nodes(&ptr_a, num_arr1);
    create_ten_nodes(&ptr_b, num_arr1);
    create_ten_nodes(&ptr_c, num_arr2);

    printf("A B is identical: %d\n", is_identical(ptr_a, ptr_b));
    printf("A C is identical: %d\n", is_identical(ptr_a, ptr_c));

    print_list(ptr_a);
    print_list(ptr_b);
    print_list(ptr_c);
    return 0;
}