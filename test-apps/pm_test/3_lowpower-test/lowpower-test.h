#ifndef __LOWPOWER_H__
#define __LOWPOWER_H__

#ifndef PWRMODE_THRESHOLD
#define PWRMODE_THRESHOLD	500
#endif // PWRMODE_THRESHOLD

#define	TASK_NUM		3

typedef struct _mytask {
	UINT32		tid;	// thread id
	UINT32		alid;	// alarm id
	UINT32		busywait;	// busywait time
	UINT32		period; // in msec
	UINT32		offset; // in msec
} mytask; // end struct

mytask my_task[TASK_NUM] = {
	{
		0,	// thread id
		0,	// alaram id
		10,	// busywait time (in msec)
		1500,	// period (in msec)
		0	// offset (in msec)
	},
	{0, 0, 30, 1700, 200},
	{0, 0, 50, 1000, 100}
};



#endif // __LOWPOWER_H__