/*
 * Ex9.c
 *
 *  Created on: Sep 21, 2024
 *      Author: ACER
 */

#include "Ex9.h"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
//unsigned char A[] = {
//    B00000000,
//    B00111100,
//    B01100110,
//    B01100110,
//    B01111110,
//    B01100110,
//    B01100110,
//    B01100110
//};

void updateLEDMATRIX(int index){
	switch (index){
		case 0:{
			HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 0);
					break;
		}
		case 1:{
			HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 0);
					break;
		}
		case 2:{
					break;
		}
		case 3:{
					break;
		}
		case 4:{
					break;
		}
		case 5:{
					break;
		}
		case 6:{
					break;
		}
		case 7:{
					break;
		}
		default:{
					break;
		}
	}
}

void ex9_init(){
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, 1);
	HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 0);
}

void ex9_run(){
	updateLEDMATRIX(index_led_matrix);
	index_led_matrix++;
	if (index_led_matrix > 8) index_led_matrix = 0;
}

