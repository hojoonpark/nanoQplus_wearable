//========================================================================
// File		: lowpower-test.c
// Author	: hj.park@etri.re.kr
// Date		: 2016.05.17
// Description : Test low-power mode
//========================================================================
// Copyright 2016-2025, ETRI
//========================================================================

#include "nos.h"

#include "lowpower-test.h"


#define Sleep		0
#define Stop		1
#define Standby		2
#define IDLE_MODE	0
#define SLEEP_MODE	1
#define STOP_MODE	2
#define STANDBY_MODE	3
#define POWEROFF_MODE	4



extern __IO uint8_t UserButtonStatus;

extern UINT32 Mode_On;
extern UINT32 dnode_delta;		// next idle time
extern UINT32 powermode_threshold;

// Thread body declaration
void my_task1(void *);

// 1ms busy wait
void my_busy_wait(UINT32 m){ 
	UINT32 i, n, a;
	
	a = 0;
	n = m * 9000;
	
	for (i = 0; i < n; i++) {
		a++;
	} // end for
} // end func

// Thread body definition & alarm handler
void my_task1_handler(UINT32 dummy) {
	UINT32 task_no;
	
	task_no = (UINT32)dummy;
	thread_activate(my_task[task_no].tid);
} // end func

void my_task1(void *dummy) {
	UINT32 task_no;
	
	task_no = (UINT32)dummy;
	my_busy_wait(my_task[task_no].busywait);
} // end func


void app_init(void) {
	
	UINT32 tid1;
	UINT32 alid1;
	
	int i;

	for (i = 0; i < TASK_NUM; i++) {
		thread_create(my_task1, (void *)i, 9, PRIORITY_NORMAL, FIFO, &tid1);
		
		my_task[i].tid = tid1;
		
		alarm_create(my_task1_handler, i,
			MSEC(my_task[i].offset),
			MSEC(my_task[i].period),
			&alid1);
		
		my_task[i].alid = alid1;
		
		alarm_start(my_task[i].alid);
	} // end for

} // end func


