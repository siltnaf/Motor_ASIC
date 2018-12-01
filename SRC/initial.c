#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"
#include "ISD51.H"
#include "epwm.h"




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
    ADCHS = 0x0f;						// select channel CH1-CH4
		
	
	
		DAC1_PD = 1;						// DAC12 down
		DAC2_PD = 1;
	
	
	
		C1PDO1PD=CFG2;								//COMP1 power off and OP1 power on
		C2PDO2PD=CFG2;								//COMP2 power off and OP2 power on
		C3PDO3PD=CFG2;								//COMP3 power off and OP3 power on
	
	
		LDO25_PD=0;             //use internal 2.5V for AD VREF
		BP4=0;                  //CH4 normal and no bypass
	
		SWFTRG=1;
	  INTEN=1;
		AD4OST=0x0000;					//AD offset   0xFC

	
	
		EADC=1;
		IADC=0;

	}


void Initepwm(void)
{
	
	
	// config IO for ePWM output

	P22_FN=CFG1;          //P22 output  PWM3B
	P23_FN=CFG1;					//P23 output  PWM3A
	
	P24_FN=CFG1;          //P24 output  PWM2B
	P25_FN=CFG1;					//P25 output  PWM2A
	
	P26_FN=CFG1;					//P26 output  PWM1B
	P27_FN=CFG1;          //P27 output  PWM1A
	
//	P00_FN=CFG1;					//P00 output  PWM4B
//  P01_FN=CFG1;          //P01 output  PWM4A	


// set period	

	P1TBPRD	=	0x0190;						// 400 step per pwm period or 10KHz
	P2TBPRD = 0x0190;
	P3TBPRD = 0x0190;
	P4TBPRD = 0x0190;

	
//enable epwm clock 
	
	
	EPWM1_ENCLK =1;							// clock for pwm1 ~ pwm4 is enable,and synchronize all channel disable
	EPWM2_ENCLK	=1;
	EPWM3_ENCLK =1;
	EPWM4_ENCLK =1;
	TBCLKSYNC=0;
	
	
	//pwm count up or down
	
	P1CTRMODE=TB_COUNT_UPDOWN;     // period load from shadow,up down mode,synchronize at CTR = ZERO
	P2CTRMODE=TB_COUNT_UPDOWN;
	P3CTRMODE=TB_COUNT_UPDOWN;
	P4CTRMODE=TB_COUNT_UPDOWN;
	
	
	P1PRDLD=TB_SHADOW;
	
	
	//time base free run or emulation 
	
	P1FREE_SOFT=FREE_RUN;							// time base free run when emulation
	P2FREE_SOFT=FREE_RUN;
	P3FREE_SOFT=FREE_RUN;
	P4FREE_SOFT=FREE_RUN;

// shadow register load mode


	P1SHDWA_MODE = CC_SHADOW;;						// shadow on,update at CTR = ZERO
	P1SHDWB_MODE = CC_SHADOW;
	P1LOADA_MODE = CC_CTR_ZERO;
	P1LOADB_MODE = CC_CTR_ZERO;
	
	P2SHDWA_MODE = CC_SHADOW;;						// shadow on,update at CTR = ZERO
	P2SHDWB_MODE = CC_SHADOW;
	P2LOADA_MODE = CC_CTR_ZERO;
	P2LOADB_MODE = CC_CTR_ZERO;
	
	P3SHDWA_MODE = CC_SHADOW;;						// shadow on,update at CTR = ZERO
	P3SHDWB_MODE = CC_SHADOW;
	P3LOADA_MODE = CC_CTR_ZERO;
	P3LOADB_MODE = CC_CTR_ZERO;
	
	P4SHDWA_MODE = CC_SHADOW;;						// shadow on,update at CTR = ZERO
	P4SHDWB_MODE = CC_SHADOW;
	P4LOADA_MODE = CC_CTR_ZERO;
	P4LOADB_MODE = CC_CTR_ZERO;
	
	
	
	//PWMxA waveform counter condition
	// when counter count up to cmpA value, PWMxA output is set high, when counter count down to cmpA value, PWMxA output is clear
	// when cmpB is disable 
	
	P1CADA=AQ_CLEAR;                    
	P1CAUA=AQ_SET;
	P1CBDA=AQ_NO_ACTION;                
	P1CBUA=AQ_NO_ACTION;
	P1PRDA=AQ_NO_ACTION;
	P1ZROA=AQ_NO_ACTION;
	
	P2CADA=AQ_CLEAR;                    
	P2CAUA=AQ_SET;
	P2CBDA=AQ_NO_ACTION;               	 
	P2CBUA=AQ_NO_ACTION;
	P2PRDA=AQ_NO_ACTION;
	P2ZROA=AQ_NO_ACTION;
	
	
	P3CADA=AQ_CLEAR;                     
	P3CAUA=AQ_SET;
	P3CBDA=AQ_NO_ACTION;               	   
	P3CBUA=AQ_NO_ACTION;
	P3PRDA=AQ_NO_ACTION;
	P3ZROA=AQ_NO_ACTION;
	
	
	P4CADA=AQ_CLEAR;                     
	P4CAUA=AQ_SET;
	P4CBDA=AQ_NO_ACTION;                
	P4CBUA=AQ_NO_ACTION;
	P4PRDA=AQ_NO_ACTION;
	P4ZROA=AQ_NO_ACTION;
	
	
	

//	P1ZROA = AQ_SET;							 // CTR = ZERO set,CTR = CMPA up clear,CTR = PRD nothing,CTR = CMPA down nothing
//  P1CAUA = AQ_CLEAR;
//  P1PRDA = AQ_NO_ACTION;
//  P1CADA = AQ_NO_ACTION;
//  P1CBDA = AQ_NO_ACTION;         // when cmpB pwmxA do nothing
//  P1CBUA = AQ_NO_ACTION;


//	P1ZROA = AQ_SET;							
//	P1CAUA = AQ_NO_ACTION;							// CTR = ZERO set,CTR = CMPA up nothing,CTR = PRD nothing,CTR = CMPA down nothing
//  P1PRDA = AQ_NO_ACTION;
//  P!CADA = AQ_NO_ACTION;
//	P1CBUA = AQ_CLEAR;		   					// CTR increment upto CMPB  then clear PWMxA output
//  P1CBDA = AQ_NO_ACTION;
;


	//PWMxB waveform counter condition , PWMxB can be use seperately by setting P1OUT_MODE=DB_DISABLE
	// when counter count up to cmpA value, PWMxB output is clear, when counter count down to cmpA value, PWMxB output is set,  PWMxB is complement of PWMxA
	// when cmpB is disable 
	
//	P1CADB=AQ_SET;                    
//	P1CAUB=AQ_CLEAR;
//	P1CBDB=AQ_NO_ACTION;                
//	P1CBUB=AQ_NO_ACTION;
//	P1PRDB=AQ_NO_ACTION;
//	P1ZROB=AQ_NO_ACTION;
	

//Dead band generator control enable and set dead band time


  P1OUT_MODE=DB_FULL_ENABLE;   // output is dead band full enable, rising edge delay on PWMxA and falling edge delay on PWMxB
  P1POLSEL=DB_ACTV_HIC;        //PWMxB is inverted or active high complement
  P1IN_MODE=DB_AUAD;           // rising edge delay source from epwmxA, falling edge delay source from epwmxA,

  P2OUT_MODE=DB_FULL_ENABLE;   // output is dead band full enable, rising edge delay on PWMxA and falling edge delay on PWMxB
  P2POLSEL=DB_ACTV_HIC;        //PWMxB is inverted or active high complement
  P2IN_MODE=DB_AUAD;           // rising edge delay source from epwmxA, falling edge delay source from epwmxA,

  P3OUT_MODE=DB_FULL_ENABLE;   // output is dead band full enable, rising edge delay on PWMxA and falling edge delay on PWMxB
  P3POLSEL=DB_ACTV_HIC;        //PWMxB is inverted or active high complement
  P3IN_MODE=DB_AUAD;           // rising edge delay source from epwmxA, falling edge delay source from epwmxA,

  P4OUT_MODE=DB_FULL_ENABLE;   // output is dead band full enable, rising edge delay on PWMxA and falling edge delay on PWMxB
  P4POLSEL=DB_ACTV_HIC;        //PWMxB is inverted or active high complement
  P4IN_MODE=DB_AUAD;           // rising edge delay source from epwmxA, falling edge delay source from epwmxA,



//	P1OUT_MODE=DB_FULL_ENABLE; 							// delay source is epwmxA,dead band full,epwmxA invert
//	P1POLSEL=DB_ACTV_LOC;
//	P1IN_MODE=DB_AUAD;
 



  P1DBRED = 0x0032;//0x0A						// rise edge dead time is 1.25uS
	P2DBRED = 0x0032;
	P3DBRED = 0x0032;
	P4DBRED = 0x0032;
	
	P1DBFED = 0x0032;               // fall edge dead time is 1.25uS
  P2DBFED = 0x0032;
  P3DBFED = 0x0032;
  P4DBFED = 0x0032;


//	 P1OUT_MODE=DB_DISABLE;						// dead band is bypass
//	 P2OUT_MODE=DB_DISABLE;		
//	 P3OUT_MODE=DB_DISABLE;		
//	 P4OUT_MODE=DB_DISABLE;		



// trip zone control: OSHT ---for one time; CBC for cycle by cycle

	P1TZ_OSHT =	TZ_ENABLE;			// OSHT enable
	P1TZ_CBC =   TZ_DISABLE;
	
 	P2TZ_OSHT =	TZ_ENABLE;				// OSHT enable
	P2TZ_CBC =   TZ_DISABLE;
	
	P3TZ_OSHT =	TZ_ENABLE;				// OSHT enable
	P3TZ_CBC =   TZ_DISABLE;
	
	P4TZ_OSHT =	TZ_ENABLE;				// OSHT enable
	P4TZ_CBC =   TZ_DISABLE;
	
	P1TZA=TZ_HIZ;              // when trigger,epwmxA high impedance
	P1TZB=TZ_HIZ;              // when trigger,epwmxB high impedance
	
	P2TZA=TZ_HIZ;              // when trigger,epwmxA high impedance
	P2TZB=TZ_HIZ;              // when trigger,epwmxB high impedance
	
	P3TZA=TZ_HIZ;              // when trigger,epwmxA high impedance
	P3TZB=TZ_HIZ;              // when trigger,epwmxB high impedance
	
		
	P4TZA=TZ_HIZ;              // when trigger,epwmxA high impedance
	P4TZB=TZ_HIZ;              // when trigger,epwmxB high impedance
	
	
// trip zone interrupt  ???  no description in datasheet

	
	
	
//	P1TZEINT = 0x00;						// CBC trigger interrupt and OST interrupt disable
//	P2TZEINT = 0x00;
//	P3TZEINT = 0x00;
//	P4TZEINT = 0x00;



//event trigger select 

	P1ET_INTEN=1;							//enable epwmx_INT interrupt
	P1ET_INTSEL=ET_CTR_ZERO;	// epwm interrupt enable at CTR = ZERO
	P1ET_SOCAEN=1;						//enable SOCA pulse
	P1ET_SOCASEL=ET_CTR_ZERO;  // enable SOCA,SOCA is CTR = ZERO
	P1ET_SOCBEN=0 ;						//disable SOCB pulse
	P1ET_SOCBSEL=ET_CTR_ZERO;  // SOCB is CTR = ZERO		
 
	P2ET_INTEN=1;							//enable epwmx_INT interrupt
	P2ET_INTSEL=ET_CTR_ZERO;	// epwm interrupt enable at CTR = ZERO
	P2ET_SOCAEN=1;						//enable SOCA pulse
	P2ET_SOCASEL=ET_CTR_ZERO;  // enable SOCA,SOCA is CTR = ZERO
	P2ET_SOCBEN=0 ;						//disable SOCB pulse
	P2ET_SOCBSEL=ET_CTR_ZERO;  // SOCB is CTR = ZERO		
 
	P3ET_INTEN=1;							//enable epwmx_INT interrupt
	P3ET_INTSEL=ET_CTR_ZERO;	// epwm interrupt enable at CTR = ZERO
	P3ET_SOCAEN=1;						//enable SOCA pulse
	P3ET_SOCASEL=ET_CTR_ZERO;  // enable SOCA,SOCA is CTR = ZERO
	P3ET_SOCBEN=0 ;						//disable SOCB pulse
	P3ET_SOCBSEL=ET_CTR_ZERO;  // SOCB is CTR = ZERO		
 
	P4ET_INTEN=1;							//enable epwmx_INT interrupt
	P4ET_INTSEL=ET_CTR_ZERO;	// epwm interrupt enable at CTR = ZERO
	P4ET_SOCAEN=1;						//enable SOCA pulse
	P4ET_SOCASEL=ET_CTR_ZERO;  // enable SOCA,SOCA is CTR = ZERO
	P4ET_SOCBEN=0 ;						//disable SOCB pulse
	P4ET_SOCBSEL=ET_CTR_ZERO;  // SOCB is CTR = ZERO		
 
 
 
 //event trigger prescaler, generate SOCA and SOCB pulse for AD conversion
 
 P1ET_INTPRD=ET_1ST;	      //generate interrupt on 1st event
 P1ET_INTCNT= ET_1ST;      // event counter period =1
 P1ET_SOCAPRD=ET_1ST;      //generate SOCA pulse on 1at event
 P1ET_SOCACNT=ET_1ST;      // SOCA event counter =1
 P1ET_SOCBPRD=ET_DISABLE;  //SOCB is not used
 P1ET_SOCBCNT=ET_DISABLE;
 
 P2ET_INTPRD=ET_1ST;	      //generate interrupt on 1st event
 P2ET_INTCNT= ET_1ST;      // event counter period =1
 P2ET_SOCAPRD=ET_1ST;      //generate SOCA pulse on 1at event
 P2ET_SOCACNT=ET_1ST;      // SOCA event counter =1
 P2ET_SOCBPRD=ET_DISABLE;  //SOCB is not used
 P2ET_SOCBCNT=ET_DISABLE;
 
 P3ET_INTPRD=ET_1ST;	      //generate interrupt on 1st event
 P3ET_INTCNT= ET_1ST;      // event counter period =1
 P3ET_SOCAPRD=ET_1ST;      //generate SOCA pulse on 1at event
 P3ET_SOCACNT=ET_1ST;      // SOCA event counter =1
 P3ET_SOCBPRD=ET_DISABLE;  //SOCB is not used
 P3ET_SOCBCNT=ET_DISABLE;
      
 P4ET_INTPRD=ET_1ST;	      //generate interrupt on 1st event
 P4ET_INTCNT= ET_1ST;      // event counter period =1
 P4ET_SOCAPRD=ET_1ST;      //generate SOCA pulse on 1at event
 P4ET_SOCACNT=ET_1ST;      // SOCA event counter =1
 P4ET_SOCBPRD=ET_DISABLE;  //SOCB is not used
 P4ET_SOCBCNT=ET_DISABLE;
      




//set PWM period



	P1TBPRD = 0x07D0;						// pwm period is 0x0190@8MHz 10KHz 0x7D0@40MHz; 0x031f?
	P2TBPRD = 0x07D0;
  P3TBPRD = 0x07D0;
  P4TBPRD = 0x07D0;



	P1CMPA = 0x01E8;						// CMPA counter value
	P2CMPA = 0x01E8;
	P3CMPA = 0x01E8;
	P4CMPA = 0x01E8;
	
	P1CMPB = 0x0190;						// CMPA counter value
	P2CMPB = 0x0190;
	P3CMPB = 0x0190;
	P4CMPB = 0x0190;
	
	

	TBCLKSYNC = 1;					// all epwm channel synchronize enable

	CLR_EPWM1_INT();
	CLR_EPWM2_INT();
  CLR_EPWM3_INT();
	CLR_EPWM4_INT();
	
	
	I2FR = 1;                //rising edge triger interrupt
	EX2 = 1;								// enable epwm1,2,3 interrupt
	//ex3 = 1;								// enable epwm4 interrupt
}


void InitComparator(void)
{
	
		P21_FN= CFG2;								 // P21	output COMP1
		P14_FN= CFG2;              	 // P14 output COMP2
		P13_FN= CFG2;              	 // P13 output COMP3
		P12_FN= CFG2;              	 // P12 output COMP4
		
	
	
		C1PDO1PD=CFG1;								//COMP1 power on and OP1 power off
		C2PDO2PD=CFG1;								//COMP2 power on and OP2 power off
		C3PDO3PD=CFG1;								//COMP3 power on and OP3 power off
		C4PD=0;												//COMP4 power on
	
	
	
		C1_INT_SEL=CFG2;							//COMP1 at rising/falling edge triiger 
		C2_INT_SEL=CFG2;							//COMP2 at rising/falling edge triiger
		C3_INT_SEL=CFG2;							//COMP3 at rising/falling edge triiger
		C4_INT_SEL=CFG2;							//COMP4 at rising/falling edge triiger
	
	
		C1_EN=1;											//C1 interrupt enable
		C2_EN=1;											//C2 interrupt enalbe
		C3_EN=1;											//C3 interrupt enalbe
		C4_EN=1;											//C4 interrupt enalbe
		
		
		C1INT=0;											//clear C1 INT flag
		C2INT=0;											//clear C2 INT flag
		C3INT=0;											//clear C3 INT flag
		C4INT=0;											//clear C4 INT flag
	
		INT_CPU=1;                    //pass C234 interrupt to EX4
	
		EX4=1;
		EX1=1;
		IE1=0;
		IEX4=0;
}



void InitWatchDog(void)
{
		WDTREL = 0xFF;
	WDT = 1;
	SWDT = 1;
    P1_FN_L = P1_FN_L & 0xFC;               //p1_0 as GPIO
    P1_DD = P1_DD & 0xFE;               	//p1_0 as output
}




#define GPIO(pin,fn_cfg,in_out,res_en_dis,pull_up_dwn,drive_4_8ma )  FN_##pin=fn_cfg;DD_##pin=in_out;PE_##pin=res_en_dis;PS_##pin=pull_up_dwn;DS_##pin=drive_4_8ma;

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

			
			GPIO(P20,CFG1,INPUT,RES_EN,PULL_DOWN,I_4MA);				//P20 as EXT2
			GPIO(P15,CFG2,INPUT,RES_EN,PULL_DOWN,I_4MA);				//P15 as TIMER3 T_EX
			GPIO(P04,CFG0,OUTPUT,RES_EN,PULL_DOWN,I_4MA);				//use P14 for timer0 ouput to test timer3 capture
			GPIO(P26,CFG0,OUTPUT,RES_DIS,PULL_DOWN,I_4MA);			//P26 for LED indication
	
}

void InitTimer01(void)
{
		T01_DIV_L= 0x05;                 //clock divider is 122, must write T01_DIV_L first;
	  T01_DIV_H= 0x00;                
  	TMOD = 0x10;                   //timer1 is 16bit timer, timer0 is 13 bit
    TL0 = 0x0;
    TH0= 0xfe;
		
		TL1=0x0;
		TH1=0x0;
	
	
    ET0 = 1;                                //enable timer0 overflow interrupt
    ET1 = 1;                                //enable timer1 overflow interrupt
		TR0= 1;                                //start timer0
		TR1 = 1;    
}

void InitTimer3(void)
{
	T3PS = 0;								// no divider
	T3RC= 0;               //reset T3 capture register
	T3CTR=0;               //reset T3 counter
	T3CT=0;                //capture clock from cpu
	T3CPRL=1;             //capture mode select
	T3EXEN=1;             //enable T3 external EX pin
	T3EX_INV=0;           //T3 EX pin ,trigger on rising edge
	T3TF_EINT	 =1;			  // timer3 overflow interrupt enable
	T3TR = 1;				      // start timer3 
	T3TF=0;               //clear T3 overflow flag
	T3EXF=0;              //clear T3 EX trigger flag
	IE1=0;                //clear  EX1 interrupt flag
	 EX1=1;               //enable EX1 interrupt
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
	  RC80M_C2=0x3f;
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
	
	  CLK_DIV_L = 0x00;
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


void InitDAC(void)
{
		DAC1_PD=0;		//power up DAC1
		DAC2_PD=0;		//power up DAC2
	DAC1_VREF=0;		//use 3.3V as vref
	DAC2_VREF=0;		//use 3.3V as vref
	ADC_DAC_SEL1=0; //select DAC output
	ADC_DAC_SEL2=0; //select DAC output
}
