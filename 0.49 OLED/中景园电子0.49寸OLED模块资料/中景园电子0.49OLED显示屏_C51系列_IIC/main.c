//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2014-0101
//  最近修改   : 
//  功能描述   : OLED 4接口演示例程(51系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   P1^0（SCL）
//              D1   P1^1（SDA）
/*------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2014/3/16
//All rights reserved
//******************************************************************************/
#include "REG51.h"
#include "oled.h"
#include "bmp.h"

 int main(void)
  {	u8 t;
		OLED_Init();			//初始化OLED  
		OLED_Clear()  	; 

	while(1) 
	{		

	   OLED_ShowString(0,0,"0.49OLED",8);
		 OLED_ShowString(0,1,"12345678",8);
		 OLED_ShowString(0,2,"12345678",8);
		OLED_ShowString(0,3,"12345678",8);

	  	delay_ms(1000);
	 	  OLED_Clear();
			OLED_ShowString(0,0,"0.49OLED",8);
		 OLED_ShowString(0,1,"12345678",8);
  	 OLED_ShowString(0,2,"12345678",16);

	  	delay_ms(1000);
	 	  OLED_Clear();
		OLED_ShowCHinese(8,0,0);//中
		OLED_ShowCHinese(24,0,1);//景
		OLED_ShowCHinese(40,0,2);//园
		OLED_ShowCHinese(8,2,7);//超
		OLED_ShowCHinese(40,2,8);//亮
	  	delay_ms(1000);
			OLED_Clear();
		OLED_DrawBMP(0,0,64,4,BMP1);			delay_ms(1000);
			delay_ms(1000);
	  	delay_ms(1000);
			 OLED_Clear();

	}	  
	
}
	