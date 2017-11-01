#include "DHT11_Temperature_LinkIt_One.h"

DHT_11_Temperature::DHT_11_Temperature():Sensor(0.0){
  DHT11Temp.begin();
}

int DHT_11_Temperature::_read(){
  double chk = (double)DHT11Temp.readTemperature();
  if (!isnan(chk)){
    _data = chk;
    return 0;
  }
  return -1;
}

#if TEMPERATURE == DHT11
  DHT_11_Temperature TL_Temperature = DHT_11_Temperature();
#endif
