#ifndef __SNC7300_USBDEV_H
#define __SNC7300_USBDEV_H

/*_____ I N C L U D E S ____________________________________________________*/
#include "SNC7312.h"
/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ M A C R O S ________________________________________________________*/

/*_____ D E C L A R A T I O N S ____________________________________________*/
extern uint16_t g_uiPID;
extern uint8_t g_Max_LUN_Num;
extern uint32_t g_uiBulkStrAddr,g_AllHiddenSectorNum;
extern void USB_Default_MSCInfo(void);
extern void USB_MSC_Init(void);
extern void USB_Service(void);


#endif	/*__SNC7300_USBDEV_H*/

