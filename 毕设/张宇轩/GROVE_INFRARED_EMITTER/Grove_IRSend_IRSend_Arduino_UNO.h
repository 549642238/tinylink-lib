#ifndef Grove_IRSend_IRSend_Arduino_UNO_H
#define Grove_IRSend_IRSend_Arduino_UNO_H

#include<Arduino.h>
#include "TL_Config.h"
#include "IRSendRev.h"
#include "Writer.h"

class Grove_IRSend_IRSend:public Writer<unsigned char *>
{
	private:
		IRSendRev IRSend;
		int _read();
	public:
		Grove_IRSend_IRSend();
		void write(unsigned char *data);
};

extern Grove_IRSend_IRSend TL_IRSend;

#endif
