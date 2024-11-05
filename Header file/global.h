/*
 * gloabl.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
//STATUS OF FINITE STATE MACHINE
extern int status;
extern int saveStatus;


#define INIT -1
#define GREEN_RED 0
#define AMBER_RED 1
#define RED_GREEN 2
#define RED_AMBER 3

#define RED_WAITING 4
#define RED_INCREASE 5
#define RED_SET 6

#define AMBER_WAITING 7
#define AMBER_INCREASE 8
#define AMBER_SET 9

#define GREEN_WAITING 10
#define GREEN_INCREASE 11
#define GREEN_SET 12

#endif /* INC_GLOBAL_H_ */
