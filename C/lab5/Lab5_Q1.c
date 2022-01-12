#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

char* transform_string(char s[]);

// 反轉字母大小寫
char* transform_string(char s[]) {
 // 判斷字串每個字元
 for (int i = 0; i < SIZE; i++)
  // 大寫 變成 小寫
  if (s[i] >= 'A' && s[i] <= 'Z')
   s[i] = s[i] - 'A' + 'a';
  // 小寫 變成 大寫
  else if (s[i] >= 'a' && s[i] <= 'z')
   s[i] = s[i] - 'a' + 'A';
  
  return s;
}

int main(int argc, char *argv[]) {
 char str[SIZE] = {' '}; /* str = 輸入字串 */
 
 while (str[0] != '-' || str[1] != '1') {
  // 輸入
  printf("Input (Input '-1' to exit): ");

  scanf("%s", str);
 
  // 輸出
  printf("Output: %s\n", transform_string(str));
 }
 // 保持顯示輸出
 system("Pause");

 return 0;
}