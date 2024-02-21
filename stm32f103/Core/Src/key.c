#include "KEY.h"

unsigned char  state=0;
unsigned char  KEY1_PRES=0;
unsigned char  KEY2_PRES=0;
unsigned char  KEY3_PRES=0;
unsigned char  KEY4_PRES=0;

/*
 *+----------------------+
 *|     GPIO KEY API     |
 *+----------------------+
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (KEY1_Pin == GPIO_Pin) // 切换
    {
        HAL_Delay(10); // 消抖
        while (!KEY1); // 按键不松手，则停在这里
        state++;  // 初始时state=0
        if (state > 3)
        {
            state = 0;//越界清零
        }
        LED1(ON);
    }
	if (KEY2_Pin == GPIO_Pin) // 等待切换功能或确认
	{
		HAL_Delay(10); // 消抖
		while (!KEY2); // 按键不松手，则停在这里
//		KEY2_PRES ^=1; //异或：0^1=1,1^1=0
		KEY2_PRES =1;
		LED1(ON);
	}
    if (KEY3_Pin == GPIO_Pin) // 状态机+一键多义
    {
        HAL_Delay(10); // 消抖
        while (!KEY3); // 按键不松手，则停在这里
        KEY3_PRES = 1;
        LED1(OFF);
    }
    if (KEY4_Pin == GPIO_Pin) // 状态机+一键多义
    {
        HAL_Delay(10); // 消抖
        while (!KEY4); // 按键不松手，则停在这里
        KEY4_PRES = 1;
        LED1(OFF);
    }
}

//void Key_choose(void)
//{
//	switch(state)
//	 {
////	 case 0:
////	     // 显示正常时间
////	     break; // 正常时钟状态
//	 case 1:
//		 if(KEY1_PRES)
//		 {
//			 KEY1_PRES=0;
//
//		 }
//	     sec++; // 秒++
//	     if (sec > 60)
//	         sec = 0;
//	     break;
//	 case 2:
//	     min++; // 分++
//	     if (min > 60)
//	         min = 0;
//	     break;
//	 case 3:
//	     hour++; // 时++
//	     if (hour > 24)
//	         hour = 0;
//	     break;
//	 default:
//	     break;
//}



/*****************************************************************************
 * @name       :u8 KEY_Scan(void)
 * @date       :2018-08-09
 * @function   :KEY processing,Response priority:KEY0>KEY1>WK_UP!!
 * @parameters :None
 * @retvalue   :0-No buttons were pressed.
								1-The KEY0 button is pressed
								2-The KEY1 button is pressed
								3-The WK_UP button is pressed
******************************************************************************/
//uint8_t KEY_Scan(void)
//{
//	if((KEY1==0||KEY2==0||KEY3==0||KEY4==0))
//	{
//		HAL_Delay(10);//去抖动
//		if (KEY1==0)
//			{
//				while(KEY1==0);//等待按键松开
//			  HAL_Delay(5);
//				return KEY1_PRES;
//			}
//		else if(KEY2==0)
//		{
//			while(KEY2==0);//等待按键松开
//			HAL_Delay(5);
//		   return KEY2_PRES;
//		}
//		else if(KEY3==0)
//		{
//			while(KEY3==0);//等待按键松开
//			HAL_Delay(5);
//			return  KEY3_PRES;
//		}
//		else if(KEY4==0)
//		{
//		 while(KEY4==0);//等待按键松开
//			HAL_Delay(5);
//		 return  KEY4_PRES;
//		}
//	}
//	return 0;// 无按键按下
//}

//void show_time(char show_data[6]) // 时间打印函数
//{
//	// LCD_Clear(WHITE);
//	LCD_Fill(0, 0, LCD_W, 20, BLUE);
//	LCD_DrawPoint(0,0,WHITE);
////	POINT_COLOR = WHITE;//画笔颜色
//	LCD_Fill(0, LCD_H - 20, LCD_W, LCD_H, BLUE);
////	LCD_DrawPoint(0,LCD_H-20,WHITE);
////	POINT_COLOR = BLUE;//画笔颜色
//	LCD_DrawRectangle(10, 50, 105, 80,BLUE);
//	LCD_ShowChar(30, 25, BLACK, BLUE, show_data[0] / 10 + '0', 16, 1); // 年
//	LCD_ShowChar(38, 25, BLACK, BLUE, show_data[0] % 10 + '0', 16, 1);
//	LCD_ShowString(46, 25, BLACK, BLUE, ".", 16, 1);
//	LCD_ShowChar(54, 25, BLACK, BLUE, show_data[1] / 10 + '0', 16, 1); // 月
//	LCD_ShowChar(62, 25, BLACK, BLUE, show_data[1] % 10 + '0', 16, 1);
//	LCD_ShowString(70, 25, BLACK, BLUE, ".", 16, 1);
//	LCD_ShowChar(78, 25, BLACK, BLUE, show_data[2] / 10 + '0', 16, 1); // 日
//	LCD_ShowChar(86, 25, BLACK, BLUE, show_data[2] % 10 + '0', 16, 1);
//
//	LCD_ShowChar(25, 60, BLUE, BLUE, show_data[3] / 10 + '0', 18, 1); // 时
//	LCD_ShowChar(35, 60, BLUE, BLUE, show_data[3] % 10 + '0', 18, 1);
//	LCD_ShowString(45, 60, BLACK, BLUE, ":", 16, 1);
//	LCD_ShowChar(55, 60, BLUE, BLUE, show_data[4] / 10 + '0', 16, 1); // 分
//	LCD_ShowChar(65, 60, BLUE, BLUE, show_data[4] % 10 + '0', 16, 1);
//	LCD_ShowString(75, 60, BLACK, BLUE, ":", 16, 1);
//	LCD_ShowChar(85, 60, BLUE, BLUE, show_data[5] / 10 + '0', 16, 1); // 秒
//	LCD_ShowChar(95, 60, BLUE, BLUE, show_data[5] % 10 + '0', 16, 1); //
//}
//void display_year(char a, uchar flag) // flag为1 时，显示数据，0时对应清除屏幕
//{
//	if (flag)
//	{
//		LCD_ShowChar(30, 25, BLACK, BLUE, a / 10 + '0', 16, 1); // 年
//		LCD_ShowChar(38, 25, BLACK, BLUE, a % 10 + '0', 16, 1);
//	}
//	else
//	{
//		// 清除年位
////		POINT_COLOR = WHITE;
//		LCD_Fill(30, 25, 45, 45,WHITE);
//	}
//}
//void display_month(char a, uchar flag)
//{
//	if (flag)
//	{
//		LCD_ShowChar(54, 25, BLACK, BLUE, a / 10 + '0', 16, 1); // 月
//		LCD_ShowChar(62, 25, BLACK, BLUE, a % 10 + '0', 16, 1);
//	}
//	else
//	{
//		// 清除月位
////		POINT_COLOR = WHITE;
//		LCD_Fill(54, 25, 69, 45,WHITE);
//	}
//}
//void display_day(char a, uchar flag)
//{
//	if (flag)
//	{
//		LCD_ShowChar(78, 25, BLACK, BLUE, a / 10 + '0', 24, 1); // 日
//		LCD_ShowChar(86, 25, BLACK, BLUE, a % 10 + '0', 24, 1);
//	}
//	else
//	{
//		// 清除日位
////		POINT_COLOR = WHITE;
//		LCD_Fill(78, 25, 92, 45,WHITE);
//	}
//}
void display_hour(char a, uchar flag)
{
	if (flag)
	{
		LCD_ShowChar(50, 50, WHITE, BLACK, a / 10 + '0', 24, 1); // 时
		LCD_ShowChar(60, 50, WHITE, BLACK, a % 10 + '0', 24, 1);
	}
	else
	{
		// 清除时位
//		POINT_COLOR = WHITE;
		LCD_Fill(50, 50, 89, 90,BLACK);
	}
}
void display_min(char a, uchar flag)
{
	if (flag)
	{
		LCD_ShowChar(90, 50, WHITE, BLACK, a / 10 + '0', 24, 1); // 分
		LCD_ShowChar(100, 50, WHITE, BLACK, a % 10 + '0', 24, 1);
	}
	else
	{
		// 清除分位
//		POINT_COLOR = WHITE;
		LCD_Fill(90, 50, 129, 90,BLACK);
	}
}
void display_sec(char a, uchar flag)
{
	if (flag)
	{
		LCD_ShowChar(120, 50, WHITE, BLACK, a / 10 + '0', 24, 1); // 秒
		LCD_ShowChar(130, 50, WHITE, BLACK, a % 10 + '0', 24, 1);
	}
	else
	{
		// 清除秒位
//		POINT_COLOR = WHITE;
		LCD_Fill(130, 50, 159, 90,BLACK);
	}
}

void display(char a, uchar flag, uchar shift) // 移位选择，按键2选择更改的日期
{
	switch (shift)
	{
	case 0:
		//整体闪动
		break;
	case 1:
		display_sec(a, flag);
		break;
	case 2:
		display_min(a, flag);
		break;
	case 3:
		display_hour(a, flag);
		break;
//	case 4:
//		display_day(a, flag);
//		break;
//	case 5:
//		display_month(a, flag);
//		break;
//	case 6:
//		display_year(a, flag);
//		break;
	default:
		break;
	}
}
