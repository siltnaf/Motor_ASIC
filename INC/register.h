
#ifndef __REGISTER_H__
#define __REGISTER_H__


//- $Id: sfr.adr.unx,v 1.1 1996/07/24 14:17:49 gina Exp $

// ISD hardware breakpoint
sfr BPCTRL = 0x93  ; //BPCTRL.7  := breakpoint interrupt request
                       //       ; BPCTRL.1  := 0=code break, 1=xdata break
                       //       ; BPCTRL.0  := breakpoint enable 
sfr BREAKL = 0x94  ; //break low  address
sfr BREAKH = 0x95  ; //break high address
//

sfr	P0	     = 0x80;
    sbit P00    = P0^0;
    sbit P01    = P0^1;
    sbit P02    = P0^2;
    sbit P03    = P0^3;
    sbit P04    = P0^4;
    sbit P05    = P0^5;
    sbit P06    = P0^6;
    sbit P07    = P0^7;

sfr	SP	     = 0x81;
sfr	DPL	     = 0x82;
sfr	DPH      = 0x83;
sfr	DPL1	   = 0x84;
sfr	DPH1	   = 0x85;
sfr WDTREL	 = 0x86;
sfr	PCON	   = 0x87;
sfr	TCON	   = 0x88;
    sbit IT0     = TCON^0;
    sbit IE0     = TCON^1;
    sbit IT1     = TCON^2;
    sbit IE1     = TCON^3;
    sbit TR0     = TCON^4;
    sbit TF0     = TCON^5;
    sbit TR1     = TCON^6;
    sbit TF1     = TCON^7;
sfr	TMOD	   = 0x89;
sfr	TL0	     = 0x8a;
sfr	TL1	     = 0x8b;
sfr	TH0	     = 0x8c;
sfr	TH1	     = 0x8d;
sfr	CKCON	   = 0x8e;
sfr CLK_PD_CON = 0x8f;
sfr	P1	     = 0x90;
    sbit P10    = P1^0;
    sbit P11    = P1^1;
    sbit P12    = P1^2;
    sbit P13    = P1^3;
    sbit P14    = P1^4;
    sbit P15    = P1^5;
    sbit P16    = P1^6;
    sbit P17    = P1^7;

sfr	CLK_DIV  = 0x91;
sfr	DPS	     = 0x92;
//0x93~0x96 reserve to port0 & port1
sfr	POWER_CON  = 0x97;	  
sfr	S0CON	   = 0x98;
    sbit	RI0    = S0CON^0;
    sbit	TI0    = S0CON^1;
    sbit	RB80   = S0CON^2;
    sbit	TB80   = S0CON^3;
    sbit	REN0   = S0CON^4;
    sbit	SM20   = S0CON^5;
    sbit	SM1    = S0CON^6;
    sbit	SM0    = S0CON^7;

sfr	S0BUF     = 0x99;
sfr IEN2	    = 0x9a;
sfr S1CON	    = 0x9b;
sfr	S1BUF	    = 0x9c;
sfr S1RELL    = 0x9d;
//0x9e reserve to port2
//0x9f reserve to port2
sfr	P2	      = 0xa0;
    sbit P20    = P2^0;
    sbit P21    = P2^1;
    sbit P22    = P2^2;
    sbit P23    = P2^3;
    sbit P24    = P2^4;
    sbit P25    = P2^5;
    sbit P26    = P2^6;
    sbit P27    = P2^7;
//0xa1~0xa7 reserve to PWM1
sfr IEN0	    = 0xa8;
    sbit EX0	   = IEN0^0;
    sbit ET0	   = IEN0^1;
    sbit EX1	   = IEN0^2;
    sbit ET1	   = IEN0^3;
    sbit ES0	   = IEN0^4;
    sbit WDT	   = IEN0^6;
    sbit EAL	   = IEN0^7;

sfr IP0	     = 0xa9;
sfr S0RELL	 = 0xaa;
sfr	BSHCTL 	 = 0xab;
sfr BSHI_0   = 0xac;
sfr BSHI_1   = 0xad;
sfr BSHI_2   = 0xae;
sfr BSHI_3   = 0xaf;
sfr	P3	     = 0xb0;
    sbit P30    = P3^0;
    sbit P31    = P3^1;
    sbit P32    = P3^2;
    sbit P33    = P3^3;
    sbit P34    = P3^4;
    sbit P35    = P3^5;
    sbit P36    = P3^6;
    sbit P37    = P3^7;
//0xb1~0xb7 reserve to PWM1
sfr IEN1	   = 0xb8;
    sbit EADC = IEN1^0;
		sbit EX2  = IEN1^1;
    sbit EX3  = IEN1^2;
    sbit EX4  = IEN1^3;
		sbit EX5  = IEN1^4;
		sbit EX6  = IEN1^5;
		sbit SWDT = IEN1^6;

sfr IP1	     = 0xb9;
sfr S0RELH	 = 0xba;
sfr S1RELH	 = 0xbb;
sfr BSHO_0   = 0xbc;
sfr BSHO_1   = 0xbd;
sfr BSHO_2   = 0xbe;
sfr BSHO_3   = 0xbf;
sfr IRCON	   = 0xc0;
    sbit IADC =IRCON^0;
		sbit IEX2 =IRCON^1;
		sbit iex3 =IRCON^2;
		sbit iex4 =IRCON^3;
		sbit iex5 =IRCON^4;
		sbit iex6 =IRCON^5;
//0xc1~0xc7 reserve to PWM2
sfr	T2CON	   = 0xc8;
    sbit I2FR = T2CON^5;
		sbit I3FR =	T2CON^6;
//0xc9~0xcf reserve to PWM2
sfr	PSW	     = 0xd0;
//0xd1~0xd7 reserve to PWM3
sfr	WDCON    = 0xd8;
    sbit WDCON_7  = WDCON^7;

//0xd9~0xdf reserve to PWM3
sfr	ACC	     = 0xe0;
//0xe1~0xe7 reserve to PWM4
sfr	MEM_CONFIG = 0xe8; //Map8: interrupt enable 1 register 
sfr MD0	     = 0xe9;
sfr MD1	     = 0xea;
sfr MD2	     = 0xeb;
sfr MD3	     = 0xec;
sfr MD4	     = 0xed;
sfr MD5	     = 0xee;
sfr ARCON	   = 0xef;
sfr	B	       = 0xf0;
//0xf1~0xf7 reserve to PWM4
sfr	SRAM_CON = 0xf8;
sfr INT_REG1 = 0xf9;
sfr INT_REG2 = 0xfa;
//0xfb,0xfc reserved by 8051
sfr INT_REG3 = 0xfd;
sfr INT_REG4 = 0xfe;
//0xff reserved by 8051



sbit RI   = 0x98;

sfr SBUF    = 0x99;
sfr IE	    = 0xa8;
    sbit ES	   = IEN0^4;
   
//from - $Id: epwm.adr.asm51,v 1.0 2016/05/18 Eric Chan $



// ePWM1 SFR ==============================================	
sfr16 P1TBPRD = 0xa1;
	sfr	P1TBPRD_L	= 0xa1;
	sfr	P1TBPRD_H	= 0xa2;
sfr16 P1CMPA =0xa3;
	sfr	P1CMPA_L	= 0xa3;
	sfr	P1CMPA_H 	= 0xa4;
sfr16 P1CMPB =0xa5;	
	sfr	P1CMPB_L	= 0xa5;	
	sfr	P1CMPB_H	= 0xa6;		 
sfr	P1AQSFRC	= 0xa7;	
sfr	P1AQCSFRC	= 0xb1;
sfr	P1TZFLG		= 0xb2;
sfr	P1TZCLR		= 0xb3;
sfr	P1TZFRC		= 0xb4;
sfr	P1ETFLG		= 0xb5;
sfr	P1ETCLR		= 0xb6;
sfr	P1ETFRC		= 0xb7;
	
// ePWM2 SFR ==============================================
sfr16 P2TBPRD =0xc1;
	sfr	P2TBPRD_L	= 0xc1;
	sfr	P2TBPRD_H	= 0xc2;
sfr16 P2CMPA=0xc3;
	sfr	P2CMPA_L	= 0xc3;	
	sfr	P2CMPA_H 	= 0xc4;	
sfr16 P2CMPB =0xc5;	
	sfr	P2CMPB_L	= 0xc5;		
	sfr	P2CMPB_H	= 0xc6;		 
sfr	P2AQSFRC	= 0xc7;	
sfr	P2AQCSFRC	= 0xc9;
sfr	P2TZFLG		= 0xca;
sfr	P2TZCLR		= 0xcb;
sfr	P2TZFRC		= 0xcc;
sfr	P2ETFLG		= 0xcd;
sfr	P2ETCLR		= 0xce;
sfr	P2ETFRC		= 0xcf;

// ePWM3 SFR ==============================================
sfr16 P3TBPRD =0xd1;
	sfr	P3TBPRD_L	= 0xd1;
	sfr	P3TBPRD_H	= 0xd2;
sfr16 P3CMPA =0xd3;
	sfr	P3CMPA_L	= 0xd3;	
	sfr	P3CMPA_H 	= 0xd4;		
sfr16 P3CMPB =0xd5;
	sfr	P3CMPB_L	= 0xd5;		
	sfr	P3CMPB_H	= 0xd6;		 
sfr	P3AQSFRC	= 0xd7;	
sfr	P3AQCSFRC	= 0xd9;
sfr	P3TZFLG		= 0xda;
sfr	P3TZCLR		= 0xdb;
sfr	P3TZFRC		= 0xdc;
sfr	P3ETFLG		= 0xdd;
sfr	P3ETCLR		= 0xde;
sfr	P3ETFRC		= 0xdf;		
	
// ePWM4 SFR ==============================================
sfr16 P4TBPRD =0xe1;
	sfr	P4TBPRD_L	= 0xe1;
	sfr	P4TBPRD_H	= 0xe2;
sfr16 P4CMPA =0xe3;
	sfr	P4CMPA_L	= 0xe3;		
	sfr	P4CMPA_H 	= 0xe4;		
sfr16 P4CMPB =0xe5;
	sfr	P4CMPB_L	= 0xe5;		
	sfr	P4CMPB_H	= 0xe6;		 
sfr	P4AQSFRC	= 0xe7;	
sfr	P4AQCSFRC	= 0xf1;
sfr	P4TZFLG		= 0xf2;
sfr	P4TZCLR		= 0xf3;
sfr	P4TZFRC		= 0xf4;
sfr	P4ETFLG		= 0xf5;
sfr	P4ETCLR		= 0xf6;
sfr	P4ETFRC		= 0xf7;

	// ePWM top ext Ram =======================================
	

	
#define PCLKCR   (*(unsigned char volatile xdata *)0xe000)
#define PSYNCICR    (*(unsigned char volatile xdata *)0xe001)
	
// ePWM1 ext Ram ==========================================
#define P1TBCTL    		(*(unsigned int volatile xdata *)0xe002)
#define P1TBCTL_H    	(*(unsigned char volatile xdata *)0xe002)
#define P1TBCTL_L    	(*(unsigned char volatile xdata *)0xe003)
#define P1TBSTS    		(*(unsigned char volatile xdata *)0xe004)
#define P1TBCTR    		(*(unsigned int volatile xdata *)0xe005)	
#define P1TBCTR_H    	(*(unsigned char volatile xdata *)0xe005)
#define P1TBCTR_L    	(*(unsigned char volatile xdata *)0xe006)	
#define P1CMPCTL   		(*(unsigned char volatile xdata *)0xe007)
#define P1AQCTLA    	(*(unsigned int volatile xdata *)0xe008)	
#define P1AQCTLA_H   	(*(unsigned char volatile xdata *)0xe008)
#define P1AQCTLA_L    (*(unsigned char volatile xdata *)0xe009)	
#define P1AQCTLB    	(*(unsigned int volatile xdata *)0xe00a)	
#define P1AQCTLB_H  	(*(unsigned char volatile xdata *)0xe00a)
#define P1AQCTLB_L    (*(unsigned char volatile xdata *)0xe00b)
#define P1DBCTL	  		(*(unsigned char volatile xdata *)0xe00c)	
#define P1DBRED    		(*(unsigned int volatile xdata *)0xe00d)	
#define P1DBRED_H  		(*(unsigned char volatile xdata *)0xe00d)
#define P1DBRED_L    	(*(unsigned char volatile xdata *)0xe00e)
#define P1DBFED    		(*(unsigned int volatile xdata *)0xe00f)	
#define P1DBFED_H  		(*(unsigned char volatile xdata *)0xe00f)
#define P1DBFED_L    	(*(unsigned char volatile xdata *)0xe010)
#define P1TZSEL   		(*(unsigned char volatile xdata *)0xe011)
#define P1TZCTL   		(*(unsigned char volatile xdata *)0xe012)

#define P1ETSEL   		(*(unsigned int volatile xdata *)0xe014)	
#define P1ETSEL_H  		(*(unsigned char volatile xdata *)0xe014)
#define P1ETSEL_L    	(*(unsigned char volatile xdata *)0xe015)
#define P1ETPS   			(*(unsigned int volatile xdata *)0xe016)	
#define P1ETPS_H  		(*(unsigned char volatile xdata *)0xe016)
#define P1ETPS_L    	(*(unsigned char volatile xdata *)0xe017)	


	
// ePWM2 ext Ram ==========================================

#define P2TBCTL   		(*(unsigned int volatile xdata *)0xe018)
#define P2TBCTL_H    	(*(unsigned char volatile xdata *)0xe018)
#define P2TBCTL_L    	(*(unsigned char volatile xdata *)0xe019)
#define P2TBSTS    		(*(unsigned char volatile xdata *)0xe01a)
#define P2TBCTR    		(*(unsigned int volatile xdata *)0xe01b)	
#define P2TBCTR_H    	(*(unsigned char volatile xdata *)0xe01b)
#define P2TBCTR_L    	(*(unsigned char volatile xdata *)0xe01c)	
#define P2CMPCTL   		(*(unsigned char volatile xdata *)0xe01d)
#define P2AQCTLA    	(*(unsigned int volatile xdata *)0xe01e)	
#define P2AQCTLA_H   	(*(unsigned char volatile xdata *)0xe01e)
#define P2AQCTLA_L    (*(unsigned char volatile xdata *)0xe01f)
#define P2AQCTLB    	(*(unsigned int volatile xdata *)0xe020)	
#define P2AQCTLB_H  	(*(unsigned char volatile xdata *)0xe020)
#define P2AQCTLB_L    (*(unsigned char volatile xdata *)0xe021)
#define P2DBCTL	  		(*(unsigned char volatile xdata *)0xe022)
#define P2DBRED    		(*(unsigned int volatile xdata *)0xe023)	
#define P2DBRED_H  		(*(unsigned char volatile xdata *)0xe023)
#define P2DBRED_L    	(*(unsigned char volatile xdata *)0xe024)
#define P2DBFED    		(*(unsigned int volatile xdata *)0xe025)	
#define P2DBFED_H  		(*(unsigned char volatile xdata *)0xe025)
#define P2DBFED_L    	(*(unsigned char volatile xdata *)0xe026)
#define P2TZSEL   		(*(unsigned char volatile xdata *)0xe027)
#define P2TZCTL   		(*(unsigned char volatile xdata *)0xe028)
#define P2ETSEL   		(*(unsigned int volatile xdata *)0xe02a)	
#define P2ETSEL_H  		(*(unsigned char volatile xdata *)0xe02a)
#define P2ETSEL_L    	(*(unsigned char volatile xdata *)0xe02b)
#define P2ETPS   			(*(unsigned int volatile xdata *)0xe02c)	
#define P2ETPS_H  		(*(unsigned char volatile xdata *)0xe02c)
#define P2ETPS_L    	(*(unsigned char volatile xdata *)0xe02d)	




	
// ePWM3 ext Ram ==========================================


#define P3TBCTL   		(*(unsigned int volatile xdata *)0xe02e)
#define P3TBCTL_H    	(*(unsigned char volatile xdata *)0xe02e)
#define P3TBCTL_L    	(*(unsigned char volatile xdata *)0xe02f)
#define P3TBSTS    		(*(unsigned char volatile xdata *)0xe030)
#define P3TBCTR    		(*(unsigned int volatile xdata *)0xe031)	
#define P3TBCTR_H    	(*(unsigned char volatile xdata *)0xe031)
#define P3TBCTR_L    	(*(unsigned char volatile xdata *)0xe032)	
#define P3CMPCTL   		(*(unsigned char volatile xdata *)0xe033)
#define P3AQCTLA    	(*(unsigned int volatile xdata *)0xe034)	
#define P3AQCTLA_H   	(*(unsigned char volatile xdata *)0xe034)
#define P3AQCTLA_L    (*(unsigned char volatile xdata *)0xe035)
#define P3AQCTLB    	(*(unsigned int volatile xdata *)0xe036)	
#define P3AQCTLB_H  	(*(unsigned char volatile xdata *)0xe036)
#define P3AQCTLB_L    (*(unsigned char volatile xdata *)0xe037)
#define P3DBCTL	  		(*(unsigned char volatile xdata *)0xe038)
#define P3DBRED    		(*(unsigned int volatile xdata *)0xe039)	
#define P3DBRED_H  		(*(unsigned char volatile xdata *)0xe039)
#define P3DBRED_L    	(*(unsigned char volatile xdata *)0xe03a)
#define P3DBFED    		(*(unsigned int volatile xdata *)0xe03b)	
#define P3DBFED_H  		(*(unsigned char volatile xdata *)0xe03b)
#define P3DBFED_L    	(*(unsigned char volatile xdata *)0xe03c)
#define P3TZSEL   		(*(unsigned char volatile xdata *)0xe03d)
#define P3TZCTL   		(*(unsigned char volatile xdata *)0xe03e)
#define P3ETSEL   		(*(unsigned int volatile xdata *)0xe040)	
#define P3ETSEL_H  		(*(unsigned char volatile xdata *)0xe040)
#define P3ETSEL_L    	(*(unsigned char volatile xdata *)0xe041)
#define P3ETPS   			(*(unsigned int volatile xdata *)0xe042)	
#define P3ETPS_H  		(*(unsigned char volatile xdata *)0xe042)
#define P3ETPS_L    	(*(unsigned char volatile xdata *)0xe043)	



	
// ePWM4 ext Ram ==========================================



#define P4TBCTL   		(*(unsigned int volatile xdata *)0xe044)
#define P4TBCTL_H    	(*(unsigned char volatile xdata *)0xe044)
#define P4TBCTL_L    	(*(unsigned char volatile xdata *)0xe045)
#define P4TBSTS    		(*(unsigned char volatile xdata *)0xe046)
#define P4TBCTR    		(*(unsigned int volatile xdata *)0xe047)	
#define P4TBCTR_H    	(*(unsigned char volatile xdata *)0xe047)
#define P4TBCTR_L    	(*(unsigned char volatile xdata *)0xe048)	
#define P4CMPCTL   		(*(unsigned char volatile xdata *)0xe049)
#define P4AQCTLA    	(*(unsigned int volatile xdata *)0xe04a)	
#define P4AQCTLA_H   	(*(unsigned char volatile xdata *)0xe04a)
#define P4AQCTLA_L    (*(unsigned char volatile xdata *)0xe04b)
#define P4AQCTLB    	(*(unsigned int volatile xdata *)0xe04c)	
#define P4AQCTLB_H  	(*(unsigned char volatile xdata *)0xe04c)
#define P4AQCTLB_L    (*(unsigned char volatile xdata *)0xe04d)
#define P4DBCTL	  		(*(unsigned char volatile xdata *)0xe04e)
#define P4DBRED    		(*(unsigned int volatile xdata *)0xe04f)	
#define P4DBRED_H  		(*(unsigned char volatile xdata *)0xe04f)
#define P4DBRED_L    	(*(unsigned char volatile xdata *)0xe050)
#define P4DBFED    		(*(unsigned int volatile xdata *)0xe051)	
#define P4DBFED_H  		(*(unsigned char volatile xdata *)0xe051)
#define P4DBFED_L    	(*(unsigned char volatile xdata *)0xe052)
#define P4TZSEL   		(*(unsigned char volatile xdata *)0xe053)
#define P4TZCTL   		(*(unsigned char volatile xdata *)0xe054)
#define P4ETSEL   		(*(unsigned int volatile xdata *)0xe056)	
#define P4ETSEL_H  		(*(unsigned char volatile xdata *)0xe056)
#define P4ETSEL_L    	(*(unsigned char volatile xdata *)0xe057)
#define P4ETPS   			(*(unsigned int volatile xdata *)0xe058)	
#define P4ETPS_H  		(*(unsigned char volatile xdata *)0xe058)
#define P4ETPS_L    	(*(unsigned char volatile xdata *)0xe059)	

 


// ADC ext Ram ==========================================

#define ADCTL  			(*(unsigned int volatile xdata *)0xe05a)
#define ADFLG 			(*(unsigned int volatile xdata *)0xe05b)	
#define ADCHS 			(*(unsigned int volatile xdata *)0xe05c)	
#define ADSHBP			(*(unsigned int volatile xdata *)0xe05d)	
#define AD1OST   		(*(unsigned int volatile xdata *)0xe05e)	
#define AD1OST_H  	(*(unsigned char volatile xdata *)0xe05e)
#define AD1OST_L    (*(unsigned char volatile xdata *)0xe05f)	
#define AD2OST   		(*(unsigned int volatile xdata *)0xe060)	
#define AD2OST_H  	(*(unsigned char volatile xdata *)0xe060)
#define AD2OST_L    (*(unsigned char volatile xdata *)0xe061)	
#define AD3OST   		(*(unsigned int volatile xdata *)0xe062)	
#define AD3OST_H  	(*(unsigned char volatile xdata *)0xe062)
#define AD3OST_L    (*(unsigned char volatile xdata *)0xe063)	
#define AD4OST   		(*(unsigned int volatile xdata *)0xe064)	
#define AD4OST_H  	(*(unsigned char volatile xdata *)0xe064)
#define AD4OST_L    (*(unsigned char volatile xdata *)0xe065)	
#define AD5OST   		(*(unsigned int volatile xdata *)0xe066)	
#define AD5OST_H  	(*(unsigned char volatile xdata *)0xe066)
#define AD5OST_L    (*(unsigned char volatile xdata *)0xe067)	
#define AD6OST   		(*(unsigned int volatile xdata *)0xe068)	
#define AD6OST_H  	(*(unsigned char volatile xdata *)0xe068)
#define AD6OST_L    (*(unsigned char volatile xdata *)0xe069)	
#define AD7OST   		(*(unsigned int volatile xdata *)0xe06a)	
#define AD7OST_H  	(*(unsigned char volatile xdata *)0xe06a)
#define AD7OST_L    (*(unsigned char volatile xdata *)0xe06b)	
#define AD1OUT      (*(unsigned int volatile xdata *)0xe06c)	
#define AD1OUT_H 		(*(unsigned char volatile xdata *)0xe06c)
#define AD1OUT_L    (*(unsigned char volatile xdata *)0xe06d)	
#define AD2OUT      (*(unsigned int volatile xdata *)0xe06e)	
#define AD2OUT_H 		(*(unsigned char volatile xdata *)0xe06e)
#define AD2OUT_L    (*(unsigned char volatile xdata *)0xe06f)	
#define AD3OUT      (*(unsigned int volatile xdata *)0xe070)	
#define AD3OUT_H 		(*(unsigned char volatile xdata *)0xe070)
#define AD3OUT_L    (*(unsigned char volatile xdata *)0xe071)	
#define AD4OUT      (*(unsigned int volatile xdata *)0xe072)	
#define AD4OUT_H 		(*(unsigned char volatile xdata *)0xe072)
#define AD4OUT_L    (*(unsigned char volatile xdata *)0xe073)	
#define AD5OUT      (*(unsigned int volatile xdata *)0xe074)	
#define AD5OUT_H 		(*(unsigned char volatile xdata *)0xe074)
#define AD5OUT_L    (*(unsigned char volatile xdata *)0xe075)	
#define AD6OUT      (*(unsigned int volatile xdata *)0xe076)	
#define AD6OUT_H 		(*(unsigned char volatile xdata *)0xe076)
#define AD6OUT_L    (*(unsigned char volatile xdata *)0xe077)	
#define AD7OUT      (*(unsigned int volatile xdata *)0xe078)	
#define AD7OUT_H 		(*(unsigned char volatile xdata *)0xe078)
#define AD7OUT_L    (*(unsigned char volatile xdata *)0xe079)	







// DAC ext Ram ==========================================

#define DAC_CON    	(*(unsigned char volatile xdata *)0xe07a)	
#define DAC1_DAT   	(*(unsigned char volatile xdata *)0xe07b)	
#define DAC2_DAT  	(*(unsigned char volatile xdata *)0xe07c)	




// SPI ext Ram ==========================================
#define SPCON 	(*(unsigned char volatile xdata *)0xe07d)	
#define SPSTA 	(*(unsigned char volatile xdata *)0xe07e)	
#define SPDAT  	(*(unsigned char volatile xdata *)0xe07f)	



// I2C ext Ram ==========================================
#define I2DATA 		(*(unsigned char volatile xdata *)0xe080)	
#define I2STATUS 	(*(unsigned char volatile xdata *)0xe081)	
#define I2CLK 		(*(unsigned char volatile xdata *)0xe082)		
#define I2TIMER 	(*(unsigned char volatile xdata *)0xe083)		
#define I2CON 		(*(unsigned char volatile xdata *)0xe084)		
#define I2ADDR 		(*(unsigned char volatile xdata *)0xe085)		
						


// TEMP ext Ram ==========================================
#define TEMP_CON 		(*(unsigned char volatile xdata *)0xe086)		


// LVD ext Ram ==========================================
#define LVD_CON 		(*(unsigned char volatile xdata *)0xe087)		



#define AD_DA_SEL  		`		(*(unsigned char volatile xdata *)0xe089)		
#define T3456_EX_INV   		(*(unsigned char volatile xdata *)0xe08a)		
#define AD_PD   					(*(unsigned char volatile xdata *)0xe08b)		
#define ADPOR_TST   			(*(unsigned char volatile xdata *)0xe08c)		
#define EXINT_EN   				(*(unsigned char volatile xdata *)0xe08d)			 



// MTP ext Ram ==========================================
#define MTPCON1   				(*(unsigned char volatile xdata *)0xe08e)		
#define MTPCON2   				(*(unsigned char volatile xdata *)0xe08f)		
#define MTPCON3   				(*(unsigned char volatile xdata *)0xe090)		
#define MTPSADD1   				(*(unsigned char volatile xdata *)0xe091)	
#define MTPSADD2   				(*(unsigned char volatile xdata *)0xe092)
#define MTPDATA1  				(*(unsigned char volatile xdata *)0xe093)
#define MTPDATA2  				(*(unsigned char volatile xdata *)0xe094)
#define MTPDATA3  				(*(unsigned char volatile xdata *)0xe095)
#define MTPDATA4  				(*(unsigned char volatile xdata *)0xe096)	




// CURRENT REF ext Ram ==========================================
#define  CREF_CON  				(*(unsigned char volatile xdata *)0xe097)	


#define  LDO_CON 				(*(unsigned char volatile xdata *)0xe09d)
// XTAL ext Ram ==========================================

#define  XTAL_CON 				(*(unsigned char volatile xdata *)0xe09e)	
//unsigned char xdata   XTAL_CON  _at_ 0xe09e;

// RTC ext Ram ==========================================

#define  RTCCTRL				(*(unsigned char volatile xdata *)0xe09f)	
#define  RTCCNT      		(*(unsigned int volatile xdata *)0xe0a0)	
#define  RTCCNTH				(*(unsigned char volatile xdata *)0xe0a0)	
#define  RTCCNTL				(*(unsigned char volatile xdata *)0xe0a1)	
#define  RTCMOD      		(*(unsigned int volatile xdata *)0xe0a2)	
#define  RTCMODH				(*(unsigned char volatile xdata *)0xe0a2)	
#define  RTCMODL				(*(unsigned char volatile xdata *)0xe0a3)	
		



// OPAMP ext Ram ==========================================
#define  OPAMP_CON				(*(unsigned char volatile xdata *)0xe0a4)	
#define  OPAMP_SEL				(*(unsigned char volatile xdata *)0xe0a5)	
			



// FLASH_SPI ext Ram ==========================================
#define  CTRLR0				(*(unsigned char volatile xdata *)0xe0a6)	
#define  CTRLR1 			(*(unsigned char volatile xdata *)0xe0a7)	
#define  CTRLR2 			(*(unsigned char volatile xdata *)0xe0a8)	
#define  MSTATR 			(*(unsigned char volatile xdata *)0xe0a9)	
#define 	FIFO 				(*(unsigned char volatile xdata *)0xe0aa)	
#define 	DIR					(*(unsigned char volatile xdata *)0xe0ab)	
#define 	ISR					(*(unsigned char volatile xdata *)0xe0ac)	
#define 	ICR					(*(unsigned char volatile xdata *)0xe0ad)	
   	  			


// RC80M ext Ram ==========================================

#define 	RC80M_C1					(*(unsigned char volatile xdata *)0xe0ae)	
#define 	RC80M_C2					(*(unsigned char volatile xdata *)0xe0af)	  	  			
#define 	RC80M_C3					(*(unsigned char volatile xdata *)0xe0b0)	 
#define 	RC80M_CAP					(*(unsigned char volatile xdata *)0xe0b1)	 
#define 	RC80M_RES					(*(unsigned char volatile xdata *)0xe0b2)	
#define 	RC80M_C						(*(unsigned char volatile xdata *)0xe0b3)	
#define 	RC80M_R						(*(unsigned char volatile xdata *)0xe0b4)
#define 	RC32K_R_SEL				(*(unsigned char volatile xdata *)0xe0b5)
	
#define 	ADC_ISEL					(*(unsigned char volatile xdata *)0xe0be)



// external interrupt ext Ram ==========================================
#define 	EXINT_CTRL				(*(unsigned char volatile xdata *)0xe0bf)



// comparator ext Ram ==========================================
#define 	COMP1_FILTER				(*(unsigned char volatile xdata *)0xe0c2)
#define 	COMP2_FILTER				(*(unsigned char volatile xdata *)0xe0c3)	
#define 	COMP3_FILTER				(*(unsigned char volatile xdata *)0xe0c4)	
#define 	COMP4_FILTER				(*(unsigned char volatile xdata *)0xe0c5)	
#define 	COMP_INT_SEL				(*(unsigned char volatile xdata *)0xe0c6)	
#define 	COMP_INT    				(*(unsigned char volatile xdata *)0xe0c7)	




// Timer 3 4 ext Ram ==========================================
#define 	T3CON    				(*(unsigned char volatile xdata *)0xe0c8)	
#define 	T3PS    				(*(unsigned char volatile xdata *)0xe0c9)	
#define   T3CTR      			(*(unsigned int volatile xdata *)0xe0ca)
#define 	T3CTR_H    			(*(unsigned char volatile xdata *)0xe0ca)		
#define 	T3CTR_L    			(*(unsigned char volatile xdata *)0xe0cb)	
#define   T3RC	     			(*(unsigned int volatile xdata *)0xe0cc)
#define 	T3RC_H    			(*(unsigned char volatile xdata *)0xe0cc)		
#define 	T3RC_L    			(*(unsigned char volatile xdata *)0xe0cd)	
#define 	T4CON    				(*(unsigned char volatile xdata *)0xe0ce)	
#define 	T4PS    				(*(unsigned char volatile xdata *)0xe0cf)	
#define   T4CTR      			(*(unsigned int volatile xdata *)0xe0d0)
#define 	T4CTR_H    			(*(unsigned char volatile xdata *)0xe0d0)		
#define 	T4CTR_L    			(*(unsigned char volatile xdata *)0xe0d1)	
#define   T4RC	     			(*(unsigned int volatile xdata *)0xe0d2)
#define 	T4RC_H    			(*(unsigned char volatile xdata *)0xe0d2)		
#define 	T4RC_L    			(*(unsigned char volatile xdata *)0xe0d3)	
		
		


// GPIO function  ext Ram ==========================================
#define 	P0_FN_H     				(*(unsigned char volatile xdata *)0xe0d4)	
#define 	P0_FN_L     				(*(unsigned char volatile xdata *)0xe0d5)	
#define 	P0_DD     					(*(unsigned char volatile xdata *)0xe0d6)	
#define 	P0_DS     					(*(unsigned char volatile xdata *)0xe0d7)	
#define 	P0_PE     					(*(unsigned char volatile xdata *)0xe0d8)	
#define 	P0_PS     					(*(unsigned char volatile xdata *)0xe0d9)	
#define 	P1_FN_H     				(*(unsigned char volatile xdata *)0xe0da)	
#define 	P1_FN_L     				(*(unsigned char volatile xdata *)0xe0db)	
#define 	P1_DD     					(*(unsigned char volatile xdata *)0xe0dc)	
#define 	P1_DS     					(*(unsigned char volatile xdata *)0xe0dd)	
#define 	P1_PE     					(*(unsigned char volatile xdata *)0xe0de)	
#define 	P1_PS     					(*(unsigned char volatile xdata *)0xe0df)	
#define 	P2_FN_H     				(*(unsigned char volatile xdata *)0xe0e0)	
#define 	P2_FN_L     				(*(unsigned char volatile xdata *)0xe0e1)	
#define 	P2_DD     					(*(unsigned char volatile xdata *)0xe0e2)	
#define 	P2_DS     					(*(unsigned char volatile xdata *)0xe0e3)	
#define 	P2_PE     					(*(unsigned char volatile xdata *)0xe0e4)	
#define 	P2_PS     					(*(unsigned char volatile xdata *)0xe0e5)	




// system function  ext Ram ==========================================
#define 	 CLK_DIV_H    				(*(unsigned char volatile xdata *)0xe0e6)	
#define 	 CLK_DIV_L    				(*(unsigned char volatile xdata *)0xe0e7)	
#define 	 LVD_INT_EN     			(*(unsigned char volatile xdata *)0xe0e9)	
#define 	 RC80M_OUT_EN     		(*(unsigned char volatile xdata *)0xe0ea)	
#define 	 COMP_INT_EN     			(*(unsigned char volatile xdata *)0xe0eb)	
#define 	 ADC_CLK_CTRL      		(*(unsigned char volatile xdata *)0xe0ec)
#define    T01_CLK_DIV	     		(*(unsigned int volatile xdata *)0xe0ee)
#define 	 T01_CLK_DIV_H       	(*(unsigned char volatile xdata *)0xe0ee)	
#define 	 T01_CLK_DIV_L       	(*(unsigned char volatile xdata *)0xe0ef)	
#define 	 MTP_PW       				(*(unsigned char volatile xdata *)0xe0f2)	








// Timer 5 6  ext Ram ==========================================
#define 	T5CON    				(*(unsigned char volatile xdata *)0xe0f3)	
#define 	T5PS    				(*(unsigned char volatile xdata *)0xe0f4)	
#define   T5CTR      			(*(unsigned int volatile xdata *)0xe0f5
#define 	T5CTR_H    			(*(unsigned char volatile xdata *)0xe0f5)		
#define 	T5CTR_L    			(*(unsigned char volatile xdata *)0xe0f6)	
#define   T5RC	     			(*(unsigned int volatile xdata *)0xe0f7)
#define 	T5RC_H    			(*(unsigned char volatile xdata *)0xe0f7)		
#define 	T5RC_L    			(*(unsigned char volatile xdata *)0xe0f8)	
#define 	T6CON    				(*(unsigned char volatile xdata *)0xe0f9)	
#define 	T6PS    				(*(unsigned char volatile xdata *)0xe0fa)	
#define   T6CTR      			(*(unsigned int volatile xdata *)0xe0fb)
#define 	T6CTR_H    			(*(unsigned char volatile xdata *)0xe0fb)		
#define 	T6CTR_L    			(*(unsigned char volatile xdata *)0xe0fc)	
#define   T6RC	     			(*(unsigned int volatile xdata *)0xe0fd)
#define 	T6RC_H    			(*(unsigned char volatile xdata *)0xe0fd)		
#define 	T6RC_L    			(*(unsigned char volatile xdata *)0xe0fe)	





#endif //MCU_H_



//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写

