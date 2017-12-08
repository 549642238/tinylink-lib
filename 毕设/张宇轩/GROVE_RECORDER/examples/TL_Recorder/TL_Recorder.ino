#include "TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(Serial.available())
    {
        char c = Serial.read();
        if(c == 'r')            // 开始录音
        {
            TL_Recorder.record();
            Serial.println("start recording...");
        }
        else if(c == 's')       // 停止录音
        {
            TL_Recorder.stopRecord();
            Serial.println("stop recording...");
        }
        else if(c == 'p')       // 播放
        {
            TL_Recorder.play();
            Serial.println("play...");
        }
    }
}
