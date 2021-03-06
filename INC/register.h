
#ifndef __REGISTER_H__
#define __REGISTER_H__

#define BIT(aByte,aPos)((struct {unsigned char _0:1;unsigned char _1:1;unsigned char _2:1;unsigned char _3:1;unsigned char _4:1;unsigned char _5:1;unsigned char _6:1;unsigned char _7:1;}*)&aByte)->_##aPos   //BIT(0,1,2,3,4,5,6,7)
#define BIT2(bByte,bPos)((struct {unsigned char _0:2;unsigned char _1:2;unsigned char _2:2;unsigned char _3:2;}*)&bByte)->_##bPos																																							//BIT2(01,23,45,67)
#define BIT3(bByte,bPos)((struct {unsigned char _0:1;unsigned char _1:2;unsigned char _2:2;unsigned char _3:2;unsigned char_4:1;}*)&bByte)->_##bPos																									          //BIT3(0,12,34,56,7)
#define BIT4(bByte,bPos)((struct {unsigned char _0:3;unsigned char _1:1;unsigned char _2:3;unsigned char _3:1;}*)&bByte)->_##bPos	                                                                            //BIT4(012,3,456,7)




#define SET_BIT(p,n) ((p) |= (1 << (n)))
#define CLR_BIT(p,n) ((p) &= (~(1) << (n)))
#define CHECK_BIT(var,pos) (((var) & (1<<(pos)))==(1<<(pos)))


//- $Id: sfr.adr.unx,v 1.1 1996/07/24 14:17:49 gina Exp $

// ISD hardware breakpoint
sfr BPCTRL = 0x93  ; //BPCTRL.7  := breakpoint interrupt request
                       //       ; BPCTRL.1  := 0=code break, 1=xdata break
                       //       ; BPCTRL.0  := breakpoint enable 
		#define BP_INT						  CHECK_BIT(BPCTRL,7)

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

sfr16 BSHI=0xac;

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
sfr16 BSHO =0xbc;
sfr BSHO_0   = 0xbc;
sfr BSHO_1   = 0xbd;
sfr BSHO_2   = 0xbe;
sfr BSHO_3   = 0xbf;
sfr IRCON	   = 0xc0;
    sbit IADC =IRCON^0;
		sbit IEX2 =IRCON^1;
		sbit IEX3 =IRCON^2;
		sbit IEX4 =IRCON^3;
		sbit IEX5 =IRCON^4;
		sbit IEX6 =IRCON^5;
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
    #define MD3_7				      CHECK_BIT(MD3,7)

sfr MD4	     = 0xed;
sfr MD5	     = 0xee;
sfr ARCON	   = 0xef;
sfr	B	       = 0xf0;
//0xf1~0xf7 reserve to PWM4
sfr	SRAM_CON = 0xf8;
sfr INT_REG1 = 0xf9;
     #define EXT(n)				      CHECK_BIT(INT_REG1,##n-1)
     #define CLR_EXT(n)   	    CLR_BIT(INT_REG1,##n-1)
	
		 #define C1_INT							CHECK_BIT(INT_REG1,5)
		 #define T3_INT						  CHECK_BIT(INT_REG1,4)

		#define CLR_T3_INT()				CLR_BIT(INT_REG1,4)
		
sfr INT_REG2 = 0xfa;

#define EPWM_INT(n)   		CHECK_BIT(INT_REG2,##n-1)



//0xfb,0xfc reserved by 8051
sfr INT_REG3 = 0xfd;
		#define CP2_INT						  CHECK_BIT(INT_REG3,0)
		#define CP3_INT						  CHECK_BIT(INT_REG3,1)
		#define CP4_INT						  CHECK_BIT(INT_REG3,2)
		#define I2C_INT             CHECK_BIT(INT_REG3,3)
		#define SPI_INT             CHECK_BIT(INT_REG3,4)
		#define EFLASH_INT          CHECK_BIT(INT_REG3,5)
		
		

		





sfr INT_REG4 = 0xfe;
		#define RTC_INT						  CHECK_BIT(INT_REG4,0)
		#define LDV18_INT						CHECK_BIT(INT_REG4,1)
		#define LDV33_INT						CHECK_BIT(INT_REG4,2)
		#define T4_INT            	CHECK_BIT(INT_REG4,3)
	 


		#define CLR_RTC_INT()   		CLR_BIT(INT_REG4,0)
		#define CLR_LDV18_INT()   	CLR_BIT(INT_REG4,1)
		#define CLR_LDV33_INT()   	CLR_BIT(INT_REG4,2)
		#define CLR_T4_INT()				CLR_BIT(INT_REG4,3)
		









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
	#define EPWM1_INT						  CHECK_BIT(P1ETFLG,0)
	#define EPWM1_SOCA						CHECK_BIT(P1ETFLG,2)
	#define EPWM1_SOCB				    CHECK_BIT(P1ETFLG,3)
	
sfr	P1ETCLR		= 0xb6;
	#define CLR_EPWM1_INT()   		    SET_BIT(P1ETCLR,0)
	#define CLR_EPWM1_SOCA()   		  SET_BIT(P1ETCLR,2)
	#define CLR_EPWM1_SOCB()   		  SET_BIT(P1ETCLR,3)
sfr	P1ETFRC		= 0xb7;
  #define FORCE_EPWM1_INT()          SET_BIT(P1ETFRC,0)
	#define FORCE_EPWM1_SOCA()         SET_BIT(P1ETFRC,2)
	#define FORCE_EPWM1_SOCB()         SET_BIT(P1ETFRC,3)
	
	
	
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
	#define EPWM2_INT						  CHECK_BIT(P2ETFLG,0)
	#define EPWM2_SOCA						CHECK_BIT(P2ETFLG,2)
	#define EPWM2_SOCB				    CHECK_BIT(P2ETFLG,3)
sfr	P2ETCLR		= 0xce;
	#define CLR_EPWM2_INT()   		    SET_BIT(P2ETCLR,0)
	#define CLR_EPWM2_SOCA()   		  SET_BIT(P2ETCLR,2)
	#define CLR_EPWM2_SOCB()   		  SET_BIT(P2ETCLR,3)
sfr	P2ETFRC		= 0xcf;
  #define FORCE_EPWM2_INT()          SET_BIT(P2ETFRC,0)
	#define FORCE_EPWM2_SOCA()         SET_BIT(P2ETFRC,2)
	#define FORCE_EPWM2_SOCB()         SET_BIT(P2ETFRC,3)
	
	

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
	#define EPWM3_INT						  CHECK_BIT(P3ETFLG,0)
	#define EPWM3_SOCA						CHECK_BIT(P3ETFLG,2)
	#define EPWM3_SOCB				    CHECK_BIT(P3ETFLG,3)
sfr	P3ETCLR		= 0xde;
	#define CLR_EPWM3_INT()   		    SET_BIT(P3ETCLR,0)
	#define CLR_EPWM3_SOCA()   		  SET_BIT(P3ETCLR,2)
	#define CLR_EPWM3_SOCB()   		  SET_BIT(P3ETCLR,3)
sfr	P3ETFRC		= 0xdf;		
  #define FORCE_EPWM3_INT()          SET_BIT(P3ETFRC,0)
	#define FORCE_EPWM3_SOCA()         SET_BIT(P3ETFRC,2)
	#define FORCE_EPWM3_SOCB()         SET_BIT(P3ETFRC,3)
	
	


	
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
	#define EPWM4_INT						  CHECK_BIT(P4ETFLG,0)
	#define EPWM4_SOCA						CHECK_BIT(P4ETFLG,2)
	#define EPWM4_SOCB				    CHECK_BIT(P4ETFLG,3)
sfr	P4ETCLR		= 0xf6;
	#define CLR_EPWM4_INT()   		    SET_BIT(P4ETCLR,0)
	#define CLR_EPWM4_SOCA()   		  SET_BIT(P4ETCLR,2)
	#define CLR_EPWM4_SOCB()   		  SET_BIT(P4ETCLR,3)
sfr	P4ETFRC		= 0xf7;
  #define FORCE_EPWM4_INT()          SET_BIT(P4ETFRC,0)
	#define FORCE_EPWM4_SOCA()         SET_BIT(P4ETFRC,2)
	#define FORCE_EPWM4_SOCB()         SET_BIT(P4ETFRC,3)
	
	

	// ePWM top ext Ram =======================================
	

	
#define PCLKCR   (*(unsigned char volatile xdata *)0xe000)
		#define TBCLKSYNC			BIT(PCLKCR,0)
		#define EPWM1_ENCLK		BIT(PCLKCR,1)
		#define EPWM2_ENCLK		BIT(PCLKCR,2)
		#define EPWM3_ENCLK		BIT(PCLKCR,3)
		#define EPWM4_ENCLK		BIT(PCLKCR,4)



#define TZ_SRC_SEL   (*(unsigned char volatile xdata *)0xe001)
	
// ePWM1 ext Ram ==========================================
 
#define P1TBCTL_H    	(*(unsigned char volatile xdata *)0xe002)
		#define P1FREE_SOFT		BIT2(P1TBCTL_H,3)
#define P1TBCTL_L    	(*(unsigned char volatile xdata *)0xe003)
		#define P1CTRMODE			BIT2(P1TBCTL_L,0)
		#define P1PRDLD				BIT(P1TBCTL_L,3)
#define P1TBSTS    		(*(unsigned char volatile xdata *)0xe004)
#define P1TBCTR	    	(*(unsigned int volatile xdata *)0xe005)
#define P1TBCTR_H    	(*(unsigned char volatile xdata *)0xe005)
#define P1TBCTR_L    	(*(unsigned char volatile xdata *)0xe006)	
#define P1CMPCTL   		(*(unsigned char volatile xdata *)0xe007)
			#define P1LOADA_MODE				BIT2(P1CMPCTL,0)
			#define P1LOADB_MODE				BIT2(P1CMPCTL,1)
			#define P1SHDWA_MODE				BIT(P1CMPCTL,4)
			#define P1SHDWB_MODE				BIT(P1CMPCTL,5)
			#define P1SHDWA_FULL				BIT(P1CMPCTL,6)
			#define P1SHDWB_FULL				BIT(P1CMPCTL,7)
#define P1AQCTLA_H   	(*(unsigned char volatile xdata *)0xe008)
			#define P1CBUA							BIT2(P1AQCTLA_H,0)
			#define P1CBDA							BIT2(P1AQCTLA_H,1)
#define P1AQCTLA_L    (*(unsigned char volatile xdata *)0xe009)	
			#define P1ZROA							BIT2(P1AQCTLA_L,0)
			#define P1PRDA							BIT2(P1AQCTLA_L,1)
			#define P1CAUA							BIT2(P1AQCTLA_L,2)
			#define P1CADA							BIT2(P1AQCTLA_L,3)
#define P1AQCTLB_H  	(*(unsigned char volatile xdata *)0xe00a)
			#define P1CBUB							BIT2(P1AQCTLB_H,0)
			#define P1CBDB							BIT2(P1AQCTLB_H,1)
#define P1AQCTLB_L    (*(unsigned char volatile xdata *)0xe00b)
      #define P1ZROB							BIT2(P1AQCTLB_L,0)
			#define P1PRDB							BIT2(P1AQCTLB_L,1)
			#define P1CAUB							BIT2(P1AQCTLB_L,2)
			#define P1CADB							BIT2(P1AQCTLB_L,3)
#define P1DBCTL	  		(*(unsigned char volatile xdata *)0xe00c)	
	    #define P1OUT_MODE					BIT2(P1DBCTL,0)
			#define P1POLSEL						BIT2(P1DBCTL,1)
			#define P1IN_MODE						BIT2(P1DBCTL,2)
#define P1DBRED  		  (*(unsigned int volatile xdata *)0xe00d)
#define P1DBRED_H  		(*(unsigned char volatile xdata *)0xe00d)
#define P1DBRED_L    	(*(unsigned char volatile xdata *)0xe00e)
#define P1DBFED    		(*(unsigned int volatile xdata *)0xe00f)
#define P1DBFED_H  		(*(unsigned char volatile xdata *)0xe00f)
#define P1DBFED_L    	(*(unsigned char volatile xdata *)0xe010)
#define P1TZSEL   		(*(unsigned char volatile xdata *)0xe011)
	   #define P1TZ_OSHT				           BIT(P1TZSEL,0)
	   #define P1TZ_CBC   			           BIT(P1TZSEL,1)
#define P1TZCTL   		(*(unsigned char volatile xdata *)0xe012)
	    #define P1TZA							BIT2(P1TZCTL,0)
			#define P1TZB							BIT2(P1TZCTL,1)
#define P1TZEINT   		(*(unsigned char volatile xdata *)0xe013)
			#define P1TZEINT_CBC  		BIT(P1TZEINT,1)
			#define P1TZEINT_OSHT  		BIT(P1TZEINT,2)
#define P1ETSEL_H  		(*(unsigned char volatile xdata *)0xe014)
	  #define P1ET_SOCASEL				BIT4(P1ETSEL_H ,0)
	  #define P1ET_SOCAEN					BIT4(P1ETSEL_H ,1)
	  #define P1ET_SOCBSEL				BIT4(P1ETSEL_H ,2)
		#define P1ET_SOCBEN					BIT4(P1ETSEL_H ,3)
#define P1ETSEL_L    	(*(unsigned char volatile xdata *)0xe015)
	  #define P1ET_INTSEL				BIT4(P1ETSEL_L ,0)
	  #define P1ET_INTEN				BIT4(P1ETSEL_L ,1)
#define P1ETPS_H  		(*(unsigned char volatile xdata *)0xe016)
	    #define P1ET_SOCAPRD				BIT2(P1ETPS_H,0)
	    #define P1ET_SOCACNT				BIT2(P1ETPS_H,1)
	    #define P1ET_SOCBPRD				BIT2(P1ETPS_H,2)
	    #define P1ET_SOCBCNT				BIT2(P1ETPS_H,3)
#define P1ETPS_L    	(*(unsigned char volatile xdata *)0xe017)	
	    #define P1ET_INTPRD				BIT2(P1ETPS_L,0)
	    #define P1ET_INTCNT				BIT2(P1ETPS_L,1)

	
// ePWM2 ext Ram ==========================================

 
#define P2TBCTL_H    	(*(unsigned char volatile xdata *)0xe018)
		#define P2FREE_SOFT		BIT2(P2TBCTL_H,3)
#define P2TBCTL_L    	(*(unsigned char volatile xdata *)0xe019)
		#define P2CTRMODE			BIT2(P2TBCTL_L,0)
		#define P2PRDLD				BIT(P2TBCTL_L,3)
#define P2TBSTS    		(*(unsigned char volatile xdata *)0xe01a)
#define P2TBCTR    		(*(unsigned int volatile xdata *)0xe01b)
#define P2TBCTR_H    	(*(unsigned char volatile xdata *)0xe01b)
#define P2TBCTR_L    	(*(unsigned char volatile xdata *)0xe01c)	
#define P2CMPCTL   		(*(unsigned char volatile xdata *)0xe01d)
			#define P2LOADA_MODE				BIT2(P2CMPCTL,0)
			#define P2LOADB_MODE				BIT2(P2CMPCTL,1)
			#define P2SHDWA_MODE				BIT(P2CMPCTL,4)
			#define P2SHDWB_MODE				BIT(P2CMPCTL,5)
			#define P2SHDWA_FULL				BIT(P2CMPCTL,6)
			#define P2SHDWB_FULL				BIT(P2CMPCTL,7)	
#define P2AQCTLA_H   	(*(unsigned char volatile xdata *)0xe01e)
			#define P2CBUA							BIT2(P2AQCTLA_H,0)
			#define P2CBDA							BIT2(P2AQCTLA_H,1)	
#define P2AQCTLA_L    (*(unsigned char volatile xdata *)0xe01f)
			#define P2ZROA							BIT2(P2AQCTLA_L,0)
			#define P2PRDA							BIT2(P2AQCTLA_L,1)
			#define P2CAUA							BIT2(P2AQCTLA_L,2)
			#define P2CADA							BIT2(P2AQCTLA_L,3)
#define P2AQCTLB_H  	(*(unsigned char volatile xdata *)0xe020)
			#define P2CBUB							BIT2(P2AQCTLB_H,0)
			#define P2CBDB							BIT2(P2AQCTLB_H,1)
#define P2AQCTLB_L    (*(unsigned char volatile xdata *)0xe021)
	    #define P2ZROB							BIT2(P2AQCTLB_L,0)
			#define P2PRDB							BIT2(P2AQCTLB_L,1)
			#define P2CAUB							BIT2(P2AQCTLB_L,2)
			#define P2CADB							BIT2(P2AQCTLB_L,3)
#define P2DBCTL	  		(*(unsigned char volatile xdata *)0xe022)
	    #define P2OUT_MODE					BIT2(P2DBCTL,0)
			#define P2POLSEL						BIT2(P2DBCTL,1)
			#define P2IN_MODE						BIT2(P2DBCTL,2)
#define P2DBRED  		  (*(unsigned int volatile xdata *)0xe023)	
#define P2DBRED_H  		(*(unsigned char volatile xdata *)0xe023)
#define P2DBRED_L    	(*(unsigned char volatile xdata *)0xe024)
#define P2DBFED   		(*(unsigned int volatile xdata *)0xe025)
#define P2DBFED_H  		(*(unsigned char volatile xdata *)0xe025)
#define P2DBFED_L    	(*(unsigned char volatile xdata *)0xe026)
#define P2TZSEL   		(*(unsigned char volatile xdata *)0xe027)
		 #define P2TZ_OSHT				           BIT(P2TZSEL,0)
     #define P2TZ_CBC   			           BIT(P2TZSEL,1)
#define P2TZCTL   		(*(unsigned char volatile xdata *)0xe028)
		  #define P2TZA							BIT2(P2TZCTL,0)
			#define P2TZB							BIT2(P2TZCTL,1)
#define P2TZEINT   		(*(unsigned char volatile xdata *)0xe029)
			#define P2TZEINT_CBC  		BIT(P2TZEINT,1)
			#define P2TZEINT_OSHT  		BIT(P2TZEINT,2)
#define P2ETSEL_H  		(*(unsigned char volatile xdata *)0xe02a)
	  #define P2ET_SOCASEL				BIT4(P2ETSEL_H ,0)
	  #define P2ET_SOCAEN					BIT4(P2ETSEL_H ,1)
	  #define P2ET_SOCBSEL				BIT4(P2ETSEL_H ,2)
		#define P2ET_SOCBEN					BIT4(P2ETSEL_H ,3)	
#define P2ETSEL_L    	(*(unsigned char volatile xdata *)0xe02b)
	  #define P2ET_INTSEL				BIT4(P2ETSEL_L ,0)
	  #define P2ET_INTEN				BIT4(P2ETSEL_L ,1)	
#define P2ETPS_H  		(*(unsigned char volatile xdata *)0xe02c)
		  #define P2ET_SOCAPRD				BIT2(P2ETPS_H,0)
	    #define P2ET_SOCACNT				BIT2(P2ETPS_H,1)
	    #define P2ET_SOCBPRD				BIT2(P2ETPS_H,2)
	    #define P2ET_SOCBCNT				BIT2(P2ETPS_H,3)
#define P2ETPS_L    	(*(unsigned char volatile xdata *)0xe02d)	
	    #define P2ET_INTPRD				BIT2(P2ETPS_L,0)
	    #define P2ET_INTCNT				BIT2(P2ETPS_L,1)



	
// ePWM3 ext Ram ==========================================


 
#define P3TBCTL_H    	(*(unsigned char volatile xdata *)0xe02e)
		#define P3FREE_SOFT		BIT2(P3TBCTL_H,3)
#define P3TBCTL_L    	(*(unsigned char volatile xdata *)0xe02f)
		#define P3CTRMODE			BIT2(P3TBCTL_L,0)
		#define P3PRDLD				BIT(P3TBCTL_L,3)
#define P3TBSTS    		(*(unsigned char volatile xdata *)0xe030)
#define P3TBCTR    		(*(unsigned int volatile xdata *)0xe031)
#define P3TBCTR_H    	(*(unsigned char volatile xdata *)0xe031)
#define P3TBCTR_L    	(*(unsigned char volatile xdata *)0xe032)	
#define P3CMPCTL   		(*(unsigned char volatile xdata *)0xe033)
			#define P3LOADA_MODE				BIT2(P3CMPCTL,0)
			#define P3LOADB_MODE				BIT2(P3CMPCTL,1)
			#define P3SHDWA_MODE				BIT(P3CMPCTL,4)
			#define P3SHDWB_MODE				BIT(P3CMPCTL,5)
			#define P3SHDWA_FULL				BIT(P3CMPCTL,6)
			#define P3SHDWB_FULL				BIT(P3CMPCTL,7)
#define P3AQCTLA_H   	(*(unsigned char volatile xdata *)0xe034)
			#define P3CBUA							BIT2(P3AQCTLA_H,0)
			#define P3CBDA							BIT2(P3AQCTLA_H,1)	
#define P3AQCTLA_L    (*(unsigned char volatile xdata *)0xe035)
			#define P3ZROA							BIT2(P3AQCTLA_L,0)
			#define P3PRDA							BIT2(P3AQCTLA_L,1)
			#define P3CAUA							BIT2(P3AQCTLA_L,2)
			#define P3CADA							BIT2(P3AQCTLA_L,3)
#define P3AQCTLB_H  	(*(unsigned char volatile xdata *)0xe036)
		  #define P3CBUB							BIT2(P3AQCTLB_H,0)
			#define P3CBDB							BIT2(P3AQCTLB_H,1)
#define P3AQCTLB_L    (*(unsigned char volatile xdata *)0xe037)
		  #define P3ZROB							BIT2(P3AQCTLB_L,0)
			#define P3PRDB							BIT2(P3AQCTLB_L,1)
			#define P3CAUB							BIT2(P3AQCTLB_L,2)
			#define P3CADB							BIT2(P3AQCTLB_L,3)
#define P3DBCTL	  		(*(unsigned char volatile xdata *)0xe038)
	    #define P3OUT_MODE					BIT2(P3DBCTL,0)
			#define P3POLSEL						BIT2(P3DBCTL,1)
			#define P3IN_MODE						BIT2(P3DBCTL,2)
#define P3DBRED   		(*(unsigned int volatile xdata *)0xe039)
#define P3DBRED_H  		(*(unsigned char volatile xdata *)0xe039)
#define P3DBRED_L    	(*(unsigned char volatile xdata *)0xe03a)
#define P3DBFED   		(*(unsigned int volatile xdata *)0xe03b)
#define P3DBFED_H  		(*(unsigned char volatile xdata *)0xe03b)
#define P3DBFED_L    	(*(unsigned char volatile xdata *)0xe03c)
#define P3TZSEL   		(*(unsigned char volatile xdata *)0xe03d)
		 #define P3TZ_OSHT				           BIT(P3TZSEL,0)
     #define P3TZ_CBC   			           BIT(P3TZSEL,1)
#define P3TZCTL   		(*(unsigned char volatile xdata *)0xe03e)
		  #define P3TZA							BIT2(P3TZCTL,0)
			#define P3TZB							BIT2(P3TZCTL,1)
#define P3TZEINT   		(*(unsigned char volatile xdata *)0xe03f)
			#define P3TZEINT_CBC  		BIT(P3TZEINT,1)
			#define P3TZEINT_OSHT  		BIT(P3TZEINT,2)	
#define P3ETSEL_H  		(*(unsigned char volatile xdata *)0xe040)
		#define P3ET_SOCASEL				BIT4(P3ETSEL_H ,0)
	  #define P3ET_SOCAEN					BIT4(P3ETSEL_H ,1)
	  #define P3ET_SOCBSEL				BIT4(P3ETSEL_H ,2)
		#define P3ET_SOCBEN					BIT4(P3ETSEL_H ,3)
#define P3ETSEL_L    	(*(unsigned char volatile xdata *)0xe041)
		#define P3ET_INTSEL				BIT4(P3ETSEL_L ,0)
	  #define P3ET_INTEN				BIT4(P3ETSEL_L ,1)
#define P3ETPS_H  		(*(unsigned char volatile xdata *)0xe042)
	    #define P3ET_SOCAPRD				BIT2(P3ETPS_H,0)
	    #define P3ET_SOCACNT				BIT2(P3ETPS_H,1)
	    #define P3ET_SOCBPRD				BIT2(P3ETPS_H,2)
	    #define P3ET_SOCBCNT				BIT2(P3ETPS_H,3)	
#define P3ETPS_L    	(*(unsigned char volatile xdata *)0xe043)	
	    #define P3ET_INTPRD				BIT2(P3ETPS_L,0)
	    #define P3ET_INTCNT				BIT2(P3ETPS_L,1)


	
// ePWM4 ext Ram ==========================================



 
#define P4TBCTL_H    	(*(unsigned char volatile xdata *)0xe044)
		#define P4FREE_SOFT		BIT2(P4TBCTL_H,3)
#define P4TBCTL_L    	(*(unsigned char volatile xdata *)0xe045)
		#define P4CTRMODE			BIT2(P4TBCTL_L,0)
		#define P4PRDLD				BIT(P4TBCTL_L,3)	
#define P4TBSTS    		(*(unsigned char volatile xdata *)0xe046)
#define P4TBCTR    		(*(unsigned int volatile xdata *)0xe047)	
#define P4TBCTR_H    	(*(unsigned char volatile xdata *)0xe047)
#define P4TBCTR_L    	(*(unsigned char volatile xdata *)0xe048)	
#define P4CMPCTL   		(*(unsigned char volatile xdata *)0xe049)
			#define P4LOADA_MODE				BIT2(P4CMPCTL,0)
			#define P4LOADB_MODE				BIT2(P4CMPCTL,1)
			#define P4SHDWA_MODE				BIT(P4CMPCTL,4)
			#define P4SHDWB_MODE				BIT(P4CMPCTL,5)
			#define P4SHDWA_FULL				BIT(P4CMPCTL,6)
			#define P4SHDWB_FULL				BIT(P4CMPCTL,7)
#define P4AQCTLA_H   	(*(unsigned char volatile xdata *)0xe04a)
			#define P4CBUA							BIT2(P4AQCTLA_H,0)
			#define P4CBDA							BIT2(P4AQCTLA_H,1)	
#define P4AQCTLA_L    (*(unsigned char volatile xdata *)0xe04b)
			#define P4ZROA							BIT2(P4AQCTLA_L,0)
			#define P4PRDA							BIT2(P4AQCTLA_L,1)
			#define P4CAUA							BIT2(P4AQCTLA_L,2)
			#define P4CADA							BIT2(P4AQCTLA_L,3)	
#define P4AQCTLB_H  	(*(unsigned char volatile xdata *)0xe04c)
			#define P4CBUB							BIT2(P4AQCTLB_H,0)
			#define P4CBDB							BIT2(P4AQCTLB_H,1)
#define P4AQCTLB_L    (*(unsigned char volatile xdata *)0xe04d)
	    #define P4ZROB							BIT2(P4AQCTLB_L,0)
			#define P4PRDB							BIT2(P4AQCTLB_L,1)
			#define P4CAUB							BIT2(P4AQCTLB_L,2)
			#define P4CADB							BIT2(P4AQCTLB_L,3)
#define P4DBCTL	  		(*(unsigned char volatile xdata *)0xe04e)
      #define P4OUT_MODE					BIT2(P4DBCTL,0)
			#define P4POLSEL						BIT2(P4DBCTL,1)
			#define P4IN_MODE						BIT2(P4DBCTL,2)	
#define P4DBRED    		(*(unsigned int volatile xdata *)0xe04f)
#define P4DBRED_H  		(*(unsigned char volatile xdata *)0xe04f)
#define P4DBRED_L    	(*(unsigned char volatile xdata *)0xe050)
#define P4DBFED   		(*(unsigned int volatile xdata *)0xe051)
#define P4DBFED_H  		(*(unsigned char volatile xdata *)0xe051)
#define P4DBFED_L    	(*(unsigned char volatile xdata *)0xe052)
#define P4TZSEL   		(*(unsigned char volatile xdata *)0xe053)
		 #define P4TZ_OSHT				           BIT(P4TZSEL,0)
     #define P4TZ_CBC   			           BIT(P4TZSEL,1)
#define P4TZCTL   		(*(unsigned char volatile xdata *)0xe054)
		  #define P4TZA							BIT2(P4TZCTL,0)
			#define P4TZB							BIT2(P4TZCTL,1)
#define P4TZEINT   		(*(unsigned char volatile xdata *)0xe055)
			#define P4TZEINT_CBC  		BIT(P4TZEINT,1)
			#define P4TZEINT_OSHT  		BIT(P4TZEINT,2)
#define P4ETSEL_H  		(*(unsigned char volatile xdata *)0xe056)
		#define P4ET_SOCASEL				BIT4(P4ETSEL_H ,0)
	  #define P4ET_SOCAEN					BIT4(P4ETSEL_H ,1)
	  #define P4ET_SOCBSEL				BIT4(P4ETSEL_H ,2)
		#define P4ET_SOCBEN					BIT4(P4ETSEL_H ,3)
#define P4ETSEL_L    	(*(unsigned char volatile xdata *)0xe057)
	  #define P4ET_INTSEL				BIT4(P4ETSEL_L ,0)
	  #define P4ET_INTEN				BIT4(P4ETSEL_L ,1)	
#define P4ETPS_H  		(*(unsigned char volatile xdata *)0xe058)
		  #define P4ET_SOCAPRD				BIT2(P4ETPS_H,0)
	    #define P4ET_SOCACNT				BIT2(P4ETPS_H,1)
	    #define P4ET_SOCBPRD				BIT2(P4ETPS_H,2)
	    #define P4ET_SOCBCNT				BIT2(P4ETPS_H,3)
#define P4ETPS_L    	(*(unsigned char volatile xdata *)0xe059)	
	    #define P4ET_INTPRD				BIT2(P4ETPS_L,0)
	    #define P4ET_INTCNT				BIT2(P4ETPS_L,1)
 


// ADC ext Ram ==========================================

#define ADCTL  			(*(unsigned char volatile xdata *)0xe05a)
		#define INTEN			BIT(ADCTL,0)
		#define REFSEL		BIT(ADCTL,1)
		#define ADCAL			BIT(ADCTL,2)
		#define TRGSEL		BIT3(ADCTL,2)
		#define SWFTRG		BIT(ADCTL,5)
		#define BUSY			BIT(ADCTL,6)

#define ADCTL2 			(*(unsigned char volatile xdata *)0xe05b)	
		#define INTFL			BIT(ADCTL2,0)
		#define ADC_TEMPC	BIT3(ADCTL2,1)


#define ADCHS 			(*(unsigned char volatile xdata *)0xe05c)	
#define ADSHBP			(*(unsigned char volatile xdata *)0xe05d)	
			#define BP4		BIT(ADSHBP,3)
		  #define BP5   BIT(ADSHBP,4)
			#define BP6	  BIT(ADSHBP,5)




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
    #define  DAC2_PD 			BIT(DAC_CON,0)
		#define  DAC2_VREF		BIT(DAC_CON,1)
		#define  DAC1_PD			BIT(DAC_CON,2)
		#define  DAC1_VREF		BIT(DAC_CON,3)
		

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

#define AD_DA_SEL   		(*(unsigned char volatile xdata *)0xe089)		
		#define ADC_DAC_SEL1						BIT(AD_DA_SEL,0)	
		#define ADC_DAC_SEL2						BIT(AD_DA_SEL,1)

#define T3456_EX_INV   		(*(unsigned char volatile xdata *)0xe08a)		
		#define T3EX_INV						BIT(T3456_EX_INV,0)	
		#define T4EX_INV						BIT(T3456_EX_INV,1)	
		#define T5EX_INV						BIT(T3456_EX_INV,2)	
		#define T6EX_INV						BIT(T3456_EX_INV,3)	


#define AD_PD   					(*(unsigned char volatile xdata *)0xe08b)		
#define ADPOR_TST   			(*(unsigned char volatile xdata *)0xe08c)		
#define EXINT_EN   				(*(unsigned char volatile xdata *)0xe08d)			 					//register write only
		#define EINT1_EN						BIT(EXINT_EN,0)	
		#define EINT2_EN						BIT(EXINT_EN,1)	
		#define EINT3_EN						BIT(EXINT_EN,2)	
		#define EINT4_EN						BIT(EXINT_EN,3)	



// MTP ext Ram ==========================================
#define MTPCON1   				(*(unsigned char volatile xdata *)0xe08e)		
		#define MTP_READ						BIT(MTPCON1,4)
		#define MTP_WRITE						BIT(MTPCON1,5)	
		#define MTP_BUSY						BIT(MTPCON1,6)

#define MTPCON2   				(*(unsigned char volatile xdata *)0xe08f)		
#define MTPCON3   				(*(unsigned char volatile xdata *)0xe090)		
#define MTPSADD1   				(*(unsigned char volatile xdata *)0xe091)	
#define MTPSADD2   				(*(unsigned char volatile xdata *)0xe092)
	
#define MTPDATA   				(*(unsigned long volatile xdata *)0xe093)
	
#define MTPDATA1  				(*(unsigned char volatile xdata *)0xe093)
#define MTPDATA2  				(*(unsigned char volatile xdata *)0xe094)
#define MTPDATA3  				(*(unsigned char volatile xdata *)0xe095)
#define MTPDATA4  				(*(unsigned char volatile xdata *)0xe096)	




// CURRENT REF ext Ram ==========================================
#define  CREF_CON  				(*(unsigned char volatile xdata *)0xe097)	


#define  LDO_CON 				(*(unsigned char volatile xdata *)0xe09d)
		#define LDO25_PD		BIT(LDO_CON,1)

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
				#define C1PDO1PD						BIT2(OPAMP_CON,0)
				#define C2PDO2PD						BIT2(OPAMP_CON,1)
				#define C3PDO3PD						BIT2(OPAMP_CON,2)
				#define C4PD								BIT(OPAMP_CON,6)

#define  OPAMP_CURRENT				(*(unsigned char volatile xdata *)0xe0a5)	
		  	#define OPAMP_SEL							BIT2(OPAMP_CURRENT,0)



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
		#define EINT1_CFG						BIT2(EXINT_CTRL,0)	
		#define EINT2_CFG						BIT2(EXINT_CTRL,1)
		#define EINT3_CFG						BIT2(EXINT_CTRL,2)
		#define EINT4_CFG						BIT2(EXINT_CTRL,3)


// comparator ext Ram ==========================================
#define 	COMP1_FILTER				(*(unsigned char volatile xdata *)0xe0c2)
#define 	COMP2_FILTER				(*(unsigned char volatile xdata *)0xe0c3)	
#define 	COMP3_FILTER				(*(unsigned char volatile xdata *)0xe0c4)	
#define 	COMP4_FILTER				(*(unsigned char volatile xdata *)0xe0c5)	
#define 	COMP_INT_SEL				(*(unsigned char volatile xdata *)0xe0c6)	
	 #define C1_INT_SEL				BIT(COMP_INT_SEL,0)	
	 #define C2_INT_SEL				BIT(COMP_INT_SEL,1)	
	 #define C3_INT_SEL				BIT(COMP_INT_SEL,2)	
	 #define C4_INT_SEL				BIT(COMP_INT_SEL,3)	

#define 	COMP_INT    				(*(unsigned char volatile xdata *)0xe0c7)	
		#define C1INT						BIT(COMP_INT,0)	
		#define C2INT						BIT(COMP_INT,1)	
		#define C3INT						BIT(COMP_INT,2)	
		#define C4INT						BIT(COMP_INT,3)	






// Timer 3 4 ext Ram ==========================================
#define 	T3CON    				(*(unsigned char volatile xdata *)0xe0c8)	
		#define T3CPRL						 	BITREF(T3CON,0)	
		#define T3CT							 	BITREF(T3CON,1)
		#define T3TR								BITREF(T3CON,2)
		#define T3EXEN							BITREF(T3CON,3)
		#define T3EXF_EINT					BITREF(T3CON,4)
		#define T3TF_EINT						BITREF(T3CON,5)
		#define T3EXF								BITREF(T3CON,6)
		#define T3TF								BITREF(T3CON,7)


#define 	T3PS    				(*(unsigned char volatile xdata *)0xe0c9)	
#define   T3CTR      			(*(unsigned int volatile xdata *)0xe0ca)
#define 	T3CTR_H    			(*(unsigned char volatile xdata *)0xe0ca)		
#define 	T3CTR_L    			(*(unsigned char volatile xdata *)0xe0cb)	
#define   T3RC	     			(*(unsigned int volatile xdata *)0xe0cc)
#define 	T3RC_H    			(*(unsigned char volatile xdata *)0xe0cc)		
#define 	T3RC_L    			(*(unsigned char volatile xdata *)0xe0cd)	
#define 	T4CON    				(*(unsigned char volatile xdata *)0xe0ce)	
		#define T4CPRL						 	BITREF(T4CON,0)	
		#define T4CT							 	BITREF(T4CON,1)
		#define T4TR								BITREF(T4CON,2)
		#define T4EXEN							BITREF(T4CON,3)
		#define T4EXF_EINT					BITREF(T4CON,4)
		#define T4TF_EINT						BITREF(T4CON,5)
		#define T4EXF								BITREF(T4CON,6)
		#define T4TF								BITREF(T4CON,7)



#define 	T4PS    				(*(unsigned char volatile xdata *)0xe0cf)	
#define   T4CTR      			(*(unsigned int volatile xdata *)0xe0d0)
#define 	T4CTR_H    			(*(unsigned char volatile xdata *)0xe0d0)		
#define 	T4CTR_L    			(*(unsigned char volatile xdata *)0xe0d1)	
#define   T4RC	     			(*(unsigned int volatile xdata *)0xe0d2)
#define 	T4RC_H    			(*(unsigned char volatile xdata *)0xe0d2)		
#define 	T4RC_L    			(*(unsigned char volatile xdata *)0xe0d3)	
		
		


// GPIO function  ext Ram ==========================================
#define 	P0_FN_H     				(*(unsigned char volatile xdata *)0xe0d4)	
		#define P04_FN						BIT2(P0_FN_H,0)
		#define P05_FN						BIT2(P0_FN_H,1)
		#define P06_FN						BIT2(P0_FN_H,2)
		#define P07_FN						BIT2(P0_FN_H,3)

		#define FN_P04						BIT2(P0_FN_H,0)
		#define FN_P05						BIT2(P0_FN_H,1)
		#define FN_P06						BIT2(P0_FN_H,2)
		#define FN_P07						BIT2(P0_FN_H,3)



#define 	P0_FN_L     				(*(unsigned char volatile xdata *)0xe0d5)	
		#define P00_FN						BIT2(P0_FN_L,0)
		#define P01_FN						BIT2(P0_FN_L,1)
		#define P02_FN						BIT2(P0_FN_L,2)
		#define P03_FN						BIT2(P0_FN_L,3)

		#define FN_P00						BIT2(P0_FN_L,0)
		#define FN_P01						BIT2(P0_FN_L,1)
		#define FN_P02						BIT2(P0_FN_L,2)
		#define FN_P03						BIT2(P0_FN_L,3)



#define 	P0_DD     					(*(unsigned char volatile xdata *)0xe0d6)	
		#define P00_DD						BIT(P0_DD,0)
		#define P01_DD						BIT(P0_DD,1)
		#define P02_DD						BIT(P0_DD,2)
		#define P03_DD						BIT(P0_DD,3)
		#define P04_DD						BIT(P0_DD,4)
		#define P05_DD						BIT(P0_DD,5)
		#define P06_DD						BIT(P0_DD,6)
		#define P07_DD						BIT(P0_DD,7)

		#define DD_P00						BIT(P0_DD,0)
		#define DD_P01						BIT(P0_DD,1)
		#define DD_P02						BIT(P0_DD,2)
		#define DD_P03						BIT(P0_DD,3)
		#define DD_P04						BIT(P0_DD,4)
		#define DD_P05						BIT(P0_DD,5)
		#define DD_P06						BIT(P0_DD,6)
		#define DD_P07						BIT(P0_DD,7)




#define 	P0_DS     					(*(unsigned char volatile xdata *)0xe0d7)	
		#define P00_DS						BIT(P0_DS,0)
		#define P01_DS						BIT(P0_DS,1)
		#define P02_DS						BIT(P0_DS,2)
		#define P03_DS						BIT(P0_DS,3)
		#define P04_DS						BIT(P0_DS,4)
		#define P05_DS						BIT(P0_DS,5)
		#define P06_DS						BIT(P0_DS,6)
		#define P07_DS						BIT(P0_DS,7)

		#define DS_P00						BIT(P0_DS,0)
		#define DS_P01						BIT(P0_DS,1)
		#define DS_P02						BIT(P0_DS,2)
		#define DS_P03						BIT(P0_DS,3)
		#define DS_P04						BIT(P0_DS,4)
		#define DS_P05						BIT(P0_DS,5)
		#define DS_P06						BIT(P0_DS,6)
		#define DS_P07						BIT(P0_DS,7)



#define 	P0_PE     					(*(unsigned char volatile xdata *)0xe0d8)	
		#define P00_PE						BIT(P0_PE,0)
		#define P01_PE						BIT(P0_PE,1)
		#define P02_PE						BIT(P0_PE,2)
		#define P03_PE						BIT(P0_PE,3)
		#define P04_PE						BIT(P0_PE,4)
		#define P05_PE						BIT(P0_PE,5)
		#define P06_PE						BIT(P0_PE,6)
		#define P07_PE						BIT(P0_PE,7)

		#define PE_P00						BIT(P0_PE,0)
		#define PE_P01						BIT(P0_PE,1)
		#define PE_P02						BIT(P0_PE,2)
		#define PE_P03						BIT(P0_PE,3)
		#define PE_P04						BIT(P0_PE,4)
		#define PE_P05						BIT(P0_PE,5)
		#define PE_P06						BIT(P0_PE,6)
		#define PE_P07						BIT(P0_PE,7)


#define 	P0_PS     					(*(unsigned char volatile xdata *)0xe0d9)	
		#define P00_PS						BIT(P0_PS,0)
		#define P01_PS						BIT(P0_PS,1)
		#define P02_PS						BIT(P0_PS,2)
		#define P03_PS						BIT(P0_PS,3)
		#define P04_PS						BIT(P0_PS,4)
		#define P05_PS						BIT(P0_PS,5)
		#define P06_PS						BIT(P0_PS,6)
		#define P07_PS						BIT(P0_PS,7)

		#define PS_P00						BIT(P0_PS,0)
		#define PS_P01						BIT(P0_PS,1)
		#define PS_P02						BIT(P0_PS,2)
		#define PS_P03						BIT(P0_PS,3)
		#define PS_P04						BIT(P0_PS,4)
		#define PS_P05						BIT(P0_PS,5)
		#define PS_P06						BIT(P0_PS,6)
		#define PS_P07						BIT(P0_PS,7)


#define 	P1_FN_H     				(*(unsigned char volatile xdata *)0xe0da)	
		#define P14_FN						BIT2(P1_FN_H,0)
		#define P15_FN						BIT2(P1_FN_H,1)                   
		#define P16_FN						BIT2(P1_FN_H,2)
		#define P17_FN						BIT2(P1_FN_H,3)

		#define FN_P14						BIT2(P1_FN_H,0)
		#define FN_P15						BIT2(P1_FN_H,1)                   
		#define FN_P16						BIT2(P1_FN_H,2)
		#define FN_P17						BIT2(P1_FN_H,3)





#define 	P1_FN_L     				(*(unsigned char volatile xdata *)0xe0db)	
		#define P10_FN						BIT2(P1_FN_L,0)
		#define P11_FN						BIT2(P1_FN_L,1)
		#define P12_FN						BIT2(P1_FN_L,2)
		#define P13_FN						BIT2(P1_FN_L,3)	

		#define FN_P10						BIT2(P1_FN_L,0)
		#define FN_P11						BIT2(P1_FN_L,1)
		#define FN_P12						BIT2(P1_FN_L,2)
		#define FN_P13						BIT2(P1_FN_L,3)	


#define 	P1_DD     					(*(unsigned char volatile xdata *)0xe0dc)	
		#define P10_DD						BIT(P1_DD,0)
		#define P11_DD						BIT(P1_DD,1)
		#define P12_DD						BIT(P1_DD,2)
		#define P13_DD						BIT(P1_DD,3)
		#define P14_DD						BIT(P1_DD,4)
		#define P15_DD						BIT(P1_DD,5)
		#define P16_DD						BIT(P1_DD,6)
		#define P17_DD						BIT(P1_DD,7)

		#define DD_P10						BIT(P1_DD,0)
		#define DD_P11						BIT(P1_DD,1)
		#define DD_P12						BIT(P1_DD,2)
		#define DD_P13						BIT(P1_DD,3)
		#define DD_P14						BIT(P1_DD,4)
		#define DD_P15						BIT(P1_DD,5)
		#define DD_P16						BIT(P1_DD,6)
		#define DD_P17						BIT(P1_DD,7)



#define 	P1_DS     					(*(unsigned char volatile xdata *)0xe0dd)	
		#define P10_DS						BIT(P1_DS,0)
		#define P11_DS						BIT(P1_DS,1)
		#define P12_DS						BIT(P1_DS,2)
		#define P13_DS						BIT(P1_DS,3)
		#define P14_DS						BIT(P1_DS,4)
		#define P15_DS						BIT(P1_DS,5)
		#define P16_DS						BIT(P1_DS,6)
		#define P17_DS						BIT(P1_DS,7)

		#define DS_P10						BIT(P1_DS,0)
		#define DS_P11						BIT(P1_DS,1)
		#define DS_P12						BIT(P1_DS,2)
		#define DS_P13						BIT(P1_DS,3)
		#define DS_P14						BIT(P1_DS,4)
		#define DS_P15						BIT(P1_DS,5)
		#define DS_P16						BIT(P1_DS,6)
		#define DS_P17						BIT(P1_DS,7)



#define 	P1_PE     					(*(unsigned char volatile xdata *)0xe0de)	
		#define P10_PE						BIT(P1_PE,0)
		#define P11_PE						BIT(P1_PE,1)
		#define P12_PE						BIT(P1_PE,2)
		#define P13_PE						BIT(P1_PE,3)
		#define P14_PE						BIT(P1_PE,4)
		#define P15_PE						BIT(P1_PE,5)
		#define P16_PE						BIT(P1_PE,6)
		#define P17_PE						BIT(P1_PE,7)

		#define PE_P10						BIT(P1_PE,0)
		#define PE_P11						BIT(P1_PE,1)
		#define PE_P12						BIT(P1_PE,2)
		#define PE_P13						BIT(P1_PE,3)
		#define PE_P14						BIT(P1_PE,4)
		#define PE_P15						BIT(P1_PE,5)
		#define PE_P16						BIT(P1_PE,6)
		#define PE_P17						BIT(P1_PE,7)



#define 	P1_PS     					(*(unsigned char volatile xdata *)0xe0df)	
		#define P10_PS						BIT(P1_PS,0)
		#define P11_PS						BIT(P1_PS,1)
		#define P12_PS						BIT(P1_PS,2)
		#define P13_PS						BIT(P1_PS,3)
		#define P14_PS						BIT(P1_PS,4)
		#define P15_PS						BIT(P1_PS,5)
		#define P16_PS						BIT(P1_PS,6)
		#define P17_PS						BIT(P1_PS,7)

		#define PS_P10						BIT(P1_PS,0)
		#define PS_P11						BIT(P1_PS,1)
		#define PS_P12						BIT(P1_PS,2)
		#define PS_P13    				BIT(P1_PS,3)
		#define PS_P14						BIT(P1_PS,4)
		#define PS_P15						BIT(P1_PS,5)
		#define PS_P16						BIT(P1_PS,6)
		#define PS_P17						BIT(P1_PS,7)


#define 	P2_FN_H     				(*(unsigned char volatile xdata *)0xe0e0)	
		#define P24_FN						BIT2(P2_FN_H,0)
		#define P25_FN						BIT2(P2_FN_H,1)
		#define P26_FN						BIT2(P2_FN_H,2)
		#define P27_FN						BIT2(P2_FN_H,3)

		#define FN_P24						BIT2(P2_FN_H,0)
		#define FN_P25						BIT2(P2_FN_H,1)
		#define FN_P26						BIT2(P2_FN_H,2)
		#define FN_P27						BIT2(P2_FN_H,3)


#define 	P2_FN_L     				(*(unsigned char volatile xdata *)0xe0e1)	
		#define P20_FN						BIT2(P2_FN_L,0)
		#define P21_FN						BIT2(P2_FN_L,1)
		#define P22_FN						BIT2(P2_FN_L,2)
		#define P23_FN						BIT2(P2_FN_L,3)

	  #define FN_P20						BIT2(P2_FN_L,0)
		#define FN_P21						BIT2(P2_FN_L,1)
		#define FN_P22						BIT2(P2_FN_L,2)
		#define FN_P23						BIT2(P2_FN_L,3)



#define 	P2_DD     					(*(unsigned char volatile xdata *)0xe0e2)	
		#define P20_DD						BIT(P2_DD,0)
		#define P21_DD						BIT(P2_DD,1)
		#define P22_DD						BIT(P2_DD,2)
		#define P23_DD						BIT(P2_DD,3)
		#define P24_DD						BIT(P2_DD,4)
		#define P25_DD						BIT(P2_DD,5)
		#define P26_DD						BIT(P2_DD,6)
		#define P27_DD						BIT(P2_DD,7)

		#define DD_P20						BIT(P2_DD,0)
		#define DD_P21						BIT(P2_DD,1)
		#define DD_P22						BIT(P2_DD,2)
		#define DD_P23						BIT(P2_DD,3)
		#define DD_P24						BIT(P2_DD,4)
		#define DD_P25						BIT(P2_DD,5)
		#define DD_P26						BIT(P2_DD,6)
		#define DD_P27						BIT(P2_DD,7)

	



#define 	P2_DS     					(*(unsigned char volatile xdata *)0xe0e3)	
		#define P20_DS						BIT(P2_DS,0)
		#define P21_DS						BIT(P2_DS,1)
		#define P22_DS						BIT(P2_DS,2)
		#define P23_DS						BIT(P2_DS,3)
		#define P24_DS						BIT(P2_DS,4)
		#define P25_DS						BIT(P2_DS,5)
		#define P26_DS						BIT(P2_DS,6)
		#define P27_DS						BIT(P2_DS,7)
	
		#define DS_P20						BIT(P2_DS,0)
		#define DS_P21						BIT(P2_DS,1)
		#define DS_P22						BIT(P2_DS,2)
		#define DS_P23						BIT(P2_DS,3)
		#define DS_P24						BIT(P2_DS,4)
		#define DS_P25						BIT(P2_DS,5)
		#define DS_P26						BIT(P2_DS,6)
		#define DS_P27						BIT(P2_DS,7)


#define 	P2_PE     					(*(unsigned char volatile xdata *)0xe0e4)	
		#define P20_PE						BIT(P2_PE,0)
		#define P21_PE						BIT(P2_PE,1)
		#define P22_PE						BIT(P2_PE,2)
		#define P23_PE						BIT(P2_PE,3)
		#define P24_PE						BIT(P2_PE,4)
		#define P25_PE						BIT(P2_PE,5)
		#define P26_PE						BIT(P2_PE,6)
		#define P27_PE						BIT(P2_PE,7)
	
		#define PE_P20						BIT(P2_PE,0)
		#define PE_P21						BIT(P2_PE,1)
		#define PE_P22						BIT(P2_PE,2)
		#define PE_P23						BIT(P2_PE,3)
		#define PE_P24						BIT(P2_PE,4)
		#define PE_P25 						BIT(P2_PE,5)
		#define PE_P26						BIT(P2_PE,6)
		#define PE_P27						BIT(P2_PE,7)


#define 	P2_PS     					(*(unsigned char volatile xdata *)0xe0e5)	
		#define P20_PS						BIT(P2_PS,0)
		#define P21_PS						BIT(P2_PS,1)
		#define P22_PS						BIT(P2_PS,2)
		#define P23_PS						BIT(P2_PS,3)
		#define P24_PS						BIT(P2_PS,4)
		#define P25_PS						BIT(P2_PS,5)
		#define P26_PS						BIT(P2_PS,6)
		#define P27_PS						BIT(P2_PS,7)

		#define PS_P20						BIT(P2_PS,0)
		#define PS_P21						BIT(P2_PS,1)
		#define PS_P22						BIT(P2_PS,2)
		#define PS_P23						BIT(P2_PS,3)
		#define PS_P24						BIT(P2_PS,4)
		#define PS_P25						BIT(P2_PS,5)
		#define PS_P26						BIT(P2_PS,6)
		#define PS_P27						BIT(P2_PS,7)



// system function  ext Ram ==========================================
#define 	 CLK_DIV_H    				(*(unsigned char volatile xdata *)0xe0e6)	
#define 	 CLK_DIV_L    				(*(unsigned char volatile xdata *)0xe0e7)	
#define 	 LVD_INT_EN     			(*(unsigned char volatile xdata *)0xe0e9)	
#define 	 RC80M_OUT_EN     		(*(unsigned char volatile xdata *)0xe0ea)	
#define 	 COMP_INT_EN     			(*(unsigned char volatile xdata *)0xe0eb)	
		#define  	C1_EN							BIT(COMP_INT_EN,0)
		#define  	C2_EN							BIT(COMP_INT_EN,1)
		#define  	C3_EN							BIT(COMP_INT_EN,2)
		#define  	C4_EN							BIT(COMP_INT_EN,3)
		#define 	INT_CPU						BIT(COMP_INT_EN,4)
		#define   T3_SEL						BIT(COMP_INT_EN,5)
		#define   T4_SEL						BIT(COMP_INT_EN,6)




#define 	 ADC_CLK_CTRL      		(*(unsigned char volatile xdata *)0xe0ec)
		#define  ADC_CLK_EN					BIT(ADC_CLK_CTRL,3)
		#define  ADC_CLK_DIV_SEL		BIT2(ADC_CLK_CTRL,0)



#define    T01_DIV	     		(*(unsigned int volatile xdata *)0xe0ee)
#define 	 T01_DIV_H       	(*(unsigned char volatile xdata *)0xe0ee)	
#define 	 T01_DIV_L       	(*(unsigned char volatile xdata *)0xe0ef)	
#define 	 MTP_PW       				(*(unsigned char volatile xdata *)0xe0f2)	






#define BITREF(aByte,aPos)((struct {unsigned char _0:1;unsigned char _1:1;unsigned char _2:1;unsigned char _3:1;unsigned char _4:1;unsigned char _5:1;unsigned char _6:1;unsigned char _7:1;}*)&aByte)->_##aPos

// Timer 5 6  ext Ram ==========================================
#define 	T5CON    				(*(unsigned char volatile xdata *)0xe0f3)	
		#define T5CPRL						 	BITREF(T5CON,0)	
		#define T5CT							 	BITREF(T5CON,1)
		#define T5TR								BITREF(T5CON,2)
		#define T5EXEN		    			BITREF(T5CON,3)
		#define T5EXF_EINT					BITREF(T5CON,4)
		#define T5TF_EINT						BITREF(T5CON,5)
		#define T5EXF								BITREF(T5CON,6)
		#define T5TF								BITREF(T5CON,7)

		#define T5_INT							((T5TF==1)|(T5EXF==1))


#define 	T5PS    				(*(unsigned char volatile xdata *)0xe0f4)	
#define   T5CTR      			(*(unsigned int volatile xdata *)0xe0f5
#define 	T5CTR_H    			(*(unsigned char volatile xdata *)0xe0f5)		
#define 	T5CTR_L    			(*(unsigned char volatile xdata *)0xe0f6)	
#define   T5RC	     			(*(unsigned int volatile xdata *)0xe0f7)
#define 	T5RC_H    			(*(unsigned char volatile xdata *)0xe0f7)		
#define 	T5RC_L    			(*(unsigned char volatile xdata *)0xe0f8)	
	

#define 	T6CON    				(*(unsigned char volatile xdata *)0xe0f9)	
		#define T6CPRL						 	BITREF(T6CON,0)	
		#define T6CT							 	BITREF(T6CON,1)
		#define T6TR								BITREF(T6CON,2)
		#define T6EXEN							BITREF(T6CON,3)
		#define T6EXF_EINT					BITREF(T6CON,4)
		#define T6TF_EINT						BITREF(T6CON,5)
		#define T6EXF								BITREF(T6CON,6)
		#define T6TF								BITREF(T6CON,7)

		#define T6_INT							((T6TF==1)|(T6EXF==1))

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

