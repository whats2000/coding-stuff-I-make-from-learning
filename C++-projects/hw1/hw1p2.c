#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
 char str[10];      /* str[10] = 輸入數字以char array 10位儲存 */
 int sum = 0;       /* sum = 總和 */
 short check = 0; /* check = 驗證器檢驗 */
 int i = 0; /* 為了兼容c99以下版本 */

 // 輸入驗證器
 do {
  check = 1; /* 每次判定重置flag */
  
  printf("Enter a number: "); /* 輸入數字 */
  scanf("%s", &str);

  for (i = 0; i < strlen(str); i++) {
   if (isdigit(str[i]))  /* 檢查輸入是否為完全數字 */
    sum += str[i] - '0'; /* char轉換成int並加到sum */

   else {
    check = 0; /* 檢驗不通過 */
    sum = 0; /* 重置sum */

    printf("Input is not all number\n");
    printf("Please input again\n");

    break; /* 終止本次判斷 */
   }
  }

 } while (!check);

 // 輸出
 printf("Sum of digits: %d\n", sum);

 // 保持顯示輸出
 system("Pause");

 return 0;
}