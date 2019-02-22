/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/04
* IC:			      SNC7312
* DESCRIPTION:	PPU Header.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		         2016/04/06	   SA2			
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


#ifndef _SNC7300_PPU_INC_H
#define _SNC7300_PPU_INC_H

/*PPU */
 void PPU_Disable(void);
 void PPU_Enable(void);
 void PPU_Backdrop_Color_Setting(uint8_t ucColor_R, uint8_t ucColor_G, uint8_t ucColor_B);
 void PPU_TableMove_Setting(uint32_t uiAHB_Addr, uint32_t uiVRAM_Addr, uint32_t uiDLength);
 void PPU_Brightness_Setting(uint8_t ucBREn, uint8_t ucBR_Lev, uint8_t ucBROut);
 void PPU_Brightness_Adjustment(uint8_t ucBRM);
 void PPU_Brightness_Adjustment_Region_Setting(uint8_t ucHStr, uint8_t ucHEnd, uint8_t ucVStr, uint8_t ucVEnd);
 void PPU_HBLK_Interrupt_Enable(uint8_t ucPolling);
 void PPU_HBLK_Interrupt_Disable(void);
 void PPU_VBLK_Interrupt_Disable(void);
 void PPU_VBLK_Interrupt_Enable(uint8_t ucPolling);
 void PPU_HBLK_Interrupt_ClearFlag(void);
 void PPU_VBLK_Interrupt_ClearFlag(void);
 uint8_t PPU_VBLK_Status(void);
 uint8_t PPU_HBLK_Status(void);
 void PPU_VRAM_Write(uint32_t uiAddr, uint16_t usData);
 uint16_t PPU_VRAM_Read(uint32_t uiAddr);
 void PPU_480x272_Initial(uint8_t uiEnable);
 
/*Text1*/
 void PPU_Text1_Disable(void);
 void PPU_Text1_Enable(void);
 void PPU_Text1_Position_Setting(uint16_t usX_Offset, uint16_t usY_Offset);
 void PPU_Text1_CharacterMode_Initial(uint8_t ucChar_Size, uint8_t ucColor, uint8_t ucVScrn_En);
 void PPU_Text1_CharacterMode_Attribute_Setting(uint8_t ucAttrInReg, uint8_t ucHVFlip, uint8_t ucPalette_Sel);
 void PPU_Text1_NumberPtr_Setting(uint32_t uiNumPtr_Addr);
 void PPU_Text1_AttributePtr_Setting(uint32_t uiAttrPtr_Addr);
 void PPU_Text1_PatternPtr_Setting(uint32_t uiPatPtr_Addr);
 void PPU_Text1_Vertical_Display_Region_Initial(uint32_t uiDisplay_Region);
 void PPU_Text1_BitmapMode_Initial(uint8_t ucColor, uint8_t ucHighColor);
 void PPU_Text1_DetphLevel_Setting(uint8_t ucDepth);
 void PPU_Text1_WallPapaer_Effect(uint8_t ucWAPEn);
 void PPU_Text1_Vertiacl_Compression_Effect(uint8_t ucVCMPEn, uint8_t ucScale, uint8_t ucOffset);
 void PPU_Text1_Blending_Effect(uint8_t ucBLDEn, uint8_t ucBLD_Lev);
 void PPU_Text1_VRAM_Initial(uint8_t ucClrMode, uint32_t uiTemp_Addr);

/*Text2*/
 void PPU_Text2_Disable(void);
 void PPU_Text2_Enable(void);
 void PPU_Text2_Position_Setting(uint16_t usX_Offset, uint16_t usY_Offset);
 void PPU_Text2_CharacterMode_Initial(uint8_t ucChar_Size, uint8_t ucColor, uint8_t ucVScrn_En);
 void PPU_Text2_CharacterMode_Attribute_Setting(uint8_t ucAttrInReg, uint8_t ucHVFlip, uint8_t ucPalette_Sel);
 void PPU_Text2_NumberPtr_Setting(uint32_t uiNumPtr_Addr);
 void PPU_Text2_AttributePtr_Setting(uint32_t uiAttrPtr_Addr);
 void PPU_Text2_PatternPtr_Setting(uint32_t uiPatPtr_Addr);
 void PPU_Text2_Vertical_Display_Region_Initial(uint32_t uiDisplay_Region);
 void PPU_Text2_BitmapMode_Initial(uint8_t ucColor, uint8_t ucHighColor);
 void PPU_Text2_DetphLevel_Setting(uint8_t ucDepth);
 void PPU_Text2_WallPapaer_Effect(uint8_t ucWAPEn);
 void PPU_Text2_Vertiacl_Compression_Effect(uint8_t ucVCMPEn, uint8_t ucScale, uint8_t ucOffset);
 void PPU_Text2_Blending_Effect(uint8_t ucBLDEn, uint8_t ucBLD_Lev);
 void PPU_Text2_VRAM_Initial(uint8_t ucClrMode, uint32_t uiTemp_Addr);


/*Text3*/
 void PPU_Text3_Disable(void);
 void PPU_Text3_Enable(void);
 void PPU_Text3_BufferAddress_Setting(uint8_t ucBuf_No, uint32_t uiBuf_Addr);
void PPU_Text3_Scale_Setting(uint8_t ucEnscale, uint8_t ucScl, uint32_t uiFrame_StrAddr, uint16_t SrcWidth, uint16_t SrcHight);

/*Sprite*/
 void PPU_Sprite_Disable(void);
 void PPU_Sprite_Enable(void);
 void PPU_Sprite_PatternPtr_Setting(uint32_t uiPatPtr_Addr);
 void PPU_Sprite_Position(uint8_t ucSprNo, uint16_t ucXP, uint16_t ucYP);
 void PPU_Sprite_HVFlip(uint8_t ucSprNo, uint8_t ucHVFlip);
 void PPU_Sprite_Depth(uint8_t ucSprNo, uint16_t usDepth);
 void PPU_Sprite_Palette_Bank(uint8_t ucSprNo, uint16_t usPalBk);
 void PPU_Sprite_ExSize(uint8_t ucSprNo, uint8_t ucExsize);
 void PPU_Sprite_Single_Disable(uint8_t ucSprNo);
 void PPU_Sprite_Single_Enable(uint8_t ucSprNo);
 void PPU_Sprite_Blending_Disable(uint8_t ucSprNo);
 void PPU_Sprite_Blending_Enable(uint8_t ucSprNo);
 void PPU_Sprite_VRAM_Initial(uint8_t ucClrMode, uint32_t uiTemp_Addr);
 void PPU_Sprite_ColorMode(uint8_t ucSprNo, uint8_t ucColor);
 void PPU_Sprite_Rotat_Scale(int32_t Ori_V_Size, int32_t Desired_V_Size, int32_t Ori_H_Size, int32_t Desired_H_Size, uint32_t Angle, uint32_t ExtSize, uint32_t index);
 
#endif
