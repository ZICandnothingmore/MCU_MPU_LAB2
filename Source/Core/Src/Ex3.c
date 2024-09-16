/*
 * Ex3.c
 *
 *  Created on: 16 thg 9, 2024
 *      Author: ACER
 */

#include "Ex3.h"
 int hour = 15, minute = 8, second = 50;

void ex3_init(){

}
void ex3_run(){

}

void clock_run(){
	second ++;
	if (second >= 60){
		second = 0;
		minute++;
	}
	if (minute >= 60){
		minute = 0;
		hour++;
	}
	if (hour >= 12){
		hour = 0;
	}

}
