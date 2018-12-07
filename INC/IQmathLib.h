//*****************************************************************************
//
// IQmathLib.h - IQmath library C language function definitions.
//
// Copyright (c) 2010-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 9453 of the Stellaris IQmath Library.
//******************************************************************************
// math function in this library
//
//      _IQ(A)  				--> convert a fix point value to  IQ format
//      _IQmpy(A,B)  		--> multiply A and B
//      _IQdiv(A,B) 		--> divide A by B
//      _IQsin(A)       --> sin value of A (in degree)
//		  _IQcos(A)      	--> cos value of A
//      _IQinv(A)       --> compute 1/A
//      _IQatan(A)   		--> compute artan (A) return value in degree
//      _IQmag(A,B)     --> compute sqrt of A*A + B*B
//			_IQsqrt(A)      --> compute  sqrt of A
//
//
//
//*****************************************************************************

#ifndef __IQMATHLIB_H__
#define __IQMATHLIB_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// By redefining MATH_TYPE, all IQmath functions will be replaced by their
// floating point equivalents.
//
//*****************************************************************************
#define FLOAT_MATH              1
#define IQ_MATH                 0
#ifndef MATH_TYPE
#define MATH_TYPE               IQ_MATH
#endif

//*****************************************************************************
//
// The IQ format to be used when the IQ format is not explicitly specified
// (such as _IQcos instead of _IQ16cos).  This value must be between 1 and 30,
// inclusive.
//
//*****************************************************************************
#ifndef GLOBAL_Q
#define GLOBAL_Q                15
#define half_Q        					 GLOBAL_Q/2
#endif

//*****************************************************************************
//
// Include some standard headers, as required based on the math type.
//
//*****************************************************************************
#if MATH_TYPE == FLOAT_MATH
#include <math.h>
#endif
#include <limits.h>
#include <stdlib.h>



#define pos  0
#define neg  1


// table address

#define sin_table 		0x0000
#define inverse_table 0x0200		  
#define sqrt_table 		0x0400	
#define atan_table  	0x0600	





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






//*****************************************************************************
//
// Various Useful Constant Definitions:
//
//*****************************************************************************
#define Q30                     30
#define Q29                     29
#define Q28                     28
#define Q27                     27
#define Q26                     26
#define Q25                     25
#define Q24                     24
#define Q23                     23
#define Q22                     22
#define Q21                     21
#define Q20                     20
#define Q19                     19
#define Q18                     18
#define Q17                     17
#define Q16                     16
#define Q15                     15
#define Q14                     14
#define Q13                     13
#define Q12                     12
#define Q11                     11
#define Q10                     10
#define Q9                      9
#define Q8                      8
#define Q7                      7
#define Q6                      6
#define Q5                      5
#define Q4                      4
#define Q3                      3
#define Q2                      2
#define Q1                      1
#define QG                      GLOBAL_Q

#define MAX_IQ_POS              LONG_MAX
#define MAX_IQ_NEG              LONG_MIN
#define MIN_IQ_POS              1
#define MIN_IQ_NEG              -1





//*****************************************************************************
//
// See if IQmath or floating point is being used.
//
//*****************************************************************************
#if MATH_TYPE == IQ_MATH

//*****************************************************************************
//
// The types for the various IQ formats.
//
//*****************************************************************************
typedef long _iq30;
typedef long _iq29;
typedef long _iq28;
typedef long _iq27;
typedef long _iq26;
typedef long _iq25;
typedef long _iq24;
typedef long _iq23;
typedef long _iq22;
typedef long _iq21;
typedef long _iq20;
typedef long _iq19;
typedef long _iq18;
typedef long _iq17;
typedef long _iq16;
typedef long _iq15;
typedef long _iq14;
typedef long _iq13;
typedef long _iq12;
typedef long _iq11;
typedef long _iq10;
typedef long _iq9;
typedef long _iq8;
typedef long _iq7;
typedef long _iq6;
typedef long _iq5;
typedef long _iq4;
typedef long _iq3;
typedef long _iq2;
typedef long _iq1;
typedef long _iq;



//******************************
// variables used
//****************************


extern Long_Data data dat;
extern _iq data X,Y,Z;
extern S8  data index;
//********************************************************************
//  functions
//**************************************************

extern _iq Normalize(_iq A);
extern _iq BarrelShift(_iq A, U8 cmd);
extern _iq _IQabs(_iq A);


#define  RA_shift    32          //Right arthematic shift
#define  LA_shift    160         //left arthematic shift
#define  LL_shift    128         //left logic shift
#define  RL_shift     0          //right logic shift




//*****************************************************************************
//
// Simple multiplies or divides, which are accomplished with simple shifts.
//
//*****************************************************************************
#define _IQmpy2(A)              ((A) << 1)
#define _IQmpy4(A)              ((A) << 2)
#define _IQmpy8(A)              ((A) << 3)
#define _IQmpy16(A)             ((A) << 4)
#define _IQmpy32(A)             ((A) << 5)
#define _IQmpy64(A)             ((A) << 6)
#define _IQdiv2(A)              ((A) >> 1)
#define _IQdiv4(A)              ((A) >> 2)
#define _IQdiv8(A)              ((A) >> 3)
#define _IQdiv16(A)             ((A) >> 4)
#define _IQdiv32(A)             ((A) >> 5)
#define _IQdiv64(A)             ((A) >> 6)

//*****************************************************************************
//
// Convert a value into an IQ number.
//
//*****************************************************************************
#define _IQ30(A)                ((_iq30)((A) *0x400000000))
#define _IQ29(A)                ((_iq29)((A) *0x200000000 ))
#define _IQ28(A)                ((_iq28)((A) *0x100000000 ))
#define _IQ27(A)                ((_iq27)((A) *0x080000000))
#define _IQ26(A)                ((_iq26)((A) *0x040000000 ))
#define _IQ25(A)                ((_iq25)((A) *0x020000000 ))
#define _IQ24(A)                ((_iq24)((A) *0x010000000 ))
#define _IQ23(A)                ((_iq23)((A) *0x008000000))
#define _IQ22(A)                ((_iq22)((A) *0x004000000 ))
#define _IQ21(A)                ((_iq21)((A) *0x002000000))
#define _IQ20(A)                ((_iq20)((A) *0x001000000 ))
#define _IQ19(A)                ((_iq19)((A) *0x000800000))
#define _IQ18(A)                ((_iq18)((A) *0x00040000))
#define _IQ17(A)                ((_iq17)((A) *0x00020000))
#define _IQ16(A)                ((_iq16)((A) *0x00010000))
#define _IQ15(A)                ((_iq15)((A) *0x00008000))
#define _IQ14(A)                ((_iq14)((A) *0x00004000))
#define _IQ13(A)                ((_iq13)((A) *0x00002000))
#define _IQ12(A)                ((_iq12)((A) *0x00001000))
#define _IQ11(A)                ((_iq11)((A) *0x00000800))
#define _IQ10(A)                ((_iq10)((A) *0x00000400))
#define _IQ9(A)                 ((_iq9)((A) *0x00000200))
#define _IQ8(A)                 ((_iq8)((A) *0x00000100))
#define _IQ7(A)                 ((_iq7)((A) *0x00000080))
#define _IQ6(A)                 ((_iq6)((A) *0x00000040))
#define _IQ5(A)                 ((_iq5)((A) *0x00000020))
#define _IQ4(A)                 ((_iq4)((A) *0x00000010))
#define _IQ3(A)                 ((_iq3)((A) *0x00000008)
#define _IQ2(A)                 ((_iq2)((A) *0x00000004))
#define _IQ1(A)                 ((_iq1)((A) *0x00000002))

#if GLOBAL_Q == 30
#define _IQ(A)                  _IQ30(A)
#endif
#if GLOBAL_Q == 29
#define _IQ(A)                  _IQ29(A)
#endif
#if GLOBAL_Q == 28
#define _IQ(A)                  _IQ28(A)
#endif
#if GLOBAL_Q == 27
#define _IQ(A)                  _IQ27(A)
#endif
#if GLOBAL_Q == 26
#define _IQ(A)                  _IQ26(A)
#endif
#if GLOBAL_Q == 25
#define _IQ(A)                  _IQ25(A)
#endif
#if GLOBAL_Q == 24
#define _IQ(A)                  _IQ24(A)
#endif
#if GLOBAL_Q == 23
#define _IQ(A)                  _IQ23(A)
#endif
#if GLOBAL_Q == 22
#define _IQ(A)                  _IQ22(A)
#endif
#if GLOBAL_Q == 21
#define _IQ(A)                  _IQ21(A)
#endif
#if GLOBAL_Q == 20
#define _IQ(A)                  _IQ20(A)
#endif
#if GLOBAL_Q == 19
#define _IQ(A)                  _IQ19(A)
#endif
#if GLOBAL_Q == 18
#define _IQ(A)                  _IQ18(A)
#endif
#if GLOBAL_Q == 17
#define _IQ(A)                  _IQ17(A)
#endif
#if GLOBAL_Q == 16
#define _IQ(A)                  _IQ16(A)
#endif
#if GLOBAL_Q == 15
#define _IQ(A)                  _IQ15(A)
#endif
#if GLOBAL_Q == 14
#define _IQ(A)                  _IQ14(A)
#endif
#if GLOBAL_Q == 13
#define _IQ(A)                  _IQ13(A)
#endif
#if GLOBAL_Q == 12
#define _IQ(A)                  _IQ12(A)
#endif
#if GLOBAL_Q == 11
#define _IQ(A)                  _IQ11(A)
#endif
#if GLOBAL_Q == 10
#define _IQ(A)                  _IQ10(A)
#endif
#if GLOBAL_Q == 9
#define _IQ(A)                  _IQ9(A)
#endif
#if GLOBAL_Q == 8
#define _IQ(A)                  _IQ8(A)
#endif
#if GLOBAL_Q == 7
#define _IQ(A)                  _IQ7(A)
#endif
#if GLOBAL_Q == 6
#define _IQ(A)                  _IQ6(A)
#endif
#if GLOBAL_Q == 5
#define _IQ(A)                  _IQ5(A)
#endif
#if GLOBAL_Q == 4
#define _IQ(A)                  _IQ4(A)
#endif
#if GLOBAL_Q == 3
#define _IQ(A)                  _IQ3(A)
#endif
#if GLOBAL_Q == 2
#define _IQ(A)                  _IQ2(A)
#endif
#if GLOBAL_Q == 1
#define _IQ(A)                  _IQ1(A)
#endif


//*****************************************************************************
//
// Saturates an IQ number in a given range.
//
//*****************************************************************************
#define _IQsat(A, Pos, Neg)     (((A) > (Pos)) ?                              \
                                 (Pos) :                                      \
                                 (((A) < (Neg)) ? (Neg) : (A)))

//*****************************************************************************
//
// Converts an IQ number between the global IQ format and a specified IQ
// format.
//
//*****************************************************************************
#define _IQtoIQ30(A)            ((_iq30)(A) << (30 - GLOBAL_Q))
#define _IQ30toIQ(A)            ((_iq30)(A) >> (30 - GLOBAL_Q))

#if (GLOBAL_Q >= 29)
#define _IQtoIQ29(A)            ((_iq29)(A) >> (GLOBAL_Q - 29))
#define _IQ29toIQ(A)            ((_iq29)(A) << (GLOBAL_Q - 29))
#else
#define _IQtoIQ29(A)            ((_iq29)(A) << (29 - GLOBAL_Q))
#define _IQ29toIQ(A)            ((_iq29)(A) >> (29 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 28)
#define _IQtoIQ28(A)            ((_iq28)(A) >> (GLOBAL_Q - 28))
#define _IQ28toIQ(A)            ((_iq28)(A) << (GLOBAL_Q - 28))
#else
#define _IQtoIQ28(A)            ((_iq28)(A) << (28 - GLOBAL_Q))
#define _IQ28toIQ(A)            ((_iq28)(A) >> (28 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 27)
#define _IQtoIQ27(A)            ((_iq27)(A) >> (GLOBAL_Q - 27))
#define _IQ27toIQ(A)            ((_iq27)(A) << (GLOBAL_Q - 27))
#else
#define _IQtoIQ27(A)            ((_iq27)(A) << (27 - GLOBAL_Q))
#define _IQ27toIQ(A)            ((_iq27)(A) >> (27 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 26)
#define _IQtoIQ26(A)            ((_iq26)(A) >> (GLOBAL_Q - 26))
#define _IQ26toIQ(A)            ((_iq26)(A) << (GLOBAL_Q - 26))
#else
#define _IQtoIQ26(A)            ((_iq26)(A) << (26 - GLOBAL_Q))
#define _IQ26toIQ(A)            ((_iq26)(A) >> (26 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 25)
#define _IQtoIQ25(A)            ((_iq25)(A) >> (GLOBAL_Q - 25))
#define _IQ25toIQ(A)            ((_iq25)(A) << (GLOBAL_Q - 25))
#else
#define _IQtoIQ25(A)            ((_iq25)(A) << (25 - GLOBAL_Q))
#define _IQ25toIQ(A)            ((_iq25)(A) >> (25 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 24)
#define _IQtoIQ24(A)            ((_iq24)(A) >> (GLOBAL_Q - 24))
#define _IQ24toIQ(A)            ((_iq24)(A) << (GLOBAL_Q - 24))
#else
#define _IQtoIQ24(A)            ((_iq24)(A) << (24 - GLOBAL_Q))
#define _IQ24toIQ(A)            ((_iq24)(A) >> (24 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 23)
#define _IQtoIQ23(A)            ((_iq23)(A) >> (GLOBAL_Q - 23))
#define _IQ23toIQ(A)            ((_iq23)(A) << (GLOBAL_Q - 23))
#else
#define _IQtoIQ23(A)            ((_iq23)(A) << (23 - GLOBAL_Q))
#define _IQ23toIQ(A)            ((_iq23)(A) >> (23 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 22)
#define _IQtoIQ22(A)            ((_iq22)(A) >> (GLOBAL_Q - 22))
#define _IQ22toIQ(A)            ((_iq22)(A) << (GLOBAL_Q - 22))
#else
#define _IQtoIQ22(A)            ((_iq22)(A) << (22 - GLOBAL_Q))
#define _IQ22toIQ(A)            ((_iq22)(A) >> (22 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 21)
#define _IQtoIQ21(A)            ((_iq21)(A) >> (GLOBAL_Q - 21))
#define _IQ21toIQ(A)            ((_iq21)(A) << (GLOBAL_Q - 21))
#else
#define _IQtoIQ21(A)            ((_iq21)(A) << (21 - GLOBAL_Q))
#define _IQ21toIQ(A)            ((_iq21)(A) >> (21 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 20)
#define _IQtoIQ20(A)            ((_iq20)(A) >> (GLOBAL_Q - 20))
#define _IQ20toIQ(A)            ((_iq20)(A) << (GLOBAL_Q - 20))
#else
#define _IQtoIQ20(A)            ((_iq20)(A) << (20 - GLOBAL_Q))
#define _IQ20toIQ(A)            ((_iq20)(A) >> (20 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 19)
#define _IQtoIQ19(A)            ((_iq19)(A) >> (GLOBAL_Q - 19))
#define _IQ19toIQ(A)            ((_iq19)(A) << (GLOBAL_Q - 19))
#else
#define _IQtoIQ19(A)            ((_iq19)(A) << (19 - GLOBAL_Q))
#define _IQ19toIQ(A)            ((_iq19)(A) >> (19 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 18)
#define _IQtoIQ18(A)            ((_iq18)(A) >> (GLOBAL_Q - 18))
#define _IQ18toIQ(A)            ((_iq18)(A) << (GLOBAL_Q - 18))
#else
#define _IQtoIQ18(A)            ((_iq18)(A) << (18 - GLOBAL_Q))
#define _IQ18toIQ(A)            ((_iq18)(A) >> (18 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 17)
#define _IQtoIQ17(A)            ((_iq17)(A) >> (GLOBAL_Q - 17))
#define _IQ17toIQ(A)            ((_iq17)(A) << (GLOBAL_Q - 17))
#else
#define _IQtoIQ17(A)            ((_iq17)(A) << (17 - GLOBAL_Q))
#define _IQ17toIQ(A)            ((_iq17)(A) >> (17 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 16)
#define _IQtoIQ16(A)            ((_iq16)(A) >> (GLOBAL_Q - 16))
#define _IQ16toIQ(A)            ((_iq16)(A) << (GLOBAL_Q - 16))
#else
#define _IQtoIQ16(A)            ((_iq16)(A) << (16 - GLOBAL_Q))
#define _IQ16toIQ(A)            ((_iq16)(A) >> (16 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 15)
#define _IQtoIQ15(A)            ((_iq15)(A) >> (GLOBAL_Q - 15))
#define _IQ15toIQ(A)            ((_iq15)(A) << (GLOBAL_Q - 15))
#else
#define _IQtoIQ15(A)            ((_iq15)(A) << (15 - GLOBAL_Q))
#define _IQ15toIQ(A)            ((_iq15)(A) >> (15 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 14)
#define _IQtoIQ14(A)            ((_iq14)(A) >> (GLOBAL_Q - 14))
#define _IQ14toIQ(A)            ((_iq14)(A) << (GLOBAL_Q - 14))
#else
#define _IQtoIQ14(A)            ((_iq14)(A) << (14 - GLOBAL_Q))
#define _IQ14toIQ(A)            ((_iq14)(A) >> (14 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 13)
#define _IQtoIQ13(A)            ((_iq13)(A) >> (GLOBAL_Q - 13))
#define _IQ13toIQ(A)            ((_iq13)(A) << (GLOBAL_Q - 13))
#else
#define _IQtoIQ13(A)            ((_iq13)(A) << (13 - GLOBAL_Q))
#define _IQ13toIQ(A)            ((_iq13)(A) >> (13 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 12)
#define _IQtoIQ12(A)            ((_iq12)(A) >> (GLOBAL_Q - 12))
#define _IQ12toIQ(A)            ((_iq12)(A) << (GLOBAL_Q - 12))
#else
#define _IQtoIQ12(A)            ((_iq12)(A) << (12 - GLOBAL_Q))
#define _IQ12toIQ(A)            ((_iq12)(A) >> (12 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 11)
#define _IQtoIQ11(A)            ((_iq11)(A) >> (GLOBAL_Q - 11))
#define _IQ11toIQ(A)            ((_iq11)(A) << (GLOBAL_Q - 11))
#else
#define _IQtoIQ11(A)            ((_iq11)(A) << (11 - GLOBAL_Q))
#define _IQ11toIQ(A)            ((_iq11)(A) >> (11 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 10)
#define _IQtoIQ10(A)            ((_iq10)(A) >> (GLOBAL_Q - 10))
#define _IQ10toIQ(A)            ((_iq10)(A) << (GLOBAL_Q - 10))
#else
#define _IQtoIQ10(A)            ((_iq10)(A) << (10 - GLOBAL_Q))
#define _IQ10toIQ(A)            ((_iq10)(A) >> (10 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 9)
#define _IQtoIQ9(A)             ((_iq9)(A) >> (GLOBAL_Q - 9))
#define _IQ9toIQ(A)             ((_iq9)(A) << (GLOBAL_Q - 9))
#else
#define _IQtoIQ9(A)             ((_iq9)(A) << (9 - GLOBAL_Q))
#define _IQ9toIQ(A)             ((_iq9)(A) >> (9 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 8)
#define _IQtoIQ8(A)             ((_iq8)(A) >> (GLOBAL_Q - 8))
#define _IQ8toIQ(A)             ((_iq8)(A) << (GLOBAL_Q - 8))
#else
#define _IQtoIQ8(A)             ((_iq8)(A) << (8 - GLOBAL_Q))
#define _IQ8toIQ(A)             ((_iq8)(A) >> (8 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 7)
#define _IQtoIQ7(A)             ((_iq7)(A) >> (GLOBAL_Q - 7))
#define _IQ7toIQ(A)             ((_iq7)(A) << (GLOBAL_Q - 7))
#else
#define _IQtoIQ7(A)             ((_iq7)(A) << (7 - GLOBAL_Q))
#define _IQ7toIQ(A)             ((_iq7)(A) >> (7 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 6)
#define _IQtoIQ6(A)             ((_iq6)(A) >> (GLOBAL_Q - 6))
#define _IQ6toIQ(A)             ((_iq6)(A) << (GLOBAL_Q - 6))
#else
#define _IQtoIQ6(A)             ((_iq6)(A) << (6 - GLOBAL_Q))
#define _IQ6toIQ(A)             ((_iq6)(A) >> (6 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 5)
#define _IQtoIQ5(A)             ((_iq5)(A) >> (GLOBAL_Q - 5))
#define _IQ5toIQ(A)             ((_iq5)(A) << (GLOBAL_Q - 5))
#else
#define _IQtoIQ5(A)             ((_iq5)(A) << (5 - GLOBAL_Q))
#define _IQ5toIQ(A)             ((_iq5)(A) >> (5 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 4)
#define _IQtoIQ4(A)             ((_iq4)(A) >> (GLOBAL_Q - 4))
#define _IQ4toIQ(A)             ((_iq4)(A) << (GLOBAL_Q - 4))
#else
#define _IQtoIQ4(A)             ((_iq4)(A) << (4 - GLOBAL_Q))
#define _IQ4toIQ(A)             ((_iq4)(A) >> (4 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 3)
#define _IQtoIQ3(A)             ((_iq3)(A) >> (GLOBAL_Q - 3))
#define _IQ3toIQ(A)             ((_iq3)(A) << (GLOBAL_Q - 3))
#else
#define _IQtoIQ3(A)             ((_iq3)(A) << (3 - GLOBAL_Q))
#define _IQ3toIQ(A)             ((_iq3)(A) >> (3 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 2)
#define _IQtoIQ2(A)             ((_iq2)(A) >> (GLOBAL_Q - 2))
#define _IQ2toIQ(A)             ((_iq2)(A) << (GLOBAL_Q - 2))
#else
#define _IQtoIQ2(A)             ((_iq2)(A) << (2 - GLOBAL_Q))
#define _IQ2toIQ(A)             ((_iq2)(A) >> (2 - GLOBAL_Q))
#endif

#define _IQtoIQ1(A)             ((_iq1)(A) >> (GLOBAL_Q - 1))
#define _IQ1toIQ(A)             ((_iq1)(A) << (GLOBAL_Q - 1))

//*****************************************************************************
//
// Converts a number between IQ format and 16-bit Qn format.
//
//*****************************************************************************
#if (GLOBAL_Q >= 15)
#define _IQtoQ15(A)             ((long)(A) >> (GLOBAL_Q - 15))
#define _Q15toIQ(A)             ((_iq15)(A) << (GLOBAL_Q - 15))
#else
#define _IQtoQ15(A)             ((long)(A) << (15 - GLOBAL_Q))
#define _Q15toIQ(A)             ((_iq15)(A) >> (15 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 14)
#define _IQtoQ14(A)             ((long)(A) >> (GLOBAL_Q - 14))
#define _Q14toIQ(A)             ((_iq14)(A) << (GLOBAL_Q - 14))
#else
#define _IQtoQ14(A)             ((long)(A) << (14 - GLOBAL_Q))
#define _Q14toIQ(A)             ((_iq14)(A) >> (14 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 13)
#define _IQtoQ13(A)             ((long)(A) >> (GLOBAL_Q - 13))
#define _Q13toIQ(A)             ((_iq13)(A) << (GLOBAL_Q - 13))
#else
#define _IQtoQ13(A)             ((long)(A) << (13 - GLOBAL_Q))
#define _Q13toIQ(A)             ((_iq13)(A) >> (13 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 12)
#define _IQtoQ12(A)             ((long)(A) >> (GLOBAL_Q - 12))
#define _Q12toIQ(A)             ((_iq12)(A) << (GLOBAL_Q - 12))
#else
#define _IQtoQ12(A)             ((long)(A) << (12 - GLOBAL_Q))
#define _Q12toIQ(A)             ((_iq12)(A) >> (12 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 11)
#define _IQtoQ11(A)             ((long)(A) >> (GLOBAL_Q - 11))
#define _Q11toIQ(A)             ((_iq11)(A) << (GLOBAL_Q - 11))
#else
#define _IQtoQ11(A)             ((long)(A) << (11 - GLOBAL_Q))
#define _Q11toIQ(A)             ((_iq11)(A) >> (11 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 10)
#define _IQtoQ10(A)             ((long)(A) >> (GLOBAL_Q - 10))
#define _Q10toIQ(A)             ((_iq10)(A) << (GLOBAL_Q - 10))
#else
#define _IQtoQ10(A)             ((long)(A) << (10 - GLOBAL_Q))
#define _Q10toIQ(A)             ((_iq10)(A) >> (10 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 9)
#define _IQtoQ9(A)              ((long)(A) >> (GLOBAL_Q - 9))
#define _Q9toIQ(A)              ((_iq9)(A) << (GLOBAL_Q - 9))
#else
#define _IQtoQ9(A)              ((long)(A) << (9 - GLOBAL_Q))
#define _Q9toIQ(A)              ((_iq9)(A) >> (9 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 8)
#define _IQtoQ8(A)              ((long)(A) >> (GLOBAL_Q - 8))
#define _Q8toIQ(A)              ((_iq8)(A) << (GLOBAL_Q - 8))
#else
#define _IQtoQ8(A)              ((long)(A) << (8 - GLOBAL_Q))
#define _Q8toIQ(A)              ((_iq8)(A) >> (8 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 7)
#define _IQtoQ7(A)              ((long)(A) >> (GLOBAL_Q - 7))
#define _Q7toIQ(A)              ((_iq7)(A) << (GLOBAL_Q - 7))
#else
#define _IQtoQ7(A)              ((long)(A) << (7 - GLOBAL_Q))
#define _Q7toIQ(A)              ((_iq7)(A) >> (7 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 6)
#define _IQtoQ6(A)              ((long)(A) >> (GLOBAL_Q - 6))
#define _Q6toIQ(A)              ((_iq6)(A) << (GLOBAL_Q - 6))
#else
#define _IQtoQ6(A)              ((long)(A) << (6 - GLOBAL_Q))
#define _Q6toIQ(A)              ((_iq6)(A) >> (6 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 5)
#define _IQtoQ5(A)              ((long)(A) >> (GLOBAL_Q - 5))
#define _Q5toIQ(A)              ((_iq5)(A) << (GLOBAL_Q - 5))
#else
#define _IQtoQ5(A)              ((long)(A) << (5 - GLOBAL_Q))
#define _Q5toIQ(A)              ((_iq5)(A) >> (5 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 4)
#define _IQtoQ4(A)              ((long)(A) >> (GLOBAL_Q - 4))
#define _Q4toIQ(A)              ((_iq4)(A) << (GLOBAL_Q - 4))
#else
#define _IQtoQ4(A)              ((long)(A) << (4 - GLOBAL_Q))
#define _Q4toIQ(A)              ((_iq4)(A) >> (4 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 3)
#define _IQtoQ3(A)              ((long)(A) >> (GLOBAL_Q - 3))
#define _Q3toIQ(A)              ((_iq3)(A) << (GLOBAL_Q - 3))
#else
#define _IQtoQ3(A)              ((long)(A) << (3 - GLOBAL_Q))
#define _Q3toIQ(A)              ((_iq3)(A) >> (3 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 2)
#define _IQtoQ2(A)              ((long)(A) >> (GLOBAL_Q - 2))
#define _Q2toIQ(A)              ((_iq2)(A) << (GLOBAL_Q - 2))
#else
#define _IQtoQ2(A)              ((long)(A) << (2 - GLOBAL_Q))
#define _Q2toIQ(A)              ((_iq2)(A) >> (2 - GLOBAL_Q))
#endif

#define _IQtoQ1(A)              ((long)(A) >> (GLOBAL_Q - 1))
#define _Q1toIQ(A)              ((_iq1)(A) << (GLOBAL_Q - 1))



//*****************************************************************************
//
// Divides two IQ numbers.
//
//***************************************************************************
#define _IQdiv(A, B)           BarrelShift((A), (LA_shift+ half_Q))/ BarrelShift((A), (RA_shift+GLOBAL_Q-half_Q))


//*****************************************************************************
//
// Multiplies two IQ numbers.
//
//*****************************************************************************





#if (GLOBAL_Q %2)== 0
#define _IQmpy(A , B)           BarrelShift((A), (RA_shift+ half_Q))* BarrelShift((B), (RA_shift+ half_Q))
#else
#define _IQmpy(A, B)            BarrelShift((A), (RA_shift+ half_Q))* BarrelShift((B), (RA_shift+ half_Q+1))
#endif




//*****************************************************************************
//
// Computes the sin of an IQ number.
//
//*****************************************************************************
extern _iq29 _IQ29sin(_iq29 A);
extern _iq28 _IQ28sin(_iq28 A);
extern _iq27 _IQ27sin(_iq27 A);
extern _iq26 _IQ26sin(_iq26 A);
extern _iq25 _IQ25sin(_iq25 A);
extern _iq24 _IQ24sin(_iq24 A);
extern _iq23 _IQ23sin(_iq23 A);
extern _iq22 _IQ22sin(_iq22 A);
extern _iq21 _IQ21sin(_iq21 A);
extern _iq20 _IQ20sin(_iq20 A);
extern _iq19 _IQ19sin(_iq19 A);
extern _iq18 _IQ18sin(_iq18 A);
extern _iq17 _IQ17sin(_iq17 A);
extern _iq16 _IQ16sin(_iq16 A);
extern _iq15 _IQ15sin(_iq15 A);
extern _iq14 _IQ14sin(_iq14 A);
extern _iq13 _IQ13sin(_iq13 A);
extern _iq12 _IQ12sin(_iq12 A);
extern _iq11 _IQ11sin(_iq11 A);
extern _iq10 _IQ10sin(_iq10 A);
extern _iq9 _IQ9sin(_iq9 A);
extern _iq8 _IQ8sin(_iq8 A);
extern _iq7 _IQ7sin(_iq7 A);
extern _iq6 _IQ6sin(_iq6 A);
extern _iq5 _IQ5sin(_iq5 A);
extern _iq4 _IQ4sin(_iq4 A);
extern _iq3 _IQ3sin(_iq3 A);
extern _iq2 _IQ2sin(_iq2 A);
extern _iq1 _IQ1sin(_iq1 A);





#if GLOBAL_Q == 29
#define _IQsin(A)               _IQ29sin(A)
#endif
#if GLOBAL_Q == 28
#define _IQsin(A)               _IQ28sin(A)
#endif
#if GLOBAL_Q == 27
#define _IQsin(A)               _IQ27sin(A)
#endif
#if GLOBAL_Q == 26
#define _IQsin(A)               _IQ26sin(A)
#endif
#if GLOBAL_Q == 25
#define _IQsin(A)               _IQ25sin(A)
#endif
#if GLOBAL_Q == 24
#define _IQsin(A)               _IQ24sin(A)
#endif
#if GLOBAL_Q == 23
#define _IQsin(A)               _IQ23sin(A)
#endif
#if GLOBAL_Q == 22
#define _IQsin(A)               _IQ22sin(A)
#endif
#if GLOBAL_Q == 21
#define _IQsin(A)               _IQ21sin(A)
#endif
#if GLOBAL_Q == 20
#define _IQsin(A)               _IQ20sin(A)
#endif
#if GLOBAL_Q == 19
#define _IQsin(A)               _IQ19sin(A)
#endif
#if GLOBAL_Q == 18
#define _IQsin(A)               _IQ18sin(A)
#endif
#if GLOBAL_Q == 17
#define _IQsin(A)               _IQ17sin(A)
#endif
#if GLOBAL_Q == 16
#define _IQsin(A)               _IQ16sin(A)
#endif
#if GLOBAL_Q == 15
#define _IQsin(A)               _IQ15sin(A)
#endif
#if GLOBAL_Q == 14
#define _IQsin(A)               _IQ14sin(A)
#endif
#if GLOBAL_Q == 13
#define _IQsin(A)               _IQ13sin(A)
#endif
#if GLOBAL_Q == 12
#define _IQsin(A)               _IQ12sin(A)
#endif
#if GLOBAL_Q == 11
#define _IQsin(A)               _IQ11sin(A)
#endif
#if GLOBAL_Q == 10
#define _IQsin(A)               _IQ10sin(A)
#endif
#if GLOBAL_Q == 9
#define _IQsin(A)               _IQ9sin(A)
#endif
#if GLOBAL_Q == 8
#define _IQsin(A)               _IQ8sin(A)
#endif
#if GLOBAL_Q == 7
#define _IQsin(A)               _IQ7sin(A)
#endif
#if GLOBAL_Q == 6
#define _IQsin(A)               _IQ6sin(A)
#endif
#if GLOBAL_Q == 5
#define _IQsin(A)               _IQ5sin(A)
#endif
#if GLOBAL_Q == 4
#define _IQsin(A)               _IQ4sin(A)
#endif
#if GLOBAL_Q == 3
#define _IQsin(A)               _IQ3sin(A)
#endif
#if GLOBAL_Q == 2
#define _IQsin(A)               _IQ2sin(A)
#endif
#if GLOBAL_Q == 1
#define _IQsin(A)               _IQ1sin(A)
#endif



//*****************************************************************************
//
// Computes the inverse of an IQ number.
//
//*****************************************************************************

#define  _IQinv(A)    _IQdiv(_IQ(1.0),A)


//*****************************************************************************
//
// Computes the cos of an IQ number.
//
//*****************************************************************************

#define _IQcos(A)    _IQsin((A)+_IQ(90.0))


//*****************************************************************************
//
// Computes the arctan of a coordinate specified by two IQ numbers.
//
//*****************************************************************************
extern _iq29 _IQ29atan2(_iq29 A, _iq29 B);
extern _iq28 _IQ28atan2(_iq28 A, _iq28 B);
extern _iq27 _IQ27atan2(_iq27 A, _iq27 B);
extern _iq26 _IQ26atan2(_iq26 A, _iq26 B);
extern _iq25 _IQ25atan2(_iq25 A, _iq25 B);
extern _iq24 _IQ24atan2(_iq24 A, _iq24 B);
extern _iq23 _IQ23atan2(_iq23 A, _iq23 B);
extern _iq22 _IQ22atan2(_iq22 A, _iq22 B);
extern _iq21 _IQ21atan2(_iq21 A, _iq21 B);
extern _iq20 _IQ20atan2(_iq20 A, _iq20 B);
extern _iq19 _IQ19atan2(_iq19 A, _iq19 B);
extern _iq18 _IQ18atan2(_iq18 A, _iq18 B);
extern _iq17 _IQ17atan2(_iq17 A, _iq17 B);
extern _iq16 _IQ16atan2(_iq16 A, _iq16 B);
extern _iq15 _IQ15atan2(_iq15 A, _iq15 B);
extern _iq14 _IQ14atan2(_iq14 A, _iq14 B);
extern _iq13 _IQ13atan2(_iq13 A, _iq13 B);
extern _iq12 _IQ12atan2(_iq12 A, _iq12 B);
extern _iq11 _IQ11atan2(_iq11 A, _iq11 B);
extern _iq10 _IQ10atan2(_iq10 A, _iq10 B);
extern _iq9 _IQ9atan2(_iq9 A, _iq9 B);
extern _iq8 _IQ8atan2(_iq8 A, _iq8 B);
extern _iq7 _IQ7atan2(_iq7 A, _iq7 B);
extern _iq6 _IQ6atan2(_iq6 A, _iq6 B);
extern _iq5 _IQ5atan2(_iq5 A, _iq5 B);
extern _iq4 _IQ4atan2(_iq4 A, _iq4 B);
extern _iq3 _IQ3atan2(_iq3 A, _iq3 B);
extern _iq2 _IQ2atan2(_iq2 A, _iq2 B);
extern _iq1 _IQ1atan2(_iq1 A, _iq1 B);

#if GLOBAL_Q == 29
#define _IQatan2(A, B)          _IQ29atan2(A, B)
#endif
#if GLOBAL_Q == 28
#define _IQatan2(A, B)          _IQ28atan2(A, B)
#endif
#if GLOBAL_Q == 27
#define _IQatan2(A, B)          _IQ27atan2(A, B)
#endif
#if GLOBAL_Q == 26
#define _IQatan2(A, B)          _IQ26atan2(A, B)
#endif
#if GLOBAL_Q == 25
#define _IQatan2(A, B)          _IQ25atan2(A, B)
#endif
#if GLOBAL_Q == 24
#define _IQatan2(A, B)          _IQ24atan2(A, B)
#endif
#if GLOBAL_Q == 23
#define _IQatan2(A, B)          _IQ23atan2(A, B)
#endif
#if GLOBAL_Q == 22
#define _IQatan2(A, B)          _IQ22atan2(A, B)
#endif
#if GLOBAL_Q == 21
#define _IQatan2(A, B)          _IQ21atan2(A, B)
#endif
#if GLOBAL_Q == 20
#define _IQatan2(A, B)          _IQ20atan2(A, B)
#endif
#if GLOBAL_Q == 19
#define _IQatan2(A, B)          _IQ19atan2(A, B)
#endif
#if GLOBAL_Q == 18
#define _IQatan2(A, B)          _IQ18atan2(A, B)
#endif
#if GLOBAL_Q == 17
#define _IQatan2(A, B)          _IQ17atan2(A, B)
#endif
#if GLOBAL_Q == 16
#define _IQatan2(A, B)          _IQ16atan2(A, B)
#endif
#if GLOBAL_Q == 15
#define _IQatan2(A, B)          _IQ15atan2(A, B)
#endif
#if GLOBAL_Q == 14
#define _IQatan2(A, B)          _IQ14atan2(A, B)
#endif
#if GLOBAL_Q == 13
#define _IQatan2(A, B)          _IQ13atan2(A, B)
#endif
#if GLOBAL_Q == 12
#define _IQatan2(A, B)          _IQ12atan2(A, B)
#endif
#if GLOBAL_Q == 11
#define _IQatan2(A, B)          _IQ11atan2(A, B)
#endif
#if GLOBAL_Q == 10
#define _IQatan2(A, B)          _IQ10atan2(A, B)
#endif
#if GLOBAL_Q == 9
#define _IQatan2(A, B)          _IQ9atan2(A, B)
#endif
#if GLOBAL_Q == 8
#define _IQatan2(A, B)          _IQ8atan2(A, B)
#endif
#if GLOBAL_Q == 7
#define _IQatan2(A, B)          _IQ7atan2(A, B)
#endif
#if GLOBAL_Q == 6
#define _IQatan2(A, B)          _IQ6atan2(A, B)
#endif
#if GLOBAL_Q == 5
#define _IQatan2(A, B)          _IQ5atan2(A, B)
#endif
#if GLOBAL_Q == 4
#define _IQatan2(A, B)          _IQ4atan2(A, B)
#endif
#if GLOBAL_Q == 3
#define _IQatan2(A, B)          _IQ3atan2(A, B)
#endif
#if GLOBAL_Q == 2
#define _IQatan2(A, B)          _IQ2atan2(A, B)
#endif
#if GLOBAL_Q == 1
#define _IQatan2(A, B)          _IQ1atan2(A, B)
#endif


//*****************************************************************************
//
// Computes the arctan of an IQ number.
//
//*****************************************************************************
#define _IQ29atan(A)            _IQ29atan2(A, _IQ29(1.0))
#define _IQ28atan(A)            _IQ28atan2(A, _IQ28(1.0))
#define _IQ27atan(A)            _IQ27atan2(A, _IQ27(1.0))
#define _IQ26atan(A)            _IQ26atan2(A, _IQ26(1.0))
#define _IQ25atan(A)            _IQ25atan2(A, _IQ25(1.0))
#define _IQ24atan(A)            _IQ24atan2(A, _IQ24(1.0))
#define _IQ23atan(A)            _IQ23atan2(A, _IQ23(1.0))
#define _IQ22atan(A)            _IQ22atan2(A, _IQ22(1.0))
#define _IQ21atan(A)            _IQ21atan2(A, _IQ21(1.0))
#define _IQ20atan(A)            _IQ20atan2(A, _IQ20(1.0))
#define _IQ19atan(A)            _IQ19atan2(A, _IQ19(1.0))
#define _IQ18atan(A)            _IQ18atan2(A, _IQ18(1.0))
#define _IQ17atan(A)            _IQ17atan2(A, _IQ17(1.0))
#define _IQ16atan(A)            _IQ16atan2(A, _IQ16(1.0))
#define _IQ15atan(A)            _IQ15atan2(A, _IQ15(1.0))
#define _IQ14atan(A)            _IQ14atan2(A, _IQ14(1.0))
#define _IQ13atan(A)            _IQ13atan2(A, _IQ13(1.0))
#define _IQ12atan(A)            _IQ12atan2(A, _IQ12(1.0))
#define _IQ11atan(A)            _IQ11atan2(A, _IQ11(1.0))
#define _IQ10atan(A)            _IQ10atan2(A, _IQ10(1.0))
#define _IQ9atan(A)             _IQ9atan2(A, _IQ9(1.0))
#define _IQ8atan(A)             _IQ8atan2(A, _IQ8(1.0))
#define _IQ7atan(A)             _IQ7atan2(A, _IQ7(1.0))
#define _IQ6atan(A)             _IQ6atan2(A, _IQ6(1.0))
#define _IQ5atan(A)             _IQ5atan2(A, _IQ5(1.0))
#define _IQ4atan(A)             _IQ4atan2(A, _IQ4(1.0))
#define _IQ3atan(A)             _IQ3atan2(A, _IQ3(1.0))
#define _IQ2atan(A)             _IQ2atan2(A, _IQ2(1.0))
#define _IQ1atan(A)             _IQ1atan2(A, _IQ1(1.0))

#if GLOBAL_Q == 29
#define _IQatan(A)              _IQ29atan2(A, _IQ29(1.0))
#endif
#if GLOBAL_Q == 28
#define _IQatan(A)              _IQ28atan2(A, _IQ28(1.0))
#endif
#if GLOBAL_Q == 27
#define _IQatan(A)              _IQ27atan2(A, _IQ27(1.0))
#endif
#if GLOBAL_Q == 26
#define _IQatan(A)              _IQ26atan2(A, _IQ26(1.0))
#endif
#if GLOBAL_Q == 25
#define _IQatan(A)              _IQ25atan2(A, _IQ25(1.0))
#endif
#if GLOBAL_Q == 24
#define _IQatan(A)              _IQ24atan2(A, _IQ24(1.0))
#endif
#if GLOBAL_Q == 23
#define _IQatan(A)              _IQ23atan2(A, _IQ23(1.0))
#endif
#if GLOBAL_Q == 22
#define _IQatan(A)              _IQ22atan2(A, _IQ22(1.0))
#endif
#if GLOBAL_Q == 21
#define _IQatan(A)              _IQ21atan2(A, _IQ21(1.0))
#endif
#if GLOBAL_Q == 20
#define _IQatan(A)              _IQ20atan2(A, _IQ20(1.0))
#endif
#if GLOBAL_Q == 19
#define _IQatan(A)              _IQ19atan2(A, _IQ19(1.0))
#endif
#if GLOBAL_Q == 18
#define _IQatan(A)              _IQ18atan2(A, _IQ18(1.0))
#endif
#if GLOBAL_Q == 17
#define _IQatan(A)              _IQ17atan2(A, _IQ17(1.0))
#endif
#if GLOBAL_Q == 16
#define _IQatan(A)              _IQ16atan2(A, _IQ16(1.0))
#endif
#if GLOBAL_Q == 15
#define _IQatan(A)              _IQ15atan2(A, _IQ15(1.0))
#endif
#if GLOBAL_Q == 14
#define _IQatan(A)              _IQ14atan2(A, _IQ14(1.0))
#endif
#if GLOBAL_Q == 13
#define _IQatan(A)              _IQ13atan2(A, _IQ13(1.0))
#endif
#if GLOBAL_Q == 12
#define _IQatan(A)              _IQ12atan2(A, _IQ12(1.0))
#endif
#if GLOBAL_Q == 11
#define _IQatan(A)              _IQ11atan2(A, _IQ11(1.0))
#endif
#if GLOBAL_Q == 10
#define _IQatan(A)              _IQ10atan2(A, _IQ10(1.0))
#endif
#if GLOBAL_Q == 9
#define _IQatan(A)              _IQ9atan2(A, _IQ9(1.0))
#endif
#if GLOBAL_Q == 8
#define _IQatan(A)              _IQ8atan2(A, _IQ8(1.0))
#endif
#if GLOBAL_Q == 7
#define _IQatan(A)              _IQ7atan2(A, _IQ7(1.0))
#endif
#if GLOBAL_Q == 6
#define _IQatan(A)              _IQ6atan2(A, _IQ6(1.0))
#endif
#if GLOBAL_Q == 5
#define _IQatan(A)              _IQ5atan2(A, _IQ5(1.0))
#endif
#if GLOBAL_Q == 4
#define _IQatan(A)              _IQ4atan2(A, _IQ4(1.0))
#endif
#if GLOBAL_Q == 3
#define _IQatan(A)              _IQ3atan2(A, _IQ3(1.0))
#endif
#if GLOBAL_Q == 2
#define _IQatan(A)              _IQ2atan2(A, _IQ2(1.0))
#endif
#if GLOBAL_Q == 1
#define _IQatan(A)              _IQ1atan2(A, _IQ1(1.0))
#endif

//*****************************************************************************
//
// Computes the square root of an IQ number.
//
//*****************************************************************************
extern _iq30 _IQ30sqrt(_iq30 A);
extern _iq29 _IQ29sqrt(_iq29 A);
extern _iq28 _IQ28sqrt(_iq28 A);
extern _iq27 _IQ27sqrt(_iq27 A);
extern _iq26 _IQ26sqrt(_iq26 A);
extern _iq25 _IQ25sqrt(_iq25 A);
extern _iq24 _IQ24sqrt(_iq24 A);
extern _iq23 _IQ23sqrt(_iq23 A);
extern _iq22 _IQ22sqrt(_iq22 A);
extern _iq21 _IQ21sqrt(_iq21 A);
extern _iq20 _IQ20sqrt(_iq20 A);
extern _iq19 _IQ19sqrt(_iq19 A);
extern _iq18 _IQ18sqrt(_iq18 A);
extern _iq17 _IQ17sqrt(_iq17 A);
extern _iq16 _IQ16sqrt(_iq16 A);
extern _iq15 _IQ15sqrt(_iq15 A);
extern _iq14 _IQ14sqrt(_iq14 A);
extern _iq13 _IQ13sqrt(_iq13 A);
extern _iq12 _IQ12sqrt(_iq12 A);
extern _iq11 _IQ11sqrt(_iq11 A);
extern _iq10 _IQ10sqrt(_iq10 A);
extern _iq9 _IQ9sqrt(_iq9 A);
extern _iq8 _IQ8sqrt(_iq8 A);
extern _iq7 _IQ7sqrt(_iq7 A);
extern _iq6 _IQ6sqrt(_iq6 A);
extern _iq5 _IQ5sqrt(_iq5 A);
extern _iq4 _IQ4sqrt(_iq4 A);
extern _iq3 _IQ3sqrt(_iq3 A);
extern _iq2 _IQ2sqrt(_iq2 A);
extern _iq1 _IQ1sqrt(_iq1 A);

#if GLOBAL_Q == 30
#define _IQsqrt(A)              _IQ30sqrt(A)
#endif
#if GLOBAL_Q == 29
#define _IQsqrt(A)              _IQ29sqrt(A)
#endif
#if GLOBAL_Q == 28
#define _IQsqrt(A)              _IQ28sqrt(A)
#endif
#if GLOBAL_Q == 27
#define _IQsqrt(A)              _IQ27sqrt(A)
#endif
#if GLOBAL_Q == 26
#define _IQsqrt(A)              _IQ26sqrt(A)
#endif
#if GLOBAL_Q == 25
#define _IQsqrt(A)              _IQ25sqrt(A)
#endif
#if GLOBAL_Q == 24
#define _IQsqrt(A)              _IQ24sqrt(A)
#endif
#if GLOBAL_Q == 23
#define _IQsqrt(A)              _IQ23sqrt(A)
#endif
#if GLOBAL_Q == 22
#define _IQsqrt(A)              _IQ22sqrt(A)
#endif
#if GLOBAL_Q == 21
#define _IQsqrt(A)              _IQ21sqrt(A)
#endif
#if GLOBAL_Q == 20
#define _IQsqrt(A)              _IQ20sqrt(A)
#endif
#if GLOBAL_Q == 19
#define _IQsqrt(A)              _IQ19sqrt(A)
#endif
#if GLOBAL_Q == 18
#define _IQsqrt(A)              _IQ18sqrt(A)
#endif
#if GLOBAL_Q == 17
#define _IQsqrt(A)              _IQ17sqrt(A)
#endif
#if GLOBAL_Q == 16
#define _IQsqrt(A)              _IQ16sqrt(A)
#endif
#if GLOBAL_Q == 15
#define _IQsqrt(A)              _IQ15sqrt(A)
#endif
#if GLOBAL_Q == 14
#define _IQsqrt(A)              _IQ14sqrt(A)
#endif
#if GLOBAL_Q == 13
#define _IQsqrt(A)              _IQ13sqrt(A)
#endif
#if GLOBAL_Q == 12
#define _IQsqrt(A)              _IQ12sqrt(A)
#endif
#if GLOBAL_Q == 11
#define _IQsqrt(A)              _IQ11sqrt(A)
#endif
#if GLOBAL_Q == 10
#define _IQsqrt(A)              _IQ10sqrt(A)
#endif
#if GLOBAL_Q == 9
#define _IQsqrt(A)              _IQ9sqrt(A)
#endif
#if GLOBAL_Q == 8
#define _IQsqrt(A)              _IQ8sqrt(A)
#endif
#if GLOBAL_Q == 7
#define _IQsqrt(A)              _IQ7sqrt(A)
#endif
#if GLOBAL_Q == 6
#define _IQsqrt(A)              _IQ6sqrt(A)
#endif
#if GLOBAL_Q == 5
#define _IQsqrt(A)              _IQ5sqrt(A)
#endif
#if GLOBAL_Q == 4
#define _IQsqrt(A)              _IQ4sqrt(A)
#endif
#if GLOBAL_Q == 3
#define _IQsqrt(A)              _IQ3sqrt(A)
#endif
#if GLOBAL_Q == 2
#define _IQsqrt(A)              _IQ2sqrt(A)
#endif
#if GLOBAL_Q == 1
#define _IQsqrt(A)              _IQ1sqrt(A)
#endif


//*****************************************************************************
//
// Returns the integer portion of an IQ number.
//
//*****************************************************************************
#define _IQ30int(A)             BarrelShift((A), (RA_shift+ 30))
#define _IQ29int(A)             BarrelShift((A), (RA_shift+ 29))
#define _IQ28int(A)             BarrelShift((A), (RA_shift+ 28))
#define _IQ27int(A)             BarrelShift((A), (RA_shift+ 27))
#define _IQ26int(A)             BarrelShift((A), (RA_shift+ 26))
#define _IQ25int(A)             BarrelShift((A), (RA_shift+ 25))
#define _IQ24int(A)             BarrelShift((A), (RA_shift+ 24))
#define _IQ23int(A)             BarrelShift((A), (RA_shift+ 23))
#define _IQ22int(A)             BarrelShift((A), (RA_shift+ 22))
#define _IQ21int(A)             BarrelShift((A), (RA_shift+ 21))
#define _IQ20int(A)             BarrelShift((A), (RA_shift+ 20))
#define _IQ19int(A)             BarrelShift((A), (RA_shift+ 19))
#define _IQ18int(A)             BarrelShift((A), (RA_shift+ 18))
#define _IQ17int(A)             BarrelShift((A), (RA_shift+ 17))
#define _IQ16int(A)             BarrelShift((A), (RA_shift+ 16))
#define _IQ15int(A)             BarrelShift((A), (RA_shift+ 15))
#define _IQ14int(A)             BarrelShift((A), (RA_shift+ 14))
#define _IQ13int(A)             BarrelShift((A), (RA_shift+ 13))
#define _IQ12int(A)             BarrelShift((A), (RA_shift+ 12))
#define _IQ11int(A)             BarrelShift((A), (RA_shift+ 11))
#define _IQ10int(A)             BarrelShift((A), (RA_shift+ 10))
#define _IQ9int(A)              BarrelShift((A), (RA_shift+ 9))
#define _IQ8int(A)              BarrelShift((A), (RA_shift+ 8))
#define _IQ7int(A)              BarrelShift((A), (RA_shift+ 7))
#define _IQ6int(A)              BarrelShift((A), (RA_shift+ 6))
#define _IQ5int(A)              BarrelShift((A), (RA_shift+ 5))
#define _IQ4int(A)              BarrelShift((A), (RA_shift+ 4))
#define _IQ3int(A)              BarrelShift((A), (RA_shift+ 3))
#define _IQ2int(A)              BarrelShift((A), (RA_shift+ 2))
#define _IQ1int(A)              BarrelShift((A), (RA_shift+ 1))
#define _IQint(A)               BarrelShift((A), (RA_shift+ GLOBAL_Q))

//*****************************************************************************
//
// Computes the fractional portion of an IQ number.
//
//*****************************************************************************
extern _iq30 _IQ30frac(_iq30 A);
extern _iq29 _IQ29frac(_iq29 A);
extern _iq28 _IQ28frac(_iq28 A);
extern _iq27 _IQ27frac(_iq27 A);
extern _iq26 _IQ26frac(_iq26 A);
extern _iq25 _IQ25frac(_iq25 A);
extern _iq24 _IQ24frac(_iq24 A);
extern _iq23 _IQ23frac(_iq23 A);
extern _iq22 _IQ22frac(_iq22 A);
extern _iq21 _IQ21frac(_iq21 A);
extern _iq20 _IQ20frac(_iq20 A);
extern _iq19 _IQ19frac(_iq19 A);
extern _iq18 _IQ18frac(_iq18 A);
extern _iq17 _IQ17frac(_iq17 A);
extern _iq16 _IQ16frac(_iq16 A);
extern _iq15 _IQ15frac(_iq15 A);
extern _iq14 _IQ14frac(_iq14 A);
extern _iq13 _IQ13frac(_iq13 A);
extern _iq12 _IQ12frac(_iq12 A);
extern _iq11 _IQ11frac(_iq11 A);
extern _iq10 _IQ10frac(_iq10 A);
extern _iq9 _IQ9frac(_iq9 A);
extern _iq8 _IQ8frac(_iq8 A);
extern _iq7 _IQ7frac(_iq7 A);
extern _iq6 _IQ6frac(_iq6 A);
extern _iq5 _IQ5frac(_iq5 A);
extern _iq4 _IQ4frac(_iq4 A);
extern _iq3 _IQ3frac(_iq3 A);
extern _iq2 _IQ2frac(_iq2 A);
extern _iq1 _IQ1frac(_iq1 A);

#if GLOBAL_Q == 30
#define _IQfrac(A)              _IQ30frac(A)
#endif
#if GLOBAL_Q == 29
#define _IQfrac(A)              _IQ29frac(A)
#endif
#if GLOBAL_Q == 28
#define _IQfrac(A)              _IQ28frac(A)
#endif
#if GLOBAL_Q == 27
#define _IQfrac(A)              _IQ27frac(A)
#endif
#if GLOBAL_Q == 26
#define _IQfrac(A)              _IQ26frac(A)
#endif
#if GLOBAL_Q == 25
#define _IQfrac(A)              _IQ25frac(A)
#endif
#if GLOBAL_Q == 24
#define _IQfrac(A)              _IQ24frac(A)
#endif
#if GLOBAL_Q == 23
#define _IQfrac(A)              _IQ23frac(A)
#endif
#if GLOBAL_Q == 22
#define _IQfrac(A)              _IQ22frac(A)
#endif
#if GLOBAL_Q == 21
#define _IQfrac(A)              _IQ21frac(A)
#endif
#if GLOBAL_Q == 20
#define _IQfrac(A)              _IQ20frac(A)
#endif
#if GLOBAL_Q == 19
#define _IQfrac(A)              _IQ19frac(A)
#endif
#if GLOBAL_Q == 18
#define _IQfrac(A)              _IQ18frac(A)
#endif
#if GLOBAL_Q == 17
#define _IQfrac(A)              _IQ17frac(A)
#endif
#if GLOBAL_Q == 16
#define _IQfrac(A)              _IQ16frac(A)
#endif
#if GLOBAL_Q == 15
#define _IQfrac(A)              _IQ15frac(A)
#endif
#if GLOBAL_Q == 14
#define _IQfrac(A)              _IQ14frac(A)
#endif
#if GLOBAL_Q == 13
#define _IQfrac(A)              _IQ13frac(A)
#endif
#if GLOBAL_Q == 12
#define _IQfrac(A)              _IQ12frac(A)
#endif
#if GLOBAL_Q == 11
#define _IQfrac(A)              _IQ11frac(A)
#endif
#if GLOBAL_Q == 10
#define _IQfrac(A)              _IQ10frac(A)
#endif
#if GLOBAL_Q == 9
#define _IQfrac(A)              _IQ9frac(A)
#endif
#if GLOBAL_Q == 8
#define _IQfrac(A)              _IQ8frac(A)
#endif
#if GLOBAL_Q == 7
#define _IQfrac(A)              _IQ7frac(A)
#endif
#if GLOBAL_Q == 6
#define _IQfrac(A)              _IQ6frac(A)
#endif
#if GLOBAL_Q == 5
#define _IQfrac(A)              _IQ5frac(A)
#endif
#if GLOBAL_Q == 4
#define _IQfrac(A)              _IQ4frac(A)
#endif
#if GLOBAL_Q == 3
#define _IQfrac(A)              _IQ3frac(A)
#endif
#if GLOBAL_Q == 2
#define _IQfrac(A)              _IQ2frac(A)
#endif
#if GLOBAL_Q == 1
#define _IQfrac(A)              _IQ1frac(A)
#endif

//*****************************************************************************
//
// Multiplies two IQ numbers in the specified iQ formats, returning the result
// in another IQ format.
//
//*****************************************************************************
extern long __IQxmpy(long A, long B, long S);
#define _IQ30mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 30 + 32 - (IQA) - (IQB))
#define _IQ29mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 29 + 32 - (IQA) - (IQB))
#define _IQ28mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 28 + 32 - (IQA) - (IQB))
#define _IQ27mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 27 + 32 - (IQA) - (IQB))
#define _IQ26mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 26 + 32 - (IQA) - (IQB))
#define _IQ25mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 25 + 32 - (IQA) - (IQB))
#define _IQ24mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 24 + 32 - (IQA) - (IQB))
#define _IQ23mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 23 + 32 - (IQA) - (IQB))
#define _IQ22mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 22 + 32 - (IQA) - (IQB))
#define _IQ21mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 21 + 32 - (IQA) - (IQB))
#define _IQ20mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 20 + 32 - (IQA) - (IQB))
#define _IQ19mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 19 + 32 - (IQA) - (IQB))
#define _IQ18mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 18 + 32 - (IQA) - (IQB))
#define _IQ17mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 17 + 32 - (IQA) - (IQB))
#define _IQ16mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 16 + 32 - (IQA) - (IQB))
#define _IQ15mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 15 + 32 - (IQA) - (IQB))
#define _IQ14mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 14 + 32 - (IQA) - (IQB))
#define _IQ13mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 13 + 32 - (IQA) - (IQB))
#define _IQ12mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 12 + 32 - (IQA) - (IQB))
#define _IQ11mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 11 + 32 - (IQA) - (IQB))
#define _IQ10mpyIQX(A, IQA, B, IQB) __IQxmpy(A, B, 10 + 32 - (IQA) - (IQB))
#define _IQ9mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 9 + 32 - (IQA) - (IQB))
#define _IQ8mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 8 + 32 - (IQA) - (IQB))
#define _IQ7mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 7 + 32 - (IQA) - (IQB))
#define _IQ6mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 6 + 32 - (IQA) - (IQB))
#define _IQ5mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 5 + 32 - (IQA) - (IQB))
#define _IQ4mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 4 + 32 - (IQA) - (IQB))
#define _IQ3mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 3 + 32 - (IQA) - (IQB))
#define _IQ2mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 2 + 32 - (IQA) - (IQB))
#define _IQ1mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, 1 + 32 - (IQA) - (IQB))
#define _IQmpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B,                            \
                                             (GLOBAL_Q) + 32 - (IQA) - (IQB))

//*****************************************************************************
//
// Multiplies an IQ number by an integer.
//
//*****************************************************************************
#define _IQ30mpyI32(A, B)       ((A) * (B))
#define _IQ29mpyI32(A, B)       ((A) * (B))
#define _IQ28mpyI32(A, B)       ((A) * (B))
#define _IQ27mpyI32(A, B)       ((A) * (B))
#define _IQ26mpyI32(A, B)       ((A) * (B))
#define _IQ25mpyI32(A, B)       ((A) * (B))
#define _IQ24mpyI32(A, B)       ((A) * (B))
#define _IQ23mpyI32(A, B)       ((A) * (B))
#define _IQ22mpyI32(A, B)       ((A) * (B))
#define _IQ21mpyI32(A, B)       ((A) * (B))
#define _IQ20mpyI32(A, B)       ((A) * (B))
#define _IQ19mpyI32(A, B)       ((A) * (B))
#define _IQ18mpyI32(A, B)       ((A) * (B))
#define _IQ17mpyI32(A, B)       ((A) * (B))
#define _IQ16mpyI32(A, B)       ((A) * (B))
#define _IQ15mpyI32(A, B)       ((A) * (B))
#define _IQ14mpyI32(A, B)       ((A) * (B))
#define _IQ13mpyI32(A, B)       ((A) * (B))
#define _IQ12mpyI32(A, B)       ((A) * (B))
#define _IQ11mpyI32(A, B)       ((A) * (B))
#define _IQ10mpyI32(A, B)       ((A) * (B))
#define _IQ9mpyI32(A, B)        ((A) * (B))
#define _IQ8mpyI32(A, B)        ((A) * (B))		
#define _IQ7mpyI32(A, B)        ((A) * (B))
#define _IQ6mpyI32(A, B)        ((A) * (B))
#define _IQ5mpyI32(A, B)        ((A) * (B))
#define _IQ4mpyI32(A, B)        ((A) * (B))
#define _IQ3mpyI32(A, B)        ((A) * (B))
#define _IQ2mpyI32(A, B)        ((A) * (B))
#define _IQ1mpyI32(A, B)        ((A) * (B))
#define _IQmpyI32(A, B)         ((A) * (B))

//*****************************************************************************
//
// Multiplies an IQ number by an integer, and returns the integer portion.
//
//*****************************************************************************
extern _iq30 _IQ30mpyI32int(_iq30 A, long B);
extern _iq29 _IQ29mpyI32int(_iq29 A, long B);
extern _iq28 _IQ28mpyI32int(_iq28 A, long B);
extern _iq27 _IQ27mpyI32int(_iq27 A, long B);
extern _iq26 _IQ26mpyI32int(_iq26 A, long B);
extern _iq25 _IQ25mpyI32int(_iq25 A, long B);
extern _iq24 _IQ24mpyI32int(_iq24 A, long B);
extern _iq23 _IQ23mpyI32int(_iq23 A, long B);
extern _iq22 _IQ22mpyI32int(_iq22 A, long B);
extern _iq21 _IQ21mpyI32int(_iq21 A, long B);
extern _iq20 _IQ20mpyI32int(_iq20 A, long B);
extern _iq19 _IQ19mpyI32int(_iq19 A, long B);
extern _iq18 _IQ18mpyI32int(_iq18 A, long B);
extern _iq17 _IQ17mpyI32int(_iq17 A, long B);
extern _iq16 _IQ16mpyI32int(_iq16 A, long B);
extern _iq15 _IQ15mpyI32int(_iq15 A, long B);
extern _iq14 _IQ14mpyI32int(_iq14 A, long B);
extern _iq13 _IQ13mpyI32int(_iq13 A, long B);
extern _iq12 _IQ12mpyI32int(_iq12 A, long B);
extern _iq11 _IQ11mpyI32int(_iq11 A, long B);
extern _iq10 _IQ10mpyI32int(_iq10 A, long B);
extern _iq9 _IQ9mpyI32int(_iq9 A, long B);
extern _iq8 _IQ8mpyI32int(_iq8 A, long B);
extern _iq7 _IQ7mpyI32int(_iq7 A, long B);
extern _iq6 _IQ6mpyI32int(_iq6 A, long B);
extern _iq5 _IQ5mpyI32int(_iq5 A, long B);
extern _iq4 _IQ4mpyI32int(_iq4 A, long B);
extern _iq3 _IQ3mpyI32int(_iq3 A, long B);
extern _iq2 _IQ2mpyI32int(_iq2 A, long B);
extern _iq1 _IQ1mpyI32int(_iq1 A, long B);

#if GLOBAL_Q == 30
#define _IQmpyI32int(A, B)      _IQ30mpyI32int(A, B)
#endif
#if GLOBAL_Q == 29
#define _IQmpyI32int(A, B)      _IQ29mpyI32int(A, B)
#endif
#if GLOBAL_Q == 28
#define _IQmpyI32int(A, B)      _IQ28mpyI32int(A, B)
#endif
#if GLOBAL_Q == 27
#define _IQmpyI32int(A, B)      _IQ27mpyI32int(A, B)
#endif
#if GLOBAL_Q == 26
#define _IQmpyI32int(A, B)      _IQ26mpyI32int(A, B)
#endif
#if GLOBAL_Q == 25
#define _IQmpyI32int(A, B)      _IQ25mpyI32int(A, B)
#endif
#if GLOBAL_Q == 24
#define _IQmpyI32int(A, B)      _IQ24mpyI32int(A, B)
#endif
#if GLOBAL_Q == 23
#define _IQmpyI32int(A, B)      _IQ23mpyI32int(A, B)
#endif
#if GLOBAL_Q == 22
#define _IQmpyI32int(A, B)      _IQ22mpyI32int(A, B)
#endif
#if GLOBAL_Q == 21
#define _IQmpyI32int(A, B)      _IQ21mpyI32int(A, B)
#endif
#if GLOBAL_Q == 20
#define _IQmpyI32int(A, B)      _IQ20mpyI32int(A, B)
#endif
#if GLOBAL_Q == 19
#define _IQmpyI32int(A, B)      _IQ19mpyI32int(A, B)
#endif
#if GLOBAL_Q == 18
#define _IQmpyI32int(A, B)      _IQ18mpyI32int(A, B)
#endif
#if GLOBAL_Q == 17
#define _IQmpyI32int(A, B)      _IQ17mpyI32int(A, B)
#endif
#if GLOBAL_Q == 16
#define _IQmpyI32int(A, B)      _IQ16mpyI32int(A, B)
#endif
#if GLOBAL_Q == 15
#define _IQmpyI32int(A, B)      _IQ15mpyI32int(A, B)
#endif
#if GLOBAL_Q == 14
#define _IQmpyI32int(A, B)      _IQ14mpyI32int(A, B)
#endif
#if GLOBAL_Q == 13
#define _IQmpyI32int(A, B)      _IQ13mpyI32int(A, B)
#endif
#if GLOBAL_Q == 12
#define _IQmpyI32int(A, B)      _IQ12mpyI32int(A, B)
#endif
#if GLOBAL_Q == 11
#define _IQmpyI32int(A, B)      _IQ11mpyI32int(A, B)
#endif
#if GLOBAL_Q == 10
#define _IQmpyI32int(A, B)      _IQ10mpyI32int(A, B)
#endif
#if GLOBAL_Q == 9
#define _IQmpyI32int(A, B)      _IQ9mpyI32int(A, B)
#endif
#if GLOBAL_Q == 8
#define _IQmpyI32int(A, B)      _IQ8mpyI32int(A, B)
#endif
#if GLOBAL_Q == 7
#define _IQmpyI32int(A, B)      _IQ7mpyI32int(A, B)
#endif
#if GLOBAL_Q == 6
#define _IQmpyI32int(A, B)      _IQ6mpyI32int(A, B)
#endif
#if GLOBAL_Q == 5
#define _IQmpyI32int(A, B)      _IQ5mpyI32int(A, B)
#endif
#if GLOBAL_Q == 4
#define _IQmpyI32int(A, B)      _IQ4mpyI32int(A, B)
#endif
#if GLOBAL_Q == 3
#define _IQmpyI32int(A, B)      _IQ3mpyI32int(A, B)
#endif
#if GLOBAL_Q == 2
#define _IQmpyI32int(A, B)      _IQ2mpyI32int(A, B)
#endif
#if GLOBAL_Q == 1
#define _IQmpyI32int(A, B)      _IQ1mpyI32int(A, B)
#endif

//*****************************************************************************
//
// Multiplies an IQ number by an integer, and returns the fractional portion.
//
//*****************************************************************************
extern _iq30 _IQ30mpyI32frac(_iq30 A, long B);
extern _iq29 _IQ29mpyI32frac(_iq29 A, long B);
extern _iq28 _IQ28mpyI32frac(_iq28 A, long B);
extern _iq27 _IQ27mpyI32frac(_iq27 A, long B);
extern _iq26 _IQ26mpyI32frac(_iq26 A, long B);
extern _iq25 _IQ25mpyI32frac(_iq25 A, long B);
extern _iq24 _IQ24mpyI32frac(_iq24 A, long B);
extern _iq23 _IQ23mpyI32frac(_iq23 A, long B);
extern _iq22 _IQ22mpyI32frac(_iq22 A, long B);
extern _iq21 _IQ21mpyI32frac(_iq21 A, long B);
extern _iq20 _IQ20mpyI32frac(_iq20 A, long B);
extern _iq19 _IQ19mpyI32frac(_iq19 A, long B);
extern _iq18 _IQ18mpyI32frac(_iq18 A, long B);
extern _iq17 _IQ17mpyI32frac(_iq17 A, long B);
extern _iq16 _IQ16mpyI32frac(_iq16 A, long B);
extern _iq15 _IQ15mpyI32frac(_iq15 A, long B);
extern _iq14 _IQ14mpyI32frac(_iq14 A, long B);
extern _iq13 _IQ13mpyI32frac(_iq13 A, long B);
extern _iq12 _IQ12mpyI32frac(_iq12 A, long B);
extern _iq11 _IQ11mpyI32frac(_iq11 A, long B);
extern _iq10 _IQ10mpyI32frac(_iq10 A, long B);
extern _iq9 _IQ9mpyI32frac(_iq9 A, long B);
extern _iq8 _IQ8mpyI32frac(_iq8 A, long B);
extern _iq7 _IQ7mpyI32frac(_iq7 A, long B);
extern _iq6 _IQ6mpyI32frac(_iq6 A, long B);
extern _iq5 _IQ5mpyI32frac(_iq5 A, long B);
extern _iq4 _IQ4mpyI32frac(_iq4 A, long B);
extern _iq3 _IQ3mpyI32frac(_iq3 A, long B);
extern _iq2 _IQ2mpyI32frac(_iq2 A, long B);
extern _iq1 _IQ1mpyI32frac(_iq1 A, long B);

#if GLOBAL_Q == 30
#define _IQmpyI32frac(A, B)     _IQ30mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 29
#define _IQmpyI32frac(A, B)     _IQ29mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 28
#define _IQmpyI32frac(A, B)     _IQ28mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 27
#define _IQmpyI32frac(A, B)     _IQ27mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 26
#define _IQmpyI32frac(A, B)     _IQ26mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 25
#define _IQmpyI32frac(A, B)     _IQ25mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 24
#define _IQmpyI32frac(A, B)     _IQ24mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 23
#define _IQmpyI32frac(A, B)     _IQ23mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 22
#define _IQmpyI32frac(A, B)     _IQ22mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 21
#define _IQmpyI32frac(A, B)     _IQ21mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 20
#define _IQmpyI32frac(A, B)     _IQ20mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 19
#define _IQmpyI32frac(A, B)     _IQ19mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 18
#define _IQmpyI32frac(A, B)     _IQ18mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 17
#define _IQmpyI32frac(A, B)     _IQ17mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 16
#define _IQmpyI32frac(A, B)     _IQ16mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 15
#define _IQmpyI32frac(A, B)     _IQ15mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 14
#define _IQmpyI32frac(A, B)     _IQ14mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 13
#define _IQmpyI32frac(A, B)     _IQ13mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 12
#define _IQmpyI32frac(A, B)     _IQ12mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 11
#define _IQmpyI32frac(A, B)     _IQ11mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 10
#define _IQmpyI32frac(A, B)     _IQ10mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 9
#define _IQmpyI32frac(A, B)     _IQ9mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 8
#define _IQmpyI32frac(A, B)     _IQ8mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 7
#define _IQmpyI32frac(A, B)     _IQ7mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 6
#define _IQmpyI32frac(A, B)     _IQ6mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 5
#define _IQmpyI32frac(A, B)     _IQ5mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 4
#define _IQmpyI32frac(A, B)     _IQ4mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 3
#define _IQmpyI32frac(A, B)     _IQ3mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 2
#define _IQmpyI32frac(A, B)     _IQ2mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 1
#define _IQmpyI32frac(A, B)     _IQ1mpyI32frac(A, B)
#endif

//*****************************************************************************
//
// Computes the square root of A^2 + B^2 using IQ numbers.
//
//*****************************************************************************
extern _iq30 _IQ30mag(_iq30 A, _iq30 B);
extern _iq29 _IQ29mag(_iq29 A, _iq29 B);
extern _iq28 _IQ28mag(_iq28 A, _iq28 B);
extern _iq27 _IQ27mag(_iq27 A, _iq27 B);
extern _iq26 _IQ26mag(_iq26 A, _iq26 B);
extern _iq25 _IQ25mag(_iq25 A, _iq25 B);
extern _iq24 _IQ24mag(_iq24 A, _iq24 B);
extern _iq23 _IQ23mag(_iq23 A, _iq23 B);
extern _iq22 _IQ22mag(_iq22 A, _iq22 B);
extern _iq21 _IQ21mag(_iq21 A, _iq21 B);
extern _iq20 _IQ20mag(_iq20 A, _iq20 B);
extern _iq19 _IQ19mag(_iq19 A, _iq19 B);
extern _iq18 _IQ18mag(_iq18 A, _iq18 B);
extern _iq17 _IQ17mag(_iq17 A, _iq17 B);
extern _iq16 _IQ16mag(_iq16 A, _iq16 B);
extern _iq15 _IQ15mag(_iq15 A, _iq15 B);
extern _iq14 _IQ14mag(_iq14 A, _iq14 B);
extern _iq13 _IQ13mag(_iq13 A, _iq13 B);
extern _iq12 _IQ12mag(_iq12 A, _iq12 B);
extern _iq11 _IQ11mag(_iq11 A, _iq11 B);
extern _iq10 _IQ10mag(_iq10 A, _iq10 B);
extern _iq9 _IQ9mag(_iq9 A, _iq9 B);
extern _iq8 _IQ8mag(_iq8 A, _iq8 B);
extern _iq7 _IQ7mag(_iq7 A, _iq7 B);
extern _iq6 _IQ6mag(_iq6 A, _iq6 B);
extern _iq5 _IQ5mag(_iq5 A, _iq5 B);
extern _iq4 _IQ4mag(_iq4 A, _iq4 B);
extern _iq3 _IQ3mag(_iq3 A, _iq3 B);
extern _iq2 _IQ2mag(_iq2 A, _iq2 B);
extern _iq1 _IQ1mag(_iq1 A, _iq1 B);

#if GLOBAL_Q == 30
#define _IQmag(A, B)            _IQ30mag(A, B)
#endif
#if GLOBAL_Q == 29
#define _IQmag(A, B)            _IQ29mag(A, B)
#endif
#if GLOBAL_Q == 28
#define _IQmag(A, B)            _IQ28mag(A, B)
#endif
#if GLOBAL_Q == 27
#define _IQmag(A, B)            _IQ27mag(A, B)
#endif
#if GLOBAL_Q == 26
#define _IQmag(A, B)            _IQ26mag(A, B)
#endif
#if GLOBAL_Q == 25
#define _IQmag(A, B)            _IQ25mag(A, B)
#endif
#if GLOBAL_Q == 24
#define _IQmag(A, B)            _IQ24mag(A, B)
#endif
#if GLOBAL_Q == 23
#define _IQmag(A, B)            _IQ23mag(A, B)
#endif
#if GLOBAL_Q == 22
#define _IQmag(A, B)            _IQ22mag(A, B)
#endif
#if GLOBAL_Q == 21
#define _IQmag(A, B)            _IQ21mag(A, B)
#endif
#if GLOBAL_Q == 20
#define _IQmag(A, B)            _IQ20mag(A, B)
#endif
#if GLOBAL_Q == 19
#define _IQmag(A, B)            _IQ19mag(A, B)
#endif
#if GLOBAL_Q == 18
#define _IQmag(A, B)            _IQ18mag(A, B)
#endif
#if GLOBAL_Q == 17
#define _IQmag(A, B)            _IQ17mag(A, B)
#endif
#if GLOBAL_Q == 16
#define _IQmag(A, B)            _IQ16mag(A, B)
#endif
#if GLOBAL_Q == 15
#define _IQmag(A, B)            _IQ15mag(A, B)
#endif
#if GLOBAL_Q == 14
#define _IQmag(A, B)            _IQ14mag(A, B)
#endif
#if GLOBAL_Q == 13
#define _IQmag(A, B)            _IQ13mag(A, B)
#endif
#if GLOBAL_Q == 12
#define _IQmag(A, B)            _IQ12mag(A, B)
#endif
#if GLOBAL_Q == 11
#define _IQmag(A, B)            _IQ11mag(A, B)
#endif
#if GLOBAL_Q == 10
#define _IQmag(A, B)            _IQ10mag(A, B)
#endif
#if GLOBAL_Q == 9
#define _IQmag(A, B)            _IQ9mag(A, B)
#endif
#if GLOBAL_Q == 8
#define _IQmag(A, B)            _IQ8mag(A, B)
#endif
#if GLOBAL_Q == 7
#define _IQmag(A, B)            _IQ7mag(A, B)
#endif
#if GLOBAL_Q == 6
#define _IQmag(A, B)            _IQ6mag(A, B)
#endif
#if GLOBAL_Q == 5
#define _IQmag(A, B)            _IQ5mag(A, B)
#endif
#if GLOBAL_Q == 4
#define _IQmag(A, B)            _IQ4mag(A, B)
#endif
#if GLOBAL_Q == 3
#define _IQmag(A, B)            _IQ3mag(A, B)
#endif
#if GLOBAL_Q == 2
#define _IQmag(A, B)            _IQ2mag(A, B)
#endif
#if GLOBAL_Q == 1
#define _IQmag(A, B)            _IQ1mag(A, B)
#endif

//*****************************************************************************
//
// Converts a string into an IQ number.
//
//*****************************************************************************
extern _iq _atoIQN(const char *A, long B);
#define _atoIQ30(A)             _atoIQN(A, 30)
#define _atoIQ29(A)             _atoIQN(A, 29)
#define _atoIQ28(A)             _atoIQN(A, 28)
#define _atoIQ27(A)             _atoIQN(A, 27)
#define _atoIQ26(A)             _atoIQN(A, 26)
#define _atoIQ25(A)             _atoIQN(A, 25)
#define _atoIQ24(A)             _atoIQN(A, 24)
#define _atoIQ23(A)             _atoIQN(A, 23)
#define _atoIQ22(A)             _atoIQN(A, 22)
#define _atoIQ21(A)             _atoIQN(A, 21)
#define _atoIQ20(A)             _atoIQN(A, 20)
#define _atoIQ19(A)             _atoIQN(A, 19)
#define _atoIQ18(A)             _atoIQN(A, 18)
#define _atoIQ17(A)             _atoIQN(A, 17)
#define _atoIQ16(A)             _atoIQN(A, 16)
#define _atoIQ15(A)             _atoIQN(A, 15)
#define _atoIQ14(A)             _atoIQN(A, 14)
#define _atoIQ13(A)             _atoIQN(A, 13)
#define _atoIQ12(A)             _atoIQN(A, 12)
#define _atoIQ11(A)             _atoIQN(A, 11)
#define _atoIQ10(A)             _atoIQN(A, 10)
#define _atoIQ9(A)              _atoIQN(A, 9)
#define _atoIQ8(A)              _atoIQN(A, 8)
#define _atoIQ7(A)              _atoIQN(A, 7)
#define _atoIQ6(A)              _atoIQN(A, 6)
#define _atoIQ5(A)              _atoIQN(A, 5)
#define _atoIQ4(A)              _atoIQN(A, 4)
#define _atoIQ3(A)              _atoIQN(A, 3)
#define _atoIQ2(A)              _atoIQN(A, 2)
#define _atoIQ1(A)              _atoIQN(A, 1)
#define _atoIQ(A)               _atoIQN(A, GLOBAL_Q)

//*****************************************************************************
//
// Converts an IQ number into a string.
//
//*****************************************************************************
extern int __IQNtoa(char *A, const char *B, _iq C, int D);
#define _IQ30toa(A, B, C)       __IQNtoa(A, B, C, 30);
#define _IQ29toa(A, B, C)       __IQNtoa(A, B, C, 29);
#define _IQ28toa(A, B, C)       __IQNtoa(A, B, C, 28);
#define _IQ27toa(A, B, C)       __IQNtoa(A, B, C, 27);
#define _IQ26toa(A, B, C)       __IQNtoa(A, B, C, 26);
#define _IQ25toa(A, B, C)       __IQNtoa(A, B, C, 25);
#define _IQ24toa(A, B, C)       __IQNtoa(A, B, C, 24);
#define _IQ23toa(A, B, C)       __IQNtoa(A, B, C, 23);
#define _IQ22toa(A, B, C)       __IQNtoa(A, B, C, 22);
#define _IQ21toa(A, B, C)       __IQNtoa(A, B, C, 21);
#define _IQ20toa(A, B, C)       __IQNtoa(A, B, C, 20);
#define _IQ19toa(A, B, C)       __IQNtoa(A, B, C, 19);
#define _IQ18toa(A, B, C)       __IQNtoa(A, B, C, 18);
#define _IQ17toa(A, B, C)       __IQNtoa(A, B, C, 17);
#define _IQ16toa(A, B, C)       __IQNtoa(A, B, C, 16);
#define _IQ15toa(A, B, C)       __IQNtoa(A, B, C, 15);
#define _IQ14toa(A, B, C)       __IQNtoa(A, B, C, 14);
#define _IQ13toa(A, B, C)       __IQNtoa(A, B, C, 13);
#define _IQ12toa(A, B, C)       __IQNtoa(A, B, C, 12);
#define _IQ11toa(A, B, C)       __IQNtoa(A, B, C, 11);
#define _IQ10toa(A, B, C)       __IQNtoa(A, B, C, 10);
#define _IQ9toa(A, B, C)        __IQNtoa(A, B, C, 9);
#define _IQ8toa(A, B, C)        __IQNtoa(A, B, C, 8);
#define _IQ7toa(A, B, C)        __IQNtoa(A, B, C, 7);
#define _IQ6toa(A, B, C)        __IQNtoa(A, B, C, 6);
#define _IQ5toa(A, B, C)        __IQNtoa(A, B, C, 5);
#define _IQ4toa(A, B, C)        __IQNtoa(A, B, C, 4);
#define _IQ3toa(A, B, C)        __IQNtoa(A, B, C, 3);
#define _IQ2toa(A, B, C)        __IQNtoa(A, B, C, 2);
#define _IQ1toa(A, B, C)        __IQNtoa(A, B, C, 1);
#define _IQtoa(A, B, C)         __IQNtoa(A, B, C, GLOBAL_Q)

//*****************************************************************************
//
// Computes the absolute value of an IQ number.
//
//*****************************************************************************


//*****************************************************************************
//
// Otherwise, floating point math is being used.
//
//*****************************************************************************
#else // MATH_TYPE == FLOAT_MATH

//*****************************************************************************
//
// The floating point equivalent of the various IQ formats.
//
//*****************************************************************************
typedef float _iq30;
typedef float _iq29;
typedef float _iq28;
typedef float _iq27;
typedef float _iq26;
typedef float _iq25;
typedef float _iq24;
typedef float _iq23;
typedef float _iq22;
typedef float _iq21;
typedef float _iq20;
typedef float _iq19;
typedef float _iq18;
typedef float _iq17;
typedef float _iq16;
typedef float _iq15;
typedef float _iq14;
typedef float _iq13;
typedef float _iq12;
typedef float _iq11;
typedef float _iq10;
typedef float _iq9;
typedef float _iq8;
typedef float _iq7;
typedef float _iq6;
typedef float _iq5;
typedef float _iq4;
typedef float _iq3;
typedef float _iq2;
typedef float _iq1;
typedef float _iq;

//*****************************************************************************
//
// Simple multiplies or divides.
//
//*****************************************************************************
#define _IQmpy2(A)              ((A) * 2.0)
#define _IQmpy4(A)              ((A) * 4.0)
#define _IQmpy8(A)              ((A) * 8.0)
#define _IQmpy16(A)             ((A) * 16.0)
#define _IQmpy32(A)             ((A) * 32.0)
#define _IQmpy64(A)             ((A) * 64.0)
#define _IQdiv2(A)              ((A) / 2.0)
#define _IQdiv4(A)              ((A) / 4.0)
#define _IQdiv8(A)              ((A) / 8.0)
#define _IQdiv16(A)             ((A) / 16.0)
#define _IQdiv32(A)             ((A) / 32.0)
#define _IQdiv64(A)             ((A) / 64.0)

//*****************************************************************************
//
// Convert a value into an IQ number.
//
//*****************************************************************************
#define _IQ30(A)                (A)
#define _IQ29(A)                (A)
#define _IQ28(A)                (A)
#define _IQ27(A)                (A)
#define _IQ26(A)                (A)
#define _IQ25(A)                (A)
#define _IQ24(A)                (A)
#define _IQ23(A)                (A)
#define _IQ22(A)                (A)
#define _IQ21(A)                (A)
#define _IQ20(A)                (A)
#define _IQ19(A)                (A)
#define _IQ18(A)                (A)
#define _IQ17(A)                (A)
#define _IQ16(A)                (A)
#define _IQ15(A)                (A)
#define _IQ14(A)                (A)
#define _IQ13(A)                (A)
#define _IQ12(A)                (A)
#define _IQ11(A)                (A)
#define _IQ10(A)                (A)
#define _IQ9(A)                 (A)
#define _IQ8(A)                 (A)
#define _IQ7(A)                 (A)
#define _IQ6(A)                 (A)
#define _IQ5(A)                 (A)
#define _IQ4(A)                 (A)
#define _IQ3(A)                 (A)
#define _IQ2(A)                 (A)
#define _IQ1(A)                 (A)
#define _IQ(A)                  (A)

//*****************************************************************************
//
// Convert an IQ number to a floating point value.
//
//*****************************************************************************
#define _IQ30toF(A)             (A)
#define _IQ29toF(A)             (A)
#define _IQ28toF(A)             (A)
#define _IQ27toF(A)             (A)
#define _IQ26toF(A)             (A)
#define _IQ25toF(A)             (A)
#define _IQ24toF(A)             (A)
#define _IQ23toF(A)             (A)
#define _IQ22toF(A)             (A)
#define _IQ21toF(A)             (A)
#define _IQ20toF(A)             (A)
#define _IQ19toF(A)             (A)
#define _IQ18toF(A)             (A)
#define _IQ17toF(A)             (A)
#define _IQ16toF(A)             (A)
#define _IQ15toF(A)             (A)
#define _IQ14toF(A)             (A)
#define _IQ13toF(A)             (A)
#define _IQ12toF(A)             (A)
#define _IQ11toF(A)             (A)
#define _IQ10toF(A)             (A)
#define _IQ9toF(A)              (A)
#define _IQ8toF(A)              (A)
#define _IQ7toF(A)              (A)
#define _IQ6toF(A)              (A)
#define _IQ5toF(A)              (A)
#define _IQ4toF(A)              (A)
#define _IQ3toF(A)              (A)
#define _IQ2toF(A)              (A)
#define _IQ1toF(A)              (A)
#define _IQtoF(A)               (A)

//*****************************************************************************
//
// Convert an IQ number to a double-precision floating point value.
//
//*****************************************************************************
#define _IQ30toD(A)             (A)
#define _IQ29toD(A)             (A)
#define _IQ28toD(A)             (A)
#define _IQ27toD(A)             (A)
#define _IQ26toD(A)             (A)
#define _IQ25toD(A)             (A)
#define _IQ24toD(A)             (A)
#define _IQ23toD(A)             (A)
#define _IQ22toD(A)             (A)
#define _IQ21toD(A)             (A)
#define _IQ20toD(A)             (A)
#define _IQ19toD(A)             (A)
#define _IQ18toD(A)             (A)
#define _IQ17toD(A)             (A)
#define _IQ16toD(A)             (A)
#define _IQ15toD(A)             (A)
#define _IQ14toD(A)             (A)
#define _IQ13toD(A)             (A)
#define _IQ12toD(A)             (A)
#define _IQ11toD(A)             (A)
#define _IQ10toD(A)             (A)
#define _IQ9toD(A)              (A)
#define _IQ8toD(A)              (A)
#define _IQ7toD(A)              (A)
#define _IQ6toD(A)              (A)
#define _IQ5toD(A)              (A)
#define _IQ4toD(A)              (A)
#define _IQ3toD(A)              (A)
#define _IQ2toD(A)              (A)
#define _IQ1toD(A)              (A)
#define _IQtoD(A)               (A)

//*****************************************************************************
//
// Saturates an IQ number in a given range.
//
//*****************************************************************************
#define _IQsat(A, Pos, Neg)     (((A) > (Pos)) ?                              \
                                 (Pos) :                                      \
                                 (((A) < (Neg)) ? (Neg) : (A)))

//*****************************************************************************
//
// Converts an IQ number between the global IQ format and a specified IQ
// format.
//
//*****************************************************************************
#define _IQtoIQ30(A)            (A)
#define _IQ30toIQ(A)            (A)
#define _IQtoIQ29(A)            (A)
#define _IQ29toIQ(A)            (A)
#define _IQtoIQ28(A)            (A)
#define _IQ28toIQ(A)            (A)
#define _IQtoIQ27(A)            (A)
#define _IQ27toIQ(A)            (A)
#define _IQtoIQ26(A)            (A)
#define _IQ26toIQ(A)            (A)
#define _IQtoIQ25(A)            (A)
#define _IQ25toIQ(A)            (A)
#define _IQtoIQ24(A)            (A)
#define _IQ24toIQ(A)            (A)
#define _IQtoIQ23(A)            (A)
#define _IQ23toIQ(A)            (A)
#define _IQtoIQ22(A)            (A)
#define _IQ22toIQ(A)            (A)
#define _IQtoIQ21(A)            (A)
#define _IQ21toIQ(A)            (A)
#define _IQtoIQ20(A)            (A)
#define _IQ20toIQ(A)            (A)
#define _IQtoIQ19(A)            (A)
#define _IQ19toIQ(A)            (A)
#define _IQtoIQ18(A)            (A)
#define _IQ18toIQ(A)            (A)
#define _IQtoIQ17(A)            (A)
#define _IQ17toIQ(A)            (A)
#define _IQtoIQ16(A)            (A)
#define _IQ16toIQ(A)            (A)
#define _IQtoIQ15(A)            (A)
#define _IQ15toIQ(A)            (A)
#define _IQtoIQ14(A)            (A)
#define _IQ14toIQ(A)            (A)
#define _IQtoIQ13(A)            (A)
#define _IQ13toIQ(A)            (A)
#define _IQtoIQ12(A)            (A)
#define _IQ12toIQ(A)            (A)
#define _IQtoIQ11(A)            (A)
#define _IQ11toIQ(A)            (A)
#define _IQtoIQ10(A)            (A)
#define _IQ10toIQ(A)            (A)
#define _IQtoIQ9(A)             (A)
#define _IQ9toIQ(A)             (A)
#define _IQtoIQ8(A)             (A)
#define _IQ8toIQ(A)             (A)
#define _IQtoIQ7(A)             (A)
#define _IQ7toIQ(A)             (A)
#define _IQtoIQ6(A)             (A)
#define _IQ6toIQ(A)             (A)
#define _IQtoIQ5(A)             (A)
#define _IQ5toIQ(A)             (A)
#define _IQtoIQ4(A)             (A)
#define _IQ4toIQ(A)             (A)
#define _IQtoIQ3(A)             (A)
#define _IQ3toIQ(A)             (A)
#define _IQtoIQ2(A)             (A)
#define _IQ2toIQ(A)             (A)
#define _IQtoIQ1(A)             (A)
#define _IQ1toIQ(A)             (A)

//*****************************************************************************
//
// Converts a number between IQ format and 16-bit Qn format.
//
//*****************************************************************************
#define _IQtoQ15(A)             ((short)((long)((A) * (1 << 15))))
#define _Q15toIQ(A)             (((float)(A)) * (1.0 / (1 << 15)))
#define _IQtoQ14(A)             ((short)((long)((A) * (1 << 14))))
#define _Q14toIQ(A)             (((float)(A)) * (1.0 / (1 << 14)))
#define _IQtoQ13(A)             ((short)((long)((A) * (1 << 13))))
#define _Q13toIQ(A)             (((float)(A)) * (1.0 / (1 << 13)))
#define _IQtoQ12(A)             ((short)((long)((A) * (1 << 12))))
#define _Q12toIQ(A)             (((float)(A)) * (1.0 / (1 << 12)))
#define _IQtoQ11(A)             ((short)((long)((A) * (1 << 11))))
#define _Q11toIQ(A)             (((float)(A)) * (1.0 / (1 << 11)))
#define _IQtoQ10(A)             ((short)((long)((A) * (1 << 10))))
#define _Q10toIQ(A)             (((float)(A)) * (1.0 / (1 << 10)))
#define _IQtoQ9(A)              ((short)((long)((A) * (1 << 9))))
#define _Q9toIQ(A)              (((float)(A)) * (1.0 / (1 << 9)))
#define _IQtoQ8(A)              ((short)((long)((A) * (1 << 8))))
#define _Q8toIQ(A)              (((float)(A)) * (1.0 / (1 << 8)))
#define _IQtoQ7(A)              ((short)((long)((A) * (1 << 7))))
#define _Q7toIQ(A)              (((float)(A)) * (1.0 / (1 << 7)))
#define _IQtoQ6(A)              ((short)((long)((A) * (1 << 6))))
#define _Q6toIQ(A)              (((float)(A)) * (1.0 / (1 << 6)))
#define _IQtoQ5(A)              ((short)((long)((A) * (1 << 5))))
#define _Q5toIQ(A)              (((float)(A)) * (1.0 / (1 << 5)))
#define _IQtoQ4(A)              ((short)((long)((A) * (1 << 4))))
#define _Q4toIQ(A)              (((float)(A)) * (1.0 / (1 << 4)))
#define _IQtoQ3(A)              ((short)((long)((A) * (1 << 3))))
#define _Q3toIQ(A)              (((float)(A)) * (1.0 / (1 << 3)))
#define _IQtoQ2(A)              ((short)((long)((A) * (1 << 2))))
#define _Q2toIQ(A)              (((float)(A)) * (1.0 / (1 << 2)))
#define _IQtoQ1(A)              ((short)((long)((A) * (1 << 1))))
#define _Q1toIQ(A)              (((float)(A)) * (1.0 / (1 << 1)))


//*****************************************************************************
//
// Multiplies two IQ numbers, with rounding.
//
//*****************************************************************************
#define _IQ30rmpy(A, B)         ((A) * (B))
#define _IQ29rmpy(A, B)         ((A) * (B))
#define _IQ28rmpy(A, B)         ((A) * (B))
#define _IQ27rmpy(A, B)         ((A) * (B))
#define _IQ26rmpy(A, B)         ((A) * (B))
#define _IQ25rmpy(A, B)         ((A) * (B))
#define _IQ24rmpy(A, B)         ((A) * (B))
#define _IQ23rmpy(A, B)         ((A) * (B))
#define _IQ22rmpy(A, B)         ((A) * (B))
#define _IQ21rmpy(A, B)         ((A) * (B))
#define _IQ20rmpy(A, B)         ((A) * (B))
#define _IQ19rmpy(A, B)         ((A) * (B))
#define _IQ18rmpy(A, B)         ((A) * (B))
#define _IQ17rmpy(A, B)         ((A) * (B))
#define _IQ16rmpy(A, B)         ((A) * (B))
#define _IQ15rmpy(A, B)         ((A) * (B))
#define _IQ14rmpy(A, B)         ((A) * (B))
#define _IQ13rmpy(A, B)         ((A) * (B))
#define _IQ12rmpy(A, B)         ((A) * (B))
#define _IQ11rmpy(A, B)         ((A) * (B))
#define _IQ10rmpy(A, B)         ((A) * (B))
#define _IQ9rmpy(A, B)          ((A) * (B))
#define _IQ8rmpy(A, B)          ((A) * (B))
#define _IQ7rmpy(A, B)          ((A) * (B))
#define _IQ6rmpy(A, B)          ((A) * (B))
#define _IQ5rmpy(A, B)          ((A) * (B))
#define _IQ4rmpy(A, B)          ((A) * (B))
#define _IQ3rmpy(A, B)          ((A) * (B))
#define _IQ2rmpy(A, B)          ((A) * (B))
#define _IQ1rmpy(A, B)          ((A) * (B))
#define _IQrmpy(A, B)           ((A) * (B))

//*****************************************************************************
//
// Multiplies two IQ numbers, with rounding and saturation.
//
//*****************************************************************************
#define _IQ30rsmpy(A, B)        ((A) * (B))
#define _IQ29rsmpy(A, B)        ((A) * (B))
#define _IQ28rsmpy(A, B)        ((A) * (B))
#define _IQ27rsmpy(A, B)        ((A) * (B))
#define _IQ26rsmpy(A, B)        ((A) * (B))
#define _IQ25rsmpy(A, B)        ((A) * (B))
#define _IQ24rsmpy(A, B)        ((A) * (B))
#define _IQ23rsmpy(A, B)        ((A) * (B))
#define _IQ22rsmpy(A, B)        ((A) * (B))
#define _IQ21rsmpy(A, B)        ((A) * (B))
#define _IQ20rsmpy(A, B)        ((A) * (B))
#define _IQ19rsmpy(A, B)        ((A) * (B))
#define _IQ18rsmpy(A, B)        ((A) * (B))
#define _IQ17rsmpy(A, B)        ((A) * (B))
#define _IQ16rsmpy(A, B)        ((A) * (B))
#define _IQ15rsmpy(A, B)        ((A) * (B))
#define _IQ14rsmpy(A, B)        ((A) * (B))
#define _IQ13rsmpy(A, B)        ((A) * (B))
#define _IQ12rsmpy(A, B)        ((A) * (B))
#define _IQ11rsmpy(A, B)        ((A) * (B))
#define _IQ10rsmpy(A, B)        ((A) * (B))
#define _IQ9rsmpy(A, B)         ((A) * (B))
#define _IQ8rsmpy(A, B)         ((A) * (B))
#define _IQ7rsmpy(A, B)         ((A) * (B))
#define _IQ6rsmpy(A, B)         ((A) * (B))
#define _IQ5rsmpy(A, B)         ((A) * (B))
#define _IQ4rsmpy(A, B)         ((A) * (B))
#define _IQ3rsmpy(A, B)         ((A) * (B))
#define _IQ2rsmpy(A, B)         ((A) * (B))
#define _IQ1rsmpy(A, B)         ((A) * (B))
#define _IQrsmpy(A, B)          ((A) * (B))



//*****************************************************************************
//
// Computes the sin of an IQ number.
//
//*****************************************************************************
#define _IQ29sin(A)             sin(A)
#define _IQ28sin(A)             sin(A)
#define _IQ27sin(A)             sin(A)
#define _IQ26sin(A)             sin(A)
#define _IQ25sin(A)             sin(A)
#define _IQ24sin(A)             sin(A)
#define _IQ23sin(A)             sin(A)
#define _IQ22sin(A)             sin(A)
#define _IQ21sin(A)             sin(A)
#define _IQ20sin(A)             sin(A)
#define _IQ19sin(A)             sin(A)
#define _IQ18sin(A)             sin(A)
#define _IQ17sin(A)             sin(A)
#define _IQ16sin(A)             sin(A)
#define _IQ15sin(A)             sin(A)
#define _IQ14sin(A)             sin(A)
#define _IQ13sin(A)             sin(A)
#define _IQ12sin(A)             sin(A)
#define _IQ11sin(A)             sin(A)
#define _IQ10sin(A)             sin(A)
#define _IQ9sin(A)              sin(A)
#define _IQ8sin(A)              sin(A)
#define _IQ7sin(A)              sin(A)
#define _IQ6sin(A)              sin(A)
#define _IQ5sin(A)              sin(A)
#define _IQ4sin(A)              sin(A)
#define _IQ3sin(A)              sin(A)
#define _IQ2sin(A)              sin(A)
#define _IQ1sin(A)              sin(A)
#define _IQsin(A)               sin(A)

//*****************************************************************************
//
// Computes the cos of an IQ number.
//
//*****************************************************************************
#define _IQ29cos(A)             cos(A)
#define _IQ28cos(A)             cos(A)
#define _IQ27cos(A)             cos(A)
#define _IQ26cos(A)             cos(A)
#define _IQ25cos(A)             cos(A)
#define _IQ24cos(A)             cos(A)
#define _IQ23cos(A)             cos(A)
#define _IQ22cos(A)             cos(A)
#define _IQ21cos(A)             cos(A)
#define _IQ20cos(A)             cos(A)
#define _IQ19cos(A)             cos(A)
#define _IQ18cos(A)             cos(A)
#define _IQ17cos(A)             cos(A)
#define _IQ16cos(A)             cos(A)
#define _IQ15cos(A)             cos(A)
#define _IQ14cos(A)             cos(A)
#define _IQ13cos(A)             cos(A)
#define _IQ12cos(A)             cos(A)
#define _IQ11cos(A)             cos(A)
#define _IQ10cos(A)             cos(A)
#define _IQ9cos(A)              cos(A)
#define _IQ8cos(A)              cos(A)
#define _IQ7cos(A)              cos(A)
#define _IQ6cos(A)              cos(A)
#define _IQ5cos(A)              cos(A)
#define _IQ4cos(A)              cos(A)
#define _IQ3cos(A)              cos(A)
#define _IQ2cos(A)              cos(A)
#define _IQ1cos(A)              cos(A)
#define _IQcos(A)               cos(A)


//*****************************************************************************
//
// Computes the arctan of an IQ number.
//
//*****************************************************************************
#define _IQ29atan(A)            atan(A)
#define _IQ28atan(A)            atan(A)
#define _IQ27atan(A)            atan(A)
#define _IQ26atan(A)            atan(A)
#define _IQ25atan(A)            atan(A)
#define _IQ24atan(A)            atan(A)
#define _IQ23atan(A)            atan(A)
#define _IQ22atan(A)            atan(A)
#define _IQ21atan(A)            atan(A)
#define _IQ20atan(A)            atan(A)
#define _IQ19atan(A)            atan(A)
#define _IQ18atan(A)            atan(A)
#define _IQ17atan(A)            atan(A)
#define _IQ16atan(A)            atan(A)
#define _IQ15atan(A)            atan(A)
#define _IQ14atan(A)            atan(A)
#define _IQ13atan(A)            atan(A)
#define _IQ12atan(A)            atan(A)
#define _IQ11atan(A)            atan(A)
#define _IQ10atan(A)            atan(A)
#define _IQ9atan(A)             atan(A)
#define _IQ8atan(A)             atan(A)
#define _IQ7atan(A)             atan(A)
#define _IQ6atan(A)             atan(A)
#define _IQ5atan(A)             atan(A)
#define _IQ4atan(A)             atan(A)
#define _IQ3atan(A)             atan(A)
#define _IQ2atan(A)             atan(A)
#define _IQ1atan(A)             atan(A)
#define _IQatan(A)              atan(A)

//*****************************************************************************
//
// Computes the arctan of a coordinate specified by two IQ numbers.
//
//*****************************************************************************
#define _IQ30atan2(A, B)        atan2(A, B)
#define _IQ29atan2(A, B)        atan2(A, B)
#define _IQ28atan2(A, B)        atan2(A, B)
#define _IQ27atan2(A, B)        atan2(A, B)
#define _IQ26atan2(A, B)        atan2(A, B)
#define _IQ25atan2(A, B)        atan2(A, B)
#define _IQ24atan2(A, B)        atan2(A, B)
#define _IQ23atan2(A, B)        atan2(A, B)
#define _IQ22atan2(A, B)        atan2(A, B)
#define _IQ21atan2(A, B)        atan2(A, B)
#define _IQ20atan2(A, B)        atan2(A, B)
#define _IQ19atan2(A, B)        atan2(A, B)
#define _IQ18atan2(A, B)        atan2(A, B)
#define _IQ17atan2(A, B)        atan2(A, B)
#define _IQ16atan2(A, B)        atan2(A, B)
#define _IQ15atan2(A, B)        atan2(A, B)
#define _IQ14atan2(A, B)        atan2(A, B)
#define _IQ13atan2(A, B)        atan2(A, B)
#define _IQ12atan2(A, B)        atan2(A, B)
#define _IQ11atan2(A, B)        atan2(A, B)
#define _IQ10atan2(A, B)        atan2(A, B)
#define _IQ9atan2(A, B)         atan2(A, B)
#define _IQ8atan2(A, B)         atan2(A, B)
#define _IQ7atan2(A, B)         atan2(A, B)
#define _IQ6atan2(A, B)         atan2(A, B)
#define _IQ5atan2(A, B)         atan2(A, B)
#define _IQ4atan2(A, B)         atan2(A, B)
#define _IQ3atan2(A, B)         atan2(A, B)
#define _IQ2atan2(A, B)         atan2(A, B)
#define _IQ1atan2(A, B)         atan2(A, B)
#define _IQatan2(A, B)          atan2(A, B)


//*****************************************************************************
//
// Computes the square root of an IQ number.
//
//*****************************************************************************
#define _IQ30sqrt(A)            sqrt(A)
#define _IQ29sqrt(A)            sqrt(A)
#define _IQ28sqrt(A)            sqrt(A)
#define _IQ27sqrt(A)            sqrt(A)
#define _IQ26sqrt(A)            sqrt(A)
#define _IQ25sqrt(A)            sqrt(A)
#define _IQ24sqrt(A)            sqrt(A)
#define _IQ23sqrt(A)            sqrt(A)
#define _IQ22sqrt(A)            sqrt(A)
#define _IQ21sqrt(A)            sqrt(A)
#define _IQ20sqrt(A)            sqrt(A)
#define _IQ19sqrt(A)            sqrt(A)
#define _IQ18sqrt(A)            sqrt(A)
#define _IQ17sqrt(A)            sqrt(A)
#define _IQ16sqrt(A)            sqrt(A)
#define _IQ15sqrt(A)            sqrt(A)
#define _IQ14sqrt(A)            sqrt(A)
#define _IQ13sqrt(A)            sqrt(A)
#define _IQ12sqrt(A)            sqrt(A)
#define _IQ11sqrt(A)            sqrt(A)
#define _IQ10sqrt(A)            sqrt(A)
#define _IQ9sqrt(A)             sqrt(A)
#define _IQ8sqrt(A)             sqrt(A)
#define _IQ7sqrt(A)             sqrt(A)
#define _IQ6sqrt(A)             sqrt(A)
#define _IQ5sqrt(A)             sqrt(A)
#define _IQ4sqrt(A)             sqrt(A)
#define _IQ3sqrt(A)             sqrt(A)
#define _IQ2sqrt(A)             sqrt(A)
#define _IQ1sqrt(A)             sqrt(A)
#define _IQsqrt(A)              sqrt(A)

//*****************************************************************************
//
// Computes 1 over the square root of an IQ number.
//
//*****************************************************************************
#define _IQ30isqrt(A)           (1.0 / sqrt(A))
#define _IQ29isqrt(A)           (1.0 / sqrt(A))
#define _IQ28isqrt(A)           (1.0 / sqrt(A))
#define _IQ27isqrt(A)           (1.0 / sqrt(A))
#define _IQ26isqrt(A)           (1.0 / sqrt(A))
#define _IQ25isqrt(A)           (1.0 / sqrt(A))
#define _IQ24isqrt(A)           (1.0 / sqrt(A))
#define _IQ23isqrt(A)           (1.0 / sqrt(A))
#define _IQ22isqrt(A)           (1.0 / sqrt(A))
#define _IQ21isqrt(A)           (1.0 / sqrt(A))
#define _IQ20isqrt(A)           (1.0 / sqrt(A))
#define _IQ19isqrt(A)           (1.0 / sqrt(A))
#define _IQ18isqrt(A)           (1.0 / sqrt(A))
#define _IQ17isqrt(A)           (1.0 / sqrt(A))
#define _IQ16isqrt(A)           (1.0 / sqrt(A))
#define _IQ15isqrt(A)           (1.0 / sqrt(A))
#define _IQ14isqrt(A)           (1.0 / sqrt(A))
#define _IQ13isqrt(A)           (1.0 / sqrt(A))
#define _IQ12isqrt(A)           (1.0 / sqrt(A))
#define _IQ11isqrt(A)           (1.0 / sqrt(A))
#define _IQ10isqrt(A)           (1.0 / sqrt(A))
#define _IQ9isqrt(A)            (1.0 / sqrt(A))
#define _IQ8isqrt(A)            (1.0 / sqrt(A))
#define _IQ7isqrt(A)            (1.0 / sqrt(A))
#define _IQ6isqrt(A)            (1.0 / sqrt(A))
#define _IQ5isqrt(A)            (1.0 / sqrt(A))
#define _IQ4isqrt(A)            (1.0 / sqrt(A))
#define _IQ3isqrt(A)            (1.0 / sqrt(A))
#define _IQ2isqrt(A)            (1.0 / sqrt(A))
#define _IQ1isqrt(A)            (1.0 / sqrt(A))
#define _IQisqrt(A)             (1.0 / sqrt(A))


//*****************************************************************************
//
// Returns the integer portion of an IQ number.
//
//*****************************************************************************
#define _IQ30int(A)             ((long)(A))
#define _IQ29int(A)             ((long)(A))
#define _IQ28int(A)             ((long)(A))
#define _IQ27int(A)             ((long)(A))
#define _IQ26int(A)             ((long)(A))
#define _IQ25int(A)             ((long)(A))
#define _IQ24int(A)             ((long)(A))
#define _IQ23int(A)             ((long)(A))
#define _IQ22int(A)             ((long)(A))
#define _IQ21int(A)             ((long)(A))
#define _IQ20int(A)             ((long)(A))
#define _IQ19int(A)             ((long)(A))
#define _IQ18int(A)             ((long)(A))
#define _IQ17int(A)             ((long)(A))
#define _IQ16int(A)             ((long)(A))
#define _IQ15int(A)             ((long)(A))
#define _IQ14int(A)             ((long)(A))
#define _IQ13int(A)             ((long)(A))
#define _IQ12int(A)             ((long)(A))
#define _IQ11int(A)             ((long)(A))
#define _IQ10int(A)             ((long)(A))
#define _IQ9int(A)              ((long)(A))
#define _IQ8int(A)              ((long)(A))
#define _IQ7int(A)              ((long)(A))
#define _IQ6int(A)              ((long)(A))
#define _IQ5int(A)              ((long)(A))
#define _IQ4int(A)              ((long)(A))
#define _IQ3int(A)              ((long)(A))
#define _IQ2int(A)              ((long)(A))
#define _IQ1int(A)              ((long)(A))
#define _IQint(A)               ((long)(A))

//*****************************************************************************
//
// Computes the fractional portion of an IQ number.
//
//*****************************************************************************
#define _IQ30frac(A)            ((A) - (float)((long)(A)))
#define _IQ29frac(A)            ((A) - (float)((long)(A)))
#define _IQ28frac(A)            ((A) - (float)((long)(A)))
#define _IQ27frac(A)            ((A) - (float)((long)(A)))
#define _IQ26frac(A)            ((A) - (float)((long)(A)))
#define _IQ25frac(A)            ((A) - (float)((long)(A)))
#define _IQ24frac(A)            ((A) - (float)((long)(A)))
#define _IQ23frac(A)            ((A) - (float)((long)(A)))
#define _IQ22frac(A)            ((A) - (float)((long)(A)))
#define _IQ21frac(A)            ((A) - (float)((long)(A)))
#define _IQ20frac(A)            ((A) - (float)((long)(A)))
#define _IQ19frac(A)            ((A) - (float)((long)(A)))
#define _IQ18frac(A)            ((A) - (float)((long)(A)))
#define _IQ17frac(A)            ((A) - (float)((long)(A)))
#define _IQ16frac(A)            ((A) - (float)((long)(A)))
#define _IQ15frac(A)            ((A) - (float)((long)(A)))
#define _IQ14frac(A)            ((A) - (float)((long)(A)))
#define _IQ13frac(A)            ((A) - (float)((long)(A)))
#define _IQ12frac(A)            ((A) - (float)((long)(A)))
#define _IQ11frac(A)            ((A) - (float)((long)(A)))
#define _IQ10frac(A)            ((A) - (float)((long)(A)))
#define _IQ9frac(A)             ((A) - (float)((long)(A)))
#define _IQ8frac(A)             ((A) - (float)((long)(A)))
#define _IQ7frac(A)             ((A) - (float)((long)(A)))
#define _IQ6frac(A)             ((A) - (float)((long)(A)))
#define _IQ5frac(A)             ((A) - (float)((long)(A)))
#define _IQ4frac(A)             ((A) - (float)((long)(A)))
#define _IQ3frac(A)             ((A) - (float)((long)(A)))
#define _IQ2frac(A)             ((A) - (float)((long)(A)))
#define _IQ1frac(A)             ((A) - (float)((long)(A)))
#define _IQfrac(A)              ((A) - (float)((long)(A)))

//*****************************************************************************
//
// Multiplies two IQ numbers in the specified IQ formats, returning the result
// in another IQ format.
//
//*****************************************************************************
#define _IQ30mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ29mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ28mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ27mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ26mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ25mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ24mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ23mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ22mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ21mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ20mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ19mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ18mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ17mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ16mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ15mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ14mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ13mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ12mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ11mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ10mpyIQX(A, IQA, B, IQB) ((A) * (B))
#define _IQ9mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ8mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ7mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ6mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ5mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ4mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ3mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ2mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQ1mpyIQX(A, IQA, B, IQB)  ((A) * (B))
#define _IQmpyIQX(A, IQA, B, IQB)   ((A) * (B))

//*****************************************************************************
//
// Multiplies an IQ number by an integer.
//
//*****************************************************************************
#define _IQ30mpyI32(A, B)       ((A) * (float)(B))
#define _IQ29mpyI32(A, B)       ((A) * (float)(B))
#define _IQ28mpyI32(A, B)       ((A) * (float)(B))
#define _IQ27mpyI32(A, B)       ((A) * (float)(B))
#define _IQ26mpyI32(A, B)       ((A) * (float)(B))
#define _IQ25mpyI32(A, B)       ((A) * (float)(B))
#define _IQ24mpyI32(A, B)       ((A) * (float)(B))
#define _IQ23mpyI32(A, B)       ((A) * (float)(B))
#define _IQ22mpyI32(A, B)       ((A) * (float)(B))
#define _IQ21mpyI32(A, B)       ((A) * (float)(B))
#define _IQ20mpyI32(A, B)       ((A) * (float)(B))
#define _IQ19mpyI32(A, B)       ((A) * (float)(B))
#define _IQ18mpyI32(A, B)       ((A) * (float)(B))
#define _IQ17mpyI32(A, B)       ((A) * (float)(B))
#define _IQ16mpyI32(A, B)       ((A) * (float)(B))
#define _IQ15mpyI32(A, B)       ((A) * (float)(B))
#define _IQ14mpyI32(A, B)       ((A) * (float)(B))
#define _IQ13mpyI32(A, B)       ((A) * (float)(B))
#define _IQ12mpyI32(A, B)       ((A) * (float)(B))
#define _IQ11mpyI32(A, B)       ((A) * (float)(B))
#define _IQ10mpyI32(A, B)       ((A) * (float)(B))
#define _IQ9mpyI32(A, B)        ((A) * (float)(B))
#define _IQ8mpyI32(A, B)        ((A) * (float)(B))
#define _IQ7mpyI32(A, B)        ((A) * (float)(B))
#define _IQ6mpyI32(A, B)        ((A) * (float)(B))
#define _IQ5mpyI32(A, B)        ((A) * (float)(B))
#define _IQ4mpyI32(A, B)        ((A) * (float)(B))
#define _IQ3mpyI32(A, B)        ((A) * (float)(B))
#define _IQ2mpyI32(A, B)        ((A) * (float)(B))
#define _IQ1mpyI32(A, B)        ((A) * (float)(B))
#define _IQmpyI32(A, B)         ((A) * (float)(B))

//*****************************************************************************
//
// Multiplies an IQ number by an integer, and returns the integer portion.
//
//*****************************************************************************
#define _IQ30mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ29mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ28mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ27mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ26mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ25mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ24mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ23mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ22mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ21mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ20mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ19mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ18mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ17mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ16mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ15mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ14mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ13mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ12mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ11mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ10mpyI32int(A, B)    ((long)((A) * (float)(B)))
#define _IQ9mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ8mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ7mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ6mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ5mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ4mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ3mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ2mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQ1mpyI32int(A, B)     ((long)((A) * (float)(B)))
#define _IQmpyI32int(A, B)      ((long)((A) * (float)(B)))

//*****************************************************************************
//
// Multiplies an IQ number by an integer, and returns the fractional portion.
//
//*****************************************************************************
#define _IQ30mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ29mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ28mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ27mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ26mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ25mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ24mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ23mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ22mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ21mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ20mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ19mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ18mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ17mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ16mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ15mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ14mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ13mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ12mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ11mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ10mpyI32frac(A, B)   (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ9mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ8mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ7mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ6mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ5mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ4mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ3mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ2mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQ1mpyI32frac(A, B)    (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))
#define _IQmpyI32frac(A, B)     (((A) * (B)) -                                \
                                 (float)((long)((A) * (float)(B))))



//*****************************************************************************
//
// Converts a string into an IQ number.
//
//*****************************************************************************
#define _atoIQ30(A)             atof(A)
#define _atoIQ29(A)             atof(A)
#define _atoIQ28(A)             atof(A)
#define _atoIQ27(A)             atof(A)
#define _atoIQ26(A)             atof(A)
#define _atoIQ25(A)             atof(A)
#define _atoIQ24(A)             atof(A)
#define _atoIQ23(A)             atof(A)
#define _atoIQ22(A)             atof(A)
#define _atoIQ21(A)             atof(A)
#define _atoIQ20(A)             atof(A)
#define _atoIQ19(A)             atof(A)
#define _atoIQ18(A)             atof(A)
#define _atoIQ17(A)             atof(A)
#define _atoIQ16(A)             atof(A)
#define _atoIQ15(A)             atof(A)
#define _atoIQ14(A)             atof(A)
#define _atoIQ13(A)             atof(A)
#define _atoIQ12(A)             atof(A)
#define _atoIQ11(A)             atof(A)
#define _atoIQ10(A)             atof(A)
#define _atoIQ9(A)              atof(A)
#define _atoIQ8(A)              atof(A)
#define _atoIQ7(A)              atof(A)
#define _atoIQ6(A)              atof(A)
#define _atoIQ5(A)              atof(A)
#define _atoIQ4(A)              atof(A)
#define _atoIQ3(A)              atof(A)
#define _atoIQ2(A)              atof(A)
#define _atoIQ1(A)              atof(A)
#define _atoIQ(A)               atof(A)

//*****************************************************************************
//
// Converts an IQ number into a string.
//
//*****************************************************************************
#define _IQ30toa(A, B, C)       sprintf(A, B, C)
#define _IQ29toa(A, B, C)       sprintf(A, B, C)
#define _IQ28toa(A, B, C)       sprintf(A, B, C)
#define _IQ27toa(A, B, C)       sprintf(A, B, C)
#define _IQ26toa(A, B, C)       sprintf(A, B, C)
#define _IQ25toa(A, B, C)       sprintf(A, B, C)
#define _IQ24toa(A, B, C)       sprintf(A, B, C)
#define _IQ23toa(A, B, C)       sprintf(A, B, C)
#define _IQ22toa(A, B, C)       sprintf(A, B, C)
#define _IQ21toa(A, B, C)       sprintf(A, B, C)
#define _IQ20toa(A, B, C)       sprintf(A, B, C)
#define _IQ19toa(A, B, C)       sprintf(A, B, C)
#define _IQ18toa(A, B, C)       sprintf(A, B, C)
#define _IQ17toa(A, B, C)       sprintf(A, B, C)
#define _IQ16toa(A, B, C)       sprintf(A, B, C)
#define _IQ15toa(A, B, C)       sprintf(A, B, C)
#define _IQ14toa(A, B, C)       sprintf(A, B, C)
#define _IQ13toa(A, B, C)       sprintf(A, B, C)
#define _IQ12toa(A, B, C)       sprintf(A, B, C)
#define _IQ11toa(A, B, C)       sprintf(A, B, C)
#define _IQ10toa(A, B, C)       sprintf(A, B, C)
#define _IQ9toa(A, B, C)        sprintf(A, B, C)
#define _IQ8toa(A, B, C)        sprintf(A, B, C)
#define _IQ7toa(A, B, C)        sprintf(A, B, C)
#define _IQ6toa(A, B, C)        sprintf(A, B, C)
#define _IQ5toa(A, B, C)        sprintf(A, B, C)
#define _IQ4toa(A, B, C)        sprintf(A, B, C)
#define _IQ3toa(A, B, C)        sprintf(A, B, C)
#define _IQ2toa(A, B, C)        sprintf(A, B, C)
#define _IQ1toa(A, B, C)        sprintf(A, B, C)
#define _IQtoa(A, B, C)         sprintf(A, B, C)



#endif // MATH_TYPE == IQ_MATH

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __IQMATHLIB_H__
