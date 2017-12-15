#ifndef Grove_Recorder_Recorder_ARDUINO_UNO_H
#define Grove_Recorder_Recorder_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Grove_Recorder_Recorder{
public:
	Grove_Recorder_Recorder();
	void record();
	void stopRecord();
	void play();
};

extern Grove_Recorder_Recorder TL_Recorder;

#endif
