#include <stdio.h>
#define MAX_ARR 10

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    // Finish your code here.
    // 計算兩陣列長度
    int length1 = m - l + 1;
    int length2 = r - m;

    // 宣告暫存陣列
    int arr1[MAX_ARR / 2];
    int arr2[MAX_ARR / 2];

    // 抄寫陣列
    for (int i = 0; i < length1; i++) {
        arr1[i] = arr[l + i];
    }

    for (int i = 0; i < length2; i++) {
        arr2[i] = arr[m + i + 1];
    }

    // 判斷兩陣列由頭到尾大小並塞回原始陣列
    int i = 0, j = 0, k = l;
    while (i < length1 && j < length2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // 填補剩餘值
    while (i < length1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < length2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        // Sortfirst and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    int arr[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input array: \n");
    printArray(arr, n);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Array after Merge Sort: \n");
    printArray(arr, n);

    return 0;
}
