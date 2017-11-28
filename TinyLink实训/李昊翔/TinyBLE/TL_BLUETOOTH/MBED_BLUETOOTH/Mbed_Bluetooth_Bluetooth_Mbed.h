#ifndef MBED_BLUETOOTH_BLUETOOTH_MBED_H
#define MBED_BLUETOOTH_BLUETOOTH_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mbed.h"
#include "BLE.h"
#include "GattCallbackParamTypes.h"
#include "TL_Config.h"
//state of ble connction
extern int state;
//ble instance
extern BLE& ble;
//buffer's max size
static const int TXRX_BUF_LEN = 20;
//call when ble connected
extern void connectionCallback(const Gap::ConnectionCallbackParams_t *params);
//call when ble disconnected
extern void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *cbParams);
//call when server ble has something to write to the client ble
extern void WrittenHandler(const GattWriteCallbackParams *Handler);
extern uint8_t buf[TXRX_BUF_LEN];
//this tinyble's name
static char DEVICE_NAME[] = "MyTinyBle";
//The UUID of the Nordic UART Service
static const uint8_t uart_base_uuid[] = { 0x71, 0x3D, 0, 0, 0x50, 0x3E, 0x4C, 0x75, 0xBA, 0x94, 0x31, 0x48, 0xF1, 0x8D, 0x94, 0x1E };
//The UUID of the TX Characteristic
static const uint8_t uart_tx_uuid[] = { 0x71, 0x3D, 0, 3, 0x50, 0x3E, 0x4C, 0x75, 0xBA, 0x94, 0x31, 0x48, 0xF1, 0x8D, 0x94, 0x1E };
//data 's payload from server ble
static uint8_t txPayload[TXRX_BUF_LEN] = { 0, };
//init the gattservice
static GattCharacteristic  txCharacteristic(uart_tx_uuid, txPayload, 1, TXRX_BUF_LEN, GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_WRITE);//| GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_WRITE_WITHOUT_RESPONSE);
static GattCharacteristic *uartChars[] = { &txCharacteristic }; 
static  GattService  uartService(uart_base_uuid, uartChars, sizeof(uartChars) / sizeof(GattCharacteristic *));

struct Mbed_Bluetooth_Bluetooth{
	
	//UARTService* uartService;
	Mbed_Bluetooth_Bluetooth(){
	}
	//init the ble to passive scanning
	int init(){
		ble.init();
		/* Set device name characteristic data */
		ble.gap().setDeviceName((const uint8_t *)DEVICE_NAME);
		/* ble's reaction when it is connected or disconnected  */
		ble.gap().onDisconnection(disconnectionCallback);/* callback: disconnectionCallback */
		ble.gap().onConnection(connectionCallback);/* callback: connectionCallback */
		/* ble's reaction when server bluetooth want to send data */
		ble.onDataWritten(WrittenHandler);/* callback: WrittenHandler */
		/*set the Advertising Type to undirected,so that every device should see the advertisement */
		ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
		/* set the payload in order to advertising */
		ble.gap().clearAdvertisingPayload();/* reset and clear Advertising payload  */
		ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED);/* Sacrifice 3B of 31B to Advertising Flags */
		ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::SHORTENED_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME)-1);/* Optional: Add name to device */
		//ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_128BIT_SERVICE_IDS,(const uint8_t *)uart_base_uuid, sizeof(uart_base_uuid));
		/* add some service to the server bluetooth */
		ble.addService(uartService);
		/* Set advertising interval. Longer interval == longer battery life *//* 100ms */
		ble.gap().setAdvertisingInterval(160);
		/* Start advertising */
		ble.gap().startAdvertising();
		return 0;
	}
		//send data from ble to the connected device
        int send(char* data){
		
		}
		//receive data from the connected device
        int recv(char* data ){
			//wait for the data from the server ble
			while(!strcmp((char*)buf,"")) {
				//printf("wait for data..\n");
				ble.waitForEvent();
			}
				//copy the data sent from server ble
				int i = 0;
				for (i = 0; buf[i] != '\0'; i++) {
					data[i] = buf[i];
				}
				data[i] = '\0';
				//clear the buffer to ready the next operation
				for (int index = 0; index < TXRX_BUF_LEN; index++)
					buf[index] = '\0';
				//return to indicate recv succeed
				return 1;
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
