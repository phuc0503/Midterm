/*
 * led7seg.c
 *
 *  Created on: Nov 5, 2022
 *      Author: DELL
 */
#include "led7seg.h"

void display7SEG(int num){
	  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D_Pin|E_Pin|F_Pin|G_Pin, SET);

	  switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D_Pin|E_Pin|F_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, B_Pin|C_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|D_Pin|E_Pin|G_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D_Pin|G_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, B_Pin|C_Pin|F_Pin|G_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, A_Pin|C_Pin|D_Pin|F_Pin|G_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, A_Pin|C_Pin|D_Pin|E_Pin|F_Pin|G_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D_Pin|E_Pin|F_Pin|G_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D_Pin|F_Pin|G_Pin, RESET);
			break;
	 }
 }
