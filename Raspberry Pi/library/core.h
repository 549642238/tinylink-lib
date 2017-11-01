#ifndef TINYLINK_CORE
#define TINYLINK_CORE

#include "SERIAL_RPI.h"
#include "dtostrf.h"
#include "ESP8266_WIFI_RPI.h"
#include "grovepi.h"
#include "itoa.h"
#include "pgmspace.h"
#include "rpi_time.h"
#include "rpi_timer.h"
#include "SERIAL_RPI.h"
#include "tl_math.h"
#include "tl_network.h"
#include "tl_utils.h"
#include "UrlUtils.h"
#include "wiringSerial.h"
#include "WString.h"
#include "TL_Type.h"

extern tinylink::Serial TL_Serial;
extern tinylink::Time TL_Time;
extern BTimer TL_Timer;

#endif
