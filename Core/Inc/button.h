/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */
#include "main.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE 		SET
#define	PRESSED_STATE 		RESET
#define NUMBER_OF_BUTTONS	3

extern int flagForButtons[NUMBER_OF_BUTTONS];
extern int flagForButtonsLongPressed[NUMBER_OF_BUTTONS];

int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
