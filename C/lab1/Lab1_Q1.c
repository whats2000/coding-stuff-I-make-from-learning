#include <stdio.h>
#include <stdlib.h>

int main() {
    int num[3] = {0}; /* num = 輸入數字 */
    int check = 0;   /* check = 驗證器檢驗 */

    // 輸入驗證器
    do {
        printf("Enter three different integers: "); /* 輸入數字 */
        check = scanf("%d %d %d", &num[0], &num[1], &num[2]);

        if (check != 3) {                 /* 判定是否符合int */
            printf("Input type error\n"); /* 不符合int 提示重新輸入 */
            printf("Please input again\n");
        }
        while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
            ;
    } while (check != 3); /* 判定是否已經輸入正確數字格式 */

    // 利用氣泡排序法排列 小到大
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < 2; i++) {
            if (num[i] > num[i + 1]) {
                int temp; /* temp = 暫存器 */

                // num[i] 與 num[i+1]交換
                temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
            }
        }
    }

    // 輸出
    printf("the max number is %d\n", num[2]);
    printf("the min number is %d\n", num[0]);

    // 保持顯示輸出
    system("Pause");

    return 0;
}