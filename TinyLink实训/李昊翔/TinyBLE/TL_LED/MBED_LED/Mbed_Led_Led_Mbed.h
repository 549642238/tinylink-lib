#ifndef MBED_LED_LED_MBED_H
#define MBED_LED_LED_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

struct Mbed_Led_Led{
        DigitalOut led;
        Mbed_Led_Led():led(p21){
        }
        void turnOff(){
                led = 0;
				led = 1;
        }
        void turnOn(){
                led = 1;
				led = 0;
        }
        void toggle(){
                //led = !led;
        }
};

extern struct Mbed_Led_Led TL_LED;

#endif
