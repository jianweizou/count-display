/******************** (C) COPYRIGHT 2016 SONiX *******************************
* COMPANY:		  SONiX
* DATE:			    2016/04
* IC:			      SNC7312
* DESCRIPTION:	dsp functions.
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
#ifndef __SNC7312_DSP
#define __SNC7312_DSP

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include "snc7312.h"

/*_____ D E F I N I T I O N S ______________________________________________*/
#define DSP_CMD_ADDR 0x20001FC0
#define DSPCMD ((SN_DSPCMD_Type *)(DSP_CMD_ADDR))
#define DSP_Trig *((uint32_t *)(0x30000000))

/*_____ M A C R O S ________________________________________________________*/

enum
{
	DSP_SHIFT_HIGH,
	DSP_SHIFT_LOW,
};
enum
{
	NULL_FUN,// 0
	DSP_PRAM_READY,
	DSP_RESET,
	DSP_ROM_CHECKSUM,
	DSP_MEMORY_COPY_SCALING,
	DSP_DATA_SHIFT,  //5
//---------------------------------------------------
	RW_SEQINBUF_LOAD,
	RW_SEQINBUF_SAVE,
	IMAENC_OUT_INIT,
	IMAENC_PROCESS,									
	IMAENC_BITRATE,
	IMAENC_DATANUM,
	IMAADPCM_ENCODE_CHL,
	IMADEC_BITRATE,
	IMADEC_OUT_INIT,
	IMADEC_PROCESS,
  IMAADPCM_DECODE_CHL, //16	
//---------------------------------------------------
	MSADPCM_INIT,										
	MSADPCMENC_PROCESS,
	MSADPCMENC_PROCESS_CHL,
	MSADPCMDEC_INIT_CHL,
	MSADPCMDEC_PROCESS_CHL, 
	MSADPCMDEC_CHL,
	MSADPCMDEC_INIT_CHR,
	MSADPCMDEC_PROCESS_CHR,	
	MSADPCMDEC_CHR,	//25
//---------------------------------------------------
	AUDIO32_ENC_MODE_SWITCH,
	AUDIO32_ENC_PROCESS,
	AUDIO32_ENC_BITRATE_SETTING,
	AUDIO32_ENC_OUT_INIT,
	AUDIO32_ENC_FILL_IN_BUF1,
	AUDIO32_ENC_FILL_IN_BUF2,
	AUDIO32_ENCODE_CHL,
	AUDIO32_MODE_SWITCH,
	AUDIO32_DEC_PARA_SET_CHL,
	AUDIO32_DEC_OUTPUT_CHL,
	AUDIO32_DEC_PROCESS_CHL,
	AUDIO32_DECCODE_CHL,						
	AUDIO32_DEC_PARA_SET_CHR,
	AUDIO32_DEC_OUTPUT_CHR,				
	AUDIO32_DEC_PROCESS_CHR,
	AUDIO32_DECCODE_CHR,//41
//----------------------------------------------------
	AGC_INIT,
	AGC_PROCESS, //43
//---------------------------------------------------
	AEC_ENGINE_INIT,
	AEC_ENGINE_PROCESS,
	AEC_ENGINE_OUT_INIT,
	AEC_ENGINE_PARAMSETTING,
	AEC_ENGINE_SETOVER64KRAMBANK,
	AEC_BUFFER_IDX_LOAD,
	AEC_BUFFER_IDX_SAVE,
	AEC_BUFFER_IDX_LOAD_REF,
	AEC_BUFFER_IDX_SAVE_REF,
	AEC_FUNCTION,//53
//---------------------------------------------------
	MP3_ENGINE_INIT,								
	MP3_SET_CHANNEL,				
	MP3_BUFFER_IDX_LOAD,
	MP3_BUFFER_IDX_SAVE,
	MP3_BUFFER_ADJUST,
	MP3_BUFFER_END,									
	MP3_ENGINE_PROCESS,//60
	MP3_ENGINE_END,
	MP3_ENGINE_GET_SUB_FRM_IDX,
	MP3_ENGINE_SEEK_FAFRM,
	MP3_ENGINE_GET_SEGDUR,					
	MP3_ENGINE_SEEKBASEG,//65
	MP3_ENGINE_CHGSPD_INIT,
	MP3_CHGSPD_IDX_LOAD,
	MP3_CHGSPD_DECODE_PROCESS,
	MP3_ENGINE_DECODE_PROCESS,
	MP3_CHGSPD_IDX_SAVE,//70
	MP3_CHGSPD_GET_STATUS,					
	MP3_CHGSPD_PROCESS,
	MP3_ENGINE_GET_BITRATE,
	MP3_ENGINE_GET_PLAYTIME,  //74	
};

typedef struct {
	uint16_t CMD;
  
	uint16_t RetStatus;	
	uint32_t PARA1;
	uint32_t PARA2;
	uint32_t PARA3;
	uint32_t PARA4;
	uint32_t PARA5;
	uint32_t PARA6;
	uint32_t PARA7;
	uint32_t PARA8;
	uint32_t PARA9;

   // DSP To M0
	uint32_t  IRQ_State;
	
	uint32_t   Return1;     // 22
	uint32_t   Return2;     // 24
	uint32_t   Return3;     // 26
	uint32_t   Return4;     // 28
	uint32_t   Return5;     // 30
} SN_DSPCMD_Type;

/*_____ D E C L A R A T I O N S ____________________________________________*/

extern uint16_t g_DSP_Flag;	

extern void DSP_Enable(void);
extern void DSP_Hold(void);
extern void DSP_Reset(void);
extern void DSP_PRAM_Ready(uint16_t ModuleID, uint32_t PRAM_Addr);
extern void Ext_DSP_PRAM_Ready(uint16_t ModuleID, uint32_t PRAM_Addr);
extern void DSP_Memory_Copy_Scaling(uint16_t* SrcAddr,uint16_t* DestAddr, uint16_t DataLen, uint16_t ScaFac);
extern void DSP_Data_Shift(uint16_t* SrcAddr, uint16_t DataLenWord, uint16_t ShiftWord, uint16_t ShiftDir);
extern uint32_t DSP_Rom_Checksum(void);
extern void DSP_Dual_Port_Trig(void);
extern uint16_t DSP_Polling(void);
extern void DSP_Write_CMD(uint16_t ucDspCmd);
#endif //__SNC7312_DSP
