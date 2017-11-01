#include "Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO.h"

Soil_Humidity::Soil_Humidity():Sensor(0.0){
}

int Soil_Humidity::_read(){
  double soil_humidity = (double)analogRead(SOIL_HUMIDITY_ANALOG);
  if(soil_humidity>=0){
    _data = soil_humidity;
    return 0;
  }else{
    return -1;
  }
}

Soil_Humidity TL_Soil_Humidity;
