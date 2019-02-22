#ifndef _SN_SDRAM_H_
#define _SN_SDRAM_H_
#include "SNC7312.h"
#define SDR_CMD_NOP         0
#define SDR_CMD_PWD_ENT     1
#define SDR_CMD_PWD_EXT     2
#define SDR_CMD_ACT         3
#define SDR_CMD_READ        4 
#define SDR_CMD_WRITE       5
#define SDR_PRE_CH_ALL      6
#define SDR_PRE_CH          7
#define SDR_ARF             8   
#define SDR_SRF_ENT         9 
#define SDR_SRF_EXT         10 
#define SDR_LMR             11
#define SDR_CLK_SUSPEND_ENT 12
#define SDR_CLK_SUSPEND_EXT 13
#define SDR_DQM_EN          14
#define SDR_DQM_DIS         15

// 1 bank size is 1M bytes

#define SDR_BNK0_0       0x20080000 //1 block size is 128k byte 
#define SDR_BNK0_1       0x20090000 //1 block size is 128k byte 
#define SDR_BNK0_2       0x200A0000 //1 block size is 128k byte 
#define SDR_BNK0_3       0x200B0000 //1 block size is 128k byte 
#define SDR_BNK0_4       0x200C0000 //1 block size is 128k byte 
#define SDR_BNK0_5       0x200D0000 //1 block size is 128k byte 
#define SDR_BNK0_6       0x200E0000 //1 block size is 128k byte 
#define SDR_BNK0_7       0x200F0000 //1 block size is 128k byte 
#define SDR_BNK0_8       0x20100000 //1 block size is 128k byte 
#define SDR_BNK0_9       0x20110000 //1 block size is 128k byte 
#define SDR_BNK0_10      0x20120000 //1 block size is 128k byte 
#define SDR_BNK0_11      0x20130000 //1 block size is 128k byte 
#define SDR_BNK0_12      0x20140000 //1 block size is 128k byte 
#define SDR_BNK0_13      0x20150000 //1 block size is 128k byte 
#define SDR_BNK0_14      0x20160000 //1 block size is 128k byte 
#define SDR_BNK0_15      0x20170000 //1 block size is 128k byte 

// 1 bank size as 1M bytes

#define SDR_BNK1_0       0x20180000 //1 block size is 128k byte 
#define SDR_BNK1_1       0x20190000 //1 block size is 128k byte 
#define SDR_BNK1_2       0x201A0000 //1 block size is 128k byte 
#define SDR_BNK1_3       0x201B0000 //1 block size is 128k byte 
#define SDR_BNK1_4       0x201C0000 //1 block size is 128k byte 
#define SDR_BNK1_5       0x201D0000 //1 block size is 128k byte 
#define SDR_BNK1_6       0x201E0000 //1 block size is 128k byte 
#define SDR_BNK1_7       0x201F0000 //1 block size is 128k byte 
#define SDR_BNK1_8       0x20200000 //1 block size is 128k byte 
#define SDR_BNK1_9       0x20210000 //1 block size is 128k byte 
#define SDR_BNK1_10      0x20220000 //1 block size is 128k byte 
#define SDR_BNK1_11      0x20230000 //1 block size is 128k byte 
#define SDR_BNK1_12      0x20240000 //1 block size is 128k byte 
#define SDR_BNK1_13      0x20250000 //1 block size is 128k byte 
#define SDR_BNK1_14      0x20260000 //1 block size is 128k byte 
#define SDR_BNK1_15      0x20270000 //1 block size is 128k byte 

//SDRAM Protect one Block  size 256 Kbyte 
#define SDR_WP_0_ADDR   0x20080000  // protect 1 block size is 256k byte 
#define SDR_WP_1_ADDR   0x200A0000  // protect 1 block size is 256k byte 
#define SDR_WP_2_ADDR   0x200C0000  // protect 1 block size is 256k byte 
#define SDR_WP_3_ADDR   0x200E0000  // protect 1 block size is 256k byte 
#define SDR_WP_4_ADDR   0x20100000  // protect 1 block size is 256k byte 
#define SDR_WP_5_ADDR   0x20120000  // protect 1 block size is 256k byte 
#define SDR_WP_6_ADDR   0x20140000  // protect 1 block size is 256k byte 
#define SDR_WP_7_ADDR   0x20160000  // protect 1 block size is 256k byte 
#define SDR_WP_8_ADDR   0x20180000  // protect 1 block size is 256k byte 
#define SDR_WP_9_ADDR   0x201A0000  // protect 1 block size is 256k byte 
#define SDR_WP_10_ADDR  0x201C0000  // protect 1 block size is 256k byte 
#define SDR_WP_11_ADDR  0x201E0000  // protect 1 block size is 256k byte 
#define SDR_WP_12_ADDR  0x20200000  // protect 1 block size is 256k byte 
#define SDR_WP_13_ADDR  0x20220000  // protect 1 block size is 256k byte 
#define SDR_WP_14_ADDR  0x20240000  // protect 1 block size is 256k byte 
#define SDR_WP_15_ADDR  0x20260000  // protect 1 block size is 256k byte 


// SDRAM Protect Register bit 
#define SDR_WP_0     0x00000001 
#define SDR_WP_1     0x00000002
#define SDR_WP_2     0x00000004
#define SDR_WP_3     0x00000008
#define SDR_WP_4     0x00000010
#define SDR_WP_5     0x00000020
#define SDR_WP_6     0x00000040
#define SDR_WP_7     0x00000080
#define SDR_WP_8     0x00000100
#define SDR_WP_9     0x00000200
#define SDR_WP_10    0x00000400
#define SDR_WP_11    0x00000800
#define SDR_WP_12    0x00001000
#define SDR_WP_13    0x00002000
#define SDR_WP_14    0x00004000
#define SDR_WP_15    0x00008000
#define SDR_WP_ALL   0x0000FFFF

#define B32_MODE    0
#define B16_MODE    1
#define B8_MODE     2

void sdram_enable( void );
void sdram_disable( void );
//void sdram_dly_count(uint8_t tRCD, uint8_t tRP, uint8_t tRC );
void sdram_init(uint16_t ARFCnt, uint16_t SDR_MR, uint8_t SDR_CL ,uint8_t SDR_DLY, uint8_t tRCD, uint8_t tRP, uint8_t tRC);
//void sdram_tune(uint8_t SDR_CL, uint8_t SDR_DLY);
//void sdram_ctrl_init(void);
//void sdram_ctrl_norm(void);
//void sdram_ctrl_pdp(void);
//void sdram_ctrl_srf(void);
//void sdram_array(void);
//void send_sdram_cmd(uint8_t type);
//void sdram_mr(uint16_t info);
//void sdram_arf_cnt(uint16_t cnt);
void sdram_memcpy(void* dest,void *src,uint32_t len);
void sdram_read(void* dest,void *src,uint32_t len);
void sdram_idma(uint32_t dest,uint32_t src,uint32_t Len);
void sdram_clear_write_protect_flag(void);
void sdram_set_write_protect_block(uint32_t block);
#endif
