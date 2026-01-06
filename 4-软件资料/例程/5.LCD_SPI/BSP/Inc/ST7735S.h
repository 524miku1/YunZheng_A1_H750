/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ST7735S_H__
#define __ST7735S_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */


/* USER CODE BEGIN Private defines */

#define USE_HORIZONTAL 1  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏


/*
 *System Function Command List系统功能命令列表
 */
#define NOP 		0X00			//No Operation//不操作
#define SWRESET 	0X01			//Software Reset//软件复位
#define RDDID 		0X04			//Read Display ID//读取显示ID
#define RDDST 		0X09			//Read Display Status//读显示状态
#define RDDPM		0X0A			//Read Display Power Mode//读显示电源模式
#define RDDMADCTL 	0X0B			//Read Display MADCTL//读显示MADCTL
#define RDDCOLMOD 	0X0C			//Read Display Pixel Format//读取显示像素格式
#define RDDIM 		0X0D			//Read Display Image Mode//读取显示图像模式
#define RDDSM 		0X0E			//Read Display Signal Mode//读取显示信号模式
#define RDDSDR 		0X0F			//Read Display Self-diagnostic//读取显示自诊断
#define SLPIN 		0X10			//Sleep In & Booster Off//进入休眠，关闭助推器
#define SLPOUT		0X11			//Sleep Out & Booster On//退出休眠，打开助推器
#define PTLON 		0X12			//Partial Mode On//部分模式开启
#define NORON 		0X13			//Partial Off (Normal)//部分关闭(正常)
#define INVOFF 		0X20			//Display Inversion Off (Normal)//显示反转关闭(正常)
#define INVON 		0X21			//Display Inversion On//显示反转开启
#define GAMSET 		0X26			//Gamma Curve Select//伽马曲线选择
#define DISPOFF 	0X28			//Display Off//显示关
#define DISPON 		0X29			//Display On//显示开
#define CASET 		0x2a			//Column Address Set//列地址设置
#define RASET 		0X2B			//Row Address Set//行地址设置
#define RAMWR 		0X2C			//Memory Write//内存写
#define RGBSET 		0X2D			//LUT for 4k,65k,262k Color display//LUT适用于4k、65k、262k彩色显示
#define RAMRD 		0X2E			//Memory Read//内存读
#define PTLAR 		0X30			//Partial Start/End Address Set//部分起始/结束地址设置
#define SCRLAR 		0X33			//Scroll area set//滚动区域设置
#define TEOFF 		0X34			//Tearing effect line off//撕裂效果线关闭
#define TEON 		0X35			//Tearing Effect Mode Set & on//撕裂效果模式设置&开启
#define MADCTL 		0X36			//Memory Data Access Contro//内存数据访问控制
#define VSCSAD 		0X37			//Scroll Start Address of RAM// RAM的滚动起始地址
#define IDMOFF 		0X38			//Idle Mode Off//空闲模式关闭
#define IDMON 		0X39			//Idle Mode On//空闲模式开启
#define COLMOD 		0X3A			//Interface Pixel Format//接口像素格式
#define RDID1 		0XDA			//Read ID1//读ID1
#define RDID2 		0XDB			//Read ID2//读ID2
#define RDID3 		0XDC			//Read ID3//读ID3

/*
 *Panel Function Command List面板功能命令列表
 */
#define FRMCTR1 	0XB1			//In Normal Mode (Full Colors)//正常模式(全彩)
#define FRMCTR2 	0XB2			//In Idle Mode (8-colors)// Idle模式(8色)
#define FRMCTR3 	0XB3			//In Partial Mode + Full Colors//部分模式+全彩模式
#define INVCTR 		0XB4			//Display Inversion Control//显示反转控制
#define PWCTR1 		0XC0			//Power Control Setting
#define PWCTR2 		0XC1			//Power Control Setting
#define PWCTR3 		0XC2			//In Normal Mode (Full Colors)//正常模式(全彩)
#define PWCTR4 		0XC3			//In Idle Mode (8-colors)// Idle模式(8色)
#define PWCTR5 		0XC4			//In Partial Mode + Full colors//部分模式+全彩模式
#define VMCTR1 		0XC5			//VCOM Control 1//VCOM 控制 1(vcom是液晶分子偏转的参考电压)
#define VMOFCTR 	0XC7			//Set VCOM Offset control//设置VCOM偏移控制
#define WRID2 		0XD1			//Set LCM Version Code//设置LCM版本码
#define WRID3 		0XD2			//Customer Project Code//客户项目代码
#define NVCTR1 		0XD9			//NVM Control Status//NVM控制状态
#define NVCTR2 		0XDE			//NVM Read Command//NVM读取命令
#define NVCTR3 		0XDF			//NVM Write Command Action Code//NVM写命令动作码
#define GAMCTRP1 	0XE0			//Gamma Adjustment (+ Polarity)
#define GAMCTRN1 	0XE1			//Gamma Adjustment (-Polarity)

/* USER CODE END Private defines */


/* USER CODE BEGIN Prototypes */
	
void LCD_Writ_Bus(uint8_t dat);			//LCD串行数据写入函数
void LCD_DC_Date(void);					//LCD数据写入使能
void LCD_DC_Commend(void);				//LCD命令写入使能
void LCD_WR_DATA8(uint8_t dat);			//LCD写入数据(8bit)
void LCD_WR_DATA(uint16_t dat);			//LCD写入数据
void LCD_WR_REG(uint8_t dat);			//LCD写入命令
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);//设置起始和结束地址
void LCD_BLK_Set(void);					//打开背光
void LCD_Init(void);					//ST7735S初始化

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ST7735S_H__ */

