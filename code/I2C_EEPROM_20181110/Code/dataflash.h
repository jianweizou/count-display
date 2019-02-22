

//***********************************************************************************************************
#define     CID_READ            0x0B
#define     DID_READ            0x0C

/*
	Since the DATAFLASH is in the APROM. Program command is same as program APROM
*/
#define     PAGE_ERASE_LD       0x62
#define     BYTE_READ_LD        0x40
#define     BYTE_PROGRAM_LD	    0x61
#define     PAGE_SIZE           128


#define     ERASE_FAIL          0x70
#define     PROGRAM_FAIL        0x71
#define     IAPFF_FAIL          0x72
#define     IAP_PASS            0x00

//---------------------------------------------------------------
// Following define by customer
// Please confirm the start addresss not over your code size
//---------------------------------------------------------------
#define     DATA_SIZE           128   
#define     DATA_START_ADDR     0x0000 
/********************************************************************************************
 Following IAP command register is also define in SFR_Macro.h
 
	#define set_IAPEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON |= SET_BIT0 ;EA=BIT_TMP
	#define clr_IAPEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON &= ~SET_BIT0;EA=BIT_TMP
	#define set_APUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN |= SET_BIT0 ;EA=BIT_TMP
	#define clr_APUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN &= ~SET_BIT0;EA=BIT_TMP
	
**********************************************************************************************/


void savedata (unsigned char datasize,unsigned int data_addr,unsigned char * buf);
void getdata(unsigned char datasize,unsigned int data_start_addr,unsigned char * buf);