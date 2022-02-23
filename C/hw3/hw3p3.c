#include <stdio.h>
#include <stdlib.h>
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

// 乘法函數
double power(double x, unsigned int y) {
    if (y <= 1)
        return x;

    else
        return x * power(x, y - 1); /* 等效 x 乘上自己共 y 次 */
}

// 輸入驗證器
void verify_num(double* x, unsigned int* y, char dec[40], int exec) {
    int check = 0; /* check = 驗證器檢驗 */
    short i;       /* i = 向下兼容c99以下 */

    do {
        printf("Please input the %s: ", dec); /* 輸入數字 */
        check = scanf("%lf %10d", x, y);

        if (check != 2) {                 /* 判定是否符合int */
            printf("Input type error\n"); /* 不符合int 提示重新輸入 */
            printf("Please input again\n");
        } else if (*x == exec && *y == exec) { /* 判定是否有特殊執行 */
            break;           /* 代表有特殊執行輸入，直接結束 */
        } else if (*y < 1) { /* 判定是否符合範圍 */
            check = 0;       /* 測試不通過 */

            printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
            printf("Please input again\n");
        }

        while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
            ;
    } while (check != 2); /* 判定是否已經輸入正確數字格式 */
}

int main(int argc, char* argv[]) {
    double base = 0.0;    /* exp = 底數 */
    unsigned int exp = 0; /* base = 指數 */

    while (exp != -1 || base != -1) {
        // 驗證輸入種類驗證  特殊命令: -1;
        verify_num(&base, &exp, "2 int number, input '-1 -1' to exit", -1);

        // 輸入 -1 跳出迴圈
        if (base == -1 && exp == -1)
            break;

        else /* 開始運算指數 */
            printf("power(%.2lf, %u) = %.2f\n", base, exp, power(base, exp));
    }

    // 保持顯示輸出
    system("Pause");

    return 0;
}