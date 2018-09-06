#include "register.h"
#include <intrins.h>
#include "app.h"
#include "initial.h"


unsigned short uwCaptureTimer;
unsigned short uwDutyCycle = 400;

void PWM1_2_3Interrupt(void)  interrupt 9
{
    unsigned char i,j;
    
    i = 0;
    j = i + 1;
    i++;
	//p0_0 = ~p0_0;
//	P1CMPA_L = (unsigned char)uwDutyCycle;
//	P1CMPA_H = (unsigned char)(uwDutyCycle >> 8);
//	P2CMPA_L = (unsigned char)uwDutyCycle;
//	P2CMPA_H = (unsigned char)(uwDutyCycle >> 8);
//	P3CMPA_L = (unsigned char)uwDutyCycle;
//	P3CMPA_H = (unsigned char)(uwDutyCycle >> 8);
//	P4CMPA_L = (unsigned char)uwDutyCycle;
//	P4CMPA_H = (unsigned char)(uwDutyCycle >> 8);
//	P1CMPB_L = (unsigned char)uwDutyCycle;
//	P1CMPB_H = (unsigned char)(uwDutyCycle >> 8);
//	P2CMPB_L = (unsigned char)uwDutyCycle;
//	P2CMPB_H = (unsigned char)(uwDutyCycle >> 8);
//	P3CMPB_L = (unsigned char)uwDutyCycle;
//	P3CMPB_H = (unsigned char)(uwDutyCycle >> 8);
//	P4CMPB_L = (unsigned char)uwDutyCycle;
//	P4CMPB_H = (unsigned char)(uwDutyCycle >> 8);
	P1ETCLR = 1;
	IEX2 = 0;
}

void PWM4Interrupt(void)  interrupt 10
{
	iex3 = 0;
}

unsigned char ubADSampleON;
unsigned short uwADDelayCounter = 1;
unsigned char ubADCCounter;
void TIMER0Interrupt(void)  interrupt 1 using 1
{
   // p0_0 = ~p0_0;
	//wdt = 1;
	//swdt = 1;
	//if(p1_0) th0 = 1;
    //DAC1_data = DAC0_data = ubSineTable[ubSineIndex++];
//	p0_3 = ~p0_3;
//	p0_6 = ~p0_6;
//	p0_7 = ~p0_7;
//	p1_2 = ~p1_2;
//	p1_3 = ~p1_3;
//	p1_4 = ~p1_4;
//	p1_5 = ~p1_5;
//    if((ADFLG & 0x01) == 0x01)
//    {
//        p0_0 = ~p0_0;
//    }
    ADCTL = 0x21;
    if(uwADDelayCounter)
    {
        if(++uwADDelayCounter >= 2000)
        {
            uwADDelayCounter = 0;
            ubADSampleON = 1;
        }
    }
//    if(ubADCCounter < 10)
//    {
//        ubADCCounter++;
//        ADCTL = 0x21;
//    }
}

void TIMER1Interrupt(void)  interrupt 3
{
    //p0_1 = ~p0_1;
    P26 = ~P26;
}

void TIMER3Interrupt(void)  //interrupt 2
{
    //p0_0 = ~p0_0;
	T3CON = T3CON & 0x7F;
	//iex1 = 0;
}

void TIMER4Interrupt(void)  interrupt 17
 {
	iex6 = 0;
}

void Comp234Interrupt(void)  interrupt 11
{
    //if(COMP_INT_REG & 0x04) p0_0 = ~p0_0;
    //p0_0 = ~p0_0;
	if(COMP_INT & 0x04)
	{
		T3CTR_L = 0;
		T3CTR_H = 0;
		uwCaptureTimer = (unsigned short)T3RC_L + (unsigned short)((unsigned short)T3RC_H << 8);
		//p0_0 = ~p0_0;
	}
	COMP_INT = 0;
	iex4 = 0;
}

void OCInterrupt(void) interrupt 2
{
	//p0_0 = ~p0_0;
	if(0x01 == (COMP_INT & 0x01))
	{
		COMP_INT = COMP_INT & 0xFE;
	}
}

//EXI interrupt routine: including comp1(overcurrent protect), timer3(overflow & external flag)
//don't need clear the interrupt ex1 flag
void EX1Interrupt(void)// interrupt 2
{
    //overcurrent protect
    if(COMP_INT & 0x01 == 0x01)
    {
        COMP_INT &= 0xfe;        //clear the interrupt flag
        ENABLE_TIME0();
    }

    //timer3 external flag
    if(T3CON & 0x40 == 0x40)
    {
        T3CON &= 0xbf;	
    }

    //timer3 overflow flag
    if(T3CON & 0x80 == 0x80)
    {
        T3CON &= 0x7f;
    }
}

void UART1Interrupt(void) //interrupt 4
{

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

//unsigned char ubADSampleON;
short swAAUU,swAAYY,swAARR;
unsigned short uwAAUU,uwAAYY,uwAARR;
unsigned short uwADIndex;
short swADBuf[256],swADBuf2[256],swADBuf3[256];
//unsigned short uwADBuf[256],uwADBuf2[256],uwADBuf3[256];
void ADCInterrupt(void) interrupt 8
{
    unsigned char tubADFLG;

    P00 = ~P00;
    tubADFLG = ADFLG;
//    if(ubADSampleON)
//    {
//        //uwAAUU = (unsigned short)AD4OUT_L + (unsigned short)((unsigned short)AD4OUT_H << 8);
//        //uwAAUU = (unsigned short)AD5OUT_L + (unsigned short)((unsigned short)AD5OUT_H << 8);
//        //uwAAUU = (unsigned short)AD6OUT_L + (unsigned short)((unsigned short)AD6OUT_H << 8);
//        //uwAAUU = (unsigned short)AD1OUT_L + (unsigned short)((unsigned short)AD1OUT_H << 8);
//        //uwAAUU = (unsigned short)AD3OUT_L + (unsigned short)((unsigned short)AD3OUT_H << 8);
//        //uwAAUU = (unsigned short)AD2OUT_L + (unsigned short)((unsigned short)AD2OUT_H << 8);
//        //uwAAYY = (unsigned short)AD1OUT_L + (unsigned short)((unsigned short)AD1OUT_H << 8);
//        //uwAARR = (unsigned short)AD2OUT_L + (unsigned short)((unsigned short)AD2OUT_H << 8);
//        ////uwAAUU = (unsigned short)AD4OUT_L + (unsigned short)((unsigned short)AD4OUT_H << 8);
//        ////uwAAYY = (unsigned short)AD5OUT_L + (unsigned short)((unsigned short)AD5OUT_H << 8);
//        ////uwAARR = (unsigned short)AD6OUT_L + (unsigned short)((unsigned short)AD6OUT_H << 8);

//        swAAUU = (short)((unsigned short)AD1OUT_L + (unsigned short)((unsigned short)AD1OUT_H << 8));
//        swAAYY = (short)((unsigned short)AD2OUT_L + (unsigned short)((unsigned short)AD2OUT_H << 8));
//        swAARR = (short)((unsigned short)AD3OUT_L + (unsigned short)((unsigned short)AD3OUT_H << 8));

//        //swAAUU = (short)((unsigned short)AD4OUT_L + (unsigned short)((unsigned short)AD4OUT_H << 8));
//        //swAAYY = (short)((unsigned short)AD5OUT_L + (unsigned short)((unsigned short)AD5OUT_H << 8));
//        //swAARR = (short)((unsigned short)AD6OUT_L + (unsigned short)((unsigned short)AD6OUT_H << 8));

//        //uwADBuf[uwADIndex] = uwAAUU;
//        //uwADBuf2[uwADIndex] = uwAAYY;
//        //uwADBuf3[uwADIndex] = uwAARR;

//        swADBuf[uwADIndex] = swAAUU;
//        swADBuf2[uwADIndex] = swAAYY;
//        swADBuf3[uwADIndex] = swAARR;

//        if(++uwADIndex >= 256) uwADIndex = 0;
//        if(0 == uwADIndex) ubADSampleON = 0;
//    }
    uwAAUU = (unsigned short)AD7OUT_L + (unsigned short)((unsigned short)AD7OUT_H << 8);
    IADC = 0;             //clr the interrupt flag
}

//unsigned short uwAAUU;
//volatile unsigned char ubAACC,ubAAEE;
//void ADCInterrupt(void) interrupt 8
//{
//    ubAACC = ADFLG;
//    //ubAAEE = ADFLG;
//    p0_0 = ~p0_0;
//    uwAAUU = (unsigned short)AD1OUT_L + (unsigned short)((unsigned short)AD1OUT_H << 8);
//    iadc = 0;             //clr the interrupt flag
//}


//unsigned char ubAACC;
//void ADCInterrupt(void) interrupt 8
//{
//    unsigned char i,j;
//    
//    j = ADFLG;
//    //ubAACC = ADFLG;
//    i = ADFLG;
//    i = 0;
//    j = i + 1;
//    p0_0 = ~p0_0;
//    //j = ADFLG;
//    //ADFLG = 0;
//    //for(i = 0;i < 30;i++);
//    //ubAACC = ADFLG;
//    i = iadc;
//    iadc = 0;             //clr the interrupt flag
//}

//void ADCInterrupt(void) interrupt 8
//{
//    unsigned char i,j;
//    
//    i = 0;
//    j = i + 1;
//    p0_0 = ~p0_0;
//    j = ADFLG;
//    j = i - 1;
//    i--;
//    j++;
//    i = iadc;
//    iadc = 0;             //clr the interrupt flag
//}
