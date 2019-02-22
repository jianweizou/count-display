/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Jun/21/2017
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 I2C demo code, Slave Address of 24LC64 = 0xA0
//
//   ____________           ______________ 
//  |            |   SDA    |             |
//  |            |<-------->|             |
//  |            |          |             |
//  |N76E003(M) |          |   24LC64(S) |
//  |            |   SCL    |             |
//  |            |--------->|             |
//  |____________|          |_____________|
//
//  Microchip I2C EEPROM 24xx64 (64K Bit) is used as the slave device.  
//  The page size are 32Byte. Total are 256 page.
//  If verification passes, Port3 will show 0x78. If there is any failure
//  occured during the progress, Port3 will show 0x00.
//***********************************************************************************************************

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"

#define I2C_CLOCK               2


bit I2C_Reset_Flag;
//========================================================================================================
void Init_I2C(void)
{
		P13_OpenDrain_Mode;					// Modify SCL pin to Open drain mode. don't forget the pull high resister in circuit
		P14_OpenDrain_Mode;					// Modify SDA pin to Open drain mode. don't forget the pull high resister in circuit
	
    /* Set I2C clock rate */
    I2CLK = I2C_CLOCK; 

    /* Enable I2C */
    set_I2CEN;                                   
}
//========================================================================================================
void I2C_SI_Check(void)
{
		if (I2STAT == 0x00)
		{
				I2C_Reset_Flag = 1;
				set_STO;
				SI = 0;
				if(SI)
				{
						clr_I2CEN;
						set_I2CEN;
						clr_SI;
						clr_I2CEN;		
				} 	
		}	
}

//========================================================================================================
void IIC_WriteMultiBytes(unsigned char device,unsigned char cmd_data,unsigned char *buf,unsigned char len)
{
	unsigned char length = 0;
	if (len == 0)
		return;
    /* Step1 */
    set_STA;                                /* Send Start bit to I2C EEPROM */         
    clr_SI;
    while (!SI);
    if (I2STAT != 0x08)                     /* 0x08:  A START condition has been transmitted*/
    {
        I2C_Reset_Flag = 1;
        goto Write_Error_Stop;
    }

    /* Step2 */
    clr_STA;                                /* Clear STA and Keep SI value in I2CON */
    I2DAT = device;         				/* Send (SLA+W) to EEPROM */
    clr_SI;
    while (!SI);
    if (I2STAT != 0x18)                     /* 0x18: SLA+W has been transmitted; ACK has been received */             
    {
        I2C_Reset_Flag = 1;
        goto Write_Error_Stop;
    }

    /* Step3 */
	while(length<len)
	{
		I2DAT = cmd_data << 6;
		clr_SI;
		while (!SI);
		if (I2STAT != 0x28)                     /* 0x28:  Data byte in S1DAT has been transmitted; ACK has been received */
		{
			I2C_Reset_Flag = 1;
			goto Write_Error_Stop;
		}
		I2DAT = buf[length];
		clr_SI;
		while (!SI);
		if (I2STAT != 0x28)                     /* 0x28:  Data byte in S1DAT has been transmitted; ACK has been received */
		{
			I2C_Reset_Flag = 1;
			goto Write_Error_Stop;
		}
	}
    /* Step7 */
    set_STO;                                /* Set STOP Bit to I2C EEPROM */
    clr_SI;
	while (STO)                        /* Check STOP signal */
	{
		I2C_SI_Check();
		if (I2C_Reset_Flag)
			goto Write_Error_Stop;
	}
		
	Write_Error_Stop: 
	if (I2C_Reset_Flag)
	{
			I2C_SI_Check();
			I2C_Reset_Flag	= 0;
	}
}

void IIC_WriteSingleByte(unsigned char device ,unsigned char cmd_data,unsigned char val)
{
	unsigned char buf;
	buf = val;
	IIC_WriteMultiBytes(device,cmd_data,(unsigned char *)&buf,1);
}
