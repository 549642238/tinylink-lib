#ifndef TL_LED_H
#define TL_LED_H

#if PLATFORM == 4 && BOARD == 1003
	#if LED == OUTLED
		#include "OUTLED_LED_RPI.h"
	#endif
#endif

#endif
