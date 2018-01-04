The TL_Gyro module provides some basic functions for gyroscope sensor.、

#read()

Description
Reads gyroscope data once from the sensor and stores it in the buffer.(the reading operation is blocking)
Syntax
int read()
Parameters
none
Return
int: 0 if successes, -1 if fail
Usage
TL_Gyro.read()
data_x()

Description
Reads gyroscope data in x direction from the buffer
Syntax
double data_x()
Parameters
none
Return
double: gyroscope data in x direction stored in the buffer
Usage
TL_Gyro.data_x()
data_y()

Description
Reads gyroscope data in y direction from the buffer
Syntax
double data_y()
Parameters
none
Return
double: gyroscope data in y direction stored in the buffer
Usage
TL_Gyro.data_y()
data_z()

Description
Reads gyroscope data in z direction from the buffer
Syntax
double data_z()
Parameters
none
Return
double: gyroscope data in z direction stored in the buffer
Usage
TL_Gyro.data_z()
Example
void setup() {
    TL_Serial.begin(9600);
}

void loop() {
    TL_Gyro.read();
    TL_Serial.print("Gyroscope data is ");
    String data = String(TL_Gyro.data_x())+","+String(TL_Gyro.data_y())+","+String(TL_Gyro.data_z());
    TL_Serial.println(data);
    TL_Time.delayMillis(1000);   
}
