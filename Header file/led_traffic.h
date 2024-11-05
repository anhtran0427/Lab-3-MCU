/*
 * led_traffic.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#ifndef INC_LED_TRAFFIC_H_
#define INC_LED_TRAFFIC_H_

#include "main.h"

#define RED 0
#define YELLOW 1
#define GREEN 2

#define LED_ON GPIO_PIN_SET
#define LED_OFF GPIO_PIN_RESET

extern int timeDisplay[2];
extern int timeDuration[3];
extern int adjustTime;
extern void initLightTable();

void resetTrafficDisplay();
void setTrafficDisplay();
extern void prepAdjustMode();
extern void increaseTime();
extern void setTimeDuration();
extern void prepAutomatic();
extern void updateTimeBuffer();
extern bool checkValid();
extern void trafficDisplay();
extern void ledBlinking();

#endif /* INC_LED_TRAFFIC_H_ */
