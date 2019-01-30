#ifndef __INITIAL_H__
#define __INITIAL_H__


#define sysclk   freq_80MHz


#define freq_4MHz 	0             // use debug baud rate 4800
#define freq_8MHz 	1					  	//use debug baud rate 9600
#define freq_10MHz 	2					  	//use debug baud rate 10473
#define freq_16MHz 	3					  	//use debug baud rate 9600
#define freq_20MHz 	4					  	//use debug baud rate 10473
#define freq_40MHz 	6					  	//use debug baud rate 9600
#define freq_80MHz 	7							//use debug baud rate 9600


void InitEXT(void);

void SystemClock(void);
void sInitUART1(void);
void sInitUART2(void);
void InitWatchDog(void);


void InitTimer01(void);
void InitTimer3(void);
void InitTimer4(void);
void InitTimer5(void);
void InitTimer6(void);


void InitComparator(void);
void Initepwm(void);
void InitGPIO(void);
void epwmOutputDisable(void);
void epwmOutputEnable(void);
void InitADC(void);
void InitDAC(void);
void InitBreakPoint(void);
void InitISDDebug(void);




#endif
