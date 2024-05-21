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
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fatfs_sd.h"
#include <string.h>
#include<stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_RTC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

FATFS fs; 		// file system
FIL fil;		// file
FRESULT fresult;	// to store the result
char buffer[1024];	// to store data

UINT br, bw;		// file read/write data

/* capacity related variables */

FATFS *pfs;
DWORD fre_clust;
uint32_t  total, free_space;

/* to send the data to uart */

void send_uart(char *string)
{
	uint8_t len = strlen(string);
	HAL_UART_Transmit(&huart1,(uint8_t *)string, len, 2000);	// transmit in blocking mode
}

/* to find the size of the data in the buffer */
int bufsize(char *buf)
{
	int i =0;
	while (*buf++ != '\0') i++;
	return i;

}

void bufclear(void)		// clear buffer
{
	for (int i = 0; i < 1024; i++){
		buffer[i] = '\0';
	}
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
  MX_SPI2_Init();
  MX_USART1_UART_Init();
  MX_FATFS_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */

  //Mount sd card

    fresult = f_mount(&fs, "/", 1);
    if (fresult != FR_OK)
  	   send_uart ("ERROR!!! in mounting SD CARD...\n\n");
    else send_uart("SD CARD mounted successfully...\n\n");


    /******************* Card capacity details **********************/

        	/* Check free space */

        	f_getfree("", &fre_clust, &pfs);

        	total = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5);
        	sprintf (buffer, "SD CARD Total Size: \t%lu\n",total);
        	send_uart(buffer);
        	bufclear();

        	free_space = (uint32_t)(fre_clust * pfs->csize * 0.5);
        	sprintf (buffer, "SD CARD Free Space: \t%lu\n\n",free_space);
        	send_uart(buffer);
        	bufclear();



        	/* Get current date from RTC */
        	RTC_DateTypeDef date;
            HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);

//            /* Create folder if it doesn't exist */
//
//            char foldername[9]; // Format: MMDDYYYY
//            sprintf(foldername, "%02d%02d%04d", date.Date, date.Month, date.Year);
//            send_uart(foldername);
//            if (f_mkdir(foldername) == FR_OK) {
//            	strcpy(buffer, "Folder created\n");
//            	send_uart(buffer);
//
//            }
//            else {
//                strcpy(buffer, "Folder already created\n");
//                send_uart(buffer);
//            }
//
//            /* Format date string for file name (assuming format DDMMYYYY) */
//            char filename[20];
//            sprintf(filename, "%02d%02d%02d.txt", date.Date, date.Month, date.Year);
//
//            /* Open file with dynamic date name for writing */
//            f_open(&fil, "/10040024/filename", FA_CREATE_ALWAYS | FA_WRITE);
//            if (fresult == FR_OK) {
//                strcpy(buffer, "File created successfully\n");
//                send_uart(buffer);
//
//                /* Write data to file using SPI communication */
//                strcpy(buffer, "This is a test file\n");
//                f_write(&fil, buffer, strlen(buffer), &bw);
//                send_uart(buffer);
//
//                /* Close file */
//                f_close(&fil);
//            } else {
//                strcpy(buffer, "Error creating file\n");
//                send_uart(buffer);
//            }
//
//
//
////        	/* Format date string for file name (assuming format DDMMYYYY) */
////            char filename[20];
////       	    sprintf(filename, "%02d%02d%02d.txt", date.Date, date.Month, date.Year);
////       	    send_uart(filename);
//
//       	    /* Open file with dynamic date name for writing */
//       	    f_open(&fil, "/filename", FA_CREATE_ALWAYS | FA_WRITE);
//
//       	    /* Write data to file using SPI communication */
//
//       	    strcpy (buffer, "This is ddmmyy.txt file \n");
//
//       	    f_write(&fil, buffer, bufsize(buffer), &bw);
//
//       	    send_uart(buffer);
//
//       	    /* Close file */
//       	    f_close(&fil);
//
//       	 /* open the file to read */
//       	    f_open(&fil, filename, FA_READ);
//
//       	    /* Read the string from the file */
//       	    f_read(&fil, buffer, sizeof(buffer), &br);
//       	    send_uart(buffer);
//
//       	         	 /* close file */
//       	    f_close(&fil);

//
//     /**************** the following operation is using PUTS and GETS  ******************/
//
        	/* open a file to write/ create a file if it does not exist */
        	fresult = f_open(&fil, "file.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);

        	if(fresult == FR_OK)
        	{
        		send_uart("file created created\n");
        	}
        	/* TO WRITE IN FILE */
        	fresult = f_puts("This is from the first file \n", &fil);

        	send_uart("file.txt is created and text is written \n");

        	/* to close file */
        	fresult = f_close(&fil);

        	/* open file to read */
        	fresult = f_open(&fil, "file.txt", FA_READ);

        	/* READ string from the file */
        	f_gets(buffer, sizeof(buffer), &fil);

        	send_uart(buffer);

        	f_close(&fil);

        	bufclear();


      /**************** The following operation is using f_write and f_read *********************/


        	 /* Create second file with read write access and open it */
        	 fresult = f_open(&fil, "file2.txt", FA_CREATE_ALWAYS | FA_WRITE | FA_READ);

       	  	/* Writing text */
        	 strcpy (buffer, "This is File2.txt, written using ...f_write... and it says Hello \n");

        	 fresult = f_write(&fil, buffer, bufsize(buffer), &bw);

        	 send_uart ("File2.txt created and data is written\n");

       	  	/* Close file */
        	 f_close(&fil);

        	 bufclear();

        	 /* open second file to read */
        	 fresult =f_open(&fil, "file2.txt", FA_READ);

        	 /* READ data from the file */

        	 f_read(&fil, buffer, sizeof(buffer), &br);
        	 send_uart(buffer);

        	 f_close(&fil);

        	 bufclear();

//
//       /*********************** UPDATING an existing file ****************************/
//
//
//        	 /* open the file with write access */
//        	 fresult =f_open(&fil, "file2.txt", FA_OPEN_ALWAYS | FA_WRITE);
//
//        	 /* move to offset to the end of the file */
//        	 fresult = f_lseek(&fil, sizeof(buffer));
//
//        	 /* write the string to the file */
//        	 fresult = f_puts("This is updated data and it should be at the end \n", &fil);
//
//        	 f_close(&fil);
//
//        	 /* open the file to read */
//        	 fresult = f_open(&fil, "file2.txt", FA_READ);
//
//        	 /* Read the string from the file */
//        	 f_read(&fil, buffer, sizeof(buffer), &br);
//        	 send_uart(buffer);
//
//        	 /* close file */
//        	 f_close(&fil);
//
//        	 bufclear();


//       /*********************** REMOVING A file from directory  *************************/
//
//
//        	 fresult = f_unlink("/file.txt");
//        	 if(fresult == FR_OK) send_uart("file.txt removed successfully \n");
////
//        	 fresult = f_unlink("/file2.txt");
//        	 if(fresult == FR_OK) send_uart("file2.txt removed successfully \n");
//
////        	 fresult = f_unlink("/file3.txt");
////        	 if(fresult == F R_OK) send_uart("file3.txt removed successfully \n");
//
//        	 /* unmount SD Card */
//        	 fresult = f_mount(NULL, "", 1);
//        	 if(fresult == FR_OK) send_uart("SD card unmounted successfully \n");


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
   while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_3;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_3;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_RTC;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0x0;
  sTime.Minutes = 0x0;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_WEDNESDAY;
  sDate.Month = RTC_MONTH_APRIL;
  sDate.Date = 0x10;
  sDate.Year = 0x24;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BSP_SD_CS_GPIO_Port, BSP_SD_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : BSP_SD_CS_Pin */
  GPIO_InitStruct.Pin = BSP_SD_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BSP_SD_CS_GPIO_Port, &GPIO_InitStruct);

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
  while (1)
  {
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
