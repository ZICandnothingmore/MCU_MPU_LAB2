/*
 * Ex9.c
 *
 *  Created on: Sep 21, 2024
 *      Author: ACER
 */

#include "Ex9.h"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
//uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
//const int MAX_LED_MATRIX = 8;
uint8_t matrix_buffer[8] = {0x00, 0xfc, 0xfe, 0x33, 0x33, 0xfe, 0xfc, 0x00};
int scanner_COL[8] = {1, 2, 4, 8, 16, 32, 64, 128};

//void updateLEDMATRIX(int num) {
//	switch (num){
//		case 0:
//			HAL_GPIO_WritePin(GPIOB, ROW0_Pin, GPIO_PIN_RESET);
//			break;
//		case 1:
//			HAL_GPIO_WritePin(GPIOB, ROW1_Pin, GPIO_PIN_RESET);
//			break;
//		case 2:
//			HAL_GPIO_WritePin(GPIOB, ROW2_Pin, GPIO_PIN_RESET);
//			break;
//		case 3:
//			HAL_GPIO_WritePin(GPIOB, ROW3_Pin, GPIO_PIN_RESET);
//			break;
//		case 4:
//			HAL_GPIO_WritePin(GPIOB, ROW4_Pin, GPIO_PIN_RESET);
//			break;
//		case 5:
//			HAL_GPIO_WritePin(GPIOB, ROW5_Pin, GPIO_PIN_RESET);
//			break;
//		case 6:
//			HAL_GPIO_WritePin(GPIOB, ROW6_Pin, GPIO_PIN_RESET);
//			break;
//		case 7:
//			HAL_GPIO_WritePin(GPIOB, ROW7_Pin, GPIO_PIN_RESET);
//			break;
//		default:
//			HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin
//									|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, GPIO_PIN_SET);
//			break;
//	}
//}

void displayLEDMatrix(int num) {
	switch (num){
	        case 0:
				HAL_GPIO_WritePin(GPIOB, ROW0_Pin, GPIO_PIN_RESET);
	            break;
	        case 1:
				HAL_GPIO_WritePin(GPIOB, ROW1_Pin, GPIO_PIN_RESET);
	            break;
	        case 2:
				HAL_GPIO_WritePin(GPIOB, ROW2_Pin, GPIO_PIN_RESET);
	            break;
	        case 3:
				HAL_GPIO_WritePin(GPIOB, ROW3_Pin, GPIO_PIN_RESET);
	            break;
	        case 4:
				HAL_GPIO_WritePin(GPIOB, ROW4_Pin, GPIO_PIN_RESET);
	            break;
	        case 5:
				HAL_GPIO_WritePin(GPIOB, ROW5_Pin, GPIO_PIN_RESET);
	            break;
	        case 6:
				HAL_GPIO_WritePin(GPIOB, ROW6_Pin, GPIO_PIN_RESET);
	            break;
	        case 7:
				HAL_GPIO_WritePin(GPIOB, ROW7_Pin, GPIO_PIN_RESET);
	            break;
	        default:
				HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin
										|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, GPIO_PIN_SET);
	            break;
	}
}

void updateLEDMatrix(int index){
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
    for(int row = 0; row < MAX_LED_MATRIX; ++row) {
    	if((scanner_COL[row] & matrix_buffer[index]) > 0) {
    		displayLEDMatrix(row);
    	}
    }
}

void ex9_init(){
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, 1);
	HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 1);
}
//
void ex9_run(){
	displayLEDMatrix(-1);
	updateLEDMatrix(index_led_matrix++);
	index_led_matrix = index_led_matrix % MAX_LED_MATRIX;
}

