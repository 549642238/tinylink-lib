#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"
#include "core.h"

// gas sesnor

#ifdef PM25
#include "TL_PM25.h"
#endif
#ifdef PM10
#include "TL_PM10.h"
#endif

#ifdef TEMPERATURE
#include "TL_Temperature.h"
#endif

#ifdef HUMIDITY
#include "TL_Humidity.h"
#endif

#ifdef SOIL_HUMIDITY
#include "TL_Soil_Humidity.h"
#endif

#ifdef GPS
#include "TL_GPS.h"
#endif


#ifdef WIRE
#include "TL_WIRE.h"
#endif

#ifdef WIFI
#include "TL_WIFI.h"
#endif

#ifdef STORAGE
#include "TL_SD.h"
#endif

#ifdef LED
#include "TL_LED.h"
#endif

#ifdef LIGHT
#include "TL_Light.h"
#endif

#endif
