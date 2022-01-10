#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

short is_triangle_num(int num);
int letter_to_int(char str[], size_t len);

// 判定是否為 traingle number
short is_triangle_num(int num) {
 // 負數直接返回
 if (num < 0)
  return 0;

 int sum = 0; /* sum = 累加判定用 */

 // 開始做累加
 for (int i = 0; i < num; i++) {
  sum += i;

  // 當累加 sum 與判定數 num 相等時是 triangle number
  if (sum == num)
   return 1;
 }

 // 都不相等則為非 triangle number
 return 0;
}

// 把字串轉成整數
int letter_to_int(char str[], size_t len) {
 int temp_sum = 0; /* temp_sum = 返回值暫存器 */

 // 讀取字串 str
 for (int i = 0; i < len; i++) {
  // 在字串不為空下
  if ((int)str[i] != 0)
   temp_sum +=
       (int)str[i] - (int)'a' + 1; /* 將該字元轉成數字 並加入暫存器 temp_sum */
 }

 return temp_sum;
}

int main(int argc, char* argv[]) {
 char letter[10]; /* letter = 輸入資料 */

 printf("Enter a word: ");

 scanf("%s", letter);

 // 判定是否為 traingle number
 if (is_triangle_num(letter_to_int(letter, 10)))
  printf("%s is a triangle word\n");
 else
  printf("%s is not a triangle word\n");

 // 保持顯示輸出
 system("Pause");

 return 0;
}
