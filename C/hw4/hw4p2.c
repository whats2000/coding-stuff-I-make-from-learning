#include <stdio.h>
#include <stdlib.h>

#ifndef INT_MAX
#define INT_MIN (-2147483647 - 1)
#endif

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

int verify_num(int* num, int min, int max);

// 輸入驗證器
int verify_num(int* num, int min, int max) {
 int check = 0; /* check = 驗證器檢驗 */
 short i;       /* i = 向下兼容c99以下 */

 do {
  check = scanf("%d", num); /* 輸入數字 */

  if (check != 1) {              /* 判定是否符合int */
   printf("Input type error\n"); /* 不符合int 提示重新輸入 */
   printf("Please input again\n");
  } else if (min != max && min < max) /* 可以設置無上限 當min(max)固定時，max <
                                         min將不觸發，如果都未設置也不觸發 */
   if (*num < min || *num > max) { /* 判定是否符合範圍 */
    check = 0;                     /* 測試不通過 */

    printf("Input range error\n"); /* 不符合範圍 提示重新輸入 */
    printf("Please input again\n");
   }

  while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
   ;
 } while (check != 1); /* 判定是否已經輸入正確數字格式 */
}

int main(int argc, char* argv[]) {
 int arr[2][5] = {0}; /* arr = 輸入資料 */
 int inter[5] = {0};  /* inter = 一樣的數字暫存 */

 short count = 0; /* count = 紀錄共有幾個一樣 */

 // 輸入資料
 printf("Please enter 5 numbers of the 1st array:\n");

 for (int i = 0; i < 5; i++)
  verify_num(&arr[0][i], INT_MIN, INT_MAX);

 printf("Please enter 5 numbers of the 2nd array:\n");

 for (int i = 0; i < 5; i++)
  verify_num(&arr[1][i], INT_MIN, INT_MAX);

 // 判定是否有一樣數字，並做紀錄
 for (int i = 0; i < 5; i++)
  for (int j = 0; j < 5; j++)
   if (arr[0][i] == arr[1][j])
    inter[count++] = arr[0][i];

 // 輸出
 for (int i = 0; i < count; i++)
  if (i == 0)
   printf("{%d", inter[i]);
  else if (i == count - 1)
   printf(", %d}\n", inter[i]);
  else
   printf(", %d", inter[i]);

 if (count == 0)
  printf("Nothing the same\n");

 // 保持顯示輸出
 system("Pause");

 return 0;
}
