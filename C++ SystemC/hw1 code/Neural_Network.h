#include "systemc.h"
#include "Neuron.h"

SC_MODULE(Neural_Network) {

 sc_in < float > input1, input2;
 sc_out < float > output;

 sc_signal < float > c1, c2;

 Neuron* N1;
 Neuron* N2;
 Neuron* N3;

 SC_CTOR(Neural_Network) {

  // vvvvv put your code here vvvvv
  N1 = new Neuron("N1");
  N2 = new Neuron("N2");
  N3 = new Neuron("N3");

  N1->input1(input1);
  N1->input2(input2);
  N1->output(c1);

  N2->input1(input1);
  N2->input2(input2);
  N2->output(c2);

  N3->input1(c1);
  N3->input2(c2);
  N3->output(output);
  // ^^^^^ put your code here ^^^^^

  N1->w1 = 10;
  N1->w2 = -10;
  N1->b = -5;
  N2->w1 = -10;
  N2->w2 = 10;
  N2->b = -5;
  N3->w1 = 10;
  N3->w2 = 10;
  N3->b = -5;
 }
};