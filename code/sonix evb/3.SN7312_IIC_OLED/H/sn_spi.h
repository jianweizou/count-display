#include "stdint.h"
#include "SNC7312.h"

/* SPI BUS MODE DEFINE */
#define SPI_MSBFirst_MODE0         0x00
#define SPI_MSBFirst_MODE1         0x01
#define SPI_MSBFirst_MODE2         0x02
#define SPI_MSBFirst_MODE3         0x03
#define SPI_LSBFirst_MODE0         0x10
#define SPI_LSBFirst_MODE1         0x11
#define SPI_LSBFirst_MODE2         0x12
#define SPI_LSBFirst_MODE3         0x13

/* SPI INTERRUPT DEFINE */
#define SPI_INT_TXFIFOTH           0x08
#define SPI_INT_RXFIFOTH           0x04
#define SPI_INT_RXTO               0x02
#define SPI_INT_RXOVF              0x01

/* SPI STATUS DEFINE */
#define SPI_STATUS_TXFIFOTH        0x40
#define SPI_STATUS_RXFIFOTH        0x20
#define SPI_STATUS_BUSY            0x10
#define SPI_STATUS_RXFULL          0x08
#define SPI_STATUS_RXEMPTY         0x04
#define SPI_STATUS_TXFULL          0x02
#define SPI_STATUS_TXEMPTY         0x01

/***/
#define Master_Mode 0
#define Slave_Mode  1

void SPI0_Enable(void);
void SPI0_Disable(void);
void SPI0_Bus_Mode_Setting(uint8_t ucTsmtMode);
void SPI0_Master_Slave_Setting(uint8_t ucMS,uint8_t ucFIFOTH,uint8_t ucSDODIS);
void SPI0_Auto_SEL_Setting(uint8_t ucEn);
void SPI0_SEL_Ctrl(uint8_t ucSel);
void SPI0_Data_Length_Setting(uint8_t ucDL);
void SPI0_Data_Length_Setting(uint8_t ucDIV);
uint8_t SPI0_Check_Status(void);
uint8_t SPI0_Read_Status(void);
void SPI0_Clear_Flag(uint8_t ucClrFlag);
void SPI0_Interrupt_Enable(uint8_t ucINTEn);
uint16_t SPI0_Receive_Data(void);
void SPI0_Send_Data(uint16_t usData);
void SPI0_LoopBack_Enable(uint8_t ucLoopBack);
uint8_t SPI0_Check_Flag(void);
void SPI0_Reset_State(void);

void SPI1_Enable(void);
void SPI1_Disable(void);
void SPI1_Bus_Mode_Setting(uint8_t ucTsmtMode);
void SPI1_Master_Slave_Setting(uint8_t ucMS,uint8_t ucFIFOTH,uint8_t ucSDODIS);
void SPI1_Auto_SEL_Setting(uint8_t ucEn);
void SPI1_SEL_Ctrl(uint8_t ucSel);
void SPI1_Data_Length_Setting(uint8_t ucDL);
void SPI1_Data_Length_Setting(uint8_t ucDIV);
uint8_t SPI1_Check_Status(void);
uint8_t SPI1_Read_Status(void);
void SPI1_Clear_Flag(uint8_t ucClrFlag);
void SPI1_Interrupt_Enable(uint8_t ucINTEn);
uint16_t SPI1_Receive_Data(void);
void SPI1_Send_Data(uint16_t usData);
void SPI1_LoopBack_Enable(uint8_t ucLoopBack);
uint8_t SPI1_Check_Flag(void);
void SPI1_Reset_State(void);

