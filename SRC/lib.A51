; .\Objects\lib.SRC generated from: lib.c
; COMPILER INVOKED BY:
;        C:\Keil_v5\C51\BIN\C51.EXE lib.c OPTIMIZE(9,SPEED) BROWSE DEBUG OBJECTEXTEND PRINT(.\Listings\lib.lst) TABS(2) SRC(.\Objects\lib.SRC)

$NOMOD51

NAME	LIB

BSHI_0	DATA	0ACH
BSHI_1	DATA	0ADH
BSHI_2	DATA	0AEH
BSHI_3	DATA	0AFH
BSHO_0	DATA	0BCH
BSHO_1	DATA	0BDH
BSHO_2	DATA	0BEH
BSHO_3	DATA	0BFH
MD0	DATA	0E9H
MD1	DATA	0EAH
BSHCTL	DATA	0ABH
MD2	DATA	0EBH
MD3	DATA	0ECH
MD4	DATA	0EDH
MD5	DATA	0EEH
DPH	DATA	083H
DPL	DATA	082H
ARCON	DATA	0EFH
?PR?_BarrelShift?LIB SEGMENT CODE 
?DT?_BarrelShift?LIB SEGMENT DATA OVERLAYABLE 
?PR?_Div32?LIB       SEGMENT CODE 
?DT?_Div32?LIB       SEGMENT DATA OVERLAYABLE 
?PR?_Div16?LIB       SEGMENT CODE 
?DT?_Div16?LIB       SEGMENT DATA OVERLAYABLE 
?PR?_Shift32?LIB     SEGMENT CODE 
?DT?_Shift32?LIB     SEGMENT DATA OVERLAYABLE 
?PR?_Normalize?LIB   SEGMENT CODE 
?DT?_Normalize?LIB   SEGMENT DATA OVERLAYABLE 
?PR?_Mul?LIB         SEGMENT CODE 
?DT?_Mul?LIB         SEGMENT DATA OVERLAYABLE 
?PR?LIB              SEGMENT CODE 
	PUBLIC	_div_remainder
	PUBLIC	_md_error
	PUBLIC	_div_denominator
	PUBLIC	_Mul
	PUBLIC	_Normalize
	PUBLIC	?_Shift32?BYTE
	PUBLIC	_Shift32
	PUBLIC	_Div16
	PUBLIC	?_Div32?BYTE
	PUBLIC	_Div32
	PUBLIC	?_BarrelShift?BYTE
	PUBLIC	_BarrelShift

	XSEG  AT  0DFFBH
_div_denominator:   DS   2

	XSEG  AT  0DFFFH
      _md_error:   DS   1

	XSEG  AT  0DFFDH
 _div_remainder:   DS   2

	RSEG  ?DT?_Div32?LIB
?_Div32?BYTE:
  numerator?142:   DS   4
	ORG  4
denominator?143:   DS   2

	RSEG  ?DT?_Div16?LIB
?_Div16?BYTE:
  numerator?244:   DS   2
	ORG  2
denominator?245:   DS   2

	RSEG  ?DT?_Mul?LIB
?_Mul?BYTE:
multiplicand?549:   DS   2
	ORG  2
multiplicator?550:   DS   2

	RSEG  ?DT?_Normalize?LIB
?_Normalize?BYTE:
        dat?448:   DS   4

	RSEG  ?DT?_BarrelShift?LIB
?_BarrelShift?BYTE:
         in?040:   DS   4
	ORG  4
        cmd?041:   DS   1

	RSEG  ?DT?_Shift32?LIB
?_Shift32?BYTE:
        dat?346:   DS   4
	ORG  4
        cmd?347:   DS   1
; /*
;  * lib.c
;  *	Copy Right (c) of Hong Kong Applied Science 
;  *      and Technology Research Institute Company Limited
;  *  Created on: 
;  *      01 June 2016
;  *  Author: 
;  *      Lori Liu
;  *  Last Modified: 
;  *      12 August 2016 by Lori Liu
;  *  Description: 
;  *      lib for JE8MCU
;  *  History:
;  *      ver 0.1 created by Lori Liu on 12 August 2016     
;  */
;  
;  /***************************************************
;  * Includes
;  */
; #include <stdio.h>
; #include <intrins.h>   
; #include <absacc.h>
; 
; #include "lib.h"
; 
; //#define  _SIM_DEBUG_
; /***************************************************
;  * Variables
;  */
; //barrel shift 
; sfr BSHCTL = 0xAB;
; sfr BSHI_0 = 0xAC;
; sfr BSHI_1 = 0xAD;
; sfr BSHI_2 = 0xAE;
; sfr BSHI_3 = 0xAF;
; sfr BSHO_0 = 0xBC;
; sfr BSHO_1 = 0xBD;
; sfr BSHO_2 = 0xBE;
; sfr BSHO_3 = 0xBF;
; 
; //multiplication division unit
; sfr MD0 = 0xE9;
; sfr MD1 = 0xEA;
; sfr MD2 = 0xEB;
; sfr MD3 = 0xEC;
; sfr MD4 = 0xED;
; sfr MD5 = 0xEE;
; sfr ARCON = 0xEF;
; 
; //dptr
; sfr DPL = 0x82;
; sfr DPH = 0x83;
; 
; volatile U8 xdata _md_error _at_ (0xDFFF);
; volatile U16 xdata _div_remainder _at_ (0xDFFD);
; volatile U16 xdata _div_denominator _at_ (0xDFFB);
; 
; //barrel shift
; /***************************************************
;  * Implements
;  */
; /*
;  * @fn		BarrelShift
;  *
;  * @brief	BarrelShift
;  * 
;  * @param	none
;  *
;  * @return 	none
;  */

	RSEG  ?PR?LIB
Com0007:
L?0008:
	USING	0
L?0009:
	MOV  	A,ARCON
	ANL  	A,#0C0H
	MOV  	DPTR,#_md_error
	MOVX 	@DPTR,A
	RET  	
; END OF Com0007

; S32 BarrelShift(S32 in, S8 cmd)

	RSEG  ?PR?_BarrelShift?LIB
_BarrelShift:
	USING	0
			; SOURCE LINE # 71
;	MOV  	in?040+03H,R7
;	MOV  	in?040+02H,R6
;	MOV  	in?040+01H,R5
;	MOV  	in?040,R4
; {
			; SOURCE LINE # 72
;   BSHCTL = cmd;
			; SOURCE LINE # 73
	MOV  	BSHCTL,cmd?041
; #pragma asm
;   mov BSHI_3, r4
	  mov BSHI_3, r4
;   mov BSHI_2, r5
	  mov BSHI_2, r5
;   mov BSHI_1, r6
	  mov BSHI_1, r6
;   mov BSHI_0, r7
	  mov BSHI_0, r7
; 	mov r4,BSHO_3
	  mov r4,BSHO_3
; 	mov r5,BSHO_2
	  mov r5,BSHO_2
; 	mov r6,BSHO_1
	  mov r6,BSHO_1
; 	mov r7,BSHO_0
	  mov r7,BSHO_0
; #pragma endasm
; }
			; SOURCE LINE # 84
	RET  	
; END OF _BarrelShift

; 
; /*
;  * @fn		Div32
;  *
;  * @brief	Div32
;  * 
;  * @param	none
;  *
;  * @return 	none
;  */
; S32 Div32(S32 numerator , S16 denominator)

	RSEG  ?PR?_Div32?LIB
_Div32:
	USING	0
			; SOURCE LINE # 95
;	MOV  	numerator?142+03H,R7
;	MOV  	numerator?142+02H,R6
;	MOV  	numerator?142+01H,R5
;	MOV  	numerator?142,R4
; {
			; SOURCE LINE # 96
; 	_div_denominator = denominator;
			; SOURCE LINE # 97
	MOV  	DPTR,#_div_denominator
	MOV  	A,denominator?143
	MOVX 	@DPTR,A
	INC  	DPTR
	MOV  	A,denominator?143+01H
	MOVX 	@DPTR,A
; 	
; #pragma asm
;   mov MD0, r7
	  mov MD0, r7
;   mov MD1, r6
	  mov MD1, r6
;   mov MD2, r5
	  mov MD2, r5
;   mov MD3, r4
	  mov MD3, r4
; 
	  
; 	mov r0, #0xFC
	  mov r0, #0xFC
; 	movx a, @r0
	  movx a, @r0
;   mov MD4, a
	  mov MD4, a
;   dec r0
	  dec r0
; 	movx a, @r0
	  movx a, @r0
;   mov MD5, a
	  mov MD5, a
; 	nop    ;wait 50
	  nop    ;wait 50
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 40
	  nop    ;wait 40
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 30
	  nop    ;wait 30
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 20
	  nop    ;wait 20
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 10
	  nop    ;wait 10
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; #pragma endasm
; 
;   _md_error = (ARCON&(MD_MDEF|MD_MDOV));
			; SOURCE LINE # 163
	LCALL	L?0008
; 
;  #pragma asm
;   mov r7, MD0
	  mov r7, MD0
;   mov r6, MD1
	  mov r6, MD1
;   mov r5, MD2
	  mov r5, MD2
;   mov r4, MD3
	  mov r4, MD3
; #pragma endasm
; 
; #pragma asm
; 	mov r1, #0xFE
	  mov r1, #0xFE
;   mov a, MD4
	  mov a, MD4
; 	movx @r1, a
	  movx @r1, a
;   dec r1
	  dec r1
;   mov a, MD5
	  mov a, MD5
; 	movx @r1, a
	  movx @r1, a
; #pragma endasm
; }
			; SOURCE LINE # 180
	RET  	
; END OF _Div32

; 
; /*
;  * @fn		Div16
;  *
;  * @brief	Div16
;  * 
;  * @param	none
;  *
;  * @return 	none
;  */
; S16 Div16(S16 numerator , S16 denominator)

	RSEG  ?PR?_Div16?LIB
_Div16:
	USING	0
			; SOURCE LINE # 191
;	MOV  	numerator?244,R6
;	MOV  	numerator?244+01H,R7
;	MOV  	denominator?245,R4
;	MOV  	denominator?245+01H,R5
; {
			; SOURCE LINE # 192
; #pragma asm
;   mov MD0, r7
	  mov MD0, r7
;   mov MD1, r6
	  mov MD1, r6
;   mov MD4, r5
	  mov MD4, r5
;   mov MD5, r4
	  mov MD5, r4
; 	nop    ;wait 34
	  nop    ;wait 34
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 24
	  nop    ;wait 24
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 14
	  nop    ;wait 14
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 4
	  nop    ;wait 4
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;  #pragma endasm
; 
;   _md_error = (ARCON&(MD_MDEF|MD_MDOV));
			; SOURCE LINE # 234
	LCALL	L?0008
; 
; #pragma asm
;   mov r7, MD0
	  mov r7, MD0
;   mov r6, MD1
	  mov r6, MD1
; 
	  
; 	mov r1, #0xFE
	  mov r1, #0xFE
; 	mov a, MD4
	  mov a, MD4
;   movx @r1, a
	  movx @r1, a
;   dec r1
	  dec r1
; 	mov a, MD5
	  mov a, MD5
; 	movx @r1, a
	  movx @r1, a
; #pragma endasm
; }
			; SOURCE LINE # 247
	RET  	
; END OF _Div16

; 
; /*
;  * @fn		Div16
;  *
;  * @brief	Div16
;  * 
;  * @param	none
;  *
;  * @return 	none
;  */
; S32 Shift32(S32 dat, U8 cmd)

	RSEG  ?PR?_Shift32?LIB
_Shift32:
	USING	0
			; SOURCE LINE # 258
;	MOV  	dat?346+03H,R7
;	MOV  	dat?346+02H,R6
;	MOV  	dat?346+01H,R5
;	MOV  	dat?346,R4
; {
			; SOURCE LINE # 259
; #pragma asm
;   mov MD0, r7
	  mov MD0, r7
;   mov MD1, r6
	  mov MD1, r6
;   mov MD2, r5
	  mov MD2, r5
;   mov MD3, r4
	  mov MD3, r4
; #pragma endasm
; 
; 	ARCON = cmd;
			; SOURCE LINE # 267
	MOV  	ARCON,cmd?347
; 
; #pragma asm
; 	nop    ;wait 33
	  nop    ;wait 33
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 23
	  nop    ;wait 23
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 13
	  nop    ;wait 13
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 3
	  nop    ;wait 3
;   nop
	  nop
;   nop
	  nop
; #pragma endasm
; 
;   _md_error = (ARCON&(MD_MDEF|MD_MDOV));
			; SOURCE LINE # 305
	LCALL	L?0009
; 
; #pragma asm
; 	mov r7, MD0
	  mov r7, MD0
; 	mov r6, MD1
	  mov r6, MD1
; 	mov r5, MD2
	  mov r5, MD2
; 	mov r4, MD3
	  mov r4, MD3
; #pragma endasm
; }
			; SOURCE LINE # 313
	RET  	
; END OF _Shift32

; 
; /*
;  * @fn		Normalize
;  *
;  * @brief	Normalize
;  * 
;  * @param	none
;  *
;  * @return 	none
;  */
; S32 Normalize(S32 dat)

	RSEG  ?PR?_Normalize?LIB
_Normalize:
	USING	0
			; SOURCE LINE # 324
;	MOV  	dat?448+03H,R7
;	MOV  	dat?448+02H,R6
;	MOV  	dat?448+01H,R5
;	MOV  	dat?448,R4
; {
			; SOURCE LINE # 325
; #pragma asm
;   mov MD0, r7
	  mov MD0, r7
;   mov MD1, r6
	  mov MD1, r6
;   mov MD2, r5
	  mov MD2, r5
;   mov MD3, r4
	  mov MD3, r4
; 
	  
; 	ANL  ARCON , #0xE0
	  ANL  ARCON , #0xE0
; 
	  
; 	nop    ;wait 34
	  nop    ;wait 34
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 24
	  nop    ;wait 24
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 14
	  nop    ;wait 14
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 4
	  nop    ;wait 4
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; #pragma endasm
;   _md_error = (ARCON&(MD_MDEF|MD_MDOV));
			; SOURCE LINE # 369
	LCALL	L?0009
; #pragma asm
;  	mov r7, MD0
	  mov r7, MD0
; 	mov r6, MD1
	  mov r6, MD1
; 	mov r5, MD2
	  mov r5, MD2
; 	mov r4, MD3
	  mov r4, MD3
; #pragma endasm
; }
			; SOURCE LINE # 376
	RET  	
; END OF _Normalize

; 
; /*
;  * @fn		Mul
;  *
;  * @brief	Mul
;  * 
;  * @param	none
;  *
;  * @return 	none
;  */
; S32 Mul(S16 multiplicand, S16 multiplicator)

	RSEG  ?PR?_Mul?LIB
_Mul:
	USING	0
			; SOURCE LINE # 387
;	MOV  	multiplicand?549,R6
;	MOV  	multiplicand?549+01H,R7
;	MOV  	multiplicator?550,R4
;	MOV  	multiplicator?550+01H,R5
; {
			; SOURCE LINE # 388
; #pragma asm
;   mov MD0, r7
	  mov MD0, r7
;   mov MD4, r6
	  mov MD4, r6
;   mov MD1, r5
	  mov MD1, r5
;   mov MD5, r4
	  mov MD5, r4
; 	nop    ;wait 18
	  nop    ;wait 18
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    ;wait 8
	  nop    ;wait 8
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
;   nop
	  nop
; 	nop    
	  nop    
;   nop
	  nop
;   nop
	  nop
; #pragma endasm
; 	_md_error = (ARCON&(MD_MDEF|MD_MDOV));
			; SOURCE LINE # 413
	LCALL	L?0009
; #pragma asm	
; 	mov r7, MD0
	  mov r7, MD0
; 	mov r6, MD1
	  mov r6, MD1
; 	mov r5, MD2
	  mov r5, MD2
; 	mov r4, MD3
	  mov r4, MD3
; #pragma endasm
; }
			; SOURCE LINE # 420
	RET  	
; END OF _Mul

	END
