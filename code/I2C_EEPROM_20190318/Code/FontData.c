#include "fontdata.h"

/*
阴码-逆项-列行式
*/
/* 16*16*/
/*
三中文数字藏归零重置是否
*/
code unsigned char font_CHN_SAN[]=
{

0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
0x40,0x40,0x41,0x41,0x41,0x41,0x41,0x41,
0x41,0x41,0x41,0x41,0x41,0x40,0x40,0x00,//"?",0
};
code unsigned char font_CHN_ZHONG[]=
{
0x00,0x00,0xF0,0x10,0x10,0x10,0x10,0xFF,
0x10,0x10,0x10,0x10,0xF0,0x00,0x00,0x00,
0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0xFF,
0x04,0x04,0x04,0x04,0x0F,0x00,0x00,0x00,//"?",1
};
code unsigned char font_CHN_WEN[]=
{
0x08,0x08,0x08,0x38,0xC8,0x08,0x09,0x0E,
0x08,0x08,0xC8,0x38,0x08,0x08,0x08,0x00,
0x80,0x80,0x40,0x40,0x20,0x11,0x0A,0x04,
0x0A,0x11,0x20,0x40,0x40,0x80,0x80,0x00,//"?",2
};
code unsigned char font_CHN_SHU[]=
{
0x90,0x52,0x34,0x10,0xFF,0x10,0x34,0x52,
0x80,0x70,0x8F,0x08,0x08,0xF8,0x08,0x00,
0x82,0x9A,0x56,0x63,0x22,0x52,0x8E,0x00,
0x80,0x40,0x33,0x0C,0x33,0x40,0x80,0x00,//"?",3
};
code unsigned char font_CHN_ZI[]=
{
0x10,0x0C,0x04,0x24,0x24,0x24,0x25,0x26,
0xA4,0x64,0x24,0x04,0x04,0x14,0x0C,0x00,
0x02,0x02,0x02,0x02,0x02,0x42,0x82,0x7F,
0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00,//"?",4
};
code unsigned char font_CHN_ZANG[]=
{
0x02,0xE2,0x82,0xF2,0x12,0xD7,0x52,0xD2,
0x52,0x17,0xFA,0x12,0x16,0x9A,0x12,0x00,
0x12,0x8E,0x62,0x1F,0x00,0x3F,0x25,0x3D,
0xA7,0x40,0x27,0x18,0x26,0x41,0xF0,0x00,//"?",5
};
code unsigned char font_CHN_GUI[]=
{
0x00,0xFC,0x00,0x00,0xFF,0x00,0x04,0x84,
0x84,0x84,0x84,0x84,0x84,0xFC,0x00,0x00,
0x00,0x87,0x40,0x30,0x0F,0x00,0x20,0x20,
0x20,0x20,0x20,0x20,0x20,0x7F,0x00,0x00,//"?",6
};
code unsigned char font_CHN_LING[]=
{
0x10,0x0C,0x05,0x55,0x55,0x55,0x85,0x7F,
0x85,0x55,0x55,0x55,0x05,0x14,0x0C,0x00,
0x04,0x04,0x02,0x0A,0x09,0x29,0x2A,0x4C,
0x48,0xA9,0x19,0x02,0x02,0x04,0x04,0x00,//"?",7
};
code unsigned char font_CHN_CHONG[]=
{
0x10,0x10,0x14,0xD4,0x54,0x54,0x54,0xFC,
0x52,0x52,0x52,0xD3,0x12,0x10,0x10,0x00,
0x40,0x40,0x50,0x57,0x55,0x55,0x55,0x7F,
0x55,0x55,0x55,0x57,0x50,0x40,0x40,0x00,//"?",8
};
code unsigned char font_CHN_ZHI[]=
{
0x00,0x17,0x15,0xD5,0x55,0x57,0x55,0x7D,
0x55,0x57,0x55,0xD5,0x15,0x17,0x00,0x00,
0x40,0x40,0x40,0x7F,0x55,0x55,0x55,0x55,
0x55,0x55,0x55,0x7F,0x40,0x40,0x40,0x00,//"?",9
};
code unsigned char font_CHN_SHI[]=
{
0x00,0x00,0x00,0x7F,0x49,0x49,0x49,0x49,
0x49,0x49,0x49,0x7F,0x00,0x00,0x00,0x00,
0x81,0x41,0x21,0x1D,0x21,0x41,0x81,0xFF,
0x89,0x89,0x89,0x89,0x89,0x81,0x81,0x00,
};
code unsigned char font_CHN_FOU[]=
{
0x00,0x02,0x82,0x82,0x42,0x22,0x12,0xFA,
0x06,0x22,0x22,0x42,0x42,0x82,0x00,0x00,
0x01,0x01,0x00,0xFC,0x44,0x44,0x44,0x45,
0x44,0x44,0x44,0xFC,0x00,0x00,0x01,0x00,	
};

/*  8*16 */
code unsigned char font0[]=
{
0x00,0xF8,0x04,0x02,0x02,0x04,0xF8,0x00,
0x00,0x03,0x04,0x08,0x08,0x04,0x03,0x00,
};
code unsigned char font1[]=
{
0x00,0x00,0x04,0x04,0xFE,0x00,0x00,0x00,
0x00,0x00,0x08,0x08,0x0F,0x08,0x08,0x00,
};
code unsigned char font2[]=
{
0x00,0x1C,0x02,0x02,0x82,0x42,0x3C,0x00,
0x00,0x0C,0x0A,0x09,0x08,0x08,0x0C,0x00,
};
code unsigned char font3[]=
{
0x00,0x0C,0x02,0x42,0x42,0xA2,0x1C,0x00,
0x00,0x06,0x08,0x08,0x08,0x08,0x07,0x00,
};
code unsigned char font4[]=
{
0x00,0x80,0x60,0x10,0x0C,0xFE,0x00,0x00,
0x00,0x01,0x01,0x09,0x09,0x0F,0x09,0x09,
};
code unsigned char font5[]=
{
0x00,0x7E,0x22,0x22,0x22,0x42,0x82,0x00,
0x00,0x06,0x08,0x08,0x08,0x04,0x03,0x00,
};
code unsigned char font6[]=
{
0x00,0xF8,0x44,0x22,0x22,0x24,0xC0,0x00,
0x00,0x03,0x04,0x08,0x08,0x08,0x07,0x00,
};
code unsigned char font7[]=
{
0x00,0x06,0x02,0x82,0x62,0x1A,0x06,0x00,
0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,
};
code unsigned char font8[]=
{
0x00,0x1C,0xA2,0x42,0x42,0xA2,0x1C,0x00,
0x00,0x07,0x08,0x08,0x08,0x08,0x07,0x00,
};
code unsigned char font9[]=
{
0x00,0x7C,0x82,0x82,0x82,0x44,0xF8,0x00,
0x00,0x00,0x04,0x08,0x08,0x04,0x03,0x00,
};
//code unsigned char font0[]=
//{	
//0x00,0x00,0x00,0xC0,0x30,0x0E,0x01,0x00,
//0x00,0x18,0x06,0x01,0x00,0x00,0x00,0x00,
//};
/* 8*16*/
code unsigned char font_A[]=
{
0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,
0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20,//"A",0
};
code unsigned char font_B[]=
{
0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,
0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00,//"B",1
};
code unsigned char font_C[]=
{
0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,
0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,//"C",2
};
code unsigned char font_D[]=
{
0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,
0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,//"D",3
};
code unsigned char font_E[]=
{
0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,
0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00,//"E",4
};
code unsigned char font_F[]=
{
0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,
0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,//"F",5
};
code unsigned char font_G[]=
{
0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,
0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00,//"G",6
};
code unsigned char font_H[]=
{
0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,
0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20,//"H",7
};
code unsigned char font_I[]=
{
0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,
0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//"I",8
};
code unsigned char font_J[]=
{
0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,
0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00,//"J",9
};
code unsigned char font_K[]=
{
0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,
0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00,//"K",10
};
code unsigned char font_L[]=
{
0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,
0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,//"L",11
};
code unsigned char font_M[]=
{
0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,
0x20,0x3F,0x01,0x3E,0x01,0x3F,0x20,0x00,//"M",12
};
code unsigned char font_N[]=
{
0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,
0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00,//"N",13
};
code unsigned char font_O[]=
{
0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,
0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,//"O",14
};
code unsigned char font_P[]=
{
0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,
0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00,//"P",15
};
code unsigned char font_Q[]=
{
0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,
0x0F,0x10,0x28,0x28,0x30,0x50,0x4F,0x00,//"Q",16
};
code unsigned char font_R[]=
{
0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,
0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20,//"R",17
};
code unsigned char font_S[]=
{
0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,
0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00,//"S",18
};
code unsigned char font_T[]=
{
0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,
0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//"T",19
};
code unsigned char font_U[]=
{
0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,
0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//"U",20
};
code unsigned char font_V[]=
{
0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,
0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00,//"V",21
};
code unsigned char font_W[]=
{
0x08,0xF8,0x00,0xF8,0x00,0xF8,0x08,0x00,
0x00,0x03,0x3E,0x01,0x3E,0x03,0x00,0x00,//"W",22
};
code unsigned char font_X[]=
{
0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,
0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20,//"X",23
};
code unsigned char font_Y[]=
{
0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,
0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//"Y",24
};
code unsigned char font_Z[]=
{
0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,
0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00,//"Z",25
};

code unsigned char TIB_0[]=
{
0x00,0x00,0xC0,0x20,0x10,0x18,0x18,0x30,0x60,0xC0,0x00,0x00,
0x00,0x00,0x03,0x03,0x06,0x06,0x06,0x06,0x02,0x01,0x00,0x00,//0
};
code unsigned char TIB_1[]=
{
0x00,0x00,0x38,0x1C,0x02,0x03,0x83,0xFF,0x3F,0x01,0x00,0x00,
0x00,0x00,0x80,0x40,0x20,0x1C,0x0F,0x03,0x00,0x00,0x00,0x00,//1
};
code unsigned char TIB_2[]=
{
0x20,0x18,0x1C,0x06,0x87,0x87,0xC6,0x3C,0x1E,0x01,0x00,0x00,
0x00,0x00,0x02,0x01,0x01,0x01,0x03,0x07,0x0E,0x18,0x60,0x80,//2
};
code unsigned char TIB_3[]=
{
0x10,0x08,0x0E,0x06,0x42,0x23,0x23,0xB2,0xEF,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x04,0x02,0x03,0x03,0x06,0x1C,0x78,0x00,//3
};
code unsigned char TIB_4[]=
{
0x40,0xE0,0x98,0x0C,0x1E,0x38,0x70,0x60,0xE0,0xC0,0x80,0x80,
0x00,0x00,0x01,0x03,0x02,0x06,0x0C,0x0C,0x08,0x18,0x10,0x10,//4
};
code unsigned char TIB_5[]=
{
0x00,0x7C,0xFE,0xC0,0x60,0x30,0xFC,0xFE,0x03,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x3C,0x40,0x80,//5
};
code unsigned char TIB_6[]=
{
0x00,0xF0,0xFC,0x0E,0x02,0x00,0x00,0x00,0x00,0x80,0xC0,0x40,
0x00,0x03,0x0F,0x30,0x40,0x84,0x8C,0xFE,0x73,0x01,0x00,0x00,//6
};
code unsigned char TIB_7[]=
{
0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0x80,0x06,0x1F,0x1C,0xF0,
0x00,0x08,0x0F,0xC3,0x60,0x20,0x3F,0x27,0x10,0x10,0x0C,0x03,//7
};
code unsigned char TIB_8[]=
{
0x00,0x20,0x20,0x30,0x30,0x30,0x78,0xEE,0xC3,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x38,0xC0,//8
};
code unsigned char TIB_9[]=
{
0x00,0x00,0x00,0xE0,0x70,0x0C,0x06,0x72,0xDE,0x8C,0x00,0x00,
0x00,0x00,0x3F,0xCF,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,//9
};

code unsigned char chargeicon_0[]=
{
0xFF,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0xF8,0xF8,0x00,0x00,
0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0x1F,0x1F,0x00,0x00,
};
code unsigned char chargeicon_1[]=
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0xF8,0xF8,0x00,0x00,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0x1F,0x1F,0x00,0x00,
};
code unsigned char chargeicon_2[]=
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0xF8,0xF8,0x00,0x00,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0x1F,0x1F,0x00,0x00,
};
code unsigned char chargeicon_3[]=
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0xF8,0xF8,0x00,0x00,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0x1F,0x1F,0x00,0x00,
};
code unsigned char chargeicon_4[]=
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0xF8,0x00,0x00,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x1F,0x00,0x00,	
};

code unsigned char baticon_0[]=
{
0x00,0x00,0xF8,0xF8,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x0F,0x0F,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0F,0x07,0x03,0x00,
};
code unsigned char baticon_1[]=
{
0x00,0x00,0xF8,0xF8,0xF8,0xF8,0x18,0x18,0x18,0x18,0x18,0x18,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0F,0x07,0x03,0x00,
};
code unsigned char baticon_2[]=
{
0x00,0x00,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0x18,0x18,0x18,0x18,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0C,0x0C,0x0C,0x0C,0x0F,0x07,0x03,0x00,
};
code unsigned char baticon_3[]=
{
0x00,0x00,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0x18,0x18,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0C,0x0C,0x0F,0x07,0x03,0x00,
};
code unsigned char baticon_4[]=
{
0x00,0x00,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x07,0x03,0x00,
};

