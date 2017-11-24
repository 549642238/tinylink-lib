#include "TL_Libraries.h"

 Serial pc(USBTX, USBRX);

void setup(){
	printf("USB init succeed!\n");
	TL_Bluetooth.init();
}

void loop(){
	char data[20] = "";
	if (TL_Bluetooth.recv(data)) {
		printf("data=%s\n",data);
		if(!strcmp(data,"on")) TL_LED.turnOn();
		else if(!strcmp(data, "off")) TL_LED.turnOff();
	}
	//printf("wait for data1..\n");
	
	/*char buffer[25] = {};
	pc.gets(buffer, 3);
	if (!strcmp(buffer, "of")) {
		pc.getc();
		buffer[2] = 'f';
		buffer[3] = '\0';
	}
	pc.printf("%s\n", buffer);
	if (!strcmp(buffer, "on")) {
		TL_LED.turnOn();
		pc.printf("LED ON\n");
	}
	else if (!strcmp(buffer, "off")) {
		TL_LED.turnOff();
		pc.printf("LED Off\n");
	}*/
	
}
