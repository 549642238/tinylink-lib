#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Bluetooth_Bluetooth_Mbed.h"

int state = 0;
BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);


uint8_t buf[TXRX_BUF_LEN] = {};

ReadOnlyArrayGattCharacteristic<uint8_t, sizeof(readValue)> readChar(readCharUUID, readValue);


void connectionCallback(const Gap::ConnectionCallbackParams_t *params){
	state = 1;
	HANDLER = (GattWriteCallbackParams *)params;
	printf("Bluetooth Connected!\n");
}

void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *cbParams){
	state = 0;
	printf("Bluetooth Disconnected!\n");
    ble.gap().startAdvertising();
}
void WrittenHandler(const GattWriteCallbackParams *Handler) {
	uint16_t bytesRead, index;//
	//clear the buf
	for (int index = 0; index < TXRX_BUF_LEN; index++)
		buf[index] = '\0';
	//*for debug
	printf("Data Received!\n");
	//
	ble.gattServer().read(Handler->handle, buf, &bytesRead);
	memset(txPayload, 0, TXRX_BUF_LEN);
	memcpy(txPayload, buf, TXRX_BUF_LEN);
	//*for debug
	printf("buf=%s\n", buf);
}


 Mbed_Bluetooth_Bluetooth TL_Bluetooth;
