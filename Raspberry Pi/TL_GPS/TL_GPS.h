#ifndef TL_GPS_H
#define TL_GPS_H

#if PLATFORM == 4 && BOARD == 1003
	#if GPS == U_BLOX
		#include "u_blox_GPS_RPI.h"
	#endif
#endif

#endif
