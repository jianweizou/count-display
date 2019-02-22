/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/04
* IC:			      SNC7312
* DESCRIPTION:	OID functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		     2016/04/11	   	   SA2			
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/

#ifndef	__OID_FUNC_H
#define	__OID_FUNC_H

/*_____ I N C L U D E S ____________________________________________________*/
#include "snc7312.h"

/*_____ M A C R O S ________________________________________________________*/
typedef struct 
{
	uint32_t OpticalData;
	uint16_t OpticalDataH;
	uint16_t OpticalDataL;
	uint16_t OpticalFlag;
	uint16_t OIDReadValid;
	uint8_t	IO_Switch;
	uint8_t	OID_CLKDIV; 
} OID_IDX;

typedef enum
{
	SDC0_withFAT,
	SDC0_withoutFAT,
	SDC1_withFAT,
	SDC1_withoutFAT,
	SPIFLASH,
	XTRAROM_withFAT,
}OID_STORAGE;

typedef enum
{
	OID_IO_NotSIWTCH,
	OID_IO_SIWTCH,
}OID_IOSWITCH;

typedef enum
{
	OID_MODE_FAIL,
	OID_MODE_OID2,
	OID_MODE_OID3,
}OID_MODE;

typedef enum
{
	OID_PD_withResponse,
	OID_PD_withoutResponse,
}OID_PD;

typedef enum
{
	OID_Read_INVALID,
	OID_Read_VALID,
}OID_READ;

/*_____ D E F I N I T I O N S ______________________________________________*/
#define	OID_CMD_PD					0x0056		//UserCmd_PowerDownOID
#define	OID_CMD_AUTO_EN			0x00A0		//UserCmd_AutoSleepFunEnable
#define	OID_CMD_AUTO_DIS		0x00A3		//UserCmd_AutoSleepFunDisable
#define	OID_CMD_CLR_TIMER		0x00A6		//UserCmd_TriggerToClearAutoSleepTimer
#define	OID_CMD_CLR_DETECT	0x00AC		//UserCmd_ClearAutoSleepTimerIfOIDDetect
#define	OID_CMD_NON_CLR			0x0050		//UserCmd_NonClearAutoSleepTimerIfOIDDetect
#define	OID_CMD_STATUS			0x0030		//UserCmd_CheckOIDStatus

#define	OID_CMD_MASK		0x00700000
#define	OID_INDEX_MASK	0x0003FFFF
#define OID_OID_ID			0x00400000
#define OID_CMD_ID			0x00200000
#define OID_BAT_STATUS	0x00100000
#define	OID_POWER_ON		0x0060FFF8
#define	OID_POWER_DOWN	0x0060FFF7
#define	OID_SYS_RESET		0x0060FFF1

#define OID_DATA_DONTCARE	0x0003FFFB

/*_____ D E C L A R A T I O N S ____________________________________________*/
//--------------------------------------------------------------------
//			Global Variable declaration
//--------------------------------------------------------------------
extern OID_IDX OIDIdx;
extern uint16_t TranCommand;

//--------------------------------------------------------------------
//			Function Declaration
//--------------------------------------------------------------------

extern uint16_t OID_CheckReadData(void);
extern uint16_t OID3_ReceiveData(uint32_t ucFlagPtr,uint32_t ucDataPtr);
extern uint16_t OID_Init(uint16_t OIDStorageDevice, uint32_t DeviceAddr ,uint32_t SRAMAddr,uint8_t OID_Switch);
extern void OID_Auto_PD(uint8_t uiOIDPDEn);
extern uint8_t OID_PowerOn(void);
extern uint8_t OID_PowerDown(void);
#endif	//__OID_FUNC_H
