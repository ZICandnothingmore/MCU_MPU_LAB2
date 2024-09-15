/*
 * software_timer.h
 *
 *  Created on: Sep 15, 2024
 *      Author: ACER
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int timer1_flag;

void setTimer1(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
