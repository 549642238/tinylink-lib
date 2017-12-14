## Mbed蓝牙历程   
移植官方的main.cpp和LEDService.h文件，未按照TinyLink方式封装，已验证，可以在TinyBle上运行。  
## 步骤
手机通过LightBlue连接上LED后，通过写0x00和0x01的方式控制红色LED灯的点亮。  
绿色LED灯1s闪一次。  
写0 红灯亮  
写1 红灯灭   
移植该历程后，可以控制电机。 
