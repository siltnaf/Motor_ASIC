/*
 * lib.c
 *	Copy Right (c) of JE
 *  Created on: 
 *      18 Sep 2018
 *  Author: 
 *      Ken
 *  Last Modified: 
 *     
 *  Description: 
 *      lib for JE8MCU
 *  History:
 *      ver 0.1 created by ken on 12 August 2016 
 *
 *		Use math table for fuctions of 
 *				sin, cos, inverse, sqrt, artan
 *				Park transform and Clark transform
 *
 *
 */
 
 /***************************************************
 * Includes
 */
#include <stdio.h>
#include <intrins.h>   
#include <absacc.h>
#include "register.h"
#include "lib.h"



volatile U8 xdata _md_error;// _at_ (0xDFFF);
volatile U16 xdata _div_remainder;// _at_ (0xDFFD);
volatile U16 xdata _div_denominator;// _at_ (0xA4FB);

#pragma asm
								CSEG    AT      4000h
#pragma endasm
const unsigned char tDebugTable[10] = {1,2,3,4,5,6,7,8,9,10};





/*
 * @fn		sin16
 *
 * @brief	sin16
 * 
 * @param	none
 * sin(x) , where x is 

 *
 * @return 	none
 */
S16 sin(S16 dat)
{
volatile signed int value;
	value= XWORD[dat];
	
return value;
	
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
//S32 Normalize(S32 dat)
//{
//#pragma asm
//  mov MD0, r7
//  mov MD1, r6
//  mov MD2, r5
//  mov MD3, r4

//	ANL  ARCON , #0xE0

//	nop    ;wait 34
//  nop
//  nop
//  nop
//  nop
//	nop    
//  nop
//  nop
//  nop
//  nop
//	nop    ;wait 24
//  nop
//  nop
//  nop
//  nop
//	nop    
//  nop
//  nop
//  nop
//  nop
//	nop    ;wait 14
//  nop
//  nop
//  nop
//  nop
//	nop    
//  nop
//  nop
//  nop
//  nop
//	nop    ;wait 4
//  nop
//  nop
//  nop
//#pragma endasm
//  _md_error = (ARCON&(MD_MDEF|MD_MDOV));
//#pragma asm
// 	mov r7, MD0
//	mov r6, MD1
//	mov r5, MD2
//	mov r4, MD3
//#pragma endasm
//return MD0;
//}
void Normalizing_Write(unsigned long Data)
{
 Long_Data LD;
 LD.Ldata =Data;
 MD0 = LD.ss1.Byte0;
 MD1 = LD.ss1.Byte1;
 MD2 = LD.ss1.Byte2;
 MD3 = LD.ss1.Byte3;
 ARCON = 0x00 ; // Start Normalizing
 while(!(PCON & 0x40)) //check MDU finish flag
 {};
}

void Normalizing_Read(void)
{ 
Long_Data LD;
 LD.ss1.Byte0 = MD0; //first read
 LD.ss1.Byte1 = MD1;
 LD.ss1.Byte2 = MD2;
 LD.ss1.Byte3 = MD3; //last read, MDEF(error flag) happen if not read
} 

void Normalizing_test(void)
{

 Normalizing_Write(0x00000001); //ANS=0x1F -->MDOV=0

 Normalizing_Read();

}