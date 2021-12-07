#include "systemc.h"

SC_MODULE(Adder) {
 sc_in < sc_uint<8> > in1, in2;
 sc_out < sc_uint<9> > out;

 void run() {
  // vvvvv put your code here vvvvv
  out = in1.read() + in2.read();
  // ^^^^^ put your code here ^^^^^
 }

 SC_CTOR(Adder) {
  SC_METHOD(run);
  sensitive << in1 << in2;
 };
};

SC_MODULE(Multiplier) {
 sc_in < sc_uint<4> > in1, in2;
 sc_out < sc_uint<8> > out;

 void run() {
  // vvvvv put your code here vvvvv
  out = in1.read() * in2.read();
  // ^^^^^ put your code here ^^^^^
 }

 SC_CTOR(Multiplier) {
  SC_METHOD(run);
  sensitive << in1 << in2;
 }

};

SC_MODULE(MAC) {
 sc_in < sc_uint<4> > in1, in2;
 sc_in < sc_uint<8> > in3;
 sc_out < sc_uint<9> > out;

 Adder* ADD_1;
 Multiplier* MUL_1;

 // vvvvv put your code here vvvvv
 sc_signal< sc_uint<8> > multiplier_to_adder;
 // ^^^^^ put your code here ^^^^^

 SC_CTOR(MAC)
 {
  // vvvvv put your code here vvvvv
  MUL_1 = new Multiplier("MUL_1");
  ADD_1 = new Adder("ADD_1");

  MUL_1->in1(in1);
  MUL_1->in2(in2);
  MUL_1->out(multiplier_to_adder);

  ADD_1->in1(in3);
  ADD_1->in2(multiplier_to_adder);
  ADD_1->out(out);
  // ^^^^^ put your code here ^^^^^
 }
};
