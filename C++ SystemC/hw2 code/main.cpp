#include "Conv.h"
#include "ROM.h"
#include "Monitor.h"
#include "clockreset.h"
#include <iostream>

using namespace std;

int sc_main( int argc, char* argv[] ) {
	
	sc_signal < bool > clk, rst;
	sc_signal < bool > rom_rd;
	sc_signal < sc_uint<7> > rom_addr;
	sc_signal < float > data_in;
	sc_signal < sc_int<19> > data_out;
	sc_signal < bool > data_out_signal;
	
	Reset m_Reset("m_Reset", 0);
	Clock m_Clock("m_Clock", 1, 215);
	ROM m_ROM( "m_ROM" );
	Conv m_Conv( "m_Conv" );
	Monitor m_Monitor( "m_Monitor" );
	
	m_Reset( rst );
	m_Clock( clk );
	m_ROM( clk, rom_rd, rom_addr, data_in );
	m_Conv( rst, clk, rom_rd, rom_addr, data_in, data_out, data_out_signal );
	m_Monitor( rst, clk, data_out, data_out_signal );
		
	sc_start( 1000, SC_NS );
	return 0;

}
