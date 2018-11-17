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




typedef  struct {
 unsigned char D3; //MSB
 unsigned char D2;
 unsigned char D1;
 unsigned char D0; //LSB
 } EE32;
 


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
	
	
#define pos  0
#define neg  1

#define sin_table 0x0000




extern S32 UartPass(void);

extern void EE_write(U8 EE_addr, U32 EE_data);
extern U32 EE_read(U8 EE_addr); 

//extern _iq (_IQsin(S16 dat));


#endif //_LIB_H_
