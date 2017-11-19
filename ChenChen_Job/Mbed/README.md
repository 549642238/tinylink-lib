# 修改说明  
1、将LED的结构体改成Class  
2、增加按键功能  
# 资料    
https://github.com/Seeed-Studio/Tiny_BLE  
# 遇到问题  
MBed 蓝牙连接不上。2017/11/12  
## 2017/11/19更新说明  
编译环境，函数必须内联。  
修复按键Bug，多写了个延时函数。  
增加蓝牙历程，通过手机控制LED的亮灭。  
所有历程都在sketch.cpp文件中，  
#define Mbed_Led_Template//led  
#define Mbed_Ble_Led_Template//Ble_led  
#define Mbed_Button_Template//Button