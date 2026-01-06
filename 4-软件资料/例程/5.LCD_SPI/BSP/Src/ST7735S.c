


#include "spi.h"
#include "gpio.h"

#include "ST7735S.h"



/******************************************************************************
      函数说明：LCD串行数据写入函数
      入口数据：dat  要写入的串行数据
      返回值：  无
******************************************************************************/
void LCD_Writ_Bus(uint8_t dat) 
{	
	HAL_SPI_Transmit(&hspi1,&dat,1,1000);
}

/******************************************************************************
      函数说明：LCD数据写入使能
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_DC_Date(void) 
{	
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);
}

/******************************************************************************
      函数说明：LCD命令写入使能
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_DC_Commend(void) 
{	
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);
}



/******************************************************************************
      函数说明：LCD写入数据(8bit)
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA8(uint8_t dat)
{
	LCD_Writ_Bus(dat);
}

/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA(uint16_t dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}

/******************************************************************************
      函数说明：LCD写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void LCD_WR_REG(uint8_t dat)
{
	LCD_DC_Commend();//写命令
	LCD_Writ_Bus(dat);
	LCD_DC_Date();//写数据
}


/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
				USE_HORIZONTAL  设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
      返回值：  无
******************************************************************************/
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(CASET);//列地址设置
		LCD_WR_DATA(x1+2);
		LCD_WR_DATA(x2+2);
		LCD_WR_REG(RASET);//行地址设置
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(RAMWR);//储存器写
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(CASET);//列地址设置
		LCD_WR_DATA(x1+2);
		LCD_WR_DATA(x2+2);
		LCD_WR_REG(RASET);//行地址设置
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(RAMWR);//储存器写
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(CASET);//列地址设置
		LCD_WR_DATA(x1+1);
		LCD_WR_DATA(x2+1);
		LCD_WR_REG(RASET);//行地址设置
		LCD_WR_DATA(y1+2);
		LCD_WR_DATA(y2+2);
		LCD_WR_REG(RAMWR);//储存器写
	}
	else
	{
		LCD_WR_REG(CASET);//列地址设置
		LCD_WR_DATA(x1+1);
		LCD_WR_DATA(x2+1);
		LCD_WR_REG(RASET);//行地址设置
		LCD_WR_DATA(y1+2);
		LCD_WR_DATA(y2+2);
		LCD_WR_REG(RAMWR);//储存器写
	}
}

void LCD_BLK_Set()					//打开背光
{
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin ,GPIO_PIN_SET);
	HAL_Delay(100);
}

void LCD_Init(void)
{
	LCD_BLK_Set();					//打开背光
	
	LCD_WR_REG(SWRESET);
	
	//************* Start Initial Sequence **********//
	HAL_Delay(1);
	LCD_WR_REG(SLPOUT); //Sleep out 

	//------------------------------------ST7735S Frame Rate-----------------------------------------// 
	LCD_WR_REG(FRMCTR1);			//正常模式(全彩)
	LCD_WR_DATA8(0x05); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_REG(FRMCTR2); 			// Idle模式(8色)
	LCD_WR_DATA8(0x05);
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_REG(FRMCTR3); 			//部分模式+全彩模式
	LCD_WR_DATA8(0x05); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x05); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	//------------------------------------End ST7735S Frame Rate---------------------------------// 
	LCD_WR_REG(INVCTR); 			//Dot inversion //Display Inversion Control//显示反转控制
	LCD_WR_DATA8(0x03); 
	//------------------------------------ST7735S Power Sequence---------------------------------// 
	LCD_WR_REG(PWCTR1);				//Power Control Setting
	LCD_WR_DATA8(0x28); 
	LCD_WR_DATA8(0x08); 
	LCD_WR_DATA8(0x04); 
	LCD_WR_REG(PWCTR2);				//Power Control Setting
	LCD_WR_DATA8(0XC0); 
	LCD_WR_REG(PWCTR3); 			
	LCD_WR_DATA8(0x0D); 
	LCD_WR_DATA8(0x00); 
	LCD_WR_REG(PWCTR4); 				
	LCD_WR_DATA8(0x8D); 
	LCD_WR_DATA8(0x2A); 
	LCD_WR_REG(PWCTR5); 
	LCD_WR_DATA8(0x8D); 
	LCD_WR_DATA8(0xEE); 
	//---------------------------------End ST7735S Power Sequence-------------------------------------// 
	LCD_WR_REG(VMCTR1); 			//VCOM //VCOM 控制 1(vcom是液晶分子偏转的参考电压)
	LCD_WR_DATA8(0x1A); 
	LCD_WR_REG(MADCTL); 			//MX, MY, RGB mode //内存数据访问控制
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
	else LCD_WR_DATA8(0xA0); 
	//------------------------------------ST7735S Gamma Sequence---------------------------------// 
	LCD_WR_REG(GAMCTRP1); 			//Gamma Adjustment (+ Polarity)
	LCD_WR_DATA8(0x04); 
	LCD_WR_DATA8(0x22); 
	LCD_WR_DATA8(0x07); 
	LCD_WR_DATA8(0x0A); 
	LCD_WR_DATA8(0x2E); 
	LCD_WR_DATA8(0x30); 
	LCD_WR_DATA8(0x25); 
	LCD_WR_DATA8(0x2A); 
	LCD_WR_DATA8(0x28); 
	LCD_WR_DATA8(0x26); 
	LCD_WR_DATA8(0x2E); 
	LCD_WR_DATA8(0x3A); 
	LCD_WR_DATA8(0x00); 
	LCD_WR_DATA8(0x01); 
	LCD_WR_DATA8(0x03); 
	LCD_WR_DATA8(0x13); 
	LCD_WR_REG(GAMCTRN1); 
	LCD_WR_DATA8(0x04); 
	LCD_WR_DATA8(0x16); 
	LCD_WR_DATA8(0x06); 
	LCD_WR_DATA8(0x0D); 
	LCD_WR_DATA8(0x2D); 
	LCD_WR_DATA8(0x26); 
	LCD_WR_DATA8(0x23); 
	LCD_WR_DATA8(0x27); 
	LCD_WR_DATA8(0x27); 
	LCD_WR_DATA8(0x25); 
	LCD_WR_DATA8(0x2D); 
	LCD_WR_DATA8(0x3B); 
	LCD_WR_DATA8(0x00); 
	LCD_WR_DATA8(0x01); 
	LCD_WR_DATA8(0x04); 
	LCD_WR_DATA8(0x13); 
	//------------------------------------End ST7735S Gamma Sequence-----------------------------// 
	LCD_WR_REG(COLMOD); 			//65k mode //Interface Pixel Format//接口像素格式
	LCD_WR_DATA8(0x05); 
	LCD_WR_REG(DISPON); 			//Display on //显示开
}





