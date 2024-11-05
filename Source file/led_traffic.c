/*
 * led_traffic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#include "led_traffic.h"


int timeDisplay[2]={5,3};
int timeDuration[3]={5,2,3};
int adjustTime;

struct trafficTable{
	uint16_t pinNum[6];
	GPIO_TypeDef* pinType[6];
}lightTable;


void initLightTable(){
	lightTable.pinNum[0]=GRE0_Pin;
	lightTable.pinNum[1]=GRE1_Pin;
	lightTable.pinNum[2]=RE0_Pin;
	lightTable.pinNum[3]=RE1_Pin;
	lightTable.pinNum[4]=YE0_Pin;
	lightTable.pinNum[5]=YE1_Pin;
	lightTable.pinType[0]=GRE0_GPIO_Port;
	lightTable.pinType[1]=GRE1_GPIO_Port;
	lightTable.pinType[2]=RE0_GPIO_Port;
	lightTable.pinType[3]=RE1_GPIO_Port;
	lightTable.pinType[4]=YE0_GPIO_Port;
	lightTable.pinType[5]=YE1_GPIO_Port;
}
//in mode 1
void trafficDisplay(){
	switch(status){
	case GREEN_RED:
		HAL_GPIO_WritePin(GRE0_GPIO_Port, GRE0_Pin,LED_ON);
		HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin,LED_ON);
		break;
	case AMBER_RED:
		HAL_GPIO_WritePin(YE0_GPIO_Port,YE0_Pin, LED_ON);
		HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin, LED_ON);
		break;
	case RED_GREEN:
		HAL_GPIO_WritePin(RE0_GPIO_Port, RE0_Pin, LED_ON);
		HAL_GPIO_WritePin(GRE1_GPIO_Port, GRE1_Pin, LED_ON);
		break;
	case RED_AMBER:
		HAL_GPIO_WritePin(RE0_GPIO_Port, RE0_Pin, LED_ON);
		HAL_GPIO_WritePin(YE1_GPIO_Port, YE1_Pin, LED_ON);
		break;
	case INIT:
		resetTrafficDisplay();
		break;
	default:
		break;
	}
}
//Supporting function
void resetTrafficDisplay(){
	for (int i=0;i<6;i++){
		HAL_GPIO_WritePin(lightTable.pinType[i], lightTable.pinNum[i], LED_OFF);
	}
}
void setTrafficDisplay(){
	for (int i=0;i<6;i++){
		HAL_GPIO_WritePin(lightTable.pinType[i], lightTable.pinNum[i], LED_ON);
	}
}
//In modification mode
void ledBlinking( ){
	switch(status){
	case RED_INCREASE:
	case RED_SET:
	case RED_WAITING:
		HAL_GPIO_TogglePin(lightTable.pinType[2], lightTable.pinNum[2]);
		HAL_GPIO_TogglePin(lightTable.pinType[3], lightTable.pinNum[3]);
		break;
	case AMBER_INCREASE:
	case AMBER_SET:
	case AMBER_WAITING:
		HAL_GPIO_TogglePin(lightTable.pinType[4], lightTable.pinNum[4]);
		HAL_GPIO_TogglePin(lightTable.pinType[5], lightTable.pinNum[5]);
		break;
	case GREEN_INCREASE:
	case GREEN_SET:
	case GREEN_WAITING:
		HAL_GPIO_TogglePin(lightTable.pinType[0], lightTable.pinNum[0]);
		HAL_GPIO_TogglePin(lightTable.pinType[1], lightTable.pinNum[1]);
		break;
	default:
		break;

	}
}

//Step in adjustMode
	void prepAdjustMode(){
		resetTrafficDisplay();
		switch (status){
		case RED_WAITING:
			adjustTime=timeDuration[RED];
			break;
		case AMBER_WAITING:
			adjustTime=timeDuration[YELLOW];
			break;
		case GREEN_WAITING:
			adjustTime=timeDuration[GREEN];
			break;
		default:
			break;
		}
		flagForButtonPress[0]=0;
		flagForButtonPress[1]=0;
		flagForButtonPress[2]=0;
	}
//Increasing step
	void increaseTime(){
		if (++adjustTime>99)adjustTime=1;
	}
//Setting step
	void setTimeDuration(){
		switch (status){
		case RED_SET:
			timeDuration[RED]=adjustTime;
			break;
		case AMBER_SET:
			timeDuration[YELLOW]=adjustTime;
			break;
		case GREEN_SET:
			timeDuration[GREEN]=adjustTime;
			break;
		default:
			break;
		}
	}
	void prepAutomatic(){
		//timerFlag[0]=0;
		switch(status){
		case GREEN_RED:
			timeDisplay[0]=timeDuration[GREEN];
			timeDisplay[1]=timeDuration[RED];
			break;
		case AMBER_RED:
			timeDisplay[0]=timeDuration[YELLOW];
			timeDisplay[1]=timeDuration[YELLOW];
			break;
		case RED_GREEN:
			timeDisplay[0]=timeDuration[RED];
			timeDisplay[1]=timeDuration[GREEN];
			break;
		case RED_AMBER:
			timeDisplay[0]=timeDuration[YELLOW];
			timeDisplay[1]=timeDuration[YELLOW];
			break;
		default:
			break;
		}
		flagForButtonPress[0]=0;
		timerFlag[0]=0;
		trafficDisplay();
	}
	void updateTimeBuffer(){
		timeDisplay[0]=timeDisplay[0]-1;
		timeDisplay[1]=timeDisplay[1]-1;
		//timerFlag[0]=0;
		if(timeDisplay[0]==0||timeDisplay[1]==0) {
			timerFlag[0]=1;
			//HAL_GPIO_WritePin(FlagCheck2_GPIO_Port, FlagCheck2_Pin,GPIO_PIN_SET);
		}
	}
	bool checkValid(){
		if (timeDuration[0]!=(timeDuration[1]+timeDuration[2])) return false;
		return true;
	}
