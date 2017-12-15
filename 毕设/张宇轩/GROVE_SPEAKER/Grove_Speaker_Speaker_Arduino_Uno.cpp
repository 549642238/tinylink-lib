#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Speaker_Speaker_Arduino_Uno.h"

Grove_Speaker_Speaker::Grove_Speaker_Speaker(){
	pinMode(SPEAKER_DIGITAL_OUTPUT,OUTPUT);
    digitalWrite(SPEAKER_DIGITAL_OUTPUT,LOW);
}

void Grove_Speaker_Speaker::write(int value)
{
    for(int i=0;i<100;i++)
    {
        digitalWrite(SPEAKER_DIGITAL_OUTPUT,HIGH);
        delayMicroseconds(value);
        digitalWrite(SPEAKER_DIGITAL_OUTPUT,LOW);
        delayMicroseconds(value);
    }
}

void Grove_Speaker_Speaker::sound(uint8_t index)
{	
	int BassTab[]={1911,1702,1516,1431,1275,1136,1012};//bass 1~7
	if(index<1){
		index=1;
	}
	if(index>7){
		index=7;
	}
    write(BassTab[index-1]);
}

Grove_Speaker_Speaker TL_Speaker;