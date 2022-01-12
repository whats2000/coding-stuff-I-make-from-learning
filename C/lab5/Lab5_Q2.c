#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void compare_str(char c1[], char c2[]);

// 比較字串
void compare_str(char c1[], char c2[]) {
 short is_same = 1; /* is_same = 紀錄相似性 */

 for (int i = 0; i < SIZE; i++) {
  if (c1[i] != c2[i]) {
    is_same = 0;

    break;
   }
 }

 if (is_same) 
  printf("They are same string\n");
 else 
  printf("They are different string\n");
}

int main(int argc, char *argv[]) {
 char str[2][SIZE] = {{' '}}; /* str = 輸入字串 */
 
 while ((str[0][0] != '-' || str[0][1] != '1') && 
        (str[1][0] != '-' || str[1][1] != '1')
        ) {
  // 輸入
  printf("Input string 1 (Input '-1' to exit): ");

  scanf("%s", str[0]);

  printf("Input string 2 (Input '-1' to exit): ");

  scanf("%s", str[1]);
 
  // 輸出
  compare_str(str[0], str[1]);
 }
 // 保持顯示輸出
 system("Pause");

 return 0;
}