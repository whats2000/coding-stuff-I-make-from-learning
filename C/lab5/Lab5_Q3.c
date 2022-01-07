#include <stdio.h>
#include <stdlib.h>
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

void list_sum_of_two_sqrt(int num);
int verify_num(int* num, char dec[40], int min, int max, int exec);

// 方法尋找器
void list_sum_of_two_sqrt(int num) {
 short is_found = 0; /* is_found = 紀錄是否找到 */

 // 從所有可能值尋找 第一層 只須找到 根號(num)
 for (int i = 0; i * i <= num; i++)
  // 第二層只須找到比 i 值小位置
  for (int j = 0; j <= i; j++) 
   // 判定是否符合 i^2 + j^2 = num
   if (i * i + j * j == num) {
    printf("x = %d y = %d, %d^2 + %d^2 = %d\n",j ,i , j, i, num);

    if(!is_found) 
     is_found = 1;
   }
  
  if(!is_found)
   printf("No found\n");
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
  // 開始運算方法
  else {
   list_sum_of_two_sqrt(num);
  }
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}