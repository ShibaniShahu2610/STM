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
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define BSP_EXT_INTR_Pin GPIO_PIN_1
#define BSP_EXT_INTR_GPIO_Port GPIOA
#define BSP_EXT_INTR_EXTI_IRQn EXTI0_1_IRQn
#define BSP_LED_Pin GPIO_PIN_5
#define BSP_LED_GPIO_Port GPIOA
#define BSP_USR_INT_Pin GPIO_PIN_8
#define BSP_USR_INT_GPIO_Port GPIOA
#define BSP_USR_INT_EXTI_IRQn EXTI4_15_IRQn
#define BSP_USART1_TX_Pin GPIO_PIN_9
#define BSP_USART1_TX_GPIO_Port GPIOA
#define BSP_USART1_RX_Pin GPIO_PIN_10
#define BSP_USART1_RX_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */