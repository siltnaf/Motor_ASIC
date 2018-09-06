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
#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__



#define uint8 unsigned char
#define uint16 unsigned int
#define uint32 unsigned long
#define int16 signed int



//typedef char S8;
//typedef int  S16;
//typedef long S32;
//typedef unsigned char U8;
//typedef unsigned int  U16;
//typedef unsigned long U32;
//typedef char* PS8;
//typedef int*  PS16;
//typedef long* PS32;
//typedef unsigned char* PU8;
//typedef unsigned int*  PU16;
//typedef unsigned long* PU32;


typedef union
{
	struct
	{
		unsigned char Byte3;
		unsigned char Byte2;
		unsigned char Byte1;
		unsigned char Byte0;
	}ss1;
	struct
	{
		unsigned int Word1;
		unsigned int Word0;
	}ss2;
	unsigned long Ldata;
}Long_Data;

#endif //_LIB_H_
