#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} QueueNode;

void enqueue(QueueNode** front, QueueNode** rear, int data) {
    QueueNode* newptr = (QueueNode*)malloc(sizeof(QueueNode));
    newptr->data = data;
    newptr->link = NULL;

    // Check if the queue is empty
    if (*front == NULL)
        *front = *rear = newptr;
    else {
        (*rear)->link = newptr;
        *rear = (*rear)->link;
    }
}

void dequeue(QueueNode** front, QueueNode** rear) {
    if (*rear == NULL) {
        printf("There is no node in the queue");
        return;
    }

    QueueNode* dropptr = *front;

    if (*front == *rear)
        *front = *rear = NULL;
    else
        *front = (*front)->link;

    free(dropptr);
}

void print_list(QueueNode* front) {
    QueueNode* temp;
    for (temp = front; temp != NULL; temp = temp->link)
        printf("%d ", temp->data);

    printf("\n");
}

int main(int argc, char** argv) {
    QueueNode* queue_a_front = NULL;
    QueueNode* queue_a_rear = NULL;

    for (int i = 1; i <= 10; i++)
        enqueue(&queue_a_front, &queue_a_rear, i);

    print_list(queue_a_front);

    for (int i = 1; i <= 11; i++) {
        dequeue(&queue_a_front, &queue_a_rear);
        print_list(queue_a_front);
    }

    return 0;
}