#ifndef TL_WIFI_H
#define TL_WIFI_H

#if PLATFORM == 4 && BOARD == 1003
	#if WIFI == ESP8266
		#include "ESP8266_WIFI_RPI.h"
	#endif
#endif

#endif
