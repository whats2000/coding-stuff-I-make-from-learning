#include <stdio.h>
#include <stdlib.h>

#ifndef INT_MAX
#define INT_MIN (-2147483647 - 1)
#endif

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#define MAX_MATRIX_SIZE 10

void verify_num(int* num, int min, int max, int count);

// 輸入驗證器
void verify_num(int* num, int min, int max, int count) {
 int check = 0; /* check = 驗證器檢驗 */
 short i;       /* i = 向下兼容c99以下 */

 for (i = 0; i < count; i++)
  do {
   check = scanf("%d", &num[i]); /* 輸入數字 */

   if (check != 1) { /* 判定是否符合int */
    printf("Input type error at the %d element\n",
           i + 1); /* 不符合int 提示重新輸入 */
    printf("Please input again\n");

    fflush(stdin);
   } else if (min != max && min < max) /* 可以設置無上限 當min(max)固定時，max <
                                          min將不觸發，如果都未設置也不觸發 */
    if (num[i] < min || num[i] > max) { /* 判定是否符合範圍 */
     check = 0;                         /* 測試不通過 */

     printf("Input range error at the %d element\n",
            i + 1); /* 不符合範圍 提示重新輸入 */
     printf("Please input again\n");

     fflush(stdin);
    }
  } while (check != 1); /* 判定是否已經輸入正確數字格式 */
}

int main(int argc, char* argv[]) {
 long int matrix[3][MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {
     0}; /* matrix [0: a矩陣; 1: b矩陣; 2: c矩陣:] [row] [col] */
 int matrix_size[3][2] = {
     0}; /* matrix_size [0: a矩陣; 1: b矩陣; 2: c矩陣:] [0: row; 1: col;] */

 // 確保是可以相乘的矩陣
 while (1) {
  // 輸入矩陣 A: row col
  printf("Enter rows and column for the first matrix A: ");
  verify_num(matrix_size[0], 1, MAX_MATRIX_SIZE, 2);

  // 輸入矩陣 B: row col
  printf("Enter rows and column for the first matrix B: ");
  verify_num(matrix_size[1], 1, MAX_MATRIX_SIZE, 2);

  // 判定 A 的 col 是否等於 B 的 row
  if (matrix_size[0][1] == matrix_size[1][0])
   break;
  else
   printf("This matrix can't be calculated, please input again\n");
 }

 // 設定矩陣 C 為 A 的 col 及 B 的 row
 matrix_size[2][0] = matrix_size[0][0];
 matrix_size[2][1] = matrix_size[1][1];

 // 輸入矩陣 A
 printf("Enter elements of the first matrix: \n");
 for (int i = 0; i < matrix_size[0][0]; i++) {
  printf("Enter row %d: ", i + 1);
  verify_num(matrix[0][i], INT_MIN, INT_MAX, matrix_size[0][1]);
 }

 // 輸入矩陣 B
 printf("Enter elements of the second matrix:\n");
 for (int i = 0; i < matrix_size[1][0]; i++) {
  printf("Enter row %d: ", i + 1);
  verify_num(matrix[1][i], INT_MIN, INT_MAX, matrix_size[1][1]);
 }

 // 矩陣運算 i = 矩陣 A: row / 矩陣 C: row; j = 矩陣 A: col / 矩陣 B: row; k =
 // 矩陣 B: col / 矩陣 C: col
 for (int i = 0; i < matrix_size[0][0]; i++)
  for (int j = 0; j < matrix_size[0][1]; j++)
   for (int k = 0; k < matrix_size[1][1]; k++)
    matrix[2][i][k] += matrix[0][i][j] * matrix[1][j][k];

 // 輸出矩陣 C
 printf("The resultant matrix of A * B: \n");
 for (int i = 0; i < matrix_size[2][0]; i++) {
  for (int j = 0; j < matrix_size[2][1]; j++)
   printf("%d ", matrix[2][i][j]);
  printf("\n");
 }

 // 保持顯示輸出
 system("Pause");

 return 0;
}
