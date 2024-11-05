/*
 * input_reading.h
 *
 *  Created on: Sep 25, 2024
 *      Author: ASUS
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
#include"main.h"

#define NO_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

extern uint8_t flagForButtonPress [ NO_OF_BUTTONS ];
extern void button_reading();
extern void initMainTable();
extern void buttonScan();
#endif /* INC_INPUT_READING_H_ */
