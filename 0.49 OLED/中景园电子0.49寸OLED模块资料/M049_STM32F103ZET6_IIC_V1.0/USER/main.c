//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : Evk123
//  ��������   : 2014-0101
//  ����޸�   : 
//  ��������   : 0.49��OLED �ӿ���ʾ����(STM32F103ZEϵ��IIC)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND   ��Դ��
//              VCC   ��5V��3.3v��Դ
//              SCL   ��PD6��SCL��
//              SDA   ��PD7��SDA��            
//              ----------------------------------------------------------------
//Copyright(C) �о�԰����2014/3/16
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
 int main(void)
  {	u8 t;
		delay_init();	    	 //��ʱ������ʼ��	  
		OLED_Init();			//��ʼ��OLED  
		OLED_Clear()  	; 

	while(1) 
	{		

	   OLED_ShowString(0,0,"0.49OLED",8);
		 OLED_ShowString(0,1,"12345678",8);
		 OLED_ShowString(0,2,"12345678",8);
		OLED_ShowString(0,3,"12345678",8);
			delay_ms(1000);
	  	delay_ms(1000);
	  	delay_ms(1000);
	 	  OLED_Clear();
			OLED_ShowString(0,0,"0.49OLED",8);
		 OLED_ShowString(0,1,"12345678",8);
  	 OLED_ShowString(0,2,"12345678",16);
			delay_ms(1000);
	  	delay_ms(1000);
	  	delay_ms(1000);
	 	  OLED_Clear();
		OLED_ShowCHinese(8,0,0);//��
		OLED_ShowCHinese(24,0,1);//��
		OLED_ShowCHinese(40,0,2);//԰
		OLED_ShowCHinese(8,2,7);//��
		OLED_ShowCHinese(40,2,8);//��
			delay_ms(1000);
	  	delay_ms(1000);
	  	delay_ms(1000);
			OLED_Clear();
		OLED_DrawBMP(0,0,64,4,BMP1);
			delay_ms(1000);
			delay_ms(1000);
	  	delay_ms(1000);
			 OLED_Clear();

	}	  
	
}