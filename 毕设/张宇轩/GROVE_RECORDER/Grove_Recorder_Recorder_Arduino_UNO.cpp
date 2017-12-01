#include "Grove_Recorder_Recorder_Arduino_UNO.h"

#define PINREC RECORDER_DIGITAL_OUTPUT
#define PINPLAY RECORDER_DIGITAL_OUTPUT1

Grove_Recorder_Recorder::Grove_Recorder_Recorder(){
	pinMode(PINREC, OUTPUT);
	pinMode(PINPLAY, OUTPUT);
	digitalWrite(PINREC, HIGH);
    digitalWrite(PINPLAY, HIGH);
}

void Grove_Recorder_Recorder::record(){
	digitalWrite(PINREC, LOW);
}

void Grove_Recorder_Recorder::stopRecord(){
	digitalWrite(PINREC, HIGH);
}

void Grove_Recorder_Recorder::play(){
	digitalWrite(PINPLAY, LOW);
    delay(100);
    digitalWrite(PINPLAY, HIGH);
}

Grove_Recorder_Recorder TL_Recorder;
