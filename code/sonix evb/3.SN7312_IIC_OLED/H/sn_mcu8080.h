#ifndef _SNC7300_MCU_8080_H_
#define _SNC7300_MCU_8080_H_

#define m_LCM_8080_PIC_SD_Offset	20000

/*********** LCM 128x128 ***********/
//#define mLCM_TG144C31
//#define mLCM_TM014EDZ19

/*********** LCM 320x240 ***********/
#define mLCM_TM024HBZ19

#ifdef mLCM_TM024HBZ19
	#define Origin_Rotation_0		0
	#define Origin_Rotation_90		0
	#define Origin_Rotation_180		0
	#define Origin_Rotation_270		1

	#if (Origin_Rotation_0 || Origin_Rotation_180)
		#define LCM_X_START			0
		#define LCM_X_END			239
		#define LCM_Y_START			0
		#define LCM_Y_END			319
	#elif (Origin_Rotation_90 || Origin_Rotation_270)
		#define LCM_X_START			0
		#define LCM_X_END			319
		#define LCM_Y_START			0
		#define LCM_Y_END			239
	#endif
#endif

extern void MCU_8080_Enable(void);
extern void MCU_8080_Disable(void);
extern void MCU_8080_From_PPU(void);
extern void MCU_8080_Set_DataMode(uint8_t ui_mode);
extern void MCU_8080_Set_Access_Pulse_Duration(uint8_t ui_HighPulse, uint8_t ui_LowPulse);
extern void MCU_8080_Write_Command(uint16_t ui_CMD);
extern void MCU_8080_Write_DataWord_LBFirst(uint16_t ui_Data);
extern void MCU_8080_Write_DataWord_HBFirst(uint16_t ui_Data);
extern void MCU_8080_Write_DataWord(uint16_t ui_Data);
extern uint16_t MCU_8080_Read_DataWord_LBFirst(void);
extern uint16_t MCU_8080_Read_DataWord_HBFirst(void);
extern uint16_t MCU_8080_Read_DataWord(void);
extern void MCU_8080_DMA_Write_Mode(uint8_t ui_Mode, uint32_t* p_ui_WRAMAddr, uint32_t ui_Length);
extern void MCU_8080_DMA_Read_Mode(uint8_t ui_Mode, uint32_t* p_ui_WRAMAddr, uint32_t ui_Length);

#endif
