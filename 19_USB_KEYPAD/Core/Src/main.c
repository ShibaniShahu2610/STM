/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include<stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define R1_PORT GPIOA
#define R1_PIN GPIO_PIN_7

#define R2_PORT GPIOA
#define R2_PIN GPIO_PIN_6

#define R3_PORT GPIOA
#define R3_PIN GPIO_PIN_5

#define R4_PORT GPIOA
#define R4_PIN GPIO_PIN_4

#define C1_PORT GPIOB
#define C1_PIN GPIO_PIN_12

#define C2_PORT GPIOB
#define C2_PIN GPIO_PIN_13

#define C3_PORT GPIOB
#define C3_PIN GPIO_PIN_14

#define C4_PORT GPIOB
#define C4_PIN GPIO_PIN_15

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
char key;
char x;
volatile int pinstatus1;
volatile int pinstatus2;
volatile int pinstatus3;
volatile int pinstatus4;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void GPIO_Initialize(void) {
	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_RESET);
}

char read_keypad(void)
{


	pinstatus1 = (HAL_GPIO_ReadPin(C1_PORT, C1_PIN));
	printf("pinstatus1 = %d\r\n",pinstatus1);

	pinstatus2 = (HAL_GPIO_ReadPin(C2_PORT, C2_PIN));
	printf("pinstatus2 = %d\r\n",pinstatus2);

	pinstatus3 = (HAL_GPIO_ReadPin(C3_PORT, C3_PIN));
	printf("pinstatus3 = %d\r\n",pinstatus3);

	pinstatus4 = (HAL_GPIO_ReadPin(C4_PORT, C4_PIN));
	printf("pinstatus4 = %d\r\n",pinstatus4);


	key = 'X'; // Default return value if no key is pressed
	/* make Row 1 LOW and other Row as HIGH*/

	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_SET);		// pull the R1 LOW
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_RESET);		// pull the R2 HIGH
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_RESET);		// pull the R3 HIGH
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_RESET);		// pull the R4 HIGH

//	HAL_Delay(200);

	if ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)  // if Col 1 is low
	{
		while ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '1';
	}

	else if ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)  // if Col 2 is low
	{
		while ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '2';
	}

	else if ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)  // if Col 3 is low
	{
		while ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '3';
	}

	else if ((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)  // if Col 4 is low
	{
		while ((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return 'A';
	}

	/* make Row 2 LOW and other Row as HIGH*/

	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_RESET);		// pull the R1 HIGH
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_SET);		// pull the R2 LOW
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_RESET);		// pull the R3 HIGH
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_RESET);		// pull the R4 HIGH

	if ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)  // if Col 1 is low
	{
		while ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '4';
	}

	else if ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)  // if Col 2 is low
	{
		while ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '5';
	}

	else if ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)  // if Col 3 is low
	{
		while ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '6';
	}

	else if ((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)  // if Col 4 is low
	{
		while ((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return 'B';
	}

	/* make Row 3 LOW and other Row as HIGH*/

	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_RESET);		// pull the R1 HIGH
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_RESET);		// pull the R2 HIGH
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_SET);		// pull the R3 LOW
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_RESET);		// pull the R4 HIGH

	if ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)  // if Col 1 is low
	{
		while ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '7';
	}

	else if ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)  // if Col 2 is low
	{
		while ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '8';
	}

	else if ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)  // if Col 3 is low
	{
		while ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '9';
	}

	else if ((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)  // if Col 4 is low
	{
		while ((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return 'C';
	}

	/* make Row 4 LOW and other Row as HIGH*/

	HAL_GPIO_WritePin(R1_PORT, R1_PIN, GPIO_PIN_RESET);		// pull the R1 HIGH
	HAL_GPIO_WritePin(R2_PORT, R2_PIN, GPIO_PIN_RESET);		// pull the R2 HIGH
	HAL_GPIO_WritePin(R3_PORT, R3_PIN, GPIO_PIN_RESET);		// pull the R3 HIGH
	HAL_GPIO_WritePin(R4_PORT, R4_PIN, GPIO_PIN_SET);		// pull the R4 LOW

	if ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)  // if Col 1 is low
	{
		while ((HAL_GPIO_ReadPin(C1_PORT, C1_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '*';
	}

	else if ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)  // if Col 2 is low
	{
		while ((HAL_GPIO_ReadPin(C2_PORT, C2_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '0';
	}

	else if ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)  // if Col 3 is low
	{
		while ((HAL_GPIO_ReadPin(C3_PORT, C3_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return '#';
	}

	else if((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)  // if Col 4 is low
	{
		while ((HAL_GPIO_ReadPin(C4_PORT, C4_PIN)) == GPIO_PIN_SET)// wait till button is pressed
			return 'D';
	}
	 return 'X';
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  GPIO_Initialize();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		key = read_keypad();

		switch(key)
		{
		case '1' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '2' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '3' :
		    printf("KEY : %c\r\n", key);
		    break;
		case 'A' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '4' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '5' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '6' :
		    printf("KEY : %c\r\n", key);
		    break;
		case 'B' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '7' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '8' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '9' :
		    printf("KEY : %c\r\n", key);
		    break;
		case 'C' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '*' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '0' :
		    printf("KEY : %c\r\n", key);
		    break;
		case '#' :
		    printf("KEY : %c\r\n", key);
		    break;
		case 'D' :
		    printf("KEY : %c\r\n", key);
		    break;
//		default:
//			printf("INVALID KEY \r\n");
		}
		HAL_Delay(500);
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_3;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, BSP_R4_OUTPUT_Pin|BSP_R3_OUTPUT_Pin|BSP_R2_OUTPUT_Pin|BSP_R1_OUTPUT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BSP_R4_OUTPUT_Pin BSP_R3_OUTPUT_Pin BSP_R2_OUTPUT_Pin BSP_R1_OUTPUT_Pin */
  GPIO_InitStruct.Pin = BSP_R4_OUTPUT_Pin|BSP_R3_OUTPUT_Pin|BSP_R2_OUTPUT_Pin|BSP_R1_OUTPUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BSP_C1_INPUT_Pin BSP_C2_INPUT_Pin BSP_C3_INPUT_Pin BSP_C4_INPUT_Pin */
  GPIO_InitStruct.Pin = BSP_C1_INPUT_Pin|BSP_C2_INPUT_Pin|BSP_C3_INPUT_Pin|BSP_C4_INPUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
