
#include <stdio.h>
#include "SNC7312.h"
//#include "sn_i2c.h"
#include "system_snc7312.h"

extern u8 font_CHN[];
extern u8 font1_0_9[];
extern u8 font2_0_9[];
extern u8 font_A_Z[];
extern u8 t0[];



typedef enum
{
	SAN,
	ZHONG,
	WEN,
	SHU,
	ZI,
	ZANG,
	GUI,
	LING,
	CHONG,
	ZHI,
	SHI,
	FOU,
	CHNEND,
}CHN;

