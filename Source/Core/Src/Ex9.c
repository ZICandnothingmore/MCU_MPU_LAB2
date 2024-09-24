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
//	  0x00, 0x3C, 0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x00
//};

void updateLEDMATRIX(int index){
	// Ensure index is within valid range
	    if (index < 0 || index >= MAX_LED_MATRIX) {
	        return; // Do nothing for invalid index
	    }

	    switch (index) {
	        case 0:
	            matrix_buffer[0] = 0xFF; // Example: Set first row/column to all ON
	            break;
	        case 1:
	            matrix_buffer[1] = 0xFE; // Example: Set second row/column
	            break;
	        case 2:
	            matrix_buffer[2] = 0xFD;
	            break;
	        case 3:
	            matrix_buffer[3] = 0xFB;
	            break;
	        case 4:
	            matrix_buffer[4] = 0xF7;
	            break;
	        case 5:
	            matrix_buffer[5] = 0xEF;
	            break;
	        case 6:
	            matrix_buffer[6] = 0xDF;
	            break;
	        case 7:
	            matrix_buffer[7] = 0xBF;
	            break;
	        default:
	            break;
	    }
}

void ex9_init(){
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, 1);
	HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 0);
}
//
void ex9_run(){
	updateLEDMATRIX(index_led_matrix);
	index_led_matrix++;
	if (index_led_matrix > 3) index_led_matrix = 0;
}

