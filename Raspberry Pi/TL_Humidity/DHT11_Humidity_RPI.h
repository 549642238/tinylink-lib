#ifndef DHT11_HUMIDITY_RPI_H
#define DHT11_HUMIDITY_RPI_H

#include "DHT11_RPI.h"

namespace tinylink {
class DHT11_HUMIDITY: public DHT11Sensor {
public:
    DHT11_HUMIDITY(int pin):DHT11Sensor(pin) {}
    double data() {
        return _hum;
    }
};
}

extern tinylink::DHT11_HUMIDITY TL_Humidity;

#endif

