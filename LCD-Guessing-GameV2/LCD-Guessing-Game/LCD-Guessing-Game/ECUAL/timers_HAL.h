/*
 * timers_status_regs.h
 *
 * Created: 9/19/2021 5:10:20 PM
 *  Author: Omar
 */ 


#ifndef TIMERS_STATUS_REGS_H_
#define TIMERS_STATUS_REGS_H_
#include "../MCAL/timer.h"
#include "../bit_operations.h"
/**************************************FUNCTIONS PROTOTYPES**********************************/

/*******
Function Description: this function initiates chosen timer
parameter: conf: is a structure contains all timer configurations timer number, mode, prescaler....
return: none
*/
void initiate_timer(const config* conf);

/*******
Function Description: this function checks a specific bit in timers status register
parameter: bit_num: is the bit number you need to check
return: 1: if the bit was HIGH
		0: if the bit was LOW  
*/
uint8_t get_timer_state(uint8_t bit_num);


/*******
Function Description: this function sets a bit in timers status register
parameter: bit_num: is the bit number you need to set
return: none
*/
void set_status_reg(uint8_t bit_num);




#endif /* TIMERS_STATUS_REGS_H_ */