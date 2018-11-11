#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "motorLib.h"
#include "ISD51.H"
#include "epwm.h"
#include "IQmathLib.h"

#pragma mdu_r515					//use hardware math unit



 unsigned int ADresult;
 unsigned int data_value;
 
 unsigned char tmr3_ov,dac_value;
 unsigned long last_capture,this_capture, pwm_capture;
 
_iq input,sin_out;     //gobal_q =24
 
U32 EE_data;
S32 math_data;
U8  index; 

void main(void)
{
   	#if ISDDebug == DISABLE_ISD
    SystemClock();
    #endif
		InitISDDebug(); 

	
	//InitTimer3();        //timer 3 using P15 pin to capture pwm "low level" pulse width
  //InitTimer4();                          //start timer1
	//InitTimer01();
  //	InitADC();                           //ADC use timer0 to trigger AD start
	
	//InitDAC();
	
		InitGPIO();
	//	InitEXT();
	//InitComparator();
	//Initepwm();
	
		EAL=1;
    while(1)
    {
			
		 
		math_data=Normalize(0x80000324);
			index=ARCON;
			
			math_data=math_data>>index;
			 
			
//			input =  _IQ10((0.25*PI));           //test IQmathlib
			
	
			
			
	
//			dac_value=(unsigned char)(pwm_capture>>11);             //check DAC
//			DAC1_DAT=dac_value;
//			DAC2_DAT=0xff;
			
			
			
//			EE_write(0x0a, 0xabcdef12);                        //check EPROM
//			EE_data=EE_read(0x0a);
		 
		
	
//		while (BUSY==1);                                     //check ADC
//				data_value= ADresult;
			
			
        #if ISDDebug == ENABLE_ISD
        ISDcheck();      // Polling for ISD command for software breakpoint
        #endif
        
    }
}




