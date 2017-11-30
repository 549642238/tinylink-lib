#ifndef GROVE_Speaker_Speaker_ARDUINO_UNO_H
#define GROVE_Speaker_Speaker_ARDUINO_UNO_H

#include "Writer.h"

class Grove_Speaker_Speaker:public Writer<int>{
private:
	//int state;
public:
	Grove_Speaker_Speaker();
	void write(int value);  //根据频率发声
	void sound(uint8_t index);  //1-7音符
};

extern Grove_Speaker_Speaker TL_Speaker;

#endif