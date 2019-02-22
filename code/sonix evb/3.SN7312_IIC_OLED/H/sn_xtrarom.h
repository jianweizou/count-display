/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2013/07
* AUTHOR:		    SA2
* IC:			      SNC7300
* DESCRIPTION:	GPIO functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		         2013/07/01	   SA2			
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

#ifndef _SNC7300_GPIO_XROM_H
#define _SNC7300_GPIO_XROM_H

extern void XROM_Init(void);
extern void XROM_Read_ID(char *buf);
extern char XROM_Read_Sector(u32 sector,char *buf);
extern char XROM_SD_Read_nByte(u32 StartAddr, char* pBuf, u32 Length);
extern char XROM_SD_Read_nByte_2(u32 StartAddr, char* pBuf, u32 Length);
#endif
