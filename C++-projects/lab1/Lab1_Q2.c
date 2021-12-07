#include <stdio.h>
#include <stdlib.h>

int main()
{
 float grade = 0.0; /* grade = 輸入數字 */
 int check = 0;     /* check = 驗證器檢驗 */

 while (grade != -1) {
  // 輸入驗證器
  do {
   printf("Please enter the score: "); /* 輸入數字 */
   check = scanf("%f", &grade);

   if (check != 1) { /* 判定是否符合float */
    printf("Input type error\n"); /* 不符合float 提示重新輸入 */
    printf("Please input again\n");
   }

   else if (grade == -1) /* -1 直接跳出迴圈 */
    break;

   else if (grade > 100 || grade < 0) { /* 判定分數範圍是否合理 */
    check = 0; /* flag 給為false */

    printf("Score is out of range\n"); /*不符合範圍 提示重新輸入*/
    printf("Please input again\n");
   }

   while (getchar() != '\n') /* 忽視掉不應該輸入字元 */
    ;
  } while (check != 1); /* 判定是否已經輸入正確數字格式 */

  if (grade != -1)
   printf("your score:%.2f\n", grade);
  else
   printf("Exit program");

  // 判定分數是否及格
  if (grade != -1) {
   if (grade >= 60)
    printf("pass!\n");

   else
    printf("failed\n");
  }
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}