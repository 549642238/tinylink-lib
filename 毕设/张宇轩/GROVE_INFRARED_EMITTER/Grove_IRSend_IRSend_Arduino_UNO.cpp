#include "Grove_IRSend_IRSend_Arduino_UNO.h"
Grove_IRSend_IRSend::Grove_IRSend_IRSend(){

}

void Grove_IRSend_IRSend::write(unsigned char *data){
    IRSend.Send(data,38);
}


Grove_IRSend_IRSend TL_IRSend;
