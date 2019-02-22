
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
extern SysStruct	sysinfo;
extern unsigned int date_time_scroll_cnt;
extern unsigned int systime_cnt;
extern unsigned int get_battery_time;
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
	date_time_scroll_cnt++;
	systime_cnt++;
	get_battery_time++;
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

extern unsigned int adcvalue[16];
extern unsigned char adc_cnt;

void ADC_ISR (void) interrupt 11
{
	char index;
	index = adc_cnt;//&0x07;
    clr_ADCF;                               // Clear ADC interrupt flag
	adcvalue[index] = ADCRH;
	adcvalue[index] = adcvalue[index]<<4;
	adcvalue[index] |= ADCRL&0x0F;
	adc_cnt++;
	if (adc_cnt >= 16)
	{
		clr_EADC;
	}
}

void initADC(void)
{
	unsigned char i;
	adc_cnt = 0;
	for(i=0;i<16;i++)
		adcvalue[i] = 0;
	PWM2_P10_OUTPUT_ENABLE;				
	Enable_ADC_AIN3;														
	PWM2_FALLINGEDGE_TRIG_ADC;	
	PWMPH = 0x07;																//Setting PWM value          
	PWMPL = 0xFF;
	PWM2H = 0x02;
	PWM2L = 0xFF;
	set_LOAD;																		// PWM run
	set_PWMRUN;
	// Setting ADC
	set_EADC;																		// Enable ADC interrupt (if use interrupt)
	EA = 1;	
	while(adc_cnt < 16);
	set_EADC;	
}

void main(void)
{
	Set_All_GPIO_Quasi_Mode;
	Timer0_Init();
	initADC();
	while(1)
	{
		main_loop();
	}
}