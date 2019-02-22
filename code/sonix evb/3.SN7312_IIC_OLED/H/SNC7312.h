
/****************************************************************************************************//**
 * @file     SNC7312.h
 *
 * @brief    CMSIS Cortex-M0 Core Peripheral Access Layer Header File for
 *           default SNC7312 Device Series
 *
 * @version  V1.0
 * @date     23. Feb 2016
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *           
 *           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. 
 *
 *******************************************************************************************************/



/** @addtogroup SONiX Technology Co., Ltd.
  * @{
  */

/** @addtogroup SNC7312
  * @{
  */

#ifndef STC7312_H
#define STC7312_H

#ifdef __cplusplus
extern "C" {
#endif

#define SET_BIT0 	       0x00000001
#define SET_BIT1   	       0x00000002
#define SET_BIT2   	       0x00000004
#define SET_BIT3  	       0x00000008
#define SET_BIT4  	       0x00000010
#define SET_BIT5  	       0x00000020
#define SET_BIT6  	       0x00000040
#define SET_BIT7  	       0x00000080
#define SET_BIT8  	       0x00000100
#define SET_BIT9  	       0x00000200
#define SET_BIT10 	       0x00000400
#define SET_BIT11 	       0x00000800
#define SET_BIT12 	       0x00001000
#define SET_BIT13 	       0x00002000
#define SET_BIT14 	       0x00004000
#define SET_BIT15 	       0x00008000
#define SET_BIT16 	       0x00010000
#define SET_BIT17 	       0x00020000
#define SET_BIT18 	       0x00040000
#define SET_BIT19 	       0x00080000
#define SET_BIT20 	       0x00100000
#define SET_BIT21 	       0x00200000
#define SET_BIT22 	       0x00400000
#define SET_BIT23 	       0x00800000
#define SET_BIT24 	       0x01000000
#define SET_BIT25 	       0x02000000
#define SET_BIT26 	       0x04000000
#define SET_BIT27 	       0x08000000
#define SET_BIT28 	       0x10000000
#define SET_BIT29 	       0x20000000
#define SET_BIT30 	       0x40000000
#define SET_BIT31 	       0x80000000
	
	
/* -------------------------  Interrupt Number Definition  ------------------------------------------------------------------- */

typedef enum {
/* -------------------  Cortex-M0 Processor Exceptions Numbers  -------------------------------------------------------------- */
    Reset_IRQn                  = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
    NonMaskableInt_IRQn         = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
    HardFault_IRQn              = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
    SVCall_IRQn                 =  -5,              /*!<  11  System Service Call via SVC instruction                          */
    DebugMonitor_IRQn           =  -4,              /*!<  12  Debug Monitor                                                    */
    PendSV_IRQn                 =  -2,              /*!<  14  Pendable request for system service                              */
    SysTick_IRQn                =  -1,              /*!<  15  System Tick Timer                                                */
/* ---------------------  SNC7312 Specific Interrupt Numbers  ---------------------------------------------------------------- */
	MPU_IRQn					= 	0,				/*!<   0  MPU                                                              */
	DSP_Issue_IRQn				= 	1,				/*!<   1  DSP Issue                                                        */
	USBDEV_IRQn					=	2,				/*!<   2  USB Dec															*/
	CIS_IRQn					= 	3,				/*!<   3  CIS																*/
	PPU_HBLK_IRQn				= 	4,				/*!<   4  PPU_HBLK                                                         */
	SD_DAC_IRQn					=	5,				/*!<   5  SD DAC 			                                               */
	SD_ADC_IRQn					= 	6,				/*!<   6  SD ADC															*/
	DMA_SDNF1_IRQn				=	7,				/*!<   7  DMA SD_CARD1 | NF                                                */
	SPI1_IRQn					=	8,				/*!<   8  SPI1																*/
	I2S2_IRQn					=   9,				/*!<   9  I2S_2																*/
	DMA_CSC_IRQn				=  10,				/*!<  10  CSC_DMA															*/
	DMA_JPEG_IRQn				=  11,				/*!<  11  JPEG_DMA															*/
	CIS_VSYNC_IRQn				=  12,				/*!<  12  TFT																*/
	SPI0_IRQn                   =  13,              /*!<  13  SPI0                                                             */
	PPU_VBLK_IRQn               =  14,              /*!<  14  PPU_HBLK                                                         */
	I2C_IRQn                    =  15,              /*!<  15  I2C                                                              */
    CT16B0_IRQn                 =  16,              /*!<  16  CT16B0                                                           */
    CT16B1_IRQn                 =  17,              /*!<  17  CT16B1                                                           */
    CT32B0_IRQn                 =  18,              /*!<  18  CT32B0                                                           */
    CT32B1_IRQn                 =  19,              /*!<  19  CT32B1                                                           */
	P4_WKP_IRQn                 =  20,              /*!<  20  P4 | KEY_WKP                                                     */	
    UART0_IRQn                 	=  21,              /*!<  21  UART0                                                            */
	NFECC_IRQn					=  22,				/*!<  22  NFECC                                                            */
	DMA_SDNF0_IRQn				=  23,				/*!<  23  DMA SD_CARD0 | NF                                                */
	SAR_ADC_IRQn				=  24,				/*!<  24  SAR ADC                                                          */
	WDT_UART1_IRQn              =  25,              /*!<  25  WDT | UART1                                                      */
    USBHOST_IRQn                =  26,              /*!<  26  USB HOST                                                         */
    RTC_IRQn                    =  27,              /*!<  27  RTC | ISO_RTC                                                    */
	P3_IRQn                     =  28,              /*!<  28  P3                                                               */
    P2_IRQn                     =  29,              /*!<  29  P2                                                               */
	P1_IRQn                     =  30,              /*!<  30  P1                                                               */
	P0_IRQn                     =  31,              /*!<  31  P0                                                               */
	
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* =========================================================================================================================== */
/* ====================================       Processor and Core Peripheral Section     ====================================== */
/* =========================================================================================================================== */

/* ------------------------------Configuration of the Cortex-M0 Processor and Core Peripherals-------------------------------- */
#define __CM0_REV                 0x0000            /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS               2            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include <core_cm0.h>                               /*!< Cortex-M0 processor and core peripherals                              */


typedef int32_t  s32;
typedef int16_t  s16;
typedef int8_t    s8;

typedef const int32_t sc32; 
typedef const int16_t sc16; 
typedef const int8_t   sc8;  

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t    vs8;

typedef __I int32_t  vsc32; 
typedef __I int16_t  vsc16; 
typedef __I int8_t    vsc8;  

typedef uint32_t       u32;
typedef uint16_t       u16;
typedef uint8_t         u8;

typedef const uint32_t uc32; 
typedef const uint16_t uc16; 
typedef const uint8_t   uc8;   

typedef __IO uint32_t  vu32;
typedef __IO uint16_t  vu16;
typedef __IO uint8_t    vu8;

typedef __I uint32_t vuc32; 
typedef __I uint16_t vuc16; 
typedef __I uint8_t   vuc8;  



/* =========================================================================================================================== */
/* ====================================       Device Specific Peripheral Section       ======================================= */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ====================================                    SN_GPIO0                    ======================================= */
/* =========================================================================================================================== */
/**
  * @brief General Purpose I/O (SN_GPIO0)
  */

typedef struct {                                    /*!< SN_GPIO0 Structure                                                    */
  
  union {
    __IO uint32_t  DATA;                            /*!< Offset:0x00 GPIO Port n Data Register                                 */
    
    struct {
      __IO uint32_t  DATA0      :  1;               /*!< Data of Pn.0                                                          */
      __IO uint32_t  DATA1      :  1;               /*!< Data of Pn.1                                                          */
      __IO uint32_t  DATA2      :  1;               /*!< Data of Pn.2                                                          */
      __IO uint32_t  DATA3      :  1;               /*!< Data of Pn.3                                                          */
      __IO uint32_t  DATA4      :  1;               /*!< Data of Pn.4                                                          */
      __IO uint32_t  DATA5      :  1;               /*!< Data of Pn.5                                                          */
      __IO uint32_t  DATA6      :  1;               /*!< Data of Pn.6                                                          */
      __IO uint32_t  DATA7      :  1;               /*!< Data of Pn.7                                                          */
      __IO uint32_t  DATA8      :  1;               /*!< Data of Pn.8                                                          */
      __IO uint32_t  DATA9      :  1;               /*!< Data of Pn.9                                                          */
      __IO uint32_t  DATA10     :  1;               /*!< Data of Pn.10                                                         */
      __IO uint32_t  DATA11     :  1;               /*!< Data of Pn.11                                                         */
      __IO uint32_t  DATA12     :  1;               /*!< Data of Pn.12                                                         */
      __IO uint32_t  DATA13     :  1;               /*!< Data of Pn.13                                                         */
      __IO uint32_t  DATA14     :  1;               /*!< Data of Pn.14                                                         */
      __IO uint32_t  DATA15     :  1;               /*!< Data of Pn.15                                                         */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MODE;                            /*!< Offset:0x04 GPIO Port n Mode Register                                 */
    
    struct {
      __IO uint32_t  MODE0      :  1;               /*!< Mode of Pn.0                                                          */
      __IO uint32_t  MODE1      :  1;               /*!< Mode of Pn.1                                                          */
      __IO uint32_t  MODE2      :  1;               /*!< Mode of Pn.2                                                          */
      __IO uint32_t  MODE3      :  1;               /*!< Mode of Pn.3                                                          */
      __IO uint32_t  MODE4      :  1;               /*!< Mode of Pn.4                                                          */
      __IO uint32_t  MODE5      :  1;               /*!< Mode of Pn.5                                                          */
      __IO uint32_t  MODE6      :  1;               /*!< Mode of Pn.6                                                          */
      __IO uint32_t  MODE7      :  1;               /*!< Mode of Pn.7                                                          */
      __IO uint32_t  MODE8      :  1;               /*!< Mode of Pn.8                                                          */
      __IO uint32_t  MODE9      :  1;               /*!< Mode of Pn.9                                                          */
      __IO uint32_t  MODE10     :  1;               /*!< Mode of Pn.10                                                         */
      __IO uint32_t  MODE11     :  1;               /*!< Mode of Pn.11                                                         */
      __IO uint32_t  MODE12     :  1;               /*!< Mode of Pn.12                                                         */
      __IO uint32_t  MODE13     :  1;               /*!< Mode of Pn.13                                                         */
      __IO uint32_t  MODE14     :  1;               /*!< Mode of Pn.14                                                         */
      __IO uint32_t  MODE15     :  1;               /*!< Mode of Pn.15                                                         */
    } MODE_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x08 GPIO Port n Configuration Register                        */
    
    struct {
      __IO uint32_t  CFG0       :  2;               /*!< Configuration of Pn.0                                                 */
      __IO uint32_t  CFG1       :  2;               /*!< Configuration of Pn.1                                                 */
      __IO uint32_t  CFG2       :  2;               /*!< Configuration of Pn.2                                                 */
      __IO uint32_t  CFG3       :  2;               /*!< Configuration of Pn.3                                                 */
      __IO uint32_t  CFG4       :  2;               /*!< Configuration of Pn.4                                                 */
      __IO uint32_t  CFG5       :  2;               /*!< Configuration of Pn.5                                                 */
      __IO uint32_t  CFG6       :  2;               /*!< Configuration of Pn.6                                                 */
      __IO uint32_t  CFG7       :  2;               /*!< Configuration of Pn.7                                                 */
      __IO uint32_t  CFG8       :  2;               /*!< Configuration of Pn.8                                                 */
      __IO uint32_t  CFG9       :  2;               /*!< Configuration of Pn.9                                                 */
      __IO uint32_t  CFG10      :  2;               /*!< Configuration of Pn.10                                                */
      __IO uint32_t  CFG11      :  2;               /*!< Configuration of Pn.11                                                */
      __IO uint32_t  CFG12      :  2;               /*!< Configuration of Pn.12                                                */
      __IO uint32_t  CFG13      :  2;               /*!< Configuration of Pn.13                                                */
      __IO uint32_t  CFG14      :  2;               /*!< Configuration of Pn.14                                                */
      __IO uint32_t  CFG15      :  2;               /*!< Configuration of Pn.15                                                */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IS;                              /*!< Offset:0x0C GPIO Port n Interrupt Sense Register                      */
    
    struct {
      __IO uint32_t  IS0        :  1;               /*!< Interrupt on Pn.0 is event or edge sensitive                          */
      __IO uint32_t  IS1        :  1;               /*!< Interrupt on Pn.1 is event or edge sensitive                          */
      __IO uint32_t  IS2        :  1;               /*!< Interrupt on Pn.2 is event or edge sensitive                          */
      __IO uint32_t  IS3        :  1;               /*!< Interrupt on Pn.3 is event or edge sensitive                          */
      __IO uint32_t  IS4        :  1;               /*!< Interrupt on Pn.4 is event or edge sensitive                          */
      __IO uint32_t  IS5        :  1;               /*!< Interrupt on Pn.5 is event or edge sensitive                          */
      __IO uint32_t  IS6        :  1;               /*!< Interrupt on Pn.6 is event or edge sensitive                          */
      __IO uint32_t  IS7        :  1;               /*!< Interrupt on Pn.7 is event or edge sensitive                          */
      __IO uint32_t  IS8        :  1;               /*!< Interrupt on Pn.8 is event or edge sensitive                          */
      __IO uint32_t  IS9        :  1;               /*!< Interrupt on Pn.9 is event or edge sensitive                          */
      __IO uint32_t  IS10       :  1;               /*!< Interrupt on Pn.10 is event or edge sensitive                         */
      __IO uint32_t  IS11       :  1;               /*!< Interrupt on Pn.11 is event or edge sensitive                         */
      __IO uint32_t  IS12       :  1;               /*!< Interrupt on Pn.12 is event or edge sensitive                         */
      __IO uint32_t  IS13       :  1;               /*!< Interrupt on Pn.13 is event or edge sensitive                         */
      __IO uint32_t  IS14       :  1;               /*!< Interrupt on Pn.14 is event or edge sensitive                         */
      __IO uint32_t  IS15       :  1;               /*!< Interrupt on Pn.15 is event or edge sensitive                         */
    } IS_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IBS;                             /*!< Offset:0x10 GPIO Port n Interrupt Both-edge Sense Register            */
    
    struct {
      __IO uint32_t  IBS0       :  1;               /*!< Interrupt on Pn.0 is triggered ob both edges                          */
      __IO uint32_t  IBS1       :  1;               /*!< Interrupt on Pn.1 is triggered ob both edges                          */
      __IO uint32_t  IBS2       :  1;               /*!< Interrupt on Pn.2 is triggered ob both edges                          */
      __IO uint32_t  IBS3       :  1;               /*!< Interrupt on Pn.3 is triggered ob both edges                          */
      __IO uint32_t  IBS4       :  1;               /*!< Interrupt on Pn.4 is triggered ob both edges                          */
      __IO uint32_t  IBS5       :  1;               /*!< Interrupt on Pn.5 is triggered ob both edges                          */
      __IO uint32_t  IBS6       :  1;               /*!< Interrupt on Pn.6 is triggered ob both edges                          */
      __IO uint32_t  IBS7       :  1;               /*!< Interrupt on Pn.7 is triggered ob both edges                          */
      __IO uint32_t  IBS8       :  1;               /*!< Interrupt on Pn.8 is triggered ob both edges                          */
      __IO uint32_t  IBS9       :  1;               /*!< Interrupt on Pn.9 is triggered ob both edges                          */
      __IO uint32_t  IBS10      :  1;               /*!< Interrupt on Pn.10 is triggered ob both edges                         */
      __IO uint32_t  IBS11      :  1;               /*!< Interrupt on Pn.11 is triggered ob both edges                         */
      __IO uint32_t  IBS12      :  1;               /*!< Interrupt on Pn.12 is triggered ob both edges                         */
      __IO uint32_t  IBS13      :  1;               /*!< Interrupt on Pn.13 is triggered ob both edges                         */
      __IO uint32_t  IBS14      :  1;               /*!< Interrupt on Pn.14 is triggered ob both edges                         */
      __IO uint32_t  IBS15      :  1;               /*!< Interrupt on Pn.15 is triggered ob both edges                         */
    } IBS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IEV;                             /*!< Offset:0x14 GPIO Port n Interrupt Event Register                      */
    
    struct {
      __IO uint32_t  IEV0       :  1;               /*!< Interrupt trigged evnet on Pn.0                                       */
      __IO uint32_t  IEV1       :  1;               /*!< Interrupt trigged evnet on Pn.1                                       */
      __IO uint32_t  IEV2       :  1;               /*!< Interrupt trigged evnet on Pn.2                                       */
      __IO uint32_t  IEV3       :  1;               /*!< Interrupt trigged evnet on Pn.3                                       */
      __IO uint32_t  IEV4       :  1;               /*!< Interrupt trigged evnet on Pn.4                                       */
      __IO uint32_t  IEV5       :  1;               /*!< Interrupt trigged evnet on Pn.5                                       */
      __IO uint32_t  IEV6       :  1;               /*!< Interrupt trigged evnet on Pn.6                                       */
      __IO uint32_t  IEV7       :  1;               /*!< Interrupt trigged evnet on Pn.7                                       */
      __IO uint32_t  IEV8       :  1;               /*!< Interrupt trigged evnet on Pn.8                                       */
      __IO uint32_t  IEV9       :  1;               /*!< Interrupt trigged evnet on Pn.9                                       */
      __IO uint32_t  IEV10      :  1;               /*!< Interrupt trigged evnet on Pn.10                                      */
      __IO uint32_t  IEV11      :  1;               /*!< Interrupt trigged evnet on Pn.11                                      */
      __IO uint32_t  IEV12      :  1;               /*!< Interrupt trigged evnet on Pn.12                                      */
      __IO uint32_t  IEV13      :  1;               /*!< Interrupt trigged evnet on Pn.13                                      */
      __IO uint32_t  IEV14      :  1;               /*!< Interrupt trigged evnet on Pn.14                                      */
      __IO uint32_t  IEV15      :  1;               /*!< Interrupt trigged evnet on Pn.15                                      */
    } IEV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x18 GPIO Port n Interrupt Enable Register                     */
    
    struct {
      __IO uint32_t  IE0        :  1;               /*!< Interrupt on Pn.0 enable                                              */
      __IO uint32_t  IE1        :  1;               /*!< Interrupt on Pn.1 enable                                              */
      __IO uint32_t  IE2        :  1;               /*!< Interrupt on Pn.2 enable                                              */
      __IO uint32_t  IE3        :  1;               /*!< Interrupt on Pn.3 enable                                              */
      __IO uint32_t  IE4        :  1;               /*!< Interrupt on Pn.4 enable                                              */
      __IO uint32_t  IE5        :  1;               /*!< Interrupt on Pn.5 enable                                              */
      __IO uint32_t  IE6        :  1;               /*!< Interrupt on Pn.6 enable                                              */
      __IO uint32_t  IE7        :  1;               /*!< Interrupt on Pn.7 enable                                              */
      __IO uint32_t  IE8        :  1;               /*!< Interrupt on Pn.8 enable                                              */
      __IO uint32_t  IE9        :  1;               /*!< Interrupt on Pn.9 enable                                              */
      __IO uint32_t  IE10       :  1;               /*!< Interrupt on Pn.10 enable                                             */
      __IO uint32_t  IE11       :  1;               /*!< Interrupt on Pn.11 enable                                             */
      __IO uint32_t  IE12       :  1;               /*!< Interrupt on Pn.11 enable                                             */
      __IO uint32_t  IE13       :  1;               /*!< Interrupt on Pn.13 enable                                             */
      __IO uint32_t  IE14       :  1;               /*!< Interrupt on Pn.14 enable                                             */
      __IO uint32_t  IE15       :  1;               /*!< Interrupt on Pn.15 enable                                             */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x1C GPIO Port n Raw Interrupt Status Register                 */
    
    struct {
      __I  uint32_t  IF0        :  1;               /*!< Pn.0 raw interrupt flag                                               */
      __I  uint32_t  IF1        :  1;               /*!< Pn.1 raw interrupt flag                                               */
      __I  uint32_t  IF2        :  1;               /*!< Pn.2 raw interrupt flag                                               */
      __I  uint32_t  IF3        :  1;               /*!< Pn.3 raw interrupt flag                                               */
      __I  uint32_t  IF4        :  1;               /*!< Pn.4 raw interrupt flag                                               */
      __I  uint32_t  IF5        :  1;               /*!< Pn.5 raw interrupt flag                                               */
      __I  uint32_t  IF6        :  1;               /*!< Pn.6 raw interrupt flag                                               */
      __I  uint32_t  IF7        :  1;               /*!< Pn.7 raw interrupt flag                                               */
      __I  uint32_t  IF8        :  1;               /*!< Pn.8 raw interrupt flag                                               */
      __I  uint32_t  IF9        :  1;               /*!< Pn.9 raw interrupt flag                                               */
      __I  uint32_t  IF10       :  1;               /*!< Pn.10 raw interrupt flag                                              */
      __I  uint32_t  IF11       :  1;               /*!< Pn.11 raw interrupt flag                                              */
      __I  uint32_t  IF12       :  1;               /*!< Pn.12 raw interrupt flag                                              */
      __I  uint32_t  IF13       :  1;               /*!< Pn.13 raw interrupt flag                                              */
      __I  uint32_t  IF14       :  1;               /*!< Pn.14 raw interrupt flag                                              */
      __I  uint32_t  IF15       :  1;               /*!< Pn.15 raw interrupt flag                                              */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x20 GPIO Port n Interrupt Clear Register                      */
    
    struct {
      __O  uint32_t  IC0        :  1;               /*!< Pn.0 interrupt flag clear                                             */
      __O  uint32_t  IC1        :  1;               /*!< Pn.1 interrupt flag clear                                             */
      __O  uint32_t  IC2        :  1;               /*!< Pn.2 interrupt flag clear                                             */
      __O  uint32_t  IC3        :  1;               /*!< Pn.3 interrupt flag clear                                             */
      __O  uint32_t  IC4        :  1;               /*!< Pn.4 interrupt flag clear                                             */
      __O  uint32_t  IC5        :  1;               /*!< Pn.5 interrupt flag clear                                             */
      __O  uint32_t  IC6        :  1;               /*!< Pn.6 interrupt flag clear                                             */
      __O  uint32_t  IC7        :  1;               /*!< Pn.7 interrupt flag clear                                             */
      __O  uint32_t  IC8        :  1;               /*!< Pn.8 interrupt flag clear                                             */
      __O  uint32_t  IC9        :  1;               /*!< Pn.9 interrupt flag clear                                             */
      __O  uint32_t  IC10       :  1;               /*!< Pn.10 interrupt flag clear                                            */
      __O  uint32_t  IC11       :  1;               /*!< Pn.11 interrupt flag clear                                            */
      __O  uint32_t  IC12       :  1;               /*!< Pn.12 interrupt flag clear                                            */
      __O  uint32_t  IC13       :  1;               /*!< Pn.13 interrupt flag clear                                            */
      __O  uint32_t  IC14       :  1;               /*!< Pn.14 interrupt flag clear                                            */
      __O  uint32_t  IC15       :  1;               /*!< Pn.15 interrupt flag clear                                            */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BSET;                            /*!< Offset:0x24 GPIO Port n Bits Set Operation Register                   */
    
    struct {
      __O  uint32_t  BSET0      :  1;               /*!< Set Pn.0                                                              */
      __O  uint32_t  BSET1      :  1;               /*!< Set Pn.1                                                              */
      __O  uint32_t  BSET2      :  1;               /*!< Set Pn.2                                                              */
      __O  uint32_t  BSET3      :  1;               /*!< Set Pn.3                                                              */
      __O  uint32_t  BSET4      :  1;               /*!< Set Pn.4                                                              */
      __O  uint32_t  BSET5      :  1;               /*!< Set Pn.5                                                              */
      __O  uint32_t  BSET6      :  1;               /*!< Set Pn.6                                                              */
      __O  uint32_t  BSET7      :  1;               /*!< Set Pn.7                                                              */
      __O  uint32_t  BSET8      :  1;               /*!< Set Pn.8                                                              */
      __O  uint32_t  BSET9      :  1;               /*!< Set Pn.9                                                              */
      __O  uint32_t  BSET10     :  1;               /*!< Set Pn.10                                                             */
      __O  uint32_t  BSET11     :  1;               /*!< Set Pn.11                                                             */
      __O  uint32_t  BSET12     :  1;               /*!< Set Pn.12                                                             */
      __O  uint32_t  BSET13     :  1;               /*!< Set Pn.13                                                             */
      __O  uint32_t  BSET14     :  1;               /*!< Set Pn.14                                                             */
      __O  uint32_t  BSET15     :  1;               /*!< Set Pn.15                                                             */
    } BSET_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BCLR;                            /*!< Offset:0x28 GPIO Port n Bits Clear Operation Register                 */
    
    struct {
      __O  uint32_t  BCLR0      :  1;               /*!< Clear Pn.0                                                            */
      __O  uint32_t  BCLR1      :  1;               /*!< Clear Pn.1                                                            */
      __O  uint32_t  BCLR2      :  1;               /*!< Clear Pn.2                                                            */
      __O  uint32_t  BCLR3      :  1;               /*!< Clear Pn.3                                                            */
      __O  uint32_t  BCLR4      :  1;               /*!< Clear Pn.4                                                            */
      __O  uint32_t  BCLR5      :  1;               /*!< Clear Pn.5                                                            */
      __O  uint32_t  BCLR6      :  1;               /*!< Clear Pn.6                                                            */
      __O  uint32_t  BCLR7      :  1;               /*!< Clear Pn.7                                                            */
      __O  uint32_t  BCLR8      :  1;               /*!< Clear Pn.8                                                            */
      __O  uint32_t  BCLR9      :  1;               /*!< Clear Pn.9                                                            */
      __O  uint32_t  BCLR10     :  1;               /*!< Clear Pn.10                                                           */
      __O  uint32_t  BCLR11     :  1;               /*!< Clear Pn.11                                                           */
      __O  uint32_t  BCLR12     :  1;               /*!< Clear Pn.12                                                           */
      __O  uint32_t  BCLR13     :  1;               /*!< Clear Pn.13                                                           */
      __O  uint32_t  BCLR14     :  1;               /*!< Clear Pn.14                                                           */
      __O  uint32_t  BCLR15     :  1;               /*!< Clear Pn.15                                                           */
    } BCLR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ODCTRL;                          /*!< Offset:0x2C GPIO Port n Open-drain Control Register                   */
    
    struct {
      __IO uint32_t  Pn0OC      :  1;               /*!< Pn.0 open-drain control                                               */
      __IO uint32_t  Pn1OC      :  1;               /*!< Pn.1 open-drain control                                               */
      __IO uint32_t  Pn2OC      :  1;               /*!< Pn.2 open-drain control                                               */
      __IO uint32_t  Pn3OC      :  1;               /*!< Pn.3 open-drain control                                               */
           uint32_t             :  8;
      __IO uint32_t  Pn12OC     :  1;               /*!< Pn.12 open-drain control                                              */
      __IO uint32_t  Pn13OC     :  1;               /*!< Pn.13 open-drain control                                              */
      __IO uint32_t  Pn14OC     :  1;               /*!< Pn.14 open-drain control                                              */
      __IO uint32_t  Pn15OC     :  1;               /*!< Pn.15 open-drain control                                              */
    } ODCTRL_b;                                     /*!< BitSize                                                               */
  };
} SN_GPIO0_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_WDT                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief Watchdog Timer (SN_WDT)
  */

typedef struct {                                    /*!< SN_WDT Structure                                                      */
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x00 WDT Configuration Register                                */
    
    struct {
      __IO uint32_t  WDTEN      :  1;               /*!< WDT enable                                                            */
      __IO uint32_t  WDTIE      :  1;               /*!< WDT interrupt enable                                                  */
      __IO uint32_t  WDTINT     :  1;               /*!< WDT interrupt flag                                                    */
           uint32_t             : 13;
      __O  uint32_t  WDKEY      : 16;               /*!< Watchdog register key                                                 */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKSOURCE;                       /*!< Offset:0x04 WDT Clock Source Register                                 */
    
    struct {
      __IO uint32_t  CLKSOURCE  :  2;               /*!< WDT clock source                                                      */
           uint32_t             : 14;
      __O  uint32_t  WDKEY      : 16;               /*!< Watchdog register key                                                 */
    } CLKSOURCE_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Offset:0x08 WDT Timer Constant Register                               */
    
    struct {
      __IO uint32_t  TC         :  8;               /*!< Watchdog timer constant reload value                                  */
           uint32_t             :  8;
      __O  uint32_t  WDKEY      : 16;               /*!< Watchdog register key                                                 */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  FEED;                            /*!< Offset:0x0C WDT Feed Register                                         */
    
    struct {
      __O  uint32_t  FV         : 16;               /*!< Watchdog feed value                                                   */
      __O  uint32_t  WDKEY      : 16;               /*!< Watchdog register key                                                 */
    } FEED_b;                                       /*!< BitSize                                                               */
  };
} SN_WDT_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_RTC                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief Real-time Clock (SN_RTC)
  */

typedef struct {                                    /*!< SN_RTC Structure                                                      */
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x00 RTC Control Register                                      */
    
    struct {
      __IO uint32_t  RTCEN      :  1;               /*!< RTC enable                                                            */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKS;                            /*!< Offset:0x04 RTC Clock Source Register                                 */
    
    struct {
      __IO uint32_t  CLKSEL     :  2;               /*!< RTC clock source                                                      */
    } CLKS_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x08 RTC Interrupt Enable Register                             */
    
    struct {
      __IO uint32_t  SECIE      :  1;               /*!< Second interrupt enable                                               */
      __IO uint32_t  ALMIE      :  1;               /*!< Alarm interrupt enable                                                */
      __IO uint32_t  OVFIE      :  1;               /*!< Overflow interrupt enable                                             */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x0C RTC Raw Interrupt Status Register                         */
    
    struct {
      __I  uint32_t  SECIF      :  1;               /*!< Second interrupt flag                                                 */
      __I  uint32_t  ALMIF      :  1;               /*!< Alarm interrupt flag                                                  */
      __I  uint32_t  OVFIF      :  1;               /*!< Overflow interrupt flag                                               */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x10 RTC Interrupt Clear Register                              */
    
    struct {
      __O  uint32_t  SECIC      :  1;               /*!< Second interrupt flag clear                                           */
      __O  uint32_t  ALMIC      :  1;               /*!< Alarm interrupt flag clear                                            */
      __O  uint32_t  OVFIC      :  1;               /*!< Overflow interrupt flag clear                                         */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  __IO uint32_t  SECCNTV;                           /*!< Offset:0x14 RTC Second Counter Reload Value Register                  */
  __I  uint32_t  SECCNT;                            /*!< Offset:0x18 RTC Second Counter Register                               */
  __IO uint32_t  ALMCNTV;                           /*!< Offset:0x1C RTC Alarm Counter Reload Value Register                   */
  __I  uint32_t  ALMCNT;                            /*!< Offset:0x20 RTC Alarm Counter Register                                */
} SN_RTC_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_CT16B0                   ======================================= */
/* =========================================================================================================================== */
/**
  * @brief 16-bit Timer 0 with Capture function (SN_CT16B0)
  */

typedef struct {                                    /*!< SN_CT16B0 Structure                                                   */
  
  union {
    __IO uint32_t  TMRCTRL;                         /*!< Offset:0x00 CT16Bn Timer Control Register                             */
    
    struct {
      __IO uint32_t  CEN        :  1;               /*!< Counter enable                                                        */
      __IO uint32_t  CRST       :  1;               /*!< Counter Reset                                                         */
    } TMRCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Offset:0x04 CT16Bn Timer Counter Register                             */
    
    struct {
      __IO uint32_t  TC         : 16;               /*!< Timer Counter                                                         */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PRE;                             /*!< Offset:0x08 CT16Bn Prescale Register                                  */
    
    struct {
      __IO uint32_t  PR         : 16;               /*!< Prescaler                                                             */
    } PRE_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC;                              /*!< Offset:0x0C CT16Bn Prescale Counter Register                          */
    
    struct {
      __IO uint32_t  PC         : 16;               /*!< Prescaler Counter                                                     */
    } PC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CNTCTRL;                         /*!< Offset:0x10 CT16Bn Counter Control Register                           */
    
    struct {
      __IO uint32_t  CTM        :  2;               /*!< Counter/Timer Mode                                                    */
      __IO uint32_t  CIS        :  2;               /*!< Counter Input Select                                                  */
    } CNTCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCTRL;                           /*!< Offset:0x14 CT16Bn Match Control Register                             */
    
    struct {
      __IO uint32_t  MR0IE      :  1;               /*!< Enable generating an interrupt when MR0 matches TC                    */
      __IO uint32_t  MR0RST     :  1;               /*!< Enable reset TC when MR0 matches TC                                   */
      __IO uint32_t  MR0STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR0 matches TC                  */
      __IO uint32_t  MR1IE      :  1;               /*!< Enable generating an interrupt when MR1 matches TC                    */
      __IO uint32_t  MR1RST     :  1;               /*!< Enable reset TC when MR1 matches TC                                   */
      __IO uint32_t  MR1STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR1 matches TC                  */
      __IO uint32_t  MR2IE      :  1;               /*!< Enable generating an interrupt when MR2 matches TC                    */
      __IO uint32_t  MR2RST     :  1;               /*!< Enable reset TC when MR2 matches TC                                   */
      __IO uint32_t  MR2STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR2 matches TC                  */
      __IO uint32_t  MR3IE      :  1;               /*!< Enable generating an interrupt when MR3 matches TC                    */
      __IO uint32_t  MR3RST     :  1;               /*!< Enable reset TC when MR3 matches TC                                   */
      __IO uint32_t  MR3STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR3 matches TC                  */
    } MCTRL_b;                                      /*!< BitSize                                                               */
  };
	
  __IO uint32_t  MR0;                               /*!< Offset:0x18 CT16Bn MR0 Register                                       */
  __IO uint32_t  MR1;                               /*!< Offset:0x1C CT16Bn MR1 Register                                       */
  __IO uint32_t  MR2;                               /*!< Offset:0x20 CT16Bn MR2 Register                                       */
  __IO uint32_t  MR3;                               /*!< Offset:0x24 CT16Bn MR3 Register                                       */
  
  union {
    __IO uint32_t  CAPCTRL;                         /*!< Offset:0x28 CT16Bn Capture Control Register                           */
    
    struct {
      __IO uint32_t  CAP0RE     :  2;               /*!< Capture/Reset on CT16Bn_CAP0/Comparator capture output signal
                                                         rising edge                                                           */
      __IO uint32_t  CAP0FE     :  2;               /*!< Capture/Reset on CT16Bn_CAP0/Comoparator capture output signal
                                                         falling edge                                                          */
      __IO uint32_t  CAP0IE     :  1;               /*!< Interrupt on CT16Bn_CAP0/Comparator capture output signal event:
                                                         a CAP0 load due to a CT16Bn_CAP0/Comparator capture output signal
                                                          event will generate an interrupt.                                    */
      __IO uint32_t  CAP0EN     :  2;               /*!< CAP0 function enable bit                                              */
    } CAPCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CAP0;                            /*!< Offset:0x2C CT16Bn CAP0 Register                                      */
    
    struct {
      __I  uint32_t  CAP0       : 16;               /*!< Timer counter capture value                                           */
    } CAP0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EM;                              /*!< Offset:0x30 CT16Bn External Match Register                            */
    
    struct {
      __IO uint32_t  EM0        :  1;               /*!< When the TC matches MR0, this bit will act according to EMC0[1:0],
                                                         and also drive the state of CT16Bn_PWM0 output.                       */
           uint32_t             :  3;
      __IO uint32_t  EMC0       :  2;               /*!< CT16Bn_PWM0 functionality                                             */
    } EM_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PWMCTRL;                         /*!< Offset:0x34 CT16Bn PWM Control Register                               */
    
    struct {
      __IO uint32_t  PWM0EN     :  1;               /*!< PWM0 enable                                                           */
      __IO uint32_t  PWM1EN     :  1;               /*!< PWM1 enable                                                           */
           uint32_t             : 18;
      __IO uint32_t  PWM0IOEN   :  1;               /*!< CT16Bn_PWM0/GPIO selection                                            */
      __IO uint32_t  PWM1IOEN   :  1;               /*!< CT16Bn_PWM1/GPIO selection                                            */
    } PWMCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x38 CT16Bn Raw Interrupt Status Register                      */
    
    struct {
      __I  uint32_t  MR0IF      :  1;               /*!< Match channel 0 interrupt flag                                        */
      __I  uint32_t  MR1IF      :  1;               /*!< Match channel 1 interrupt flag                                        */
      __I  uint32_t  MR2IF      :  1;               /*!< Match channel 2 interrupt flag                                        */
      __I  uint32_t  MR3IF      :  1;               /*!< Match channel 3 interrupt flag                                        */
      __I  uint32_t  CAP0IF     :  1;               /*!< Capture channel 0 interrupt flag                                      */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x3C CT16Bn Interrupt Clear Register                           */
    
    struct {
      __O  uint32_t  MR0IC      :  1;               /*!< MR0IF clear bit                                                       */
      __O  uint32_t  MR1IC      :  1;               /*!< MR1IF clear bit                                                       */
      __O  uint32_t  MR2IC      :  1;               /*!< MR2IF clear bit                                                       */
      __O  uint32_t  MR3IC      :  1;               /*!< MR3IF clear bit                                                       */
      __O  uint32_t  CAP0IC     :  1;               /*!< CAP0IF clear bit                                                      */
    } IC_b;                                         /*!< BitSize                                                               */
  };
} SN_CT16B0_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_CT32B0                   ======================================= */
/* =========================================================================================================================== */
/**
  * @brief 32-bit Timer 0 with Capture function (SN_CT32B0)
  */

typedef struct {                                    /*!< SN_CT32B0 Structure                                                   */
  
  union {
    __IO uint32_t  TMRCTRL;                         /*!< Offset:0x00 CT32Bn Timer Control Register                             */
    
    struct {
      __IO uint32_t  CEN        :  1;               /*!< Counter Enable                                                        */
      __IO uint32_t  CRST       :  1;               /*!< Counter Reset                                                         */
    } TMRCTRL_b;                                    /*!< BitSize                                                               */
  };
  __IO uint32_t  TC;                                /*!< Offset:0x04 CT32Bn Timer Counter Register                             */
  __IO uint32_t  PRE;                               /*!< Offset:0x08 CT32Bn Prescale Register                                  */
  __IO uint32_t  PC;                                /*!< Offset:0x0C CT32Bn Prescale Counter Register                          */
  
  union {
    __IO uint32_t  CNTCTRL;                         /*!< Offset:0x10 CT32Bn Counter Control Register                           */
    
    struct {
      __IO uint32_t  CTM        :  2;               /*!< Counter/Timer Mode                                                    */
      __IO uint32_t  CIS        :  2;               /*!< Counter Input Select                                                  */
    } CNTCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCTRL;                           /*!< Offset:0x14 CT32Bn Match Control Register                             */
    
    struct {
      __IO uint32_t  MR0IE      :  1;               /*!< Enable generating an interrupt when MR0 matches TC                    */
      __IO uint32_t  MR0RST     :  1;               /*!< Enable reset TC when MR0 matches TC                                   */
      __IO uint32_t  MR0STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR0 matches TC                  */
      __IO uint32_t  MR1IE      :  1;               /*!< Enable generating an interrupt when MR1 matches TC                    */
      __IO uint32_t  MR1RST     :  1;               /*!< Enable reset TC when MR1 matches TC                                   */
      __IO uint32_t  MR1STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR1 matches TC                  */
      __IO uint32_t  MR2IE      :  1;               /*!< Enable generating an interrupt when MR2 matches TC                    */
      __IO uint32_t  MR2RST     :  1;               /*!< Enable reset TC when MR2 matches TC                                   */
      __IO uint32_t  MR2STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR2 matches TC                  */
      __IO uint32_t  MR3IE      :  1;               /*!< Enable generating an interrupt when MR3 matches TC                    */
      __IO uint32_t  MR3RST     :  1;               /*!< Enable reset TC when MR3 matches TC                                   */
      __IO uint32_t  MR3STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR3 matches TC                  */
    } MCTRL_b;                                      /*!< BitSize                                                               */
  };
	
  __IO uint32_t  MR0;                               /*!< Offset:0x18 CT32Bn MR0 Register                                       */
  __IO uint32_t  MR1;                               /*!< Offset:0x1C CT32Bn MR1 Register                                       */
  __IO uint32_t  MR2;                               /*!< Offset:0x20 CT32Bn MR2 Register                                       */
  __IO uint32_t  MR3;                               /*!< Offset:0x24 CT32Bn MR3 Register                                       */
  
  union {
    __IO uint32_t  CAPCTRL;                         /*!< Offset:0x28 CT32Bn Capture Control Register                           */
    
    struct {
      __IO uint32_t  CAP0RE     :  2;               /*!< Capture/Reset on CT32Bn_CAP0/Comparator capture output signal
                                                         rising edge.                                                          */
      __IO uint32_t  CAP0FE     :  2;               /*!< Capture/Reset on CT32Bn_CAP0/Comparator capture output signal
                                                         falling edge.                                                         */
      __IO uint32_t  CAP0IE     :  1;               /*!< Interrupt on CT32Bn_CAP0/Comparator capture output event              */
      __IO uint32_t  CAP0EN     :  2;               /*!< Capture 0 function enable bit                                         */
    } CAPCTRL_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  CAP0;                              /*!< Offset:0x2C CT32Bn CAP0 Register                                      */
  
  union {
    __IO uint32_t  EM;                              /*!< Offset:0x30 CT32Bn External Match Register                            */
    
    struct {
      __IO uint32_t  EM0        :  1;               /*!< When the TC matches MR0, this bit will act according to EMC0[1:0],
                                                         and also drive the state of CT16Bn_PWM0 output.                       */
      __IO uint32_t  EM1        :  1;               /*!< When the TC matches MR1, this bit will act according to EMC1[1:0],
                                                         and also drive the state of CT16Bn_PWM1 output.                       */
           uint32_t             :  2;
      __IO uint32_t  EMC0       :  2;               /*!< CT32Bn_PWM0 functionality                                             */
      __IO uint32_t  EMC1       :  2;               /*!< CT32Bn_PWM1 functionality                                             */
    } EM_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PWMCTRL;                         /*!< Offset:0x34 CT32Bn PWM Control Register                               */
    
    struct {
      __IO uint32_t  PWM0EN     :  1;               /*!< PWM0 enable                                                           */
      __IO uint32_t  PWM1EN     :  1;               /*!< PWM1 enable                                                           */
           uint32_t             : 18;
      __IO uint32_t  PWM0IOEN   :  1;               /*!< CT32Bn_PWM0/GPIO selection                                            */
      __IO uint32_t  PWM1IOEN   :  1;               /*!< CT16Bn_PWM1/GPIO selection                                            */
    } PWMCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x38 CT32Bn Raw Interrupt Status Register                      */
    
    struct {
      __I  uint32_t  MR0IF      :  1;               /*!< Match channel 0 interrupt flag                                        */
      __I  uint32_t  MR1IF      :  1;               /*!< Match channel 1 interrupt flag                                        */
      __I  uint32_t  MR2IF      :  1;               /*!< Match channel 2 interrupt flag                                        */
      __I  uint32_t  MR3IF      :  1;               /*!< Match channel 3 interrupt flag                                        */
      __I  uint32_t  CAP0IF     :  1;               /*!< Capture channel 0 interrupt flag                                      */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x3C CT32Bn Interrupt Clear Register                           */
    
    struct {
      __O  uint32_t  MR0IC      :  1;               /*!< MR0IF clear bit                                                       */
      __O  uint32_t  MR1IC      :  1;               /*!< MR1IF clear bit                                                       */
      __O  uint32_t  MR2IC      :  1;               /*!< MR2IF clear bit                                                       */
      __O  uint32_t  MR3IC      :  1;               /*!< MR3IF clear bit                                                       */
      __O  uint32_t  CAP0IC     :  1;               /*!< CAP0IF clear bit                                                      */
    } IC_b;                                         /*!< BitSize                                                               */
  };
} SN_CT32B0_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_SPI                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief SPI (SN_SPI)
  */

typedef struct {                                    /*!< SN_SSP0 Structure                                                     */
  
  union {
    __IO uint32_t  CTRL0;                           /*!< Offset:0x00 SSPn Control Register 0                                   */
    
    struct {
      __IO uint32_t  SPIEN      :  1;               /*!< SSP enable                                                            */
      __IO uint32_t  LOOPBACK   :  1;               /*!< Loopback mode enable                                                  */
      __IO uint32_t  SDODIS     :  1;               /*!< Slave data out disable                                                */
      __IO uint32_t  MS         :  1;               /*!< Master/Slave selection                                                */
      __IO uint32_t  FORMAT     :  1;               /*!< Interface format                                                      */
           uint32_t             :  1;
      __O  uint32_t  FRESET     :  2;               /*!< SSP FSM and FIFO Reset                                                */
      __IO uint32_t  DL         :  4;               /*!< Data length = DL[3:0]+1                                               */
      __IO uint32_t  TXFIFOTH   :  3;               /*!< TX FIFO Threshold level                                               */
      __IO uint32_t  RXFIFOTH   :  3;               /*!< Rx FIFO Threshold level                                               */
      __IO uint32_t  SELDIS     :  1;               /*!< Auto-SEL disable bit                                                  */
      __IO uint32_t  SELCTRL    :  1;               /*!< Source for SEL pin                                                    */
    } CTRL0_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTRL1;                           /*!< Offset:0x04 SSPn Control Register 1                                   */
    
    struct {
      __IO uint32_t  MLSB       :  1;               /*!< MSB/LSB seletion                                                      */
      __IO uint32_t  CPOL       :  1;               /*!< Clock priority selection                                              */
      __IO uint32_t  CPHA       :  1;               /*!< Clock phase of edge sampling                                          */
    } CTRL1_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKDIV;                          /*!< Offset:0x08 SSPn Clock Divider Register                               */
    
    struct {
      __IO uint32_t  DIV        :  8;               /*!< SSPn SCK=SSPn_PCLK/(2*DIV+2)                                          */
    } CLKDIV_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  STAT;                            /*!< Offset:0x0C SSPn Status Register                                      */
    
    struct {
      __I  uint32_t  TX_EMPTY   :  1;               /*!< TX FIFO empty flag                                                    */
      __I  uint32_t  TX_FULL    :  1;               /*!< TX FIFO full flag                                                     */
      __I  uint32_t  RX_EMPTY   :  1;               /*!< RX FIFO empty flag                                                    */
      __I  uint32_t  RX_FULL    :  1;               /*!< RX FIFO full flag                                                     */
      __I  uint32_t  BUSY       :  1;               /*!< Busy flag                                                             */
      __I  uint32_t  TXFIFOTHF  :  1;               /*!< TX FIFO threshold flag                                                */
      __I  uint32_t  RXFIFOTHF  :  1;               /*!< RX FIFO threshold flag                                                */
    } STAT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x10 SSPn Interrupt Enable Register                            */
    
    struct {
      __IO uint32_t  RXOVFIE    :  1;               /*!< RX FIFO overflow interrupt enable                                     */
      __IO uint32_t  RXTOIE     :  1;               /*!< RX time-out interrupt enable                                          */
      __IO uint32_t  RXFIFOTHIE :  1;               /*!< RX FIFO threshold interrupt enable                                    */
      __IO uint32_t  TXFIFOTHIE :  1;               /*!< TX FIFO threshold interrupt enable                                    */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x14 SSPn Raw Interrupt Status Register                        */
    
    struct {
      __I  uint32_t  RXOVFIF    :  1;               /*!< RX FIFO overflow interrupt flag                                       */
      __I  uint32_t  RXTOIF     :  1;               /*!< RX time-out interrupt flag                                            */
      __I  uint32_t  RXFIFOTHIF :  1;               /*!< RX FIFO threshold interrupt flag                                      */
      __I  uint32_t  TXFIFOTHIF :  1;               /*!< TX FIFO threshold interrupt flag                                      */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x18 SSPn Interrupt Clear Register                             */
    
    struct {
      __O  uint32_t  RXOVFIC    :  1;               /*!< RX FIFO overflow flag clear                                           */
      __O  uint32_t  RXTOIC     :  1;               /*!< RX time-out interrupt flag clear                                      */
      __O  uint32_t  RXFIFOTHIC :  1;               /*!< RX Interrupt flag Clear                                               */
      __O  uint32_t  TXFIFOTHIC :  1;               /*!< TX Interrupt flag Clear                                               */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA;                            /*!< Offset:0x1C SSPn Data Register                                        */
    
    struct {
      __IO uint32_t  Data       : 16;               /*!< Data                                                                  */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
} SN_SPI_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_I2C                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief I2C (SN_I2C)
  */

typedef struct {                                    /*!< SN_I2C0 Structure                                                     */
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x00 I2Cn Control Register                                     */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  NACK       :  1;               /*!< NACK assert flag                                                      */
      __IO uint32_t  ACK        :  1;               /*!< ACK assert flag                                                       */
           uint32_t             :  1;
      __IO uint32_t  STO        :  1;               /*!< STOP assert flag                                                      */
      __IO uint32_t  STA        :  1;               /*!< START assert flag                                                     */
           uint32_t             :  1;
      __IO uint32_t  I2CMODE    :  1;               /*!< I2C mode                                                              */
      __IO uint32_t  I2CEN      :  1;               /*!< I2Cn interface enable                                                 */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  STAT;                            /*!< Offset:0x04 I2Cn Status Register                                      */
    
    struct {
      __I  uint32_t  RX_DN      :  1;               /*!< RX done status                                                        */
      __I  uint32_t  ACK_STAT   :  1;               /*!< ACK done status                                                       */
      __I  uint32_t  NACK_STAT  :  1;               /*!< NACK done status                                                      */
      __I  uint32_t  STOP_DN    :  1;               /*!< STOP done status                                                      */
      __I  uint32_t  START_DN   :  1;               /*!< START done status                                                     */
      __I  uint32_t  I2C_MST    :  1;               /*!< I2C master/slave status                                               */
      __I  uint32_t  SLV_RX_HIT :  1;               /*!< Slave RX address hit flag                                             */
      __I  uint32_t  SLV_TX_HIT :  1;               /*!< Slave TX address hit flag                                             */
      __I  uint32_t  LOST_ARB   :  1;               /*!< Lost arbitration status                                               */
      __I  uint32_t  TIMEOUT    :  1;               /*!< Time-out status                                                       */
           uint32_t             :  5;
      __IO uint32_t  I2CIF      :  1;               /*!< I2C interrupt flag                                                    */
    } STAT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TXDATA;                          /*!< Offset:0x08 I2Cn TX Data Register                                     */
    
    struct {
      __IO uint32_t  Data       :  8;               /*!< TX Data                                                               */
    } TXDATA_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RXDATA;                          /*!< Offset:0x0C I2Cn RX Data Register                                     */
    
    struct {
      __I  uint32_t  Data       :  8;               /*!< RX Data received when RX_DN=1                                         */
    } RXDATA_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR0;                        /*!< Offset:0x10 I2Cn Slave Address 0 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 0                                                  */
           uint32_t             : 20;
      __IO uint32_t  GCEN       :  1;               /*!< General call address enable                                           */
      __IO uint32_t  ADD_MODE   :  1;               /*!< Slave address mode                                                    */
    } SLVADDR0_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR1;                        /*!< Offset:0x14 I2Cn Slave Address 1 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 1                                                  */
    } SLVADDR1_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR2;                        /*!< Offset:0x18 I2Cn Slave Address 2 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 2                                                  */
    } SLVADDR2_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR3;                        /*!< Offset:0x1C I2Cn Slave Address 3 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 3                                                  */
    } SLVADDR3_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SCLHT;                           /*!< Offset:0x20 I2Cn SCL High Time Register                               */
    
    struct {
      __IO uint32_t  SCLH       :  16;               /*!< SCLn High period time=(SCLHT+1)*I2Cn_PCLK cycle                      */
    } SCLHT_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SCLLT;                           /*!< Offset:0x24 I2Cn SCL Low Time Register                                */
    
    struct {
      __IO uint32_t  SCLL       :  16;               /*!< SCLn Low period time=(SCLLT+1)*I2Cn_PCLK cycle                       */
    } SCLLT_b;                                      /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO uint32_t  TOCTRL;                          /*!< Offset:0x2C I2Cn Timeout Control Register                             */
    
    struct {
      __IO uint32_t  TO         : 16;               /*!< Timeout period time = TO*I2Cn_PCLK cycle                              */
    } TOCTRL_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MMCTRL;                          /*!< Offset:0x30 I2Cn Monitor Mode Control Register                        */
    
    struct {
      __IO uint32_t  MMEN       :  1;               /*!< Monitor mode enable                                                   */
      __IO uint32_t  SCLOEN     :  1;               /*!< SCLn output enable                                                    */
      __IO uint32_t  MATCH_ALL  :  1;               /*!< Match address selection                                               */
    } MMCTRL_b;                                     /*!< BitSize                                                               */
  };
	
	union {
    __IO uint32_t  EMODE;                          /*!< Offset:0x34 I2Cn Engineer Mode Register                                */
    
    struct {
      __IO uint32_t  ICOD       :  1;               /*!< I2C Open Drain enable                                                 */
      __IO uint32_t  SLVSTAEN   :  1;               /*!< Slave START Enable                                                    */
    } EMODE_b;                                      /*!< BitSize                                                               */
  };
} SN_I2C_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_UART                     ======================================= */
/* =========================================================================================================================== */
/**
  * @brief UART (SN_UART)
  */

typedef struct {                                    /*!< SN_UART0 Structure                                                    */
  
  union {
    union {
      __IO uint32_t  DLL;                           /*!< Offset:0x00 UARTn Divisor Latch LSB Register                          */
      
      struct {
        __IO uint32_t  DLL      :  8;               /*!< DLL and DLM register determines the baud rate of UARTn                */
      } DLL_b;                                      /*!< BitSize                                                               */
    };
    
    union {
      __O  uint32_t  TH;                            /*!< Offset:0x00 UARTn Transmit Holding Register                           */
      
      struct {
        __O  uint32_t  TH       :  8;               /*!< The oldest byte to be transmitted in UART TX FIFO when transmitter
                                                         is available                                                          */
      } TH_b;                                       /*!< BitSize                                                               */
    };
    
    union {
      __I  uint32_t  RB;                            /*!< Offset:0x00 UARTn Receiver Buffer Register                            */
      
      struct {
        __I  uint32_t  RB       :  8;               /*!< The oldest received byte in UART RX FIFO                              */
      } RB_b;                                       /*!< BitSize                                                               */
    };
  } ;
  
  union {
    union {
      __IO uint32_t  IE;                            /*!< Offset:0x04 UARTn Interrupt Enable Register                           */
      
      struct {
        __IO uint32_t  RDAIE    :  1;               /*!< RDA interrupt enable                                                  */
        __IO uint32_t  THREIE   :  1;               /*!< THRE interrupt enable                                                 */
        __IO uint32_t  RLSIE    :  1;               /*!< RLS interrupt enable                                                  */
             uint32_t           :  1;
        __IO uint32_t  TEMTIE   :  1;               /*!< TEMT interrupt enable                                                 */
             uint32_t           :  3;
        __IO uint32_t  ABEOIE   :  1;               /*!< ABE0 interrupt enable                                                 */
        __IO uint32_t  ABTOIE   :  1;               /*!< ABT0 interrupt enable                                                 */
      } IE_b;                                       /*!< BitSize                                                               */
    };
    
    union {
      __IO uint32_t  DLM;                           /*!< Offset:0x04 UARTn Divisor Latch MSB Register                          */
      
      struct {
        __IO uint32_t  DLM      :  8;               /*!< DLL and DLM register determines the baud rate of UARTn                */
      } DLM_b;                                      /*!< BitSize                                                               */
    };
  } ;
  
  union {
    union {
      __O  uint32_t  FIFOCTRL;                      /*!< Offset:0x08 UARTn FIFO Control Register                               */
      
      struct {
        __O  uint32_t  FIFOEN   :  1;               /*!< FIFO enable                                                           */
        __O  uint32_t  RXFIFORST:  1;               /*!< RX FIFO reset                                                         */
        __O  uint32_t  TXFIFORST:  1;               /*!< TX FIFO reset                                                         */
             uint32_t           :  3;
        __O  uint32_t  RXTL     :  2;               /*!< RX trigger level                                                      */
      } FIFOCTRL_b;                                 /*!< BitSize                                                               */
    };
    
    union {
      __I  uint32_t  II;                            /*!< Offset:0x08 UARTn Interrupt Identification Register                   */
      
      struct {
        __I  uint32_t  INTSTATUS:  1;               /*!< Interrupt status                                                      */
        __I  uint32_t  INTID    :  3;               /*!< Interrupt ID of RX FIFO                                               */
             uint32_t           :  2;
        __I  uint32_t  FIFOEN   :  2;               /*!< Equal to FIFOEN bits in UARTn_FIFOCTRL register                       */
        __I  uint32_t  ABEOIF   :  1;               /*!< ABEO interrupt flag                                                   */
        __I  uint32_t  ABTOIF   :  1;               /*!< ABTO interrupt flag                                                   */
      } II_b;                                       /*!< BitSize                                                               */
    };
  } ;
  
  union {
    __IO uint32_t  LC;                              /*!< Offset:0x0C UARTn Line Control Register                               */
    
    struct {
      __IO uint32_t  WLS        :  2;               /*!< Word length selection                                                 */
      __IO uint32_t  SBS        :  1;               /*!< Stop bit selection                                                    */
      __IO uint32_t  PE         :  1;               /*!< Parity enable                                                         */
      __IO uint32_t  PS         :  2;               /*!< Parity selection                                                      */
      __IO uint32_t  BC         :  1;               /*!< Break control                                                         */
      __IO uint32_t  DLAB       :  1;               /*!< Divisor Latch access                                                  */
    } LC_b;                                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __I  uint32_t  LS;                              /*!< Offset:0x14 UARTn Line Status Register                                */
    
    struct {
      __I  uint32_t  RDR        :  1;               /*!< Receiver data ready flag                                              */
      __I  uint32_t  OE         :  1;               /*!< Overrun error flag                                                    */
      __I  uint32_t  PE         :  1;               /*!< Parity error flag                                                     */
      __I  uint32_t  FE         :  1;               /*!< Framing error flag                                                    */
      __I  uint32_t  BI         :  1;               /*!< Break interrupt flag                                                  */
      __I  uint32_t  THRE       :  1;               /*!< THR empty flag                                                        */
      __I  uint32_t  TEMT       :  1;               /*!< Transmitter empty flag                                                */
      __I  uint32_t  RXFE       :  1;               /*!< Receiver FIFO error flag                                              */
    } LS_b;                                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  SP;                              /*!< Offset:0x1C UARTn Scratch Pad Register                                */
    
    struct {
      __IO uint32_t  PAD        :  8;               /*!< Pad informaton                                                        */
    } SP_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ABCTRL;                          /*!< Offset:0x20 UARTn Auto-baud Control Register                          */
    
    struct {
      __IO uint32_t  START      :  1;               /*!< Auto-baud run bit                                                     */
      __IO uint32_t  MODE       :  1;               /*!< Auto-baud mode selection                                              */
      __IO uint32_t  AUTORESTART:  1;               /*!< Restart mode selection                                                */
           uint32_t             :  5;
      __O  uint32_t  ABEOIFC    :  1;               /*!< Clear ABEOIF flag                                                     */
      __O  uint32_t  ABTOIFC    :  1;               /*!< Clear ABTOIF flag                                                     */
    } ABCTRL_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  FD;                              /*!< Offset:0x28 UARTn Fractional Divider Register                         */
    
    struct {
      __IO uint32_t  DIVADDVAL  :  4;               /*!< Baud rate generation prescaler divisor value                          */
      __IO uint32_t  MULVAL     :  4;               /*!< Baud rate generation prescaler multiplier value                       */
      __IO uint32_t  OVER8      :  1;               /*!< Oversampling value                                                    */
    } FD_b;                                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x30 UARTn Control Register                                    */
    
    struct {
      __IO uint32_t  UARTEN     :  1;               /*!< UART enable                                                           */
           uint32_t             :  5;
      __IO uint32_t  RXEN       :  1;               /*!< RX enable                                                             */
      __IO uint32_t  TXEN       :  1;               /*!< TX enable                                                             */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HDEN;                            /*!< Offset:0x34 UARTn Control Register                                    */
    
    struct {
      __IO uint32_t  HDEN       :  1;               /*!< Half-duplex mode enable                                               */
    } HDEN_b;                                       /*!< BitSize                                                               */
  };
} SN_UART_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_I2S                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief I2S (SN_I2S)
  */

typedef struct {                                    /*!< SN_I2S Structure                                                      */
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x00 I2S Control Register                                      */
    
    struct {
      __IO uint32_t  START      :  1;               /*!< Start Transmit/Receive                                                */
      __IO uint32_t  MUTE       :  1;               /*!< Mute enable                                                           */
      __IO uint32_t  MONO       :  1;               /*!< Mono/stereo selection                                                 */
      __IO uint32_t  MS         :  1;               /*!< Master/Slave selection bit                                            */
      __IO uint32_t  FORMAT     :  2;               /*!< I2S operation format                                                  */
      __IO uint32_t  TXEN       :  1;               /*!< Transmit enable bit                                                   */
      __O  uint32_t  RXEN       :  1;               /*!< Receiver enable bit                                                   */
      __O  uint32_t  CLRTXFIFO  :  1;               /*!< Clear I2S TX FIFO                                                     */
      __O  uint32_t  CLRRXFIFO  :  1;               /*!< Clear I2S RX FIFO                                                     */
      __IO uint32_t  DL         :  2;               /*!< Data length                                                           */
      __IO uint32_t  PAUSE		:  1;               /*!< PAUSE Mode                                                    		*/
      __IO uint32_t             :  7;
      __IO uint32_t  CHLENGTH   :  5;               /*!< Bit number of single channel                                          */
      __IO uint32_t             :  4;
      __IO uint32_t  ADCEN      :  1;               /*!< ADC enable                                                            */
	  __IO uint32_t  DACEN      :  1;               /*!< DAC enable                                                            */
      __IO uint32_t  I2SEN      :  1;               /*!< I2S enable                                                            */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLK;                             /*!< Offset:0x04 I2S Clock Register                                        */
    
    struct {
      __IO uint32_t  MCLKDIV    :  3;               /*!< MCLK divider                                                          */
      __IO uint32_t  MCLKOEN    :  1;               /*!< MLCK output enable                                                    */
      __IO uint32_t  MCLKSEL    :  1;               /*!< MLCK source selection                                                 */
           uint32_t             :  3;
      __IO uint32_t  BCLKDIV    :  8;               /*!< BCLK divider                                                          */
	  __IO uint32_t  FPLLDIV    :  2;               /*!< Fractional PLL divider                                                */
    } CLK_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  STATUS;                          /*!< Offset:0x08 I2S Status Register                                       */
    
    struct {
      __I  uint32_t  TX_TOG     :  1;               /*!< TX Toggle                                                             */
      __I  uint32_t  RX_TOG     :  1;               /*!< Rx Toggle                                                             */
    } STATUS_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x0C I2S Interrupt Enable Register                             */
    
    struct {
      __IO uint32_t  TXINTEN:  1;                   /*!< TX interrupt enable                                                   */
      __IO uint32_t  RXINTEN:  1;                   /*!< RX interrupt enable                                                   */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  
	__O  uint32_t  TXRAMLENGTH;						/*!< Offset:0x10	                                                         */ 
	
	     uint32_t  Reserved1;						/*!< Offset:0x14	                                                         */ 
	     uint32_t  Reserved2;						/*!< Offset:0x18	                                                         */
	     uint32_t  Reserved3;						/*!< Offset:0x1C	                                                         */
	
	__O  uint32_t  TXRAMADR;						/*!< Offset:0x20	                                                         */
	
  	__O  uint32_t  TXRAMADRRCHOFST;					/*!< Offset:0x24	                                                         */
  
  	__I  uint32_t  TX_RAM_IDX;						/*!< Offset:0x28	                                                         */
   
	     uint32_t  Reserved4;						/*!< Offset:0x2C	                                                         */
	
  	__O  uint32_t  RXRAMADR;						/*!< Offset:0x30	                                                         */

  	__O  uint32_t  RXRAMADRRCHOFST;					/*!< Offset:0x34	                                                         */
	
	__I  uint32_t  RX_RAM_IDX;						/*!< Offset:0x38	                                                         */	
  
} SN_I2S_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_I2S2                     ======================================= */
/* =========================================================================================================================== */
/**
  * @brief I2S_2 (SN_I2S_2)
  */

typedef struct {                                    /*!< SN_I2S_2 Structure                                                    */
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x00 I2S Control Register                                      */
    
    struct {
      __IO uint32_t  START      :  1;               /*!< Start Transmit/Receive                                                */
      __IO uint32_t  MUTE       :  1;               /*!< Mute enable                                                           */
      __IO uint32_t  MONO       :  1;               /*!< Mono/stereo selection                                                 */
      __IO uint32_t  MS         :  1;               /*!< Master/Slave selection bit                                            */
      __IO uint32_t  FORMAT     :  2;               /*!< I2S operation format                                                  */
      __IO uint32_t  TXEN       :  1;               /*!< Transmit enable bit                                                   */
      __O  uint32_t  RXEN       :  1;               /*!< Receiver enable bit                                                   */
      __O  uint32_t  CLRTXFIFO  :  1;               /*!< Clear I2S TX FIFO                                                     */
      __O  uint32_t  CLRRXFIFO  :  1;               /*!< Clear I2S RX FIFO                                                     */
      __IO uint32_t  DL         :  2;               /*!< Data length                                                           */
      __IO uint32_t  TXFIFOTH   :  3;               /*!< Tx FIFO threshold level                                               */
           uint32_t             :  1;
      __IO uint32_t  RXFIFOTH   :  3;               /*!< Rx FIFO threshold level                                               */
           uint32_t             :  1;
      __IO uint32_t  CHLENGTH   :  5;               /*!< Bit number of single channel                                          */
           uint32_t             :  5;
      __IO uint32_t  I2SMOD     :  1;               /*!< I2S mode select bit                                                   */
      __IO uint32_t  I2SEN      :  1;               /*!< I2S enable                                                            */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLK;                             /*!< Offset:0x04 I2S Clock Register                                        */
    
    struct {
      __IO uint32_t  MCLKDIV    :  3;               /*!< MCLK divider                                                          */
      __IO uint32_t  MCLKOEN    :  1;               /*!< MLCK output enable                                                    */
      __IO uint32_t  MCLKSEL    :  1;               /*!< MLCK source selection                                                 */
           uint32_t             :  3;
      __IO uint32_t  BCLKDIV    :  8;               /*!< BCLK divider                                                          */
			__IO uint32_t  FPLLDIV    :  2;               /*!< Fractional PLL divider                                          */
    } CLK_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  STATUS;                          /*!< Offset:0x08 I2S Status Register                                       */
    
    struct {
      __I  uint32_t  I2SINT     :  1;               /*!< I2S interrupt flag                                                    */
      __I  uint32_t  RIGHTCH    :  1;               /*!< Current channel status                                                */
           uint32_t             :  4;
      __I  uint32_t  TXFIFOTHF  :  1;               /*!< TX FIFO threshold flag                                                */
      __I  uint32_t  RXFIFOTHF  :  1;               /*!< RX FIFO threshold flag                                                */
      __I  uint32_t  TXFIFOFULL :  1;               /*!< TX FIFO full flag                                                     */
      __I  uint32_t  RXFIFOFULL :  1;               /*!< RX FIFO full flag                                                     */
      __I  uint32_t  TXFIFOEMPTY:  1;               /*!< TX FIFO empty flag                                                    */
      __I  uint32_t  RXFIFOEMPTY:  1;               /*!< RX FIFO empty flag                                                    */
      __I  uint32_t  TXFIFOLV   :  4;               /*!< TX FIFO used level                                                    */
           uint32_t             :  1;
      __I  uint32_t  RXFIFOLV   :  4;               /*!< RX FIFO used level                                                    */
    } STATUS_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x0C I2S Interrupt Enable Register                             */
    
    struct {
           uint32_t             :  4;
      __IO uint32_t  TXFIFOOVFIEN:  1;              /*!< TX FIFO overflow interrupt enable                                     */
      __IO uint32_t  RXFIFOUDFIEN:  1;              /*!< RX FIFO underflow interrupt enable                                    */
      __IO uint32_t  TXFIFOTHIEN:  1;               /*!< TX FIFO threshold interrupt enable                                    */
      __IO uint32_t  RXFIFOTHIEN:  1;               /*!< RX FIFO threshold interrupt enable                                    */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x10 I2S Raw Interrupt Status Register                         */
    
    struct {
           uint32_t             :  4;
      __I  uint32_t  TXFIFOOVIF :  1;               /*!< TX FIFO overflow interrupt flag                                       */
      __I  uint32_t  RXFIFOUDIF :  1;               /*!< RX FIFO underflow interrupt flag                                      */
      __I  uint32_t  TXFIFOTHIF :  1;               /*!< TX FIFO threshold interrupt flag                                      */
      __I  uint32_t  RXFIFOTHIF :  1;               /*!< RX FIFO threshold interrupt flag                                      */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x14 I2S Interrupt Clear Register                              */
    
    struct {
           uint32_t             :  4;
      __O  uint32_t  TXFIFOOVIC :  1;               /*!< TX FIFO overflow interrupt clear                                      */
      __O  uint32_t  RXFIFOUDIC :  1;               /*!< RX FIFO underflow interrupt clear                                     */
      __O  uint32_t  TXFIFOTHIC :  1;               /*!< TX FIFO threshold interrupt clear                                     */
      __O  uint32_t  RXFIFOTHIC :  1;               /*!< RX FIFO threshold interrupt clear                                     */
    } IC_b;                                         /*!< BitSize                                                               */
  };
	
	__I  uint32_t  RXFIFO;                          	/*!< Offset:0x18 UARTn RX FIFO Register                                    */
	__O  uint32_t  TXFIFO;                            /*!< Offset:0x1C UARTn TX FIFO Register                                    */
	
  
} SN_I2S2_Type;

/* =========================================================================================================================== */
/* ====================================                    SN_ADC                      ======================================= */
/* =========================================================================================================================== */


/**
  * @brief Codec ADC Control Registers (SN_ADC)
  */

typedef struct {                                    /*!< SN_ADC Structure                                                      */
  __I  uint32_t  RESERVED0[388];

//	__IO uint32_t		SET54;				 										//!< Offset:0x540 ADC Setting 54 Register
//	__I  uint32_t		RESERVED54[3];														
//																	
//	__IO uint32_t		SET55;				 										//!< Offset:0x550 ADC Setting 55 Register
//	__I  uint32_t		RESERVED55[3];														
//																	
//	__IO uint32_t		SET56;				 										//!< Offset:0x560 ADC Setting 56 Register
//	__I  uint32_t		RESERVED56[3];														
//																	
//	__IO uint32_t		SET57;				 										//!< Offset:0x570 ADC Setting 57 Register
//	__I  uint32_t		RESERVED57[3];														
//																	
//	__IO uint32_t		SET58;				 										//!< Offset:0x580 ADC Setting 58 Register
//	__I  uint32_t		RESERVED58[3];														
//																	
//	__IO uint32_t		SET59;				 										//!< Offset:0x590 ADC Setting 59 Register
//	__I  uint32_t		RESERVED59[3];														
//																	
//	__IO uint32_t		SET5A;				 										//!< Offset:0x5A0 ADC Setting 5A Register
//	__I  uint32_t		RESERVED5A[3];														
//																	
//	__IO uint32_t		SET5B;				 										//!< Offset:0x5B0 ADC Setting 5B Register
//	__I  uint32_t		RESERVED5B[3];														
//																	
//	__IO uint32_t		SET5C;				 										//!< Offset:0x5C0 ADC Setting 5C Register
//	__I  uint32_t		RESERVED5C[3];														
//																	
//	__IO uint32_t		SET5D;				 										//!< Offset:0x5D0 ADC Setting 5D Register
//	__I  uint32_t		RESERVED5D[3];														
//																	
//	__IO uint32_t		SET5E;				 										//!< Offset:0x5E0 ADC Setting 5E Register
//	__I  uint32_t		RESERVED5E[3];														
//																	
//	__IO uint32_t		SET5F;				 										//!< Offset:0x5F0 ADC Setting 5F Register
//	__I  uint32_t		RESERVED5F[3];														
//																	
//	__IO uint32_t		SET60;				 										//!< Offset:0x600 ADC Setting 60 Register
//	__I  uint32_t		RESERVED60[3];														
																	
	union {
    __IO uint32_t		SET61;				 										//!< Offset:0x610 ADC Setting 62 Register
		struct {
      __IO uint32_t  PGA_SET_VAL   :  5;               /*!< AGC Control. PGA setting value at normal mode when AGC is on.    */
      __IO uint32_t  BOOST_SET_VAL :  2;               /*!< AGC Control. Boost setting value at normal mode when AGC is on.  */
			__IO uint32_t  AGC_OFF       :  1;               /*!< AGC Control. AGC function control.                               */
    } SET61_b;                                      /*!< BitSize                                                             */
  };
	__I  uint32_t		RESERVED61[3];														
																	
	union {
    __IO uint32_t		SET62;				 										//!< Offset:0x620 ADC Setting 62 Register
		struct {
      __IO uint32_t  IWL        :  2;               /*!< World length of DAI                                                   */
      __IO uint32_t  ACTIVE     :  1;               /*!< Digital Audio Interface Control                                       */
    } SET62_b;                                      /*!< BitSize                                                               */
  };
	__I  uint32_t		RESERVED62[3];														
																	
	union {
    __IO uint32_t  SET63;                           /*!< Offset:0x630 ADC Setting 63 Register                                  */
    
    struct {
      __IO uint32_t  PGA       :  5;              /*!< PGA setting value when AGC is off(1.5dB/step)                           */
      __IO uint32_t  BOOST     :  2;              /*!< Boost setting value when AGC is off                                     */
    } SET63_b;                                      /*!< BitSize                                                               */
  };
	__I  uint32_t		RESERVED63[3];														
																	
	union {
    __IO uint32_t  SET64;                           /*!< Offset:0x640 ADC Setting 6E Register                                  */
    
    struct {
      __IO uint32_t  HPGAIN       :  4;             /*!< HPF GAIN                                                              */
      __IO uint32_t  ADCHPD       :  1;             /*!< HPF function for DC offset cancellation                               */
      __IO uint32_t  FILTER_OFF   :  1;             /*!< Filter function for noise suppression                                 */
    } SET64_b;                                      /*!< BitSize                                                               */
  };
	__I  uint32_t		RESERVED64[3];														
																	
	union {
    __IO uint32_t  SET65;                           /*!< Offset:0x650 ADC Setting 65 Register                                  */
    
    struct {
      __IO uint32_t  MUTE_CTRL    :  4;             /*!< Digital volume attenuation control at mute mode                       */
      __IO uint32_t  VOL_CTRL     :  4;             /*!< Digital volume attenuation control at normal mode                     */
    } SET65_b;                                      /*!< BitSize                                                               */
  };
	__I  uint32_t		RESERVED65[3];														
																	
	__IO uint32_t		SET66;				 										//!< Offset:0x660 ADC Setting 66 Register
	__I  uint32_t		RESERVED66[3];														
																	
	__IO uint32_t		SET67;				 										//!< Offset:0x670 ADC Setting 67 Register
	__I  uint32_t		RESERVED67[3];														
																	
	__IO uint32_t		SET68;				 										//!< Offset:0x680 ADC Setting 68 Register
	__I  uint32_t		RESERVED68[3];														

	__IO uint32_t		SET69;				 										//!< Offset:0x690 ADC Setting 69 Register
	__I  uint32_t		RESERVED69[3];	

	__IO uint32_t		SET6A;				 										//!< Offset:0x6A0 ADC Setting 6A Register
	__I  uint32_t		RESERVED6A[3];	
																	
	union {
    __IO uint32_t		SET6B;				 										//!< Offset:0x6B0 ADC Setting 6B Register
		struct {
			__I  uint32_t  RESERVED1    :  3;               /*!<																																			 */
  		__IO uint32_t  DEMPD        :  1;               //*!< DEM disable, active 'High'                                           */
      __IO uint32_t  PGA_EN       :  1;               //*!< PGA power-up enable, active 'High'                                   */
      __IO uint32_t  MICBT_EN     :  1;               //*!< MICBOOST power-up enable, active 'High'                              */
			__I  uint32_t  RESERVED2    :  1;               /*!<																																			 */
			__IO uint32_t  ADC_EN       :  1;               //*!< ADC power-up enable, active 'High'                                   */  		
    } SET6B_b;                                      /*!< BitSize                                                               */
  };
	__I  uint32_t		RESERVED6B[3];				

  union {
    __IO uint32_t  SET6C;                           /*!< Offset:0x6C0 ADC Setting 6C Register                                  */
    
    struct {
      __IO uint32_t  CK_EN      :  1;               /*!< CKGEN enable                                                          */
      __IO uint32_t  MICB_EN    :  1;            		/*!< Microphone bias enable, active 'High'                                 */
      __IO uint32_t  VREF_EN    :  1;               /*!< VREF circuit enable, active 'High'                                    */
      __IO uint32_t  IREF_EN    :  1;               /*!< IREF circuit enable, active 'High'                                    */
      __IO uint32_t  DX_EN      :  1;               /*!< SDM data to IC external enable, active 'High'                         */
      __IO uint32_t  CS         :  2;           		/*!< Chopper frequency select                                              */				
    } SET6C_b;                                      	/*!< Left Channel BitSize                                                */
  };
  __I  uint32_t  RESERVED6C[3];
	
	union {
    __IO uint32_t  SET6D;                           /*!< Offset:0x6D0 ADC Setting 6D Register                                  */
    
    struct {
			__IO uint32_t  SEL_MIX_MIC    :  1;               /*!< Microphone input path to mixer enable                          */
      __I  uint32_t  RESERVED1      :  1;               /*!<																			                          */
      __IO uint32_t  SEL_MIC        :  1;               /*!< Microphone input structure select                              */
      __I  uint32_t  RESERVED2      :  1;               /*!<																																*/
			__IO uint32_t  SEL_MICB       :  1;               /*!< Microphone Bias Output select                                  */ 
			__IO uint32_t  SEL_IB         :  2;               /*!< Internal Bias Current select                                   */			
    } SET6D_b;                                     		/*!< Right Channel BitSize                                               */
  };
  __I  uint32_t  RESERVED6D[3];

	__IO uint32_t	 SET6E;				 										//!< Offset:0x6E0 ADC Setting 60 Register
  __I  uint32_t  RESERVED6E[3];
	  																   	
} SN_ADC_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_DAC                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief Codec DAC Control Registers (SN_DAC)
  */

typedef struct {                                   /*!< SN_DAC Structure                                                      */
   union {
    __IO  uint32_t  SET0;                          /*!< Offset:0x00 DAC Setting 0 Register                                    */
    
    struct {
			__IO  uint32_t  PD_DACR		:  1;              /*!<R-CH DAC power-down, active ¡¥High¡¦                                      */
      __IO  uint32_t  PD_DACL		:  1;          	   /*!<L-CH DAC power-down, active ¡¥High¡¦                                      */
      __IO  uint32_t  PD_DRVR		:  1;          	   /*!<R-CH DRIVER DAC power-down, active ¡¥High¡¦                               */
      __IO  uint32_t  PD_DRVL		:  1;           	 /*!<L-CH DRIVER DAC power-down, active ¡¥High¡¦                               */
      __IO  uint32_t  PD_STDBY	:  1;              /*!<VREF circuit STDBY, active 'High'                                       */
      __IO  uint32_t  PD_DEMR	  :  1;              /*!<Power down DEM for R-CH, active 'High'                                  */
      __IO  uint32_t  PD_DEML	  :  1;              /*!<Power down DEM for L-CH, active 'High'                                  */
      __IO  uint32_t  PD_CK  		:  1;              /*!<CKGEN power-down, active 'High'                                         */
    } SET0_b;                                      /*!< BitSize                                                                */
  };
	 
  __I  uint32_t  RESERVED0[3]; 
  union {
		
    __IO uint32_t  SET1;                            /*!< Offset:0x010 DAC Setting 1 Register                                   */
    
    struct {
      __IO uint32_t  SEL_IB     :  2;               /*!< Internal Bias Current select                                          */
      __IO uint32_t  PD_IREF    :  1;               /*!< IREF Circuit Power-down enable                                        */			
      __IO uint32_t  PD_VREF    :  1;               /*!< VREF Circuit Power-down enable                                        */			
      __IO uint32_t  NOPOP      :  3;               /*!< Headphone output POP noise elimination                                */
      __IO uint32_t  VMIDSEL    :  1;               /*!< Normal mode/Fast Start-up select                                      */
    } SET1_b;                                       /*!< BitSize                                                               */
  };
	
  __I  uint32_t  RESERVED1[3];
  union {
    __IO uint32_t  SET2;                            /*!< Offset:0x020 DAC Setting 2 Register                                   */
    
    struct {
      __IO uint32_t  SOFT_RSTN  :  1;               /*!< Software reset digital circuit(one MCLK pulse trigger)                */
      __IO uint32_t  DAC_EN_IN  :  1;               /*!< DAC Enable                                                            */
      __IO uint32_t  MUTX       :  1;               /*!< Mute ON/OFF                                                           */
      __I  uint32_t  RESERVED1  :  2;               /*!<																																			 */
			__IO uint32_t  I2S_RL_SEL :  1;               /*!< I2S data reload selection                                             */
			__IO uint32_t  BCK_INV    :  1;               /*!< I2S Bit clock invert control                                          */
      __IO uint32_t  LRCK_INV   :  1;               /*!< I2S word clock invert control                												 */
    } SET2_b;                                       /*!< BitSize                                                               */
  };
	
  __I  uint32_t  RESERVED2[3]; 
  union {
    __IO uint32_t  SET3;                            /*!< Offset:0x030 DAC Setting 3 Register                                   */
    
    struct {
      __IO uint32_t  VOL_       :  6;               /*!< DAC Digital Volume attenuation control                                */
    } SET3_b;                                       /*!< BitSize                                                               */
  };
	
  __I  uint32_t  RESERVED3[3];
  union {
    __IO uint32_t  SET4;                            /*!< Offset:0x040 DAC Setting 4 Register                                   */
    
    struct {
			__IO uint32_t  TRIM  :  7;                    /*!<VCOMC TRIM Value                                                       */
		} SET4_b;                                       /*!< BitSize                                                               */
  };
	
  __I  uint32_t  RESERVED4[3];
  union {
    __IO  uint32_t  SET5;                          /*!< Offset:0x050 DAC Setting 5 Register                                    */
    
    struct {
			__IO uint32_t  DEMS        :  2;              /*!< Select the DAC de-emphasis response curve                             */
			__IO uint32_t  DEML_IN     :  1;              /*!< De-emphasis function contro;                                          */			
    } SET5_b;                                      /*!< BitSize                                                                */
  };
} SN_DAC_Type;


/* =========================================================================================================================== */
/* ====================================            SN_DAC_Amplifier                    ======================================= */
/* =========================================================================================================================== */
/**
  * @brief Codec DAC Audio Amplifier Registers (SN_DAC_AMP)
  */

typedef struct {                                   /*!< SN_DAC_AMP Structure                                                   */
  
  union {
    __IO uint32_t  OPA;                            /*!< Offset:0x000 DAC Setting Operation Register                            */
    
    struct {
      __IO uint32_t  RDY	      :  1;              /*!< Info user that can output data via builtin OPA (Enable Time)				   */
      __IO uint32_t  CE	      	:  1;              /*!< Built-in OPA Chip Enable control bit                              	   */
      __IO uint32_t  VOL	      :  5;              /*!< OPA volume control                               									     */
    } OPA_b; 
	};		
} SN_DAC_AMP_Type;

/* =========================================================================================================================== */
/* ====================================                 SN_Flash                       ======================================= */
/* =========================================================================================================================== */
/**
  * @brief FLASH Memory Control Registers (SN_FLASH)
  */

typedef struct { 
  union {
    __IO uint32_t  FLASH_CTRL;                       /*!< Offset:0x08 Comparator Capture Output Match register                 */
    
    struct {           
      __IO uint32_t  PP          :  1;               
      __IO uint32_t  BP          :  1;   
      __IO uint32_t  WP4         :  1;
      __IO uint32_t  WP          :  1;
      __IO uint32_t  READ4       :  1;
      __IO uint32_t  READ2       :  1; 
      __IO uint32_t  FAST_READ   :  1;
      __IO uint32_t  READ        :  1;
      __IO uint32_t  DE_CYCLE    :  4;
      __IO uint32_t  CLK         :  2;
      __IO uint32_t  QUAD        :  1;               
      __IO uint32_t  EN          :  1;  
	  __I  uint32_t  RSEREVED	:  16;  	               
    } FLASH_CTRL_b;                                                                             
  };

  union {
    __IO uint32_t  FLASH_CMD;                       /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {         
      __I  uint32_t  RESERVED0   :  1;
      __I  uint32_t  WIP         :  1; 
      __IO uint32_t  DT          :  2; 
      __IO uint32_t  CUSTOMER    :  1;
      __IO uint32_t  C_ADDR      :  1; 
      __I  uint32_t  RESERVED6   :  1; 
      __IO uint32_t  C_READ      :  1;
      __IO uint32_t  CE        	 :  1; 
      __IO uint32_t  BE        	 :  1;
      __IO uint32_t  SE        	 :  1; 
      __IO uint32_t  SR_W        :  1;   
      __IO uint32_t  RDP         :  1;  
      __IO uint32_t  DP          :  1; 
      __IO uint32_t  SR_R        :  1;  
      __IO uint32_t  ID_R        :  1; 
	  __I  uint32_t  RSEREVED	:  16;   
    } FLASH_CMD_b;                                 
  };                                   

  union {
    __IO uint32_t  FLASH_ADDRH;                     /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {                                               
	  __IO  uint32_t  ADDR         :  7;
    __I   uint32_t  RESERVED     :  25;   
    } FLASH_ADDRH_b;                        
  };   

  union {
    __IO uint32_t  FLASH_ADDRL;                     /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {                                               
      __IO  uint32_t  ADDR       :  16;
      __I   uint32_t  RESERVED   :  16;             /*!< Checksum calculation choosen                                          */
    } FLASH_ADDRL_b;                                /*!< BitSize                                                               */
  }; 

  union {
    __IO uint32_t  FLASH_CMD_DATA;                  /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {                                               
	    __IO  uint32_t  DATA       :  8;
      __I   uint32_t  RESERVED   :  24;             /*!< Checksum calculation choosen                                          */
    } FLASH_CMD_DATA_b;                             /*!< BitSize                                                               */
  }; 

  union {
    __IO uint32_t  FLASH_STAT;                      /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {                                               
	    __IO  uint32_t  DATA       :  8;
      __I   uint32_t  RESERVED   :  24;             /*!< Checksum calculation choosen                                          */
    } FLASH_STAT_b;                                 /*!< BitSize                                                               */
  }; 

  union {
    __IO uint32_t  FLASH_ID;                        /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {                                               
	    __IO  uint32_t  DATA       :  16;
      __I   uint32_t  RESERVED   :  16;             /*!< Checksum calculation choosen                                          */
    } FLASH_ID_b;                                   /*!< BitSize                                                               */
  }; 

  union {
    __IO uint32_t  FLASH_RDATA;                     /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {                                               
      __IO  uint32_t  DATA       :  16;
      __I   uint32_t  RESERVED   :  16;             /*!< Checksum calculation choosen                                          */
    } FLASH_RDATA_b;                                /*!< BitSize                                                               */
  }; 
  union {
    __IO uint32_t  FLASH_WDATA;                     /*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {                                              
	    __IO  uint32_t  DATA       :  16;
      __I   uint32_t  RESERVED   :  16;             /*!< Checksum calculation choosen                                          */
    } FLASH_WDATA_b;                                /*!< BitSize                                                               */
  };
  
} SN_FLASH_Type;




/* =========================================================================================================================== */
/* ====================================                 SN_SDCARD0                     ======================================= */
/* =========================================================================================================================== */
/**
  * @brief SDCARD Control Registers (SN_SDCARD)
  */

typedef struct { 

    __IO uint32_t  SPI_CMD_ARGL;                    /*!< Offset:0x00 SD Card Command Argument Low Word	[15:0]								 */
    __IO uint32_t  SPI_CMD_ARGH;       	            /*!< Offset:0x04 SD Card Command Argument High Word	[15:0]								 */
    __IO uint32_t  SPI_CMD_INDEX;                   /*!< Offset:0x08 SD Card Command Index	[7:0]															 */

  union {
    __IO uint32_t  SD_CMD;                          /*!< Offset:0x0C SD Card Command Register																	 */
    
    struct {         
      __I  uint32_t  RESERVED0   	:  1;
      __IO uint32_t  CM12_SEL    	:  2; 
      __IO uint32_t  CM25_18_SEL 	:  2; 
      __IO uint32_t  RESERVED1   	:  3;
      __IO uint32_t  SD_CMD_NIB  	:  4;  
    } SD_CMD_b;                             
  };                                   
    __IO uint32_t  RESERVED0; 										  /*!< Offset:0x10                   																				 */
  union {
    __IO uint32_t  SD_STAT;                         /*!< Offset:0x14 SD Card Status Register                                   */
    
    struct {                                               
	    __IO  uint32_t  TRAN_ERR 		 :  1;
      __IO  uint32_t  TRAN_DONE    :  1; 
      __I   uint32_t  RESERVED0  	 :  2;	    
	    __IO  uint32_t  CRC_ERR 		 :  1;
      __I   uint32_t  RESERVED1  	 :  1;	 
      __IO  uint32_t  WR_DONE   	 :  1;   
      __I   uint32_t  RESERVED2  	 :  3;	 
      __IO  uint32_t  TO_DONE   	 :  1;   
    } SD_STAT_b;                        
  };   
    __IO uint32_t  RESERVED1; 									    /*!< Offset:0x18                                                           */
  union {
    __IO uint32_t  SD_CTRL;                         /*!< Offset:0x1C SD Card Control Register                                  */
    
    struct {                                               
	    __IO  uint32_t  SD_MODE 		 :  2;
      __O   uint32_t  SPI_CMD_TRIG :  1;
      __O   uint32_t  SPI_BUSY_TRIG : 1;
	    __I   uint32_t  SPI_DONE 		 :  1;
      __IO  uint32_t  SPI_RW   	   :  1;
      __IO  uint32_t  CRC_EN	   	 :  2;
      __IO  uint32_t  CMD_DATA_R   :  1;
    } SD_CTRL_b;                                    /*!< BitSize                                                               */
  }; 
    __IO uint32_t  SD_RW_LEN; 										  /*!< Offset:0x20                                                           */
    __IO uint32_t  RESERVED3; 										  /*!< Offset:0x24                                                           */

  union {
    __IO uint32_t  RESPONSE_MODE;                   /*!< Offset:0x28 SD Card Response Register                                 */    
    struct {                                               
	    __IO  uint32_t  NUM	         :  4;
      __IO  uint32_t  MODE  	     :  1;
    } RESPONSE_MODE_b;                              /*!< BitSize                                                               */
  }; 

		__IO uint32_t  SD_SPEED;                        /*!< Offset:0x2C SD Card Speed Control Register                            */
		__IO uint32_t  RESERVED4; 						          /*!< Offset:0x30  [15:0]                                                   */
    __IO uint32_t  CRC7; 	    							        /*!< Offset:0x34 SD Card 7bit CRC for CMD/RESPONSE	[6:0]									 */
    __IO uint32_t  CRC16_0; 							          /*!< Offset:0x38 SD Card 16bit CRC for DATA0	[15:0]											 */
    __IO uint32_t  CRC16_1; 							          /*!< Offset:0x3C SD Card 16bit CRC for DATA1  [15:0]											 */
    __IO uint32_t  CRC16_2; 							          /*!< Offset:0x40 SD Card 16bit CRC for DATA2	[15:0]											 */
    __IO uint32_t  CRC16_3; 							          /*!< Offset:0x44 SD Card 16bit CRC for DATA3	[15:0]											 */
    __IO uint32_t  TIME_CNT_L; 						          /*!< Offset:0x48 SD Card Time out counter [15:0]													 */
    __IO uint32_t  TIME_CNT_H; 						          /*!< Offset:0x4C SD Card Time out counter [29:16]													 */
    __IO uint32_t  RESERVED5; 						          /*!< Offset:0x50	                                                         */
    __IO uint32_t  RESERVED6; 						          /*!< Offset:0x54	                                                         */
    __IO uint32_t  RESERVED7; 			                /*!< Offset:0x58	                                                         */
    __IO uint32_t  RESERVED8;											  /*!< Offset:0x5C	                                                         */
    __IO uint32_t  RESERVED9;											  /*!< Offset:0x60	                                                         */
    		
	union {
		__IO uint32_t  SDIO_MODE;						/*!< Offset:0x64	SDIO_MODE Control                                        */
	struct {
		__IO	uint32_t	SDIO_EN					:	1;					
		__IO	uint32_t	SDIO_4BIT_MODE			:	1;
		__IO	uint32_t	SDIO_INT_EN				:	1;
		__I		uint32_t	SDIO_INT_FLG			:	1;
		__O		uint32_t	CLR_SDIO_INT			:	1;
		__IO	uint32_t	SDIO_IO_ABORT_EN		:	1;//Dummy for test
		__IO	uint32_t	RESERVED0				:	2;
		__IO	uint32_t	SDIO_REG_FUNC			:	3;
		__IO	uint32_t	RESERVED1				:	1;				
		__IO	uint32_t	SDIO_REG_OPCODE			:	1;
		__IO	uint32_t	SDIO_REG_BLK			:	1;
		}SDIO_MODE_b;
	};											  
    __IO uint32_t  RESERVEDB;											  /*!< Offset:0x68	                                                         */
    __IO uint32_t  RESERVEDC;											  /*!< Offset:0x6C	                                                         */
    __IO uint32_t  SD_REG1; 	 				              /*!< Offset:0x70	[7:0] 1ch                                                */
    __IO uint32_t  SD_REG2; 					              /*!< Offset:0x74	[7:0] 1dh                                                */
    __IO uint32_t  SD_REG3; 					              /*!< Offset:0x78	[7:0] 1eh                                                */
    __IO uint32_t  SD_REG4; 					              /*!< Offset:0x7C	[7:0] 1fh                                                */
} SN_SDCARD_Type;



/* =========================================================================================================================== */
/* ====================================                   SN_NAND                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief NAND Flash Control Registers (SN_NF)
  */

typedef struct { 

    __IO uint32_t  NF_ADDRL;                        /*!< Offset:0x00 [15:0]                                                    */
    __IO uint32_t  NF_ADDRH;       			            /*!< Offset:0x04 [15:0]                                                    */
    __IO uint32_t  RESERVED2;        		            /*!< Offset:0x08                                                           */

  union {
    __IO uint32_t  NF_CMD;                          /*!< Offset:0x0C                                                           */
    
    struct {         
      __IO uint32_t  RESERVED5  	:  1; 
      __IO uint32_t  WR_CHK_SEL   :  2;
      __IO uint32_t  CMD_ADDR_SEL :  2; 
      __IO uint32_t  RESERVED1    :  3;  
      __IO uint32_t  NF_CMD_NIB   :  4;
    } NF_CMD_b;                                 
  };                                   
    __IO uint32_t  RESERVED0; 										  /*!< Offset:0x10                                                           */
  union {
    __IO uint32_t  NF_STAT;                         /*!< Offset:0x14                                                           */
    
    struct {                                               
			__IO  uint32_t  NF_CMD_STATUS  :  2;
      __I   uint32_t  RESERVED0   	 :  1;
      __IO  uint32_t  NF_ECC_FF   	 :  1;	    
			__IO  uint32_t  ECC_ERR 		   :  1;
      __IO  uint32_t  ECC_FAIL   	   :  1;	 
      __IO  uint32_t  PROG_ERR   	   :  1;   
      __IO  uint32_t  ERASE_ERR   	 :  1;	 
      __IO  uint32_t  CRC_ERR_CNT    :  2;   
      __IO  uint32_t  TIME_OUT_ERR   :  1;   
      __IO  uint32_t  NF_INFO_ERR    :  1; 
	    __IO  uint32_t  ECC_ERR_CNT    :  4;   
    } NF_STAT_b;                        
  };   
  union {
    __IO uint32_t  NF_CMD_BUF;                      /*!< Offset:0x18                                                           */
    
    struct {                                               
	    __IO  uint32_t  CMD_BUF_STATUS :  5;
      __IO  uint32_t  CMD_BUF_CLEAR  :  3; 	 
    } NF_CMD_BUF_b;                                 /*!< BitSize                                                               */
  };

  union {
    __IO uint32_t  NF_CTRL;                         /*!< Offset:0x1C                                                           */
    
    struct {                                               
	    __IO  uint32_t  NF_MODE 		 	 :  2;
	    __I   uint32_t  RESERVED0      :  2;
      __IO  uint32_t  MS_RDY     	   :  1; 
      __IO  uint32_t  MS_REG_RW      :  1;	    
			__IO  uint32_t  EXTRA_EN 		   :  1;
      __IO  uint32_t  ECC_EN   	     :  1;	 	 
    } NF_CTRL_b;                                    /*!< BitSize                                                               */
  }; 
    __IO uint32_t  NF_RW_LENGTH; 									  /*!< Offset:0x20                                                           */

  union {
    __IO uint32_t  NF_PAGE_INFO1;                   /*!< Offset:0x24                                                           */
    struct {                                               
			__IO  uint32_t  PG_WR_SEQ_W	   :  4;
			__IO  uint32_t  RESERVED0      :  4;
      __IO  uint32_t  USER_DEF_W  	 :  5;
    } NF_PAGE_INFO1_b;                              /*!< BitSize                                                               */
  };  

  union {
    __IO uint32_t  NF_PAGE_INFO2;                   /*!< Offset:0x28 */
    struct {                                               
			__IO  uint32_t  LBA_W	         :  14;
    } NF_PAGE_INFO2_b;                              /*!< BitSize                                                               */
  }; 

  union {
    __IO uint32_t  NF_INFO;                         /*!< Offset:0x2C */
    
    struct {                                               
			__IO  uint32_t  ADDR_CYCLE     :  2;
      __IO  uint32_t  PAGE_SIZE      :  2;
			__IO  uint32_t  BLOCK_SIZE     :  2;
    } NF_INFO_b;                                    /*!< BitSize                                                               */
	};

  union {
    __IO uint32_t  NF_ACC;                          /*!< Offset:0x30                                                           */
    
    struct {                                               
			__IO  uint32_t  RD_WIDTH       :  2;
      __IO  uint32_t  WR_WIDTH       :  2;
			__I   uint32_t  RESERVED       :  4;
			__O   uint32_t  INFO_CRC       :  8;
    } NF_ACC_b;                                     /*!< BitSize                                                               */
	};
 
    __IO uint32_t  RESERVED0C; 	                    /*!< Offset:0x34                                                           */
    __IO uint32_t  RESERVED0B; 	                    /*!< Offset:0x38                                                           */
    __IO uint32_t  RESERVED0A; 	                    /*!< Offset:0x3C                                                           */
    __IO uint32_t  RESERVED10; 	                    /*!< Offset:0x40                                                           */
    __IO uint32_t  RESERVED11; 	                    /*!< Offset:0x44                                                           */
    __IO uint32_t  TIME_CNT_L; 	                    /*!< Offset:0x48                                                           */
    __IO uint32_t  TIME_CNT_H; 	                    /*!< Offset:0x4C                                                           */
    __IO uint32_t  RESERVED4; 	                    /*!< Offset:0x50                                                           */
    __IO uint32_t  RESERVED5; 	                    /*!< Offset:0x54                                                           */
    __IO uint32_t  RESERVED6; 	                    /*!< Offset:0x58                                                           */
   
	union {
    __IO uint32_t  NF_PG_WR;                        /*!< Offset:0x5C                                                           */
    
    struct {                                               
			__O   uint32_t  PG_WR_SEQ      :  4;
      __O   uint32_t  PAGE_EMPTY     :  1;
			__IO  uint32_t  RESERVED       :  2;
			__O   uint32_t  USER_DEF       :  5;
    } NF_PG_WR_b;                                   /*!< BitSize                                                               */
	};
		
	  __O  uint32_t  NF_LBA;                          /*!< Offset:0x60                                                           */
    __IO uint32_t  RESERVED19;  									  /*!< Offset:0x64                                                           */
    __IO uint32_t  RESERVED1A;  									  /*!< Offset:0x68                                                           */
    __IO uint32_t  RESERVED1B;										  /*!< Offset:0x6C                                                           */
    __IO uint32_t  NF_REG1; 	            				  /*!< Offset:0x70                                                           */
    __IO uint32_t  NF_REG2; 	            				  /*!< Offset:0x74                                                           */
    __IO uint32_t  NF_REG3; 	              			  /*!< Offset:0x78                                                           */
    __IO uint32_t  NF_REG4; 	            				  /*!< Offset:0x7C                                                           */
    __IO uint32_t  RESERVED20;	  
    __IO uint32_t  RESERVED21; 	 
    __O uint32_t   NF_ECC_ADDR;               		  /*!< Offset:0x88                                                           */
    __O uint32_t   NF_ECC_MASK;               		  /*!< Offset:0x8C                                                           */

	union { 
    __O  uint32_t  NF_ECC_REQ;                      /*!< Offset:0x90                                                           */
    
    struct {                                               
			__O   uint32_t  ECC_DN         :  1;
      __O   uint32_t  ECC_REQ        :  1;
    } NF_ECC_REQ_b;                                 /*!< BitSize                                                               */		
	};
   
} SN_NF_Type;


/* =========================================================================================================================== */
/* ====================================                    SN_JPEG                     ======================================= */
/* =========================================================================================================================== */
/**
  * @brief JPEG Control Registers (SN_JPEG)
  */

typedef struct {													 					/*!< SN_IDMA Structure                                                     */ 

  union {
    __IO uint32_t  JPEG_CTRL;                       /*!< Offset:0x00 JPEG Control Register																	   */ 
    struct {         
      __IO uint32_t  RESERVED0   	       : 10;			/*!< RESERVED 										                  				  				     */
			__IO uint32_t  Input_Frame_End     :  1; 			/*!< Input_Frame_End 0: Normal, 1: Input data frame end 				  				 */
      __IO uint32_t  Insert_Q_Table	     :  1; 			/*!< Insert_Q_Table  0: Normal, 1: Insert Q Table 										     */
      __IO uint32_t  YUV_Format   	     :  1;			/*!< YUV_Format 0: 411 format(4x1,1x1,1x1), 1: 422 format(2x1,1x1,1x1)     */
      __IO uint32_t  JFIF_Mode  	       :  1;  		/*!< JFIF_Mode  0: Non-JFIF, 1: JFIF 										                   */
			__IO uint32_t  Codec_Type  	       :  1;  		/*!< Codec_Type 0: Decoder, 1: Encoder										                 */
			__IO uint32_t  Codec_ON  	         :  1;  		/*!< Codec_ON   0: OFF, 1: ON 										                  			 */	
    } JPEG_CTRL_b;																	/*!< BitSize                                                               */
  };

  union {
    __IO uint32_t  JPEG_STAT;                       /*!< Offset:0x04 JPEG Status Register                                      */
    struct {                                               
	    __O  uint32_t  ERR_Signal 	   		 :  1;			/*!< ERR_Signal 0: Normal, 1:Error 										                  	 */
      __O  uint32_t  Output_data_request :  1; 			/*!< Output_data_request 0: not ready, 1: ready for read 		 				       */
      __O  uint32_t  Input_data_request	 :  1;	    /*!< Input_data_request  0: Don't input data, 1: Input data request        */
			__O	 uint32_t	 Q_Table_Full				 :	1;			/*!< Q_Table_Full 0: Q_table not full, 1: Q_table is full 						     */
      __IO uint32_t  RESERVED0  	       :  9;			/*!< RESERVED 										                  				  				     */
			__O  uint32_t  Output_Color				 :  2;			/*!< Output_Color 										                  				  				 */
			__O  uint32_t  OF_End 	 					 :  1; 			/*!< OF_End  0: Normal, 1: Output data frame end 										       */
    } JPEG_STAT_b;																	/*!< BitSize                                                               */
  };

  	__IO uint32_t  RESERVED1; 											/*!< Offset:0x08  RESERVED                                                 */
		__IO uint32_t  RESERVED2; 											/*!< Offset:0x0C  RESERVED                                                 */
    __IO uint32_t  JPEG_Write_Q_Table; 		     			/*!< Offset:0x10  JPEG_Write_Q_Table Register[7:0]                         */
		__IO uint32_t  IDMA_Select; 			 		  			  /*!< Offset:0x14  IDMA_Select Register 1: RAM, 0:CSC                       */																										

} SN_JPEG_Type;


/* =========================================================================================================================== */
/* ====================================                   SN_CSC                       ======================================= */
/* =========================================================================================================================== */
/**
  * @brief CSC Control Registers (SN_CSC)
  */

typedef struct {													 					/*!< SN_IDMA Structure                                                     */

  union {
    __IO uint32_t  CSC_CTRL;  											/*!< Offset:0x00 CSC Control Register            													 */                          
    struct {         
      
      __O  uint32_t	 Output_Valid		 :  1;					/*!< Output_Valid 										                  				  				 */
			__O  uint32_t	 Input_Request	 :  1;				  /*!< Input_Request 										                  				  				 */
			__IO uint32_t  RESERVED1			 :  6;					/*!< RESERVED 										                  				  				     */
			__IO uint32_t  YCbCr_Mode		   :  1;					/*!< YCbCr_Mode 0: 420 mode, 1: 422 mode																   */
			__IO uint32_t  RESERVED2			 :  2;					/*!< RESERVED 										                  				  				     */
			__IO uint32_t  En_Tr			 		 :  1;					/*!< Tr Enable                                                             */
      __IO uint32_t  CSC_Mode	       :  2; 					/*!< 00: Data input to line, 01: YCbCr to RGB (Data in/line buffer)			   */
																										/*!< 10: YCbCr to RGB (Data in/Data out), 11: RGB to YCbCr(Data in/Data out)*/
			__IO uint32_t  DMA_Mode        :  1; 					/*!< DMA_Mode 0: By MPU, 1: By DMA                                         */
			__IO uint32_t  CSC_ON   	     :  1;					/*!< CSC Enable                                                            */
    } CSC_CTRL_b;																		/*!< BitSize                                                               */
  };

		__I  uint32_t  CSC_DATA_IN;        	      			/*!< Offset:0x04  CSC Data In Register[15:0]                               */
		__O  uint32_t  CSC_DATA_OUT;       				      /*!< Offset:0x08  CSC Data Out Register[15:0]                              */
  	__IO uint32_t  RESERVED3; 											/*!< Offset:0x0C                                                           */
		__IO uint32_t  RESERVED4; 											/*!< Offset:0x10                                                           */
		__IO uint32_t  Tr_Table_Addr; 		  						/*!< Offset:0x14  Tr Table Address Register 12:0]                          */
		__IO uint32_t  CSC_DMA_DATA_IN_Addr_L; 		      /*!< Offset:0x18  Data In Addr_L[15:0]                                     */
		__IO uint32_t  CSC_DMA_DATA_IN_Addr_H; 			  	/*!< Offset:0x1C  Data In Addr_H[15:0]                                     */
		__IO uint32_t  CSC_DMA_DATA_OUT_Addr_L;         /*!< Offset:0x20 //for jpeg encoder                                        */
		__IO uint32_t  CSC_DMA_DATA_OUT_Addr_H;         /*!< Offset:0x24                                                           */
		__IO uint32_t  JPEG_LINE_SIZE;                  /*!< Offset:0x28                                                           */

} SN_CSC_Type;

/* =========================================================================================================================== */
/* ====================================                   SN_IDMA                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief 
  */

typedef struct {                                    /*!< SN_IDMA Structure                                                     */
  

    __IO uint32_t  CH_RAM_ADDR;                     /*!< Offset:0x00 Ram address                                               */
    
    __IO uint32_t  CH_LEN;  
	                      
  union {
    __IO uint32_t  CH_CTRL;                       	/*!< Offset:0x08 Comparator Capture Output Match register                  */
    
    struct {
		__IO uint32_t  START              :  1;
		__IO uint32_t  WR_RAM             :  1;
		__IO uint32_t  PRAMM              :  1;
 		__IO uint32_t  AD_PASS            :  1;
 		__IO uint32_t  SCALAR             :  2;
    } CH_CTRL_b;                                    /*!< BitSize                                                               */
  };
    __IO uint32_t  CH_DIP_ADDR;

} SN_IDMA_Type;

/* =========================================================================================================================== */
/* ====================================                    SN_PPU                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief
  */

typedef struct {                                    /*!< SN_PPU Structure for PPU                                             */

  union {
    __IO uint32_t  PPU_CTRL;                   		  /*!< Offset:0x00                     																			*/
    
    struct {
      __IO uint32_t  TX1EN      :  1;             
      __IO uint32_t  TX2EN      :  1;             
      __IO uint32_t  SPEN       :  1;							
      __IO uint32_t  TX3EN 			:  1;
			__IO uint32_t  PPUEN      :  1;
			__IO uint32_t  TXPalRAM_Sel :  1;
			__IO uint32_t  PIXEL_LINE_Sel :  1;
			__IO uint32_t  Display_Resolution :  1;				//0:Display line is 320 pixel, 1:Display line is 321~640 any pixel
				
    } PPU_CTRL_b;                                   /*!< BitSize                                                              */
  };

    __IO uint32_t  TX1_X_POS; 										  /*!< Offset:0x04                    																			*/
    __IO uint32_t  TX1_Y_POS; 										  /*!< Offset:0x08                    																			*/

  union {
		__IO uint32_t  TX1_ATTR; 										    /*!< Offset:0x0C                    																			*/
    
    struct {
      __IO uint32_t  Color      :  2;             
      __IO uint32_t  HFlip      :  1;             
      __IO uint32_t  VFlip      :  1;							
      __IO uint32_t  HSize      :  2;
			__IO uint32_t  VSize      :  2;
			__IO uint32_t  Palette    :  4;
			__IO uint32_t  Depth      :  2;
    } TX1_ATTR_b;                                   /*!< BitSize                                                              */
  };
	
	union {
		__IO uint32_t  TX1_CTRL; 										    /*!< Offset:0x10                    																			*/
    
    struct {
      __IO uint32_t  BMP        :  1;             
      __IO uint32_t  AttrInReg  :  1;             
      __IO uint32_t  WAP        :  1;							
      __IO uint32_t  RGB        :  1;
			__IO uint32_t  RESERVED0  :  2;
			__IO uint32_t  VCMP_EN    :  1;
			__IO uint32_t  BLD_EN     :  1;
			__IO uint32_t  VSCRN_SIZE :  1;
    } TX1_CTRL_b;                                   /*!< BitSize                                                              */
  };
	
	  __IO uint32_t  TX1_NUM_PTR; 		 			          /*!< Offset:0x14 [15:0]                   																*/
		__IO uint32_t  TX1_ATTR_PTR; 		 			          /*!< Offset:0x18 [15:0]                   																*/
		__IO uint32_t  TX1_DISP_CTRL; 	 			          /*!< Offset:0x1C [14:0]                   																*/
		__IO uint32_t  TX1_PATT_ADDRL;	 			          /*!< Offset:0x20 [15:0]                   																*/
		__IO uint32_t  TX1_PATT_ADDRH;	 			          /*!< Offset:0x24 [15:0]                   																*/
    __IO uint32_t  TX2_X_POS; 			 			          /*!< Offset:0x28 [8:0]                   																	*/
    __IO uint32_t  TX2_Y_POS; 			 			          /*!< Offset:0x2C [7:0]                   																	*/
    
	union {	
		__IO uint32_t  TX2_ATTR; 										    /*!< Offset:0x30                    																			*/
    struct {
      __IO uint32_t  Color      :  2;             
      __IO uint32_t  HFlip      :  1;             
      __IO uint32_t  VFlip      :  1;							
      __IO uint32_t  HSize      :  2;
			__IO uint32_t  VSize      :  2;
			__IO uint32_t  Palette    :  4;
			__IO uint32_t  Depth      :  2;
    } TX2_ATTR_b;                                   /*!< BitSize                                                              */
	}; 

  union {
		__IO uint32_t  TX2_CTRL; 										    /*!< Offset:0x34                    																			*/
    
		struct {
      __IO uint32_t  BMP        :  1;             
      __IO uint32_t  AttrInReg  :  1;             
      __IO uint32_t  WAP        :  1;							
      __IO uint32_t  RGB        :  1;
			__IO uint32_t  RESERVED0  :  2;
			__IO uint32_t  VCMP_EN    :  1;
			__IO uint32_t  BLD_EN     :  1;
			__IO uint32_t  VSCRN_SIZE :  1;
    } TX2_CTRL_b;                                   /*!< BitSize                                                              */
  };		
		
	  __IO uint32_t  TX2_NUM_PTR; 		 			          /*!< Offset:0x38 [12:0]                   																*/
		__IO uint32_t  TX2_ATTR_PTR; 		 			          /*!< Offset:0x3C [12:0]                   																*/
		__IO uint32_t  TX2_DISP_CTRL; 	 			          /*!< Offset:0x40 [14:0]                   																*/
		__IO uint32_t  TX2_PATT_ADDRL;	 			          /*!< Offset:0x44 [15:0]                   																*/
		__IO uint32_t  TX2_PATT_ADDRH;	 			          /*!< Offset:0x48 [15:0]                   																*/
		__IO uint32_t  SPR_PATT_ADDRL;	 			          /*!< Offset:0x4C [15:0]                   																*/
		__IO uint32_t  SPR_PATT_ADDRH;	 			          /*!< Offset:0x50 [15:0]                   																*/

	union {
		__IO uint32_t  DMA_REQ;					 //[15]				  /*!< Offset:0x54                    																			*/
		
		struct {
			__IO uint32_t  RESERVED0  :  15;
			__IO uint32_t  START      :  1;
		} DMA_REQ_b;
	};
	
		__IO uint32_t  DMA_SRC_ADDRL;		 			          /*!< Offset:0x58  [15:0]                  																*/
		__IO uint32_t  DMA_SRC_ADDRH;		 			          /*!< Offset:0x5C  [15:0]                  																*/
		__IO uint32_t  DMA_DES_ADDRL;		 			          /*!< Offset:0x60  [15:0]                  																*/
		__IO uint32_t  DMA_DES_ADDRH;		 	  	          /*!< Offset:0x64  [15:0]                   																*/
		__IO uint32_t  DMA_LEN;					 			          /*!< Offset:0x68  [15:0]                   																*/
	
	union {	
		__IO uint32_t  Blend_CTRL;       			          /*!< Offset:0x6C  [4:0]                  																	*/
		
		struct {
			__IO uint32_t  Level      :  5;
		} Blend_CTRL_b;
	};

	union {
		__IO uint32_t  Backdrop_Color;	 		            /*!< Offset:0x70  RGB565	                 																*/
		
		struct {
			__IO uint32_t  B          :  5;
			__IO uint32_t  G          :  6;
			__IO uint32_t  R          :  5;
		} Backdrop_Color_b;
	};
	
	union {
		__IO uint32_t  Bright_CTRL;			 	              /*!< Offset:0x74  [7:0]                  																	*/
		
		struct {
			__IO uint32_t  Level      :  5;
			__IO uint32_t  BRM        :  1;               /*!0: Increase, 1: Decrease                                               */
			__IO uint32_t  BROUT      :  1;               /*!0: Inside, 1: Outside                                                  */
			__IO uint32_t  BREN       :  1;               /*!0: Disable, 1: Enable                                                  */
		} Bright_CTRL_b;
	};
	
		__IO uint32_t  Brightness_STA_X;      			    /*!< Offset:0x78 [8:0]                   																	*/
		__IO uint32_t  Brightness_STA_Y;        	      /*!< Offset:0x7C [7:0]                  																	*/
		__IO uint32_t  Brightness_END_X;      	        /*!< Offset:0x80 [8:0]                  																	*/
		__IO uint32_t  Brightness_END_Y;     	          /*!< Offset:0x84 [7:0]                   																	*/
		__IO uint32_t  VCMP_Scale;			     			      /*!< Offset:0x88 [2:0]                  																	*/
		__IO uint32_t  VCMP_Offset;			  			        /*!< Offset:0x8C [7:0]                   																	*/
		__IO uint32_t  TX_LINE_STA_ADDRH;               /*!< Offset:0x90 [7:0]	 TX1  [23:16] TX2                 								*/

		__IO uint32_t  TFT_HSYNC_BACK_PORCH;	          /*!< Offset:0x94 [15:0]                   																*/
		__IO uint32_t  TFT_HSYNC_FRONT_PORCH;	          /*!< Offset:0x98 [15:0]                  																	*/
		__IO uint32_t  TFT_VSYNC_BACK_PORCH;	          /*!< Offset:0x9C [15:0]                  																	*/
		__IO uint32_t  TFT_VSYNC_FRONT_PORCH;	          /*!< Offset:0xA0 [15:0]                   																*/
		__IO uint32_t  TFT_HSYNC_PULSE_WIDTH;	          /*!< Offset:0xA4 [15:0] 0:1, 1:2, ...       															*/
		__IO uint32_t  TFT_VSYNC_PULSE_WIDTH;	          /*!< Offset:0xA8 [15:0]0:1, 1:2, ...       																*/
		__IO uint32_t  TFT_HSYNC_DISPLAY;			          /*!< Offset:0xAC [7:0]0:320, 1:640, 2:960 																*/
	union {	
		__IO uint32_t  TFT_BLK_INT_CTRL; 			          /*!< Offset:0xB0  [1:0]                  																	*/
		struct {
			__IO uint32_t  HBLK       :  1; 
			__IO uint32_t  VBLK       :  1; 
		} TFT_BLK_INT_CTRL_b;
	};
		
	union {	
		__IO uint32_t  TFT_BLK_INT_STAT; 			          /*!< Offset:0xB4 [1:0]                   																	*/
		struct {
			__IO uint32_t  HBLK       :  1; 
			__IO uint32_t  VBLK       :  1; 
		} TFT_BLK_INT_STAT_b;
	};
	
	union {
		__IO uint32_t  TFT_CTRL; 				 			          /*!< Offset:0xB8 [1:0]                   																	*/
		
		struct {
			__IO uint32_t  Mode       :  2;               /*!< 00:UPS051                     																				*/
			__IO uint32_t  RESERVED0  :  2;
			__IO uint32_t  RGB_SEQ_052 :  1;
			__IO uint32_t  RESERVED1  :  1;
			__IO uint32_t  EVEN_RGB_SEQ_051 :  2;
			__IO uint32_t  RESERVED2  :  1;
			__IO uint32_t  ODD_RGB_SEQ_051 :  2;
			__IO uint32_t  DCLK_Pol   :  1;               /*!< 0: Negative polarity, 1: Positive polarity                   				*/
			__IO uint32_t  HSYNC_Pol  :  1;               /*!< 0: Negative polarity, 1: Positive polarity                   				*/                     																				
			__IO uint32_t  VSYNC_Pol  :  1;               /*!< 0: Negative polarity, 1: Positive polarity                   			  */                     																				
			__IO uint32_t  PAREL_OPT  :  1;
			__IO uint32_t  EN  				:  1;
		} TFT_CTRL_b;
	};
	
	__IO uint32_t  TFT_DCLK_LEN; 											/*!< Offset:0xBC                                                       		*/
	
	union {
		__IO uint32_t  MPU_8080_CTRL; 				 				  /*!< Offset:0xC0                    																			*/
		
		struct {
			__IO uint32_t  MPUS       :  1;               /*!< 0:Idle, 1:Start             			           		                      */
			__IO uint32_t  MPURW  		:  2;               /*!< 0:Read Command, 1:Read Data, 2:Write Command, 3:Write Data           */
			__IO uint32_t  ASRM				:  1;               /*!< 0:D7 ~ D0 is valid, 1:D15 ~ D0 is valid(2 bytes)             				*/
			__IO uint32_t  HLF				:  1;               /*!< 0:High byte first, 1:Low byte first             					            */
			__IO uint32_t  RESERVED0  :  3;
			__IO uint32_t  PPU_8080_EN :  1;              /*!< 0:No Action, 1:PPU display via 8080             					            */
			__IO uint32_t  RESERVED1  :  3;
			__IO uint32_t  DMODE			:  1;               /*!< 0:8-bit mode, 1:16-bit mode            					                    */
			__IO uint32_t  RESERVED2  :  2;
			__IO uint32_t  MPUEN  		:  1;               /*!< 0:Disable, 1:Enable           					                              */
		} MPU_8080_CTRL_b;
	};

	union {
		__IO uint32_t  MPU_8080_WIDTH_CTRL; 	 				  /*!< Offset:0xC4                    																			*/
		
		struct {
			__IO uint32_t  RW_LP      :  8;
			__IO uint32_t  RW_HP      :  8;
		} MPU_8080_WIDTH_CTRL_b;
	};
	
	__IO uint32_t  MPU_8080_DATA; 	 								  /*!< Offset:0xC8                    																			*/
	__IO uint32_t  MPU_8080_DMA_RAM_ADDR; 					  /*!< Offset:0xCC                    																			*/
	
	union {
		__IO uint32_t  MPU_8080_DMA_CTRL; 						  /*!< Offset:0xD0                    																			*/
		struct {
			__IO uint32_t  START      :  1;               /*!< 0:Stop, 1:Start                    																	*/
			__IO uint32_t  MODE_SEL   :  1;               /*!< 0:8080 -> AHB RAM (Read)                    													*/
																			              /*!< 1:AHB RAM -> 8080 (Write)                    												*/
		} MPU_8080_DMA_CTRL_b;
	};
	
	__IO uint32_t  MPU_8080_DMA_LEN; 								  /*!< Offset:0xD4                    																			*/

	__IO uint32_t  OTHER_RES_DISP_START_X; 					/*!< Offset:0xD8                    																				*/
	__IO uint32_t  OTHER_RES_DISP_START_Y; 					/*!< Offset:0xDC                    																				*/
	__IO uint32_t  TX1_DISP_CTRL2; 									/*!< Offset:0xE0                    																				*/
	
																									/* line 240~639 */
	__IO uint32_t  TX2_DISP_CTRL2; 									/*!< Offset:0xE4                    																				*/
																									/* line 240~639 */
	
	__IO uint32_t  OTHER_RES_DISP_SIZE_X; 					/*!< Offset:0xE8                    																				*/
	__IO uint32_t  OTHER_RES_DISP_SIZE_Y; 					/*!< Offset:0xEC                    																				*/	

} SN_PPU_Type;

/* =========================================================================================================================== */
/* ====================================                    SN_CIS                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief CIS Control Registers
  */


typedef struct {                                    /*!< SN_CIS Structure                                                     */
  
  union {
    __IO uint32_t  CIS_CTRL; 		                    /*!< Offset:0x00 CIS register                                             */
    struct {
			__IO uint32_t  CIS_CLK_SEL    :  2;						//0 1
			__IO uint32_t  CIS_PIXEL_CLK  :  1;						//2
			__IO uint32_t  CIS_HERF       :  1;						//3
			__IO uint32_t  CIS_VSYNC      :  1;						//4
			__IO uint32_t  L0_FULL_FLG    :  1;					  //5
			__IO uint32_t  L1_FULL_FLG    :  1;					  //6
			__IO uint32_t  L2_FULL_FLG    :  1;						//7
			__IO uint32_t  PIXEL_FMT      :  1;						//8
			__IO uint32_t  L2B_FMT        :  1;						//9
			__IO uint32_t  WINDOWS_SET    :  1;						//10
			__IO uint32_t  TRANSPARENT_DIS:  1;           //11
			__IO uint32_t  L2B_ENABLE     :  1;						//12
			__IO uint32_t  CIS_DATA       :  1;           //13
			__IO uint32_t  RESERVED1      :  1;           //14
			__IO uint32_t  CIS_ENABLE     :  1;						//15

		} CIS_CTRL_b;
	};
		
    __IO uint32_t  LINE0_ADDR;                      /*!< Offset:0x04                                                          */
    __IO uint32_t  LINE1_ADDR;                      /*!< Offset:0x08                                                          */
    __IO uint32_t  LINE2_ADDR;                      /*!< Offset:0x0C                                                          */
    __IO uint32_t  CIS_COL_N;                       /*!< Offset:0x10                                                          */
	__IO uint32_t  RESERVED0;                       /*!< Offset:0x14                                                          */
    __IO uint32_t  CIS_VOFFSET;                     /*!< Offset:0x18                                                          */
	__IO uint32_t  CIS_HOFFSET;                     /*!< Offset:0x1C                                                          */

	union {
    __IO uint32_t  CIS_SCALE_SIZE;                  /*!< Offset:0x20 CIS_SCALE_SIZE                                           */
    
    struct {
			__IO uint32_t  PIXEL_SKIP       :  2;  
			__IO uint32_t  PIXEL_SEL        :  1;
			__IO uint32_t  RESERVED         :  5;
			__IO uint32_t  LINE_SKIP        :  2;
			__IO uint32_t  LINE_SEL         :  1;         
      __IO uint32_t  SCLAE_EN         :  1;         
      
      
    } CIS_SCALE_SIZE_b;                                                                                             
  };

	__IO uint32_t L2B_LINESKIP;                       /*!< Offset:0x24                                                          */
	
	
} SN_CIS_Type;

/* =========================================================================================================================== */
/* ====================================                 SN_JPEG_DMA                    ======================================= */
/* =========================================================================================================================== */
/**
  * @brief JPEG DMA Control Registers (SN_JPEG_DMA)
  */

typedef struct { 

  union {
    __IO uint32_t  LINE_CTRL;                       /*!< Offset:0x00 DMA LINE Control Register																*/ 
    struct {
      __IO uint32_t	 DMA_EN		 			:  1;
	  __IO uint32_t	 DMA_START			:  1;
    } LINE_CTRL_b;
  };

	__IO uint32_t  LINE_ADDR_0;                     /*!< Offset:0x04 Line Addr0 Register                                      */
	__IO uint32_t  LINE_ADDR_1;                     /*!< Offset:0x08 Line Addr1 Register                                      */
	__IO uint32_t  LINE_NUM;                        /*!< Offset:0x0C LINE NUM Register for TX3                                */
	__IO uint32_t  PIXEL_NUM;                       /*!< Offset:0x10 PIXEL NUM Register for TX3                               */

} SN_JPEG_DMA_Type;


/* =========================================================================================================================== */
/* ====================================                 SN_SCALING_DMA                 ======================================= */
/* =========================================================================================================================== */
/**
  * @brief SCALING DMA Control Registers (SN_SCALING_DMA)
  */

typedef struct { 

  union {
    __IO uint32_t  LINE_CTRL;                       /*!< Offset:0x00 DMA LINE Control Register																*/ 
    struct {
	__IO uint32_t	 DMA_EN		 			:  1;
	__O  uint32_t	 DMA_START			:  1; 
	__IO uint32_t	 SCALE_SEL 			:  1;           /*!< 0:x2, 1:x4																                            */ 
    } LINE_CTRL_b;
  };

	__IO uint32_t  LINE_ADDR;                       /*!< Offset:0x04 Line Addr Register                                       */
	__IO uint32_t  LINE_NUM;                        /*!< Offset:0x08 Line Addr Register                                       */
	__IO uint32_t  PIXEL_NUM;                       /*!< Offset:0x0C Line Addr Register                                       */

} SN_SCALING_DMA_Type;

/* =========================================================================================================================== */
/* ====================================                   SN_ADC                       ======================================= */
/* =========================================================================================================================== */
/**
  * @brief
  */

typedef struct {                                    /*!< SN_SAR_ADC Structure for SAR_ADC                                     */

  union {
		__IO uint32_t  ADP;                   		      /*!< Offset:0x00                 																				  */
		struct {
			__IO uint32_t  AIN0_DI					:  1;	        /*!< AIN0 is digital input(when AIN0 isn¡¦t analog input)                  */
			__IO uint32_t  AIN1_DI					:  1;	        /*!< AIN1 is digital input(when AIN0 isn¡¦t analog input)                 	*/
			__IO uint32_t  AIN2_DI					:  1;	        /*!< AIN2 is digital input(when AIN0 isn¡¦t analog input)                 	*/
			__IO uint32_t  AIN3_DI					:  1;	        /*!< AIN3 is digital input(when AIN0 isn¡¦t analog input)                 	*/
			__IO uint32_t  AIN4_DI					:  1;	        /*!< AIN4 is digital input(when AIN0 isn¡¦t analog input)                  */
			__IO uint32_t  AIN5_DI					:  1;	        /*!< AIN5 is digital input(when AIN0 isn¡¦t analog input)                  */
			__IO uint32_t  RESERVED0				:  2;			
			__IO uint32_t  ADC_VREF_SEL			:  1;	        /*!< SAR-ADC reference voltage select										                 	*/
			__IO uint32_t  ADC_IVREF_EN			:  1;	        /*!< Internal reference voltage power enable                 							*/
			__IO uint32_t  RESERVED1				:  2;
			__IO uint32_t  CHS							:  4;	        /*!< CHS „» analog input channel select bin                 							*/
																						        /*!< 0000 : all analog input disable                											*/
																						        /*!< 1000 : AIN0 is analog input                													*/
																						        /*!< 1001 : AIN1 is analog input                 													*/
																						        /*!< 1010 : AIN2 is analog input                													*/
																						        /*!< 1011 : AIN3 is analog input                													*/
																										/*!< 1100 : AIN4 is analog input                													*/
																										/*!< 1101 : AIN5 is analog input                													*/
		} ADP_b;                                        /*!< BitSize	                                                            */
	};	
	
	union {
		__IO uint32_t  ADM;                   		      /*!< Offset:0x04                 																				  */
		struct {
			__IO uint32_t  START					:  1;	          /*!< 0: stop, 1: start	                                                  */
			__IO uint32_t  VALID					:  1;	          /*!< 1:data is valid (Read only)	                                        */
			__IO uint32_t  RESERVED2			:  1;
			__IO uint32_t  AUTO						:  1;	          /*!< 1:HW auto clear start signal	                                        */
			__IO uint32_t  RESERVED4			:  5;
			__IO uint32_t  ADCKS					:  3;	          /*!< ADC¡¦s clock source select bit	                                      */
			__IO uint32_t  RESERVED12			:  1;
			__IO uint32_t  BAT_SW					:  1;	          /*!< 1: low power battery switch on	                                      */
			__IO uint32_t  ADC_LEN				:  1;	          /*!< 0: 8 bit, 1: 10bit	                                                  */
			__IO uint32_t  ADC_EN					:  1;	          /*!< 1:ADC enable	                                                        */
		} ADM_b;                                        /*!< BitSize	                                                            */
	};
	
		__IO uint32_t  ADR;		                          /*!< Offset:0x08 12-bit ADC output data at MSB, and LSB 6 bit is ¡§0¡¨	    */
	
}SN_SAR_ADC_Type;

/* =========================================================================================================================== */
/* ====================================                Periphial_DMA                   ======================================= */
/* =========================================================================================================================== */
/**
  * @brief IDMA Registers (SN_IDMA_JPEG_IN,SN_IDMA_JPEG_OUT,...)
  */

typedef struct {                                    /*!< SN_IDMA Structure                                                    */
  
    __IO uint32_t  CH_RAM_ADDR;                     /*!< Offset:0x00 Address            																			*/    
    __IO uint32_t  CH_LEN;  											  /*!< Offset:0x04 Length             																			*/
	                      
  union {
    __IO uint32_t  CH_CTRL;                         /*!< Offset:0x08 Control Register                  												*/

    struct {
      __IO uint32_t  START       :  1;              /*!< Start IDMA bit 								                                      */
      __IO uint32_t  WR_RAM      :  1;              /*!< 1=read DIP writer RAM   0=read RAM write DIP                         */
      __IO uint32_t  PRAMM       :  1;							/*!< Memory Address 								                                      */
      __IO uint32_t  AD_PASS     :  1;              /*!< Address Pass (only CIS)								                              */
    } CH_CTRL_b;                                    /*!< BitSize                                                              */
  };
    __IO uint32_t  CH_DIP_ADDR;										  /*!< Offset:0x0C Peripheral Address Register          		  							*/

} SN_IDMA1_Type;



/* =========================================================================================================================== */
/* ====================================                   SN_SYS0                      ======================================= */
/* =========================================================================================================================== */
/**
  * @brief System Control Registers (SN_SYS0):OPM
 */

typedef struct {                                    /*!< SN_SYS0 Structure                                                     */ 
 union {
    __IO uint32_t  OSC_CTRL;                        /*!< Offset:0x00 OSC Control Register                  				  				   */
    
    struct {
      __IO uint32_t  IHRCEN      :  1;			        /*!< IHRC Enable 										                  				  				   */
	  __IO uint32_t  RESERVED2	 :  3;			        /*!< RESERVED 										                  				  				     */
      __IO uint32_t  HXTALEN     :  1;              /*!< 12MHz XTAL Enable 							                  				  				   */
	  __IO uint32_t  SEL_POST		 :  1;              /*!< SPLL Post scalar 										                  				  		 */
	  __IO uint32_t  SEL_PRE		 :  1;              /*!< SPLL PRE  scalar 										                  				  		 */			
      __IO uint32_t  SPLL_DIV    :  7;              /*!< SPLL DIV  Setting 							                  				  				   */
      __IO uint32_t  SPLL_SRCSEL : 	1;              /*!< SPLL CLK SET      							                  				  				   */
	  __IO uint32_t  SPLLEN      :  1;              /*!< SPLL Enable       							                  				  				   */
      __IO uint32_t  RESERVED0   : 16;              /*!< RESERVED 										                  				  				     */
    } OSC_CTRL_b;                                   /*!< BitSize                                                               */ 
  };
 union {
    __IO uint32_t  FPLL_CTRL;                        /*!< Offset:0x04 Fractional PLL Control Register                  				 */
    
    struct 
		{
			__IO uint32_t  FRA_H	     :  4;			        /*!< FPLL FRA NUM_H 		              				  				     */
      __IO uint32_t  INT		     :  4;              /*!< FPLL INT NUM 					                  				  		 */
      __IO uint32_t  VLD_IN	     :  1;				      /*!<                                    				  		       */
  		__IO uint32_t  SDM_EN_IN   :  1;				      /*!<                                    				  		       */
  		__IO uint32_t  ICP_SEL     :  2;              /*!<          					               				  				     */
		  __IO uint32_t  RESERVED1	 :  2;              /*!< RESERVED 					               				  				     */
      __IO uint32_t  SRCSEL	     :  1;					    /*!< Clock source 							         				  		       */
      __IO uint32_t  FPLLEN      :  1;							/*!< Fractional PLL Enable 							     				  		   */	
      __IO uint32_t  FRA_L       : 16;              /*!< FPLL FRA NUM_L 													  				     */
    } FPLL_CTRL_b;                                   /*!< BitSize                                                              */
  };	

 union {
    __IO uint32_t  OSC_STAT;                        /*!< Offset:0x08 CLK Status Register                  										 */
    
    struct {		
      __IO uint32_t  IHRC_RDY    :  1;              /*!< IHRC Ready Flag 							                  				  		 				 */
			__IO uint32_t  RESERVED3	 :  1;			        /*!< RESERVED 										                  				  				     */
      __IO uint32_t  LXTAL_RDY   :  1;              /*!< LXTAL Ready Flag 							                  				  		 			 */			
			__IO uint32_t  RESERVED4	 :  1;			        /*!< RESERVED 										                  				  				     */			
		  __IO uint32_t  HXTAL_RDY   :  1; 							/*!< HXTAL Ready Flag 							                  				  		       */
			__IO uint32_t  RESERVED2	 :  1;              /*!< RESERVED 										                  				  				     */
      __IO uint32_t  SPLL_RDY    :  1;							/*!< System PLL Ready Flag 							                  				  		   */										
			__IO uint32_t  RESERVED1	 :  1;		          /*!< RESERVED 										                  				  				     */	
      __IO uint32_t  FPLL_RDY    :  1;							/*!< Fractional PLL Ready Flag 							                  				  	 */																	
      __IO uint32_t  RESERVED0   : 23;              /*!< RESERVED 										                  				  				     */
    } OSC_STAT_b;                                   /*!< BitSize                                                               */
  };

 union {
    __IO uint32_t  SYS_CLKCFG;                      /*!< Offset:0x0C System CLK Control Register      												 */
    
    struct {		
      __IO uint32_t  SRCSEL      :  3;							/*!< System CLK source select 						           				  				     */																	
			__IO uint32_t  RESERVED1	 :  1;							/*!< RESERVED 										                  				  				     */
      __IO uint32_t  STAT				 :  3;							/*!< System CLK Status						                  				  				     */							
      __IO uint32_t  RESERVED0   : 25;              /*!< RESERVED 										                  				  				     */
    } SYS_CLKCFG_b;                                   /*!< BitSize                                                             */
  };	
    __IO uint32_t  SYS_CLKDIV;                      /*!< Offset:0x10 System CLK Division Register                  						 */
    
 union {
    __IO uint32_t  RST_FLAG;                        /*!< Offset:0x14 Control Register                  												 */
    
    struct {		
      __IO uint32_t  SFW_FLAG    :  1;							/*!< Software Reset 										                  				  			 */											
      __IO uint32_t  WDT_FLAG    :  1;							/*!< WDT Reset 										                  				  				     */													
      __IO uint32_t  LVD_FLAG    :  1;						  /*!< LVD Reset 										                  				  				     */											
	  __IO uint32_t  DPD_FLAG		 :  1;							/*!< RESERVED 										                  				  				     */
      __IO uint32_t  POR_FLAG    :  1;							/*!< POR Reset 										                  				  				     */											
      __IO uint32_t  RESERVED0   : 27;              /*!< RESERVED 										                  				  				     */
    } RST_FLAG_b;                                   /*!< BitSize                                                               */
  };

 union {
    __IO uint32_t  LVD_CTRL;                        /*!< Offset:0x18 LVD Control Register                  										 */
    
    struct {		
      __IO uint32_t  LVD33EN     :  1;							/*!< 3.3v LVD Enable 										                  				  			 */											
      __IO uint32_t  LVD10EN     :  1;							/*!< 1.0v LVD Enable 										                  				  			 */																
      __IO uint32_t  DISCHARGE_PD  :  1;						/*!< DISCHARGE_PD 										                  				  				 */
      __IO uint32_t  RESERVED0   : 29;              /*!< RESERVED 										                  				  				     */
    } LVD_CTRL_b;                                   /*!< BitSize                                                               */
  };
    __IO uint32_t  RESERVED11;                      /*!< Offset:0x1C RESERVED            																			 */	
	
	
  union{
    __IO uint32_t  IO_SW;                          /*!< Offset:0x20 IO Switch Register                                                                                                           */
    
	struct {
      __IO        uint32_t   SWD     : 1;
      __IO        uint32_t   SD1     : 1;
      __IO        uint32_t   SDNF0   : 1;
      __IO        uint32_t   SSI0    : 1;
      __IO        uint32_t   UART0   : 1;
      __IO        uint32_t   TFT     : 1;
      __IO        uint32_t   CT16PWM : 1;
      __IO        uint32_t   OID     : 1;
      __IO        uint32_t   HOST_PPC : 1;
      __IO        uint32_t   RESERVED0 : 16;           
    }IO_SW_b;
	};
	
	
    __IO uint32_t  RESERVED0;                       /*!< Offset:0x24 Memory Limit Address Register            								 */	

 union {
    __IO uint32_t  MEM_CTRL;                        /*!< Offset:0x28 Memory Control Register                  								 */
    
    struct {		
			__IO uint32_t  S0_RO_EN    :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  S1_RO_EN    :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  S2_RO_EN    :  1;							/*!< RAM S2(0x2000_2000~0x2001_1FFF) Read Only Enable				  				     */		
      __IO uint32_t  S3_RO_EN    :  1;				      /*!< RAM S3(0x2001_2000~0x2002_1FFF) Read Only Enable				  				     */
			__IO uint32_t  S4_RO_EN    :  1;				      /*!< RAM S4(0x2002_2000~0x2002_9FFF) Read Only Enable				  				     */
      __IO uint32_t  S5_RO_EN    :  1;				      /*!< RAM S5(0x2002_A000~0x2002_DFFF) Read Only Enable				  				     */
      __IO uint32_t  S6_RO_EN    :  1;							/*!< RAM S6(0x2002_E000~0x2002_fFFF) Read Only Enable				  				     */		
			__IO uint32_t  S7_RO_EN    :  1;							/*!< RAM S7(0x2002_E000~0x2002_fFFF) Read Only Enable				  				     */		
      __IO uint32_t  LIMIT_EN    :  1;							/*!< Limit Function Enable 										                  				   */		
      __IO uint32_t  RESERVED2   :  7;							/*!< RESERVED 										                  				  				     */
			__IO uint32_t  S0_FLAG     :  1;							/*!< Access to RAM S0 Read Only Area Flag 				                  			 */
      __IO uint32_t  S1_FLAG     :  1;						  /*!< Access to RAM S1 Read Only Area Flag 				                  			 */
      __IO uint32_t  S2_FLAG     :  1;							/*!< Access to RAM S2 Read Only Area Flag 				                  			 */
      __IO uint32_t  S3_FLAG     :  1;				      /*!< Access to RAM S3 Read Only Area Flag 				                  			 */
			__IO uint32_t  S4_FLAG     :  1;				      /*!< Access to RAM S4 Read Only Area Flag 				                  			 */
      __IO uint32_t  S5_FLAG     :  1;						  /*!< Access to RAM S5 Read Only Area Flag 				                  			 */
      __IO uint32_t  S6_FLAG     :  1;			        /*!< Access to RAM S6 Read Only Area Flag 				                  			 */
			__IO uint32_t  S7_FLAG     :  1;							/*!< Access to RAM S7 Read Only Area Flag 				                  			 */		
      __IO uint32_t  LIMIT_FLAG  :  1;							/*!< Access to Limit Area Flag								                  				   */		
      __IO uint32_t  RESERVED0   :  7;              /*!< RESERVED 										                  				  				     */
    } MEM_CTRL_b;                                   /*!< BitSize                                                               */
  };
  union {
    __IO uint32_t  BOOT_REMAP;                       /*!< Offset:0x2C IO Switch Register  */
    
    struct {		
			__IO uint32_t  MEM_REMAP    :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  SECURITY     :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  OID_SEC      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  RESERVED0    :  29;              /*!< RESERVED 										                  				  				   */
    } BOOT_REMAP_b;                                   /*!< BitSize                                                             */
  };
	
	union {
    __IO uint32_t  FEUSE0;                       /*!< Offset:0x30 E-FUSE 0 Register  */
    
    struct {		
			__IO uint32_t  LVD10_0      :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  LVD10_1      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  LVD10_2      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  RESERVED0    :  1;              /*!< RESERVED 										                  				  				   */
			__IO uint32_t  LVD33_0      :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  LVD33_1      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  RESERVED1    :  10;            /*!< RESERVED 										                  				  				   */
			__IO uint32_t  LVD10_3      :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  LVD10_4      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  LVD10_5      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  RESERVED2    :  1;              /*!< RESERVED 										                  				  				   */
			__IO uint32_t  LVD33_2      :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  LVD33_3      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  RESERVED3    :  10;            /*!< RESERVED 										                  				  				   */
    } FEUSE0_b;                                     /*!< BitSize                                                             */
  };
	
	union {
    __IO uint32_t  FEUSE1;                       /*!< Offset:0x34 E-FUSE 0 Register  */
    
    struct {		
			__IO uint32_t  LDO_0        :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  LDO_1        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  LDO_2        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  LDO_3        :  1;              /*!< RESERVED 										                  				  				   */
			__IO uint32_t  RESERVED0    :  4;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  SDR_0        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  SDR_1        :  1;             /*!< RESERVED 										                  				  				   */
			__IO uint32_t  SDR_2        :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  SDR_3        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  SDR_4        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  SDR_5        :  1;              /*!< RESERVED 										                  				  				   */
			__IO uint32_t  SDR_6        :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  SDR_7        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  IHRC_0       :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  IHRC_1       :  1;             /*!< RESERVED 										                  				  				   */
			__IO uint32_t  IHRC_2       :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  IHRC_3       :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  IHRC_4       :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  IHRC_5       :  1;              /*!< RESERVED 										                  				  				   */
			__IO uint32_t  IHRC_6       :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  IHRC_7       :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  DAC_0        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  DAC_1        :  1;             /*!< RESERVED 										                  				  				   */
			__IO uint32_t  DAC_2        :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  DAC_3        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  DAC_4        :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  DAC_5        :  1;              /*!< RESERVED 										                  				  				   */
			__IO uint32_t  DAC_6        :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
			__IO uint32_t  RESERVED1    :  1;            /*!< RESERVED 										                  				  				   */
    } FEUSE1_b;                                     /*!< BitSize                                                             */
  };
	
	union {
    __IO uint32_t  FEUSE2;                       /*!< Offset:0x38 E-FUSE 2 Register  */
    
    struct {		
			__IO uint32_t  OIDID_0      :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  OIDID_1      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  OIDID_2      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  OIDID_3      :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  OIDID_4      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  OIDID_5      :  1;            /*!< RESERVED 										                  				  				   */
			__IO uint32_t  OIDID_6      :  1;							/*!< RAM S0(0x2000_0000~0x2000_0FFF) Read Only Enable				  				     */
      __IO uint32_t  RESERVED0    :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
			__IO uint32_t  OID_SEN      :  1;				      /*!< RAM S1(0x2000_1000~0x2000_1FFF) Read Only Enable				  				     */
      __IO uint32_t  RESERVED2    :  23;            /*!< RESERVED 										                  				  				   */
    } FEUSE2_b;                                     /*!< BitSize                                                             */
  };
	
	 __IO uint32_t  FEUSE3;                       /*!< Offset:0x3C E-FUSE 3 Register  */

} SN_OPM_Type;	

/* =========================================================================================================================== */
/* ====================================                   SN_SYS1                      ======================================= */
/* =========================================================================================================================== */
/**
  *@brief Peripheral Control Registers (SN_SYS1):Peripheral
*/

typedef struct {                                    /*!< SN_SYS1 Structure                                                     */
	union {
    __IO uint32_t  PCLK_EN;                         /*!< Offset:0x00 Peripheral Clock Enable Register                  				 */
    
    struct {		
			__IO uint32_t  CT16B0  		 :  1;							/*!< Timer16B0 CLK Enable 										                  				   */						
			__IO uint32_t  CT16B1  		 :  1;				      /*!< Timer16B1 CLK Enable 										                  				   */						
			__IO uint32_t  CT32B0      :  1;				      /*!< Timer32B0 CLK Enable 										                  				   */						
			__IO uint32_t  CT32B1      :  1;							/*!< Timer32B1 CLK Enable 										                  				   */						
      __IO uint32_t  WDT         :  1;						  /*!< WDT       CLK Enable 										                  				   */												
      __IO uint32_t  RTC         :  1;							/*!< RTC       CLK Enable 										                  				   */						
      __IO uint32_t  UART        :  1;							/*!< UART      CLK Enable 										                  				   */						
			__IO uint32_t  I2C         :  1;							/*!< I2C 			 CLK Enable 										                  				   */
			__IO uint32_t  I2S2        :  1;							/*!< I2S2			 CLK Enable 										                  				   */
      __IO uint32_t  SPI         :  1;							/*!< SPI 			 CLK Enable 										                  				   */
      
			__IO uint32_t  GPIO0       :  1;							/*!< GPIO0 		 CLK Enable 										                  				   */			
      __IO uint32_t  GPIO1       :  1;							/*!< GPIO1 		 CLK Enable 										                  				   */
			__IO uint32_t  GPIO2       :  1;				      /*!< GPIO2 		 CLK Enable 										                  				   */
      __IO uint32_t  GPIO3       :  1;				      /*!< GPIO3 		 CLK Enable 										                  				   */
      __IO uint32_t  GPIO4       :  1;				      /*!< GPIO4 		 CLK Enable 										                  				   */
      __IO uint32_t  IDMA0       :  1;				      /*!< IDMA0 		 CLK Enable 										                  				   */
      __IO uint32_t  SFC         :  1;				      /*!< SFC 			 CLK Enable 										                  				   */
			__IO uint32_t  SD1         :  1;              /*!< SD1 			 CLK Enable 										                  				   */
      __IO uint32_t  JPG         :  1;	            /*!< JPG 			 CLK Enable 										                  				   */      
			__IO uint32_t  CIS         :  1;	            /*!< CIS 			 CLK Enable 										                  				   */
		
			__IO uint32_t  USBHOST     :  1;              /*!< USBHOST 	 CLK Enable 										                  				   */
      __IO uint32_t  SDNF0       :  1;              /*!< SDNF0 		 CLK Enable 										                  				   */
      __IO uint32_t  USBDEV      :  1;	            /*!< USBDEV 	 CLK Enable 										                  				   */
			__IO uint32_t  PPU         :  1;	            /*!< PPU 			 CLK Enable 										                  				   */
      __IO uint32_t  ADC_I2S     :  1;	            /*!< ADC_I2S	 CLK Enable 										                  				   */
      __IO uint32_t  DAC_I2S     :  1;	            /*!< DAC_I2S 	 CLK Enable 										                  				   */
      __IO uint32_t  SAR         :  1;	            /*!< SAR 		   CLK Enable 										                  				   */
			__IO uint32_t  AES	       :  1;	            /*!< _8080     CLK Enable 										                  				   */
      __IO uint32_t  OID         :  1;	            /*!< TFT 		   CLK Enable 										                  				   */
      __IO uint32_t  CSC         :  1;	            /*!< CSC       CLK Enable 										                  				   */
			
			__IO uint32_t  IDMA1	     :  1;			        /*!< IDMA1     CLK Enable 										                  				   */
	    __IO uint32_t  DSP      	 :  1;	            /*!< DSP       CLK Enable 										                  				   */
    } PCLK_EN_b;                                    /*!< BitSize                                                               */
  };

    __IO uint32_t  RESERVED8;                       /*!< Offset:0x04 RESERVED8            																		 */	

 union {
    __IO uint32_t  PCLK_CTL;                        /*!< Offset:0x08 Peripheral Clock Control Register    										 */
    
    struct {		
      __IO uint32_t  PCLKDIV     :  3;	            /*!< PCLKDIV 										                  				                 */
			__IO uint32_t  USBDIV      :  1;	            /*!< USBDIV 										                  				                 */
			__IO uint32_t  OIDDIV      :  1;	            /*!< USBDIV 										                  				                 */
		  __IO uint32_t  RESERVED2	 :  3;	            /*!< RESERVED 										                  				  				     */
      __IO uint32_t  CLKOUT_DIV  :  3;	            /*!< CLKOUT_DIV 										                  				  				   */
			__IO uint32_t  RESERVED1	 :  1;	            /*!< RESERVED 										                  				  				     */
      __IO uint32_t  CLKOUT_SEL  :  3;				      /*!< CLKOUT_SEL 										                  				  				   */
      __IO uint32_t  RESERVED0   : 17;              /*!< RESERVED 										                  				  				     */
    } PCLK_CTL_b;                                   /*!< BitSize                                                               */
  };
	
 union {
    __IO uint32_t  PCLK_RST;                        /*!< Offset:0x0C Peripheral Reset Control Register                  			 */
    
    struct {		
			__IO uint32_t  CT16B0  		 :  1;							/*!< Timer16B0 Clock Reset 										                  				   */
			__IO uint32_t  CT16B1  		 :  1;				      /*!< Timer16B1 Clock Reset 										                  				   */
			__IO uint32_t  CT32B0  		 :  1;				      /*!< Timer32B0 Clock Reset 										                  				   */
			__IO uint32_t  CT32B1  		 :  1;							/*!< Timer32B1 Clock Reset 										                  				   */
      __IO uint32_t  WDT     		 :  1;							/*!< WDT       Clock Reset 										                  				   */
      __IO uint32_t  RTC     		 :  1;							/*!< RTC       Clock Reset 										                  				   */
      __IO uint32_t  UART        :  1;							/*!< UART      Clock Reset 										                  				   */
			__IO uint32_t  I2C         :  1;							/*!< I2C       Clock Reset 										                  				   */
			__IO uint32_t  I2S2        :  1;							/*!< I2S       Clock Reset 										                  				   */							
      __IO uint32_t  SPI         :  1;							/*!< SSI       Clock Reset 										                  				   */							
      __IO uint32_t  GPIO0       :  1;							/*!< GPIO0     Clock Reset 										                  				   */										
      __IO uint32_t  GPIO1       :  1;							/*!< GPIO1     Clock Reset 										                  				   */										
			__IO uint32_t  GPIO2       :  1;				      /*!< GPIO2     Clock Reset 										                  				   */										
      __IO uint32_t  GPIO3       :  1;				      /*!< GPIO3     Clock Reset 										                  				   */										
      __IO uint32_t  GPIO4       :  1;				      /*!< GPIO4     Clock Reset 										                  				   */										
      __IO uint32_t  IDMA0       :  1;				      /*!< IDMA0     Clock Reset 										                  				   */										
      __IO uint32_t  SFC         :  1;				      /*!< SFC       Clock Reset 										                  				   */							
			__IO uint32_t  SD1         :  1;              /*!< SD1       Clock Reset 										                  				   */							
      __IO uint32_t  JPG         :  1;	            /*!< JPG       Clock Reset 										                  				   */							
      __IO uint32_t  CIS         :  1;	            /*!< CIS       Clock Reset 										                  				   */							
			__IO uint32_t  USBHOST     :  1;              /*!< USBHOST   Clock Reset 										                  				   */							
      __IO uint32_t  SDNF0       :  1;              /*!< SDNF0     Clock Reset 										                  				   */							
      __IO uint32_t  USBDEV      :  1;	            /*!< USBDEV    Clock Reset 										                  				   */							
			__IO uint32_t  PPU         :  1;	            /*!< PPU       Clock Reset 										                  				   */							
      __IO uint32_t  ADC_I2S     :  1;	            /*!< ADC       Clock Reset 										                  				   */							
      __IO uint32_t  DAC_I2S     :  1;	            /*!< DAC_I2S   Clock Reset 										                  				   */							
      __IO uint32_t  SAR         :  1;	            /*!< SAR       Clock Reset 										                  				   */							
			__IO uint32_t  AES 	       :  1;	            /*!< _8080     Clock Reset 										                  				   */							
      __IO uint32_t  OID         :  1;	            /*!< TFT       Clock Reset 										                  				   */							
      __IO uint32_t  CSC         :  1;	            /*!< CSC       Clock Reset 										                  				   */							
			__IO uint32_t  IDMA1	     :  1;			        /*!< IDMA1     Clock Reset 										                  				   */							
	    __IO uint32_t  DSP  	     :  1;							/*!< DSP       Clock Reset 										                  				   */											
    } PCLK_RST_b;                                   /*!< BitSize                                                               */
  };
	
	union {
    __IO uint32_t  USB_CTRL;                        /*!< Offset:0x10 USB PHY Control Register                  								 */
    
    struct {		
      __IO uint32_t  DevPLL480   :  1;							/*!< DevPLL480 										                  				  				     */
		  __IO uint32_t  HostPLL480 	:  1;							/*!< HostPLL480 										                  				  				   */
      __IO uint32_t  PHY_PDN_MUX  :  1;						  /*!< PHY_PDN_MUX										                  				  				   */
			__IO uint32_t  CPUD_UTMI_PDN  : 1;						/*!< CPUD_UTMI_PDN 										                  				  				 */
      __IO uint32_t  HID_EP3En	 :  1;							/*!< EP3En										                  				  				         */
			__IO uint32_t  DevPHYPullLow	 :  1;					/*!< DevPHYPullLow										                  				  				 */
      __IO uint32_t  RESERVED0   : 27;              /*!< RESERVED 										                  				  				     */
    } USB_CTRL_b;                                   /*!< BitSize                                                               */
  };	
	
	
} SN_PERI_Type;


/* =========================================================================================================================== */
/* ====================================                 SN_ISOBlock                    ======================================= */
/* =========================================================================================================================== */
/**
  *@brief ISO Control Registers (SN_ISO)
*/

typedef struct {  																	/*!< SN_ISO Structure                                                      */
		// Modify 20150429, by ChiCheTsai
 union {
    __IO uint32_t  ISO_CTRL;                        /*!< Offset:0x00 ISO Control Register                  										 */
    
    struct {		
      __IO uint32_t  RTC_TIME    :  3;							/*!< RTC_TIME 										                  				  				     */
		  __IO uint32_t  RTC_WKP		 :  1;							/*!< RTC WAKEUP										                  				  				     */
      __IO uint32_t  LXTAL_SpdRel : 1;						  /*!< LXTL Release speed up 										                  				   */
			__IO uint32_t  LXTALEN  	 :  1;							/*!< LXTL EN 										                  				  				       */
      __IO uint32_t  RTC_SRCSEL	 :  1;							/*!< RTC SRC SEL										                  				  				   */
      __IO uint32_t  RTC_EN		   :  1;							/*!< RTCEN 										                  				  				         */			
      __IO uint32_t  RESERVED0   : 24;              /*!< RESERVED 										                  				  				     */
    } ISO_CTRL_b;                                   /*!< BitSize                                                               */
  };
 union {
    __IO uint32_t  ISO_TRIM;                        /*!< Offset:0x00 ISO Control Register                  										 */
    
    struct {		
      __IO uint32_t  ILRC_3V_TRIM_L  :  4;					/*!<  										                  				  				             */
		  __IO uint32_t  ILRC_3V_TRIM_H	 :  2;					/*!<  										                  				  				             */
      __IO uint32_t  SDRAM_OFF 			 :  1;					/*!< 										                  				  				               */
			__IO uint32_t  RTC_CLEAR 			 :  1;					/*!< 										                  				  				               */
      __IO uint32_t  RESERVED0   		 : 24;          /*!<  										                  				  				             */
    } ISO_TRIM_b;                                   /*!< BitSize                                                               */
  };		
//    __IO uint32_t  BK_REG14; 												/*!< Offset:0x00 Backup Register14 				                  			         */
//    __IO uint32_t  BK_REG15; 												/*!< Offset:0x04 Backup Register15 				                  			         */			
    __IO uint32_t  BK_REG0; 												/*!< Offset:0x08 Backup Register0 				                  			 				 */
    __IO uint32_t  BK_REG1; 												/*!< Offset:0x0c Backup Register1 				                  			         */
	__IO uint32_t  BK_REG2; 												/*!< Offset:0x10 Backup Register2 				                  			         */
    __IO uint32_t  BK_REG3; 												/*!< Offset:0x14 Backup Register3 				                  			         */
    __IO uint32_t  BK_REG4; 												/*!< Offset:0x18 Backup Register4 				                  			         */
    __IO uint32_t  BK_REG5; 												/*!< Offset:0x1C Backup Register5 				                  			         */
    __IO uint32_t  BK_REG6; 												/*!< Offset:0x20 Backup Register6 				                  			         */
    __IO uint32_t  BK_REG7; 												/*!< Offset:0x24 Backup Register7 				                  			         */
	__IO uint32_t  BK_REG8; 												/*!< Offset:0x28 Backup Register8 				                  			         */
    __IO uint32_t  BK_REG9; 												/*!< Offset:0x2C Backup Register9 				                  			         */
    __IO uint32_t  BK_REG10; 												/*!< Offset:0x30 Backup Register10 				                  			         */
    __IO uint32_t  BK_REG11; 												/*!< Offset:0x34 Backup Register11 				                  			         */
    __IO uint32_t  BK_REG12; 												/*!< Offset:0x38 Backup Register12				                  			         */
    __IO uint32_t  BK_REG13; 												/*!< Offset:0x3C Backup Register13 				                  			         */
    __IO uint32_t  BK_REG16; 												/*!< Offset:0x40 Backup Register16 				                  			         */
	__IO uint32_t  BK_REG17; 												/*!< Offset:0x44 Backup Register17 				                  			         */	
    __IO uint32_t  BK_REG18; 												/*!< Offset:0x48 Backup Register18 				                  			         */
    __IO uint32_t  BK_REG19; 												/*!< Offset:0x4C Backup Register19 				                  			         */
    __IO uint32_t  BK_REG20; 												/*!< Offset:0x50 Backup Register20 				                  			         */
    __IO uint32_t  BK_REG21; 												/*!< Offset:0x54 Backup Register21 				                  			         */
    __IO uint32_t  BK_REG22; 												/*!< Offset:0x58 Backup Register22 				                  			         */
    __IO uint32_t  BK_REG23; 												/*!< Offset:0x5C Backup Register23 				                  			         */



} SN_ISO_Type;


/* =========================================================================================================================== */
/* ====================================                   SN_PMU                       ======================================= */
/* =========================================================================================================================== */
/**
  *@brief PMU Control Registers (SN_PMU)
*/

typedef struct {  																	/*!< SN_PMU Structure                                                      */
	

 union {
    __IO uint32_t  PMU_CTRL;                       /*!< Offset:0x00 PMU Control Register                  										 */
    
    struct {		
      __IO uint32_t  DPDEN        :  1;						 /*!< DPDEN 										                  				  				     	   */
		  __IO uint32_t  DSLEEPEN	    :  1;					   /*!< DSLEEPEN 										                  				  				       */	
		  __IO uint32_t  SLEEPEN	    :  1;					   /*!< SLEEPEN 										                  				  				       */				
      __IO uint32_t  ROM_PWR      :  1;						 /*!< ROM_PWR 										                  				  				       */	
			__IO uint32_t  RTC_FLAG	    :  1;						 /*!< RTC_Flag 										                  				  				       */			
			__IO uint32_t  RESERVED2    :  1;						 /*!< RESERVED1 										                  				  				     */						
			__IO uint32_t  WKP_FLAG	    :  1;						 /*!< WKP_Flag 										                  				  				       */						
			__IO uint32_t  RESERVED1    :  8;						 /*!< RESERVED 										                  				  				       */			
			__IO uint32_t  WKP			    :  1;						 /*!< WKP PAD 										                  				  				       */						
      __IO uint32_t  RESERVED0    : 15;            /*!< RESERVED 					   					                  				  				     */	
			__IO uint32_t  RTC_CNT_FLAG :  1;            /*!< RTC Counter Valid flag  										                  		     */	
    } PMU_CTRL_b;                                  /*!< BitSize                                                                */
  };	
//    //__IO uint32_t  MEM_ISO; 											 /*!< Offset:0x04 MEM_ISO Control Register                  								 */
// union {
//    __IO uint32_t  MEM_ISO;                       /*!< Offset:0x04 MEM_ISO Control Register                  										 */
//    
//    struct {		
//      __IO uint32_t  REGION2     :  1;						 /*!< REGION2 										                  				  				     	   */
//		  __IO uint32_t  REGION3	   :  1;					   /*!< REGION3 										                  				  				       */	
//      __IO uint32_t  RESERVED0   : 30;             /*!< RESERVED 										                  				  				       */	
//    } MEM_ISO_b;                                  /*!< BitSize                                                                */
//  };
	
//    //__IO uint32_t  MEM_PWR_OFF; 		               /*!< Offset:0x08 MEM_PWR_OFF Control Register                  						 */
// union {
//    __IO uint32_t  MEM_PWR_OFF;                       /*!< Offset:0x08 MEM_PWR_OFF Control Register                  										 */
//    
//    struct {		
//      __IO uint32_t  REGION2     :  1;						 /*!< REGION2 										                  				  				     	   */
//		  __IO uint32_t  REGION3	   :  1;					   /*!< REGION3 										                  				  				       */	
//      __IO uint32_t  RESERVED0   : 30;             /*!< RESERVED 										                  				  				       */	
//    } MEM_PWR_OFF_b;                                  /*!< BitSize                                                                */
//  };	
	
	
} SN_PMU_Type;

/* =========================================================================================================================== */
/* ====================================                 RTC_Counter                    ======================================= */
/* =========================================================================================================================== */
/**
  *@brief RTC Counter Registers (SN_PMU)
*/

typedef struct {  																	/*!< SN_RTCC                                                              */
	

 union {
    __O uint32_t  RTC_COUNTER;                      /*!< Offset:0x00 PMU Control Register                  								  */
    
    struct {		
      __O uint32_t  RTC_COUNTER :  32;						  /*!< RTC Counter Value					                  				  				     	  */
    } RTC_COUNTER_b;                                /*!< BitSize                                                            */
  };	
} SN_RTC_COUNTER_Type;


/* =========================================================================================================================== */
/* ====================================                   SN_Test                      ======================================= */
/* =========================================================================================================================== */
/**
  *@brief TESTMODE Control Registers (SN_TESTMODE)
*/

typedef struct {  																	/*!< SN_PMU Structure                                                      */
	

 union {
    __IO uint32_t  TEST_CTL;                       /*!< Offset:0x00 TEST Control Register                  										 */
    
    struct {		
      __IO uint32_t  AIPTEST     :  8;			       /*!< AIPTEST 										                  				  				     	 */
      __IO uint32_t  RESERVED0	 : 23;			       /*!< RESERVED 										                  				  				       */						
      __IO uint32_t  TESTPIN     :  1;             /*!< TESTPIN 										                  				  				       */	
    } TEST_CTL_b;                                  /*!< BitSize                                                                */
  };	
    
 union {
    __IO uint32_t  TES_EN;                         /*!< Offset:0x04 MEM_ISO Control Register                  								 */
    
    struct {		
      __IO uint32_t  TESTMODE     :  1;			      /*!< TESTMODE 										                  				  				     	 */
		  __IO uint32_t  USBMONITOR   :  1;		        /*!< USBMONITOR 										                  				  				     */	
      __IO uint32_t  RESERVED0	  : 14;			      /*!< RESERVED 										                  				  				       */									
      __IO uint32_t  TEST_KEY     : 16;           /*!< TEST_KEY 										                  				  				       */	
    } TES_EN_b;                                   /*!< BitSize                                                                 */
  };
	
} SN_TEST_Type;

typedef struct {  								                /*!< SN_OID Structure                                                        */
	

 union {
    __IO uint32_t  OID_CTL;                       /*!< Offset:0x00 TEST Control Register                  										 */
    
    struct {		
      __IO uint32_t  OID_GPIO_2WIRE     :  1;			/*!< OID_GPIO_2WIRE 										                  				  				 */
      __IO uint32_t  OID_SEN_PD	 			  :  1;			/*!< OID_SEN_PD 										                  				  				     */						
      __IO uint32_t  OID_SENCMD_PD      :  1;     /*!< OID_SENCMD_PD 										                  				  				   */	
			__IO uint32_t  OID_IO_SWT_EN      :  1;     /*!< OID_IO_SWT_EN 										                  				  				   */	
			__IO uint32_t  RESERVED     		  :  28;    /*!< RESERVED 										                  				  				       */	
    } OID_CTL_b;                                  /*!< BitSize                                                                 */
  };	
 } SN_OID_Type;
 
 
 
/* =========================================================================================================================== */
/* ====================================                  SDRAM CLK                     ======================================= */
/* =========================================================================================================================== */
/**
  *@brief PMU Control Registers (SN_SDRAM_CLK)
*/

typedef struct {  									              /*!< SN_PMU Structure                                                        */
	
 union {
    __IO uint32_t  SDRAM_CLK;                     /*!< Offset:0x00 TEST Control Register                  	                   */
    
    struct {		
      __IO uint32_t   SDR_PLL_DIV        :  7;    /*!< SDRAM PLL Div Setting                                                   */ 										                  				  				 		
      __IO uint32_t   SDR_PLL_PRE        :  1;    /*!< SDRAM PLL PRE scalar 									                                 */
   	  __IO uint32_t   SDR_PLL_POS        :  1;    /*!< SDRAM PLL POS scalar									                                   */
	  __IO uint32_t   RESERVED0          :  5;	  /*!< RESERVED0      										                                     */
      __IO uint32_t   SDR_RST            :  1;	  /*!< SDRAM¡@Reset      										                                   */
	  __IO uint32_t   SDR_EN             :  1;	  /*!<  SDRAM  Enable      									                                   */
	  __IO uint32_t   RESERVED1          :  16;	  /*!< RESERVED1      										                                     */ 
	} SDRAM_CLK_b;                                  /*!< BitSize                                                                 */
  };	
    
} SN_SDRAM_CLK_Type;

/* =========================================================================================================================== */
/* ====================================                   SN_SDRAM                     ======================================= */
/* =========================================================================================================================== */
/**
  *@brief PMU Control Registers (SN_SDRAM)
*/
typedef struct {  									 /*!< SN_PMU Structure                                                                    */
	

  union {
    __IO uint32_t  SDRAM_CTRL;                       /*!< Offset:0x00 SDRAM Control Register                  	              */
   
		struct {		
      __IO uint32_t  CPU_CMD_MODE         :  1;			 /*!< CPU_CMD_MODE										                  				  				*/
	    __IO uint32_t  RESERVED0	          :  3;			 /*!< RESERVED0 										                  				  				  */	
	    __IO uint32_t  CPU_SUS_CMD	        :  1;			 /*!< CPU_SUS_CMD 										                  				  				*/				
      __IO uint32_t  RESERVED1            : 10;			 /*!< RESERVED1 										                  				  				  */	
	    __IO uint32_t  SDR_WP_IF            :  1;      /*!< SDRAM Write Protect Interrupt Flag                                  */
	   	__IO uint32_t  RESERVED2            :  8;			 /*!< RESERVED2                                                           */
		  __IO uint32_t  SDRAM_FLUSH	        :  1;			 /*!< SDRAM_FLUSH										                  				  				  */			
		  __IO uint32_t  RESERVED3            :  7;			 /*!< RESERVED3 										                  				  				  */					
    } SDRAM_CTRL_b;                                  /*!< BitSize                                                             */
  };	
    //__IO uint32_t  SDRAM_CMD; 									   /*!< Offset:0x04 SDRAM_CMD Control Register                  	  			  */
 
 union {
    __IO uint32_t  SDRAM_CMD;                        /*!< Offset:0x04 SDRAM_CMD Control Register                  						*/
    
    struct {		
      __IO uint32_t  DQM                 :  1;			 /*!< DQM									                  				  				     	      */
		  __IO uint32_t  WEN	               :  1;			 /*!< WEN 										                  				  				        */	
      __IO uint32_t  CAS                 :  1;       /*!< CAS										                  				  				          */
		  __IO uint32_t  RAS                 :  1;       /*!< RAS 										                  				  				        */
      __IO uint32_t  CS                  :  1;       /*!< CS										                  				  				          */
		  __IO uint32_t  CKE                 :  1;       /*!< CKE 										                  				  				        */
		  __IO uint32_t  RESERVED            : 26;       /*!< RESERVER 										                  				  				    */
	} SDRAM_CMD_b;                                     /*!< BitSize                                                             */
  };
	
    //__IO uint32_t  SDRAM_LMR_INFO; 		             /*!< Offset:0x08 SDRAM_LMR_INFO Control Register             						*/
 union {
    __IO uint32_t  SDRAM_MR;                         /*!< Offset:0x08 SDRAM_LMR_INFO Control Register                  				*/
    
    struct {		
      __IO uint32_t  MR_INFO             : 12;	     /*!< SDRAM_LMR_INFO 										                  				  			*/
      __IO uint32_t  RESERVED            : 20;       /*!< RESERVED 										                  				  				    */	
    } SDRAM_MR_b;                                    /*!< BitSize                                                             */
  };	
	
    //__IO uint32_t  SDRAM_ADDR; 									   /*!< Offset:0x0C  SDRAM_ADDR Control Register                  					*/
 union {
    __IO uint32_t  SDRAM_ARRAY;                      /*!< Offset:0x0C  SDRAM_ADDR Control Register                  					*/
    
    struct {		
      __IO uint32_t  COL_BITS            :  5;			 /*!< COL_BITS 										                  				  				    */
		  __IO uint32_t  RESERVED0           :  3;			 /*!< RESERVED0										                  				  				    */	
      __IO uint32_t  ROW_BITS            :  5;       /*!< ROW_BITS 										                  				  				    */
		  __IO uint32_t  RESERVED1           :  3;       /*!< RESERVED1 										                  				  				  */
      __IO uint32_t  BK_BITS             :  2;       /*!< BK_BITS 										                  				  				    */	 										                  				  				      
		  __IO uint32_t  RESERVED2           : 14;       /*!< RESERVED2 										                  				  				  */
	} SDRAM_ARRAY_b;                                   /*!< BitSize                                                             */
  };	
	
	    //__IO uint32_t  SDRAM_ARF; 									 /*!< Offset:0x10 SDRAM_ARF Control Register                  						*/
  union {
    __IO uint32_t  SDRAM_ARF;                        /*!< Offset:0x10 SDRAM_ARF Control Register                  						*/
   
    struct {		
      __IO uint32_t  ARF_CNT             :  12;			 /*!< ARF_CNT									                  				  				     	  */
		  __IO uint32_t  RESERVED 	         :  20;			 /*!< RESERVED										                  				  				    */										                  				  			
	}	SDRAM_ARF_b;                                     /*!< BitSize                                                             */
  };
		    //__IO uint32_t  SDRAM_TUNE_CL; 						 /*!< Offset:0x1C SDRAM_TUNE_CL Control Register                  				*/
  union {
    __IO uint32_t  SDRAM_TUNE_CL;                    /*!< Offset:0x1C SDRAM_TUNE_CL Control Register                  				*/
    
	struct {		
    __IO uint32_t  CK_CL                 :  2;			 /*!< CK_CL 										                  				  				     	*/
		__IO uint32_t  RESERVED0             :  2;			 /*!< RESERVED0										                  				  				    */	
		__IO uint32_t  CK_DLY	               :  4;			 /*!< CK_DLY										                  				  				      */										                  				  			
		//__IO uint32_t  CK_INV	               :  1;			 /*!< CK_INV		                                                          */
		__IO uint32_t  RESERVED1             :  25;			 /*!< RESERVED1										                  				  				    */	
	} SDRAM_TUNE_CL_b;                                 /*!< BitSize                                                             */
  };
	
   //__IO uint32_t  SDRAM_TUNE_CL; 						       /*!< Offset:0x1C SDRAM_TUNE_CL Control Register                  				*/
  union {
     __IO uint32_t  SDRAM_NOP_COUNT;                 /*!< Offset:0x1C SDRAM_TUNE_CL Control Register                  				*/
    
	struct {		
    __IO uint32_t  tRCD                  :  4;			 /*!< Active to Write/Read Command Delay Timing(tRCD+2) 									*/
		__IO uint32_t  tRP	                 :  4;			 /*!< Percharge to End Timing(tRP+1)										                  */										                  				  			
		__IO uint32_t  tRC	                 :  4;			 /*!< Aout Refresh to Idel Timing		                                      */
	    __IO uint32_t  RESERVED 	         :  20;			 /*!< RESERVED										                  				  				    */	
	} SDRAM_NOP_COUNT_b;                               /*!< BitSize                                                             */
  };
	
	
} SN_SDRAM_Type;

/* =========================================================================================================================== */
/* ====================================               SN_SDRAM_Protect                 ======================================= */
/* =========================================================================================================================== */
/**
  *@brief PMU Control Registers (SN_SDRAM)
*/
typedef struct {  									/*!< SN_PMU Structure                                                      */
	

 union {
    __IO uint32_t  SDRAM_Protect;                   /*!< Offset:0x00 SDRAM Control Register										*/
    
	struct {		
    __IO uint32_t  BANK0_SDR_0            :  1;		  /*SDRAM mapping address	  Addr[20:17]: 0000                                */	
	__IO uint32_t  BANK0_SDR_1            :  1;		  /*SDRAM mapping address	  Addr[20:17]: 0001                                */
	__IO uint32_t  BANK0_SDR_2            :  1;			/*SDRAM mapping address	  Addr[20:17]: 0002                                */
    __IO uint32_t  BANK0_SDR_3            :  1;							
	__IO uint32_t  BANK0_SDR_4            :  1;						 			
	__IO uint32_t  BANK0_SDR_5            :  1;	
    __IO uint32_t  BANK0_SDR_6            :  1;
    __IO uint32_t  BANK0_SDR_7            :  1;
    __IO uint32_t  BANK0_SDR_8            :  1;
    __IO uint32_t  BANK0_SDR_9            :  1;	
    __IO uint32_t  BANK0_SDR_10           :  1;
    __IO uint32_t  BANK0_SDR_11           :  1;	
    __IO uint32_t  BANK0_SDR_12           :  1;
    __IO uint32_t  BANK0_SDR_13           :  1;
    __IO uint32_t  BANK0_SDR_14           :  1;
    __IO uint32_t  BANK0_SDR_15           :  1;		
    __IO uint32_t  RESERVED				:  16;		/*!< RESERVED                                                             */		  			
    } SDRAM_Protect_b;                                 
  };	
                                              
} SN_SDRAM_Protect_Type;
 

/* =========================================================================================================================== */
/* ====================================                     SN_AES                     ======================================= */
/* =========================================================================================================================== */
 
typedef struct {                                   /*!< SN_AES Structure                                                       */
  
  union {
    __IO uint32_t	CTRL;                    	       /*!< Offset:0x00 AES Control Register                                       */
    
    struct {
      __IO uint32_t	Enable     				    :  1;    /*!< AES enable                                                             */
      __I  uint32_t Reserved_AES0			    :  1;
      __IO uint32_t Key_GEN    				    :  1;    /*!< AES generate key                                                       */
			__I	 uint32_t Reserved_AES1			    :  1;
			__IO uint32_t Mode							    :  4;	   /*!< AES function mode							  						                           */
			__IO uint32_t CRC_Read_Data			    : 16;		 /*!< CRC calculate data							     	   			                         */
			__IO uint32_t Mode_S						    :  2;		 /*!< AES/DES/3DES mode select					   					                         */
			__IO uint32_t Bit_S						    	:  2;		 /*!< AES/DES/3DES CFB/OFB mode bit number select                            */
			__IO uint32_t Key_Len					    	:  2;		 /*!< AES key length select						   					                           */
			__IO uint32_t Update_IV					    :  1;		 /*!< Update Initial vector control				   			                           */
			__I  uint32_t Reserved_AES2  		    :  1;
    }CTRL_b;                                	     /*!< BitSize                                                                */
  };
	
  __IO uint32_t	BUSY;                      	       /*!< Offset:0x04 AES Busy Status Register                                   */
	
  union {
    __IO uint32_t	MASK;                  			     /*!< Offset:0x08 AES MASK Register                                          */
   
    struct {
      __IO uint32_t	Func_Mask     		    :  1; 	 /*!< AES function mask                                                      */
      __IO uint32_t	AHB_Master_Mask		    :  1;		 /*!< AES AHB master mask                                                    */
		  __I  uint32_t	Reserved_AES3 		    : 30;
    } MASK_b;                                      /*!< BitSize                                                                */
  };
  
  union {
    __IO uint32_t	STAT;                   	       /*!< Offset:0x0C AES Status Register                                        */
    
    struct {
      __IO uint32_t Func_STAT     		  	:  1;    /*!< AES function status                       	                           */
      __IO uint32_t AHB_Master_STAT			  :  1;	   /*!< AES AHB master status                     	                           */
			__IO uint32_t AHB_Slave_STAT	      :  1;	   /*!< AES AHB slave status                                                   */ 
			__IO uint32_t CLR_Func_STAT				  :  1;	   /*!< Write 1 to clear FUN_STATUS                                            */
			__IO uint32_t CLR_AHB_Master_STAT	  :  1;	   /*!< Write 1 to clear AHB_MASTER_STATUS                                     */
		  __I  uint32_t Reserved_AES4  			  : 27;
    } STAT_b; 	                                   /*!< BitSize                                                                */
  };
  
  union {
    __IO uint32_t	SRC_ADDR;                        /*!< Offset:0x10 Source Address Register       	                           */
    
    struct {
      __I  uint32_t Reserved_AES5		    	:  4;
      __IO uint32_t Src_Addr					    : 28;		 /*!< Memory start address of source data                                    */
    } SRC_ADDR_b;                                  /*!< BitSize                                                                */
  };
  
  union {
    __IO uint32_t	DEST_ADDR;                       /*!< Offset:0x14 Destination Address Register                               */
    
    struct {
      __I  uint32_t Reserved_AES6         :  4;
      __IO uint32_t Dest_Addr					    : 28;		 /*!< Memory start address of destination data                               */
    } DEST_ADDR_b;                                 /*!< BitSize                                                                */
  };
  
  union {
    __IO uint32_t	DATA_SIZE;                	     /*!< Offset:0x18 Data Size Register   			   	                          	 */
    
    struct {
      __I  uint32_t Reserved_AES7			    :  4;	
      __IO uint32_t	DEST_Size				     	: 21;		 /*!< Data size				                       		                          	 */
	    __I	 uint32_t Reserved_AES8			    :  7;
    } DATA_SIZE_b;                                 /*!< BitSize                                                                */
  };
  
  __IO uint32_t	KEY_IN_0;                         /*!< Offset:0x1C AES key input[31:0] or DES key in1[31:0] or CRC data input(REG mode)*/
  __IO uint32_t KEY_IN_1;                         /*!< Offset:0x20 AES key input[63:32] or DES key in1[63:32] or KEY_IN_1[0] is ready signal(REG mode)*/
  __IO uint32_t KEY_IN_2;                         /*!< Offset:0x24 AES key input[95:64] or DES key in2[31:0]*/
  __IO uint32_t KEY_IN_3;                         /*!< Offset:0x28 AES key input[127:96] or DES key in2[63:32]*/
  __I  uint32_t KEY_OUT_0;										    /*!< Offset:0x2C AES key output[31:0]			  			                           */
  __I  uint32_t KEY_OUT_1;										    /*!< Offset:0x30 AES key output[63:32]			   		                           */
  __I  uint32_t KEY_OUT_2;										    /*!< Offset:0x34 AES key output[95:64]			  		                           */
  __I  uint32_t KEY_OUT_3;										    /*!< Offset:0x38 AES key output[127:96]			   		                           */
  __I  uint32_t IP_VERSION;										    /*!< Offset:0x3C Version of AES codec			  			                           */
  __IO uint32_t KEY_IN_4;                         /*!< Offset:0x40 DES key in3[31:0]				  			                           */
  __IO uint32_t KEY_IN_5;                         /*!< Offset:0x44 DES key in3[63:32]				  			                           */
  __I  uint32_t	Reserved_AES1[2];
  __IO uint32_t IV0_IN;												    /*!< Offset:0x50 Initial vector 0(for AES/DES/3DES)                          */
  __IO uint32_t IV1_IN;												    /*!< Offset:0x54 Initial vector 1(for AES/DES/3DES)                          */
  __IO uint32_t IV2_IN;												    /*!< Offset:0x58 Initial vector 2(for AES only)                              */
  __IO uint32_t IV3_IN;												    /*!< Offset:0x5C Initial vector 3(for AES only)	                             */
  __I  uint32_t	Reserved_AES2[8];  
  __IO uint32_t KEY_IN_6;                         /*!< Offset:0x80 Input key 6 (for AES 256-bit mode)                          */
  __IO uint32_t KEY_IN_7;                         /*!< Offset:0x84 Input key 7 (for AES 256-bit mode)                          */
  __I  uint32_t KEY_OUT_4;										    /*!< Offset:0x88 Output key 4 (AES output key)	                             */
  __I  uint32_t KEY_OUT_5;										    /*!< Offset:0x8C Output key 5 (AES output key)	                             */
  __I  uint32_t KEY_OUT_6;									    	/*!< Offset:0x90 Output key 6 (AES output key)	                             */
  __I  uint32_t KEY_OUT_7;									    	/*!< Offset:0x94 Output key 7 (AES output key)	                             */  
}SN_AES_Type;



/* -----------------------------------------  End of section using anonymous unions  ---------------------------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif





/* =========================================================================================================================== */
/* ====================================              Peripheral memory map             ======================================= */
/* =========================================================================================================================== */
#define SN_CT16B0_BASE                  0x40000000UL
#define SN_CT16B1_BASE                  0x40002000UL
#define SN_CT32B0_BASE                  0x40004000UL
#define SN_CT32B1_BASE                  0x40006000UL
#define SN_WDT_BASE                     0x40010000UL
#define SN_RTC_BASE                     0x40012000UL
#define SN_UART0_BASE                   0x40014000UL
#define SN_UART1_BASE                   0x40018000UL
#define SN_I2C_BASE                     0x40016000UL
#define SN_SPI0_BASE                    0x4001A000UL
#define SN_SPI1_BASE                    0x4001C000UL
#define SN_GPIO0_BASE                   0x40022000UL
#define SN_GPIO1_BASE                   0x40024000UL
#define SN_GPIO2_BASE                   0x40026000UL
#define SN_GPIO3_BASE                   0x40028000UL
#define SN_GPIO4_BASE                   0x4002A000UL
#define SN_IDMA_CSC_IN_BASE             0x40030000UL
#define SN_IDMA_CSC_OUT_BASE            0x40030010UL
#define SN_IDMA_USBDEV_BASE             0x40032030UL
#define SN_IDMA_SDNF0_BASE              0x40032040UL
#define SN_IDMA_SDNF1_BASE              0x40032050UL
#define SN_IDMA_SPIF_BASE               0x40032060UL
#define SN_IDMA_CIS_BASE                0x40032070UL
#define SN_IDMA_RAM_BASE                0x40032000UL
#define SN_IDMA_JPEG_IN_BASE            0x40032010UL
#define SN_IDMA_JPEG_OUT_BASE           0x40032020UL
#define SN_FLASH_BASE                   0x40034000UL
#define SN_SDCARD1_BASE                 0x40036000UL
#define SN_JPEG_BASE                  	0x40038000UL
#define SN_CSC_BASE                   	0x40038100UL
#define SN_CIS_BASE                     0x4003A000UL
#define SN_SDCARD0_BASE                 0x4003E000UL
#define SN_NF_BASE                    	0x4003E000UL
#define SN_I2S2_BASE                    0x40045000UL
#define SN_I2S1_BASE                    0x40046000UL
#define SN_ADC_I2S_BASE					0x40046000UL
#define SN_ADC_BASE						0x40047000UL
#define SN_I2S0_BASE                    0x40048000UL
#define SN_DAC_I2S_BASE					0x40048000UL
#define SN_DAC_AMP_BASE					0x40048200UL
#define SN_DAC_BASE						0x40049000UL
#define SN_SAR_ADC0_BASE				0x4004A000UL
#define SN_SAR_ADC1_BASE				0x4004B000UL
#define SN_PPU_BASE						0x40050000UL
#define SN_JPEG_DMA_BASE				0x40058000UL
#define SN_SCALING_DMA_BASE				0x40059000UL
#define SN_SDRAM_BASE                   0x4005A000UL   //SNC7312 NEW
#define SN_SDRAM_PROTECT_BASE           0x4005A020UL   //SNC7312 NEW
#define SN_SDRAM_CLK_RST_BASE           0x45000114UL   //SNC7312 NEW
#define SN_AES_BASE                     0x4005B000UL   //SNC7312 NEW
#define SN_OID_BASE                     0x40060000UL   //SNC7312 NEW
#define SN_OPM_BASE						0x45000000UL
#define SN_PERI_BASE					0x45000100UL
#define SN_ISO_BASE						0x45000200UL
#define SN_PMU_BASE						0x45000300UL
#define	SN_RTC_COUNTER_BASE				0x45000304UL
#define SN_TEST_BASE					0x45000400UL

/* =========================================================================================================================== */
/* ====================================               Peripheral declaration           ======================================= */
/* =========================================================================================================================== */
#define SN_GPIO0                        ((SN_GPIO0_Type           *) SN_GPIO0_BASE)
#define SN_GPIO1                        ((SN_GPIO0_Type           *) SN_GPIO1_BASE)
#define SN_GPIO2                        ((SN_GPIO0_Type           *) SN_GPIO2_BASE)
#define SN_GPIO3                        ((SN_GPIO0_Type           *) SN_GPIO3_BASE)
#define SN_GPIO4                        ((SN_GPIO0_Type           *) SN_GPIO4_BASE)
#define SN_WDT                          ((SN_WDT_Type             *) SN_WDT_BASE)
#define SN_RTC                          ((SN_RTC_Type             *) SN_RTC_BASE)
#define SN_CT16B0                       ((SN_CT16B0_Type          *) SN_CT16B0_BASE)
#define SN_CT16B1                       ((SN_CT16B0_Type          *) SN_CT16B1_BASE)
#define SN_CT32B0                       ((SN_CT32B0_Type          *) SN_CT32B0_BASE)
#define SN_CT32B1                       ((SN_CT32B0_Type          *) SN_CT32B1_BASE)
#define SN_SPI0                         ((SN_SPI_Type             *) SN_SPI0_BASE)
#define SN_SPI1                         ((SN_SPI_Type             *) SN_SPI1_BASE)
#define SN_I2C                          ((SN_I2C_Type             *) SN_I2C_BASE)
#define SN_UART0                        ((SN_UART_Type            *) SN_UART0_BASE)
#define SN_UART1                        ((SN_UART_Type            *) SN_UART1_BASE)
#define SN_I2S0                         ((SN_I2S_Type             *) SN_I2S0_BASE)
#define SN_I2S1                         ((SN_I2S_Type             *) SN_I2S1_BASE)
#define SN_I2S2                         ((SN_I2S2_Type            *) SN_I2S2_BASE)
#define SN_SAR_ADC                      ((SN_SAR_ADC_Type         *) SN_SAR_ADC0_BASE)
#define SN_SAR_ADC1                    	((SN_SAR_ADC_Type         *) SN_SAR_ADC1_BASE)
#define SN_DAC                          ((SN_DAC_Type             *) SN_DAC_BASE)
#define SN_FLASH                        ((SN_FLASH_Type           *) SN_FLASH_BASE)
#define SN_IDMA_RAM                     ((SN_IDMA_Type            *) SN_IDMA_RAM_BASE)  	     //IDMA0_CH0
#define SN_IDMA_JPEG_IN                 ((SN_IDMA_Type            *) SN_IDMA_JPEG_IN_BASE)     //IDMA0_CH1
#define SN_IDMA_JPEG_OUT                ((SN_IDMA_Type            *) SN_IDMA_JPEG_OUT_BASE)    //IDMA0_CH2
#define SN_IDMA_USB                     ((SN_IDMA_Type            *) SN_IDMA_USBDEV_BASE)
#define SN_IDMA_SDNF0					((SN_IDMA_Type            *) SN_IDMA_SDNF0_BASE)       //IDMA0_CH4
#define SN_IDMA_SDNF1					((SN_IDMA_Type            *) SN_IDMA_SDNF1_BASE)       //IDMA0_CH5
#define SN_IDMA_SPIF                    ((SN_IDMA_Type            *) SN_IDMA_SPIF_BASE)        //IDMA0_CH6
#define SN_IDMA_CIS                     ((SN_IDMA_Type            *) SN_IDMA_CIS_BASE)         //IDMA0_CH7
#define SN_IDMA_CSC_IN                  ((SN_IDMA_Type            *) SN_IDMA_CSC_IN_BASE)      //IDMA1_CH0 (CH8)
#define SN_IDMA_CSC_OUT                 ((SN_IDMA_Type            *) SN_IDMA_CSC_OUT_BASE)     //IDMA1_CH1 (CH9)
#define SN_SDCARD0                      ((SN_SDCARD_Type          *) SN_SDCARD0_BASE)
#define SN_SDCARD1                      ((SN_SDCARD_Type          *) SN_SDCARD1_BASE)
#define SN_NF							((SN_NF_Type              *) SN_NF_BASE)
#define SN_XtraROM						((SN_NF_Type              *) SN_NF_BASE)
#define SN_JPEG                        	((SN_JPEG_Type            *) SN_JPEG_BASE)
#define SN_CSC                        	((SN_CSC_Type             *) SN_CSC_BASE)
#define SN_PPU                        	((SN_PPU_Type             *) SN_PPU_BASE)
#define SN_CIS                          ((SN_CIS_Type             *) SN_CIS_BASE)
#define SN_JPEG_DMA						((SN_JPEG_DMA_Type		  *) SN_JPEG_DMA_BASE)
#define SN_SCALING_DMA					((SN_SCALING_DMA_Type	  *) SN_SCALING_DMA_BASE)
#define SN_SDRAM_CLK                    ((SN_SDRAM_CLK_Type       *) SN_SDRAM_CLK_RST_BASE)    //SNC7312 NEW SDRAM
#define SN_SDRAM                        ((SN_SDRAM_Type           *) SN_SDRAM_BASE)            //SNC7312 NEW SDRAM
#define SN_SDRAM_PRT                    ((SN_SDRAM_Protect_Type   *) SN_SDRAM_PROTECT_BASE)    //SNC7312 NEW SDRAM
#define SN_ADC                          ((SN_ADC_Type             *) SN_ADC_BASE)
#define SN_ADC_I2S                      ((SN_I2S_Type             *) SN_ADC_I2S_BASE)
#define SN_DAC                          ((SN_DAC_Type             *) SN_DAC_BASE)
#define SN_DAC_I2S                      ((SN_I2S_Type             *) SN_DAC_I2S_BASE)
#define SN_DAC_AMP                      ((SN_DAC_AMP_Type         *) SN_DAC_AMP_BASE)
#define SN_SYS0                        	((SN_OPM_Type             *) SN_OPM_BASE)
#define SN_SYS1                        	((SN_PERI_Type            *) SN_PERI_BASE)
#define SN_ISO                        	((SN_ISO_Type             *) SN_ISO_BASE)
#define SN_PMU                        	((SN_PMU_Type             *) SN_PMU_BASE)
#define SN_RTC_COUNTER                 	((SN_RTC_COUNTER_Type     *) SN_RTC_COUNTER_BASE)
#define SN_TESTMODE                    	((SN_TEST_Type            *) SN_TEST_BASE)
#define SN_OID							((SN_OID_Type             *) SN_OID_BASE)             //SNC7312 NEW OID
#define SN_AES							((SN_AES_Type             *) SN_AES_BASE)             //SNC7312 NEW AES

/** @} */ /* End of group Device_Peripheral_Registers                                                                         */
/** @} */ /* End of group SNC7312                                                                                             */
/** @} */ /* End of group SONiX Technology Co., Ltd.                                                                          */

#ifdef __cplusplus
}
#endif


#endif  /* SNC7312_H */

