#ifndef __INITIAL_H__
#define __INITIAL_H__


#define GPIO(pin,fn_cfg,in_out,res_en_dis,pull_up_dwn,drive_4_8ma )  FN_##pin=fn_cfg;DD_##pin=in_out;PE_##pin=res_en_dis;PS_##pin=pull_up_dwn;DS_##pin=drive_4_8ma;



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
void InitBreakPoint  (void);
void InitISDDebug(void);


#endif
