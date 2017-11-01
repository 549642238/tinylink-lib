#ifndef DHT_11_TEMPERATURE_LINKIT_ONE_H
#define DHT_11_TEMPERATURE_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_one_dht.h"

#if TEMPERATURE == DHT11
  #define DHTPIN TEMPERATURE_DIGITAL_OUTPUT
#endif

class DHT_11_Temperature: public Sensor<double>{
private:
  DHT_Lib DHT11Temp = DHT_Lib(DHTPIN,DHT11_SENSOR);
  int _read();
public:
  DHT_11_Temperature();
};

extern DHT_11_Temperature TL_Temperature;

#endif
