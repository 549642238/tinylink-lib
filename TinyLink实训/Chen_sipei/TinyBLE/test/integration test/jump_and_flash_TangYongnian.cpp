#include "TL_Libraries.h"
//LED模块与Accelerometer模块配合使用
Serial pc(p9,p11);
short x,y,z,prex,prey,prez;
void setup()
{
    //初始化蓝牙模块
    //TL_Bluetooth.init("My device");
    //设置加速计和陀螺仪的默认倍率
    TL_Accelerometer.setFSR(2);
    //TL_Gyro.setFSR(500);
	prex=0;
	prey=0;
	prez=0;
}

void loop()
{
    TL_Accelerometer.read();
    x = TL_Accelerometer.data_x();
    y = TL_Accelerometer.data_y();
    z = TL_Accelerometer.data_z();
    //如果加速计读数发生变化,LED闪烁三次
    if(x != prex || y != prey || z != prez)
    {
		for(int i = 0 ; i < 3 ; ++ i)
        {
            TL_LED.turnOn();
            TL_Time.delayMillis(1000);
            TL_LED.turnOff();
            TL_Time.delayMillis(1000);
        }
    }
    prex = x;
    prey = y;
    prez = z;
}
