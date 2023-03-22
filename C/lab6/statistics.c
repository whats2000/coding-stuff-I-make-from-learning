#include <math.h>
#include <stdio.h>
#define SIZE 99  // 陣列大小

void printArray(int array[]);

int main(void) {
    // 宣告一個99個元素的整數陣列，數值範圍介於1~9之間
    int values[SIZE] = {6, 7, 8, 9, 8, 7, 8, 9, 8, 9, 7, 8, 9, 5, 9, 8, 7,
                        8, 7, 8, 6, 7, 8, 9, 3, 9, 8, 7, 8, 7, 7, 8, 9, 8,
                        9, 8, 9, 7, 8, 9, 6, 7, 8, 7, 8, 7, 9, 8, 9, 2, 7,
                        8, 9, 8, 9, 8, 9, 7, 5, 3, 5, 6, 7, 2, 5, 3, 9, 4,
                        6, 4, 7, 8, 9, 6, 8, 7, 8, 9, 7, 8, 7, 4, 4, 2, 5,
                        3, 8, 7, 5, 6, 4, 5, 6, 1, 6, 5, 7, 8, 7};
    printf("[values]\n");
    printArray(values);
    printf("\n***** Statistical Results *****\n");

    /*TO-DO*/
    int sum = 0, max = values[0], min = values[0], mode = 0;
    float avg = 0, std = 0, median = 0;

    // Sorting
    int n = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++)
            if (values[j] > values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
    }

    // Deal with sum, min, max, std
    for (int i = 0; i < SIZE; i++) {
        sum += values[i];

        if (min > values[i])
            min = values[i];

        if (max < values[i])
            max = values[i];
    }

    // Deal with avg
    avg = (float)sum / SIZE;

    // Deal with std
    for (int i = 0; i < SIZE; i++) {
        std += pow((float)values[i] - avg, 2);
    }

    std /= SIZE;
    std = sqrt(std);

    // Deal with median
    if (SIZE % 2 == 0)
        median = (values[SIZE / 2 - 1] + values[SIZE / 2]) / 2;
    else
        median = values[SIZE / 2];

    // Deal with mode
    int count = 0, max_count = 0;

    for (int i = 0; i < SIZE; i++) {
        count = 0;
        for (int j = 0; j < SIZE; j++)
            if (values[i] == values[j])
                count++;

        if (count > max_count) {
            max_count = count;
            mode = values[i];
        }
    }

    // Output
    printf("Sum : %d\n", sum);
    printf("Avg : %f\n", avg);
    printf("Std : %f\n", std);
    printf("Min : %d\n", min);
    printf("Max : %d\n", max);
    printf("Median : %f\n", median);
    printf("Mode : %d", mode);

    return 0;
}

// 將陣列內容在螢幕顯示出來
void printArray(int array[]) {
    int i;
    for (i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
