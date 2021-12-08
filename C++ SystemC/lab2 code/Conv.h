#include "systemc.h"

SC_MODULE( Conv ) {	
	sc_in_clk clk;
	sc_in < bool > rst;
	sc_in < float > data_in;
	sc_out < bool > rom_rd;
	sc_out < sc_uint<5> > rom_addr;
	sc_out < float > data_out;
	sc_out < bool > data_out_signal;
	
	void run();

	// vvvvv put your code here vvvvv
	int clock_cycle = 0;
	int count = 0;
	float kernel[9] = {};
	float sum = 0;
	float data[9] = {}; /* 打console用不參與運算 */
	float bias; /* 打console用不參與運算 */
	// ^^^^^ put your code here ^^^^^
	
	SC_CTOR( Conv )
	{	
		SC_METHOD( run );
		sensitive << clk.neg();
		dont_initialize();
	}
};





