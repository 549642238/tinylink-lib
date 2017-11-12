#ifndef MBED_BLUETOOTH_BLUETOOTH_MBED_H
#define MBED_BLUETOOTH_BLUETOOTH_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mbed.h"
#include "BLE.h"
#include "UARTService.h"
#include "TL_Config.h"

extern int state;
extern BLEDevice ble;

void connectionCallback(const Gap::ConnectionCallbackParams_t *params);

void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *cbParams);

struct Mbed_Bluetooth_Bluetooth{
	//UARTService* uartService;
	Mbed_Bluetooth_Bluetooth(){
	}
	int init(char* name){
		ble.init();
		ble.gap().onDisconnection(disconnectionCallback);
		ble.gap().onConnection(connectionCallback);
		ble.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED);
		ble.setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
		ble.accumulateAdvertisingPayload(GapAdvertisingData::SHORTENED_LOCAL_NAME, (const uint8_t *)name, sizeof(name));
		ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_128BIT_SERVICE_IDS, (const uint8_t *)UARTServiceUUID_reversed, sizeof(UARTServiceUUID_reversed));
		ble.setAdvertisingInterval(160);
		ble.gap().startAdvertising();
		//uartService = new UARTService(ble);
		return 0;
	}
        int send(char* data){
		if(state == 1){
			UARTService uartService(ble);
			int res = uartService.writeString(data);
			if(res > 0){
				return 0;
			}else{
				return -1;
			}
		}
	}
        int recv(char* data){
		
	}
	/*
	~Mbed_Bluetooth_Bluetooth(){
		if(uartService != NULL){
			delete uartService;
		}
	}*/
};

extern struct Mbed_Bluetooth_Bluetooth TL_Bluetooth;

#endif
