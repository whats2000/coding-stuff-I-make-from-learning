#include <stdio.h>
#include <stdlib.h>
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

// 二元數轉換器
unsigned long long int to_binary(int x) {
 if(x == 0)
  return 0; /* 0 時返回 0 */

 else
  return (x % 2 + 10 * to_binary(x/2)); /* 把首次餘數記在最右方， 下個記錄到下個位數 */
}

// 輸入驗證器
int verify_num(int* num, char dec[40], int min, int max, int exec) {
 int check = 0; /* check = 驗證器檢驗 */
 short i; /* i = 向下兼容c99以下 */

 do {
  printf("Please input the %s: ", dec); /* 輸入數字 */
  check = scanf("%d", num);

  if (check != 1) { /* 判定是否符合int */
   printf("Input type error\n"); /* 不符合int 提示重新輸入 */
   printf("Please input again\n");
  }
  else if (*num == exec) { /* 判定是否有特殊執行 */
   break; /* 代表有特殊執行輸入，直接結束 */
  }
  else if (min != max && min < max) /* 可以設置無上限 當min(max)固定時，max < min將不觸發，如果都未設置也不觸發 */
   if (*num < min || *num > max) { /* 判定是否符合範圍 */
    check = 0; /* 測試不通過 */

    printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
    printf("Please input again\n");
   }


  while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
   ;
 } while (check != 1); /* 判定是否已經輸入正確數字格式 */
}

int main(int argc, char* argv[]) {
 int num = 0; /* num = 驗證數字 */

 while (num != -1) {
  // 驗證輸入種類驗證 陣列: num; 種類: int; 長度: 10; 範圍: 0~2147483647; 特殊命令: -1;
  verify_num(&num, "int number, input -1 to exit", 0, INT_MAX, -1);

  // 輸入 -1 跳出迴圈
  if (num == -1)
   break;

  else {/* 開始運算二元數 */
   printf("The result is %llu\n", to_binary(num));
  }
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}