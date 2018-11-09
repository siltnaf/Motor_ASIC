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
#include "motorLib.h"



volatile U8 xdata _md_error;// _at_ (0xDFFF);
volatile U16 xdata _div_remainder;// _at_ (0xDFFD);
volatile U16 xdata _div_denominator;// _at_ (0xA4FB);

#pragma asm
								CSEG    AT      4000h
#pragma endasm
const unsigned char tDebugTable[10] = {1,2,3,4,5,6,7,8,9,10};



/*
 * @fn		EE_write
 *
 * @brief write data to EEPROM , 64x32 bit
 * 
 * @param	none
 * EE_write(eeprom address, eeprom data)

 *
 * @return 	none
 */

 void EE_write(U8 EE_addr, U32 EE_data)
{
	
			while (MTP_BUSY==1);
			MTPCON2=0x53;         //init MTP write mode
			MTPSADD1=EE_addr;       // EEPROM address
			MTPSADD2=0x00;
			MTPDATA=EE_data;
			
			MTPCON1=0x0b;				//start 
			
			while (MTP_WRITE==0);
			MTPCON1=0x0;
	
}

/*
 * @fn		EE_read
 *
 * @brief read data from EEPROM , 64x32 bit
 * 
 * @param	none
 * EE_read(eeprom address)

 *
 * @return 	eprom data
 */

U32 EE_read(U8 EE_addr)
{
	
			while (MTP_BUSY==1);
			MTPCON2=0x55;         //init MTP read mode
			MTPSADD1=EE_addr;       //
			MTPSADD2=0x00;
			MTPCON1=0x07;					//start
			while (MTP_READ==0);
			MTPCON1=0x0;
			return MTPDATA;
	
}






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



S32 Normalize(S32 Data)
{
 Long_Data LD;
 LD.Ldata =Data;
 MD0 = LD.ss1.Byte0;
 MD1 = LD.ss1.Byte1;
 MD2 = LD.ss1.Byte2;
 MD3 = LD.ss1.Byte3;
 ARCON = 0x00 ; // Start Normalizing
 while(MD3_7==0 ); //check MDU finish flag
	LD.ss1.Byte0=MD0;
	LD.ss1.Byte1=MD1;
	LD.ss1.Byte2=MD2;
	LD.ss1.Byte3=MD3;
 
	 return LD.Ldata ;
}
