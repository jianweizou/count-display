/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/04
* IC:			      SNC7312
* DESCRIPTION:	Timer functions.
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
#ifndef __SNC7300_Timer_H
#define __SNC7300_Timer_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include "snc7312.h"

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ M A C R O S ________________________________________________________*/

/*_____ D E C L A R A T I O N S ____________________________________________*/

void CT16B0_Init(void);
void CT16B0_IRQEnable(void);
uint16_t CT16B0_TC(void);
void CT16B0_Prescale(uint16_t usPre);
uint16_t CT16B0_PC(void);
uint8_t CT16B0_MREnable(uint8_t usNum, uint8_t usMode);
void CT16B0_MRValue(uint8_t usNum, uint16_t usValue);
void CT16B0_Enable(void);
void CT16B0_Disable(void);
uint8_t CT16B0_IRQFlag(void);
void CT16B0_IRQFlagClear(uint8_t usNum);

void CT16B1_Init(void);
void CT16B1_IRQEnable(void);
uint16_t CT16B1_TC(void);
void CT16B1_Prescale(uint16_t usPre);
uint16_t CT16B1_PC(void);
uint8_t CT16B1_MREnable(uint8_t usNum, uint8_t usMode);
void CT16B1_MRValue(uint8_t usNum, uint16_t usValue);
void CT16B1_Enable(void);
void CT16B1_Disable(void);
uint8_t CT16B1_IRQFlag(void);
void CT16B1_IRQFlagClear(uint8_t usNum);

void CT32B0_Init(void);
void CT32B0_IRQEnable(void);
uint32_t CT32B0_TC(void);
void CT32B0_Prescale(uint32_t usPre);
uint32_t CT32B0_PC(void);
uint8_t CT32B0_MREnable(uint8_t usNum, uint8_t usMode);
void CT32B0_MRValue(uint8_t usNum, uint32_t usValue);
void CT32B0_Enable(void);
void CT32B0_Disable(void);
uint8_t CT32B0_IRQFlag(void);
void CT32B0_IRQFlagClear(uint8_t usNum);

void CT32B1_Init(void);
void CT32B1_IRQEnable(void);
uint32_t CT32B1_TC(void);
void CT32B1_Prescale(uint32_t usPre);
uint32_t CT32B1_PC(void);
uint8_t CT32B1_MREnable(uint8_t usNum, uint8_t usMode);
void CT32B1_MRValue(uint8_t usNum, uint32_t usValue);
void CT32B1_Enable(void);
void CT32B1_Disable(void);
uint8_t CT32B1_IRQFlag(void);
void CT32B1_IRQFlagClear(uint8_t usNum);

#endif	/*__SNC7300_Timer_H*/
