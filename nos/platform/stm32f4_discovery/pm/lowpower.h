//

#include "nos.h"

#define IDLE_MODE	0
#define SLEEP_MODE	1
#define STOP_MODE	2
#define STANDBY_MODE	3
#define POWEROFF_MODE	4

// defines power mode threshold, if 0, ignored (default value)
#ifndef PWRMODE_IDLE_THRESHOLD
	#define PWRMODE_IDLE_THRESHOLD		0
#endif // PWRMODE_IDLE_THRESHOLD

#ifndef PWRMODE_SLEEP_THRESHOLD
	#define PWRMODE_SLEEP_THRESHOLD		100
#endif // PWRMODE_SLEEP_THRESHOLD

#ifndef PWRMODE_STOP_THRESHOLD
	#define PWRMODE_STOP_THRESHOLD		500
#endif // PWRMODE_STOP_THRESHOLD

#ifndef PWRMODE_STANDBY_THRESHOLD
	#define PWRMODE_STANDBY_THRESHOLD	7000
#endif // PWRMODE_STANDBY_THRESHOLD

#ifndef PWRMODE_PWROFF_THRESHOLD
	#define PWRMODE_PWROFF_THRESHOLD	0
#endif // PWRMODE_PWROFF_THRESHOLD



#ifndef RTC_SCALE
#define RTC_SCALE       145
#endif // RTC_SCLE


extern UINT32 actual_idle_tick;




void RTC_Configuration(uint32_t tick);
void SYSCLKConfig_STOP(void);

UINT32 lp_get_idle_mode(UINT32);
void lp_enter_sleep_mode(UINT32);
void lp_enter_stop_mode(UINT32);
void lp_enter_standby_mode(UINT32);
void lp_enter_pwroff_mode(UINT32);

void lp_save_context();
