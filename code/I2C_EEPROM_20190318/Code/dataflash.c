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


#if 0
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
    clr_LDUEN;
    clr_IAPEN;
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

#else


#define ADDR_BASE 0x3800

/*****************************************************************************************************************
write_DATAFLASH_BYTE :
user can copy all this subroutine into project, then call this function in main.
******************************************************************************************************************/		
void write_DATAFLASH_BYTE(UINT16 u16_addr,UINT8 u8_data)
{
	UINT8 looptmp=0,u8_addrl_r;
	unsigned char code *cd_longaddr;
	unsigned char xdata *xd_tmp;
	
//Check page start address
	u8_addrl_r = u16_addr;
	if (u8_addrl_r<0x80)
	{
		u8_addrl_r = 0;
	}
	else 
	{
		u8_addrl_r = 0x80;
	}
//Save APROM data to XRAM
	xd_tmp = 0x280;
	cd_longaddr = (u16_addr&0xff00)+u8_addrl_r;	
	while (xd_tmp !=0x300)
	{
		*xd_tmp = *cd_longaddr;
		looptmp++;
		xd_tmp++;
		cd_longaddr++;
	}
// Modify customer data in XRAM
	u8_addrl_r = u16_addr;
	if (u8_addrl_r<0x80)
	{
		xd_tmp = u8_addrl_r+0x280;
	}
	else
	{
		xd_tmp = u8_addrl_r+0x200;
	}
	*xd_tmp = u8_data;
//Erase APROM DATAFLASH page
		IAPAL = u16_addr;
		IAPAH = u16_addr>>8;
		IAPFD = 0xFF;
	  set_IAPEN; 
		set_APUEN;
    IAPCN = 0x22; 		
 		set_IAPGO; 
//Save changed RAM data to APROM DATAFLASH
	u8_addrl_r = u16_addr;
	if (u8_addrl_r<0x80)
	{
		u8_addrl_r =0;
	}
	else
	{
		u8_addrl_r = 0x80;
	}
		xd_tmp = 0x280;
	  IAPAL = u8_addrl_r;
    IAPAH = u16_addr>>8;
		set_IAPEN; 
		set_APUEN;
	  IAPCN = 0x21;
		while (xd_tmp !=0x2FF)
		{
			IAPFD = *xd_tmp;
			set_IAPGO;
			IAPAL++;
			xd_tmp++;
		}
		clr_APUEN;
		clr_IAPEN;
}	
	
//-------------------------------------------------------------------------
UINT8 read_APROM_BYTE(UINT16 code *u16_addr)
{
	UINT8 rdata;
	rdata = *u16_addr>>8;
	return rdata;
}

void getdata(unsigned char datasize,unsigned char * buf)
{
	unsigned char i;
	for(i=0;i<datasize;i++)
	{
		buf[i] = read_APROM_BYTE ((UINT16 code *)(ADDR_BASE+i));
	}	

}

void savedata (unsigned char datasize,unsigned char * buf)
{
	unsigned char i;
	for(i=0;i<datasize;i++)
	{
		write_DATAFLASH_BYTE (ADDR_BASE + i,buf[i]);
	}
}
#endif

//-----------------------------------------------------------------------------------------------------------
