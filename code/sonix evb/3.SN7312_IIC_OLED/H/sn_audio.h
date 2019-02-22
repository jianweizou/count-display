/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/04
* IC:			      SNC7312
* DESCRIPTION:	GPIO functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		     2016/04/08	   	   SA2			
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/
#ifndef __SNC7312_Audio_H
#define __SNC7312_Audio_H

/*_____ I N C L U D E S ____________________________________________________*/
#include "SNC7312.h"
/*_____ D E F I N I T I O N S ______________________________________________*/
/* I2S */
#define I2S_CHANNEL_8BIT		7
#define I2S_CHANNEL_16BIT		15
#define I2S_CHANNEL_32BIT		31
#define I2S_DATA_8BIT				0
#define I2S_DATA_16BIT			1
#define I2S_DATA_32BIT			2
#define I2S_STD         0
#define I2S_LJ          1
#define I2S_RJ          2
#define I2S_MONO        1
#define I2S_STEREO      0
#define I2S_MASTER      0
#define I2S_SLAVE	      1

/* SD_ADC */
#define ADC_MONO        1
#define ADC_STEREO      0

/* SD_DAC */
#define m_SD_DAC_VOL_MIN 63
#define DAC_MONO        1
#define DAC_STEREO      0

/* Type */
#define MUTE_OFF        0
#define MUTE_ON         1

#define	SR_32K			0
#define	SR_16K			1
#define	SR_8K				2
#define	SR_4K				3
#define	SR_44_1K		4
#define	SR_22_05K		5
#define	SR_11_025K	6
#define	SR_5_5125K	7
#define	SR_48K			8
#define	SR_24K			9
#define	SR_12K			10
#define	SR_6K				11

#define FPLL_IHRC   0
#define FPLL_XTAL   1

/*_____ M A C R O S ________________________________________________________*/
/* FPLL */
struct AUDIO_LIB_REG_TYPE{
	uint8_t FPLL_SR;	
	uint8_t DAC_Volume;
};

/* I2S */
typedef struct{                                    /*!< SN_I2S Structure                                                      */
	 
	union{
		uint32_t  DW;                            /*!< Offset:0x00 I2S Control Register                                      */
  
		struct{
			uint32_t  START      :  1;               /*!< Start Transmit/Receive                                                */
			uint32_t  MUTE       :  1;               /*!< Mute enable                                                           */
			uint32_t  MONO       :  1;               /*!< Mono/stereo selection                                                 */
			uint32_t  MS         :  1;               /*!< Master/Slave selection bit                                            */
			uint32_t  FORMAT     :  2;               /*!< I2S operation format                                                  */
			uint32_t  TXEN       :  1;               /*!< Transmit enable bit                                                   */
			uint32_t  RXEN       :  1;               /*!< Receiver enable bit                                                   */
			uint32_t  CLRTXFIFO  :  1;               /*!< Clear I2S TX FIFO                                                     */
			uint32_t  CLRRXFIFO  :  1;               /*!< Clear I2S RX FIFO                                                     */
			uint32_t  DL         :  2;               /*!< Data length                                                           */
			uint32_t  PAUSE  	   :  1;               /*!< PAUSE Mode                                                    				 */
			uint32_t  R13        :  7;
			uint32_t  CHLENGTH   :  5;               /*!< Bit number of single channel                                          */
			uint32_t  R25        :  4;
			uint32_t  ADCEN      :  1;               /*!< ADC enable                                                            */
			uint32_t  DACEN      :  1;               /*!< DAC enable                                                            */
			uint32_t  I2SEN      :  1;               /*!< I2S enable                                                            */
		}b; 	
	}CTRL;
	
	__IO uint32_t  TxRxRAMLength;			//
	__IO uint32_t  TxRAMADR1;					//
	__IO uint32_t  TxRAMADR2;					//
	__IO uint32_t  TxRAMIDX;					//
	
	__IO uint32_t  RxRAMADR1;					//
	__IO uint32_t  RxRAMADR2;					//
	__IO uint32_t  RxRAMIDX;					//	
}EXT_I2S2_CTRL_TYPE;

extern EXT_I2S2_CTRL_TYPE st_I2S2_Reg;

/*_____ D E C L A R A T I O N S ____________________________________________*/
/* FPLL */
uint8_t FPLL_Turn_On(uint8_t ucCLKSrc,uint8_t _uiSR);
uint8_t FPLL_Turn_Off(void);

/* I2S0 */
void I2S0_Enable(void);
void I2S0_Disable(void);
void I2S0_Start(void);
void I2S0_Stop(void);
void I2S0_MS_TR_Select(uint8_t ucMS,uint8_t ucTXEN,uint8_t ucRXEN);
void I2S0_TR_Length(uint8_t ucChannel,uint8_t ucData);
void I2S0_Format(uint8_t ucFormat);
void I2S0_Channel(uint8_t ucChannel);
uint8_t I2S0_Sample_Rate_Select(uint8_t ucCLKSrc,uint8_t ucSR);
void I2S0_RAM_Buf_Parameter(uint16_t usTxRxRAMLength,uint32_t uiTxRAMADR1,uint32_t uiTxRAMADR2,uint32_t uiRxRAMADR1,uint32_t uiRxRAMADR2);
uint32_t I2S0_TX_RAM_Idx(void);
uint32_t I2S0_RX_RAM_Idx(void);
void I2S0_TX_RAM_Idx_Clr(void);
void I2S0_RX_RAM_Idx_Clr(void);
void I2S0_Pause(uint8_t ucPause);
void I2S0_Mute(uint8_t ucMute);
void I2S0_Interrupt_Init(uint8_t ucTxTOGEN,uint8_t ucRxTOGEN);

/* I2S1 */
void I2S1_Enable(void);
void I2S1_Disable(void);
void I2S1_Start(void);
void I2S1_Stop(void);
void I2S1_MS_TR_Select(uint8_t ucMS,uint8_t ucTXEN,uint8_t ucRXEN);
void I2S1_TR_Length(uint8_t ucChannel,uint8_t ucData);
void I2S1_Format(uint8_t ucFormat);
void I2S1_Channel(uint8_t ucChannel);
uint8_t I2S1_Sample_Rate_Select(uint8_t ucCLKSrc,uint8_t ucSR);
void I2S1_RAM_Buf_Parameter(uint16_t usTxRxRAMLength,uint32_t uiTxRAMADR1,uint32_t uiTxRAMADR2,uint32_t uiRxRAMADR1,uint32_t uiRxRAMADR2);
uint32_t I2S1_TX_RAM_Idx(void);
uint32_t I2S1_RX_RAM_Idx(void);    
void I2S1_TX_RAM_Idx_Clr(void);
void I2S1_RX_RAM_Idx_Clr(void);
void I2S1_Pause(uint8_t ucPause);
void I2S1_Mute(uint8_t ucMute);
void I2S1_Interrupt_Init(uint8_t ucTxTOGEN,uint8_t ucRxTOGEN);

/* I2S2 */
void I2S2_Enable(void);
void I2S2_Disable(void);
void I2S2_Start(void);
void I2S2_Stop(void);
void I2S2_MS_TR_Select(uint8_t ucMS,uint8_t ucTXEN,uint8_t ucRXEN);
void I2S2_TR_Length(uint8_t ucChannel,uint8_t ucData);
void I2S2_Format(uint8_t ucFormat);
void I2S2_Channel(uint8_t ucChannel);
uint8_t I2S2_Sample_Rate_Select(uint8_t ucCLKSrc,uint8_t ucSR);
void I2S2_RAM_Buf_Parameter(uint16_t usTxRAMLength,uint32_t uiTxRAMADR1,uint32_t uiTxRAMADR2,uint32_t uiRxRAMADR1,uint32_t uiRxRAMADR2);
uint32_t I2S2_TX_RAM_Idx(void);
uint32_t I2S2_RX_RAM_Idx(void);
void I2S2_TX_RAM_Idx_Clr(void);
void I2S2_RX_RAM_Idx_Clr(void);
void I2S2_Pause(uint8_t ucPause);
void I2S2_Mute(uint8_t ucMute);
void I2S2_Interrupt_Init(uint8_t ucTxTOGEN,uint8_t ucRxTOGEN);
void I2S2_TH_Setting(uint8_t ucTX_TH,uint8_t ucRX_TH);
void I2S2_TxFIFO_Clear(void);
void I2S2_RIS_TxTH_Clr(void);
void I2S2_RIS_RxTH_Clr(void);
void I2S2_RIS_TxOV_Clr(void);
void I2S2_RIS_RxUD_Clr(void);

uint8_t I2S2_RIS_TxTH_Flag(void);
uint8_t I2S2_RIS_RxTH_Flag(void);
uint8_t I2S2_RIS_TxOV_Flag(void);
uint8_t I2S2_RIS_RxUD_Flag(void);
uint8_t I2S2_RxFIFO_Empty_Flag(void);
void I2S2_FIFO_Write(uint32_t ucI2S2Data);
uint32_t I2S2_FIFO_Read(void);
/* SD_ADC */
uint8_t SD_ADC_Turn_On(uint8_t ucCLKSrc, uint8_t ucADC_SR);
void SD_ADC_Turn_Off(void);
uint8_t SD_ADC_Gain_Ctrl(uint16_t usGainValue);
void SD_ADC_RAM_Buf_Parameter(uint16_t usRxRAMLength,uint32_t uiRxRAMADR1);
uint32_t SD_ADC_RX_RAM_Idx(void);
void SD_ADC_RX_RAM_Idx_Clr(void);
void SD_ADC_Channel(uint8_t ucChannel);
void SD_ADC_Pause(uint8_t ucPause);
uint8_t SD_ADC_RX_Toggle(void);

/* SD_DAC */
void SD_DAC_Initial(void);
uint8_t SD_DAC_Turn_On(uint8_t ucCLKSrc, uint8_t ucDAC_SR);
void SD_DAC_Turn_Off(void);
void SD_DAC_Volume_Control(uint8_t ucVolume);
void SD_DAC_RAM_Buf_Parameter(uint16_t usTxRAMLength,uint32_t uiTxRAMADR1,uint32_t uiTxRAMADR2);
void SD_DAC_Pause(uint8_t ucPause);
void SD_DAC_Mute(uint8_t ucMute);
void SD_DAC_Channel(uint8_t ucChannel);
uint32_t SD_DAC_TX_RAM_Idx(void);
void SD_DAC_TX_RAM_Idx_Clr(void);
uint8_t SD_DAC_TX_Toggle(void);

/* SD_DAC_AMP */
uint8_t SD_DAC_AMP_Turn_On(uint8_t ucCLKSrc, uint8_t ucDAC_SR);
void SD_DAC_AMP_Turn_Off(void);
void SD_DAC_AMP_Volume_Control(uint8_t ucVolume);

#endif           //SNC7312_Audio_H
