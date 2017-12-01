#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Water_Atomization_Arduino_Uno.h"

Grove_Water_Atomization::Grove_Water_Atomization():Controller(ATOMIZATION_DIGITAL_OUTPUT){
}

Grove_Water_Atomization TL_Atomization;