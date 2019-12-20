#ifndef __I2C_H__
#define __I2C_H__

#include <stdio.h>

int	I2C_Start(void);
void	I2C_Stop(void);
void	I2C_Send_Byte(unsigned char  tx_data);
unsigned char  I2C_Read_Byte(void);
void	Dvice_WriteData(unsigned char  DeciveAddr,unsigned char  DataAddr,unsigned char  Data);
void	Decive_ReadData(unsigned char  DeciveAddr,unsigned char  DataAddr,unsigned char  ReciveData);
void	I2C_Ack(void);
void	I2C_NoAck(void);
unsigned char  I2C_Wait_Ack(void);
extern void Write_I2C_Byte(unsigned char IIC_Byte);

#define IIC_SELECT	1	//0 i2c.c
/**********************************************
SCL--- P31
SDA--- P30
**************************************************/
//SDA
#define		SDA_DATA			P11
#define		SDA_MODE_IN		P11_Input_Mode
#define		SDA_MODE_OUT	P11_OpenDrain_Mode
#define		SDA_PULL_HIGH	P11_PushPull_Mode

//SCL
#define		SCL_DATA			P12
#define		SCL_MODE_IN		P12_Input_Mode
#define		SCL_MODE_OUT	P12_OpenDrain_Mode
//#define		I2C_Delay()		

#endif
