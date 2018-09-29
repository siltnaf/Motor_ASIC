#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "ISD51.H"




void InitEXT(void)
{	
//		EINT1_EN=0; 
//		EINT2_EN=1;				//enable EXT2
//		EINT3_EN=0;
//		EINT4_EN=0;
	
			EXINT_EN = 0x02;					//RXINT_EN cannot be read, it can be write only
																//EXINT_EN= 0x01      -----enable EXT1
																//					0x02			-----enable EXT2
																//					0x04		  -----enable EXT3
																//					0x08			-----enable EXT4
	
		EINT2_CFG=RISING_EDGE;		//rising edge trigger
		EX0=1;
		IT0=1;
		IE0=0;
		INT_REG1 &=0xf0;
	
}

void InitISDDebug(void)
{
	
    EAL = 0;
    //ISD51++++++++++++++++++++++++++
    #if ISDDebug == ENABLE_ISD
		InitBreakPoint();
    sInitUART1();
 
    IP0 = 0x30;
    IP1 = 0x20;
    ET0 = 0;
    EX6 = 0 ;
    ES0 = 1;
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
		EAL = 1;                                //enable all interrupts
}





void InitBreakPoint  (void)
{
    BPCTRL   = 0x01;
	BREAKL   = 0xff;
	BREAKH   = 0xff;
}

void epwmOutputDisable(void)
{
	P1AQCSFRC = 0x05;						// force epwmxA and epwmxB output low
	P2AQCSFRC = 0x05;
	P3AQCSFRC = 0x05;
	P4AQCSFRC = 0x05;
}

void epwmOutputEnable(void)
{
	P1AQCSFRC = 0x0F;						// software force disable
	P2AQCSFRC = 0x0F;
	P3AQCSFRC = 0x0F;
	P4AQCSFRC = 0x0F;
}

void InitADC(void)
{

		AD_PD = 0;							//Power up ADD
	  ADC_CLK_EN=1;
		ADC_CLK_DIV_SEL=0x03;    //system divided by 4
    ADCHS = BIT_3;						// select channel CH4
		DAC1_PD = 1;						// DAC12 down
		DAC2_PD = 1;
		LDO25_PD=0;             //use internal 2.5V for AD VREF
		BP4=1;                  //CH4 bypass sample and hold
		BP5=1; 									//CH5 bypass sample and hold
		BP6=1;			            //CH6 bypass sample and hold
		INTEN=1;								//enable interrupt
		SWFTRG=1;								//start AD conversion
		AD4OST_H=0xFC;					//AD offset 
		AD4OST_L=0x00;					//AD offset
	
	
		EADC=1;
		IADC=0;

	}


void Initepwm(void)
{
	P2_FN_H = 0x55;							// p2_4 ~ p2_7 as pwm2x ~ pwm1x
	P2_FN_L = P2_FN_L & 0x0F | 0x50;		// p2_2 ~ p2_3 as pwm3x
	//P0_FN_L = P0_FN_L & 0xF0 | 0x05;		  // p0_0 ~ p0_1 as pwm4x

//	P1TBPRD_L = 0x90;						// pwm period is 10KHz
//	P1TBPRD_H = 0x01;
//	P2TBPRD_L = 0x90;
//	P2TBPRD_H = 0x01;
//	P3TBPRD_L = 0x90;
//	P3TBPRD_H = 0x01;
//	P4TBPRD_L = 0x90;
//	P4TBPRD_H = 0x01;

	PCLKCR = 0x1E;//0x1F							// clock for pwm1 ~ pwm4 is enable,and synchronize all channel disable
//	PSYNCICR = 0x3C;//0x1F;						// all synchronize input enable

	P1TBCTL_L = 0x02;//0x12;						// period load from shadow,up down mode,synchronize at CTR = ZERO
	P1TBCTL_H = 0x80;						// time base free run when emulation
	P2TBCTL_L = 0x02;//0x12;
	P2TBCTL_H = 0x80;
	P3TBCTL_L = 0x02;//0x12;
	P3TBCTL_H = 0x80;
	P4TBCTL_L = 0x02;//0x12;
	P4TBCTL_H = 0x80;

//	P1TBCTL_L = 0x00;						// period load from shadow,up mode
//	P1TBCTL_H = 0x80;
//	P2TBCTL_L = 0x00;
//	P2TBCTL_H = 0x80;
//	P3TBCTL_L = 0x00;
//	P3TBCTL_H = 0x80;
//	P4TBCTL_L = 0x00;
//	P4TBCTL_H = 0x80;

	P1CMPCTL = 0x00;						// shadow on,update at CTR = ZERO
	P2CMPCTL = 0x00;
	P3CMPCTL = 0x00;
	P4CMPCTL = 0x00;
	P1AQCTLA_L = 0x60;						// when cmpA,count up is set,count down is clear
	P1AQCTLA_H = 0x00;						// when cmpB pwmxA do nothing
	P2AQCTLA_L = 0x60;
	P2AQCTLA_H = 0x00;
	P3AQCTLA_L = 0x60;
	P3AQCTLA_H = 0x00;
	P4AQCTLA_L = 0x60;
	P4AQCTLA_H = 0x00;
	P1AQCTLB_L = 0x00;//0x60;
	P1AQCTLB_H = 0x00;
	P2AQCTLB_L = 0x00;//0x60;
	P2AQCTLB_H = 0x00;
	P3AQCTLB_L = 0x00;//0x60;
	P3AQCTLB_H = 0x00;
	P4AQCTLB_L = 0x00;//0x60;
	P4AQCTLB_H = 0x00;

//	P1AQCTLA_L = 0x12;							// CTR = ZERO set,CTR = CMPA up clear,CTR = PRD nothing,CTR = CMPA down nothing
//	P1AQCTLA_H = 0x00;							// when cmpB pwmxA do nothing
//	P1AQCTLB_L = 0x02;							// CTR = ZERO set,CTR = CMPA up nothing,CTR = PRD nothing,CTR = CMPA down nothing
//	P1AQCTLB_H = 0x01;							// CTR = CMPB clear
//	P2AQCTLA_L = 0x12;
//	P2AQCTLA_H = 0x00;
//	P2AQCTLB_L = 0x02;
//	P2AQCTLB_H = 0x01;
//	P3AQCTLA_L = 0x12;
//	P3AQCTLA_H = 0x00;
//	P3AQCTLB_L = 0x02;
//	P3AQCTLB_H = 0x01;
//	P4AQCTLA_L = 0x12;
//	P4AQCTLA_H = 0x00;
//	P4AQCTLB_L = 0x02;
//	P4AQCTLB_H = 0x01;

	P1DBCTL = 0x0B;							// delay source is epwmxA,dead band full,epwmxB invert
	P2DBCTL = 0x0B;
	P3DBCTL = 0x0B;
	P4DBCTL = 0x0B;
//	P1DBCTL = 0x07;							// delay source is epwmxA,dead band full,epwmxA invert
//	P2DBCTL = 0x07;
//	P3DBCTL = 0x07;
//	P4DBCTL = 0x07;
	P1DBRED_L = 0x32;//0x0A						// rise edge dead time is 1.25uS
	P1DBRED_H = 0x00;
	P2DBRED_L = 0x32;
	P2DBRED_H = 0x00;
	P3DBRED_L = 0x32;
	P3DBRED_H = 0x00;
	P4DBRED_L = 0x32;
	P4DBRED_H = 0x00;
	P1DBFED_L = 0x32;						// fall edge dead time is 1.25uS
	P1DBFED_H = 0x00;
	P2DBFED_L = 0x32;
	P2DBFED_H = 0x00;
	P3DBFED_L = 0x32;
	P3DBFED_H = 0x00;
	P4DBFED_L = 0x32;
	P4DBFED_H = 0x00;

//	P1DBCTL = 0x00;							// dead band is bypass
//	P2DBCTL = 0x00;
//	P3DBCTL = 0x00;
//	P4DBCTL = 0x00;

	P1TZSEL = 0x00;							// disable all trigger zone
	P2TZSEL = 0x00;
	P3TZSEL = 0x00;
	P4TZSEL = 0x00;
	P1TZCTL = 0x00;							// when trigger,epwmxA and epwmxB high impedance
	P2TZCTL = 0x00;
	P3TZCTL = 0x00;
	P4TZCTL = 0x00;
//	P1TZEINT = 0x00;						// CBC trigger interrupt and OST interrupt disable
//	P2TZEINT = 0x00;
//	P3TZEINT = 0x00;
//	P4TZEINT = 0x00;

//	P1TZSEL = 0x01;							// OSHT enable
//	P2TZSEL = 0x01;
//	P3TZSEL = 0x01;
//	P4TZSEL = 0x01;
//	P1TZCTL = 0x00;							// when trigger,epwmxA and epwmxB high impedance
//	P2TZCTL = 0x00;
//	P3TZCTL = 0x00;
//	P4TZCTL = 0x00;
//	P1TZEINT = 0x00;						// CBC trigger interrupt and OST interrupt disable
//	P2TZEINT = 0x00;
//	P3TZEINT = 0x00;
//	P4TZEINT = 0x00;

//	P1TZSEL = 0x02;							// CBC enable
//	P2TZSEL = 0x02;
//	P3TZSEL = 0x02;
//	P4TZSEL = 0x02;
//	P1TZCTL = 0x00;							// when trigger,epwmxA and epwmxB high impedance
//	P2TZCTL = 0x00;
//	P3TZCTL = 0x00;
//	P4TZCTL = 0x00;
//	P1TZEINT = 0x00;						// CBC trigger interrupt and OST interrupt disable
//	P2TZEINT = 0x00;
//	P3TZEINT = 0x00;
//	P4TZEINT = 0x00;

	P1ETSEL_L = 0x09;						// epwm interrupt enable at CTR = ZERO
    P1ETSEL_H = 0x0C;//0xE0;//0xA0;//0x90;//0x0A;//0x09;                       // enable SOCA,SOCA is CTR = ZERO
	P2ETSEL_L = 0x00;
	P2ETSEL_H = 0x00;//0xF0;//0x00;
	P3ETSEL_L = 0x00;
	P3ETSEL_H = 0x00;
	P4ETSEL_L = 0x00;
	P4ETSEL_H = 0x00;
	P1ETPS_L = 0x05;						// 1 event 1 interrupt
    P1ETPS_H = 0x05;//0x50;//0x05;                        // 1 evnt,SOCA period is 1
	P2ETPS_L = 0x00;
    P2ETPS_H = 0x00;//0x50;
	P3ETPS_L = 0x00;
	P4ETPS_L = 0x00;

	P1TBPRD_L = 0xD0;						// pwm period is 0x0190@8MHz 10KHz 0x7D0@40MHz
	P1TBPRD_H = 0x07;
	P2TBPRD_L = 0xD0;
	P2TBPRD_H = 0x07;
	P3TBPRD_L = 0xD0;
	P3TBPRD_H = 0x07;
	P4TBPRD_L = 0xD0;
	P4TBPRD_H = 0x07;

//	P1TBPRD_L = 0x1F;						// pwm period is 10KHz
//	P1TBPRD_H = 0x03;
//	P2TBPRD_L = 0x1F;
//	P2TBPRD_H = 0x03;
//	P3TBPRD_L = 0x1F;
//	P3TBPRD_H = 0x03;
//	P4TBPRD_L = 0x1F;
//	P4TBPRD_H = 0x03;

	P1CMPA_L = 0xE8;						// pwm period is 0x0C8@8MHz 10KHz
	P1CMPA_H = 0x03;
	//P1CMPB_L = 0xC8;
	//P1CMPB_H = 0x00;
	P2CMPA_L = 0xE8;
	P2CMPA_H = 0x03;
	//P2CMPB_L = 0xC8;
	//P2CMPB_H = 0x00;
	P3CMPA_L = 0xE8;
	P3CMPA_H = 0x03;
	//P3CMPB_L = 0xC8;
	//P3CMPB_H = 0x00;
	P4CMPA_L = 0xE8;
	P4CMPA_H = 0x03;
	//P4CMPB_L = 0xC8;
	//P4CMPB_H = 0x00;

//	P1CMPA_L = 0xF4;						// pwm period is 0x0C8@8MHz 10KHz
//	P1CMPA_H = 0x01;
//	P1CMPB_L = 0xEE;
//	P1CMPB_H = 0x02;
//	P2CMPA_L = 0xE8;
//	P2CMPA_H = 0x03;
//	P2CMPB_L = 0xE2;
//	P2CMPB_H = 0x04;
//	P3CMPA_L = 0xDC;
//	P3CMPA_H = 0x05;

//	P1CMPA_L = 0x90;
//	P1CMPA_H = 0x01;
//	P1CMPB_L = 0x90;
//	P1CMPB_H = 0x01;
//	P2CMPA_L = 0x90;
//	P2CMPA_H = 0x01;
//	P2CMPB_L = 0x90;
//	P2CMPB_H = 0x01;
//	P3CMPA_L = 0x90;
//	P3CMPA_H = 0x01;
//	P3CMPB_L = 0x90;
//	P3CMPB_H = 0x01;
//	P4CMPA_L = 0x90;
//	P4CMPA_H = 0x01;
//	P4CMPB_L = 0x90;
//	P4CMPB_H = 0x01;

//	OPAMP_SEL = 0xF0;
//	COMP_INT_EN = COMP_INT_EN | (1 << 0);	// comparator1 interrupt output enable
//	COMP_INT_SET = COMP_INT_SET & 0xFC;		// comparator1 falling edge trigger
//	P1_FN_H = P1_FN_H & 0xF3 | 0x08;		// comp1 output
//	ex1 = 1;								// enable comp1 to CPU interrupt

	PCLKCR = PCLKCR | 1;					// all epwm channel synchronize enable

	P1ETCLR = 1;
	I2FR = 1;
	EX2 = 1;								// enable epwm1,2,3 interrupt
	//ex3 = 1;								// enable epwm4 interrupt
}


void InitComp234(void)
{
	P1_FN_L = P1_FN_L & 0x0F | 0xA0;
	P1_FN_H = P1_FN_H & 0xF0 | 0x0A;
	//COMP_FILTER_1 = 4;
	//COMP_FILTER_2 = 4;
	//COMP_FILTER_3 = 4;
	//COMP_FILTER_4 = 4;
	OPAMP_SEL = 0xF0;
    COMP_INT_SEL = 0xAA;//0;//0x55;                    // comp1 ~ comp4 all trigger at rise egde
	COMP_INT_EN = 0x3E;//0x1E;//0x14;						// comp2,3,4 interrupt enable,and comp2,3,4 to CPU enable
	EX4 = 1;								// external interrupt 4 enable
}



void InitWatchDog(void)
{
		WDTREL = 0xFF;
	WDT = 1;
	SWDT = 1;
    P1_FN_L = P1_FN_L & 0xFC;               //p1_0 as GPIO
    P1_DD = P1_DD & 0xFE;               	//p1_0 as output
}


void InitGPIO(void)
{
		P0_FN_L = 0x00;									// P00 ~ P03as GPIO
		P0_FN_H = 0x00;									// P04 ~ P07 as GPIO
		P0_DD = 0x00;										// 	P00 ~  P07 intput
		P0_PE = 0xFF;										// output resistor enable	
		P0_DS = 0x00;										//drive current =4mA
		P0_PS=	0x00;										//pull down resistor 
	
		P1_FN_L = 0x00;									// P10 ~ P13 as GPIO
		P1_FN_H = 0x00;									// P14 ~ P17 as GPIO
		P1_DD = 0x00;										// P10 ~ P17 intput
		P1_PE = 0xFF;										// output resistor enable	
		P1_DS = 0x00;										//drive current =4mA
		P1_PS=	0x00;										//pull down resistor 
	
		P2_FN_L = 0x00;									// P20 ~ P23 as GPIO
		P2_FN_H = 0x00;									// P24 ~ P27 as GPIO
		P2_DD = 0x00;										// P20~ P27 intput
		P2_PE = 0xFF;										// pull/down resistor enable	
		P2_DS = 0x00;										//drive current =4mA
		P2_PS=	0x00;										//pull down resistor 
	
	// use P26 and P00 as output
	
    P00_FN= CFG0;              	 // P00 as GPIO
    P00_DD = OUTPUT;               //P00 as output
    P00_PE = RES_DIS;               //P00 pull resistor off
		P00_DS = I_4MA;

    P26_FN = CFG0;               //P26 as GPIO
    P26_DD = OUTPUT;               //P26 as output
    P26_PE = RES_DIS;               //P26 output resistor off
		P26_DS = I_4MA;

	
	
	
	// use P20 as EXT2
	
	    P20_FN= CFG1;              	 //P20 as EXT2
			P20_DD = INPUT;               //P20 as input
			P20_PE = RES_EN;               // P20 output resistor enable
			P20_PS = PULL_DOWN;               //P20 with pull down resistor
	
		hh=P2_FN_L|0x0;
	
}

void InitTimer01(void)
{
		T01_DIV = 0x0240;                 //clock divider is 122
    TMOD = TMOD & 0xF0 | (3 << 0);                     //timer0 is 16bit timer
    TL0 = 0x00;
    TH0= 0x00;
		
    ET0 = 1;                                //enable timer0 overflow interrupt
    ET1 = 1;                                //enable timer1 overflow interrupt
		TR0= 1;                                //start timer0
		TR1 = 1;    
}

void InitTimer3(void)
{
	T3PS = 0;								// no divider
	T3RC= 0x00C0;

	T3TF_EINT	 =1;							// timer4 overflow interrupt enable
	T3TR = 1;				// start timer4
	CLR_T3_INT();
	IE1=0;
	 EX1=1;
}

void InitTimer4(void)
{
	T4PS = 0;								// no divider
	T4RC = 0xE0C0;

	T4TF_EINT	 =1;							// timer4 overflow interrupt enable
	T4TR = 1;				// start timer4
	CLR_T4_INT();
	EX6 = 1;
	IEX6=0;
}
void InitTimer5(void)
{
	T5PS = 0;											// no divider
	T5RC = 0x10C0;
	
	T5TF_EINT	 =1;								// timer4 overflow interrupt enable
	T5TR = 1;											// start timer4
	T5TF=0;												// clear interrupt flag

	
	I3FR=1;
	EX3 = 1;
	IEX3=0;
}
void InitTimer6(void)
{
	T6PS = 0;											// no divider
	T6RC = 0x10C0;
	
	T6TF_EINT	 =1;							// timer4 overflow interrupt enable
	T6TR = 1;										// start timer4
	T6TF=0;											// clear interrupt flag

	

	EX5 = 1;
	IEX5=0;
}
void SystemClock(void)
{
    RC80M_RES = 0x2e;
	  #pragma asm
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		#pragma endasm
	
	  CLK_DIV_L = 0x02;
	  CLK_DIV_H = 0x00;
		
		#pragma asm
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		#pragma endasm
}



//initial UART1, there are 2 different ways to generate baudrate
//way 1
void sInitUART1(void)
{
	S0CON  = 0x50;		      // set as 8-bit UART,  enable serial 0 reception, enable serial 0 multiprocessor function
    WDCON = 0x80;            // 0x80: baud rate = (2^smod) * Fclk / (64 * (2^10 - s0rel));
                              // 0x00: baud rate = (2^smod) * Fclk / (32 * 12 * (256 - th1));
                              // smod = 0;	Fclk = system clock
    S0RELL = 0xF3;             //Fclk = 8MHz, baud rate = 9600
    S0RELH = 0x03;	
}

void sInitUART2(void)
{
    S1CON  = 0x90;		        //enable serial 1 reception, enable serial 0 multiprocessor function
                                //s1con.7 = 1: 8-bit UART(mode B)    s1con.7 = 0: 9-bit UART(mode A)
    S1RELL = 0xE6;            //baud rate = Fclk / (32 * (2^10 - s0rel));
    S1RELH = 0x03;	          //Fclk = 8MHz, baud rate = 9600
}
