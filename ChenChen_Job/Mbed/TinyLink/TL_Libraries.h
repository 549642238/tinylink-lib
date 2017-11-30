#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

#ifdef TIME
	#if PLATFORM == 5 && BOARD == 1011
		#if TIME == MBED_TIME
			#include "Mbed_Time_Time_Mbed.h"
		#endif
	#endif
#endif

#ifdef LED
	#if PLATFORM == 5 && BOARD == 1011
		#if LED == MBED_LED
			#include "Mbed_Led_Led_Mbed.h"
		#endif
	#endif
#endif

#ifdef BLUETOOTH
	#if PLATFORM == 5 && BOARD == 1011
		#if BLUETOOTH == MBED_BLUETOOTH
			#include "Mbed_Bluetooth_Bluetooth_Mbed.h"
		#endif
	#endif
#endif

#ifdef ACCELERATION 
	#if PLATFORM == 5 && BOARD == 1011
		#if ACCELERATION == MBED_MPU6050
			#include "Mbed_MPU6050_Accelerometer_Mbed.h"
			// #include "other acceleration"
		#endif
	#endif
#endif

#ifdef BUTTON 
	#if PLATFORM == 5 && BOARD == 1011
		#if BUTTON == MBED_BUTTON
			#include "Mbed_Button_Button_Mbed.h"
		#endif
	#endif
#endif

#ifdef BLE_LED 
	#if PLATFORM == 5 && BOARD == 1011
		#if BLE_LED == MBED_BLE_LED
			#include "LEDService.h"
		#endif
	#endif
#endif

#endif
