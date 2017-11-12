#ifndef MBED_BLUETOOTH_BLUETOOTH_MBED_H
#define MBED_BLUETOOTH_BLUETOOTH_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mbed.h"
#include "BLE.h"
#include "UARTService.h"
#include "TL_Config.h"
#include "LEDService.h"

extern int state;
// extern BLEDevice ble;
extern uint8_t LedState;
void connectionCallback(const Gap::ConnectionCallbackParams_t *params);
void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params);
void onDataWrittenCallback(const GattWriteCallbackParams *params);
void bleInitComplete(BLE::InitializationCompleteCallbackContext *params);
class Mbed_Bluetooth_Bluetooth_T {
public:

	int init(void)
	{
		BLE &ble = BLE::Instance();
		ble.init(bleInitComplete);
 		// ble.init();
		// ble.gap().onDisconnection(disconnectionCallback);
		// ble.gattServer().onDataWritten(onDataWrittenCallback);

		// bool initialValueForLEDCharacteristic = false;
		// ledServicePtr = new LEDService(ble, initialValueForLEDCharacteristic);

		// /* setup advertising */
		// ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
		// ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list));
		// ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
		// ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
		// ble.gap().setAdvertisingInterval(1000); /* 1000ms. */
		// ble.gap().startAdvertising();		
		return 0;
	}
};
typedef Mbed_Bluetooth_Bluetooth_T Mbed_Bluetooth_Bluetooth;
extern Mbed_Bluetooth_Bluetooth TL_Bluetooth;


#endif
