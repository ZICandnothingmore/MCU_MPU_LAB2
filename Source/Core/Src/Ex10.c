/*
 * Ex10.c
 *
 *  Created on: 24 thg 9, 2024
 *      Author: ACER
 */

#ifndef SRC_EX10_C_
#define SRC_EX10_C_

#include "Ex10.h"

int shift = 1;

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
    if (shift == 1){
		for(int row = 0; row < MAX_LED_MATRIX; ++row) {
			if((scanner_COL[row] & matrix_buffer[index]) > 0) {
				displayLEDMatrix(row);
			}
		}
		shift--;
    }
    if (shift == 0){
		for(int row = 0; row < MAX_LED_MATRIX; ++row) {
			if((scanner_COL[row-1] & matrix_buffer[index-1]) > 0) {
				displayLEDMatrix(row);
			}
		}
		shift = 1;
    }
}

void ex10_init(){

}

void ex10_run(){
	displayLEDMatrix(-1);
	updateLEDMatrix_leftshift(index_led_matrix++);
	index_led_matrix = index_led_matrix % MAX_LED_MATRIX;
}


#endif /* SRC_EX10_C_ */
