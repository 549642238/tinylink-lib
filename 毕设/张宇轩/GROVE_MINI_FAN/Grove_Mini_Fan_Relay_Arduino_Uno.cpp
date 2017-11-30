#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Mini_Fan_Relay_Arduino_Uno.h"

Grove_Mini_Fan_Relay::Grove_Mini_Fan_Relay():Controller(RELAY_DIGITAL_OUTPUT){
}

Grove_Mini_Fan_Relay TL_Relay;