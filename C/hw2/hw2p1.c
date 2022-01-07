0#include <stdio.h>
#include <stdlib.h>

// 輸入驗證器
int verify_num(char dec[40], int min, int max, int exec)
{
 int num = 0;   /* num = 要的返回數字 */
 int check = 0; /* check = 驗證器檢驗 */

 do
 {
  printf("Please input the %s: ", dec); /* 輸入數字 */
  check = scanf("%d", &num);

  if (check != 1)
  {                              /* 判定是否符合int */
   printf("Input type error\n"); /* 不符合int 提示重新輸入 */
   printf("Please input again\n");
  }
  else if (num == exec)
  {       /* 判定是否有特殊執行 */
   break; /* 代表有特殊執行輸入，直接結束 */
  }
  else if (min != max && min < max) /* 可以設置無上限 當min(max)固定時，max < min將不觸發，如果都未設置也不觸發 */
   if (num < min || num > max)
   {           /* 判定是否符合範圍 */
    check = 0; /* 測試不通過 */

    printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
    printf("Please input again\n");
   }

  while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
   ;
 } while (check != 1); /* 判定是否已經輸入正確數字格式 */

 return num;
}

int main(int argc, char *argv[])
{
 int num = 0;  /* num = 驗證數字 */
 int max = -1; /* max = 最大值 預設 -1 表示未有任何輸入 */

 while (num != -1)
 {
  num = verify_num("number, input -1 to exit", 0, INT_MAX, -1);

  if (num > max)
   max = num;
 }

 // 輸出
 if (max >= 0)
  printf("The largest number is %d.", max);
 else
  printf("No number was entered.\n");

 // 保持顯示輸出
 system("Pause");

 return 0;
}