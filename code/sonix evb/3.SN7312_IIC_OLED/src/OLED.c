#include <stdio.h>
#include "SNC7312.h"
//#include "sn_i2c.h"
#include "system_snc7312.h"

#include "i2c.h"
#include "OLED.h"

#define	Brightness	0xCF 
#define X_WIDTH 	128
#define Y_WIDTH 	64

void OLED_WrCmd(unsigned char cmd)
{
	Dvice_WriteData(0x78,0x00,cmd);
//	I2C_Start();
//	I2C_Send_Byte(0x78);
//	I2C_Send_Byte(0x00);
//	I2C_Send_Byte(cmd);
//	I2C_Stop();
}

void OLED_WrDat(unsigned char data)
{
	Dvice_WriteData(0x78,0x40,data);
//	I2C_Start();
//	I2C_Send_Byte(0x78);
//	I2C_Send_Byte(0x40);
//	I2C_Send_Byte(data);
//	I2C_Stop();
}

void OLED_Fill(unsigned char bmp_dat)
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		OLED_WrCmd(0xb0+y);
		OLED_WrCmd(0x01);
		OLED_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		OLED_WrDat(bmp_dat);
	}
}

void OLED_CLS(void)
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		OLED_WrCmd(0xb0+y);
		OLED_WrCmd(0x01);
		OLED_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		OLED_WrDat(0);
	}
}


void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 
	OLED_WrCmd(0xb0+y);
	OLED_WrCmd(((x&0xf0)>>4)|0x10);
	OLED_WrCmd((x&0x0f)|0x01);
} 

void Draw_BMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;

	if(y1%8==0)
		y=y1/8;      
	else 
		y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
		for(x=x0;x<x1;x++)
	    {      
			OLED_WrDat(BMP[j++]);
	    }
	}
}

void OLED_CLS_Windows(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1)
{
	unsigned int j=0;
	unsigned char x,y;

	if(y1%8==0)
		y=y1/8;      
	else 
		y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
		for(x=x0;x<x1;x++)
	    {      
			OLED_WrDat(0x00);
	    }
	}	
}
	  
  
void OLED_Display_On(void)
{
	OLED_WrCmd(0X8D);  //SET DCDC??
	OLED_WrCmd(0X14);  //DCDC ON
	OLED_WrCmd(0XAF);  //DISPLAY ON
}
void OLED_Display_Off(void)
{
	OLED_WrCmd(0X8D);  //SET DCDC??
	OLED_WrCmd(0X10);  //DCDC OFF
	OLED_WrCmd(0XAE);  //DISPLAY OFF
}	
void OLED_Init(void)
{
//	delay(500);//初始化之前的延时很重要！
	OLED_WrCmd(0xae);//--turn off oled panel
	OLED_WrCmd(0x00);//---set low column address
	OLED_WrCmd(0x10);//---set high column address
	OLED_WrCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WrCmd(0x81);//--set contrast control register
	OLED_WrCmd(0xCF); // Set SEG Output Current Brightness
	OLED_WrCmd(0xa1);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	OLED_WrCmd(0xc8);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	OLED_WrCmd(0xa6);//--set normal display
	OLED_WrCmd(0xa8);//--set multiplex ratio(1 to 64)
	OLED_WrCmd(0x3f);//--1/64 duty
	OLED_WrCmd(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WrCmd(0x00);//-not offset
	OLED_WrCmd(0xd5);//--set display clock divide ratio/oscillator frequency
	OLED_WrCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WrCmd(0xd9);//--set pre-charge period
	OLED_WrCmd(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WrCmd(0xda);//--set com pins hardware configuration
	OLED_WrCmd(0x12);
	OLED_WrCmd(0xdb);//--set vcomh
	OLED_WrCmd(0x40);//Set VCOM Deselect Level
	OLED_WrCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WrCmd(0x02);//
	OLED_WrCmd(0x8d);//--set Charge Pump enable/disable
	OLED_WrCmd(0x14);//--set(0x10) disable
	OLED_WrCmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
	OLED_WrCmd(0xa6);// Disable Inverse Display On (0xa6/a7) 
	OLED_WrCmd(0xaf);//--turn on oled panel
	OLED_Fill(0x00); //初始清屏
	OLED_Set_Pos(0,0);
}
