#include <stdio.h>
#include <stdlib.h>
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

// 乘法函數
unsigned long long int mult(int x, int y) {
 if (y > 0)
  return x + mult(x, y - 1); /* 等效 x 加上自己共 y 次 */
}

// 輸入驗證器
void verify_num(int* num_arr, char dec[40], int min, int max, int exec) {
 int check = 0; /* check = 驗證器檢驗 */
 short i; /* i = 向下兼容c99以下 */

 do {
  printf("Please input the %s: ", dec); /* 輸入數字 */
  check = scanf("%10d %10d", &num_arr[0], &num_arr[1]);

  if (check != 2) { /* 判定是否符合int */
   printf("Input type error\n"); /* 不符合int 提示重新輸入 */
   printf("Please input again\n");
  }
  else if (num_arr[0] == exec || num_arr[1] == exec) { /* 判定是否有特殊執行 */
   break; /* 代表有特殊執行輸入，直接結束 */
  }
  else if (min != max && min < max) /* 可以設置無上限 當min(max)固定時，max < min將不觸發，如果都未設置也不觸發 */
  for (i = 0; i < 2; i++) {
   if (num_arr[i] < min || num_arr[i] > max) { /* 判定是否符合範圍 */
    check = 0; /* 測試不通過 */

    printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
    printf("Please input again\n");
   }
  }
  
  while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
   ;
 } while (check != 2); /* 判定是否已經輸入正確數字格式 */
}

int main(int argc, char* argv[]) {
 int num[2] = {}; /* num = 驗證數字 */

 while (num[0] != -1 && num[1] != -1) {
  // 驗證輸入種類驗證 陣列: num; 種類: int; 長度: 10; 範圍: 0~2147483647; 特殊命令: -1;
  verify_num(num, "2 int number, input -1 to exit", 0, INT_MAX, -1);

  // 輸入 -1 跳出迴圈
  if (num[0] == -1 || num[1] == -1)
   break;

  else /* 開始運算乘法 */
   printf("The result is %llu\n", mult(num[0], num[1]));
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}