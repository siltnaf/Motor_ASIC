/*
 * lib.c
 *	Copy Right (c) of Hong Kong Applied Science 
 *      and Technology Research Institute Company Limited
 *  Created on: 
 *      01 June 2016
 *  Author: 
 *      Lori Liu
 *  Last Modified: 
 *      12 August 2016 by Lori Liu
 *  Description: 
 *      lib for JE8MCU
 *  History:
 *      ver 0.1 created by Lori Liu on 12 August 2016     
 */
 
 /***************************************************
 * Includes
 */
#include <stdio.h>
#include <intrins.h>   
#include <absacc.h>

#include "lib.h"

//#define  _SIM_DEBUG_
/***************************************************
 * Variables
 */
//barrel shift 
sfr BSHCTL = 0xAB;
sfr BSHI_0 = 0xAC;
sfr BSHI_1 = 0xAD;
sfr BSHI_2 = 0xAE;
sfr BSHI_3 = 0xAF;
sfr BSHO_0 = 0xBC;
sfr BSHO_1 = 0xBD;
sfr BSHO_2 = 0xBE;
sfr BSHO_3 = 0xBF;

//multiplication division unit
sfr MD0 = 0xE9;
sfr MD1 = 0xEA;
sfr MD2 = 0xEB;
sfr MD3 = 0xEC;
sfr MD4 = 0xED;
sfr MD5 = 0xEE;
sfr ARCON = 0xEF;
//dptr
sfr DPL = 0x82;
sfr DPH = 0x83;

// MTP ext Ram ==========================================
#define   MTPCON1   0xe08e;
#define   MTPCON2   0xe08f;
#define   MTPCON3   0xe090;
#define   MTPSADD1  0xe091;
#define   MTPSADD2  0xe092;
#define   MTPDADD1  0xe093;
#define   MTPDADD2  0xe094;
#define   MTPDADD3  0xe095;
#define   MTPDADD4  0xe096;

volatile U8 xdata _md_error;// _at_ (0xDFFF);
volatile U16 xdata _div_remainder;// _at_ (0xDFFD);
volatile U16 xdata _div_denominator;// _at_ (0xA4FB);

#pragma asm
								CSEG    AT      4000h
#pragma endasm
const unsigned char tDebugTable[10] = {1,2,3,4,5,6,7,8,9,10};

S32 UartPass(void)
{
#pragma asm
		mov	dptr, #MTPCON3
		movx	a, @dptr

		mov	A, #0
		mov	dptr, #MTPSADD2
		movx	@dptr, A

		mov	A, #3
		mov	dptr, #MTPCON2		; write to MTPCON2 Authorize MTP access and enable write operation
		movx	@dptr, A

		mov	B, #0

		mov	A, B
		mov	dptr, #MTPSADD1
		movx	@dptr, A

		mov	A, #5
		mov	dptr, #MTPDADD1
		movx	@dptr, A
		mov	A, #9
		mov	dptr, #MTPDADD2
		movx	@dptr, A
		mov	A, #1
		mov	dptr, #MTPDADD3
		movx	@dptr, A
		mov	A, #3
		mov	dptr, #MTPDADD4
		movx	@dptr, A
		
		mov	dptr, #MTPCON1
		movx	a, @dptr
		
		mov	A, #9
		mov	dptr, #MTPCON1
		movx	@dptr, A				; write operation start

UP_loop0:		
		mov	dptr, #MTPCON1
		movx	a, @dptr
		anl		a, #0x20
;		jz	UP_loop0
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		
		;READ OPERATION
		mov	A, #5
		mov	dptr, #MTPCON2
		movx	@dptr, A				; Authorize MTP access and enable Read operation
		
		mov	b, #0
		mov	A, B
		mov	dptr, #MTPSADD1
		movx	@dptr, A
		mov		r0, A
		
		mov	A, #5
		mov	dptr, #MTPCON1
		movx	@dptr, A				; Enable MTP, Access MTP, Byte Read
		
UP_loop1:		
		mov	dptr, #MTPCON1
		movx	A, @dptr
;		cjne	A, #0x11, UP_loop1
	
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop

		mov		dptr, #MTPDADD1
		movx	A, @dptr
		mov		dptr, #MTPDADD2
		movx	A, @dptr
		mov		dptr, #MTPDADD3
		movx	A, @dptr
		mov		dptr, #MTPDADD4
		movx	A, @dptr
		

#pragma endasm
}

//barrel shift
/***************************************************
 * Implements
 */
/*
 * @fn		BarrelShift
 *
 * @brief	BarrelShift
 * 
 * @param	none
 *
 * @return 	none
 */
S32 BarrelShift(S32 in, S8 cmd)
{
  BSHCTL = cmd;
#pragma asm
  mov BSHI_3, r4
  mov BSHI_2, r5
  mov BSHI_1, r6
  mov BSHI_0, r7
	mov r4,BSHO_3
	mov r5,BSHO_2
	mov r6,BSHO_1
	mov r7,BSHO_0
#pragma endasm
}

/*
 * @fn		Div32
 *
 * @brief	Div32
 * 
 * @param	none
 *
 * @return 	none
 */
S32 Div32(S32 numerator , S16 denominator)
{
	_div_denominator = denominator;
	
#pragma asm
#pragma endasm
}

/*
 * @fn		Div16
 *
 * @brief	Div16
 * 
 * @param	none
 *
 * @return 	none
 */
S16 Div16(S16 numerator , S16 denominator)
{
#pragma asm
	mov	r1,	#0
	mov	A,	r6
	rlc	A
	jnc	D16_P1
	mov	r1, #1
	clr	C
	clr	A
	subb	A, r7
	mov	MD0, A
	clr	A
	subb	A, R6
	mov	MD1, A
	sjmp	D16_common
D16_P1:
  mov MD0, r7
  mov MD1, r6
D16_common:			
	mov	A, r4
	rlc	A
	jnc	D16_PD
	mov	A, #2
	orl	A, r1
	mov	r1, A
	clr	C
	clr	A
	subb	A, r5
	mov	MD4, A
	clr	A
	subb	A, r4
	mov	MD5, A
	sjmp	D16_GO
D16_PD:
  mov MD4, r5
  mov MD5, r4
D16_GO:	
	nop    ;wait 34
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 24
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 14
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 4
  nop
  nop
  nop
 #pragma endasm

  _md_error = (ARCON&(MD_MDEF|MD_MDOV));

#pragma asm
	mov	a, r1
	jz	Div16_RNS
	clr	C
	subb	A,	#1
	jz	DIV_16_R1
	mov	a, r1
	clr	C
	subb	A,	#2
	jz	DIV_16_R2
DIV_16_R3:
  mov r7, MD0
  mov r6, MD1
	sjmp	DIV_16_NR
DIV_16_R2:
	clr	C
	clr	A
	subb	A, MD0
	mov	r7, A
	clr	A
	subb	A, MD1
	mov	r6, A
	sjmp	DIV_16_PR
DIV_16_R1:
	clr	C
	clr	A
	subb	A, MD0
	mov	r7, A
	clr	A
	subb	A, MD1
	mov	r6, A
DIV_16_NR:
  MOV  	DPTR,#_div_remainder+1
	clr	C
	clr	A
	subb	A, MD4
	MOVX 	@DPTR,A
	MOV  	DPTR,#_div_remainder
	clr	A
	subb	A, MD5
	MOVX 	@DPTR,A

	RET
Div16_RNS:
  mov r7, MD0
  mov r6, MD1
DIV_16_PR:
  MOV  	DPTR,#_div_remainder+1
  mov a, MD4
	MOVX 	@DPTR,A
	MOV  	DPTR,#_div_remainder
  mov a, MD5 
  MOVX 	@DPTR,A
//	mov r1, #0xFE
//	mov a, MD4
//  movx @r1, a
//  dec r1
//	mov a, MD5
//	movx @r1, a
#pragma endasm
}

/*
 * @fn		Div16
 *
 * @brief	Div16
 * 
 * @param	none
 *
 * @return 	none
 */
S32 Shift32(S32 dat, U8 cmd)
{
#pragma asm
  mov MD0, r7
  mov MD1, r6
  mov MD2, r5
  mov MD3, r4
#pragma endasm

	ARCON = cmd;

#pragma asm
	nop    ;wait 33
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 23
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 13
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 3
  nop
  nop
#pragma endasm

  _md_error = (ARCON&(MD_MDEF|MD_MDOV));

#pragma asm
	mov r7, MD0
	mov r6, MD1
	mov r5, MD2
	mov r4, MD3
#pragma endasm
}

/*
 * @fn		Normalize
 *
 * @brief	Normalize
 * 
 * @param	none
 *
 * @return 	none
 */
S32 Normalize(S32 dat)
{
#pragma asm
  mov MD0, r7
  mov MD1, r6
  mov MD2, r5
  mov MD3, r4

	ANL  ARCON , #0xE0

	nop    ;wait 34
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 24
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 14
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 4
  nop
  nop
  nop
#pragma endasm
  _md_error = (ARCON&(MD_MDEF|MD_MDOV));
#pragma asm
 	mov r7, MD0
	mov r6, MD1
	mov r5, MD2
	mov r4, MD3
#pragma endasm
}

/*
 * @fn		Mul
 *
 * @brief	Mul
 * 
 * @param	none
 *
 * @return 	none
 */
S32 Mul(S16 multiplicand, S16 multiplicator)
{
#pragma asm
	mov	r1, #0
	mov	A, r6
	rlc	A
	jnc	MUL_P_M1
	mov	r1, #1
	clr	C
	clr	A
	subb	A, r7
	mov	MD0, A
	clr	A
	subb	A, R6
	mov	R6, A
	sjmp	MUL_common
MUL_P_M1:
	mov MD0, r7
MUL_common :
	mov	A, r4
	rlc	A
	jnc	MUL_P_M2
	mov	A, #1
	xrl	A, r1
	mov	r1, A
	clr	C
	clr	A
	subb	A, r5
	mov	MD4, A
	clr	A
	subb	A, r4
	mov	r4, A
	sjmp	MUL_Common_2
MUL_P_M2:
  mov MD4, r5
MUL_Common_2:
  mov MD1, r6
  mov MD5, r4
	nop    ;wait 18
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
  nop
  nop
	nop    ;wait 8
  nop
  nop
  nop
  nop
	nop    
  nop
  nop
#pragma endasm
	_md_error = (ARCON&(MD_MDEF|MD_MDOV));
#pragma asm	
	mov	a, r1
	jz	MUL_Positive
	clr	C
	clr	A
	subb	A, MD0
	mov	r7, A
	clr	A
	subb	A, MD1
	mov	r6, A
	clr A
	subb	A, MD2
	mov	r5, A
	clr	A
	subb	A, MD3
	mov	r4, A
	ret
MUL_Positive:
	mov r7, MD0
	mov r6, MD1
	mov r5, MD2
	mov r4, MD3
#pragma endasm
}

