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
#ifndef _MOTORLIB_H_
#define _MOTORLIB_H_




	
	


 

extern void EE_write(unsigned char EE_addr, unsigned long EE_data);
extern unsigned long EE_read(unsigned char EE_addr); 

//extern _iq (_IQsin(S16 dat));


#endif //_LIB_H_
