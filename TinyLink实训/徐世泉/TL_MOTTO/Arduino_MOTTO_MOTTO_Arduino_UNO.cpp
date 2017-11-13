/**
 	designed by xsq
	 2017/11/1
*/
#include "Arduino_MOTTO_MOTTO_Arduino_UNO.h"

//���õ������������ 
Internal_MOTTO::Internal_MOTTO()
{
  pinMode(mottoPin, OUTPUT);
}

//��������øߵ�ƽ��ʹ��ת�� 
void Internal_MOTTO::Run()
{
  digitalWrite(mottoPin, HIGH);
}

//��������õ͵�ƽ��ֹͣת�� 
void Internal_MOTTO::Stop()
{
  digitalWrite(mottoPin, LOW);
}

/*
	���Գ��򣬵�����yʱ���ת����������nʱ���ֹͣת�� 
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
