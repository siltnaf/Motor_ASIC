#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "lib.h"
#include "ISD51.H"

#pragma mdu_r515					//use hardware math unit


 unsigned char hh;
 unsigned int ADresult;
 unsigned int data_value;

void main(void)
{
   	#if ISDDebug == DISABLE_ISD
    SystemClock();
    #endif
		InitISDDebug(); 
 
  //InitTimer4();                          //start timer1
	InitTimer01();
	InitADC();                           //ADC use timer0 to trigger AD start
	
	
	
		InitGPIO();
	//	InitEXT();
	
	
		EAL=1;
    while(1)
    {
	
		
		while (BUSY==1);
				data_value= ADresult;
			
			
        #if ISDDebug == ENABLE_ISD
        ISDcheck();      // Polling for ISD command for software breakpoint
        #endif
        
    }
}


