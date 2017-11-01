#ifndef DHT11_RPI_H
#define DHT11_RPI_H

namespace tinylink {
class DHT11Sensor {
private:
    int _pin;
protected:
    double _tem, _hum;
public:
    DHT11Sensor(int pin);
    int read(void);
    virtual double data(void) = 0;
};
}

#endif

