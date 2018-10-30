#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "lib.h"
#include "ISD51.H"

#pragma mdu_r515					//use hardware math unit



 unsigned int ADresult;
 unsigned int data_value;
 
 unsigned char tmr3_ov;
 unsigned long last_capture,this_capture, pwm_capture;
 
U32 EE_data;
 

void main(void)
{
   	#if ISDDebug == DISABLE_ISD
    SystemClock();
    #endif
		InitISDDebug(); 
InitTimer3();    
  //InitTimer4();                          //start timer1
	InitTimer01();
//	InitADC();                           //ADC use timer0 to trigger AD start
	
	
	
		InitGPIO();
	//	InitEXT();
	//InitComparator();
	
		EAL=1;
    while(1)
    {


			
			
			
//			EE_write(0x0a, 0xabcdef12);
//			EE_data=EE_read(0x0a);
		 
		
	
		while (BUSY==1);
				data_value= ADresult;
			
			
        #if ISDDebug == ENABLE_ISD
        ISDcheck();      // Polling for ISD command for software breakpoint
        #endif
        
    }
}


//void EE_write ( unsigned int  addr, unsigned char dat1, unsigned char dat2

