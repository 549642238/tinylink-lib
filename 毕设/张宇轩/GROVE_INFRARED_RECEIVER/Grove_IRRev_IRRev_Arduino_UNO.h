#ifndef Grove_IRRev_IRRev_Arduino_UNO_H
#define Grove_IRRev_IRRev_Arduino_UNO_H

#include<Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "IRSendRev.h"

class Grove_IRRev_IRRev:public Sensor<unsigned char *>
{
	private:
		IRSendRev IRRev;
		int _read();
	public:
		Grove_IRRev_IRRev();
		void init();
		~Grove_IRRev_IRRev();
};

extern Grove_IRRev_IRRev TL_IRRev;

#endif