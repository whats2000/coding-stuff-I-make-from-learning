#include <stdio.h>
#include <stdlib.h>

// 輸入驗證器
int verify_num(char dec[40], int min, int max) {
 int num = 0;   /* num = 要的返回數字 */
 int check = 0; /* check = 驗證器檢驗 */

 do {
  printf("Please input the %s: ", dec); /* 輸入數字 */
  check = scanf("%d", &num);

  if (check != 1) {                              /* 判定是否符合int */
   printf("Input type error\n"); /* 不符合int 提示重新輸入 */
   printf("Please input again\n");
  }
  else if (min != max && min < max) /* 可以設置無上限 當min(max)固定時，max < min將不觸發，如果都未設置也不觸發 */
   if (num < min || num > max) {           /* 判定是否符合範圍 */
    check = 0; /* 測試不通過 */

    printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
    printf("Please input again\n");
   }

  while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
   ;
 } while (check != 1); /* 判定是否已經輸入正確數字格式 */

 return num;
}

int main(int argc, char *argv[]) {
 int num = 0;             /* num = 輸入數字 */
 int i = 0, j = 0, k = 0; /* 兼容c99以下使用 */

 num = verify_num("number of rows", 1, INT_MAX);

 // 輸出
 printf("The Floyd’s triangle:\n");

 for (i = 0; i < num; i++) { /* i = (層數) */
  for (j = 0; j < i + 1; j++) { /* j = (每層數量) */
   printf("%d ", ++k); /* 輸出數字 */
  }

  printf("\n");
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}