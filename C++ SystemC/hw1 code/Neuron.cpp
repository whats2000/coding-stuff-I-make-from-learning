#include "Neuron.h"

void Neuron::neuron() {

 // vvvvv put your code here vvvvv
 y = w1 * input1 + w2 * input2 + b;

 output_temp = 1 / 2 + y / 4 - pow(y, 3) / 48 + pow(y, 5) / 480;

 if (output_temp > 0.5)
  output = 1;

 else
  output = 0;
 // ^^^^^ put your code here ^^^^^
}