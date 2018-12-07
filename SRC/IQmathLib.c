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



 Long_Data dat;
 _iq data X,Y,Z;
 S8  data index;










//_iq Normalize(_iq A)              //normalize only work for positive value. it return error if the MD3_7=1 
//{


//	

// dat.Ldata =A;
// MD0 = dat.ss1.Byte0;
// MD1 = dat.ss1.Byte1;
// MD2 = dat.ss1.Byte2;
// MD3 = dat.ss1.Byte3;
//	

//	
// ARCON = 0x00 ; // Start Normalizing
// while(MD3_7==0 ); //check MDU finish flag
//	dat.ss1.Byte0=MD0;
//	dat.ss1.Byte1=MD1;
//	dat.ss1.Byte2=MD2;
//	dat.ss1.Byte3=MD3;
// 
//	 return dat.Ldata ;
//}


/*
 * @fn		sin32
 *
 * @brief	sin32
 * 
* @param	none
 * _IQsin(X) ,  =sin(X), X is in degree

 *
 * @return 	value in IQ
 */







_iq _IQsin(_iq A)
{

	X=_IQabs(A);
	
		
	//limtit the search anlge to <360)
	
  while (X>=_IQ(360.0))
			{
				X-=_IQ(360.0);
			}
	
	
	// convert angle to data in sin table, angle =angle/360 * 512  or  =angle *64/45
			
	X=_IQmpy(X,_IQ(1.422222));
  X=_IQint(X);          //convert to integer
  Z=XWORD[X+sin_table];
	Z=BarrelShift(Z,(LL_shift+16));   										//sin table is in Q15 format, it need to convert to Q31 first by shifting 16 bit to left
	Z=BarrelShift(Z, (RA_shift+ (30 - GLOBAL_Q)));     	//convert Q31 to global Q format

	if (A<0) Z=-(Z);

return Z ;
	
}









/*
 * @fn		sqrt32
 *
 * @brief	sqrt32
 * 
 * @param	none
 * _IQsqrt(X) ,  sqrt(X)

 *
 * @return 	sqrt value in IQ
 */






_iq _IQsqrt(_iq A)

{

	if (A<0) return 0;

	X=Normalize(A);   //convert to Q30 format
	index=(31-GLOBAL_Q-ARCON);
	
	if (index %2==0)                //check if the power is even or  odd value	
	{
	X &=0x7fffffff;
	X=BarrelShift(X, (RA_shift+23))+128;	
		
		Z=XWORD[X+sqrt_table];
	}
	else
	{
    index++;                             //if the power is odd value , divide t by 2
	
		X =BarrelShift(X,(RA_shift+24));             //square root in value is divided by 2 
	  X &=0x0000007f;
		Z=XWORD[X+sqrt_table];
	}
	Z=BarrelShift(Z,(LL_shift+16));   										//sqrt table is in Q15 format, it need to convert to Q31 first by shifting 16 bit to left
	Z=BarrelShift(Z, (RA_shift+ (30 - GLOBAL_Q)));     	//convert Q31 to global Q format
	

	
	if (index>=0)
	Z=BarrelShift(Z, (LA_shift+(index/2)));
	else Z=BarrelShift(Z,(RA_shift+((-index)/2)));
	
return  Z;
}


/*
 * @fn		atan32
 *
 * @brief	atan32
 * 
 * @param	none
 * _IQatan2(Y,X) ,  atan2(Y/X)
 * _IQatan(Y)    , =atan2(Y/1)
 *


 * @return 	angle in degree
 */

_iq _IQatan2(_iq A, _iq B)
{
	Y=_IQabs(A);
	X=_IQabs(B);

	
	if (X>Y)
		{
			
			
			
			Y=BarrelShift(Y,(LA_shift+5));  
			X=BarrelShift(X,(RA_shift+4));  
			X=Y/X;
		
		
			index=pos;
		
		 

		}
		else
		{
			X=BarrelShift(X,(LA_shift+5)); ;
			Y=BarrelShift(Y,(RA_shift+4)); 
			X=X/Y;

			
			index=neg;
		}
			
			
			
		Z=XWORD[X+atan_table];
		Z=Z*45;                 //Z=(Z/4096)*45 degree
		Z=BarrelShift(Z,(LL_shift+12));   										//sin table is in Q15 format, it need to convert to Q31 first by shifting 16 bit to left
		Z=BarrelShift(Z, (RA_shift+ (24 - GLOBAL_Q)));     	//convert Q31 to global Q format
		
		
		if (index==neg)	Z=_IQ(90.0)-Z;
		
	if ((A<0)&&(B>0))
		Z=_IQ(180.0)-Z;
		else if ((A<0)&&(B<0))
			Z=_IQ(180.0)+Z;
		else if ((A>0)&&(B<0))
			Z=_IQ(360.0)-Z;
	
	

return Z;	
}


_iq _IQmag(_iq A, _iq B) 
{
	X=_IQmpy(A,A)+_IQmpy(B,B);
	Z=_IQsqrt(X);
	return Z;
	
}



