#ifndef __12864_H__
#define __12864_H__

#include <stdio.h>
#include "SNC7312.h"
//#include "sn_i2c.h"


void Draw_BMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1,unsigned char BMP[]);
void OLED_Init(void);
void OLED_WrCmd(unsigned char cmd);
void OLED_WrDat(unsigned char IIC_Data);
void OLED_Fill(unsigned char bmp_dat);
void OLED_CLS(void);
void OLED_P16x16Ch(unsigned char x, unsigned char y, unsigned char N);

#endif
