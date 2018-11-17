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
#include "IQmathLib.h"



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


_iq _IQsin(_iq dat)
{
volatile _iq angle_in,sin_out;
volatile U32 table_angle;
	 
	
	
								
	
	angle_in=(((dat) < 0) ? - (dat) : (dat));
			
	//limit the search anlge to <360)
	
  while (angle_in>=_IQ(360.0))
			{
				angle_in-=_IQ(360.0);
			}
	
	// convert angle to data in sin table, angle =angle/360 * 512  or  =angle *64/45
			
	table_angle=(U32)((angle_in<<6)>>GLOBAL_Q ); 
	table_angle/=45;	
 
  sin_out=XWORD[table_angle+sin_table];
	
	if (dat<0) sin_out=-(sin_out);
	

	
return sin_out ;
	
}




_iq _IQcos(_iq dat)
{
volatile _iq angle_in,cos_out;
volatile U32 table_angle;
	 
	
	
								
	
	angle_in=(((dat) < 0) ? - (dat) : (dat));
			
	//limit the search anlge to <360)
	
  while (angle_in>=_IQ(360.0))
			{
				angle_in-=_IQ(360.0);
			}
	
	// convert angle to data in cos table, cos(angle) =sin(angle+90)
			
	table_angle=(U32)((angle_in<<6)>>GLOBAL_Q ); 
	table_angle/=45;
	table_angle+=128;
 
  cos_out=XWORD[table_angle+sin_table];
	

	
return cos_out ;
	
}







S32 Normalize(S32 Data)              //normalize only work for positive value. it return error if the MD3_7=1 
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

