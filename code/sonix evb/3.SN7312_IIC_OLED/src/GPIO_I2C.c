#include "GPIO_I2C.h"

/*
* System Clock = 96MHZ
*	nop(10):I2C Clock = 400KHZ
*/


/*
*Fun:			GPIO_I2C_Init
*Input:		Null
*Output:	Null
*Description：Init GPIO I2C Mode & DATA
*/
void GPIO_I2C_Init(void)
{
	//SCK Output H
	I2C_SCK_Mode_Output;
	I2C_SCK_CFG_H;
	I2C_SCK_SET;
	//DATA Output H
	I2C_DAT_Mode_Output;
	I2C_DAT_CFG_H;
	I2C_DAT_SET;
}
void nop(u8 x)
{
	while(x--)
	{
		__nop();
	}
}
void I2CWriteByte(unsigned char data)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(data&0x80)
		{
			I2C_DAT_SET;
		}
		else
		{
			I2C_DAT_CLR;
		}
		data<<=1;
		I2C_SCK_SET;
		nop(12);
		I2C_SCK_CLR;
		nop(10);
	}
}
unsigned char I2CReadByte(void)
{
	unsigned char i,data=0;
	I2C_DAT_Mode_Input;
	for(i=0;i<8;i++)
	{
		data = data <<1;
		I2C_SCK_SET;
		if(I2C_DAT_GET)
		{
			data++;
		}
		nop(10);
		I2C_SCK_CLR;
		nop(10);
	}
	I2C_DAT_Mode_Output;
	return data;
}

unsigned char ReadACK(void)
{
//	unsigned char i;
//	I2C_DAT_Mode_Input;
	I2C_DAT_CLR;
	I2C_SCK_SET;
	nop(10);
//	i = I2C_DAT_GET;
	I2C_SCK_CLR;
//	I2C_DAT_Mode_Output;
	nop(20);
	return ACK;
}
/*
*ACK = 1
*NACK = 0
*/
void WriteACK(unsigned char ack)
{
	if(ack == ACK)
		I2C_DAT_CLR;
	else
		I2C_DAT_SET;
	I2C_SCK_SET;
	nop(10);
	I2C_SCK_CLR;
	nop(10);
}
unsigned char GPIO_I2C_ReadBytes(unsigned char Device,unsigned char Reg,unsigned char Length,unsigned char* buf)
{
	unsigned char i = 0;
	//start condition
	I2C_DAT_SET;
	nop(10);
	I2C_SCK_SET;
	nop(10);
	I2C_DAT_CLR;
	nop(10);
	I2C_SCK_CLR;
	nop(10);
	//send device write data
	I2CWriteByte(Device);
	if(ReadACK() == NACK)
		return 1;
	
	//send reg	data
	I2CWriteByte(Reg);
	if(ReadACK() == NACK)
		return 1;
	
	//start condition
	I2C_DAT_SET;
	nop(10);
	I2C_SCK_SET;
	nop(20);
	I2C_DAT_CLR;
	nop(10);
	I2C_SCK_CLR;
	nop(10);
	//send device read data
	I2CWriteByte(Device+READ_CMD);
	if(ReadACK() == NACK)
		return 1;
	
	//read bytes
	for(i=0;i<Length;i++)
	{
		buf[i] = I2CReadByte();
		if(i == Length -1 )
			WriteACK(NACK);
		else
			WriteACK(ACK);
	}
	//stop condition
	I2C_DAT_CLR;
	nop(10);
	I2C_SCK_SET;
	nop(10);
	I2C_DAT_SET;
	
	return 0;
}

unsigned char GPIO_I2C_WriteBytes(unsigned char Device,unsigned char Reg,unsigned char Length,unsigned char* buf)
{
	unsigned char i = 0;
	//start condition
	I2C_DAT_SET;
	nop(10);
	I2C_SCK_SET;
	nop(10);
	I2C_DAT_CLR;
	nop(10);
	I2C_SCK_CLR;
	nop(10);
	//send device write data
	I2CWriteByte(Device);
	if(ReadACK() == NACK)
		return 1;
	
	//send reg	data
	I2CWriteByte(Reg);
	if(ReadACK() == NACK)
		return 1;
	for(i=0;i<Length;i++)
	{
		I2CWriteByte(buf[i]);
		if(ReadACK() == NACK)
			return 1;
	}
	//stop condition
	I2C_DAT_CLR;
	nop(10);
	I2C_SCK_SET;
	nop(10);
	I2C_DAT_SET;
		
	return 0;
}

unsigned char GPIO_I2C_WriteSingleByte(unsigned char Device,unsigned char Reg,unsigned char Data)
{
	unsigned char temp;
	temp = Data;
	return GPIO_I2C_WriteBytes(Device,Reg,1,(unsigned char *)&temp);
}

unsigned char GPIO_I2C_ReadSingleByte(unsigned char Device,unsigned char Reg)
{
	unsigned char temp ;
	if(GPIO_I2C_ReadBytes(Device,Reg,1,(unsigned char *)&temp) == 1)
		return 0xFF;
	return temp;
}
