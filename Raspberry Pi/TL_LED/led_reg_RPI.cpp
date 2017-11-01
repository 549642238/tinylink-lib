/* Implement GPIO using registers.
 * We assume that libarmmem.so implements several functions(eg. mmap) used by mmapGpio, 
 * and libarmmem.so is conflict with valgrind. 
 */
#include "led_reg_RPI.h"
#include "mmapGpio.h"
#include <cassert>

namespace tinylink {
    Led &Led::setPin(int pin) {
        _pin = pin;
        return *this;
    }

    void Led::_digitalWrite(int value) {
        assert(_pin >= 0);
        if (_mode != mmapGpio::OUTPUT) {
            _gpio.setPinDir(_pin, mmapGpio::OUTPUT);
            _mode = mmapGpio::OUTPUT;
        }
        _gpio.writePinState(_pin, value);
    }
    int Led::_digitalRead() {
        assert(_pin >= 0);
        if (_mode != mmapGpio::INPUT) {
            _gpio.setPinDir(_pin, mmapGpio::INPUT);
            _mode = mmapGpio::INPUT;
        }
        return _gpio.readPin(_pin);
    }
    void Led::turnOn(void) {
        _digitalWrite(mmapGpio::HIGH);
    }
    void Led::turnOff(void) {
        _digitalWrite(mmapGpio::LOW);
    }
    void Led::toggle(void) {
        _digitalWrite((_digitalRead() == mmapGpio::HIGH)? mmapGpio::LOW: mmapGpio::HIGH);
    }
    int Led::state(void) {
        return _digitalRead();
    }
}
