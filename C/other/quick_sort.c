#include <stdio.h>
#include <time.h>
#define SIZE 20  // 陣列大小
#define MAX 100  // 亂數範圍
#define SWAP(x, y) \
    {              \
        int t;     \
        t = x;     \
        x = y;     \
        y = t;     \
    }

void genRandomIntArry(int arr[], int sizem, int max);
void printArray(int arr[], int size);
int partition(int[], int, int);
void quickSort(int[], int, int);

int main(void) {
    int arr[SIZE] = {0};
    genRandomIntArry(arr, SIZE, MAX);

    printf("before sorting\n");
    printArray(arr, SIZE);

    // implement the sorting algorithm
    // sorting(arr);
    quickSort(arr, 0, SIZE - 1);

    printf("after sorting\n");
    printArray(arr, SIZE);

    return 0;
}

void genRandomIntArry(int arr[], int size, int max) {
    int i;                        // 陣列索引
    srand((unsigned)time(NULL));  // 產生亂數種子

    // 賦予值給陣列
    for (i = 0; i < size; i++) {
        arr[i] = rand() % max + 1;  // 指定0~MAX範圍的亂數
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int number[], int left, int right) {
    // Finish your code here.
    int pivot = number[left];   // 以左側為參照點
    int left_pos = left;        // 左側位置標記
    int right_pos = right + 1;  // 右側位置標記

    // 重複執行，直到代理人相遇
    while (left_pos < right_pos) {
        // 左代理人找尋比標記點大於或等於數字位置
        while (number[++left_pos] < pivot)
            ;

        // 右代理人找尋比標記點小於或等於數字位置
        while (number[--right_pos] > pivot)
            ;

        // 若位置符合，交換左代理人與右代理人數字
        if (left_pos < right_pos)
            SWAP(number[left_pos], number[right_pos]);
    }

    // 移動標定點到右代理人數字
    SWAP(number[left], number[right_pos]);

    // 回傳分割點
    return right_pos;
}

void quickSort(int number[], int left, int right) {
    // Finish your code here.
    if (left < right) {
        // 找尋分割位置，並排序一組資料
        int partition_pos = partition(number, left, right);
        // 依照分割位置向左與右遞迴
        quickSort(number, left, partition_pos - 1);
        quickSort(number, partition_pos + 1, right);
    }
}