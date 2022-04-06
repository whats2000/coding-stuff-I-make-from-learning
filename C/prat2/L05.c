#include <stdio.h>

void swap(int* a, int* b);
void bubble_sort(int arr[], size_t len);

// Use to swap two integers
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// To modify the array in order
void bubble_sort(int arr[], size_t len) {
    short is_end = 1;  // check if all have been sort

    // print the original array
    for (int j = 0; j < len; j++)
        printf("%d ", arr[j]);
    printf("\n");

    // sort by order low to high
    for (int i = 0; i < len - 1; i++) {
        is_end = 1;

        for (int j = 0; j < len - i; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                is_end = 0;
            }

        // print current array
        for (int j = 0; j < len; j++)
            printf("%d ", arr[j]);
        printf("\n");

        // if nothing have been swapped mean it is end
        if (is_end)
            break;
    }
}

int main(int argc, char* argv) {
    int len = 0;

    // input length of the array
    printf("Enter the size of the array: ");
    scanf("%d", &len);

    int arr[len];

    // input the array elements
    for (size_t i = 0; i < len; i++) {
        printf("array[%d] = ", i);

        scanf("%d", &arr[i]);
    }

    // start bubble sort the array
    bubble_sort(arr, len);
}