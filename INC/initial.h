#ifndef __INITIAL_H__
#define __INITIAL_H__





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
