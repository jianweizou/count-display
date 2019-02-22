
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "OLED.h"
#include "count.h"
#include "dataflash.h"

#define TH0_INIT        (65536-6667)/256 //5.0ms@XTAL=12MHz, Period = (10.85/2) ms@XTAL=22.1184MHz
#define TL0_INIT        (65536-6667)%256
#define TH1_INIT        0xE0 //2.5ms@XTAL=12MHz, Period = (5.425/2) ms@XTAL=22.1184MHz
#define TL1_INIT        0x00

bit BIT_TMP;

extern unsigned char is_5ms_Flag;
extern unsigned char blinktime;
extern unsigned int powercnt;
/************************************************************************************************************
*    TIMER 0 interrupt subroutine
************************************************************************************************************/
void Timer0_ISR (void) interrupt 1          //interrupt address is 0x000B
{
    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
	is_5ms_Flag = 1;
	blinktime++;
	if (blinktime > (BLINK_H+BLINK_L))
		blinktime = 0;
	powercnt++;
}

void Timer0_Init(void)
{
	TMOD = 0XFF;
	TIMER0_MODE1_ENABLE;                        //Timer 0  mode configuration
    
	clr_T0M;
    
	TH0 = TH0_INIT;
	TL0 = TL0_INIT;
    
	set_ET0;                                    //enable Timer0 interrupt
	set_EA;                                     //enable interrupts
	
	set_TR0;                                    //Timer0 run
}
extern SysStruct	sysinfo;
void main(void)
{
	Set_All_GPIO_Quasi_Mode;
	Timer0_Init();
	while(1)
	{
		main_loop();
	}
}