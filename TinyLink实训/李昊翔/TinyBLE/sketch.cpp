#include "TL_Libraries.h"

void setup(){
	TL_Bluetooth.init();
	printf("Bluetooth init succeed!\n");
}

void loop(){
	char data[20] = "";
		TL_Bluetooth.recv(data);
		printf("data=%s\n",data);
		if(!strcmp(data,"on")) {
			TL_LED.turnOn();
		}
		else if(!strcmp(data, "off")) {
			TL_LED.turnOff();
		}
}

