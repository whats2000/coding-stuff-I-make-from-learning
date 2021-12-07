#include <stdio.h>
#include <stdlib.h>

// 輸入驗證器
int verfy_num(char dec[20]) {
 int num = 0; /* num = 要的返回數字 */
 int check = 0; /* check = 驗證器檢驗 */
 

 do {
  printf("Please input the %s: ", dec); /* 輸入數字 */
  check = scanf("%d", &num);

  if (check != 1) { /* 判定是否符合int */
   printf("Input type error\n"); /* 不符合int 提示重新輸入 */
   printf("Please input again\n");
  }

  while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
   ;
 } while (check != 1); /* 判定是否已經輸入正確數字格式 */

 return num;
}

int main()
{
 int height = 0; /* height = 金字塔高度 */
 int minstar = 0; /* min = 最頂上金字塔星星數 */
 int i = 0, j = 0, k = 0; /* for迴圈便量 兼容舊版c99前編譯器用 */

 // 輸入資料
 height = verfy_num("height of pyramid");
 minstar = verfy_num("min star");

 for (i = 1; i <= height; i++) { /* 一層一層做 從 (層數 = 第一層) 到 (層數 = 高度) */
  //第 i 層空格共需要 (height - i) 個
  for (j = 1; j <= height - i; j++)
   printf(" ");

  // 星星等差數列 (首項 = minstar) (公差 = 2) (項數 = n)
  for (k = 1; k <= minstar + 2 * (i - 1); k++)
   printf("*");

  printf("\n");
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}