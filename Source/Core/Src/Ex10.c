/*
 * Ex10.c
 *
 *  Created on: 24 thg 9, 2024
 *      Author: ACER
 */

#ifndef SRC_EX10_C_
#define SRC_EX10_C_

#include "Ex10.h"

const int MAX_LED_MATRIX_leftshift = 8;
const int MAX_FRAME_MATRIX = 16;
int index_led_matrix_leftshift = 0;
int index_frame_matrix = 0;
uint8_t matrix_buffer_leftshift[16][8] = {
								{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
								{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18},
								{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18},
								{0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18},
								{0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x99},
								{0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x99, 0xDB},
								{0x00, 0x00, 0x18, 0x18, 0x18, 0x99, 0xDB, 0x7E},
								{0x00, 0x18, 0x18, 0x18, 0x99, 0xDB, 0x7E, 0x3C},
								{0x18, 0x18, 0x18, 0x99, 0xDB, 0x7E, 0x3C, 0x18},
								{0x18, 0x18, 0x99, 0xDB, 0x7E, 0x3C, 0x18, 0x00},
								{0x18, 0x99, 0xDB, 0x7E, 0x3C, 0x18, 0x00, 0x00},
								{0x99, 0xDB, 0x7E, 0x3C, 0x18, 0x00, 0x00, 0x00},
								{0xDB, 0x7E, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00},
								{0x7E, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},
								{0x3C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
								{0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
								};
int scanner[8] = {1, 2, 4, 8, 16, 32, 64, 128};

void updateLEDMatrix_leftshift(int index){
	switch (index){
	        case 0:
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin
										|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_RESET);
	            break;
	        case 1:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin
										|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_RESET);
	            break;
	        case 2:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM3_Pin|ENM4_Pin
										|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_RESET);
	            break;
	        case 3:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM4_Pin
										|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_RESET);
	            break;
	        case 4:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin
										|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_RESET);
	            break;
	        case 5:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin
										|ENM4_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_RESET);
	            break;
	        case 6:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin
										|ENM4_Pin|ENM5_Pin|ENM7_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_RESET);
	            break;
	        case 7:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin
										|ENM4_Pin|ENM5_Pin|ENM6_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_RESET);
	            break;
	        default:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin
										|ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
	            break;
    }
    for(int row = 0; row < MAX_LED_MATRIX_leftshift; ++row) {
		if((matrix_buffer_leftshift[index_frame_matrix][index] & scanner[row]) > 0) {
			displayLEDMatrix(row);
		}
	}
}

void ex10_init(){

}

void ex10_run(){
	displayLEDMatrix(-1);
	updateLEDMatrix_leftshift(index_led_matrix_leftshift++);
	if(index_led_matrix_leftshift >= MAX_LED_MATRIX_leftshift) {
		index_led_matrix_leftshift = 0;
		index_frame_matrix++;
		index_frame_matrix = index_frame_matrix % MAX_FRAME_MATRIX;
	}
}


#endif /* SRC_EX10_C_ */
