#ifndef DHT11_TEMPERATURE_RPI_H
#define DHT11_TEMPERATURE_RPI_H

#include "DHT11_RPI.h"

namespace tinylink {
class DHT11_TEMPERATURE: public DHT11Sensor {
public:
    DHT11_TEMPERATURE(int pin):DHT11Sensor(pin) {}
    double data() {
        return _tem;
    }
};
}

extern tinylink::DHT11_TEMPERATURE TL_Temperature;

#endif

