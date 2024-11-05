/*
 * seg_7.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#ifndef INC_SEG_7_H_
#define INC_SEG_7_H_

#include "main.h"


#define MAX_LED 4
extern uint8_t led_buffer [4];
extern uint8_t index_led;
void segDisplay(int num);
void update7SEG ( uint8_t index );
void resetSegDisplay();

extern void updateSegBuffer();
extern void segScanning();

#endif /* INC_SEG_7_H_ */
