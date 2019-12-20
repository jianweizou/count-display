
#include "I2C_Software_Master.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "i2c.h"
#if IIC_SELECT
/***************************************************************/

#define I2C_DIRECTION_TRANSMITTER       ((char)0x00)
#define I2C_DIRECTION_RECEIVER          ((char)0x01)

#define SDA_H		SDA_DATA = 1
#define SDA_L		SDA_DATA = 0

#define SCL_H		SCL_DATA = 1
#define SCL_L		SCL_DATA = 0


void I2C_SoftWare_Master_Init(void)
{
	P12_PushPull_Mode;	//SCL PULL HIGH
	SCL_MODE_OUT;	//SCL output
	SCL_DATA = 1;	//SCL 1

	P11_PushPull_Mode;	//SDA PULL HIGH		
	SDA_MODE_OUT;	//SDA output	
	SDA_DATA = 1;	//SDA 1	
}

void Init_I2C(void)
{
	I2C_SoftWare_Master_Init();
}

int I2C_SoftWare_Master_ReInit(void)
{
    I2C_SoftWare_Master_Init();
  
    return -1;
}
  
void ACK_read_init(void)
{  
    SDA_MODE_IN;
}    

void ACK_read_deinit(void)
{    
    SDA_MODE_OUT;	//SDA output	
}

int SCL_read(void)
{
    return SCL_DATA;
}

int SDA_read(void)
{
    return SDA_DATA;
}    

/* ======================================================================================================== */

void I2C_delay(void)
{
}

int I2C_Start(void)
{
    SDA_H;
    SCL_H;
    I2C_delay();
    if (!SDA_read())
        return 0;
    SDA_L;
    I2C_delay();
    if (SDA_read())
        return 0;
    SCL_L;
    I2C_delay();
    return 1;
}

void I2C_Stop(void)
{
    SCL_L;
    I2C_delay();
    SDA_L;
    I2C_delay();
    SCL_H;
    I2C_delay();
    SDA_H;
    I2C_delay();
}


void I2C_Ack(void)
{
    SCL_L;
    I2C_delay();
    SDA_L;
    I2C_delay();
    SCL_H;
    I2C_delay();
    SCL_L;
    I2C_delay();
}

void I2C_NoAck(void)
{
    SCL_L;
    I2C_delay();
    SDA_H;
    I2C_delay();
    SCL_H;
    I2C_delay();
    SCL_L;
    I2C_delay();
}

int I2C_WaitAck(void)
{
    ACK_read_init();  
    
    SCL_L;
    I2C_delay();
    SDA_H;
    if (SDA_read())
    {
        SCL_H;
        I2C_delay();
        return 0;
    }
    SCL_H;
    I2C_delay();
    
    ACK_read_deinit(); 
    
    return 1;
}

void I2C_SendByte(char byte)
{
    char i = 8;
    while (i--)
    {
        SCL_L;
        I2C_delay();//
        if (byte & 0x80)
            SDA_H;
        else
            SDA_L;
        I2C_delay();
        byte <<= 1;
        I2C_delay();
        SCL_H;
        I2C_delay();
    }
    SCL_L;
}


int I2C_ReceiveByte(void)
{
    char i = 8;
    char byte = 0;

    ACK_read_init();/* set SDA to input */
    
    while (i--) 
    {
        byte <<= 1;
        SCL_L;
        I2C_delay();
        SCL_H;
        I2C_delay();
        if (SDA_read()) 
        {
            byte |= 0x01;
        }
    }
    SCL_L;
    
    ACK_read_deinit();/* set SDA to input */
        
    return byte;
}

int I2C_SoftWare_Master_Write(int DeviceAddr, char* pBuffer, int NumByteToWrite)
{
    int i;
    if (!I2C_Start())
        return I2C_SoftWare_Master_ReInit();
    
    I2C_delay();
    I2C_SendByte((DeviceAddr<<1) | I2C_DIRECTION_TRANSMITTER);
    if (!I2C_WaitAck())
    {
        //I2C_Stop();
        return -1;
    }
    
    I2C_delay();
   
    for (i = 0; i < NumByteToWrite; i++) 
    {
        I2C_SendByte(pBuffer[i]);
        if (!I2C_WaitAck()) 
        {
            //I2C_Stop();
            //return I2C_SoftWare_Master_ReInit();
            return -1;
        }
    }

    return 0; 
}

int I2C_SoftWare_Master_Write_One_Byte(int DeviceAddr,char cmd, char value)
{
	char buf[2];
	char temp;
	buf[0] = cmd;
	buf[1] = value;
	temp =  I2C_SoftWare_Master_Write(DeviceAddr,(char*)buf,2);
	I2C_Stop();
	return temp;
}

int I2C_Start_Master_read(void)
{
        I2C_delay();
        
        SCL_L;
        
        I2C_delay();
        
        if(!SCL_read())
        {
            SDA_H;            
        }else
        {        
            return 1;    
        }
        
        I2C_delay();
           
        if(!(SCL_read()&SDA_read()))      
        {
                I2C_delay();
        }
        
        I2C_Start();
                
        return 0;
}    

int I2C_SoftWare_Master_Read(char DeviceAddr, char* pBuffer, int NumByteToRead)
{
    I2C_delay();  
    
    I2C_Start_Master_read();

    I2C_SendByte((DeviceAddr<<1) | I2C_DIRECTION_RECEIVER);
    
    if (!I2C_WaitAck())
    {
        //I2C_Stop();
        return 1;
    }
    
    while (NumByteToRead) 
    {
        *pBuffer = I2C_ReceiveByte();
        if (NumByteToRead == 1)
            I2C_NoAck();
        else
            I2C_Ack();
        pBuffer++;
        NumByteToRead--;
    }
    
    
    return 0;
}

#endif
