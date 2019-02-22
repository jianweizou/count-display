#include "SNC7312.h"
#include "i2c.h"

uint8_t ack = 0;
//启动信号 
void I2C_Start()
{
    //数据线下降沿
    SDA_DATA = 1;
	SCL_DATA = 1;	
    I2C_Delay();
    SDA_DATA = 0;
    I2C_Delay();
	SCL_DATA = 0;
	I2C_Delay();
}

//停止信号 
void I2C_Stop()
{
	SDA_DATA = 0;
//	I2C_Delay();
	SCL_DATA = 1;
	I2C_Delay();
    //数据线上升沿
    SDA_DATA = 1;
//	I2C_Delay();
}

//写一个字节数据
void I2C_Send_Byte(uint8_t tx_data)
{
    uint8_t i;
    for(i = 0;i < 8; i ++)
    {	
        SDA_DATA = ((tx_data & 0x80)>> 7);
		tx_data <<= 1;

        SCL_DATA = 1;
        I2C_Delay();
		SCL_DATA = 0;
        I2C_Delay();
    }
}

uint8_t I2C_Wait_Ack(void)
{
    //先将数据线要设置成输入模式,有应答则会出现下降沿
	SDA_MODE_IN;
	SCL_DATA = 1;
	I2C_Delay();
	if(SDA_DATA)
	{
		I2C_Stop();
		SDA_MODE_OUT;
		SCL_DATA = 0;
		I2C_Delay();
		return 1;
	}
	SDA_MODE_OUT;
	SCL_DATA = 0;
	I2C_Delay();
	return 0;
}

//写数据
void Dvice_WriteData(uint8_t DeciveAddr,uint8_t DataAddr,uint8_t Data)
{
    I2C_Start();
    I2C_Send_Byte(DeciveAddr);
    I2C_Wait_Ack();
    I2C_Send_Byte(DataAddr);
    I2C_Wait_Ack();
    I2C_Send_Byte(Data);
	I2C_Wait_Ack();
    I2C_Stop();     
}

//应答
void I2C_Ack()
{
    //数据线一直保持为低电平，时钟线出现上升沿即为应答
    SDA_DATA = 0;
    SCL_DATA = 0;
    I2C_Delay();
    SCL_DATA = 1;
    I2C_Delay();
}

uint8_t I2C_Read_Byte()
{
    uint8_t i = 0;
    uint8_t receive = 0;
    //数据线模式切换为输入
	SDA_MODE_IN;
    for(i = 0;i < 8; i ++)
    {
        SCL_DATA = 0;
        I2C_Delay();
		SCL_DATA = 1;
		I2C_Delay();
		receive <<= 1;
        //判断数据线电平
        if(SDA_DATA)
        {
            receive ++;
        }
    }
	SDA_MODE_OUT;
	I2C_Ack();
	return receive;
}

//uint8_t Decive_ReadData(uint8_t DeciveAddr,uint8_t DataAddr,uint8_t ReciveData)
//{
//    uint8_t i;
//    I2C_Start();
//    I2C_Send_Byte(DeciveAddr);
//    I2C_Wait_Ack();
//    I2C_Send_Byte(DataAddr);                     
//    I2C_Wait_Ack();     
//    //发送器件地址读模式
//    I2C_Send_Byte(DeciveAddr + 1);
//    //等待应答
//    I2C_Wait_Ack();
//    for(i = 0;i < 8;i ++)
//    {
//        ReciveData= I2C_Read_Byte();
//        ReciveData++;
//    }
//    //停止信号

//    I2C_Stop();
//	return ReciveData;
//}
