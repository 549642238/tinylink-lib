#ifndef ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#define ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Internal_MOTOR
{

private:
  const static int  motorPin = 8;//�����õ�����
public:
	Internal_MOTOR();//���캯��
	void turnOn();//�������
	void turnOff();//�رյ��
	/*
		���Գ���
		1�����ܣ��Ӵ������롰on��ʹ�õ������ / �Ӵ�������"off"ʹ�õ���ر�
		2�������������δ��ȫ��ȷ
			aһ��ʼ�����һ����������������ȻûЧ��
			b������ȷ�����Ի������Щʱ������on��off�����У���ʱ����Ҫ��һ��ſ��Լ���
		3)�²⣺
			a�п�������Ϊ����������߱��Ҷ��ˣ��Ӵ��������²���
	*/
	void test();
};
extern Internal_MOTOR TL_MOTOR;//����һ��ʵ��������

#endif
