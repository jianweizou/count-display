/******************************************
//I2C学习程序，主机模式
//Pin:
	SCL   GPIO3.14
	SDA   GPIO3.15
*****************************************/

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include "SNC7312.h"
//#include "sn_i2c.h"
#include "system_snc7312.h"

#include "i2c.h"
#include "OLED.h"
#include "fontdata.h"
int main(void)
{
	int i=0;
	Peri_Inital();
	/******************************
	* system clock setting = 96MHz
	******************************/
	if(HXTAL_Enable())//enable high X'tal
		while(1);//error
	if(SPLL_Enable(SYS_HXTAL))//enable SPLL
		while(1);//error
	SysClk_Setting(SYS_SPLL,0);
	

	SN_GPIO3->CFG_b.CFG0 = 0;	//SCL PULL HIGH
	SN_GPIO3->MODE_b.MODE0 = 1;	//SCL output
	SN_GPIO3->DATA_b.DATA0 = 1;	//SCL 1

	SN_GPIO3->CFG_b.CFG1 = 0;	//SDA PULL HIGH		
	SN_GPIO3->MODE_b.MODE1 = 1;	//SDA output	
	SN_GPIO3->DATA_b.DATA1 = 1;	//SDA 1
	
	Delay1usFor96MHz(200000);
	OLED_Init();

	OLED_CLS();
	//测试藏文
	OLED_Set_Pos(0,4);
	for(i=0;i<64;i++)
		OLED_WrDat(0x01);
	
	for(i=0;i<4;i++)
	{
		OLED_Set_Pos(64,i);
		OLED_WrDat(0xFF);			
	}
	/*
	for(i=0;i<5;i++)
	{
		Draw_BMP(12*i,0,12+12*i,2,t0 + 24*i);		
	}
	for(i=5;i<10;i++)
	{
		Draw_BMP(12*(i-5),2,12+12*(i-5),4,t0 + 24*i);		
	}	
	Delay1usFor96MHz(1000*1000);
	OLED_CLS();
	//测试0-9 / 6*8
	for(i=0;i<11;i++)
	{
		Draw_BMP(6*i,0,6+6*i,1,font1_0_9 + 6*i);
	}
	
	Delay1usFor96MHz(1000*1000);
	OLED_CLS();
	//测试0-9 / 8*16
	for(i=0;i<11;i++)
	{
		Draw_BMP(8*i,0,8+8*i,2,font2_0_9 + 16*i);
	}	
	
	Delay1usFor96MHz(1000*1000);
	OLED_CLS();
	//测试A-Z
	for(i=0;i<16;i++)
	{
		Draw_BMP(8*i,0,8+8*i,2,font_A_Z + 16*i);
	}	
	for(i=16;i<26;i++)
	{
		Draw_BMP(8*(i-16),2,8+8*(i-16),4,font_A_Z + 16*i);
	}	
	Delay1usFor96MHz(1000*1000);
	OLED_CLS();
	//测试中文 16*16
	for(i=0;i<CHNEND;i++)
	{
		Draw_BMP(0,0,16,2,font_CHN + 32*i);
		Delay1usFor96MHz(1000*1000);
		OLED_CLS();
	}
	*/
	
	while(1)
	{
		main_loop();
	}	
}
