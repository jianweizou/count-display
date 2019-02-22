/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/03
* IC:			      SNC7312
* DESCRIPTION:	I2C functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		         2016/03/31	   SA2			
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include "snc7312.h"


#ifndef _SNC7300_I2C_inc_H
#define _SNC7300_I2C_inc_H

#define PCLKI2C  48 //96Mhz

/*---- I2C Status Define------*/
#define S_RX_DN       0x0001
#define S_ACK_STAT    0x0002
#define S_NACK_STAT   0x0004
#define S_STOP_DN     0x0008
#define S_START_DN    0x0010
#define S_I2C_MST     0x0020
#define S_SLVRX_HIT   0x0040
#define S_SLVTX_HIT   0x0080
#define S_LOST_ARB    0x0100
#define S_TIMEOUT     0x0200
#define S_I2CIF       0x8000


/*---I2C STATUS
___________________________________________________________________________________
  Master(TX)            State               Slave(RX)             State
-----------------------------------------------------------------------------------
  START             F_MST_STRDN(0x8030)
  Address+(W)       F_MST_ACK(0x8022)       ACK/NACK        F_SLV_RX_ADRHIT(0x8040)
                   /F_MST_NACK(0x8024)                      
  Data              F_MST_ACK(0x8022)       ACK/NACK        F_SLV_RX_DN(0x8001)
                   /F_MST_NACK(0x8024)                      
  STOP              F_STOPDN(0x8008)                        F_STOPDN(0x8008)                    
  RESTART           F_MST_RESTR(0x8038)
___________________________________________________________________________________
  Master(RX)            State               Slave(Tx)             State
-----------------------------------------------------------------------------------
  START             F_MST_STRDN(0x8030)
  Address+(R)       F_MST_RX_DN(0x8021)      Data           F_SLV_TX_ADRHIT(0x8080)
  ACK               F_MST_ACK(0x8022)   
	                  F_MST_RX_DN(0x8021)      Data
  ACK               F_MST_ACK(0x8022)                     F_SLV_ACK(0x8002)
	ACK               F_MST_ACK(0x8022)        Data           F_SLV_ACK(0x8002)
	NACK              

*/

#define F_MST_STRDN   0x8030
#define F_STOPDN      0x8008 
#define F_MST_ACK     0x8022
#define F_MST_RESTR   0x8038
#define F_MST_RX_DN   0x8021
#define F_MST_NACK    0x8024


 extern void I2C_Enable(void);
 extern void I2C_Disable(void);
 extern void I2C_Address_Setting(uint8_t ucAddr_mode, uint8_t ucGeneral_En, uint16_t usSlv_Addr0, uint16_t usSlv_Addr1, uint16_t usSlv_Addr2, uint16_t usSlv_Addr3);
 extern void I2C_Send_ACK(void);
 extern void I2C_Send_NACK(void);
 extern void I2C_Set_Start_Condition(void);
 extern void I2C_Set_Stop_Condition(void);
 extern void I2C_Speed_Initial(uint8_t ucMode);
 //extern uint8_t I2C_Receive_Data_Polling(void);
 extern void I2C_Send_Data(uint8_t ucData);
 extern void I2C_Clear_Flag(void);
 extern uint16_t I2C_Read_Status(void); 
 extern uint8_t I2C_Receive_Data(void);
 //extern void I2C_Send_Data_Polling(uint8_t ucData);
 extern uint8_t I2C_Status_Polling(uint16_t usstauts);
 extern void I2C_Set_Restart_Condition(void);
 extern uint8_t I2C_MonitorMode_Ctrl(uint8_t ucI2CmatchAll, uint8_t ucI2Cscloen, uint8_t ucI2Cmmen);
 extern void I2C_AutoSend_Data(uint32_t uilength, uint8_t *ucdata_ptr);

#endif
