#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "lib.h"
#include "ISD51.H"

#pragma mdu_r515					//use hardware math unit


 unsigned char hh;
 unsigned short ADresult;

void main(void)
{
   	#if ISDDebug == DISABLE_ISD
    SystemClock();
    #endif
		InitISDDebug(); 
 
  InitTimer4();                          //start timer1
	

	
	
	
		InitGPIO();
	//	InitEXT();
	
	
		EAL=1;
    while(1)
    {
			
			
			
			if 	(T4TF==1)	
			{
				T4TF=0;
				P26=~P26;
			}
			
			
        #if ISDDebug == ENABLE_ISD
        ISDcheck();      // Polling for ISD command for software breakpoint
        #endif
        
    }
}


