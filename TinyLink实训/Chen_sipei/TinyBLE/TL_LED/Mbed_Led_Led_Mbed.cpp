#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Led_Led_Mbed.h"


        void Mbed_Led_Led_T::turnOff(){
				led = 1;
				stateSig = 0;
        }
        void Mbed_Led_Led_T::turnOn(){
				led = 0;
				stateSig = 1;        
		}
        void Mbed_Led_Led_T::toggle(){
              led = !led ; 
        }
        int Mbed_Led_Led_T::state(){
      		return stateSig;
        }

Mbed_Led_Led TL_LED;
