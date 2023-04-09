#include <stdio.h>
#define MAX_QUEUE_SIZE 5

int front = -1, rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int data) {
    if ((rear + 1) % MAX_QUEUE_SIZE == front) {
        printf("The queue is full\n");
        return;
    }

    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = data;

    if (front == -1)
        front = 0;

    printf("Added item: %d\n", queue[rear]);
}

void dequeue() {
    if (front == -1) {
        printf("The queue is empty\n");
        return;
    }

    printf("Drop item %d\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else
        front = (front + 1) % MAX_QUEUE_SIZE;
}

int main() {
    // 测试插入和删除操作
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);  // 插入一个元素，队列已满，无法插入
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();  // 删除一个元素，队列已空，无法删除
    return 0;
}
