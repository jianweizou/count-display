/**************************************************************************//**
 * @file     system_SNC7312.h
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Header File
 *           for the SONIX SNC7312 Device
 * @version  V1.0
 * @date     November 2011
 *
 * @note
 * Copyright (C) 2009-2010 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __SYSTEM_SNC7312_H
#define __SYSTEM_SNC7312_H

#include "SNC7312.h"
#include <stdint.h>

/******************************************************************************************/
/* System Clock Source Definition                                                         */
/******************************************************************************************/
// #define SySRst_Flag              SN_SYS0->RST_FLAG
#define SYS_IHRC                    0x0
#define SYS_HXTAL                   0x1		
#define SYS_ILRC                    0x2
#define SYS_LXTAL                   0x3	
#define SYS_SPLL                    0x4

/******************************************************************************************/
/* System Clock Function                                                                  */
/******************************************************************************************/
extern uint8_t IHRC_Enable(void);
extern uint8_t HXTAL_Enable(void);
extern uint8_t LXTAL_Enable(void);
extern uint8_t SPLL_Enable(uint8_t Src);
extern void IHRC_Disable(void);
extern void HXTAL_Disable(void);
extern void LXTAL_Disable(void);
extern void SPLL_Disable(void);
extern void SysClk_Setting(uint8_t Src,uint8_t DIV);
extern void Clk_Output(uint8_t CLKSEL,uint8_t DIV);
extern void PeriClk_Setting(uint8_t DIV);

/******************************************************************************************/
/* System IO Switch Definition                                                            */
/******************************************************************************************/
#define IOSW_SDNF0_Enable            SN_SYS0->IO_SW_b.SDNF0 = 1;
#define IOSW_SDNF0_Disable           SN_SYS0->IO_SW_b.SDNF0 = 0;
#define IOSW_SWD_Enable              SN_SYS0->IO_SW_b.SWD   = 1;
#define IOSW_SWD_Disable             SN_SYS0->IO_SW_b.SWD   = 0;
#define IOSW_SD1_Enable              SN_SYS0->IO_SW_b.SD1   = 1;
#define IOSW_SD1_Disable             SN_SYS0->IO_SW_b.SD1   = 0;
#define IOSW_SPI0_Enable             SN_SYS0->IO_SW_b.SPI0  = 1;
#define IOSW_SPI0_Disable            SN_SYS0->IO_SW_b.SPI0  = 0;
#define IOSW_UART0_Enable            SN_SYS0->IO_SW_b.UART0 = 1;
#define IOSW_UART0_Disable           SN_SYS0->IO_SW_b.UART0 = 0;
#define IOSW_TFT_Enable              SN_SYS0->IO_SW_b.TFT   = 1;
#define IOSW_TFT_Disable             SN_SYS0->IO_SW_b.TFT   = 0;
#define IOSW_CT16_Enable             SN_SYS0->IO_SW_b.CT16PWM = 1;
#define IOSW_CT16_Disable            SN_SYS0->IO_SW_b.CT16PWM = 0;
#define IOSW_OID_Enable              SN_SYS0->IO_SW_b.OID = 1;
#define IOSW_OID_Disable             SN_SYS0->IO_SW_b.OID = 0;
#define IOSW_HOST_Enable             SN_SYS0->IO_SW_b.HOSTPPC = 1;
#define IOSW_HOST_Disable            SN_SYS0->IO_SW_b.HOSTPPC = 0;
	
/**
 * Operation mode & ISO Block
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */

/*----------------------- ISO Backup Registers --------------------------------*/
#define ISO_BK_REG0                  SN_ISO->BK_REG0
#define ISO_BK_REG1                  SN_ISO->BK_REG1
#define ISO_BK_REG2                  SN_ISO->BK_REG2
#define ISO_BK_REG3                  SN_ISO->BK_REG3
#define ISO_BK_REG4                  SN_ISO->BK_REG4
#define ISO_BK_REG5                  SN_ISO->BK_REG5
#define ISO_BK_REG6                  SN_ISO->BK_REG6
#define ISO_BK_REG7                  SN_ISO->BK_REG7
#define ISO_BK_REG8                  SN_ISO->BK_REG8
#define ISO_BK_REG9                  SN_ISO->BK_REG9
#define ISO_BK_REG10                 SN_ISO->BK_REG10
#define ISO_BK_REG11                 SN_ISO->BK_REG11
#define ISO_BK_REG12                 SN_ISO->BK_REG12
#define ISO_BK_REG13                 SN_ISO->BK_REG13
#define ISO_BK_REG14                 SN_ISO->BK_REG14
#define ISO_BK_REG15                 SN_ISO->BK_REG15
#define ISO_BK_REG16                 SN_ISO->BK_REG16
#define ISO_BK_REG17                 SN_ISO->BK_REG17
#define ISO_BK_REG18                 SN_ISO->BK_REG18
#define ISO_BK_REG19                 SN_ISO->BK_REG19
#define ISO_BK_REG20                 SN_ISO->BK_REG20
#define ISO_BK_REG21                 SN_ISO->BK_REG21
#define ISO_BK_REG22                 SN_ISO->BK_REG22
#define ISO_BK_REG23                 SN_ISO->BK_REG23

#define ISO_RTC_Enable()             SN_ISO->ISO_CTRL_b.RTC_EN=1
#define ISO_RTC_Disable()            SN_ISO->ISO_CTRL_b.RTC_EN=0
#define ISO_WKPPin()                 SN_PMU->PMU_CTRL_b.WKP
#define ISO_WKPFlag                  SN_PMU->PMU_CTRL_b.WKP_FLAG
#define ISO_RTCFlag                  SN_PMU->PMU_CTRL_b.RTC_FLAG		

/******************************************************************************************/
/* System Operation Function                                                              */
/******************************************************************************************/
extern void Enter_DPD(void);
extern void Enter_DSLEEP(void);
extern void Enter_SLEEP(void);

extern void Peri_Inital(void);
// extern void LVD_Enable(void);
// extern void LVD_Disable(void);

extern void WDT_RST_Mode(void);
extern void WDT_INT_Mode(void);
extern void WDT_Overflow_time(uint8_t TC);
extern void WDT_1_Sec(void);
extern void WDT_Enable(void);
extern void WDT_Disable(void);
extern void WDT_CLR(void);
extern void WDT_CLR_IRQ(void);

extern void USBPLL_Config(uint8_t value);
extern void USBDev_PowerDown(void);
extern void USBDev_PowerOn(void);
// extern void AIP_PD(void);

/*---------------------------- ISO RTC Setting --------------------------------*/
#define RTC_ILRC                   0x00
#define RTC_LXTAL                  0x01
#define SEC_IE                     0x01//
#define ALM_IE                     0x02//
#define OVF_IE                     0x04//

#define RTC_SEC_IRQ                SN_RTC->RIS_b.SECIF
#define RTC_ALM_IRQ                SN_RTC->RIS_b.ALMIF
#define RTC_OV_IRQ                 SN_RTC->RIS_b.OVFIF
#define RTC_CLR_SECIRQ()           SN_RTC->IC|=0x01
#define RTC_CLR_ALMIRQ()           SN_RTC->IC|=0x02
#define RTC_CLR_OVIRQ()            SN_RTC->IC|=0x04

// extern void ISO_RTC_Config(uint8_t src,uint8_t time);
extern void RTC_Mode(uint8_t CLK_SEL,uint8_t type);
extern void RTC_Sec_Counter(uint32_t cnt);
extern void RTC_Alarm_Counter(uint32_t cnt);
extern void RTC_Enable(void);
extern void RTC_Disable(void);

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
// extern void SystemInit (void);


#endif /* __SYSTEM_SNC7300_H */
