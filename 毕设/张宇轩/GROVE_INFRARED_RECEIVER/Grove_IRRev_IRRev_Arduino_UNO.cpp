#include "Grove_IRRev_IRRev_Arduino_UNO.h"
Grove_IRRev_IRRev::Grove_IRRev_IRRev():Sensor(0){
	_data=(unsigned char*)malloc(20);
}

Grove_IRRev_IRRev::~Grove_IRRev_IRRev(){
	free(_data);
}

int Grove_IRRev_IRRev::_read(){
	if(IRRev.IsDta()){
		IRRev.Recv(_data); 
		return 0;
	}else{
		return -1;
	}
}

void Grove_IRRev_IRRev::init(){
	IRRev.Init(IRREV_DIGITAL_OUTPUT);
}

Grove_IRRev_IRRev TL_IRRev;