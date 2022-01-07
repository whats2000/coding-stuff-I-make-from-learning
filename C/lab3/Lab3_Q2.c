#include <stdio.h>
#include <stdlib.h>

// 判斷質數
void is_prime_type(unsigned int x) {
 int t = 0; /* t = 判定因數暫存 */
 short flag = 0; /* flag = 判定數字依據 0: 其他; 1: 質數;  2: 合數;*/

 // x <= 2 時獨立計算
 if (x <= 2)
  if (x == 2) /* x == 2 時 flag 紀錄為 質數 */
   flag = 1;

  else
   flag = 0; /* 其餘情況 時 flag 紀錄為 其他 */

 else { /* 否則則做因數判定 */
  flag = 1; /* 預設認定為質數 */

  for (t = 2; t <= x / t; t++)
   if (x % t == 0) {
    flag = 2;
    break;
   }
 }


 if (flag == 1) /* 此時判定為質數 */
  printf("%d is prime.\n", x);

 else if (flag == 2) /* 此時判定為合數 */
  printf("%d is not a prime number. %d is a composite number\n", x, x);

 else
  printf("%d is not a prime number. %d is neither prime nor composite number.\n", x, x);
}

// 輸入驗證器
int verify_num(char dec[40], int min, int max, int exec) {
 int num = 0;   /* num = 要的返回數字 */
 int check = 0; /* check = 驗證器檢驗 */

 do {
  printf("Please input the %s: ", dec); /* 輸入數字 */
  check = scanf("%10d", &num);

  if (check != 1) { /* 判定是否符合int */
   printf("Input type error\n"); /* 不符合int 提示重新輸入 */
   printf("Please input again\n");
  }
  else if (num == exec) { /* 判定是否有特殊執行 */
   break; /* 代表有特殊執行輸入，直接結束 */
  }
  else if (min != max && min < max) /* 可以設置無上限 當min(max)固定時，max < min將不觸發，如果都未設置也不觸發 */
   if (num < min || num > max) { /* 判定是否符合範圍 */
    check = 0; /* 測試不通過 */

    printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
    printf("Please input again\n");
   }

  while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
   ;
 } while (check != 1); /* 判定是否已經輸入正確數字格式 */

 return num;
}

int main(int argc, char* argv[]) {
 int num = 0; /* num = 驗證數字 */

 while (num != -1) {
  // 驗證輸入種類驗證 種類: int; 長度: 10; 範圍: 0~2147483647; 特殊命令: -1;
  num = verify_num("number, input -1 to exit", 0, INT_MAX, -1);

  // 輸入 -1 跳出迴圈
  if (num == -1)
   break;

  else /* 輸入判定質數 */
   is_prime_type(num);
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}