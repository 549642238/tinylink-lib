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

extern uint8_t LedState;
extern BLEDevice ble;
void connectionCallback(const Gap::ConnectionCallbackParams_t *params);
void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params);
void onDataWrittenCallback(const GattWriteCallbackParams *params);
void bleInitComplete(BLE::InitializationCompleteCallbackContext *params);
class Mbed_Bluetooth_Bluetooth_T {
public:
	Mbed_Bluetooth_Bluetooth_T()
	{
	}
	int init(void)
	{
		// ble = BLE::Instance();
		ble.init(bleInitComplete);
		/* SpinWait for initialization to complete. This is necessary because the
		 * BLE object is used in the main loop below. */
		while (ble.hasInitialized()  == false) { /* spin loop */ }	
		return 0;
	}
	void Ble_Wait(void)
	{
		ble.waitForEvent();
	}
private:
	BLE ble;
};
typedef Mbed_Bluetooth_Bluetooth_T Mbed_Bluetooth_Bluetooth;
extern Mbed_Bluetooth_Bluetooth TL_Bluetooth;


#endif
