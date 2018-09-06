#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "typedef.h"
#include "ISD51.H"

#pragma mdu_r515


Long_Data LD;

unsigned char ubP0,ubP1,ubP2,k;
unsigned int X,Y,Z;
unsigned long ulZ,ulC,ulD;

unsigned int uX,uY,uZ;

unsigned char ubABC;





//volatile unsigned char code reserved[256] _at_ 0x2003;

int xdata  swADCResult8     _at_ 0xe06c;
int swADCResultA8 = 0;

//ISD51++++++++++++++++++++++++++
#if ISDDebug == ENABLE_ISD

void InitBreakPoint();

#endif
//++++++++++++++++++++++++++++++
//sfr16 P1TBCTL = 0xa0;
unsigned int AA;


void main(void)
{


    #if ISDDebug == DISABLE_ISD
    sSystemClockConfig();
    #endif
//    EAL = 0;
    //ISD51++++++++++++++++++++++++++
    #if ISDDebug == ENABLE_ISD
    sInitUART1();
    InitBreakPoint();
    IP0 = 0x30;
    IP1 = 0x20;
    ET0 = 0;
    EX6 = 0 ;
    //es0 = 1;
		ES = 1;
    EAL = 1;
    _nop_();
    _nop_();
    _nop_();
    while(1)
    {
        P10 = 0;
        P10 = 1;
        ISDcheck();      // initialize uVision2 Debugger and continue program run
        if((BPCTRL & 0x10) != 0) break;
    }
    _nop_();
    _nop_();
    _nop_();
    ET0 = 1;
    EX6 = 1;
    _nop_();
    _nop_();
    _nop_();
    #endif
    //++++++++++++++++++++++++++++++
    EAL = 1;    //enable all interrupts
		T01_CLK_DIV=0x0190;
	
   AA=XWORD[23];

	InitGPIO();
	
  InitADC();
  


while(1)
    {
        #if ISDDebug == ENABLE_ISD
        ISDcheck();      // initialize uVision2 Debugger and continue program run
        #endif
		
    }
}












