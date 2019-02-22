/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/04
* IC:			      SNC7312
* DESCRIPTION:	SPI Flash Controller functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		         2016/04/01	   SA2			
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/
#ifndef _SNC7312_SPIFC
#define _SNC7312_SPIFC
/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include "snc7312.h"

void SPIFC_Enable(void);
void SPIFC_Disable(void);
void SPIFC_Clock_Select(uint32_t clk);
void SPIFC_Deselect_Cycle(uint8_t uiDeselectCycle);
uint32_t SPIFC_Read_Factory_ID(void);
void SPIFC_Block_Erase(uint32_t Addr);
void SPIFC_Chip_Erase(void);
void SPIFC_Sector_Erase(uint32_t Addr);
uint8_t SPIFC_Erase_Data_Polling(void);
uint8_t SPIFC_Read_Status(void);
void SPIFC_Write_Status(uint8_t uiStatus);
void SPIFC_Read_DMA_Mode(uint8_t uiMode, uint32_t uiSPIAddr, uint32_t uiLength, uint32_t* p_uiWRAMAddr);
uint8_t SPIFC_Write_Data_Polling(void);
void SPIFC_Write_DMA_Mode(uint8_t uiMode, uint32_t uiSPIAddr, uint32_t uiLength, uint32_t* p_uiWRAMAddr);
void SPIFC_Disable_Quad_Mode(void);
void SPIFC_Enable_Quad_Mode(void);
void SPIFC_Power_Down(void);
void SPIFC_Wake_Up(void);
uint16_t SPIFC_Customer_RD_Mode(uint8_t Cmd, uint8_t WithAddr, uint32_t Addr, uint8_t length);
void SPIFC_Customer_WR_Mode(uint8_t Cmd,uint8_t WithAddr,uint32_t Addr,uint8_t length,uint16_t Data);

#endif

