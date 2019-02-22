#include "N76E003.h"
#include "Function_define.h"
#include "OLED.h"
#include "Delay.h"
#include "dataflash.h"

extern void Init_I2C(void);
extern void IIC_WriteMultiBytes(unsigned char device,unsigned char cmd_data,unsigned char *buf,unsigned char len);
extern void IIC_WriteSingleByte(unsigned char device ,unsigned char cmd_data,unsigned char val);
extern void Dvice_WriteData(unsigned char  DeciveAddr,unsigned char  DataAddr,unsigned char);
#define OLED_WR_Byte(val,cmd_data)	Dvice_WriteData(0x78,cmd_data,val)//IIC_WriteSingleByte(0x78,cmd_data,val)
extern unsigned int powercnt;
unsigned char OLED_Init(void)
{
	P12_PushPull_Mode;
	P12 = 0;
	powercnt = 0;
	while(powercnt<2);
	P12 = 1;

	/* Initial I2C function */
    Init_I2C();	
	powercnt = 0;
	while(powercnt<2);
	
	OLED_WR_Byte(0xAE,OLED_CMD);//--display off
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x12,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x00,OLED_CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WR_Byte(0xB0,OLED_CMD);//--set page address
	OLED_WR_Byte(0x81,OLED_CMD); // contract control
	OLED_WR_Byte(0xFF,OLED_CMD);//--128   
	OLED_WR_Byte(0xA1,OLED_CMD);//set segment remap 
	OLED_WR_Byte(0xA6,OLED_CMD);//--normal / reverse
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x1F,OLED_CMD);//--1/32 duty
	OLED_WR_Byte(0xC8,OLED_CMD);//Com scan direction
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset
	OLED_WR_Byte(0x00,OLED_CMD);//
	OLED_WR_Byte(0xD5,OLED_CMD);//set osc division
	OLED_WR_Byte(0x80,OLED_CMD);//
	OLED_WR_Byte(0xD9,OLED_CMD);//set pre-charge period
	OLED_WR_Byte(0x1F,OLED_CMD);//
	OLED_WR_Byte(0xDA,OLED_CMD);//set COM pins
	OLED_WR_Byte(0x12,OLED_CMD);//
	OLED_WR_Byte(0xDB,OLED_CMD);//set vcomh
	OLED_WR_Byte(0x40,OLED_CMD);//
	OLED_WR_Byte(0x8D,OLED_CMD);//set charge pump enable
	OLED_WR_Byte(0x14,OLED_CMD);//
	OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel	
	return 0;
}


void OLED_Set_Pos(unsigned char x, unsigned char y) 
{
	unsigned char x0;
	x0=x+32;
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x0&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x0&0x0f),OLED_CMD); 
}   	  
  
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC??
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
  
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC??
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
void OLED_Clear(void)  
{  
	unsigned char i,n;		    
	for(i=0;i<4;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);
		OLED_WR_Byte (0x00,OLED_CMD);     
		OLED_WR_Byte (0x12,OLED_CMD);    
		for(n=32;n<96;n++)
			OLED_WR_Byte(0,OLED_DATA); 
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
			OLED_WR_Byte(0x00,OLED_DATA);
	    }
	}	
}


void Draw_BMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1,unsigned char * BMP)
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
			OLED_WR_Byte(BMP[j++],OLED_DATA);
	    }
	}
}