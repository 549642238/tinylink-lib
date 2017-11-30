#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Button_Button_Arduino_Uno.h"

Grove_Button_Button::Grove_Button_Button():Switch(BUTTON_DIGITAL_INPUT){
}

Grove_Button_Button TL_Button;