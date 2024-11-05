/*
 * software_timer.h
 *
 *  Created on: Sep 15, 2024
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER2_H_
#define INC_SOFTWARE_TIMER2_H_

#include "main.h"

#define TIMER_CYCLE_2 10

/* Variables */
extern uint8_t timerFlag[5];
extern uint8_t timerEnable[5];
extern void setTimer(int index,int ms);

/*extern uint8_t timerFlag[10];
extern void setTimer(int index,int ms);*/
#endif /* INC_SOFTWARE_TIMER_H_ */
