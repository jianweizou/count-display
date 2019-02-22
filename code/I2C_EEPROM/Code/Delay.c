/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2016 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2016
//***********************************************************************************************************

#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include <N76E003.H>
#include "count.h"


#define TH0_INIT        0xFC //5.0ms@XTAL=12MHz, Period = (10.85/2) ms@XTAL=22.1184MHz
#define TL0_INIT        0x0F
#define TH1_INIT        0xE0 //2.5ms@XTAL=12MHz, Period = (5.425/2) ms@XTAL=22.1184MHz
#define TL1_INIT        0x00

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
	TIMER0_MODE0_ENABLE;                        //Timer 0  mode configuration
    
	clr_T0M;
    
	TH0 = TH0_INIT;
	TL0 = TL0_INIT;
    
	set_ET0;                                    //enable Timer0 interrupt
	set_EA;                                     //enable interrupts
	
	set_TR0;                                    //Timer0 run
}


void Timer1_Delay10ms(unsigned long cnt)
{
    clr_T1M;																		//T1M=0, Timer1 Clock = Fsys/12
    TMOD |= 0x10;																//Timer1 is 16-bit mode
    set_TR1;																		//Start Timer1
    while (cnt != 0)
    {
        TL1 = LOBYTE(TIMER_DIV12_VALUE_10ms);		//Find  define in "Function_define.h" "TIMER VALUE"
        TH1 = HIBYTE(TIMER_DIV12_VALUE_10ms);
        while (TF1 != 1);												//Check Timer1 Time-Out Flag
        clr_TF1;
        cnt --;
    }
    clr_TR1;                               			//Stop Timer1
}