#ifndef _SNC7300_Series_TFT_H_
#define _SNC7300_Series_TFT_H_

#include <stdio.h>
#include "SNC7312.h"

extern void TFT_Enable(void);
extern void TFT_Disable(void);
extern void TFT_DCLK_Polarity(uint8_t ui_mode);
extern void TFT_VS_Polarity(uint8_t ui_mode);
extern void TFT_HS_Polarity(uint8_t ui_mode);
extern void TFT_VS_Pulse_Width(uint8_t ui_value);
extern void TFT_HS_Pulse_Width(uint8_t ui_value);
extern void TFT_Display_Mode(uint8_t ui_mode);
extern void TFT_Odd_Line_Sequence(uint8_t ui_mode);
extern void TFT_Even_Line_Sequence(uint8_t ui_mode);
extern void TFT_DCLK_Speed(uint16_t ui_value);
extern void TFT_VS_BackPorch(uint16_t ui_value);
extern void TFT_VS_FrontPorch(uint16_t ui_value);
extern void TFT_HS_BackPorch(uint16_t ui_value);
extern void TFT_HS_FrontPorch(uint16_t ui_value);
extern void TFT_Dummy_RGB(uint8_t ui_mode);

#endif
