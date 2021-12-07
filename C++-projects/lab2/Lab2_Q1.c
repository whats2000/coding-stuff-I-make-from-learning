#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
 char str[10];      /* str[10] = 輸入數字以char array 10位儲存 */
 short check = 0; /* check = 驗證器檢驗 */
 int i = 0; /* 為了兼容c99以下版本 */

 // 輸入驗證器
 do {
  check = 1; /* 每次判定重置flag */

  printf("Enter a number: "); /* 輸入數字 */
  scanf("%s", &str);

  for (i = 0; i < strlen(str); i++) {
   if (!isdigit(str[i])) { /* 檢查輸入是否為完全數字 */
    check = 0; /* 檢驗不通過 */

    printf("Input is not all number\n");
    printf("Please input again\n");

    break; /* 終止本次判斷 */
   }
  }

 } while (!check);

 // 輸出
 printf("The number with its reverse is : ");

 for (i = strlen(str); i >= 0; i--) { /* 反向輸出陣列 */
  printf("%c", str[i]);
 }

 printf("\n");

 // 保持顯示輸出
 system("Pause");

 return 0;
}