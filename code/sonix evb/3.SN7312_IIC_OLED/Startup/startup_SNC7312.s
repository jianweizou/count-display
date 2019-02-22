;/******************************************************************************
; * @file     startup_SNC7312.s
; * @brief    CMSIS Cortex-M0 Core Device Startup File
; *           for the SONIX SNC7312 Device Series
; * @version  V1.0
; * @date     June 2015
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; * @note
; * Copyright (C) 2009-2010 ARM Limited. All rights reserved.
; *
; * @par
; * ARM Limited (ARM) is supplying this software for use with Cortex-M 
; * processor based microcontrollers.  This file can be freely distributed 
; * within development tools that are supporting such ARM based processors. 
; *
; * @par
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; ******************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size		EQU		0x00000600

				AREA	STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem		SPACE	Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size		EQU		0x00000000

				AREA	HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem		SPACE	Heap_Size
__heap_limit


				PRESERVE8
				THUMB


; Vector Table Mapped to Address 0 at Reset

				AREA	RESET, DATA, READONLY
				EXPORT	__Vectors

__Vectors		DCD		__initial_sp				; Top of Stack
				DCD		Reset_Handler				; Reset Handler
				DCD		NMI_Handler					; NMI Handler
                DCD     HardFault_Handler			; Hard Fault Handler
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		SVC_Handler					; SVCall Handler
				DCD		0							; Reserved
				DCD		0							; Reserved
				DCD		PendSV_Handler				; PendSV Handler
				DCD		SysTick_Handler				; SysTick Handler
			    ;DCD OS_CPU_SysTickHandler

				; External Interrupts
				DCD		MPU_IRQHandler				; 16+ 0: Wakeup
				DCD		DSP_Issue_IRQHandler		; 16+ 1: DSP Issue
				DCD		USBDEV_IRQHandler		    ; 16+ 2: USB
				DCD		CIS_IRQHandler				; 16+ 3: CIS
				DCD		PPU_HBLK_IRQHandler			; 16+ 4: PPU HBLK
				DCD		SD_DAC_IRQHandler			; 16+ 5: SD_DAC
				DCD		SD_ADC_IRQHandler			; 16+ 6: SD_ADC
				DCD		DMA_SDNF1_IRQHandler		; 16+ 7: DMA SDCARD1 | NF
				DCD		SPI1_IRQHandler				; 16+ 8: SPI1
				DCD		I2S2_IRQHandler		    	; 16+ 9: I2S_2
				DCD		DMA_CSC_IRQHandler	        ; 16+10: DMA CSC
				DCD		DMA_JPEG_IRQHandler		    ; 16+11: DMA JPEG
				DCD		CIS_VSYNC_IRQHandler		; 16+12: CIS Vsync
				DCD		SPI0_IRQHandler  			; 16+13: SPI0
				DCD		PPU_VBLK_IRQHandler			; 16+14: PPU VBLK
				DCD     I2C_IRQHandler 		   	    ; 16+15: I2C
				DCD     CT16B0_IRQHandler  			; 16+16: 16-bit Counter-Timer 0
				DCD     CT16B1_IRQHandler  			; 16+17: 16-bit Counter-Timer 1
				DCD     CT32B0_IRQHandler  			; 16+18: 32-bit Counter-Timer 1
				DCD     CT32B1_IRQHandler  			; 16+19: 32-bit Counter-Timer 0				
				DCD     P4_WKP_IRQHandler     	    ; 16+20: GPIO INT4 | Wakeup INT
				DCD		UART0_IRQHandler 			; 16+21: UART0
				DCD		NFECC_IRQHandler			; 16+22: NF ECC
				DCD		DMA_SDNF0_IRQHandler	    ; 16+23: DMA SDCARD0 | NF
				DCD		SARADC_IRQHandler			; 16+24: SAR ADC
				DCD		WDT_UART1_IRQHandler	    ; 16+25: Watchdog Timer | UART1
				DCD		USBHOST_IRQHandler			; 16+26: USB HOST
				DCD		RTC_IRQHandler				; 16+27: Real Time Clock
				DCD		P3_IRQHandler				; 16+28: GPIO INT3
				DCD		P2_IRQHandler				; 16+29: GPIO INT2
				DCD		P1_IRQHandler				; 16+30: GPIO INT1
				DCD		P0_IRQHandler				; 16+31: GPIO INT0


                


              
				AREA	|.text|, CODE, READONLY

; Reset Handler

Reset_Handler	PROC
				EXPORT  Reset_Handler			[WEAK]
				;IMPORT  Peri_Inital
				IMPORT  __main
				;LDR     R0, =Peri_Inital
				;BLX     R0
				LDR     R0, =__main
				BX      R0
				ENDP


; Dummy Exception Handlers (infinite loops which can be modified)                

NMI_Handler		PROC
				EXPORT	NMI_Handler				    [WEAK]
				B		.
				ENDP
HardFault_Handler	PROC
				EXPORT	HardFault_Handler		    [WEAK]
				B		.
				ENDP
SVC_Handler		PROC
				EXPORT	SVC_Handler				    [WEAK]
				B		.
				ENDP
PendSV_Handler	PROC
				EXPORT	PendSV_Handler			    [WEAK]
				B		.
				ENDP
SysTick_Handler	PROC
				EXPORT	SysTick_Handler			    [WEAK]
				B		.
				ENDP
;OS_CPU_SysTickHandler	PROC
			;	EXPORT	OS_CPU_SysTickHandler			[WEAK]
			;	B		.
			;	ENDP				
Default_Handler	PROC
				EXPORT		MPU_IRQHandler			[WEAK] ;0
				EXPORT		DSP_Issue_IRQHandler	[WEAK] ;1
				EXPORT 		USBDEV_IRQHandler		[WEAK] ;2
				EXPORT		CIS_IRQHandler			[WEAK] ;3
				EXPORT		PPU_HBLK_IRQHandler		[WEAK] ;4
				EXPORT		SD_DAC_IRQHandler		[WEAK] ;5
				EXPORT		SD_ADC_IRQHandler		[WEAK] ;6
				EXPORT		DMA_SDNF1_IRQHandler   	[WEAK] ;7
				EXPORT		SPI1_IRQHandler			[WEAK] ;8
				EXPORT		I2S2_IRQHandler	        [WEAK] ;9
				EXPORT		DMA_CSC_IRQHandler      [WEAK] ;10
				EXPORT		DMA_JPEG_IRQHandler	    [WEAK] ;11
				EXPORT		CIS_VSYNC_IRQHandler	[WEAK] ;12
				EXPORT		SPI0_IRQHandler			[WEAK] ;13
				EXPORT		PPU_VBLK_IRQHandler		[WEAK] ;14
				EXPORT		I2C_IRQHandler			[WEAK] ;15
				EXPORT		CT16B0_IRQHandler 		[WEAK] ;16
				EXPORT		CT16B1_IRQHandler		[WEAK] ;17
				EXPORT		CT32B0_IRQHandler		[WEAK] ;18
				EXPORT		CT32B1_IRQHandler		[WEAK] ;19
				EXPORT		P4_WKP_IRQHandler		[WEAK] ;20
				EXPORT		UART0_IRQHandler	    [WEAK] ;21
				EXPORT 		NFECC_IRQHandler		[WEAK] ;22
				EXPORT		DMA_SDNF0_IRQHandler	[WEAK] ;23
				EXPORT		SARADC_IRQHandler		[WEAK] ;24
				EXPORT		WDT_UART1_IRQHandler	[WEAK] ;25
				EXPORT      USBHOST_IRQHandler      [WEAK] ;26
				EXPORT      RTC_IRQHandler          [WEAK] ;27
				EXPORT		P3_IRQHandler			[WEAK] ;28
				EXPORT		P2_IRQHandler			[WEAK] ;29
				EXPORT		P1_IRQHandler			[WEAK] ;30
				EXPORT		P0_IRQHandler			[WEAK] ;31

				

MPU_IRQHandler
DSP_Issue_IRQHandler
USBDEV_IRQHandler
CIS_IRQHandler
PPU_HBLK_IRQHandler
SD_DAC_IRQHandler
SD_ADC_IRQHandler
DMA_SDNF1_IRQHandler
SPI1_IRQHandler
I2S2_IRQHandler
DMA_CSC_IRQHandler
DMA_JPEG_IRQHandler
CIS_VSYNC_IRQHandler
SPI0_IRQHandler
PPU_VBLK_IRQHandler
I2C_IRQHandler
CT16B0_IRQHandler
CT16B1_IRQHandler
CT32B0_IRQHandler
CT32B1_IRQHandler		
P4_WKP_IRQHandler
UART0_IRQHandler
NFECC_IRQHandler
DMA_SDNF0_IRQHandler
SARADC_IRQHandler
WDT_UART1_IRQHandler
USBHOST_IRQHandler
RTC_IRQHandler
P3_IRQHandler
P2_IRQHandler
P1_IRQHandler
P0_IRQHandler
				

                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, =  Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
