/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */
#include "button.h"

int KeyBuffer1[NUMBER_OF_BUTTONS];
int KeyBuffer2[NUMBER_OF_BUTTONS];
int KeyBuffer3[NUMBER_OF_BUTTONS];
int KeyBuffer4[NUMBER_OF_BUTTONS];

int flagForButtons[NUMBER_OF_BUTTONS];
int flagForButtonsLongPressed[NUMBER_OF_BUTTONS];
int timerForKeyPress[NUMBER_OF_BUTTONS];

int isButtonPressed(int index){
	if(index > NUMBER_OF_BUTTONS){
		return 0;
	}
	if(flagForButtons[index] == 1){
		flagForButtons[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(index > NUMBER_OF_BUTTONS){
		return 0;
	}
	if(flagForButtonsLongPressed[index] == 1){
		flagForButtonsLongPressed[index] == 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for(int i = 0; i < NUMBER_OF_BUTTONS; i++){
		KeyBuffer1[i] = KeyBuffer2[i];
		KeyBuffer2[i] = KeyBuffer3[i];
		switch(i){
		//Button 1
		case 0:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(BUT_RES_GPIO_Port, BUT_RES_Pin);
			break;
		//Button 2
		case 1:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(BUT_INC_GPIO_Port, BUT_INC_Pin);
			break;
		//Button 3
		case 2:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(BUT_DEC_GPIO_Port, BUT_DEC_Pin);
			break;
		default:
			break;
		}
		if((KeyBuffer1[i] == KeyBuffer2[i]) && (KeyBuffer2[i] == KeyBuffer3[i])){
			if(KeyBuffer3[i] != KeyBuffer4[i]){
				KeyBuffer4[i] = KeyBuffer3[i];

				if(KeyBuffer3[i] == PRESSED_STATE){
					timerForKeyPress[i] = 300;
					flagForButtons[i] = 1;
				}
			}else{
				timerForKeyPress[i]--;
				if(timerForKeyPress[i] == 0){
					flagForButtonsLongPressed[i] = 1;
					KeyBuffer4[i] = NORMAL_STATE;
				}
			}
		}
	}
}

