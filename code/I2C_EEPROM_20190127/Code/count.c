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
extern void initADC(void);
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

#if POWER_WAKEUP
unsigned char power_debounce;
bit  is_enter_charging;
unsigned char las_stage;
#endif
#define BAT_LEVEL_BUF_0	0x860
#define BAT_LEVEL_BUF_1	0x8C0
#define BAT_LEVEL_BUF_2	0x920
#define BAT_LEVEL_BUF_3	0x980

unsigned int adcvalue[16];
unsigned char adc_cnt;
unsigned char batlevel=0xFF;
bit isdisplaybaticon = 0;
extern bit BIT_TMP;

unsigned char ischangebatlevel_cnt = 0;
unsigned char get_battery_time = 0;
unsigned int val = 0;

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
			else if (islongpress >= 5)
			{
				keytype = LONGKEY_12S;
			}
			else if (islongpress >= 3)
			{
				keytype = LONGKEY_5S;
			}
			else if (islongpress >= 2)
			{
				keytype = LONGKEY_2S;
			}
			debounce = 0;
			islongpress = 0;
			
			powercnt = 0;
		}
		else if(curKey == 0)
		{
			debounce++;
			if (debounce > 200)
			{
				debounce = 0;
				islongpress++;
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

void display_Language_chinese(unsigned char isdisplay)
{
	if (isdisplay == 1)
	{
		Draw_BMP(16,0,16+16,2,(unsigned char *)(font_CHN + (ZHONG)*32));
		Draw_BMP(32,0,32+16,2,font_CHN + (WEN)*32);
	}
	else
	{
		OLED_CLS_Windows(16,0,48,2);
	}
}
void display_Language_english(unsigned char isdisplay)
{
	char * en = "ENGLISH";
	char i;
	if (isdisplay == 1)
	{
		for(i=0;i<7;i++)
			Draw_BMP(4+8*i,2,4+8+8*i,4,font_A_Z + (en[i] - 'A')*16);
	}
	else
	{
		OLED_CLS_Windows(4,2,60,4);
	}
}
void Select_Language(void)
{
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		//init 
		OLED_CLS_Windows(12,1,52,3);
		display_Language_chinese(1);
		display_Language_english(1);		
		stage_loopcnt = sysinfo.language;
		blinktime = (BLINK_H+BLINK_L);
	}
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == CHINESE)
			{
				display_Language_chinese(1);
				stage_loopcnt = ENGLISH;
			}
			else
			{
				display_Language_english(1);
				stage_loopcnt = CHINESE;	
			}
			sysinfo.language = stage_loopcnt;
		}
		else if (keytype >= LONGKEY_2S)
		{
			sysinfo.language = stage_loopcnt;
			sysinfo.sysloop = SELECT_NUMTYPE;
			stage_loopcnt = 0;
			blinktime = 0;
			sysinfo.isneedinitstage = 1;
			display_Language_english(0);
			display_Language_chinese(0);
		}
		keytype = NULLKEY;
	}
	//blink
	if (blinktime == BLINK_H)
	{
		if (sysinfo.language == CHINESE)
			display_Language_chinese(0);
		else
			display_Language_english(0);
	}	
	else if (blinktime == (BLINK_H+BLINK_L))
	{
		if (sysinfo.language == CHINESE)
			display_Language_chinese(1);
		else
			display_Language_english(1);		
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

void display_cnt_stage_arabnum(unsigned char isdisplay)
{
	char * nor = "NORMAL";
	char i;
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			for (i=0;i<6;i++)
			{
				Draw_BMP(8 + i*8,0,8+8 + i*8,2,font_A_Z + (nor[i] - 'A')*16);
			}
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
			Draw_BMP(16,0,16+16,2,font_CHN + (SHU)*32);
			Draw_BMP(32,0,32+16,2,font_CHN + (ZI)*32);
		}
		else
		{
			OLED_CLS_Windows(16,0,48,2);
		}
	}
}
void display_cnt_stage_tibnum(unsigned char isdisplay)
{	
	char * nor = "TIBETAN";
	char i;
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			for (i=0;i<7;i++)
			{
				Draw_BMP(4+ i*8,2,8+4+ i*8,4,font_A_Z + (nor[i] - 'A')*16);
			}
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
			Draw_BMP(0,2,0+16,4,font_CHN + (ZANG)*32);
			Draw_BMP(16,2,16+16,4,font_CHN + (WEN)*32);		
			Draw_BMP(32,2,16+32,4,font_CHN + (SHU)*32);
			Draw_BMP(48,2,48+16,4,font_CHN + (ZI)*32);
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
		display_cnt_stage_arabnum(1);
		display_cnt_stage_tibnum(1);
		stage_loopcnt = sysinfo.numtype;
		blinktime = (BLINK_H+BLINK_L);
	}	
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == TIBENUM)
			{
				display_cnt_stage_tibnum(1);
				stage_loopcnt = ARABNUM;
			}
			else
			{
				display_cnt_stage_arabnum(1);
				stage_loopcnt = TIBENUM;
			}
			sysinfo.numtype = stage_loopcnt;
		}
		else if (keytype >= LONGKEY_2S)
		{
			sysinfo.sysloop = CNT_STAGE;
			sysinfo.numtype = stage_loopcnt;
			stage_loopcnt = 0;
			blinktime = 0;
			sysinfo.isneedinitstage = 1;
			display_cnt_stage_arabnum(0);
			display_cnt_stage_tibnum(0);			
		}
		keytype = NULLKEY;
	}
	//blink
	if (blinktime == BLINK_H)
	{
		if (stage_loopcnt == TIBENUM)
			display_cnt_stage_tibnum(0);
		else if (stage_loopcnt == ARABNUM)
			display_cnt_stage_arabnum(0);
	}	
	else if (blinktime == (BLINK_H+BLINK_L))
	{
		if (stage_loopcnt == TIBENUM)
			display_cnt_stage_tibnum(1);
		else if (stage_loopcnt == ARABNUM)
			display_cnt_stage_arabnum(1);
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
		
		#define CNT_START_ARABNUM	12
		#define ARABNUM_SIZE	8
		start_index = CNT_START_ARABNUM;
		i = getdiv(temp,10000);
		temp = getremainder(temp,10000);
		if (i != 0)
		{
			Draw_BMP(start_index,2,start_index+ARABNUM_SIZE,4,font2_0_9 + 16*i);
			nextdisplay = 1;
			start_index+=ARABNUM_SIZE;
		}
		else
		{
			start_index+=ARABNUM_SIZE>>1;
		}
		
		i = getdiv(temp,1000);
		temp = getremainder(temp,1000);
		if ((nextdisplay == 1)||(i != 0))
		{
			nextdisplay = 1;
			Draw_BMP(start_index,2,start_index+ARABNUM_SIZE,4,font2_0_9 + 16*i);
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
			Draw_BMP(start_index,2,start_index+ARABNUM_SIZE,4,font2_0_9 + 16*i);
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
			Draw_BMP(start_index,2,start_index+ARABNUM_SIZE,4,font2_0_9 + 16*i);
			start_index+=ARABNUM_SIZE;
		}
		else
		{
			start_index+=ARABNUM_SIZE>>1;
		}
		
		i = temp;
		Draw_BMP(start_index,2,start_index+ARABNUM_SIZE,4,font2_0_9 + 16*i);
	}
	else
	{
		#define CNT_START_TIBENUM	2
		#define TIBENUM_SIZE	12
		start_index = CNT_START_TIBENUM;
		i = getdiv(temp,10000);
		temp = getremainder(temp,10000);
		if (i != 0)
		{
			Draw_BMP(start_index,2,start_index+TIBENUM_SIZE,4,t0 + 24*i);
			nextdisplay = 1;
			start_index+=TIBENUM_SIZE;
		}
		else
			start_index+=TIBENUM_SIZE>>1;
		
		i = getdiv(temp,1000);
		temp = getremainder(temp,1000);
		if ((nextdisplay == 1)||(i != 0))
		{
			Draw_BMP(start_index,2,start_index+TIBENUM_SIZE,4,t0 + 24*i);
			nextdisplay = 1;
			start_index+=TIBENUM_SIZE;
		}
		else
			start_index+=TIBENUM_SIZE>>1;
		
		i = getdiv(temp,100);
		temp = getremainder(temp,100);
		if ((nextdisplay == 1)||(i != 0))
		{
			Draw_BMP(start_index,2,start_index+TIBENUM_SIZE,4,t0 + 24*i);
			nextdisplay = 1;
			start_index+=TIBENUM_SIZE;
		}
		else
			start_index+=TIBENUM_SIZE>>1;
		
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		if ((nextdisplay == 1)||(i != 0))
		{
			Draw_BMP(start_index,2,start_index+TIBENUM_SIZE,4,t0 + 24*i);
			nextdisplay = 1;
			start_index+=TIBENUM_SIZE;
		}
		else
			start_index+=TIBENUM_SIZE>>1;
		
		i = temp;
		Draw_BMP(start_index,2,start_index+TIBENUM_SIZE,4,t0 + 24*i);	
	}
}



unsigned char getbatlever(unsigned char ischarging)
{
	unsigned char i,j;
	unsigned int curval = 0;
	unsigned char temp=0xFF;
	if (adc_cnt >= 16)
	{
		clr_EADC;
		adc_cnt = 0;
		for(i=0;i<16;i++)
		{
			for (j = i+1;j<16;j++)
			{
				curval = adcvalue[j];
				if (curval > adcvalue[i])
				{
					adcvalue[j] = adcvalue[i];
					adcvalue[i] = curval;
				}
			}
		}
		curval = 0;
		for (i = 4; i<12;i++)
			curval+=adcvalue[i];
		curval = curval>>3;
		if (ischarging == 1)
			curval -= 0x20;
		
		
		if (val == 0)
			val = curval;
		else
		{			
			if (curval > (val+5))
			{
				val++;
				return 0xFF;
				//curval = val+5;
			}
			else if ((curval+5) < val)
			{
				val--;
				return 0xFF;
				//curval = val-5;
			}
			else if ((curval+20) < val)
			{
				val = curval + 20;
			}
//			curval = curval >> 1;
//			val = val >> 1;
			curval = (curval +val) >> 1;
			if (ischarging == 1)
			{				
				if (curval > val)
				{
					val = curval;
//					val = val << 1;
				}
			}
			else
			{
				if (val > curval)
				{
					val = curval;
//					val = val << 1;
				}
			}
			
		}
		
		
		if (isdisplaybaticon == 0)
		{
			if (val > BAT_LEVEL_BUF_3)
				temp =  4;
			else if (val > BAT_LEVEL_BUF_2)
				temp =  3;
			else if (val > BAT_LEVEL_BUF_1)
				temp =  2;
			else if (val > BAT_LEVEL_BUF_0)
				temp =  1;
			else 
				temp =  0;
			ischangebatlevel_cnt = 0;
//			set_EADC;
		}
		else
		{
			if (val < (BAT_LEVEL_BUF_0 - 0x08))
				temp =  0;
			else if ((val > (BAT_LEVEL_BUF_0 + 0x08))&&(val < (BAT_LEVEL_BUF_1 - 0x08)))
			{
				temp =  1;
			}
			else if ((val > (BAT_LEVEL_BUF_1+ 0x08))&&(val < (BAT_LEVEL_BUF_2 - 0x08)))
			{
				temp =  2;
			}
			else if ((val > (BAT_LEVEL_BUF_2 + 0x08))&&(val < (BAT_LEVEL_BUF_3 - 0x08)))
			{
				temp =  3;
			}
			else if (val > (BAT_LEVEL_BUF_3 + 0x08))
			{
				temp =  4;
			}
			
			if (temp != batlevel)
			{
				ischangebatlevel_cnt++;
				if (ischangebatlevel_cnt < 5)
				{
					temp = batlevel;
				}
				else
				{
					ischangebatlevel_cnt = 0;
//					if (ischarging == 1)
//					{
//						if (temp <= batlevel)
//							temp = batlevel;
//					}
//					else
//					{
//						if (temp >= batlevel)
//							temp = batlevel;
//					}
				}
			}
			else
				ischangebatlevel_cnt = 0;
		}
//		set_EADC;
	}
	return temp;
}

void display_baticonlevel(unsigned char level)
{
	unsigned char *buf;
	if (level > 4)
		level = 4;
//	if (level == 0)
//	{
//		for (i = 0; i < 8;i++)
//		{
//			baticon[4+i] = 0x18;
//			baticon[20+i] = 0x0C;
//		}
//	}
//	else if(level == 1)
//	{
//		for (i = 0; i < 2;i++)
//		{
//			baticon[4+i] = 0xF8;
//			baticon[20+i] = 0x0F;
//		}
//		for (i = 2; i < 8;i++)
//		{
//			baticon[4+i] = 0x18;
//			baticon[20+i] = 0x0C;
//		}
//	}
//	else if(level == 2)
//	{
//		for (i = 0; i < 4;i++)
//		{
//			baticon[4+i] = 0xF8;
//			baticon[20+i] = 0x0F;
//		}
//		for (i = 4; i < 8;i++)
//		{
//			baticon[4+i] = 0x18;
//			baticon[20+i] = 0x0C;
//		}
//	}
//	else if(level == 3)
//	{
//		for (i = 0; i < 6;i++)
//		{
//			baticon[4+i] = 0xF8;
//			baticon[20+i] = 0x0F;
//		}
//		for (i = 6; i < 8;i++)
//		{
//			baticon[4+i] = 0x18;
//			baticon[20+i] = 0x0C;
//		}
//	}
//	else
//	{
//		for (i = 0; i < 8;i++)
//		{
//			baticon[4+i] = 0xF8;
//			baticon[20+i] = 0x0F;
//		}
//	}
	buf = (unsigned char *)baticon + (level * 32);
	isdisplaybaticon = 1;
	Draw_BMP(0,0,16,2,buf);
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
		adc_cnt = 0;
//		set_EADC;
	}
}

void Cnt_Stage(void)
{		
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		blinktime = 0;
		isdisplaybaticon = 0;		
//		display_cnt_stage_date(1);
//		initADC();
		display_cnt_stage_cnt(sysinfo.totalcnt,1);
//		if (sysinfo.lastpower == 0xFF)
		{
			isdisplaybaticon = 0;
			sysinfo.lastpower = getbatlever(0);			
		}
		batlevel = sysinfo.lastpower;
		display_baticonlevel(sysinfo.lastpower);
		
	}

	display_baticon();

//	if (powercnt == 20)
//	{
//		powercnt = 0;
//		sysinfo.totalcnt++;
//		if (sysinfo.totalcnt > 99999)
//				sysinfo.totalcnt = 0;
//		display_cnt_stage_cnt(sysinfo.totalcnt,1);
//	}
	
	if (keytype != NULLKEY)
	{
//		sysinfo.totalcnt = val;
//		display_cnt_stage_cnt(sysinfo.totalcnt,1);
		if (keytype == SHORTKEY)
		{
			sysinfo.totalcnt++;
			if (sysinfo.totalcnt > 99999)
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
//			batlevel = 0xFF;
			OLED_CLS_Windows(0,0,64,2);
//			display_cnt_stage_date(0);
			display_cnt_stage_cnt(0,0);			
		}
		else if (keytype == LONGKEY_12S)
		{
			sysinfo.sysloop = RST_SYS;
			sysinfo.isneedinitstage = 1;
			stage_loopcnt = 0;
//			batlevel = 0xFF;
			OLED_CLS_Windows(0,0,64,2);
//			display_cnt_stage_date(0);
			display_cnt_stage_cnt(0,0);			
		}
		keytype = NULLKEY;
	}
}


void display_rst_cnt_stage_1(unsigned char isdisplay)
{
	char i;
	char * en = "RST";
	char * en1 = "CNT";
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			for (i=0;i<3;i++)
			{
				Draw_BMP(6+i*8,0,8+6 + i*8,2,font_A_Z + (en[i]-'A')*16);
				Draw_BMP(32+ i*8,0,8+32+ i*8,2,font_A_Z + (en1[i]-'A')*16);
			}
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
			Draw_BMP(16,0,16+16,2,font_CHN + (GUI)*32);
			Draw_BMP(32,0,32+16,2,font_CHN + (LING)*32);
		}
		else
		{
			OLED_CLS_Windows(16,0,48,2);
		}
	}
}
void display_rst_cnt_stage_yes(unsigned char isdisplay)
{
	char i;
	char * en = "YES";
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			for (i=0;i<3;i++)
			{
				Draw_BMP(10+i*8,2,8+10 + i*8,4,font_A_Z + (en[i]-'A')*16);
			}
		}
		else
		{
			OLED_CLS_Windows(10,2,34,4);
		}		
	}
	else	
	{
		if (isdisplay == 1)
		{
			Draw_BMP(12,2,12+16,4,font_CHN + (SHI)*32);
		}
		else
		{
			OLED_CLS_Windows(12,2,28,4);
		}	
	}
}
void display_rst_cnt_stage_no(unsigned char isdisplay)
{
	char i;
	char * en = "NO";
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			for (i=0;i<2;i++)
			{
				Draw_BMP(38+i*8,2,8+38 + i*8,4,font_A_Z + (en[i]-'A')*16);
			}
		}
		else
		{
			OLED_CLS_Windows(38,2,54,4);
		}		
	}
	else	
	{	
		if (isdisplay == 1)
		{
			Draw_BMP(36,2,36+16,4,font_CHN + (FOU)*32);
		}
		else
		{
			OLED_CLS_Windows(36,2,52,4);
		}
	}	
}
void Rst_Cnt_Stage(void)
{
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		display_rst_cnt_stage_1(1);
		display_rst_cnt_stage_yes(1);
		display_rst_cnt_stage_no(1);
		blinktime = (BLINK_H+BLINK_L);
	}
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == YES)
			{
				display_rst_cnt_stage_yes(1);
				stage_loopcnt = NO;
			}
			else
			{
				stage_loopcnt = YES;
				display_rst_cnt_stage_no(1);
			}
		}
		else if (keytype >= LONGKEY_2S)
		{
			if (stage_loopcnt == 0)//yes
				sysinfo.totalcnt = 0;
			sysinfo.sysloop = CNT_STAGE;
			stage_loopcnt = 0;
			blinktime = 0;
//			batlevel = 0xff;
			sysinfo.isneedinitstage = 1;
			display_rst_cnt_stage_1(0);
			display_rst_cnt_stage_yes(0);
			display_rst_cnt_stage_no(0);			
		}
		keytype = NULLKEY;
	}
	//blink
	if (blinktime == BLINK_H)
	{
		if (stage_loopcnt == YES)
			display_rst_cnt_stage_yes(0);
		else if (stage_loopcnt == NO)
			display_rst_cnt_stage_no(0);
	}	
	else if (blinktime == (BLINK_H+BLINK_L))
	{
		if (stage_loopcnt == YES)
			display_rst_cnt_stage_yes(1);
		else if (stage_loopcnt == NO)
			display_rst_cnt_stage_no(1);
	}	
}

void display_rst_sys_stage_1(unsigned char isdisplay)
{
	char i;
	char * en = "RST";
	char * en1 = "DEV";
	if (sysinfo.language == ENGLISH)
	{
		if (isdisplay == 1)
		{
			for (i=0;i<3;i++)
			{
				Draw_BMP(6+i*8,0,8+6 + i*8,2,font_A_Z + (en[i]-'A')*16);
				Draw_BMP(32+ i*8,0,8+32+ i*8,2,font_A_Z + (en1[i]-'A')*16);
			}
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
			Draw_BMP(16,0,16+16,2,font_CHN + (CHONG)*32);
			Draw_BMP(32,0,32+16,2,font_CHN + (ZHI)*32);
		}
		else
		{
			OLED_CLS_Windows(16,0,48,2);
		}
	}
}

void Rst_Sys_Stage(void)
{
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		display_rst_sys_stage_1(1);
		display_rst_cnt_stage_yes(1);
		display_rst_cnt_stage_no(1);	
		blinktime = (BLINK_H+BLINK_L);
	}
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == YES)
			{
				display_rst_cnt_stage_yes(1);
				stage_loopcnt = NO;
			}
			else
			{
				stage_loopcnt = YES;
				display_rst_cnt_stage_no(1);	
			}
		}
		else if (keytype >= LONGKEY_2S)
		{
			display_rst_sys_stage_1(0);
			display_rst_cnt_stage_yes(0);	
			display_rst_cnt_stage_no(0);	
			if (stage_loopcnt == 0)
			{
				sysinfo.sysloop = SYSINIT;
			}
			else
				sysinfo.sysloop = CNT_STAGE;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
//			batlevel = 0xff;
		}
		keytype = NULLKEY;
	}
	//blink
	if (blinktime == BLINK_H)
	{
		if (stage_loopcnt == YES)
			display_rst_cnt_stage_yes(0);
		else if (stage_loopcnt == NO)
			display_rst_cnt_stage_no(0);
	}	
	else if (blinktime == (BLINK_H+BLINK_L))
	{
		if (stage_loopcnt == YES)
			display_rst_cnt_stage_yes(1);
		else if (stage_loopcnt == NO)
			display_rst_cnt_stage_no(1);
	}		
}

#if POWER_WAKEUP
void display_baticonlevel_charging(unsigned char level)
{
	unsigned char *buf;
	if (level > 4)
		level = 4;
//	if (level == 0)
//	{
//		for (i = 0; i < 24;i++)
//		{
//			chargeicon[2+i] = 0x03;
//			chargeicon[34+i] = 0xC0;
//		}
//	}
//	else if(level == 1)
//	{
//		for (i = 0; i < 6;i++)
//		{
//			chargeicon[2+i] = 0xFF;
//			chargeicon[34+i] = 0xFF;
//		}
//		for (i = 6; i < 24;i++)
//		{
//			chargeicon[2+i] = 0x03;
//			chargeicon[34+i] = 0xC0;
//		}
//	}
//	else if(level == 2)
//	{
//		for (i = 0; i < 12;i++)
//		{
//			chargeicon[2+i] = 0xFF;
//			chargeicon[34+i] = 0xFF;
//		}
//		for (i = 12; i < 24;i++)
//		{
//			chargeicon[2+i] = 0x03;
//			chargeicon[34+i] = 0xC0;
//		}
//	}
//	else if(level == 3)
//	{
//		for (i = 0; i < 18;i++)
//		{
//			chargeicon[2+i] = 0xFF;
//			chargeicon[34+i] = 0xFF;
//		}
//		for (i = 18; i < 24;i++)
//		{
//			chargeicon[2+i] = 0x03;
//			chargeicon[34+i] = 0xC0;
//		}
//	}
//	else
//	{
//		for (i = 0; i < 24;i++)
//		{
//			chargeicon[2+i] = 0xFF;
//			chargeicon[34+i] = 0xFF;
//		}
//	}
	buf = (unsigned char*)chargeicon + (64*level);
	isdisplaybaticon = 1;
	Draw_BMP(16,1,16+32,3,buf);
}


void Sys_Charge_Stage(void)
{
	unsigned char level;
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;	
		OLED_CLS_Windows(0,0,64,4);
//		initADC();		
		if (sysinfo.lastpower == 0xFF)
		{
			isdisplaybaticon = 0;
			sysinfo.lastpower = getbatlever(1);			
		}
		batlevel = sysinfo.lastpower;
		display_baticonlevel_charging(sysinfo.lastpower);
		blinktime = 0;
	}
	if (keytype != NULLKEY)
	{
		keytype = NULLKEY;
	}
	//blink
	if (blinktime == (BLINK_H+BLINK_L))
	{			
//		level = getbatlever(1);
//		sysinfo.totalcnt = val;
//		display_cnt_stage_cnt(sysinfo.totalcnt,1);
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
			adc_cnt = 0;			
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
		case RST_SYS:
			Rst_Sys_Stage();
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
	//ÉèÖÃP17°´¼ü»½ÐÑ
	P30_init();
	exti1_init();
	
	set_PD;
	
	PICON  = PICON & 0xFE;
				
	clr_EX0;
	clr_EX1;
	clr_EPI;
}

void main_loop(void)
{
	clr_EPI;
	OLED_Init();
	OLED_Clear();
	KeyInit();
	//read sys struct from ldrom
	getdata(SysStructLen,DATA_START_ADDR,(unsigned char *)&sysinfo);
	stage_loopcnt = 0;
	sysinfo.isneedinitstage = 1;
	powercnt = 0;
	isdisplaybaticon = 0;
	batlevel = 0xff;
	val = 0;
	initADC();	
	while(!GETKEY);
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
//			sysinfo.lastpower = 0xFF;
//			batlevel = 0xff;
			//Display power on stage
			OLED_Set_Pos(7,1);
			Draw_BMP(12,1,12+8,3,font_A_Z + ('K' - 'A')*16);
			Draw_BMP(20,1,20+16,3,font_CHN + (SAN)*32);
			Draw_BMP(36,1,36+8,3,font_A_Z + ('W' - 'A')*16);
			Draw_BMP(44,1,44+8,3,font_A_Z + ('A' - 'A')*16);
			
			powercnt = 0;
			Erase_LDROM(512,0);
			Erase_LDROM(512,512);	
//			initADC();
//			sysinfo.lastpower = getbatlever(P30);
			while(powercnt<400);
			powercnt=0;
			sysinfo.isneedinitstage = 1;
			
			OLED_CLS_Windows(12,1,52,3);
		}
		SysLoop();

		if (get_battery_time >= 200)
		{
			if (EADC == 0)
				set_EADC;
			get_battery_time = 0;
		}
		//power mode
		if (powercnt >= POWER_CNT1)
		{
			
			//close OLED
			OLED_Display_Off();
			//OLED power down
			//save DATA 
			if ((sysinfo.sysloop == RST_CNT) ||(sysinfo.sysloop == RST_SYS))
				sysinfo.sysloop = CNT_STAGE;
			savedata(SysStructLen,DATA_START_ADDR,(unsigned char *)&sysinfo);

			Set_All_GPIO_Quasi_Mode;
			clr_ADCEN;
			clr_TR0;
			
			P14_OpenDrain_Mode;
			P14 = 0;
			Enter_DPD();
			powercnt = 0;
			set_TR0;
			initADC();
			return;
		}
	}
}


