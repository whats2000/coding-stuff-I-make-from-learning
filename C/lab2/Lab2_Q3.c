#include <stdio.h>
#include <stdlib.h>

// 輸入驗證器
int verify_num(char dec[40], int min, int max) {
    int num = 0;   /* num = 要的返回數字 */
    int check = 0; /* check = 驗證器檢驗 */

    do {
        printf("Please input the %s: ", dec); /* 輸入數字 */
        check = scanf("%d", &num);

        if (check != 1) {                 /* 判定是否符合int */
            printf("Input type error\n"); /* 不符合int 提示重新輸入 */
            printf("Please input again\n");
        } else if (min != max &&
                   min < max) /* 可以設置無上限 當min(max)固定時，max <
                                 min將不觸發，如果都未設置也不觸發 */
            if (num < min || num > max) { /* 判定是否符合範圍 */
                check = 0;                /* 測試不通過 */

                printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
                printf("Please input again\n");
            }

        while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
            ;
    } while (check != 1); /* 判定是否已經輸入正確數字格式 */

    return num;
}

int main() {
    short option = 0;          /* option = 用戶模式選項 */
    int height = 0, width = 0; /* height = 高度, width = 寬度 */
    int i = 0, j = 0, k = 0; /* for迴圈便量 兼容舊版c99前編譯器用 */

    option =
        verify_num("Input mode. Mode 0 = rectangle; Mode 1 = triangle; Input",
                   0, 1); /* 輸入模式，僅限0 or 1 */

    switch (option) {
        case 0:
            height = verify_num(
                "Input rectangle height", 0,
                -1); /* 輸入高度，限制大於0，上限不限 (設為比min小int) */
            width = verify_num(
                "Input rectangle width", 0,
                -1); /* 輸入寬度，限制大於0，上限不限 (設為比min小int) */

            for (i = 1; i <= height;
                 i++) { /* 高度迴圈從 (高度 = 1) 到 (高度 = height) */
                for (j = 1; j <= width;
                     j++) { /* 寬度迴圈從 (寬度 = 1) 到 (寬度 = width) */
                    printf("*");
                }

                printf("\n");
            }

            break;

        case 1:
            height = verify_num(
                "Input triangle height", 0,
                -1); /* 輸入高度，限制大於0，上限不限 (設為比min小int) */

            for (i = 1; i <= height;
                 i++) { /* 一層一層做 從 (層數 = 第一層) 到 (層數 = 高度) */
                //第 i 層空格共需要 (height - i) 個
                for (j = 1; j <= height - i; j++)
                    printf(" ");

                // 星星等差數列 (首項 = 1) (公差 = 2) (項數 = n)
                for (k = 1; k <= 1 + 2 * (i - 1); k++)
                    printf("*");

                printf("\n");
            }

            break;
    }

    // 輸出

    // 保持顯示輸出
    system("Pause");

    return 0;
}
