#include "Arduino_MOTOR_MOTOR_Arduino_UNO.h"
//���캯������ʼ��pin��
Internal_MOTOR::Internal_MOTOR()
{
  pinMode(motorPin, OUTPUT);
  
}
//�������
void Internal_MOTOR::turnOn()
{
  digitalWrite(motorPin, HIGH);
}
//�رյ��
void Internal_MOTOR::turnOff()
{
	digitalWrite(motorPin, LOW);
}
//���Գ���
void Internal_MOTOR::test() {
	Serial.begin(9600);//��ʼ������
	char buf[3] = {};//�������
	int i = 0;
	while (!Serial.available());//�ȴ�����ָ��
		while (Serial.available()) {
			buf[i] = Serial.read();
			delay(2);
			if ((++i) == 3) i = 0;
		}
		if (strcmp(buf, "on") == 0) {
			turnOn();
		}
		else if (strcmp(buf, "off") == 0) {
			turnOff();
		}
}
Internal_MOTOR TL_MOTOR;//�������ʵ��������
