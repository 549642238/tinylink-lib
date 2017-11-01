#ifndef SDS018_PM25_LINKIT_ONE_H
#define SDS018_PM25_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class T_SDS018: public Sensor<double>{
private:
  double pm25, pm10;
  int start;
  int _read();
public:
  T_SDS018();
};

extern T_SDS018 TL_PM25;

#endif
