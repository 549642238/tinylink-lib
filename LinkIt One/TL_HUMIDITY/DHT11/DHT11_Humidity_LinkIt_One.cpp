#include "DHT11_Humidity_LinkIt_One.h"

DHT_11_Humidity::DHT_11_Humidity():Sensor(0.0){
  DHT11Humi.begin();
}

int DHT_11_Humidity::_read(){
  double chk = (double)DHT11Humi.readHumidity();
  if (!isnan(chk)){
    _data = chk;
    return 0;
  }
  return -1;
}

#if HUMIDITY == DHT11
  DHT_11_Humidity TL_Humidity = DHT_11_Humidity();
#endif
