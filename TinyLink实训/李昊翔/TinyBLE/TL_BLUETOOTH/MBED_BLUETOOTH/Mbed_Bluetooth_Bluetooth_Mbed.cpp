#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Bluetooth_Bluetooth_Mbed.h"

int ble_state = 0;
BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
uint8_t buf[TXRX_BUF_LEN] = {};
void connectionCallback(const Gap::ConnectionCallbackParams_t *params) {
	ble_state = 1;
	printf("Bluetooth Connected!\n");
}

void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *cbParams) {
	ble_state = 0;
	printf("Bluetooth Disconnected!\n");
	ble.gap().startAdvertising();
}

void WrittenHandler(const GattWriteCallbackParams *Handler) {
	uint16_t bytesRead;//
	//clear the buf
	for (int index = 0; index < TXRX_BUF_LEN; index++)
		buf[index] = '\0';
	//*for debug
	printf("Data Received!\n");
	//
	ble.gattServer().read(Handler->handle, buf, &bytesRead);
	memset(txValue, 0, TXRX_BUF_LEN);
	memcpy(txValue, buf, TXRX_BUF_LEN);
	//*for debug
	printf("buf=%s\n", buf);
	//ble.gap().processConnectionEvent;
}


 Mbed_Bluetooth_Bluetooth TL_Bluetooth;
