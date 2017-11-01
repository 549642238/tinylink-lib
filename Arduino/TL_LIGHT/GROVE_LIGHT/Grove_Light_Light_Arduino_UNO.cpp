#include "Grove_Light_Light_Arduino_UNO.h"

Grove_Light::Grove_Light():Sensor(0.0){
}

int Grove_Light::_read(){
  double intensity = (double)analogRead(LIGHT_ANALOG);
  if(intensity>=0){
    _data = intensity;
    return 0;
  }else{
    return -1;
  }
}

Grove_Light TL_Light;
