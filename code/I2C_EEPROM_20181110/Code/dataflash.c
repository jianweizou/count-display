/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Jan/21/2017
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 APROM program DATAFLASH (APROM) demo code
//***********************************************************************************************************
#include "dataflash.h"

/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2017
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 APROM program DATAFLASH (APROM) demo code
//***********************************************************************************************************

#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "dataflash.h"				



//-----------------------------------------------------------------------------------------------------------/
void Trigger_IAP(void)
{   
    set_IAPGO;																	//trigger IAP
    if((CHPCON&SET_BIT6)==SET_BIT6)             // if fail flag is set, toggle error LED and IAP stop
	{
		clr_IAPFF;
	}
}
/*
		WARNING:
	No matter read or writer, when IAPFF is set 1, 
	this step process is fail. DATA should be ignore.
*/
//-----------------------------------------------------------------------------------------------------------/

/*****************************************************************************************************************
Erase APROM subroutine:
	

******************************************************************************************************************/		
void Erase_LDROM(unsigned int datasize,unsigned int dataaddr)
{   
    unsigned int u16Count,i;
	if (datasize == 0)
		return;
	u16Count = datasize>>7;
	if (datasize & 0x7F)
		u16Count++;
    set_IAPEN;													// Enable IAP function
		IAPFD = 0xFF;												// IMPORTANT !! To erase function must setting IAPFD = 0xFF 
    IAPCN = PAGE_ERASE_LD;
    set_LDUEN;													//  APROM modify Enable
	
    for(i=0x0000;i<u16Count;i++)		//
    {        
        IAPAL = LOBYTE(i*PAGE_SIZE + dataaddr);
        IAPAH = HIBYTE(i*PAGE_SIZE + dataaddr);
        Trigger_IAP(); 
    }
//    clr_LDUEN;
//    clr_IAPEN;
}

//-----------------------------------------------------------------------------------------------------------
void Program_LDROM(unsigned int datasize,unsigned int dataaddr,unsigned char * buf)
{   
    unsigned int u16Count;

    set_IAPEN;
    set_LDUEN;    
    IAPAL = LOBYTE(dataaddr);
    IAPAH = HIBYTE(dataaddr);
    IAPCN = BYTE_PROGRAM_LD;
    
    for(u16Count=0;u16Count<datasize;u16Count++)
    {   
        IAPFD = buf[u16Count];
        Trigger_IAP();
       
        IAPAL++;
        if(IAPAL == 0)
        {
            IAPAH++;
        }
    } 
		
    clr_LDUEN;
    clr_IAPEN;
}
//-----------------------------------------------------------------------------------------------------------
void Program_LDROM_Verify(unsigned int datasize,unsigned int dataaddr,unsigned char  *buf)
{   
    unsigned int u16Count;

    set_IAPEN;
    IAPAL = LOBYTE(dataaddr);
    IAPAH = HIBYTE(dataaddr);
    IAPCN = BYTE_READ_LD;

    for(u16Count=0;u16Count<datasize;u16Count++)
    {   
        Trigger_IAP();
		buf[u16Count] = IAPFD;
        IAPAL++;
        if(IAPAL == 0)
        {
            IAPAH++;
        }
    } 

    clr_IAPEN;
}

/*
512 bytes div 32*16
*/

void getdata(unsigned char datasize,unsigned int data_start_addr,unsigned char * buf)
{
	unsigned char i;
	getdatastart:
	for(i = 0; i< 32 ;i++)
	{
		Program_LDROM_Verify(datasize,data_start_addr + (i<<4),buf);
		if (buf[0] != 0xA5)
			break;
	}
	if (i == 0)
	{
		//error read back area
		if (data_start_addr < 512)
		{
			data_start_addr += 512;
			goto getdatastart;
		}
	}
	else
	{
		i = i - 1;
		Program_LDROM_Verify(datasize,data_start_addr + (i<<4),buf);
	}
}
//-----------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------
void savedata (unsigned char datasize,unsigned int data_addr,unsigned char * buf) 
{
	unsigned char buf1[16];
	unsigned char i,j;
	for(i=0;i<32;i++)
	{
		Program_LDROM_Verify(datasize,data_addr + (i<<4),buf1);
		if (buf1[0] != 0xA5)
			break;
	}
	j = i;
	if (i == 32)
	{
		Erase_LDROM(512,data_addr);
		i = 0;
	}
	Program_LDROM(datasize,data_addr + (i<<4),buf); 
	
	//backup
	if (j == 32)
	{
		Erase_LDROM(512,512);
		j = 0;
	}
	Program_LDROM(datasize,data_addr + (j<<4) + 512,buf);
}


//-----------------------------------------------------------------------------------------------------------
