#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "ds1302.h"
/*
ds1302 CLOCK/CALENDAR 数据是BCD格式，请注意格式转换。
*/

void Delay1us(unsigned char x)
{
	while(x--);
}
#define SCLK_OUT	P03_PushPull_Mode
#define SDA_OUT		P01_PushPull_Mode
#define SDA_IN		P01_PushPull_Mode;P01_Input_Mode
#define CE_OUT		P00_PushPull_Mode

#define SCLK_H		P03=1
#define SCLK_L		P03=0
#define SDA_H		P01=1
#define SDA_L		P01=0
#define CE_H		P00=1
#define CE_L		P00=0

#define GET_SDA		P01

void writebyte(unsigned char x)
{
	unsigned char i;
	SCLK_L;
	Delay1us(2);
	
	for(i=0;i<8;i++)
	{
		if (x&0x01)
			SDA_H;
		else
			SDA_L;
		Delay1us(1);
		SCLK_H;
		Delay1us(1);
		SCLK_L;
		x = x>>1;
	}	
}

unsigned char readbyte(void)
{
	unsigned char i,dt;
	//sda input
	SDA_IN;
	Delay1us(2);
	for(i=0;i<8;i++)
	{
		dt = dt >> 1;
		if (GET_SDA == 1)
		{
			dt |= 0x80;
		}
		SCLK_H;
		Delay1us(1);
		SCLK_L;
		Delay1us(1);
	}
	SDA_OUT;
	return dt;
}

void ds1302writebyte(unsigned char cmd,unsigned char dt)
{
	CE_L;
	SCLK_L;
	CE_H;
	writebyte(cmd);
	writebyte(dt);
	SCLK_H;
	CE_L;
}

unsigned char ds1302readbyte(unsigned char cmd)
{
	unsigned char dt;
	CE_L;
	SCLK_L;
	CE_H;
	writebyte(cmd);
	dt = readbyte();
	SCLK_H;
	CE_L;
	return dt;
}


void ds1302_dpd(unsigned char dpd)
{
	unsigned char t;
	ds1302writebyte(0x8E,0x00);
	t = ds1302readbyte(0x81);
	if (dpd)
		t |= 0x80;
	else
		t &= 0x7F;
	ds1302writebyte(0x80,t);
	ds1302writebyte(0x8E,0x80);
}

void Init1302(void)
{
	SCLK_OUT;
	SDA_OUT;
	CE_OUT;
	
	SCLK_L;
	SDA_L;
	CE_L;	
	
//	ds1302_dpd(0);
	if (ds1302readbyte(0xC1) == 0xA8)
		return;	
	ds1302writebyte(0x8E,0x00);
//	ds1302writebyte(0x90,0x0D);
	ds1302writebyte(0x80,0x00);
	ds1302writebyte(0x82,0x20);
	ds1302writebyte(0x84,0x07);
	ds1302writebyte(0x86,0x25);
	ds1302writebyte(0x88,0x12);
	ds1302writebyte(0x8A,0x10);
	ds1302writebyte(0x8C,0x06);
	
	ds1302writebyte(0x90,0x00);
//	ds1302writebyte(0xC0,0xf0);
	
	ds1302writebyte(0xC0,0xA8);
	
	ds1302writebyte(0x8E,0x80);
	
}

unsigned char bcd_hex(unsigned char x)
{
	unsigned char temp;
	temp = x & 0xF0;
	temp = temp >>4;
	temp = temp *10;
	temp += x& 0x0F;
	return temp;
}

unsigned char hex_bcd(unsigned char x)
{
	unsigned char temp;
	temp = 0;
	while(1)
	{
		if (x >= 10)
		{
			temp += 0x10;
			x = x - 10;
		}
		else
		{
			temp |= x;
			break;
		}
	}
	return temp;
}

void readtimer(TIME_INFO* time)
{
	//BCD
	time->sec = ds1302readbyte(0x81);
	time->min = ds1302readbyte(0x83);
	time->hr =  ds1302readbyte(0x85);
	time->date = ds1302readbyte(0x87);
	time->month = ds1302readbyte(0x89);
	time->day = ds1302readbyte(0x8B);
	time->year = ds1302readbyte(0x8D)+YEAR_BASE;	
	
	time->sec = bcd_hex(time->sec);
	time->min = bcd_hex(time->min);
	time->hr = bcd_hex(time->hr);
	time->date = bcd_hex(time->date);
	time->month = bcd_hex(time->month);
	time->day = bcd_hex(time->day);
	time->year = bcd_hex(time->year);
}

void writetimer(TIME_INFO* time)
{
	unsigned char temp;
	ds1302writebyte(0x8E,0x00);
	ds1302writebyte(0xC0,0xFF);
	
	temp = hex_bcd(time->sec);
	ds1302writebyte(0x80,temp);
	temp = hex_bcd(time->min);
	ds1302writebyte(0x82,temp);
	temp = hex_bcd(time->hr);
	ds1302writebyte(0x84,temp);
	temp = hex_bcd(time->date);
	ds1302writebyte(0x86,temp);
	temp = hex_bcd(time->month);
	ds1302writebyte(0x88,temp);
	
//	ds1302writebyte(0x8A,time->day);
	
	temp = hex_bcd(time->year);
	ds1302writebyte(0x8C,temp);
	
	ds1302writebyte(0xC0,0xA8);
	
	ds1302writebyte(0x8E,0x80);	
}


void ds1303_update_hr(unsigned char hr)
{
	unsigned char temp;
	ds1302writebyte(0x8E,0x00);
	
	temp = hex_bcd(hr);
	ds1302writebyte(0x84,temp);
	
	ds1302writebyte(0x8E,0x80);	
}
void ds1303_update_min(unsigned char min)
{
	unsigned char temp;
	ds1302writebyte(0x8E,0x00);
	
	temp = hex_bcd(min);
	ds1302writebyte(0x82,temp);
	
	ds1302writebyte(0x8E,0x80);	
}
void ds1303_update_sec(unsigned char sec)
{
	unsigned char temp;
	ds1302writebyte(0x8E,0x00);
	
	temp = hex_bcd(sec);
	ds1302writebyte(0x80,temp);
	
	ds1302writebyte(0x8E,0x80);	
}

