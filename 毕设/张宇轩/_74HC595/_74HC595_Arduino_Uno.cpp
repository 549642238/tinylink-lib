#include <Arduino.h>
#include "TL_Config.h"
#include "_74HC595_Arduino_Uno.h"

_74HC595_SERIAL_TO_PARALLEL::_74HC595_SERIAL_TO_PARALLEL(){
	pinMode(_74HC595_DATA_DIGITAL_OUTPUT, OUTPUT);  //74HC595��14�� ������������SI 
	pinMode(_74HC595_LATCH_DIGITAL_OUTPUT, OUTPUT);  //74hc595��12�� ����洢��������RCK 
	pinMode(_74HC595_CLOCK_DIGITAL_OUTPUT, OUTPUT);  //74hc595��11�� ʱ���� SCK
}

void _74HC595_SERIAL_TO_PARALLEL::pinOut(int value){
	digitalWrite(_74HC595_LATCH_DIGITAL_OUTPUT, LOW);//
	shiftOut(_74HC595_DATA_DIGITAL_OUTPUT, _74HC595_CLOCK_DIGITAL_OUTPUT, MSBFIRST, value);//���������������λ����
	digitalWrite(_74HC595_LATCH_DIGITAL_OUTPUT, HIGH);//����
}



_74HC595_SERIAL_TO_PARALLEL TL_74HC595;