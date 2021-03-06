#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "motorLib.h"
#include "ISD51.H"
#include "epwm.h"
#include "IQmathLib.h"

#pragma mdu_r515					//use hardware math unit



 unsigned int xdata ADresult;
 unsigned char xdata tmr3_ov,capture_flag;
 unsigned long xdata last_capture,this_capture,pwm_capture;
 unsigned char  xdata timer5_flag;

  

 
_iq xdata  result,theta,beta  ;     //gobal_q =24
 
U32 xdata EE_data;
 



void main(void)
{
  
	
	  SystemClock();
		InitISDDebug(); 

	
	//InitTimer3();        //timer 3 using P15 pin to capture pwm "low level" pulse width
  //InitTimer4();    
                     
	
	timer5_flag=0;
		InitTimer5(); 
		InitTimer6(); 
	//InitTimer01();
  //	InitADC();                           //ADC use timer0 to trigger AD start
	
	//InitDAC();
	
		InitGPIO();
	//	InitEXT();
	//InitComparator();
	//Initepwm();
	
		P26=0;
		EAL=1;
    while(1)
    {
			
		 

			 
			
//			input =  _IQ10((0.25*PI));           //test IQmathlib
			
	
//			P26=1;
			
//			result=_IQmul(_IQ(-6.57),_IQ(-2.5));

			
//			P26=0;
	
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




