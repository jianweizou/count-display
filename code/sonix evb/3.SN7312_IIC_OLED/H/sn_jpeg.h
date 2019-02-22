#include <stdio.h>
#include "SNC7312.h"

#ifndef _SNC7312_Series_JPEG_inc_H_
#define _SNC7312_Series_JPEG_inc_H_


#define	YCBCR420    0
#define	YCBCR422   	1

#define	DECODER	    0
#define	ENCODER	    1

#define QQVGA_Width      160
#define QVGA_Width       320
#define VGA_Width        640
#define SXGA_Width       1280

extern void JPEG_Insert_Q(void);
extern void JPEG_Init(uint8_t Codec_Type, uint8_t YUV_Format, uint16_t Encode_Width);
extern void JPEG_Enable(void);
extern void JPEG_Disable(void);
extern void JPEG_Set_IF_End(void);
extern uint8_t JPEG_Chk_OF_End(void);
extern void IDMA_JPEG_OUT(uint32_t WRAM_Addr, uint32_t Length);
extern void IDMA_JPEG_IN(uint32_t WRAM_Addr, uint32_t Length);
extern uint8_t Chk_IDMA_JPEG_OUT_DONE(void);
extern uint8_t Chk_IDMA_JPEG_IN_DONE(void);
extern void Stop_IDMA_JPEG_OUT(void);
extern void Stop_IDMA_JPEG_IN(void);
extern void JPEG_IDMA_OUT_INT(void);
extern void JPEG_IDMA_IN_INT(void);
extern uint32_t Get_IDMA_JPEG_OUT_Idx(void);
extern uint32_t Get_IDMA_JPEG_IN_Idx(void);
extern void JPEG_Set_Line_DMA(uint32_t Buf_Addr0, uint32_t Buf_Addr1);
extern uint8_t JPEG_Chk_Line_DMA(void);
extern void JPEG_Stop_Line_DMA(void);
extern void IDMA_CSC_OUT(uint32_t WRAM_Addr, uint32_t Length);
extern void IDMA_CSC_IN(uint32_t WRAM_Addr, uint32_t Length);
extern uint8_t Chk_IDMA_CSC_OUT_DONE(void);
extern uint8_t Chk_IDMA_CSC_IN_DONE(void);


#endif
