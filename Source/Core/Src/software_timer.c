/*
 * software_timer.c
 *
 *  Created on: Sep 15, 2024
 *      Author: ACER
 */

#include "software_timer.h"

int timer1_flag = 0;
int timer1_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;

void setTimer1(int duration){
	timer1_counter = duration/10;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_counter = duration/10;
	timer2_flag = 0;
}

void timer_run(){
	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter <=0 ){
			timer1_flag = 1;
		}
	}
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter <=0 ){
			timer2_flag = 1;
		}
	}
}
