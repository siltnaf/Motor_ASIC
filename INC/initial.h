#ifndef __INITIAL_H__
#define __INITIAL_H__

void sSystemClockConfig(void);
void sInitUART1(void);
void sInitUART2(void);
void InitLED(void);
void InitWatchDog(void);
void InitTimer3(void);
void InitComp234(void);
void Initepwm(void);
void InitGPIO(void);
void epwmOutputDisable(void);
void epwmOutputEnable(void);
void InitADC(void);
void InitBreakPoint  (void);

#endif
