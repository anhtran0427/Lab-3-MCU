/*
 * input_reading.c
 *
 *  Created on: Sep 25, 2024
 *      Author: ASUS
 */
#include"input_reading.h"


static GPIO_PinState buttonBuffer [ NO_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer1 [ NO_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer2 [ NO_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer3 [ NO_OF_BUTTONS ];
uint8_t flagForButtonPress [ NO_OF_BUTTONS ];

struct buttonTable{
	uint16_t pinNum[NO_OF_BUTTONS];
	GPIO_TypeDef* pinType[NO_OF_BUTTONS];
}mainTable;

void initMainTable(){
	mainTable.pinNum[0]=B0_Pin;
	mainTable.pinNum[1]=B1_Pin;
	mainTable.pinNum[2]=B2_Pin;
	mainTable.pinType[0]=B0_GPIO_Port;
	mainTable.pinType[1]=B1_GPIO_Port;
	mainTable.pinType[2]=B2_GPIO_Port;
}

void button_reading(){
for (int i=0;i<NO_OF_BUTTONS;i++){
	debounceButtonBuffer3[i]=debounceButtonBuffer2[i];
	debounceButtonBuffer2[i]=debounceButtonBuffer1[i];
	debounceButtonBuffer1[i]=HAL_GPIO_ReadPin(mainTable.pinType[i], mainTable.pinNum[i]);

	if ((debounceButtonBuffer3[i]==debounceButtonBuffer2[i])
			&&(debounceButtonBuffer2[i]==debounceButtonBuffer1[i])){
		if (buttonBuffer[i]!=debounceButtonBuffer1[i]){
			buttonBuffer[i]=debounceButtonBuffer1[i];

			if (buttonBuffer[i]==BUTTON_IS_PRESSED){
				flagForButtonPress[i]=1;
			}
		}
	}
}
}



void buttonScan(){
	if (timerFlag[4]==1){
		button_reading();
		setTimer(4,10);
	}
}


