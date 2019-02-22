#ifndef __SNC7300_SDCARD_H
#define __SNC7300_SDCARD_H

/*_____ I N C L U D E S ____________________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/
#define	SD_4BIT_MODE    0x01
#define	SD_SPI_MODE     0X04

#define NO_ERROR				0x00
#define RW_TO_ERR				0x01
#define CRC_ERR					0x02
#define WRITE_ERR				0x03
#define RETRY_TO_ERR    0x04
#define CMD_TO_ERR			0x05
#define SDC_TIME_OUT		0x40
#define SDC_BUSY				0x80

#define CMD7_ERR				0x06
#define ACMD6_ERR				0x07
#define ACMD41_ERR			0x08
#define CMD6_ERR				0x09
#define CMD55_ERR       0x0A
#define CMD58_ERR       0x0B
#define NO_SUPPLY_CARD  0x0C

#define RES_NONE		0
#define RES_R1			1
#define RES_R2			2
#define RES_R3			3
#define RES_R4			4
#define RES_R5			5
#define RES_R6			6
#define RES_R7			7
#define RES_R1B			8

#define SD_CARD			1
#define MMC_CARD		2

#define	V1X_SDSC		1
#define	V20_SDSC		2
#define	V20_SDHC		3

#define	HEAD				1
#define	MIDDLE			2
#define	TAIL				3

#define CMD_TO_VALUE 		0xFFFFFFFF
#define RW_TO_VALUE_L		0xFFFF
#define RW_TO_VALUE_H 		0xFFFF
#define SDC_SPEED_24MHz		0x0000
#define SDC_SPEED_16MHz		0x0001
#define SDC_SPEED_12MHz		0x0002

/*_____ M A C R O S ________________________________________________________*/

/*_____ D E C L A R A T I O N S ____________________________________________*/
extern uint32_t g_uiSDC0CMDTimeOutValue;
extern uint8_t g_ucSDC0CardType, g_ucSDC0CardVer;
extern uint32_t g_uiSDC0TotalBlockNum;

extern uint32_t g_uiSDC1CMDTimeOutValue;
extern uint8_t g_ucSDC1CardType, g_ucSDC1CardVer;
extern uint32_t g_uiSDC1TotalBlockNum;

//uint8_t SDC0_4BIT_Init(uint32_t uiCMDTimeOutValue, uint16_t usRWTimeOutValueH, uint16_t usRWTimeOutValueL, uint8_t ucSDCSpeed, uint8_t SDC_Mode, uint32_t pin_option);
uint8_t SDC0_4BIT_Init(uint32_t uiCMDTimeOutValue, uint16_t usRWTimeOutValueH, uint16_t usRWTimeOutValueL, uint8_t ucSDCSpeed);
void SDC0_Disable_Function(void);
uint8_t SDC0_Read_Single_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
uint8_t SDC0_Write_Single_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
uint8_t SDC0_Read_Multi_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
uint8_t SDC0_Write_Multi_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
uint8_t SDC0_Erase_Function(uint32_t uiStartSecCnt, uint32_t uiEndSecCnt);
void SDC0_Write_Single_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
void SDC0_Write_Multi_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
void SDC0_Read_Single_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
void SDC0_Read_Multi_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
uint8_t SDC0_Polling_Flag(void);
void SDC0_Pin_Switch_Enable(void);
	
//uint8_t SDC1_4BIT_Init(uint32_t uiCMDTimeOutValue, uint16_t us_RWTimeOutValueH, uint16_t us_RWTimeOutValueL, uint8_t ucSDCSpeed, uint8_t SDC_Mode, uint32_t pin_option);
uint8_t SDC1_4BIT_Init(uint32_t uiCMDTimeOutValue, uint16_t us_RWTimeOutValueH, uint16_t us_RWTimeOutValueL, uint8_t ucSDCSpeed);
void SDC1_Disable_Function(void);
uint8_t SDC1_Read_Single_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
uint8_t SDC1_Write_Single_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
uint8_t SDC1_Read_Multi_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
uint8_t SDC1_Write_Multi_Block(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
uint8_t SDC1_Erase_Function(uint32_t uiStartSecCnt, uint32_t uiEndSecCnt);
void SDC1_Write_Single_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
void SDC1_Write_Multi_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
void SDC1_Read_Single_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucSDMode);
void SDC1_Read_Multi_Block_Polling(uint32_t uiSecCnt, uint32_t uiDataBufAddr, uint8_t ucType, uint8_t ucSDMode);
uint8_t SDC1_Polling_Flag(void);
void SDC1_Pin_Switch_Enable(void);

#endif	/*__SNC7300_SDCARD_H*/

