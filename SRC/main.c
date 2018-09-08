#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "typedef.h"
#include "ISD51.H"

#pragma mdu_r515








//ISD51++++++++++++++++++++++++++
#if ISDDebug == ENABLE_ISD

void InitBreakPoint();

#endif
//++++++++++++++++++++++++++++++



void main(void)
{


    #if ISDDebug == DISABLE_ISD
    sSystemClockConfig();
    #endif

    //ISD51++++++++++++++++++++++++++
    #if ISDDebug == ENABLE_ISD
    sInitUART1();
    InitBreakPoint();
    IP0 = 0x30;
    IP1 = 0x20;
    DISABLE_TIMER0_INTERRUPT();
		DISABLE_HARDWARE_BREAKPOINT_INTERRUPT();
		ENABLE_SERIAL_INTERRUPT();	
		ENABLE_ALL_INTERRUPT();
    _nop_();
    _nop_();
    _nop_();
    while(1)
    {
       
        ISDcheck();      // initialize uVision2 Debugger and continue program run
        if((BPCTRL & 0x10) != 0) break;
    }
    _nop_();
    _nop_();
    _nop_();
    ENABLE_TIMER0_INTERRUPT();
		ENABLE_HARDWARE_BREAKPOINT_INTERRUPT();
    _nop_();
    _nop_();
    _nop_();
    #endif
    //++++++++++++++++++++++++++++++


		T01_CLK_DIV=0x0190;
	
//   AA=XWORD[23];

	InitGPIO();
  InitADC();
  
		EXINT_EN=0x01;
		ENABLE_GPIO_INTERRUPT();
		ENABLE_ALL_INTERRUPT();    //enable all interrupts

while(1)
    {
P00=~P00;
			
			
        #if ISDDebug == ENABLE_ISD
        ISDcheck();      // initialize uVision2 Debugger and continue program run
        #endif
		
    }
}












