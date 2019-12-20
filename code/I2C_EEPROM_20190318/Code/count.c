#include "N76E003.h"
#include "SFR_Macro.h"
#include "count.h"
#include "fontdata.h"
#include "Function_define.h"
#include "OLED.h"
#include "dataflash.h"
#include "ds1302.h"
extern void Timer0_Init(void);
extern void Timer1_Delay10ms(unsigned long cnt);
extern void Erase_LDROM(unsigned int datasize,unsigned int dataaddr);
#define POWER_WAKEUP	1
#if POWER_WAKEUP
#define KEYINPUTMODE 	P17_Input_Mode;P30_Input_Mode;P04_Input_Mode
#else
#define KEYINPUTMODE 	P17_Input_Mode
#endif
#define GETKEY		P17

unsigned char stage_loopcnt = 0;

SysStruct	sysinfo;
KEYTYPE keytype;
unsigned char curKey,preKey;
unsigned char debounce;
unsigned char islongpress;
unsigned char is_5ms_Flag;
unsigned char blinktime;
unsigned int powercnt;





#define TH0_INIT        (65536-6667)/256 //5.0ms@XTAL=12MHz, Period = (10.85/2) ms@XTAL=22.1184MHz
#define TL0_INIT        (65536-6667)%256
#define TH1_INIT        0xE0 //2.5ms@XTAL=12MHz, Period = (5.425/2) ms@XTAL=22.1184MHz
#define TL1_INIT        0x00

bit BIT_TMP;

extern unsigned char is_5ms_Flag;
extern unsigned char blinktime;
extern unsigned int powercnt;
extern SysStruct	sysinfo;
extern unsigned char get_battery_time;
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

#define UART_TEST	1

#if UART_TEST

/*******************************/
typedef unsigned char         UINT8;
typedef unsigned int          UINT16;
typedef unsigned long         UINT32;

typedef unsigned char         uint8_t;
typedef unsigned int          uint16_t;
typedef unsigned long         uint32_t;
/*uart1*/
void InitialUART1_Timer3(UINT32 u32Baudrate) //use timer3 as Baudrate generator
{
		P02_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
		P16_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
	
	  SCON_1 = 0x50;   	//UART1 Mode1,REN_1=1,TI_1=1
    T3CON = 0x08;   	//T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1), UART1 in MODE 1
		clr_BRCK;
	
#ifdef FOSC_160000
		RH3    = HIBYTE(65536 - (1000000/u32Baudrate)-1);  		/*16 MHz */
		RL3    = LOBYTE(65536 - (1000000/u32Baudrate)-1);			/*16 MHz */
#endif
#ifdef FOSC_166000
		RH3    = HIBYTE(65536 - (1037500/u32Baudrate));  			/*16.6 MHz */
		RL3    = LOBYTE(65536 - (1037500/u32Baudrate));				/*16.6 MHz */
#endif
    set_TR3;         //Trigger Timer3
}
UINT8 Receive_Data_From_UART1(void)
{
    UINT8 c;
    
    while (!RI_1);
    c = SBUF_1;
    RI_1 = 0;
    return (c);
}

void Send_Data_To_UART1 (UINT8 c)
{
    TI_1 = 0;
    SBUF_1 = c;
    while(TI_1==0);
}
char putchar (char c)
{
		while (!TI_1);  /* wait until transmitter ready */
		TI_1 = 0;
		SBUF_1 = c;      /* output character */
		return (c);
}

void Timer1_Delay100us(unsigned long cnt)
{
    clr_T1M;																		//T1M=0, Timer1 Clock = Fsys/12
    TMOD |= 0x10;																//Timer1 is 16-bit mode
    set_TR1;																		//Start Timer1
    while (cnt != 0)
    {
        TL1 = LOBYTE(TIMER_DIV12_VALUE_100us);		//Find  define in "Function_define.h" "TIMER VALUE"
        TH1 = HIBYTE(TIMER_DIV12_VALUE_100us);
        while (TF1 != 1);												//Check Timer1 Time-Out Flag
        clr_TF1;
        cnt --;
    }
    clr_TR1;                               			//Stop Timer1
}
#endif

#if POWER_WAKEUP
unsigned char power_debounce;
bit  is_enter_charging;
unsigned char las_stage;
#endif
#define BAT_LEVEL_0	3500
#define BAT_LEVEL_1	3700
#define BAT_LEVEL_2	3900

unsigned char bat_change_cnt=0;
unsigned char batlevel=0xFF;
unsigned char bat_charging_level;
bit isdisplaybaticon = 0;
extern bit BIT_TMP;

unsigned char ischangebatlevel_cnt = 0;
unsigned char get_battery_time = 0;

void KeyInit(void)
{
	curKey = 0;
	preKey = 1;
	debounce = 0;
	islongpress = 0;
	keytype = 0;
	KEYINPUTMODE;
	
	//
	#if POWER_WAKEUP
	power_debounce = 0;
	is_enter_charging = 0;
	#endif
}

void KeyScan(void)
{
	if (is_5ms_Flag)
	{
		is_5ms_Flag = 0;
		curKey = GETKEY;
		if (curKey != preKey)
		{
			preKey = curKey;
			if ((islongpress == 0)&&(debounce > 10))
			{
				keytype = SHORTKEY;
			}
			debounce = 0;
			islongpress = 0;
			
			powercnt = 0;
		}
		else if(curKey == 0)
		{
			debounce++;
			if (debounce >= 200)
			{
				debounce = 0;
				islongpress++;
				if (islongpress >= 10)
				{
					keytype = LONGKEY_12S;
				}
				else if (islongpress >= 5)
				{
					keytype = LONGKEY_5S;
				}
				else if (islongpress >= 2)
				{
					keytype = LONGKEY_2S;
				}
			}
			powercnt = 0;
		}
		#if POWER_WAKEUP
		//5v power check
		if (P30 == 0)
		{
			power_debounce = 0;
			if (is_enter_charging == 1)
			{
				is_enter_charging = 0;
				sysinfo.sysloop = las_stage;
				sysinfo.isneedinitstage = 1;
				OLED_CLS_Windows(16,1,48,3);
			}
		}
		else
		{
			powercnt = 0;
			power_debounce++;
			if (power_debounce > 10)
			{
				//enter power charging
				power_debounce = 10;
				if (is_enter_charging == 0)
				{
					is_enter_charging = 1;
					las_stage = sysinfo.sysloop;
					sysinfo.sysloop = SYS_CHARGE;
					sysinfo.isneedinitstage = 1;
				}
			}
		}
		#endif
	}
}

void display_Language_chinese(unsigned char isdisplay,unsigned char inverse)
{
	if (isdisplay == 1)
	{
		Draw_BMP(16,2,16+16,4,(unsigned char *)font_CHN_ZHONG,inverse);
		Draw_BMP(32,2,32+16,4,(unsigned char *)font_CHN_WEN,inverse);
	}
	else
	{
		OLED_CLS_Windows(16,2,48,4);
	}
}
void display_Language_english(unsigned char isdisplay,unsigned char inverse)
{
	if (isdisplay == 1)
	{
		Draw_BMP(4,0,12,2,(unsigned char *)font_E,inverse);
		Draw_BMP(12,0,20,2,(unsigned char *)font_N,inverse);
		Draw_BMP(20,0,28,2,(unsigned char *)font_G,inverse);
		Draw_BMP(28,0,36,2,(unsigned char *)font_L,inverse);
		Draw_BMP(36,0,44,2,(unsigned char *)font_I,inverse);
		Draw_BMP(44,0,52,2,(unsigned char *)font_S,inverse);
		Draw_BMP(52,0,60,2,(unsigned char *)font_H,inverse);
	}
	else
	{
		OLED_CLS_Windows(4,0,60,2);
	}
}
void Select_Language(void)
{
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		//init 
		OLED_CLS_Windows(12,1,52,3);
		display_Language_chinese(1,0);
		display_Language_english(1,1);		
		stage_loopcnt = ENGLISH;
		while(GETKEY == 0);
	}
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == CHINESE)
			{
				display_Language_chinese(1,0);
				display_Language_english(1,1);	
				stage_loopcnt = ENGLISH;
			}
			else
			{
				display_Language_chinese(1,1);
				display_Language_english(1,0);	
				stage_loopcnt = CHINESE;	
			}
			sysinfo.language = stage_loopcnt;
		}
		else if (keytype >= LONGKEY_2S)
		{
			sysinfo.language = stage_loopcnt;
			sysinfo.sysloop = SELECT_NUMTYPE;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
			display_Language_english(0,0);
			display_Language_chinese(0,0);
		}
		keytype = NULLKEY;
	}
}


unsigned int getdiv(unsigned long x,unsigned long y)
{
	unsigned int div = 0;
	while(x >= y)
	{
		div++;
		x = x - y;
	}
	return div;
}
unsigned int getremainder(unsigned long x,unsigned long y)
{
	while(x >= y)
	{
		x = x - y;
	}
	return x;
}

void display_cnt_stage_arabnum(unsigned char isdisplay,unsigned char inverse)
{
//	char * nor = "NORMAL";
//	char i;
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
//			for (i=0;i<6;i++)
//			{
//				Draw_BMP(8 + i*8,0,8+8 + i*8,2,font_A_Z + (nor[i] - 'A')*16);
//			}
			Draw_BMP(8,0,16,2,(unsigned char *)font_N,inverse);
			Draw_BMP(16,0,24,2,(unsigned char *)font_O,inverse);
			Draw_BMP(24,0,32,2,(unsigned char *)font_R,inverse);
			Draw_BMP(32,0,40,2,(unsigned char *)font_M,inverse);
			Draw_BMP(40,0,48,2,(unsigned char *)font_A,inverse);
			Draw_BMP(48,0,56,2,(unsigned char *)font_L,inverse);
		}
		else
		{
			OLED_CLS_Windows(8,0,56,2);
		}		
	}
	else
	{
		if (isdisplay == 1)
		{
			Draw_BMP(16,0,16+16,2,(unsigned char *)font_CHN_SHU,inverse);
			Draw_BMP(32,0,32+16,2,(unsigned char *)font_CHN_ZI,inverse);
		}
		else
		{
			OLED_CLS_Windows(16,0,48,2);
		}
	}
}
void display_cnt_stage_tibnum(unsigned char isdisplay,unsigned char inverse)
{	
//	char * nor = "TIBETAN";
//	char i;
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
//			for (i=0;i<7;i++)
//			{
//				Draw_BMP(4+ i*8,2,8+4+ i*8,4,font_A_Z + (nor[i] - 'A')*16);
//			}
			Draw_BMP(4,2,12,4,(unsigned char *)font_T,inverse);
			Draw_BMP(12,2,20,4,(unsigned char *)font_I,inverse);
			Draw_BMP(20,2,28,4,(unsigned char *)font_B,inverse);
			Draw_BMP(28,2,36,4,(unsigned char *)font_E,inverse);
			Draw_BMP(36,2,44,4,(unsigned char *)font_T,inverse);
			Draw_BMP(44,2,52,4,(unsigned char *)font_A,inverse);
			Draw_BMP(52,2,60,4,(unsigned char *)font_N,inverse);
		}
		else
		{
			OLED_CLS_Windows(4,2,60,4);
		}		
	}
	else
	{
		if (isdisplay == 1)
		{
			Draw_BMP(0,2,0+16,4,(unsigned char *)font_CHN_ZANG,inverse);
			Draw_BMP(16,2,16+16,4,(unsigned char *)font_CHN_WEN,inverse);		
			Draw_BMP(32,2,16+32,4,(unsigned char *)font_CHN_SHU,inverse);
			Draw_BMP(48,2,48+16,4,(unsigned char *)font_CHN_ZI,inverse);
		}
		else
		{
			OLED_CLS_Windows(0,2,64,4);
		}
	}
}
void Select_NumType(void)
{
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		display_cnt_stage_arabnum(1,1);
		display_cnt_stage_tibnum(1,0);
		stage_loopcnt = ARABNUM;
		while(GETKEY == 0);
	}	
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == TIBENUM)
			{
				display_cnt_stage_arabnum(1,1);
				display_cnt_stage_tibnum(1,0);
				stage_loopcnt = ARABNUM;
			}
			else
			{
				display_cnt_stage_arabnum(1,0);
				display_cnt_stage_tibnum(1,1);
				stage_loopcnt = TIBENUM;
			}
			sysinfo.numtype = stage_loopcnt;
		}
		else if (keytype >= LONGKEY_2S)
		{
			sysinfo.sysloop = CNT_STAGE;
			sysinfo.numtype = stage_loopcnt;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
			display_cnt_stage_arabnum(0,0);
			display_cnt_stage_tibnum(0,0);			
		}
		keytype = NULLKEY;
	}
}


void display_ARA(unsigned char start,unsigned char startline,unsigned char end,unsigned char endline, unsigned char index,unsigned char inverse)
{
	if (index == 0)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font0,inverse);
	}
	else if (index == 1)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font1,inverse);
	}
	else if (index == 2)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font2,inverse);
	}
	else if (index == 3)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font3,inverse);
	}
	else if (index == 4)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font4,inverse);
	}
	else if (index == 5)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font5,inverse);
	}
	else if (index == 6)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font6,inverse);
	}
	else if (index == 7)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font7,inverse);
	}
	else if (index == 8)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font8,inverse);
	}
	else if (index == 9)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)font9,inverse);
	}
}

void display_TIB(unsigned char start,unsigned char startline,unsigned char end,unsigned char endline, unsigned char index,unsigned char inverse)
{
	if (index == 0)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_0,inverse);
	}
	else if (index == 1)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_1,inverse);
	}
	else if (index == 2)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_2,inverse);
	}
	else if (index == 3)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_3,inverse);
	}
	else if (index == 4)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_4,inverse);
	}
	else if (index == 5)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_5,inverse);
	}
	else if (index == 6)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_6,inverse);
	}
	else if (index == 7)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_7,inverse);
	}
	else if (index == 8)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_8,inverse);
	}
	else if (index == 9)
	{
		Draw_BMP(start,startline,end,endline,(unsigned char*)TIB_9,inverse);
	}
}

void display_cnt_stage_cnt(unsigned long cnt,unsigned char isdisplay)
{
	
	unsigned char i;
	unsigned long temp;
	unsigned char nextdisplay=0; 
	unsigned char start_index=0;
	if (isdisplay == 0)
	{
		OLED_CLS_Windows(0,2,64,4);
		return;
	}
	temp = cnt;
	if (sysinfo.numtype == ARABNUM)
	{
		#define CNT_START_ARABNUM	0
		#define ARABNUM_SIZE	16
		start_index = CNT_START_ARABNUM;
		
		i = getdiv(temp,1000);
		temp = getremainder(temp,1000);
		if ((nextdisplay == 1)||(i != 0))
		{
			nextdisplay = 1;
			display_ARA(start_index,1,start_index+ARABNUM_SIZE,4,i,0);
			start_index+=ARABNUM_SIZE;
		}
		else
		{
			start_index+=ARABNUM_SIZE>>1;
		}
		
		i = getdiv(temp,100);
		temp = getremainder(temp,100);
		if ((nextdisplay == 1)||(i != 0))
		{
			nextdisplay = 1;
			display_ARA(start_index,1,start_index+ARABNUM_SIZE,4,i,0);
			start_index+=ARABNUM_SIZE;
		}
		else
		{
			start_index+=ARABNUM_SIZE>>1;
		}
		
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		if ((nextdisplay == 1)||(i != 0))
		{
			nextdisplay = 1;
			display_ARA(start_index,1,start_index+ARABNUM_SIZE,4,i,0);
			start_index+=ARABNUM_SIZE;
		}
		else
		{
			start_index+=ARABNUM_SIZE>>1;
		}
		
		i = temp;
		display_ARA(start_index,1,start_index+ARABNUM_SIZE,4,i,0);
	}
	else
	{
		#define CNT_START_TIBENUM	0
		#define TIBENUM_SIZE	16
		start_index = CNT_START_TIBENUM;
		
		i = getdiv(temp,1000);
		temp = getremainder(temp,1000);
		if ((nextdisplay == 1)||(i != 0))
		{
			display_TIB(start_index,1,start_index+TIBENUM_SIZE,4,i,0);
			nextdisplay = 1;
			start_index+=TIBENUM_SIZE;
		}
		else
			start_index+=TIBENUM_SIZE>>1;
		
		i = getdiv(temp,100);
		temp = getremainder(temp,100);
		if ((nextdisplay == 1)||(i != 0))
		{
			display_TIB(start_index,1,start_index+TIBENUM_SIZE,4,i,0);
			nextdisplay = 1;
			start_index+=TIBENUM_SIZE;
		}
		else
			start_index+=TIBENUM_SIZE>>1;
		
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		if ((nextdisplay == 1)||(i != 0))
		{
			display_TIB(start_index,1,start_index+TIBENUM_SIZE,4,i,0);
			nextdisplay = 1;
			start_index+=TIBENUM_SIZE;
		}
		else
			start_index+=TIBENUM_SIZE>>1;
		
		i = temp;
		display_TIB(start_index,1,start_index+TIBENUM_SIZE,4,i,0);
	}
}

double  Bandgap_Voltage,VDD_Voltage,BAT_Power_Voltage;			//please always use "double" mode for this
unsigned  char xdata ADCdataH[5], ADCdataL[5];
int ADCsumH=0, ADCsumL=0;
unsigned char ADCavgH,ADCavgL;
#define			READ_UID					0x04
void READ_BANDGAP(void)
{
		UINT8 BandgapHigh,BandgapLow,BandgapMark;
		double Bandgap_Value,Bandgap_Voltage_Temp;
	
		BAT_Power_Voltage = 0;
		VDD_Voltage = 0;
		Bandgap_Voltage = 0;
	
		set_IAPEN;
		IAPCN = READ_UID;
		IAPAL = 0x0d;
    IAPAH = 0x00;
    set_IAPGO;
		BandgapLow = IAPFD;
		BandgapMark = BandgapLow&0xF0;
			
		if (BandgapMark==0x80)
		{
				BandgapLow = BandgapLow&0x0F;
				IAPAL = 0x0C;
				IAPAH = 0x00;
				set_IAPGO;
				BandgapHigh = IAPFD;
				Bandgap_Value = (BandgapHigh<<4)+BandgapLow;
				Bandgap_Voltage_Temp = Bandgap_Value*3/4;
				Bandgap_Voltage = Bandgap_Voltage_Temp - 33;			//the actually banggap voltage value is similar this value.
		}
		if (BandgapMark==0x00)
		{
				BandgapLow = BandgapLow&0x0F;
				IAPAL = 0x0C;
				IAPAH = 0x00;
				set_IAPGO;
				BandgapHigh = IAPFD;
				Bandgap_Value = (BandgapHigh<<4)+BandgapLow;
				Bandgap_Voltage= Bandgap_Value*3/4;
		}
		if (BandgapMark==0x90)
		{
				IAPAL = 0x0E;
				IAPAH = 0x00;
				set_IAPGO;
				BandgapHigh = IAPFD;
				IAPAL = 0x0F;
				IAPAH = 0x00;
				set_IAPGO;
				BandgapLow = IAPFD;
				BandgapLow = BandgapLow&0x0F;
				Bandgap_Value = (BandgapHigh<<4)+BandgapLow;
				Bandgap_Voltage= Bandgap_Value*3/4;
		}
		clr_IAPEN;
}

void Get_Power_Value(void)
{	
		double bgvalue;
		unsigned int i;
		clr_EA;
		Enable_ADC_BandGap;												
		CKDIV = 0x02;															// IMPORTANT!! Modify system clock to 4MHz ,then add the ADC sampling clock base to add the sampling timing.
		for(i=0;i<5;i++)													// All following ADC detect timing is 200uS run under 4MHz.
		{
				clr_ADCF;
				set_ADCS;																
				while(ADCF == 0);
				ADCdataH[i] = ADCRH;
				ADCdataL[i] = ADCRL;
		}		
		CKDIV = 0x00;															// After ADC sampling, modify system clock back to 16MHz to run next code.
		Disable_ADC;
		for(i=2;i<5;i++)													// use the last 3 times data to make average 
		{
			ADCsumH = ADCsumH + ADCdataH[i];
			ADCsumL = ADCsumL + ADCdataL[i];
		}				
		ADCavgH = ADCsumH/3;
		ADCavgL = ADCsumL/3;
		bgvalue = (ADCavgH<<4) + ADCavgL;
		set_EA;
		VDD_Voltage = (0x1000/bgvalue)*Bandgap_Voltage;
		printf ("\r\n VDD voltage = %0.4f", VDD_Voltage); 
		
		ADCsumH = 0;
		ADCsumL = 0;
		//bat
		clr_EA;
		Enable_ADC_AIN3;
		CKDIV = 0x02;
		for(i=0;i<5;i++)													// All following ADC detect timing is 200uS run under 4MHz.
		{
				clr_ADCF;
				set_ADCS;																
				while(ADCF == 0);
				ADCdataH[i] = ADCRH;
				ADCdataL[i] = ADCRL;
		}		
		CKDIV = 0x00;
		Disable_ADC;
		for(i=2;i<5;i++)													// use the last 3 times data to make average 
		{
			ADCsumH = ADCsumH + ADCdataH[i];
			ADCsumL = ADCsumL + ADCdataL[i];
		}				
		ADCavgH = ADCsumH/3;
		ADCavgL = ADCsumL/3;
		bgvalue = (ADCavgH<<4) + ADCavgL;
		bgvalue = bgvalue * 2;
		set_EA;
		if (BAT_Power_Voltage == 0)
		{
			BAT_Power_Voltage = (bgvalue/0x1000)*VDD_Voltage;
		}
		else
		{
			BAT_Power_Voltage = BAT_Power_Voltage * 0.8;
			BAT_Power_Voltage = BAT_Power_Voltage + (bgvalue/0x1000)*VDD_Voltage * 0.2;
		}
		printf ("\r\n BAT voltage = %0.4f", BAT_Power_Voltage); 
		
		ADCsumH = 0;
		ADCsumL = 0;
}

unsigned char getbatlever(unsigned char ischarging)
{
	unsigned char temp;
	if (ischarging == 1)
	{
		BAT_Power_Voltage -= 50;
	}
	{
		if (BAT_Power_Voltage < (BAT_LEVEL_0 - 50))
		{
			//0
			temp = 0;
		}
		else if ((BAT_Power_Voltage > (BAT_LEVEL_0 + 50)) && (BAT_Power_Voltage < (BAT_LEVEL_1 - 50)))
		{
			//1
			temp = 1;
		}
		else if ((BAT_Power_Voltage > (BAT_LEVEL_1 + 50)) && (BAT_Power_Voltage < (BAT_LEVEL_2 - 50)))
		{
			//2
			temp = 2;
		}
		else if (BAT_Power_Voltage > (BAT_LEVEL_1 + 50))
		{
			//3
			temp = 3;
		}
//		printf("t/b=%d,%d",temp,batlevel);
		if (temp != batlevel)
		{
			bat_change_cnt++;
			if (bat_change_cnt >= 50)
			{
				if (ischarging == 1)
				{
					if (temp > batlevel)
					{
						batlevel = temp;
					}		
					else
					{
						temp = batlevel;
					}			
				}
				else
				{
					if (temp < batlevel)
					{
						batlevel = temp;
					}
					else
					{
						temp = batlevel;
					}
				}
				bat_change_cnt = 0;
			}
			else
			{
				temp = 0xFF;
			}
		}
		else
		{
			temp = 0xFF;
			bat_change_cnt = 0;
		}
	}
	return temp;
}

void display_baticonlevel(unsigned char level)
{
	unsigned char *buf;
	if(level == 0)
		buf = (unsigned char *)baticon_0;
	else if (level == 1)
		buf = (unsigned char *)baticon_1;
	else if (level == 2)
		buf = (unsigned char *)baticon_2;
	else if (level == 3)
		buf = (unsigned char *)baticon_3;
	else
	{
		printf("level error=%d\r\n",level);
		return;
	}
	isdisplaybaticon = 1;
	Draw_BMP(64-24,0,64,1,buf,0);
}

void display_baticon(void)
{
	unsigned char level;
	level = getbatlever(0);
	if (level != 0xFF)
	{
		if (batlevel != level)
		{
			batlevel = level;
			display_baticonlevel(batlevel);
		}
		sysinfo.lastpower = level;
	}
}

void Cnt_Stage(void)
{		
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		isdisplaybaticon = 0;
		display_cnt_stage_cnt(sysinfo.totalcnt,1);
		while (sysinfo.lastpower == 0xFF)
		{
			isdisplaybaticon = 0;
			sysinfo.lastpower = getbatlever(0);			
		}
		batlevel = sysinfo.lastpower;
		display_baticonlevel(sysinfo.lastpower);
		
		while(GETKEY == 0);
	}

	display_baticon();

	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			sysinfo.totalcnt++;
			if (sysinfo.totalcnt > 9999)
			{
				sysinfo.totalcnt = 0;
				display_cnt_stage_cnt(0,0);	
			}
			display_cnt_stage_cnt(sysinfo.totalcnt,1);
		}
		else if (keytype == LONGKEY_5S)
		{
			sysinfo.sysloop = RST_CNT;
			sysinfo.isneedinitstage = 1;
			stage_loopcnt = 0;
			OLED_CLS_Windows(0,0,64,2);
			display_cnt_stage_cnt(0,0);			
		}
		keytype = NULLKEY;
	}
}


void display_rst_cnt_stage_1(unsigned char isdisplay,unsigned char inverse)
{
//	char i;
//	char * en = "RST";
//	char * en1 = "CNT";
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
//			for (i=0;i<3;i++)
//			{
//				Draw_BMP(6+i*8,0,8+6 + i*8,2,font_A_Z + (en[i]-'A')*16);
//				Draw_BMP(32+ i*8,0,8+32+ i*8,2,font_A_Z + (en1[i]-'A')*16);
//			}
			Draw_BMP(6,0,14,2,(unsigned char *)font_R,inverse);
			Draw_BMP(32,0,40,2,(unsigned char *)font_C,inverse);
			Draw_BMP(14,0,22,2,(unsigned char *)font_S,inverse);
			Draw_BMP(40,0,48,2,(unsigned char *)font_N,inverse);
			Draw_BMP(22,0,30,2,(unsigned char *)font_T,inverse);
			Draw_BMP(48,0,56,2,(unsigned char *)font_T,inverse);
		}
		else
		{
			OLED_CLS_Windows(6,0,56,2);
		}		
	}
	else
	{
		if (isdisplay == 1)
		{
			Draw_BMP(16,0,16+16,2,(unsigned char *)font_CHN_GUI,inverse);
			Draw_BMP(32,0,32+16,2,(unsigned char *)font_CHN_LING,inverse);
		}
		else
		{
			OLED_CLS_Windows(16,0,48,2);
		}
	}
}
void display_rst_cnt_stage_yes(unsigned char isdisplay,unsigned char inverse)
{
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			Draw_BMP(20,0,20+8,2,(unsigned char *)font_Y,inverse);
			Draw_BMP(28,0,28+8,2,(unsigned char *)font_E,inverse);
			Draw_BMP(36,0,36+8,2,(unsigned char *)font_S,inverse);
		}
		else
		{
			OLED_CLS_Windows(20,0,44,2);
		}		
	}
	else	
	{
		if (isdisplay == 1)
		{
			Draw_BMP(24,0,24+16,2,(unsigned char *)font_CHN_SHI,inverse);
		}
		else
		{
			OLED_CLS_Windows(24,0,24+16,2);
		}	
	}
}
void display_rst_cnt_stage_no(unsigned char isdisplay,unsigned char inverse)
{
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			Draw_BMP(24,2,24+8,4,(unsigned char *)font_N,inverse);
			Draw_BMP(32,2,32+8,4,(unsigned char *)font_O,inverse);
		}
		else
		{
			OLED_CLS_Windows(24,2,40,4);
		}		
	}
	else	
	{	
		if (isdisplay == 1)
		{
			Draw_BMP(24,2,24+16,4,(unsigned char *)font_CHN_FOU,inverse);
		}
		else
		{
			OLED_CLS_Windows(24,2,24+16,4);
		}
	}	
}
void Rst_Cnt_Stage(void)
{
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		display_rst_cnt_stage_yes(1,1);
		display_rst_cnt_stage_no(1,0);
		stage_loopcnt = YES;
	}
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == YES)
			{
				display_rst_cnt_stage_yes(1,0);
				display_rst_cnt_stage_no(1,1);
				stage_loopcnt = NO;
			}
			else
			{
				display_rst_cnt_stage_yes(1,1);
				display_rst_cnt_stage_no(1,0);
				stage_loopcnt = YES;
			}
		}
		else if (keytype == LONGKEY_2S)
		{
			if (stage_loopcnt == 0)//yes
				sysinfo.totalcnt = 0;
			sysinfo.sysloop = CNT_STAGE;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
			display_rst_cnt_stage_yes(0,0);
			display_rst_cnt_stage_no(0,0);			
		}
		else if (keytype == LONGKEY_12S)
		{
			display_rst_cnt_stage_yes(0,0);
			display_rst_cnt_stage_no(0,0);	
			sysinfo.sysloop = SYSINIT;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
		}
		keytype = NULLKEY;
	}
}

#if POWER_WAKEUP
void display_baticonlevel_charging(unsigned char level)
{
	unsigned char *buf;
	if(level == 0)
		buf = (unsigned char*)chargeicon_0;
	else if (level == 1)
		buf = (unsigned char*)chargeicon_1;
	else if (level == 2)
		buf = (unsigned char*)chargeicon_2;
	else if (level == 3)
		buf = (unsigned char*)chargeicon_3;
	else
	{
		printf("level error=%d\r\n",level);
		return;
	}
	isdisplaybaticon = 1;
	Draw_BMP(16,1,16+32,3,buf,0);
}


void Sys_Charge_Stage(void)
{
	unsigned char level;
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;	
		OLED_CLS_Windows(0,0,64,4);
		while (sysinfo.lastpower == 0xFF)
		{
			isdisplaybaticon = 0;
			sysinfo.lastpower = getbatlever(1);			
		}
		batlevel = sysinfo.lastpower;
		display_baticonlevel_charging(sysinfo.lastpower);
		blinktime = 0;
		bat_charging_level = batlevel;
	}
	if (keytype != NULLKEY)
	{
		keytype = NULLKEY;
	}
	//blink
	if (blinktime == (BLINK_H+BLINK_L))
	{
		blinktime = 0;
		level = getbatlever(1);
		if (level != 0xFF)
		{
			if (batlevel != level)
			{
				batlevel = level;
				//display bat
				display_baticonlevel_charging(batlevel);
			}
			sysinfo.lastpower = level;	
		}
		else
		{
			bat_charging_level++;
			if (bat_charging_level > 3)
				bat_charging_level = sysinfo.lastpower;
			display_baticonlevel_charging(bat_charging_level);
		}
	}		
}
#endif
void SysLoop(void)
{
	switch(sysinfo.sysloop)
	{
		case SELECT_LANGUAGE:
			Select_Language();
			break;
		case SELECT_NUMTYPE:
			Select_NumType();
			break;
		case CNT_STAGE:
			Cnt_Stage();
			break;
		case RST_CNT:
			Rst_Cnt_Stage();
			break;
		#if POWER_WAKEUP
		case SYS_CHARGE:
			Sys_Charge_Stage();
			break;
		#endif
		default:break;
	}
}
void PinInterrupt_ISR (void) interrupt 7
{
	PIF = 0;
}
void EXT_INT0(void) interrupt 0
{
	
}

void EXT_INT1(void) interrupt 2
{
	
}
void P30_init(void){
	P30_Input_Mode;
	set_P3S_0;
//	set_IT0;
//	set_EX0;
//	
//	Enable_BIT0_RasingEdge_Trig;
	PICON|=0x04;PINEN&=0xFE;PIPEN|=0x01;
	Enable_INT_Port3;
	set_EPI;
	
	set_EA;
}
void exti1_init(void){
	P17_Input_Mode;
	set_P1S_7;
	set_EX1;
	set_EA;
}
void Enter_DPD(void)
{
	//…Ë÷√P17∞¥º¸ªΩ–—
	P30_init();
	exti1_init();
	
	set_PD;
	
	PICON  = PICON & 0xFE;
				
	clr_EX0;
	clr_EX1;
	clr_EPI;
}
void main1 (void) 
{
		double bgvalue;
		unsigned int i;
//	Set_All_GPIO_Quasi_Mode;
		Timer0_Init();
		InitialUART1_Timer3(115200);
	TI_1 = 1;
		READ_BANDGAP();
		printf ("\n BG ROMMAP = %e",Bandgap_Voltage); 
	
		while (1)
		{
				Enable_ADC_BandGap;												
				CKDIV = 0x02;															// IMPORTANT!! Modify system clock to 4MHz ,then add the ADC sampling clock base to add the sampling timing.
				for(i=0;i<5;i++)													// All following ADC detect timing is 200uS run under 4MHz.
				{
						clr_ADCF;
						set_ADCS;																
						while(ADCF == 0);
						ADCdataH[i] = ADCRH;
						ADCdataL[i] = ADCRL;
				}		
				CKDIV = 0x00;															// After ADC sampling, modify system clock back to 16MHz to run next code.
				Disable_ADC;
				for(i=2;i<5;i++)													// use the last 3 times data to make average 
				{
					ADCsumH = ADCsumH + ADCdataH[i];
					ADCsumL = ADCsumL + ADCdataL[i];
				}				
				ADCavgH = ADCsumH/3;
				ADCavgL = ADCsumL/3;
				bgvalue = (ADCavgH<<4) + ADCavgL;
				VDD_Voltage = (0x1000/bgvalue)*Bandgap_Voltage;
				printf ("\r\n VDD voltage = %e", VDD_Voltage); 
				
				ADCsumH = 0;
				ADCsumL = 0;
				//bat
				Enable_ADC_AIN3;
				CKDIV = 0x02;
				for(i=0;i<5;i++)													// All following ADC detect timing is 200uS run under 4MHz.
				{
						clr_ADCF;
						set_ADCS;																
						while(ADCF == 0);
						ADCdataH[i] = ADCRH;
						ADCdataL[i] = ADCRL;
				}		
				CKDIV = 0x00;
				Disable_ADC;
				for(i=2;i<5;i++)													// use the last 3 times data to make average 
				{
					ADCsumH = ADCsumH + ADCdataH[i];
					ADCsumL = ADCsumL + ADCdataL[i];
				}				
				ADCavgH = ADCsumH/3;
				ADCavgL = ADCsumL/3;
				bgvalue = (ADCavgH<<4) + ADCavgL;
				bgvalue = bgvalue * 2;
				VDD_Voltage = (bgvalue/0x1000)*VDD_Voltage;
				printf ("\r\n VDD voltage = %e", VDD_Voltage); 
				
				ADCsumH = 0;
				ADCsumL = 0;
		}
}

void main(void)
{
	while(1)
	{
//		Set_All_GPIO_Quasi_Mode;
		Timer0_Init();
		OLED_Init();
		OLED_Clear();
		KeyInit();
		//read sys struct from ldrom
		getdata(SysStructLen,(unsigned char *)&sysinfo);
		stage_loopcnt = 0;
		sysinfo.isneedinitstage = 1;
		powercnt = 0;
		isdisplaybaticon = 0;
		#if UART_TEST
		InitialUART1_Timer3(115200);
		TI_1 = 1;
		#endif
		READ_BANDGAP();
		Get_Power_Value();
//		while(1)
//		{
//			if (get_battery_time >= 200)
//			{
//				Get_Power_Value();
//				get_battery_time = 0;
//			}
//		}
		while(!GETKEY);
		printf("start\r\n");
		while(1)
		{
			KeyScan();
			
			if ((sysinfo.isinitsys != 0xA5)||(sysinfo.sysloop == SYSINIT))
			{
				//clr sysinfo
				sysinfo.language = CHINESE;
				sysinfo.numtype = ARABNUM;
				sysinfo.totalcnt = 0;
				sysinfo.isinitsys = 0xA5;
				sysinfo.sysloop = SELECT_LANGUAGE;
				OLED_Set_Pos(7,1);
				Draw_BMP(12,1,12+8,3,(unsigned char *)font_K,0);
				Draw_BMP(20,1,20+16,3,(unsigned char *)font_CHN_SAN,0);
				Draw_BMP(36,1,36+8,3,(unsigned char *)font_W,0);
				Draw_BMP(44,1,44+8,3,(unsigned char *)font_A,0);
				
				powercnt = 0;
				while(powercnt<400);
				powercnt=0;
				sysinfo.isneedinitstage = 1;
				
				OLED_CLS_Windows(12,1,52,3);
			}
			SysLoop();

			if (get_battery_time >= 40)
			{
				Get_Power_Value();
				get_battery_time = 0;
			}
			//power mode
			if (powercnt >= POWER_CNT1)
			{
				printf("sleep\r\n");
				OLED_Display_Off();
				if (sysinfo.sysloop == RST_CNT)
					sysinfo.sysloop = CNT_STAGE;
				savedata(SysStructLen,(unsigned char *)&sysinfo);

				Set_All_GPIO_Quasi_Mode;
				clr_ADCEN;
				clr_TR0;
				
				P14_OpenDrain_Mode;
				P14 = 0;
				Enter_DPD();
				powercnt = 0;
				set_TR0;
				printf("wakeup\r\n");
				break;
			}
		}
	}
}


