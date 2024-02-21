#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "main.h"

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

/* Choose a display rotation you want to use: (0-3) */
#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
//#define USE_HORIZONTAL 1
//#define USE_HORIZONTAL 2
//#define USE_HORIZONTAL 3
#if USE_HORIZONTAL == 0
	#define LCD_W 240     //use Normally on 240x240
	#define LCD_H 240
#endif
#if USE_HORIZONTAL == 1
	#define LCD_W 240
	#define LCD_H 240
#endif

void LCD_GPIO_Init(void);//初始化GPIO
void LCD_Writ_Bus(u8 dat);//模拟SPI时序
void LCD_WR_DATA8(u8 dat);//写入一个字节
void LCD_WR_DATA(u16 dat);//写入两个字节
void LCD_WR_REG(u8 dat);//写入一个指令
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//设置坐标函数
void LCD_Init(void);//LCD初始化

#endif




