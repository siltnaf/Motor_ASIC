#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"


/*interrupt number
 EXT1-4     0
 
 

 TIMER0			1
 TIMER1     3
 UART0      4
 ADC        8
 UART1      16
 
 COMP1      22
 TIMER3     23
 
 ePWM1-3    9

 ePMW4      20
 Timer5     21
 
 Timer6			24
 I2C				25
 SPI				26
 eFlash			27
 
 


*/


void EXT1234Interrupt (void) 	interrupt 0
{
	
	if (EXT(1)==1)
	{
		
		CLR_EXT(1);
	}
	
	
	if (EXT(2)==1)	
	{
		      P26=~P26;
		CLR_EXT(2);
	}
	
	
	if (EXT(3)==1)
	{
		CLR_EXT(3);
	}
	

	if (EXT(4)==1)
	{
		
		CLR_EXT(4);
	}
	
	if ((EXT(1)==0)&&(EXT(2)==0)&&(EXT(3)==0)&&(EXT(4)==0))
		IE0=0;

}







/*  Timer interrupt   **/


void TIMER0Interrupt(void)  interrupt 1
{

	  TF0=0;
 P04=~P04;
	
	
	SWFTRG=1;				//start next AD
	


}

void TIMER1Interrupt(void)  interrupt 3
{
	
	
	TF1=0;
}

void TIMER3Interrupt(void)  interrupt 23
{
  
	
	if (T3TF==1)
	{
		tmr3_ov++;
//		P26=~P26;
	
		T3TF=0;
	}
	
	if (T3EXF==1)
	{

		this_capture=(unsigned long) T3RC;
		if (T3EX_INV==1)                //capture falling edge and start counting
				{

				T3EX_INV=0;                 //set to capture next rising edge 
				last_capture=this_capture;
				tmr3_ov=0;										//reset tmr3_ov
			
				}
				else
				{
					
					
				if (!tmr3_ov)
					//rising edge to record time lapse
					{
						
					pwm_capture=this_capture-last_capture;
		
					}
					else 
					{
						pwm_capture=(unsigned long)(tmr3_ov)<<16;
						
						pwm_capture=pwm_capture+this_capture-last_capture;
						
						
						
					}
					
					T3EX_INV=1;          //reset to capture falling edge 

					
				}
				T3EXF=0;
	}
	
	if ((T3TF==0)&&(T3EXF==0)&&(C1_INT==0))
		
		IE1=0;
}

void TIMER4Interrupt(void)  interrupt 17
{
	
	
	
	T4TF=0;

	CLR_T4_INT();

	
	P26= ~P26;
	
			if ((RTC_INT==0)&&(LDV18_INT==0)&&(LDV33_INT==0)&&(T4_INT==0)&&(BP_INT==0))
			IEX6=0;
			
	
	
}

void TIMER5Interrupt(void)  interrupt 21
{

	T5TF=0;
	T5EXF=0;

	if (timer5_flag==0)
		{
		timer5_flag=1;
		P26=1;
		}
		else
			{			
				timer5_flag=0;
				P26=0;
			}
	   //             test with led output
	
	if ((T5_INT==0)&&(EPWM_INT(4)==0))
		IEX3=0;
	
	
}
void TIMER6Interrupt(void)  interrupt 24
{

	T6TF=0;
	T6EXF=0;
  if (timer5_flag==1)
			P26= ~P26 ;  //           test with led output
			else P26=0;
	
	if ((I2C_INT==0)&&(SPI_INT==0)&&(EFLASH_INT==0)&&(T6_INT==0))
		IEX5=0;
	
	
}




/*     EPWM interrupt */

void ePWM123Interrupt(void) interrupt 9
{
	if (EPWM1_INT==1)
	{
		
		
		
		CLR_EPWM1_INT();
	}

	
	if (EPWM2_INT==1)
	{
		
		
		
		
		
		CLR_EPWM2_INT();
	}
	
	
	if (EPWM3_INT==1)
	{
		
    CLR_EPWM3_INT(); 
	}
	
	if ((EPWM1_INT==0)&&(EPWM2_INT==0)&&(EPWM3_INT==0))
		IEX2=0;
	
}


void ePWM4Interrupt(void)  interrupt 20
{

	 CLR_EPWM4_INT(); 
	
	if ((T5_INT==0)&&(EPWM4_INT==0))
			IEX3=0;
	
}





/* comparator interrupt */

void Comp1Interrupt(void) interrupt 22
	
{
	
	
	
	C1INT=0;	
	
	if ((T3_INT==0)&&(C1_INT==0))
			IE1=0;
}


void  Comp234Interrupt(void) interrupt 11

{
	
	
	if (C2INT==1)

		{
			
			
		
			C2INT=0;	

    


			
		}
		
		if (C3INT==1)

		{
		
				C3INT=0;	

		}
					
		if (C4INT==1)

		{
	
			C4INT=0;	

			
		}
		
		if ((C2INT==0)&&(C3INT==0)&&(C4INT==0))
				IEX4=0;
			
	}



	/*  serial communication  */

void I2CInterrupt(void)  interrupt 25
{

//	CLR_I2C_INT();
	
	if ((I2C_INT==0)&&(SPI_INT==0)&&(EFLASH_INT==0)&&(T6_INT==0))
		IEX5=0;
}

void SPIInterrupt(void)  interrupt 26
{

//	CLR_SPI_INT();
	if ((I2C_INT==0)&&(SPI_INT==0)&&(EFLASH_INT==0)&&(T6_INT==0))
		IEX5=0;
}

void eFlashInterrupt(void)  interrupt 27
{

//	CLR_EFLASH_INT();
	if ((I2C_INT==0)&&(SPI_INT==0)&&(EFLASH_INT==0)&&(T6_INT==0))
		IEX5=0;
}


/*  voltage detect, RTC  */

void RTCInterrupt(void) interrupt 28
{
	
	
	
	CLR_RTC_INT();
			if ((RTC_INT==0)&&(LDV18_INT==0)&&(LDV33_INT==0)&&(T4_INT==0)&&(BP_INT==0))
			IEX6=0;
			
	
}
	

void LDV18Interrupt(void) interrupt 29
{
	
	CLR_LDV18_INT();
			if ((RTC_INT==0)&&(LDV18_INT==0)&&(LDV33_INT==0)&&(T4_INT==0)&&(BP_INT==0))
			IEX6=0;
			

}

void LDV33Interrupt(void) interrupt 30
{
	
	CLR_LDV33_INT();
	
			if ((RTC_INT==0)&&(LDV18_INT==0)&&(LDV33_INT==0)&&(T4_INT==0)&&(BP_INT==0))
			IEX6=0;
			
}





/* debug and UART port */
	

void UART1Interrupt(void) //interrupt 4
{
    if(RI0 == 1)
    {
        RI0 = 0;
    }

    if(TI0 == 1)
    {
       TI0 = 0;
    }
}

void UART2Interrupt(void) interrupt 16
{
    //receive
    if((S1CON & 0x01) == 0x01)
    {
        S1CON &= 0xfe;
//        ucUARTReceiver = S1BUF;
//        ucUARTReceiver++;
//        ucUARTReceiver++;
//        ucReceiveFlag = 1;
    }

    //transmit
    if((S1CON & 0x02) == 0x02)
    {
        S1CON &= 0xfd;
    }
}

void ADCInterrupt(void) interrupt 8
{
	

		if (INTFL==1)
		{
				INTFL=0;
				IADC=0;
		}
	
    ADresult = AD4OUT;

	
}
