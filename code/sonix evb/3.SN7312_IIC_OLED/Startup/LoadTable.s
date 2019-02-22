;*** <<< Use Configuration Wizard in Context Menu >>> ***
;<h> SONiX SNC7312 Load Table Configuration
;   <o1> Mark_String_L                     0x33313241
;   <o2> Mark_String_H                     0x534E4337
;   <o3.0> Enable User Code Encyption
;   <o3.1> Enable Multiple User Code

 AREA	|.ARM.__at_0x60002000|, DATA, READONLY
	;Linker-defined symbols to use
	;Symbols to export
	
	; EXPORT UserCodeAddr0
	; EXPORT UserCodeAddr1
	; EXPORT UserCodeAddr2
	; EXPORT UserCodeAddr3
	; EXPORT UserCodeAddr4
	; EXPORT UserCodeAddr5
	
MARK
	DCD 0x33313241;'3','1','2','A'
	DCD 0x534E4337;'S','N','C','7' 
	DCD 0x00000000;	
	DCD 0x00000000;DLO List address
; UserCodeAddr0
	DCD 0x60100000;PRAM0
; UserCodeAddr1
	DCD 0x00000000;PRAM1
; UserCodeAddr2
	DCD 0x00000000;PRAM2
; UserCodeAddr3
	DCD 0x00000000;PRAM3
; UserCodeAddr4
	DCD 0x00000000;PRAM4
; UserCodeAddr5
	DCD 0x00000000;PRAM5
	END 
; </h>
;*** <<< end of configuration section >>>    ***

	