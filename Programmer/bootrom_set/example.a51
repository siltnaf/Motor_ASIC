;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Write EEPROM[7]
;; R2 = bit8-15
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
$Include (..\..\Include\Register.INC)
$Include (..\..\Include\TO2_esfr.INC)
PROG_OFFSET EQU 02000h


;#define Xtal 1
#define RC 1
#define high_byte 0x70
;#define ee_command 0x2261
;#define Reg_Data_Start 0x2262 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
EMOV	MACRO Addr, Data		
		MOV		DPTR,#Addr 	
		MOV		A,#Data
		MOVX 	@DPTR, A 
		ENDM
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
EMOVR	MACRO Addr	
		MOV		DPTR,#Addr 	
		MOVX 	A,@DPTR
		ENDM
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SerialWrite MACRO Val
		CLR		TI0
		MOV		S0_BUF,#Val
		JNB		TI0,$	
		ENDM
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;		
 
		ORG		PROG_OFFSET
		LJMP	START
		
START:
		MOV		R1,#00h
		MOV		R2,#66h
		MOV		R3,#00h
		MOV		R4,#00h	
        MOV     SP,#50H         ;init stack pointer
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Select external 32MHz clock		
#ifdef  Xtal
		EMOV	P0_FN_L, 10h	;select external 32M clock source
		MOV		CLK_PD_CON, #05h
		EMOV	CLK_DIV_L, 01h
#endif
#ifdef RC		
		EMOV	CLK_DIV_L, 04h	
#endif
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;		
;Port 1				
		EMOV	P1_FN_L, 00h		;(P1_FN_L): P1.0-P1.3 mux selection
		EMOV	P1_FN_H, 50h		;(P1_FN_H): P1.4-P1.7 mux selection
		EMOV	P1DD, 0FFh 			;(P1DD): Input/Output Select, 0=input, 1=output		

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; main
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
main:	
		mov	dptr, #0h 
		mov	a,#0
		movc 	A, @A+DPTR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; EEPROM Write
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		mov	A, #0x53
		mov	dptr, #MTPCON2		; write to MTPCON2 Authorize MTP access and enable write operation
		movx	@dptr, A
UP_ReadDone:		
		; Writing EEPROM

		mov	dps, #0
		; Writing Destination Address
		mov	A, #0x00
		mov	dptr, #mtpsadd2
		movx	@dptr, A

		mov 	R5,#0x07	;EEPROM Address
		mov		b,#1	
		
		; Writing 4-Bytes to MTP Data Bus		
	
		mov		dps, #0		
		mov		A, R1
		mov		dptr, #mtpdata1
		movx	@dptr, A
		mov		A, R2
		mov		dptr, #mtpdata2
		movx	@dptr, A
		mov		A, R3
		mov		dptr, #mtpdata3
		movx	@dptr, A
		mov		A, R4
		mov		dptr, #mtpdata4
		movx	@dptr, A
		
		mov		A, #11
		mov		dptr, #mtpcon1
		movx	@dptr, A				; write operation start

UP_loopEEPROM:		
		mov		dptr, #mtpcon1
		movx	a, @dptr
		anl		a, #0x20
		jz		UP_loopEEPROM					; Loop until writing done		
		jmp     $	
END
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	