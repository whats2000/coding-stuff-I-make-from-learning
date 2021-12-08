#include "Monitor.h"


void Monitor:: monitor() {
	if ( data_out_signal ) {
		cout << "Result: " << data_out << endl;
		sc_stop();
	}
}


