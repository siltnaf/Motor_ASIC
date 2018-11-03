#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "lib.h"
#include "ISD51.H"
#include "epwm.h"

#pragma mdu_r515					//use hardware math unit



 unsigned int ADresult;
 unsigned int data_value;
 
 unsigned char tmr3_ov,dac_value;
 unsigned long last_capture,this_capture, pwm_capture;
 
U32 EE_data;
 

void main(void)
{
   	#if ISDDebug == DISABLE_ISD
    SystemClock();
    #endif
		InitISDDebug(); 
InitTimer3();        //timer 3 using P15 pin to capture pwm "low level" pulse width
  //InitTimer4();                          //start timer1
	InitTimer01();
//	InitADC();                           //ADC use timer0 to trigger AD start
	
	InitDAC();
	
		InitGPIO();
	//	InitEXT();
	//InitComparator();
	
		EAL=1;
    while(1)
    {
			
		 
	
			dac_value=(unsigned char)(pwm_capture>>11);
			DAC1_DAT=0x88;
			DAC2_DAT=0xff;
			
			
			
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

