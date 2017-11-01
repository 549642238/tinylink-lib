#ifndef DHT_11_HUMIDITY_LINKIT_ONE_H
#define DHT_11_HUMIDITY_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_one_dht.h"

#if HUMIDITY == DHT11
  #define DHTPIN HUMIDITY_DIGITAL_OUTPUT
#endif

class DHT_11_Humidity: public Sensor<double>{

private:
  DHT_Lib DHT11Humi = DHT_Lib(DHTPIN,DHT11_SENSOR);
  int _read();
public:
  DHT_11_Humidity();
};


extern DHT_11_Humidity TL_Humidity;

#endif
