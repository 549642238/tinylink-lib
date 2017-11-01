#ifndef TINYLINK_LED
#define TINYLINK_LED

#include "mmapGpio.h"

namespace tinylink {
class Led {
private:
    mmapGpio _gpio;
    int _pin = -1;
    int _mode = -1;
    void _digitalWrite(int value);
    int _digitalRead();
public:
    Led &setPin(int pin);
    void turnOn(void);
    void turnOff(void);
    void toggle(void);
    int state(void);
};
}

#endif
