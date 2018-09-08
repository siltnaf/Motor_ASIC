#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"

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
    unsigned char i;
    //unsigned short j;

    OPAMP_SEL = 0x0F;
    ADC_ISEL = 0x05;
    ADC_CLK_CTRL = 0x03;
    LDO_CON |= 1 << 1;
    //for(j = 0;j < 2500;j++);
    ADCHS = 0x40;
//    ADCHS = 0x07;//0x38;//0x02;//0x20;//0x10;//0x08;//0x38;//0x18;//0x08;                           // select channel 4
//    ADSHBP = 0x00;//0x38;                          // ADC channel 4,5,6 S/H bypass
//    AD1OST_L = 0x00;
//    AD1OST_H = 0xFC;//0x04;
//    AD2OST_L = 0x00;
//    AD2OST_H = 0xFC;//0x04;
//    AD3OST_L = 0x00;
//    AD3OST_H = 0xFC;//0x04;
//    AD4OST_L = 0x00;
//    AD4OST_H = 0xFC;//0x04;
//    AD5OST_L = 0x00;
//    AD5OST_H = 0xFC;//0x04;
//    AD6OST_L = 0x00;
//    AD6OST_H = 0xFC;//0x04;
    //AD7OST_L = 0x00;
    //AD7OST_H = 0x04;
    i = ADFLG;
    IADC = 0;
    ADCTL = 0x01;                           // select software force trigger and enable ADC INT
    //ADCTL = 0x09;//0x11;                           // select epwm soca and enable ADC INT
    EADC = 1;
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
	PSYNCICR = 0x3C;//0x1F;						// all synchronize input enable

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

void InitLED(void)
{
	P0_FN_L = 0x00;															// p0_0 ~ p0_3 as GPIO
	P0_FN_H = 0x00;															// p0_4 ~ p0_7 as GPIO
	P1_FN_L = 0x00;															// p1_0 ~ p1_3 as GPIO
	P1_FN_H = 0x00;															// p1_4 ~ p1_7 as GPIO
	P0_DD = P0_DD | (1 << 3) | (1 << 6) | (1 << 7);							// p0_0 ~ p0_7 output
	P1_DD = P1_DD | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);				// p1_0 ~ p1_7 output
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
	P0_FN_L = 0x00;							// p0_0 ~ p0_3 as GPIO
	P0_FN_H = 0x00;							// p0_4 ~ p0_7 as GPIO
	
	P2_FN_L=0x04;	
	P2_DD=0X00;          		//P21 as EXT1
	
//	P1_FN_L = 0x00;							// p1_0 ~ p1_3 as GPIO
//	P1_FN_H = 0x00;							// p1_4 ~ p1_7 as GPIO
//	P2_FN_L = 0x00;							// p2_0 ~ p2_3 as GPIO
//	P2_FN_H = 0x00;							// p2_4 ~ p2_7 as GPIO
//	P0_DD = 0x00;							// p0_0 ~ p0_7 input
//	P1_DD = 0x00;							// p1_0 ~ p1_7 input
//	P2_DD = 0x00;							// p2_0 ~ p2_7 input
	P0_DD = 0xFF;							// p0_0 ~ p0_7 output
//	P1_DD = 0xFF;							// p1_0 ~ p1_7 output
//	P2_DD = 0xFF;							// p2_0 ~ p2_7 output
	P0_DS = 0xFF;
//	P1_DS = 0xFF;
//	P2_DS = 0xFF;
	//P0 = 0xFF;
	//p0 = 0xFF;
	//P1 = 0xFF;
	//p1 = 0xFF;
	//P2 = 0xFF;
	//p2 = 0xFF;
	P0_PE = 0xFF;							// pull enable
//	P1_PE = 0xFF;							// pull enable
//	P1_PE = 0xFF;							// pull enable
//	P0_PS = 0x00;							// pull down
//	P1_PS = 0x00;							// pull down
//	P2_PS = 0x00;							// pull down
	P0_PS = 0xFF;							// pull up
//	P1_PS = 0xFF;							// pull up
//	P2_PS = 0xFF;							// pull up
}

void InitTimer3(void)
{
	T3PS = 0;								// no divider
	T3RC_L = 0xC0;
	T3RC_H = 0xE0;
	T3CON = 0x20;//0x29;//0x28;							// capture mode,timer3 overflow interrupt enable
	T3CON = T3CON | (1 << 2);				// start timer3
	EX1 = 1;
}

void sSystemClockConfig(void)
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
