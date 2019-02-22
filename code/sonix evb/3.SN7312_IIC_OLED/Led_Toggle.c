#include "sn_gpio.h"

extern uint32_t flag_1s;

void Led_toggle(uint16_t uIOData){
	SN_GPIO0->DATA = uIOData;
//	if(!GPIO1_Data_Bit_Read(0))
//		SN_GPIO1->DATA_b.DATA0 = 1;
//	else
//		SN_GPIO1->DATA_b.DATA0 = 0;
}