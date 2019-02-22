/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/01
* AUTHOR:		    SA2
* IC:			      SNC7312
* DESCRIPTION:	CIS Controller functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		         2016/01/27	   SA2				
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



#ifndef _SNC7312_CIS_INC_H
#define _SNC7312_CIS_INC_H

 void CIS_Enable(void);
 void CIS_Disable(void);
 void CIS_Remove_Trans_Enable(void);
 void CIS_Remove_Trans_Disable(void);
 void CIS_Pixel_Format(uint8_t ucPFMT);
 void CIS_Clr_Line0_Full_Flag(void);
 void CIS_Clr_Line1_Full_Flag(void);
 void CIS_Clr_Line2_Full_Flag(void);
 void CIS_VSYNC_Edge_Falling(void);
 void CIS_VSYNC_Edge_Rising(void);
 void CIS_HREF_Edge_Falling(void);
 void CIS_HREF_Edge_Rising(void);
 void CIS_Data_Latch_PixelClk_Falling(void);
 void CIS_Data_Latch_PixelClk_Rising(void);
 void CIS_Clock_Select(uint8_t ucClk);
 void CIS_Col_N_Set(uint32_t uiCol_n);
 void CIS_Set_LineBuffer_Addr(uint8_t ucBuf_No,uint32_t uiAddr);
 void CIS_Scale_Disable(void);
 void CIS_Scale_Enable(void);
 void CIS_Scale_Setting(uint8_t ucL_sel, uint8_t ucL_skip, uint8_t ucP_sel, uint8_t ucP_skip);
 void CIS_Window_Enable(void);
 void CIS_Window_Setting(uint32_t uiVoffset, uint32_t uiHoffset);
 void CIS_Transfer_Enable(void);
 void CIS_Transfer_Setting(uint16_t usH_Size, uint16_t usV_Size);
 void CIS_Window_Disable(void);
 uint32_t CIS_Chk_Line0_Full_Flag(void);
 uint32_t CIS_Chk_Line1_Full_Flag(void);
 uint32_t CIS_Chk_Line2_Full_Flag(void);
 void CIS_Source_format(uint8_t SrcFmt);
 void CIS_L2B_Disable(void);
 void CIS_L2B_Enable( uint8_t BlockType, uint32_t SkipLine );



#endif //_SNC7312_CIS_INC_H
