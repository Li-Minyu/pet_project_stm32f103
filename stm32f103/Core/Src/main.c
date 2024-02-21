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
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include "key.h"

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
char time_data[6] = { 0 }; // 读取DS1302当前时间缓存矩阵//这里如果是unsigned char ,不好做阈值处理
unsigned char KeyNum, TimeSetSelect;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	char rtcTimeString[20];
	char TimingString[20];

//	unsigned char func_index = 1;
//	unsigned char last_index = 14;
//	char set_run1 = 0; // 按键0run状态标识符
//	char set_run2 = 0; // 按键1run状态标识符
//	unsigned char init_time[6] = { 24, 2, 19, 18, 03, 20 };

	unsigned char time_data[3]={18,30,10};
//	u8 i,j;
//	float t=0;
//	uint8_t string[10]={1,2,3};
//	char string[]="新年快乐";

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
  MX_RTC_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	/* LCD initialization */
	LCD_Init();
	LCD_Fill(0, 0, LCD_W, LCD_H, BLACK);

	/* RTC peripheral */
	RTC_TimeTypeDef rtcTime;
	RTC_DateTypeDef rtcDate;

	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &rtcTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &rtcDate, RTC_FORMAT_BIN);

	LED1(ON);
	HAL_Delay(300);
	LED1(OFF);
	printf("Hello,My name is STM32F103ZET6!\r\n");

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
		/* Get the RTC current Time */
		HAL_RTC_GetTime(&hrtc, &rtcTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &rtcDate, RTC_FORMAT_BIN);

		/* Display RTC current Time on LCD */
		sprintf(rtcTimeString, "%u-%02u-%02u %02u:%02u:%02u",
				2000 + rtcDate.Year, rtcDate.Month, rtcDate.Date, rtcTime.Hours,
				rtcTime.Minutes, rtcTime.Seconds);
		LCD_ShowString(5, 10, (uint8_t*) rtcTimeString, WHITE, BLACK, 24, 0);

		LCD_ShowString(5, 50, (uint8_t*) "Timing: ", WHITE, BLACK, 24, 0);
		sprintf(TimingString,"%2d:%2d:%2d",time_data[0],time_data[1],time_data[2]);
		LCD_ShowString(110, 50, (uint8_t*) TimingString, WHITE, BLACK, 24, 0);


#if 0
		while(KEY1_PRES)
		{
			if((1==KEY1_PRES) && (1==KEY2_PRES))
			{
				KEY2_PRES=0;
				//闪烁+显示
				display(time_data[3 - state], 0, state);
				HAL_Delay(50);
				display(time_data[3 - state], 1, state);

				switch (state) //// 设置选择位(时、分、秒)
				{
					case 1:
						if(KEY3_PRES)//加
						{
							KEY3_PRES=0;
							time_data[2]++; // 时间设置位数值加1
							if (time_data[2] > 59)// 秒越界判断
							{
								time_data[2] = 0;
							}
							if(KEY2_PRES)//确认键
							{
								KEY2_PRES=0;
								KEY1_PRES=0;//结束大循环
							}
						}
						else if(KEY4_PRES)//减
						{
							KEY3_PRES=0;
							time_data[2]--; // 时间设置位数值减1
							if (time_data[2] < 0)// 秒越界判断
							{
								time_data[2] = 59;
							}
							if(KEY2_PRES)//确认键
							{
								KEY2_PRES=0;
								KEY1_PRES=0;//结束大循环
							}
						}
						else if(KEY2_PRES)//确认键
						{
							KEY2_PRES=0;
							KEY1_PRES=0;//结束大循环
						}
						break;
					case 2:
						if(KEY3_PRES)//加
						{
							KEY4_PRES=0;
							time_data[1]++; // 时间设置位数值加1
							if (time_data[1] > 59)// 分越界判断
							{
								time_data[1] = 0;
							}
						}
						else if(KEY4_PRES)//减
						{
							KEY4_PRES=0;
							time_data[1]--; // 时间设置位数值减1
							if (time_data[1] < 0)// 分越界判断
							{
								time_data[1] = 59;
							}
						}
						break;
					case 3:
						if(KEY3_PRES)//加
						{
							KEY3_PRES=0;
							time_data[0]++; // 时间设置位数值加1
							if (time_data[0] > 23)// 时越界判断
							{
								time_data[0] = 0;
							}
						}
						else if(KEY4_PRES)//减
						{
							KEY4_PRES=0;
							time_data[0]--; // 时间设置位数值减1
							if (time_data[0] < 0)// 时越界判断
							{
								time_data[0] = 23;
							}
						}
						break;
					default:
						break;
				}
			}
			if(2==KEY1_PRES)
			{
				KEY1_PRES=0;
				//闪烁
				if(1==KEY2_PRES)
				{
					KEY2_PRES=0;
					//打开投喂器
				}
			}
			if(3==KEY1_PRES)
			{
				KEY1_PRES=0;
				//闪烁
				if(1==KEY2_PRES)
				{
					KEY2_PRES=0;
					//打开风扇
				}
			}
		}
#endif
//		DS1302_Readtime();
//		show_time(time_data);


//		LCD_ShowChinese(0,10,(uint8_t *)"新年快乐",RED,WHITE,16,0);
//		LCD_ShowString(0,40,(uint8_t *)"LCD_W:",RED,WHITE,16,0);
//		LCD_ShowIntNum(48,40,(uint16_t )LCD_W,3,RED,WHITE,16);
//		LCD_ShowString(80,40,(uint8_t *)"LCD_H:",RED,WHITE,16,0);
//		LCD_ShowIntNum(128,40,(uint16_t )LCD_H,3,RED,WHITE,16);
//		LCD_ShowString(80,40,(uint8_t *)"LCD_H:",RED,WHITE,16,0);
//		LCD_ShowString(0,70,(uint8_t *)"Increaseing Nun:",RED,WHITE,16,0);
//		LCD_ShowFloatNum1(128,70,t,4,RED,WHITE,16);
//		t+=0.11;
//		for(j=0;j<3;j++)
//		{
//			for(i=0;i<6;i++)
//			{
//				LCD_ShowPicture(40*i,120+j*40,40,40,gImage_1);
//			}
//		}

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
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
