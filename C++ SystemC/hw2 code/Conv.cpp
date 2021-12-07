#include "Conv.h"

void Conv::run() {
 // vvvvv put your code here vvvvv
 rom_addr = 109;

 rom_rd = true;

 bias = data_in;

 rom_rd = false;

 for (int m = 0; m < 3; m++)
  for (int n = 0; n < 3; n++) {
   rom_addr = 100 + 3 * m + n;

   rom_rd = true;

   kernel[m][n] = data_in;

   rom_rd = false;
  }

 for (int m = 1; m <= 8; m++) //列處理
  for (int n = 1; n <= 8; n++) { //行處理
   sum = 0;

   for (int i = -1; i <= 1; i++) //列偏移
    for (int j = -1; j <= 1; j++) { //行偏移
     rom_addr = 10 * (m + i) + (n + j);

     rom_rd = true;

     sum += data_in * kernel[i + 1][j + 1];

     rom_rd = false;
    }

   if (sum < 0)
    sum = 0;

   data_out_signal = true;

   data_out = sum;

   data_out_signal = false;
  }
 // ^^^^^ put your code here ^^^^^
}



