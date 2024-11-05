/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
#include "stdlib.h"
#include "software_timer2.h"
#include "global.h"
#include "input_reading.h"
#include "led_traffic.h"
#include "seg_7.h"
#include "manual.h"
#include "automatic.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EN0_Pin GPIO_PIN_1
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_2
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_3
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_4
#define EN3_GPIO_Port GPIOA
#define SEG0_Pin GPIO_PIN_5
#define SEG0_GPIO_Port GPIOA
#define SEG1_Pin GPIO_PIN_6
#define SEG1_GPIO_Port GPIOA
#define SEG2_Pin GPIO_PIN_7
#define SEG2_GPIO_Port GPIOA
#define GRE0_Pin GPIO_PIN_0
#define GRE0_GPIO_Port GPIOB
#define YE0_Pin GPIO_PIN_1
#define YE0_GPIO_Port GPIOB
#define RE0_Pin GPIO_PIN_2
#define RE0_GPIO_Port GPIOB
#define SEG3_Pin GPIO_PIN_8
#define SEG3_GPIO_Port GPIOA
#define SEG4_Pin GPIO_PIN_9
#define SEG4_GPIO_Port GPIOA
#define SEG5_Pin GPIO_PIN_10
#define SEG5_GPIO_Port GPIOA
#define SEG6_Pin GPIO_PIN_11
#define SEG6_GPIO_Port GPIOA
#define B0_Pin GPIO_PIN_13
#define B0_GPIO_Port GPIOA
#define B1_Pin GPIO_PIN_14
#define B1_GPIO_Port GPIOA
#define B2_Pin GPIO_PIN_15
#define B2_GPIO_Port GPIOA
#define GRE1_Pin GPIO_PIN_3
#define GRE1_GPIO_Port GPIOB
#define YE1_Pin GPIO_PIN_4
#define YE1_GPIO_Port GPIOB
#define RE1_Pin GPIO_PIN_5
#define RE1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
