#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

#ifdef SERIAL
	#if SERIAL == ARDUINO_SERIAL
		#include "Arduino_Serial_Serial_Arduino_UNO.h"
	#endif
#endif

#ifdef TIME
	#if TIME == ARDUINO_TIME
		#include "Arduino_Time_Time_Arduino_UNO.h"
	#endif
#endif

#ifdef TIMER
	#if TIMER == ARDUINO_TIMER
		#include "Arduino_Timer_Timer_Arduino_UNO.h"
	#endif
#endif

#ifdef LED
	#if LED == ARDUINO_LED
		#include "Arduino_LED_LED_Arduino_UNO.h"
	#endif
#endif

#ifdef FAN
	#if FAN == ARDUINO_FAN
		#include "Arduino_FAN_FAN_Arduino_UNO.h"
	#endif
#endif

#ifdef PM25
	#if PM25 == SDS018
		#include "SDS018_PM25_Arduino_UNO.h"
	#endif
#endif

#ifdef BLUETOOTH
	#if BLUETOOTH == DUAL_BLE
		#include "Dual_Ble_Bluetooth_Arduino_UNO.h"
	#endif
#endif

#ifdef GPRS
  // not available
#endif

#ifdef WIFI
	#if WIFI == ESP8266
		#include "ESP8266_WiFi_Arduino_UNO.h"
	#endif
#endif

#ifdef HUMIDITY
	#if HUMIDITY == DHT11
		#include "DHT11_Humidity_Arduino_UNO.h"
	#endif
#endif

#ifdef TEMPERATURE
	#if TEMPERATURE == DHT11
		#include "DHT11_Temperature_Arduino_UNO.h"
	#endif
#endif

#ifdef GPS
	#if GPS == U_BLOX
  		#include "U_BLOX_Arduino_UNO.h"
	#endif
#endif

#ifdef STORAGEf
	#if STORAGE == SD_SHIELD
		#include "SD_Shield_Storage_Arduino_UNO.h"
	#endif
#endif




#ifdef SOUND
	// not available
#endif

#ifdef DISPLAY
	#if DISPLAY==GROVE_LCD_RGB
		#include "Grove_LCD_RGB_Display_Arduino_Uno.h"
	#endif
#endif

#ifdef RELAY
	#if RELAY == GROVE_RELAY
		#include "Grove_Relay_Relay_Arduino_Uno.h"
	#endif
#endif

#ifdef ACCELEROMETER
	#if ACCELEROMETER == GROVE_IMU9
		#include "Grove_IMU9_Accelerometer_Arduino_UNO.h"
	#endif
#endif

#ifdef MAGNET
	#if MAGNET == GROVE_IMU9
		#include "Grove_IMU9_Magnet_Arduino_UNO.h"
	#endif
#endif

#ifdef GYRO
	#if GYRO == GROVE_IMU9
		#include "Grove_IMU9_Gyro_Arduino_UNO.h"
	#endif
#endif

#endif
