/*
 * Ex3.c
 *
 *  Created on: 15 thg 9, 2024
 *      Author: ACER
 */

#include "Ex3.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

void update7SEG(int index){
	switch(index){
		case 0:
			//TODO
			break;
		case 1:
			//TODO
			break;
		case 2:
			//TODO
			break;
		case 3:
			//TODO
			break;
		default:
			break;
	}
}

void ex3_init(){
	update7SEG(index_led);
}

void ex3_run(){
	update7SEG(index_led++);
}
