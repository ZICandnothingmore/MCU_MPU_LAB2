/*
 * software_timer.h
 *
 *  Created on: Sep 15, 2024
 *      Author: ACER
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

void setTimer(int index, int duration);
void timer_run();
int isTimerExpired(int index);

#endif /* INC_SOFTWARE_TIMER_H_ */
