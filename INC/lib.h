/*
 * lib.h
 *	Copy Right (c) of Hong Kong Applied Science 
 *      and Technology Research Institute Company Limited
 *  Created on: 
 *      01 June 2016
 *  Author: 
 *      Lori Liu
 *  Last Modified: 
 *      12 August 2016 by Lori Liu
 *  Description: 
 *      lib header for JE8MCU
 *  History:
 *      ver 0.1 created by Lori Liu on 12 August 2016     
 */
#ifndef _LIB_H_
#define _LIB_H_

typedef char S8;
typedef int  S16;
typedef long S32;
typedef unsigned char U8;
typedef unsigned int  U16;
typedef unsigned long U32;
typedef char* PS8;
typedef int*  PS16;
typedef long* PS32;
typedef unsigned char* PU8;
typedef unsigned int*  PU16;
typedef unsigned long* PU32;

typedef union {
 struct {
 unsigned char Byte3; //MSB
 unsigned char Byte2;
 unsigned char Byte1;
 unsigned char Byte0; //LSB
 }ss1;
 struct {
 unsigned int Word1; //MSW
 unsigned int Word0; //LSW
 }ss2; 	
unsigned long Ldata;
}Long_Data;
//========================================================= 
	
	
	
	

#define  BSH_MODE_MASK         (0xE0)
#define  BSH_MODE_POSITION     (5)

#define  BSH_RR                (0x00)
#define  BSH_RRA               (0x20)
#define  BSH_RRC               (0x40)
#define  BSH_RL                (0x80)
#define  BSH_RLA               (0xA0)
#define  BSH_RLC               (0xC0)

#define  MD_RR                 (0x20)
#define  MD_RL                 (0x00)
#define  MD_MDEF               (0x80)
#define  MD_MDOV               (0x40)

extern volatile U8 xdata _md_error;
extern volatile U16 xdata _div_remainder;
extern volatile U16 xdata _div_denominator;

extern S32 BarrelShift(S32 in, S8 cmd);

extern S32 Div32(S32 numerator , S16 denominator);
extern S16 Div16(S16 numerator, S16 denominator);
extern S32 Shift32(S32 dat, U8 cmd);
extern S32 Normalize(S32 dat);
extern S32 Mul(S16 multiplicand, S16 multiplicator);

extern S32 UartPass(void);

#endif //_LIB_H_
