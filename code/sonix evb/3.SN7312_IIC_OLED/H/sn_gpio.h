/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/03
* IC:			      SNC7312
* DESCRIPTION:	GPIO functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		         2013/03/24	   SA2			
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include "SNC7312.h"

#ifndef _SNC7312_GPIO
#define _SNC7312_GPIO

/* GPIO 0 */
void GPIO0_Output_Bit_Setting(uint8_t Bit_No);
void GPIO0_Input_Bit_Setting(uint8_t Bit_No);
void GPIO0_Mode_Setting(uint16_t Mode);
void GPIO0_Data_Setting(uint16_t Data);
void GPIO0_Data_High_Bit_Setting(uint8_t Bit_No);
void GPIO0_Data_Low_Bit_Setting(uint8_t Bit_No);
void GPIO0_Config_Bit_Setting(uint8_t CFG, uint8_t Bit_No);
void GPIO0_Config_Setting(uint32_t CFG);
void GPIO0_Interrupt_BothEdge_Bit_Setting(uint8_t Bit_No);
void GPIO0_Interrupt_FallingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO0_Interrupt_RaisingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO0_Interrupt_HighLevel_Bit_Setting(uint8_t Bit_No);
void GPIO0_Interrupt_LowLevel_Bit_Setting(uint8_t Bit_No);
void GPIO0_Interrupt_Clear_Bit_Setting(uint8_t Bit_No);
void GPIO0_Interrupt_Enable_Bit_Setting(uint8_t Bit_No);
uint8_t GPIO0_Interrupt_Flag_Bit_Check(uint8_t Bit_No);
uint16_t GPIO0_Data_Read(void);
uint8_t GPIO0_Data_Bit_Read(uint8_t Bit_No);

/* GPIO 1 */
void GPIO1_Output_Bit_Setting(uint8_t Bit_No);
void GPIO1_Input_Bit_Setting(uint8_t Bit_No);
void GPIO1_Mode_Setting(uint16_t Mode);
void GPIO1_Data_Setting(uint16_t Data);
void GPIO1_Data_High_Bit_Setting(uint8_t Bit_No);
void GPIO1_Data_Low_Bit_Setting(uint8_t Bit_No);
void GPIO1_Config_Bit_Setting(uint8_t CFG, uint8_t Bit_No);
void GPIO1_Config_Setting(uint32_t CFG);
void GPIO1_Interrupt_BothEdge_Bit_Setting(uint8_t Bit_No);
void GPIO1_Interrupt_FallingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO1_Interrupt_RaisingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO1_Interrupt_HighLevel_Bit_Setting(uint8_t Bit_No);
void GPIO1_Interrupt_LowLevel_Bit_Setting(uint8_t Bit_No);
void GPIO1_Interrupt_Clear_Bit_Setting(uint8_t Bit_No);
void GPIO1_Interrupt_Enable_Bit_Setting(uint8_t Bit_No);
uint8_t GPIO1_Interrupt_Flag_Bit_Check(uint8_t Bit_No);
uint16_t GPIO1_Data_Read(void);
uint8_t GPIO1_Data_Bit_Read(uint8_t Bit_No);

/* GPIO 2 */
void GPIO2_Output_Bit_Setting(uint8_t Bit_No);
void GPIO2_Input_Bit_Setting(uint8_t Bit_No);
void GPIO2_Mode_Setting(uint16_t Mode);
void GPIO2_Data_Setting(uint16_t Data);
void GPIO2_Data_High_Bit_Setting(uint8_t Bit_No);
void GPIO2_Data_Low_Bit_Setting(uint8_t Bit_No);
void GPIO2_Config_Bit_Setting(uint8_t CFG, uint8_t Bit_No);
void GPIO2_Config_Setting(uint32_t CFG);
void GPIO2_Interrupt_BothEdge_Bit_Setting(uint8_t Bit_No);
void GPIO2_Interrupt_FallingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO2_Interrupt_RaisingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO2_Interrupt_HighLevel_Bit_Setting(uint8_t Bit_No);
void GPIO2_Interrupt_LowLevel_Bit_Setting(uint8_t Bit_No);
void GPIO2_Interrupt_Clear_Bit_Setting(uint8_t Bit_No);
void GPIO2_Interrupt_Enable_Bit_Setting(uint8_t Bit_No);
uint8_t GPIO2_Interrupt_Flag_Bit_Check(uint8_t Bit_No);
uint16_t GPIO2_Data_Read(void);
uint8_t GPIO2_Data_Bit_Read(uint8_t Bit_No);

/* GPIO 3 */
void GPIO3_Output_Bit_Setting(uint8_t Bit_No);
void GPIO3_Input_Bit_Setting(uint8_t Bit_No);
void GPIO3_Mode_Setting(uint16_t Mode);
void GPIO3_Data_Setting(uint16_t Data);
void GPIO3_Data_High_Bit_Setting(uint8_t Bit_No);
void GPIO3_Data_Low_Bit_Setting(uint8_t Bit_No);
void GPIO3_Config_Bit_Setting(uint8_t CFG, uint8_t Bit_No);
void GPIO3_Config_Setting(uint32_t CFG);
void GPIO3_Interrupt_BothEdge_Bit_Setting(uint8_t Bit_No);
void GPIO3_Interrupt_FallingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO3_Interrupt_RaisingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO3_Interrupt_HighLevel_Bit_Setting(uint8_t Bit_No);
void GPIO3_Interrupt_LowLevel_Bit_Setting(uint8_t Bit_No);
void GPIO3_Interrupt_Clear_Bit_Setting(uint8_t Bit_No);
void GPIO3_Interrupt_Enable_Bit_Setting(uint8_t Bit_No);
uint8_t GPIO3_Interrupt_Flag_Bit_Check(uint8_t Bit_No);
uint16_t GPIO3_Data_Read(void);
uint8_t GPIO3_Data_Bit_Read(uint8_t Bit_No);

/* GPIO 4 */
void GPIO4_Output_Bit_Setting(uint8_t Bit_No);
void GPIO4_Input_Bit_Setting(uint8_t Bit_No);
void GPIO4_Mode_Setting(uint16_t Mode);
void GPIO4_Data_Setting(uint16_t Data);
void GPIO4_Data_High_Bit_Setting(uint8_t Bit_No);
void GPIO4_Data_Low_Bit_Setting(uint8_t Bit_No);
void GPIO4_Config_Bit_Setting(uint8_t CFG, uint8_t Bit_No);
void GPIO4_Config_Setting(uint32_t CFG);
void GPIO4_Interrupt_BothEdge_Bit_Setting(uint8_t Bit_No);
void GPIO4_Interrupt_FallingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO4_Interrupt_RaisingEdge_Bit_Setting(uint8_t Bit_No);
void GPIO4_Interrupt_HighLevel_Bit_Setting(uint8_t Bit_No);
void GPIO4_Interrupt_LowLevel_Bit_Setting(uint8_t Bit_No);
void GPIO4_Interrupt_Clear_Bit_Setting(uint8_t Bit_No);
void GPIO4_Interrupt_Enable_Bit_Setting(uint8_t Bit_No);
uint8_t GPIO4_Interrupt_Flag_Bit_Check(uint8_t Bit_No);
uint16_t GPIO4_Data_Read(void);
uint8_t GPIO4_Data_Bit_Read(uint8_t Bit_No);

#endif
