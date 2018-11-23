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


  

 
_iq   tbl_out,theta  ;     //gobal_q =24
 
U32 xdata EE_data;




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
			
		 

			 
			
//			input =  _IQ10((0.25*PI));           //test IQmathlib
			
	
			theta=_IQ(145.25);    


			
			tbl_out=_IQsqrt(theta);
	
			
			
//			tbl_out=_IQsin(theta);
//  			tbl_out=_IQcos(theta);
//			
			
	
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




