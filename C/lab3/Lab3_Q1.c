#include <stdio.h>
#include <stdlib.h>

// 處理 x^y 整數指數
double pow_int(int x, int y) {
 double result = 1.0; /* result = 待返回數字 */

 result = 1; /* result 使乘設為 1 */ 

 // 判定 y 的數字
 if (x == 0 && y == 0) /* 0 ^ 0 升起錯誤 */
  goto InvalidError;

 else if (y == 0) /* 除底數為 0 外始終返回 1.0 */
  result = 1.0;

 else if (y > 0) /* y > 0 共需做 y 次 */
  for (int i = 0; i < y; i++)
   result *= x;

 else /* y < 0 共需做 -y 次 */
  for (int i = y; i < 0; i++)
   result *= 1.0 / x;

 return result;

 // 承擔 0 的 0 次方錯誤
InvalidError:
 printf("0 to the 0th power is meaningless ! \n");
}

int main(int argc, char* argv[]) {
 int num[2] = {}; /* num = 輸入數字 */
 int check = 0;   /* check = 驗證器檢驗 */

 while (num[0] != -1 && num[1] != -1) {
  // 輸入驗證器
  do {
   printf("Enter a base and exp (base and exp all = -1 to stop) : "); /* 輸入數字 */
   check = scanf("%10d %10d", &num[0], &num[1]);

   if (check != 2) {                              /* 判定是否符合int */
    printf("Input type error\n"); /* 不符合int 提示重新輸入 */
    printf("Please input again\n");
   }
   while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
    ;
  } while (check != 2); /* 判定是否已經輸入正確數字格式 */

  // 計算輸入
  if (num[0] == -1 && num[1] == -1) /* 終止程式指令 */
   break;

  else /* 正常執行程序 */
   printf("The exponent of the number is %.2f\n", pow_int(num[0], num[1]));
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}