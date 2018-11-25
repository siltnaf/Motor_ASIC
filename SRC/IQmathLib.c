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

#include <intrins.h>   
#include <absacc.h>
#include "register.h"
#include "IQmathLib.h"










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
volatile U32 table_input;
	 
	angle_in=_IQabs(dat);
			
	//limit the search anlge to <360)
	
  while (angle_in>=_IQ(360.0))
			{
				angle_in-=_IQ(360.0);
			}
	
	// convert angle to data in sin table, angle =angle/360 * 512  or  =angle *64/45
			
	table_input=_IQint(angle_in<<6); 
	table_input/=45;	
 
  sin_out=XWORD[table_input+sin_table];
			sin_out=(sin_out<<16);   										//sin table is in Q15 format, it need to convert to Q31 first by shifting 16 bit to left
			sin_out=(sin_out) >> (31 - GLOBAL_Q);     	//convert Q31 to global Q format
	
	if (dat<0) sin_out=-(sin_out);
 

	
return sin_out ;
	
}





_iq _IQcos(_iq dat)
{
	
volatile _iq angle_in,cos_out;
volatile U32 table_input;
	 

	angle_in=_IQabs(dat);
			
	//limit the search anlge to <360)
	
  while (angle_in>=_IQ(360.0))
			{
				angle_in-=_IQ(360.0);
			}
	
	// convert angle to data in cos table, cos(angle) =sin(angle+90)
			
	table_input=_IQint(angle_in<<6); 
	table_input/=45;

 
  cos_out=XWORD[table_input+sin_table+128];            //cos is  lead sin by 90
 
	
	cos_out=(cos_out<<16);   										//sin table is in Q15 format, it need to convert to Q31 first by shifting 16 bit to left
	cos_out=(cos_out) >> (31 - GLOBAL_Q);     	//convert Q31 to global Q format
			
return cos_out ;
	
}







_iq Normalize(_iq dat)              //normalize only work for positive value. it return error if the MD3_7=1 
{
 Long_Data LD;
 LD.Ldata =dat;
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


_iq _IQinv(_iq dat)

{
volatile _iq inverse_in, inverse_out;
	volatile U32 table_input;
volatile S8  index;
	
	inverse_in=_IQabs(dat);
	

	inverse_in=Normalize(inverse_in);   //convert to Q30 format
	index=(30-GLOBAL_Q-ARCON);          //find the power index of normalized value
	inverse_in &=0x7fffffff;            
	table_input=inverse_in>>22;         //take the 9 bit value for table search
	inverse_out=XWORD[table_input+inverse_table];	 //read from the ROM table
	inverse_out=inverse_out<<16;
	inverse_out=(inverse_out) >> (31 - GLOBAL_Q);     	//convert Q31 to global Q format
	
	if (index>=0)   
		inverse_out=(inverse_out)>>index;
		else 
		inverse_out=inverse_out<<(-index);
                                               //multiply the index and return the output value
	if (dat<0) inverse_out=- inverse_out;
	
	
return inverse_out;
}


_iq _IQsqrt(_iq dat)

{
volatile _iq sqrt_in, sqrt_out;
	volatile U32 table_input;
volatile S8  power;
	
	sqrt_in=_IQabs(dat);
	sqrt_in=Normalize(sqrt_in);   //convert to Q30 format
	power=(31-GLOBAL_Q-ARCON);
	

	if (power %2==0)                //check if the power is even or  odd value
		
	{
	sqrt_in &=0x7fffffff;
	table_input=(sqrt_in>>23)+128;	
		
		sqrt_out=XWORD[table_input+sqrt_table];
	}
	else
	{
    power=power+1;                             //if the power is odd value , divide t by 2
	
		table_input =sqrt_in>>24;             //square root in value is divided by 2 
	  table_input &=0x0000007f;
		sqrt_out=XWORD[table_input+sqrt_table];
	}
	sqrt_out=sqrt_out<<16;
	sqrt_out=(sqrt_out) >> (30 - GLOBAL_Q);     	//convert Q31 to global Q format
	
	if (power>=0)
	sqrt_out=(sqrt_out)<<(power>>1);
	else sqrt_out=sqrt_out>>((-power)>>1);
	

	
	
return  sqrt_out;
}
