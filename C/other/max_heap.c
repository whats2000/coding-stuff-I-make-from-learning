/*
 Max Heap implementation in c
 */
#include <stdio.h>
#include <stdlib.h>
/*
 Array Implementation of MaxHeap data Structure
 */

HEAP_SIZE = 20;

struct Heap {
    int* arr;
    int count;
    int capacity;
    int heap_type;  // for min heap , 1 for max heap
};
typedef struct Heap Heap;

Heap* CreateHeap(int capacity, int heap_type);
void insert(Heap* h, int key);
void print(Heap* h);
void heapify_bottom_top(Heap* h, int index);
void heapify_top_bottom(Heap* h, int parent_node);
int PopMax(Heap* h);

int main() {
    int i;
    Heap* heap = CreateHeap(HEAP_SIZE, 1);
    if (heap == NULL) {
        printf("__Memory Issue__\n");
        return -1;
    }

    for (i = 9; i > 0; i--)
        insert(heap, i);

    print(heap);

    for (i = 9; i > 0; i--) {
        int temp = PopMax(heap);
        printf("Pop Max : %d\n", temp);
        print(heap);
    }
    return 0;
}

Heap* CreateHeap(int capacity, int heap_type) {
    Heap* h = (Heap*)malloc(sizeof(Heap));  // one is number of heap

    // check if memory allocation is fails
    if (h == NULL) {
        printf("Memory Error!");
        return NULL;
    }
    h->heap_type = heap_type;
    h->count = 0;
    h->capacity = capacity;
    h->arr = (int*)malloc(capacity * sizeof(int));  // size in bytes

    // check if allocation succeed
    if (h->arr == NULL) {
        printf("Memory Error!");
        return NULL;
    }
    return h;
}

void insert(Heap* h, int key) {
    if (h->count < h->capacity) {
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

void heapify_bottom_top(Heap* h, int index) {
    int temp;
    int parent_node = (index - 1) / 2;

    if (h->arr[parent_node] < h->arr[index]) {
        // swap and recursive call
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top(h, parent_node);
    }
}

void heapify_top_bottom(Heap* h, int parent_node) {
    // Finish your code here.
    // 交換用暫存
    int temp;
    // 小孩身處位置計算
    int left_child = parent_node * 2 + 1;
    int right_child = parent_node * 2 + 2;

    // 紀錄當前最大節點
    int biggest_node = parent_node;

    // 確認左小孩存在且是最大節點
    if (left_child < h->count && h->arr[left_child] > h->arr[biggest_node]) {
        biggest_node = left_child;
    }

    // 確認右小孩存在且是最大節點
    if (right_child < h->count && h->arr[right_child] > h->arr[biggest_node]) {
        biggest_node = right_child;
    }

    // 若小孩比家長大則交換，並往較大小孩方向遞迴
    if (biggest_node != parent_node) {
        temp = h->arr[biggest_node];
        h->arr[biggest_node] = h->arr[parent_node];
        h->arr[parent_node] = temp;

        heapify_top_bottom(h, biggest_node);
    }
}

int PopMax(Heap* h) {
    int pop;
    if (h->count == 0) {
        printf("\n__Heap is Empty__\n");
        return -1;
    }
    // replace first node by last and delete last
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count - 1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
}
void print(Heap* h) {
    int i;
    printf("==============Print Heap===============\n");
    if (h->count) {
        for (i = 0; i < h->count - 1; i++) {
            printf("%d -> ", h->arr[i]);
        }
        printf("%d\n", h->arr[h->count - 1]);
    } else
        printf("__Heap is Empty__\n");
}
