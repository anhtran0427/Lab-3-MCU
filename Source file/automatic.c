/*
 * automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */
#include "automatic.h"

void automaticFSM(){
	switch (status){
	case INIT:
		if (true){
			status=GREEN_RED;
			prepAutomatic();
			timerFlag[3]=1;
			setTimer(2,1000);
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			timerFlag[0]=0;*/

		}
		return;
		break;
	case  GREEN_RED:
		if (timerFlag[2]==1){
				updateTimeBuffer();
				updateSegBuffer();
				//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
				setTimer(2,1000);

			}
		if (timerFlag[0]==1){
			resetTrafficDisplay();
			status=AMBER_RED;
			//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
			prepAutomatic();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			timerFlag[0]=0;*/
		}
		if(flagForButtonPress[0]==1){
			resetTrafficDisplay();
			saveStatus=status;
			status=RED_WAITING;
			prepAdjustMode();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;*/
			setTimer(1,250);
		}
		break;
	case AMBER_RED:
		if (timerFlag[2]==1){
				updateTimeBuffer();
				updateSegBuffer();
				//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
				setTimer(2,1000);

			}
		if (timerFlag[0]==1){
			resetTrafficDisplay();
			status=RED_GREEN;
			//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
			prepAutomatic();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			timerFlag[0]=0;*/
		}
		if(flagForButtonPress[0]==1){
			resetTrafficDisplay();
			saveStatus=status;
			status=RED_WAITING;
			prepAdjustMode();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;*/
			setTimer(1,250);
		}
		break;
	case RED_GREEN:
		if (timerFlag[2]==1){
				updateTimeBuffer();
				updateSegBuffer();
				//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
				setTimer(2,1000);

			}
		if (timerFlag[0]==1){
			resetTrafficDisplay();
			status=RED_AMBER;
			//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
			prepAutomatic();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			timerFlag[0]=0;*/
		}
		if(flagForButtonPress[0]==1){
			resetTrafficDisplay();
			saveStatus=status;
			status=RED_WAITING;
			prepAdjustMode();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;*/
			setTimer(1,250);
		}
		break;
	case RED_AMBER:
		if (timerFlag[2]==1){
				updateTimeBuffer();
				updateSegBuffer();
				//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
				setTimer(2,1000);

			}
		if (timerFlag[0]==1){
			resetTrafficDisplay();
			status=GREEN_RED;
			//HAL_GPIO_TogglePin(FlagCheck_GPIO_Port, FlagCheck_Pin);
			prepAutomatic();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			timerFlag[0]=0;*/
		}
		if(flagForButtonPress[0]==1){
			resetTrafficDisplay();
			saveStatus=status;
			status=RED_WAITING;
			prepAdjustMode();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;*/
			setTimer(1,250);
		}
		break;
	default:
		return;
		break;
	}
}
