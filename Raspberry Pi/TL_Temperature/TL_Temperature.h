#ifndef TL_TEMPERATURE_H
#define TL_TEMPERATURE_H

#if PLATFORM == 4 && BOARD == 1003
	#if TEMPERATURE == DHT11
		#include "DHT11_Temperature_RPI.h"
	#endif
#endif

#endif
