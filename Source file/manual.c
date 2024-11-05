/*
 * manual.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */
#include "manual.h"
void adjustFSM(){
	switch (status){
	case RED_WAITING:
		if(flagForButtonPress[0]==1){
			status=AMBER_WAITING;
			prepAdjustMode();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;*/
		}
		if (flagForButtonPress[1]==1){
			status=RED_INCREASE;
		}
		if (flagForButtonPress[2]==1){
			status=RED_SET;
		}
		break;
	case RED_INCREASE:
		increaseTime();
		if (true){
			status=RED_WAITING;
			updateSegBuffer();
			flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;
		}
		break;
	case RED_SET:
		setTimeDuration();
		if (true){
			status=RED_WAITING;
			updateSegBuffer();
			flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;
		}
		break;
	case AMBER_WAITING:
		if(flagForButtonPress[0]==1){
			status=GREEN_WAITING;
			prepAdjustMode();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;*/
		}
		if (flagForButtonPress[1]==1){
			status=AMBER_INCREASE;
		}
		if (flagForButtonPress[2]==1){
			status=AMBER_SET;
		}
		break;
	case AMBER_INCREASE:
		increaseTime();
		if (true){
			status=AMBER_WAITING;
			updateSegBuffer();
			flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;
		}
		break;
	case AMBER_SET:
		setTimeDuration();
		if (true){
			status=AMBER_WAITING;
			updateSegBuffer();
			flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;
		}
		break;
	case GREEN_WAITING:
		if(flagForButtonPress[0]==1&&checkValid()){
			resetTrafficDisplay();
			status=saveStatus;
			prepAutomatic();
			updateSegBuffer();
			//flagForButtonPress[0]=0;
			//Dong bo seg display
			timerFlag[3]=1;
			index_led=0;
			setTimer(2,1000);
			//timerFlag[0]=0;
		}
		if(flagForButtonPress[0]==1&&(!checkValid())){
			status=RED_WAITING;
			prepAdjustMode();
			updateSegBuffer();
			/*flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;*/
		}
		if (flagForButtonPress[1]==1){
			status=GREEN_INCREASE;
		}
		if (flagForButtonPress[2]==1){
			status=GREEN_SET;
		}
		break;
	case GREEN_INCREASE:
		increaseTime();
		if (true){
			status=GREEN_WAITING;
			updateSegBuffer();
			flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;
		}
		break;
	case GREEN_SET:
		setTimeDuration();
		if (true){
			status=GREEN_WAITING;
			updateSegBuffer();
			flagForButtonPress[0]=0;
			flagForButtonPress[1]=0;
			flagForButtonPress[2]=0;
		}
		break;
	default:
		return;
		break;
	}
	if (timerFlag[1]==1){
		ledBlinking(RED);
		setTimer(1,250);

	}
}
