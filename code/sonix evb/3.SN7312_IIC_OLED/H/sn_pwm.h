/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/03
* IC:			      SNC7312
* DESCRIPTION:	GPIO functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		         2016/03/30	   SA2			
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
#include "SNC7312.h"

#ifndef _SNC7300_PWM_h
#define _SNC7300_PWM_h

void CT16B0_PWM1_Enable(uint32_t, uint16_t, uint8_t);
void CT16B1_PWM1_Enable(uint32_t, uint16_t, uint8_t);

void CT16B_PWM_Pin_Switch_Disable(uint32_t, uint16_t, uint8_t);
void CT16B_PWM_Pin_Switch_Enable(uint32_t, uint16_t, uint8_t);
void CT16B0_PWM0_Disable(uint32_t, uint16_t, uint8_t);
void CT16B0_PWM0_Enable(uint32_t, uint16_t, uint8_t);
void CT16B1_PWM0_Disable(uint32_t, uint16_t, uint8_t);
void CT16B1_PWM0_Enable(uint32_t, uint16_t, uint8_t);
void CT32B0_PWM0_Disable(uint32_t, uint16_t, uint8_t);
void CT32B0_PWM0_Enable(uint32_t, uint16_t, uint8_t);
void CT32B0_PWM1_Disable(uint32_t, uint16_t, uint8_t);
void CT32B0_PWM1_Enable(uint32_t, uint16_t, uint8_t);
void CT32B1_PWM0_Disable(uint32_t, uint16_t, uint8_t);
void CT32B1_PWM0_Enable(uint32_t, uint16_t, uint8_t);
void CT32B1_PWM1_Disable(uint32_t, uint16_t, uint8_t);
void CT32B1_PWM1_Enable(uint32_t, uint16_t, uint8_t);
#endif