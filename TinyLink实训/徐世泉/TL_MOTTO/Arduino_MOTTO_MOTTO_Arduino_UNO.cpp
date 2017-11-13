/**
 	designed by xsq
	 2017/11/1
*/
#include "Arduino_MOTTO_MOTTO_Arduino_UNO.h"

//设置电机的驱动引脚 
Internal_MOTTO::Internal_MOTTO()
{
  pinMode(mottoPin, OUTPUT);
}

//给电机设置高电平，使其转动 
void Internal_MOTTO::Run()
{
  digitalWrite(mottoPin, HIGH);
}

//给电机设置低电平，停止转动 
void Internal_MOTTO::Stop()
{
  digitalWrite(mottoPin, LOW);
}

/*
	测试程序，当输入y时舵机转动，当输入n时舵机停止转动 
*/
void Internal_MOTTO::Test()
{
	if(Serial.available()>0)
    {
      delay(100);
      char numdata = Serial.read();
      Serial.println(numdata);
      if(numdata == 'y')
	  TL_MOTTO.Run();
      else if(numdata == 'n')
      TL_MOTTO.Stop();
    
    } 
}


Internal_MOTTO TL_MOTTO;
