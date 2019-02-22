#include "count.h"
#include "sn_timer.h"

#include "fontdata.h"

unsigned char MONTH_DAY[]={31,28,31,30,31,30,31,31,30,31,30,31};

unsigned char stage_loopcnt = 0;

SysStruct	sysinfo;
KEYTYPE keytype;

unsigned char curKey,preKey;
unsigned char debounce;
unsigned int islongpress;
unsigned char is_5ms_Flag;
unsigned char blinktime;

unsigned int powercnt=0;

void KeyInit(void)
{
	curKey = 0;
	preKey = 0;
	debounce = 0;
	islongpress = 0;
	keytype = 0;
	KEYINPUTMODE;
}
#if MCU_SNC7312
void Timer_5ms(void)
{
		CT32B1_Init();//CT32B1 initial
		CT32B1_IRQEnable();//IRQ enable
		CT32B1_Prescale(0); //prescale = 0
		CT32B1_MREnable(0,0); //MR0 enable and mode = 0(TC reset)
		CT32B1_MRValue(0,96000*5); //15s @ 96MHz (0x55D4A800 = 1440000000)
		CT32B1_Enable();//timer enable	
}
/*****************************************************************************
* Function		: CT32B1_IRQHandler
* Description	: ISR of CT32B1 interrupt
*****************************************************************************/
 __irq void CT32B1_IRQHandler(void)
 {
	CT32B1_IRQFlagClear(0);//clear MR0 IRQ flag
	is_5ms_Flag = 1;
	 blinktime++;
	 if (blinktime > (BLINK_H+BLINK_L))
		 blinktime = 0;
	 powercnt++;
 }
 #endif
void KeyScan(void)
{
	if (is_5ms_Flag)
	{
		is_5ms_Flag = 0;
		curKey = GETKEY;
		if (curKey != preKey)
		{
			preKey = curKey;
			if ((islongpress == 0)&&(debounce > 5))
			{
				keytype = SHORTKEY;
			}
			else if (islongpress >= 12)
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
	}
}
void display_Language_chinese(unsigned char isdisplay)
{
	if (isdisplay == 1)
	{
		Draw_BMP(16,0,16+16,2,font_CHN + (ZHONG)*32);
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
		else if (keytype == LONGKEY_2S)
		{
			sysinfo.language = stage_loopcnt;
			sysinfo.sysloop = SELECT_DATE;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
			display_Language_english(0);
			display_Language_chinese(0);
		}
		else if (keytype == LONGKEY_5S)
		{
		}
		else if (keytype == LONGKEY_12S)
		{
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
void display_date_year(unsigned char isdisplay)
{
	unsigned char i;
	unsigned int  year;
	if (isdisplay == 1)
	{
		year = BASEYEAR + sysinfo.sysdate.Year - 2000;
		Draw_BMP(16,0,16+8,2,font2_0_9 + 16*2);//2
		i = getdiv(year,100);
		year = getremainder(year,100);
		Draw_BMP(24,0,24+8,2,font2_0_9 + 16*i);//
		i = getdiv(year,10);
		year = getremainder(year,10);
		Draw_BMP(32,0,32+8,2,font2_0_9 + 16*i);//
		i= year;
		Draw_BMP(40,0,40+8,2,font2_0_9 + 16*i);//2
	}
	else
	{
		OLED_CLS_Windows(16,0,48,2);
	}
}
void display_date_month(unsigned char isdisplay)
{
	unsigned char month;
	unsigned char i;
	if (isdisplay == 1)
	{
		month = sysinfo.sysdate.Month;
		i = getdiv(month,10);
		month = getremainder(month,10);
		Draw_BMP(12,2,12+8,4,font2_0_9 + 16*i);
		i = month;
		Draw_BMP(20,2,20+8,4,font2_0_9 + 16*i);
		Draw_BMP(28,2,28+8,4,font2_0_9 + 16*10);// '/'
	}
	else
	{
		OLED_CLS_Windows(12,2,28,4);
	}
}
void display_date_day(unsigned char isdisplay)
{
	unsigned char day;
	unsigned char i;
	if (isdisplay == 1)
	{
		day = sysinfo.sysdate.Day;
		i = getdiv(day,10);
		day = getremainder(day,10);
		Draw_BMP(36,2,36+8,4,font2_0_9 + 16*i);
		i = day;
		Draw_BMP(44,2,44+8,4,font2_0_9 + 16*i);
	}
	else
	{
		OLED_CLS_Windows(36,2,54,4);
	}
}
void Select_Date(void)
{
	unsigned char maxday;
	unsigned char year;
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;
		//init 
		display_Language_chinese(0);
		display_Language_english(0);
		//date
		display_date_year(1);
		display_date_month(1);
		display_date_day(1);
	}	
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			if (stage_loopcnt == YEAR)
				sysinfo.sysdate.Year++;
			else if (stage_loopcnt == MONTH)
			{
				sysinfo.sysdate.Month++;
				if (sysinfo.sysdate.Month > 12)
					sysinfo.sysdate.Month = 1;
			}
			else if (stage_loopcnt == DAY)
			{
				maxday = MONTH_DAY[sysinfo.sysdate.Month-1];
				sysinfo.sysdate.Day++;
				year = BASEYEAR + sysinfo.sysdate.Year;
				if((year%4==0&&year%100!=0)||(year%400==0))
				{
					if (sysinfo.sysdate.Month == 2)
						maxday = 29;
				}
				if (sysinfo.sysdate.Day > maxday)
					sysinfo.sysdate.Day = 1;
			}
		}
		else if (keytype == LONGKEY_2S)
		{
			if (stage_loopcnt == DAY)
			{
				sysinfo.sysloop = SELECT_NUMTYPE;
				sysinfo.isneedinitstage = 1;
				stage_loopcnt = 0;
				display_date_year(0);
				display_date_month(0);
				display_date_day(0);
			}
			else
				stage_loopcnt++;
			if (stage_loopcnt == MONTH)
				display_date_year(1);
			if (stage_loopcnt == DAY)
			{
				display_date_month(1);
			}
		}
		else if (keytype == LONGKEY_5S)
		{
		}
		else if (keytype == LONGKEY_12S)
		{
		}
		keytype = NULLKEY;
	}
	//blink
	if (blinktime == BLINK_H)
	{
		if (stage_loopcnt == YEAR)
			display_date_year(0);
		else if (stage_loopcnt == MONTH)
			display_date_month(0);
		else
			display_date_day(0);
	}	
	else if (blinktime == (BLINK_H+BLINK_L))
	{
		if (stage_loopcnt == YEAR)
			display_date_year(1);
		else if (stage_loopcnt == MONTH)
			display_date_month(1);
		else
			display_date_day(1);	
	}
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
		}
		else if (keytype == LONGKEY_2S)
		{
			sysinfo.sysloop = CNT_STAGE;
			sysinfo.numtype = stage_loopcnt;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
			display_cnt_stage_arabnum(0);
			display_cnt_stage_tibnum(0);			
		}
		else if (keytype == LONGKEY_5S)
		{
		}
		else if (keytype == LONGKEY_12S)
		{
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

void display_cnt_stage_date(unsigned char isdisplay)
{
	unsigned int temp;
	unsigned char i;
	if (isdisplay == 1)
	{
		temp = sysinfo.sysdate.Day;
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		Draw_BMP(52,0,58,1,font1_0_9 + 6*i);
		i = temp;
		Draw_BMP(58,0,64,1,font1_0_9 + 6*i);
		
		// '/'
		Draw_BMP(46,0,52,1,font1_0_9 + 6*10);
		
		temp = sysinfo.sysdate.Month;
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		Draw_BMP(34,0,40,1,font1_0_9 + 6*i);
		i = temp;
		Draw_BMP(40,0,46,1,font1_0_9 + 6*i);

		// '/'
		Draw_BMP(28,0,34,1,font1_0_9 + 6*10);
		
		temp = BASEYEAR + sysinfo.sysdate.Year - 2000;
		Draw_BMP(6,0,12,1,font1_0_9 + 6*2);//2
		i = getdiv(temp,100);
		temp = getremainder(temp,100);
		Draw_BMP(12,0,18,1,font1_0_9 + 6*i);//
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		Draw_BMP(18,0,22,1,font1_0_9 + 6*i);//
		i= temp;
		Draw_BMP(22,0,28,1,font1_0_9 + 6*i);//2		
	}
	else
	{
		OLED_CLS_Windows(6,0,64,2);
	}
}


void display_cnt_stage_cnt(unsigned long cnt,unsigned char isdisplay)
{
	unsigned char i;
	unsigned long temp;
	if (isdisplay == 0)
	{
		OLED_CLS_Windows(0,2,64,4);
		return;
	}
	temp = cnt;
	if (sysinfo.numtype == ARABNUM)
	{
		i = getdiv(temp,10000);
		temp = getremainder(temp,10000);
		Draw_BMP(12,2,12+8,4,font2_0_9 + 16*i);
		i = getdiv(temp,1000);
		temp = getremainder(temp,1000);
		Draw_BMP(20,2,20+8,4,font2_0_9 + 16*i);
		i = getdiv(temp,100);
		temp = getremainder(temp,100);
		Draw_BMP(28,2,28+8,4,font2_0_9 + 16*i);
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		Draw_BMP(36,2,36+8,4,font2_0_9 + 16*i);
		i = temp;
		Draw_BMP(44,2,44+8,4,font2_0_9 + 16*i);
	}
	else
	{
		i = getdiv(temp,10000);
		temp = getremainder(temp,10000);
		Draw_BMP(1,2,1+12,4,t0 + 24*i);
		i = getdiv(temp,1000);
		temp = getremainder(temp,1000);
		Draw_BMP(13,2,13+12,4,t0 + 24*i);
		i = getdiv(temp,100);
		temp = getremainder(temp,100);
		Draw_BMP(25,2,25+12,4,t0 + 24*i);
		i = getdiv(temp,10);
		temp = getremainder(temp,10);
		Draw_BMP(37,2,37+12,4,t0 + 24*i);
		i = temp;
		Draw_BMP(49,2,49+12,4,t0 + 24*i);		
	}
}
void Cnt_Stage(void)
{		
	if (sysinfo.isneedinitstage == 1)
	{
		sysinfo.isneedinitstage = 0;		
		display_cnt_stage_date(1);
		display_cnt_stage_cnt(sysinfo.totalcnt,1);
	}
	if (keytype != NULLKEY)
	{
		if (keytype == SHORTKEY)
		{
			sysinfo.totalcnt++;
			if (sysinfo.totalcnt > 99999)
				sysinfo.totalcnt = 0;
			display_cnt_stage_cnt(sysinfo.totalcnt,1);
		}
		else if (keytype == LONGKEY_2S)
		{
			
		}
		else if (keytype == LONGKEY_5S)
		{
			sysinfo.sysloop = RST_CNT;
			sysinfo.isneedinitstage = 1;
			stage_loopcnt = 0;
			display_cnt_stage_date(0);
			display_cnt_stage_cnt(0,0);			
		}
		else if (keytype == LONGKEY_12S)
		{
			sysinfo.sysloop = RST_SYS;
			sysinfo.isneedinitstage = 1;
			stage_loopcnt = 0;
			display_cnt_stage_date(0);
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
		else if (keytype == LONGKEY_2S)
		{
			if (stage_loopcnt == 0)//yes
				sysinfo.totalcnt = 0;
			sysinfo.sysloop = CNT_STAGE;
			stage_loopcnt = 0;
			sysinfo.isneedinitstage = 1;
			display_rst_cnt_stage_1(0);
			display_rst_cnt_stage_yes(0);
			display_rst_cnt_stage_no(0);			
		}
		else if (keytype == LONGKEY_5S)
		{
		}
		else if (keytype == LONGKEY_12S)
		{
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
		else if (keytype == LONGKEY_2S)
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
		}
		else if (keytype == LONGKEY_5S)
		{
		}
		else if (keytype == LONGKEY_12S)
		{
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

void SysLoop(void)
{
	switch(sysinfo.sysloop)
	{
		case SELECT_LANGUAGE:
			Select_Language();
			break;
		case SELECT_DATE:
			Select_Date();
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
		default:break;
	}
}


void main_loop(void)
{
	KeyInit();
	#if !MCU_SNC7312
	OLED_Init();
	#endif
	Timer_5ms();
	//read sys struct from ldrom
	stage_loopcnt = 0;
	
	sysinfo.isdpd = 0;
	while(1)
	{
		KeyScan();
		
		if ((sysinfo.isinitsys != 0xA5)||(sysinfo.sysloop == SYSINIT))
		{
			//clr sysinfo
			sysinfo.language = CHINESE;
			sysinfo.numtype = ARABNUM;
			sysinfo.sysdate.Year = 0;
			sysinfo.sysdate.Month = 1;
			sysinfo.sysdate.Day = 1;
			sysinfo.totalcnt = 0;
			sysinfo.isinitsys = 0xA5;
			sysinfo.sysloop = SELECT_LANGUAGE;
			sysinfo.isdpd = 0;
			//Display power on stage
			OLED_Set_Pos(7,1);
			Draw_BMP(12,1,12+8,3,font_A_Z + ('K' - 'A')*16);
			Draw_BMP(20,1,20+16,3,font_CHN + (SAN)*32);
			Draw_BMP(36,1,36+8,3,font_A_Z + ('W' - 'A')*16);
			Draw_BMP(44,1,44+8,3,font_A_Z + ('A' - 'A')*16);
			
			Delay1usFor96MHz(1000 * 2000);
			sysinfo.isneedinitstage = 1;
			
			OLED_CLS_Windows(12,1,52,3);
		}
		if (sysinfo.isdpd == 0)
			SysLoop();
		else
		{
			if (keytype != NULLKEY)
			{
				keytype = NULLKEY;
				//reinit oled
				sysinfo.isdpd = 0;
				OLED_Display_On();
			}
		}
		
		//power mode
		if (powercnt == POWER_CNT1)
		{
			//close OLED
			OLED_Display_Off();
			sysinfo.isdpd = 1;
			//display off
		}
		else if (powercnt == POWER_CNT2)
		{
			//enter dpd close device
			while(1);
		}
	}
}