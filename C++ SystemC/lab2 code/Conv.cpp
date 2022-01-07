#include "Conv.h"

void Conv::run() {
 // vvvvv put your code here vvvvv
 if (rst.read()) {
  clock_cycle = 0;
  sum = 0;
  count = 0;

  rom_addr = 0;
  data_out = 0;
  rom_rd = false;
  data_out_signal = false;

  for (int i = 0; i < 9; i++)
   kernel[i] = 0;
 }
 else {
  rom_rd = true;

  // 0 ~ 9週期 緩存 kernel
  if (clock_cycle <= 9) {
   if (clock_cycle != 9)
    rom_addr.write(clock_cycle + 9);
   else
    rom_addr.write(clock_cycle - 9);

   if (clock_cycle >= 1)
    kernel[clock_cycle - 1] = data_in.read();
  }
  // 10 ~ 18週期 取得 data 並做運算
  else if (10 <= clock_cycle && clock_cycle <= 18) {
   if (clock_cycle != 18)
    rom_addr.write(clock_cycle - 9);
   else
    rom_addr.write(18);

   sum += data_in.read() * kernel[count];

   data[count] = data_in.read();

   count++;
  } // 19週期輸出
  // 19週期輸出
  else if (clock_cycle == 19) {
   sum += data_in.read();

   bias = data_in.read();

   data_out.write(sum);

   data_out_signal.write(true);

   cout << "kernel: " << endl;

   for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
     cout << kernel[3 * i + j] << " ";
    cout << endl;
   }

   cout << endl;

   cout << "data: " << endl;

   for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
     cout << data[3 * i + j] << " ";
    cout << endl;
   }

   cout << endl;

   cout << "bias: " << endl << bias << endl;

   cout << endl;
  }

  clock_cycle++;
 }
 // ^^^^^ put your code here ^^^^^
}
