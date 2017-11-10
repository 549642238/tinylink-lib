#include "Arduino_MOTOR_MOTOR_Arduino_UNO.h"
//构造函数，初始化pin脚
Internal_MOTOR::Internal_MOTOR()
{
  pinMode(motorPin, OUTPUT);
  
}
//开启电机
void Internal_MOTOR::turnOn()
{
  digitalWrite(motorPin, HIGH);
}
//关闭电机
void Internal_MOTOR::turnOff()
{
	digitalWrite(motorPin, LOW);
}
//测试程序
void Internal_MOTOR::test() {
	Serial.begin(9600);//初始化串口
	char buf[3] = {};//存放命令
	int i = 0;
	while (!Serial.available());//等待键入指令
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
Internal_MOTOR TL_MOTOR;//定义这个实例化对象
