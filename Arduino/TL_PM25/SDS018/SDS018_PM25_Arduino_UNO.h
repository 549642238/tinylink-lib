#ifndef SDS018_PM25_ARDUINO_UNO_H
#define SDS018_PM25_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include <SoftwareSerial.h>

class T_SDS018: public Sensor<double>{
private:
  double pm25, pm10;
  int _read();
public:
  T_SDS018();
};

extern T_SDS018 TL_PM25;

#endif
