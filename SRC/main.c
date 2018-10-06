#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "lib.h"
#include "ISD51.H"

#pragma mdu_r515					//use hardware math unit


 unsigned char hh;
 unsigned int ADresult;
 unsigned int NEXTresult;

void main(void)
{
   	#if ISDDebug == DISABLE_ISD
    SystemClock();
    #endif
		InitISDDebug(); 
 
  //InitTimer4();                          //start timer1
	InitTimer01();
	InitADC();
	
	
	
		InitGPIO();
	//	InitEXT();
	
	
		EAL=1;
    while(1)
    {
	
			while (BUSY==1);
				NEXTresult= ADresult;
				SWFTRG=1;				//start next AD
			
        #if ISDDebug == ENABLE_ISD
        ISDcheck();      // Polling for ISD command for software breakpoint
        #endif
        
    }
}


