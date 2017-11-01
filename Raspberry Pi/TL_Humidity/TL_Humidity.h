#ifndef TL_HUMIDITY_H
#define TL_HUMIDITY_H

#if PLATFORM == 4 && BOARD == 1003
	#if HUMIDITY == DHT11
		#include "DHT11_Humidity_RPI.h"
	#endif
#endif

#endif
