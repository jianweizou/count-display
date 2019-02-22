#ifndef _GPIO_I2C_H_
#define _GPIO_I2C_H_

#include "snc7312.h"
#define GPIO_I2C_Enable	1

#define I2C_SCK_Mode_Output SN_GPIO0->MODE_b.MODE0 = 1
#define I2C_SCK_Mode_Input 	SN_GPIO0->MODE_b.MODE0 = 0
#define I2C_SCK_CFG_H		SN_GPIO0->CFG_b.CFG0 = 0
#define I2C_SCK_CFG_L		SN_GPIO0->CFG_b.CFG0 = 2
#define I2C_DAT_Mode_Output SN_GPIO0->MODE_b.MODE1 = 1
#define I2C_DAT_Mode_Input 	SN_GPIO0->MODE_b.MODE1 = 0
#define I2C_DAT_CFG_H		SN_GPIO2->CFG_b.CFG1 = 0
#define I2C_DAT_CFG_L		SN_GPIO0->CFG_b.CFG1 = 2

#define I2C_SCK_SET		SN_GPIO0->DATA_b.DATA0 = 1
#define I2C_DAT_SET		SN_GPIO0->DATA_b.DATA1 = 1

#define I2C_SCK_CLR		SN_GPIO0->DATA_b.DATA0 = 0
#define I2C_DAT_CLR   	SN_GPIO0->DATA_b.DATA1 = 0

#define I2C_DAT_GET		SN_GPIO0->DATA_b.DATA1

#define READ_CMD	1
#define WRITE_CMD	0
#define ACK		0
#define NACK	1

void GPIO_I2C_Init(void);
unsigned char GPIO_I2C_WriteSingleByte(unsigned char Device,unsigned char Reg,unsigned char Data);
unsigned char GPIO_I2C_ReadSingleByte(unsigned char Device,unsigned char Reg);
unsigned char GPIO_I2C_ReadBytes(unsigned char Device,unsigned char Reg,unsigned char Length,unsigned char* buf);
unsigned char GPIO_I2C_WriteBytes(unsigned char Device,unsigned char Reg,unsigned char Length,unsigned char* buf);
void WriteACK(unsigned char ack);
unsigned char ReadACK(void);
#endif
