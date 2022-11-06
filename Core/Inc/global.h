/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"

#define INIT 	    1
#define AUTO 		2
#define INC 		3
#define DEC 	    4
#define RES			5
#define INC_LONG	6
#define DEC_LONG	7

extern int status;
extern int counter;
#endif /* INC_GLOBAL_H_ */
