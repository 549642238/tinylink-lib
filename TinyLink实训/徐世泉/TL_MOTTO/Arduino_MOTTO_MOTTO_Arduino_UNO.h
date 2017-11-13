/**
 	designed by xsq
	 2017/11/1
*/
#ifndef ARDUINO_MOTTO_MOTTO_ARDUINO_UNO_H
#define ARDUINO_MOTTO_MOTTO_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
using namespace std;

//建立一个电机驱动类 
class Internal_MOTTO
{

private:
  const static int mottoPin = 3;

public:
  Internal_MOTTO();
  void Run();
  void Stop();
  void Test();
};

extern Internal_MOTTO TL_MOTTO;

#endif
