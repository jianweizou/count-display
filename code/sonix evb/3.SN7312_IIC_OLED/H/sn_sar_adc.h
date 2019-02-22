/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/04
* IC:			      SNC7312
* DESCRIPTION:	GPIO functions.
*____________________________________________________________________________
* REVISION	     Date		       User		  Description
* 1.0		     2016/04/08	   	   SA2			
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/
#ifndef __SNC7312_SAR_ADC_H
#define __SNC7312_SAR_ADC_H

/*_____ I N C L U D E S ____________________________________________________*/
#include "snc7312.h"
/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ M A C R O S ________________________________________________________*/
enum
{
	AIN_DIS,
	AIN0,
	AIN1,
	AIN2,
	AIN3,
 	AIN4,
 	AIN5,
 	AIN0_DI,
 	AIN1_DI,
 	AIN2_DI,
 	AIN3_DI,
 	AIN4_DI,
 	AIN5_DI,
	AIN_VSS,
	AIN_VREF,	
};
enum
{
	SAR_EXTERNAL_VREF,
	SAR_INTERNAL_VREF,
};
enum
{
	SAR_INIT_Disable,
	SAR_INIT_Enable,
};
enum
{
	SAR_NonAUTO,
	SAR_AUTO,
};

/*_____ D E C L A R A T I O N S ____________________________________________*/

extern void SAR_ADC_Enable(void);
extern void SAR_ADC_Disable(void);
extern uint8_t SAR_ADC_CHS(uint8_t ucSelCh);
extern uint8_t SAR_ADC_CKS(uint8_t ucSelCks);
extern void SAR_ADC_BAT_SW(uint8_t ucMode);
extern void SAR_ADC_Auto(uint8_t ucMode);
extern void SAR_ADC_Interrupt_Init(uint8_t ucMode);
extern void SAR_ADC_Start(uint8_t ucMode);
extern uint8_t SAR_ADC_Data_Valid(void);
extern uint8_t SAR_ADC_Data(void);
extern void SAR_ADC_Vref_Select(uint8_t ucMode);

#endif	/*__SNC7312_SAR_ADC_H*/
