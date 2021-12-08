#include "Conv.h"
#include "ROM.h"
#include "Monitor.h"
#include "clockreset.h"
#include <iostream>

using namespace std;

int sc_main( int argc, char* argv[] ) {
	
	sc_signal < bool > clk, rst;
	sc_signal < bool > rom_rd;
	sc_signal < sc_uint<5> > rom_addr;
	sc_signal < float > data_in;
	sc_signal < float > data_out;
	sc_signal < bool > data_out_signal;
	
	Reset m_Reset( "m_Reset", 10 );
	Clock m_Clock( "m_Clock", 5, 1000 );
	ROM m_ROM( "m_ROM" );
	Conv m_Conv( "m_Conv" );
	Monitor m_Monitor( "m_Monitor" );
	
	m_Reset( rst );
	m_Clock( clk );
	m_ROM( clk, rom_rd, rom_addr, data_in );
	m_Conv( clk, rst, data_in, rom_rd, rom_addr, data_out, data_out_signal );
	m_Monitor( clk, data_out, data_out_signal );
		
	sc_start( 1000, SC_NS );
	return 0;

}











