#ifndef _THREAD_PUSH_H_
#define _THREAD_PUSH_H_

#include "cmsis_os.h"

extern osMessageQId mesq_id;

extern osThreadId thread_push_id;

extern void thread_push_entry(void const * arg);

#endif
