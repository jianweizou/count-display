#ifndef __I2C_H__
#define __I2C_H__

#include <stdio.h>
#include "SNC7312.h"
//#include "sn_i2c.h"

void	Delay1usFor96MHz(u32 us);
void	I2C_Start(void);
void	I2C_Stop(void);
void	I2C_Send_Byte(uint8_t tx_data);
uint8_t I2C_Read_Byte(void);
void	Dvice_WriteData(uint8_t DeciveAddr,uint8_t DataAddr,uint8_t Data);
void	Decive_ReadData(uint8_t DeciveAddr,uint8_t DataAddr,uint8_t ReciveData);
void	I2C_Ack(void);
void	I2C_NoAck(void);
uint8_t I2C_Wait_Ack(void);
extern void Write_I2C_Byte(unsigned char IIC_Byte);

/**********************************************
SCL--- P31
SDA--- P30
**************************************************/
//SDA
#define		SDA_DATA		SN_GPIO3->DATA_b.DATA0
#define		SDA_MODE_IN		(SN_GPIO3->MODE_b.MODE0 = 0) //P3.0 input mode 0
#define		SDA_MODE_OUT	(SN_GPIO3->MODE_b.MODE0 = 1) //P3.0 output mode 1
#define		SDA_PULL_HIGH	SN_GPIO3->CFG_b.CFG1 = 0;		//SDA PULL HIGH	

//SCL
#define		SCL_DATA		SN_GPIO3->DATA_b.DATA1
//#define		SCL_MODE_IN		(SN_GPIO3->MODE_b.MODE1 = 0) //P3.1 input mode 0
#define		SCL_MODE_OUT	(SN_GPIO3->MODE_b.MODE1 = 1) //P3.1 output mode 1

#define		I2C_Delay()		Delay1usFor96MHz(5)
//#define		I2C_Delay()		__asm("nop")

#endif
