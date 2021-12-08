#include "systemc.h"
#include <iostream>

using namespace std;

SC_MODULE( Monitor ) {	
	sc_in_clk clock;
	sc_in < float > data_out;
	sc_in < bool > data_out_signal;
	
	void monitor();
	
	SC_CTOR( Monitor ) 
	{	
		SC_METHOD( monitor );
		sensitive << clock.pos();
	}
};

