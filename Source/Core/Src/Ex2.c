/*
 * Ex2.c
 *
 *  Created on: Sep 15, 2024
 *      Author: ACER
 */

#include "Ex2.h"

int status = 1;

void display7SEG(int num){
	if (num == 0){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 1);
	}
	if (num == 1){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 1);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 1);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 1);
	}
	if (num == 2){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 1);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 0);
	}
	if (num == 3){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 0);
	}
	if (num == 4){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 1);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 1);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 0);
	}
	if (num == 5){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 1);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 0);
	}
	if (num == 6){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 1);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 0);
	}
	if (num == 7){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 1);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 1);
	}
	if (num == 8){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 0);
	}
	if (num == 9){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 0);
	}
}

void ex2_init(){

}

void ex2_run(){
	switch(status){
		case 1:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(1);
			status = 2;
			break;
		}
		case 2:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(2);
			status = 3;
			break;
		}
		case 3:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG(3);
			status = 0;
			break;
		}
		case 0:{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			display7SEG(0);
			status = 1;
			break;
		}
		default:
			break;
	}
}
