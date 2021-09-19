/*
 * timers_status_regs.c
 *
 * Created: 9/19/2021 5:10:54 PM
 *  Author: Omar
 */ 
#include "timers_HAL.h"
void initiate_timer(const config* conf)
{
	Timer_init(conf);
}
uint8_t get_timer_state(uint8_t bit_num)
{
	return GETBIT(TIFR, bit_num);
}
void set_status_reg(uint8_t bit_num)
{
	 SETBIT(TIFR, bit_num);
}
