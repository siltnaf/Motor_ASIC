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




 _iq  data X,Y,Z;
 S8  data index;




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


_iq _IQsin(_iq A)
{

	X=_IQabs(A);
		
	//limtit the search anlge to <360)
	
  while (X>=_IQ(360.0))
			{
				X=_IQ(360.0);
			}
	
	// convert angle to data in sin table, angle =angle/360 * 512  or  =angle *64/45
			
	X=_IQint(X<<6); 
	X/=45;	
 
  Z=XWORD[X+sin_table];
			Z=(Z<<16);   										//sin table is in Q15 format, it need to convert to Q31 first by shifting 16 bit to left
			Z=(Z) >> (30 - GLOBAL_Q);     	//convert Q31 to global Q format
	
	if (A<0) Z=-(Z);

return Z ;
	
}





_iq _IQcos(_iq A)
{
	
	X=_IQabs(A);
		
	//limit the search anlge to <360)
	
  while (X>=_IQ(360.0))
			{
				X-=_IQ(360.0);
			}
	
	// convert angle to data in cos table, cos(angle) =sin(angle+90)
			
	X=_IQint(X<<6); 
	X/=45;

 
  Z=XWORD[X+sin_table+128];            //cos is  lead sin by 90
 
	
	Z=(Z<<16);   										//sin table is in Q15 format, it need to convert to Q31 first by shifting 16 bit to left
	Z=(Z) >> (30 - GLOBAL_Q);     	//convert Q31 to global Q format
			
return Z ;
	
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


_iq _IQinv(_iq A)

{

	X=_IQabs(A);
	X=Normalize(X);   //convert to Q30 format
	index=(30-GLOBAL_Q-ARCON);          //find the power index of normalized value
	X &=0x7fffffff;            
	X=X>>22;         //take the 9 bit value for table search
	Z=XWORD[X+inverse_table];	 //read from the ROM table
	Z=Z<<16;
	Z=(Z) >> (31 - GLOBAL_Q);     	//convert Q31 to global Q format
	
	if (index>=0)   
		Z=(Z)>>index;
		else 
		Z=Z<<(-index);
                                               //multiply the index and return the output value
	if (A<0) Z=- Z;
	
	
return Z;
}



_iq _IQmpy(_iq A, _iq B)
{

	X=A>>half_Q;
	Y=B>>half_Q;
	
	Z = X* Y;
	
	
	if (GLOBAL_Q %2==1) Z =Z >>1; 
	return Z;
	
}







_iq _IQdiv(_iq A,_iq B)
{

	X=A<<half_Q;
 
	Y= B>>(GLOBAL_Q-half_Q);
	Z=X/Y;
	return Z;

}





_iq _IQsqrt(_iq A)

{

	X=_IQabs(A);

	X=Normalize(X);   //convert to Q30 format
	index=(31-GLOBAL_Q-ARCON);
	
	if (index %2==0)                //check if the power is even or  odd value	
	{
	X &=0x7fffffff;
	X=(X>>23)+128;	
		
		Z=XWORD[X+sqrt_table];
	}
	else
	{
    index++;                             //if the power is odd value , divide t by 2
	
		X =X>>24;             //square root in value is divided by 2 
	  X &=0x0000007f;
		Z=XWORD[X+sqrt_table];
	}
	Z=Z<<16;
	Z=(Z) >> (30 - GLOBAL_Q);     	//convert Q31 to global Q format
	
	if (index>=0)
	Z=(Z)<<(index>>1);
	else Z=Z>>((-index)>>1);
	
return  Z;
}

_iq _IQatan2(_iq A, _iq B)
{
	X=_IQabs(A);
	Y=_IQabs(B);
	if (X>Y)
		{
			Y=Y<<5;
			X=X>>4;
			X=Y/X;
			Z=XWORD[X+atan_table];
	
			Z=Z*45;                 //Z=(Z/4096)*45 degree
			Z=Z<<12;
			Z=Z>>(24-GLOBAL_Q);     //convert to IQ format
			
		}
		else
		{
			X=X<<5;
			Y=Y>>4;
			X=X/Y;
			Z=XWORD[X+atan_table];
			Z=Z*45;                 //Z=(Z/4096)*45 degree
			Z=Z<<12;
			Z=Z>>(24-GLOBAL_Q);     //convert to IQ format
			Z=_IQ(90.0)-Z;
		}
	if ((A<0)&&(B>0))
		Z=_IQ(180.0)-Z;
		else if ((A<0)&&(B<0))
			Z=_IQ(180.0)+Z;
		else if ((A>0)&&(B<0))
			Z=_IQ(360.0)-Z;
	
	

return Z;	
}


