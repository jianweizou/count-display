#ifndef __SNC7300_UART_inc_H
#define __SNC7300_UART_inc_H

/*_____ I N C L U D E S ____________________________________________________*/
#include "SNC7312.h"

/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ D E C L A R A T I O N S ____________________________________________*/

void UART0_Init(uint32_t SR);
void UART0_SendByte (uint8_t ucDat);
char UART0_GetByte (void);
void UART0_SendString(char *pt);
void UART1_Init(uint32_t SR);
void UART1_SendByte (uint8_t ucDat);
char UART1_GetByte (void);
void UART1_SendString(char *pt);
void UART0_Pin_Switch_Enable(void);
void UART0_Pin_Switch_Disable(void);

#endif	/* __SNC7300_UART0_H */
