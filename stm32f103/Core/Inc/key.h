#ifndef INC_KEY_H_
#define INC_KEY_H_

#include "gpio.h"
#include "lcd.h"
#include "lcd_init.h"

#define uchar unsigned char

#define KEY1  HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)//读取按键1
#define KEY2  HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)//读取按键2
#define KEY3  HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin)//读取按键3
#define KEY4  HAL_GPIO_ReadPin(KEY4_GPIO_Port,KEY4_Pin)//读取按键3

extern unsigned char state;
extern unsigned char KEY1_PRES;
extern unsigned char  KEY2_PRES;
extern unsigned char  KEY3_PRES;
extern unsigned char  KEY4_PRES;


//typedef struct
//{
//	unsigned char current;		 // 现在所在页面层数
//	unsigned char down;			 // 向下翻
//	unsigned char enter;		 // 进入功能
//	void (*current_operation)(); // 执行函数。显示图片
//} key_table;

//key_table table[15] =
//	{
//		// 首页
//		{0, 0, 1, (*my_testA0)},
//
//		// 第一层
//		{1, 2, 5, (*my_testB1)},
//		{2, 3, 7, (*my_testB2)},
//		{3, 4, 9, (*my_testB3)},
//		{4, 1, 1, (*my_testB4)},
//
//		// 第二层
//		{5, 6, 11, (*my_testC5)},
//		{6, 5, 1, (*my_testC6)},
//
//		{7, 8, 12, (*my_testC7)},
//		{8, 7, 2, (*my_testC8)},
//
//		{9, 10, 13, (*my_testC9)},
//		{10, 9, 3, (*my_testC10)},
//
//		// 第三层
//		{11, 11, 1, (*my_testD11)},
//
//		{12, 12, 1, (*my_testD12)},
//
//		{13, 13, 1, (*my_testD13)},
//};

//uint8_t KEY_Scan(void);
//void show_time(char show_data[6]); // 时间打印函数
//void display_year(char a, uchar flag); // flag为1 时，显示数据，0时对应清除屏幕
//void display_month(char a, uchar flag);
//void display_day(char a, uchar flag);
void display_hour(char a, uchar flag);
void display_min(char a, uchar flag);
void display_sec(char a, uchar flag);
void display(char a, uchar flag, uchar shift); // 移位选择，按键2选择更改的日期


#endif /* INC_KEY_H_ */
