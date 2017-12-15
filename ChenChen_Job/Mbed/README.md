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
 

## 2017/11/26 更新说明  
移植加速度，加速度值可以通过串口打印，串口波特率为9600。  
## 2017/12/3  
修改加速度接口，既可以支持读取原始数据，又可以获取姿态信息。  
## MPU6050 DMP说明  
### DMP和DMP特性
DMP是InvenSense MPU(运动处理器)设备独有的硬件特性，它可以通过传感器数值计算四元数，执行设备校准，也包括注入计步器等针对特定应用的特性。DMP映像（固件）存储在MPU的非永久性存储器上，需要在每次芯片上电时更新到DMP内，以使能此功能。Motion Driver的DMP映像支持的特性包括：  
#### DMP_FEATURE_LP_QUAT：
DMP以200Hz的频率根据陀螺仪的数据计算三轴四元数，低功耗。  
#### DMP_FEATURE_6X_LP_QUAT
DMP以200Hz的频率根据陀螺仪和加速度计的数据融合计算四元数并输出，低功耗。  
#### DMP_FEATURE_TAP
这是一个“轻敲”手势特性，可识别出轻敲事件并分辨其基本的特征，比如单击、双击，或者轻敲的方向。  
####DMP_FEATURE_ANDROID_ORIENT
此功能是兼容谷歌Motion Driver设备显示方向的实现。此功能包括一个状态机，它计算显示方向。
#### DMP_PEDOMETER
计步特性，一直使能，在MPU上电后即在DMP中运行。Motion Driver 库可以复位计步器步数值，查询步行时间，以及返回步数。为改善精度、避免误判，在更新步数前会有7步的延时。此特性随DMP的使能一直使能。
#### DMP_FEATURE_GYRO_CAL：此特性将在每次设备静止超过8秒时，校准陀螺仪零偏。
#### DMP_FEATURE_SEND_RAW_ACCEL
将加速度计的raw轴（偏航）的数据放入FIFO，此数据基于芯片坐标系。  
#### DMP_FEATURE_SEND_RAW_GYRO
将陀螺仪的raw轴（偏航）的数据放入FIFO，此数据基于芯片坐标系。  
#### DMP_FEATURE_SEND_CAL_GYRO
将陀螺仪的校准后的数据放入FIFO。不可与DMP_FEATURE_SEND_RAW_GYRO结合使用。输出不基于芯片frame，而是基于设备frame或者体frame。
#加载并使能DMP特性的步骤  
更新映像和初始化DMP特性。  
推送DMP映像到MPU内存：提供了dmp_load_motion_driver_firmware函数帮助实现此任务  
推送陀螺仪和加速度计的方向矩阵到DMP：可以发送方向矩阵到DMP来转换输出为参考板子或设备坐标系的输出。dmp_set_orientation () 函数用来更新方向矩阵。  
DMP回调函数：一些DMP特性注册回调函数向主程序传递警讯，这些回调函数在诸如方向准备、检测到轻触等DMP特性下触发。在Motion Driver里提供了一些函数作为例子，比如方向改变特性，将触发dmp_register_android_orient_cb(android_orient_cb);。注意注册一个回调函数并不意味着默认打开了该特性。  
使能DMP特性：提供了函数 dmp_enable_feature ();  
数据速率：FIFO速率定义了DMP的输出速率，可以通过函数 mpu_set_fifo_rate (input)更新。
