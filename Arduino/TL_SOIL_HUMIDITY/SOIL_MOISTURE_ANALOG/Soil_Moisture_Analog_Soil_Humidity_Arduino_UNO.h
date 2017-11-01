#ifndef SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_ARDUINO_UNO_H
#define SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Soil_Humidity: public Sensor<double>{
private:
  int _read();
public:
  Soil_Humidity();
};

extern Soil_Humidity TL_Soil_Humidity;

#endif
