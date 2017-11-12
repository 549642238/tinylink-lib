#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Bluetooth_Bluetooth_Mbed.h"

int state = 0;
BLEDevice ble;

void connectionCallback(const Gap::ConnectionCallbackParams_t *params){
	state = 1;
}

void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *cbParams){
	state = 0;
        ble.startAdvertising();
}

struct Mbed_Bluetooth_Bluetooth TL_Bluetooth;
