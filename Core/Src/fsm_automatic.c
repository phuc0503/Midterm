/*
 * fsm_automatic.c
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */
#include "fsm_automatic.h"
#include "led7seg.h"
void fsm_automatic_run(){
	switch(status){
	case INIT:
		status = AUTO;
		break;
	case AUTO:
		if(timer2_flag == 1){
			status = AUTO;
			display7SEG(counter);
			if(counter > 0){
				counter--;
			}
			setTimer2(1000);
		}
		if(isButtonPressed(0)== 1){
			status = RES;
			counter = 0;
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(1) == 1){
			status = INC;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(2) == 1){
			status = DEC;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		break;
	case INC:
		if(timer2_flag == 1){
			status = AUTO;
			display7SEG(counter);
			if(counter > 0){
				counter--;
			}
			setTimer2(1000);
		}
		if(isButtonPressed(0)== 1){
			status = RES;
			counter = 0;
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(1) == 1){
			status = INC;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(2) == 1){
			status = DEC;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		break;
	case DEC:
		if(timer2_flag == 1){
			status = AUTO;
			display7SEG(counter);
			if(counter > 0){
				counter--;
			}
			setTimer2(1000);
		}
		if(isButtonPressed(0)== 1){
			status = RES;
			counter = 0;
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(1) == 1){
			status = INC;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(2) == 1){
			status = DEC;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		break;
	case RES:
		if(isButtonPressed(1) == 1){
			status = INC;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(2) == 1){
			status = DEC;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonLongPressed(1)){
			status = INC_LONG;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonLongPressed(2)){
			status = DEC_LONG;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		break;
	case INC_LONG:
		if(isButtonLongPressed(1)){
			status = INC_LONG;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonLongPressed(2)){
			status = DEC_LONG;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(timer2_flag == 1){
			status = AUTO;
			display7SEG(counter);
			if(counter > 0){
				counter--;
			}
			setTimer2(1000);
		}
		if(isButtonPressed(0)){
			status = RES;
			counter = 0;
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(1) && !isButtonLongPressed(1)){
			status = INC;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(2)){
			status = DEC;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		break;
	case DEC_LONG:
		if(isButtonLongPressed(1)){
			status = INC_LONG;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonLongPressed(2)){
			status = DEC_LONG;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(timer2_flag == 1){
			status = AUTO;
			display7SEG(counter);
			if(counter > 0){
				counter--;
			}
			setTimer2(1000);
		}
		if(isButtonPressed(0)){
			status = RES;
			counter = 0;
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(1)){
			status = INC;
			if(counter < 9){
				counter++;
			}else{
				counter = 0;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		if(isButtonPressed(2)){
			status = DEC;
			if(counter > 0){
				counter--;
			}else{
				counter = 9;
			}
			display7SEG(counter);
			setTimer2(10000);
		}
		break;
	default:
		break;
	}
}


