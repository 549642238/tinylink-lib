#ifndef MBED_LED_LED_MBED_H
#define MBED_LED_LED_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

class Mbed_Led_Led_T{
public:
        DigitalOut led;
		Mbed_Led_Led_T():led(p21){
        }
        void turnOff(){
				led = 1;
        }
        void turnOn(){
				led = 0;
        }
        void toggle(){
              led = !led;
        }
};
typedef Mbed_Led_Led_T Mbed_Led_Led;
extern  Mbed_Led_Led TL_LED;

#endif