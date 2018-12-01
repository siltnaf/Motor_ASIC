#ifndef __APP_H__
#define __APP_H__

#define ENABLE_ISD   1
#define DISABLE_ISD  0
#define ISDDebug   ENABLE_ISD


// math parameter
#define PI 3.14159





//  GPIO parameter

#define CFG0			0
#define CFG1			1
#define CFG2			2
#define CFG3			3
#define OUTPUT		1
#define INPUT			0
#define RES_EN		1
#define RES_DIS		0
#define PULL_UP		1
#define PULL_DOWN	0
#define I_4MA			0
#define I_8MA			1


//BIT operation
#define BIT_0     (1)
#define BIT_1    (1<<1)
#define BIT_2     (1<<2)
#define BIT_3      (1<<3)
#define BIT_4      (1<<4)
#define BIT_5     (1<<5)
#define BIT_6      (1<<6)
#define BIT_7     (1<<7)




//EXT interrupt parameter
#define FALLING_EDGE	0
#define RISING_EDGE		1
#define BOTH_EDGE			2
#define LOW_LEVEL			3





#define mHighLevelEffective 1

#define mPeriod_L 0xD0     //0x07D0 = 2000   2000 * 12.5ns * 2 = 50us
#define mPeriod_H 0x07
#define mDeadTime_L  0xA0  //0x00A0 = 160  160 * 12.5ns = 2us
#define mDeadTime_H  0x00

//all interrupt
#define ENABLE_ALL_INTERRUPT()  EAL = 1
#define DISABLE_ALL_INTERRUPT()  EAL = 0

//external interrupt 0, including EXINT1, EXINT2, EXINT3, EXINT4
#define ENABLE_EX0_INTERRUPT()   EX0 = 1
#define DISABLE_EX0_INTERRUPT()   EX0 = 0

//timer 0 overflow interrupt
#define ENABLE_TIME0_OVERFLOW_INTERRUPT()  ET0 = 1
#define DISABLE_TIME0_OVERFLOW_INTERRUPT()   ET0 = 0

//external interrupt 1, including comp1(overcurrent protect), timer3(overflow & external flag)
#define ENABLE_EX1_INTERRUPT()   IT1 = 1;EX1 = 1
#define DISABLE_EX1_INTERRUPT()   IT1 = 1;EX1 = 0

//timer 1 overflow interrupt
#define ENABLE_TIME1_OVERFLOW_INTERRUPT()   ET1= 1
#define DISABLE_TIME1_OVERFLOW_INTERRUPT()   ET1 = 0

//UART1 interrupt
#define ENABLE_UART1_INTERRUPT()   ES0 = 1
#define DISABLE_UART1_INTERRUPT()   ES1 = 0

//ADC interrupt
#define ENABLE_ADC_INTERRUPT()   ADCTL |= 0x01;EADC = 1
#define DISABLE_ADC_INTERRUPT()   ADCTL &= 0xfe;EADC = 0

//external interrupt 2, including PWM1, PWM2, PWM3
#define ENABLE_PWM1_2_3_INTERRUPT()   I2FR = 1;EX2 = 1
#define DISABLE_PWM1_2_3_INTERRUPT()   I2FR = 1;EX2 = 0

//external interrupt 3, including PWM4
#define ENABLE_PWM4_INTERRUPT()   I3FR = 1;EX3 = 1
#define DISABLE_PWM4_INTERRUPT()   I3FR = 1;EX3 = 0

//external interrupt 4, including comp2, comp3, comp4
#define ENABLE_EX4_INTERRUPT()   EX4 = 1
#define DISABLE_EX4_INTERRUPT()   EX4 = 0

//external interrupt 5, including I2C, SPI, SPI_eflash
#define ENABLE_EX5_INTERRUPT()   EX5 = 1
#define DISABLE_EX5_INTERRUPT()   EX5 = 0

//external interrupt 6, including RTC, LVD18, LVD33, timer4, hwbp(hardware breakpoint)
#define ENABLE_EX6_INTERRUPT()   EX6 = 1
#define DISABLE_EX6_INTERRUPT()   EX6 = 0

//UART2 interrupt
#define ENABLE_UART2_INTERRUPT()   IEN2 = 0X01
#define DISABLE_UART2_INTERRUPT()   IEN2 = 0X00

#define ENABLE_TIMER3()  T3CON |= 0x04               //enable timer3
#define DISABLE_TIME3()  T3CON &= 0XFB               //disable timer3

#define ENABLE_TIMER4()  T4CON |= 0x04               //enable timer4
#define DISABLE_TIME4()  T4CON &= 0XFB               //disable timer4

#define TIME01_CLKDIV_SET(LOW_8BIT, HIGH_8BIT)  TIM01_CLK_DIV_L = LOW_8BIT;TIM01_CLK_DIV_H = HIGH_8BIT
#define ENABLE_TIME0()   TR0 = 1
#define DISABLE_TIME0()  TR0 = 0
#define ENABLE_TIME1()   TR1 = 1
#define DISABLE_TIME1()  TR1 = 0

#define ADC_CALIBRATE_REFP()  ADCTL |= 0x06
#define ADC_CALIBRATE_REFN()  ADCTL &= 0xfd;ADCTL |= 0x04

#define ADC_START()  ADCTL |= 0x20
#define ADC_BUSY     (ADCTL & 0x40)




//extern unsigned char ucUARTReceiver;
//extern unsigned char ucReceiveFlag;

extern unsigned int xdata ADresult;
extern unsigned char xdata tmr3_ov,capture_flag;
extern unsigned long xdata last_capture,this_capture,pwm_capture;




#endif
