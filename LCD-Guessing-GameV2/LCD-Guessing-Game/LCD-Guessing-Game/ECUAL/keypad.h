/*
 * keypad.h
 *
 * Created: 9/17/2021 7:30:33 PM
 *  Author: Omar
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../MCAL/dio.h"
#include "../types.h"
#define active_row 1
#define rows 4
#define  cols 4
#define initialze_rows 0x0F
#define enable_row 0b00010000
/******************************************************* GLOBAL VARIABLES **************************************************/
uint8_t port_name;
/******************************************************* FUNCTIONS PROTOTYPE ***********************************************/
/*******
Function Description: this function initializes kepad pins and select its port
parameter: port_var: gets the port name
return: none
*/
void keypad_init(uint8_t port_var);

/*******
Function Description: this function gets the number entered by user
parameter: none
return: number entered by user
*/
uint8_t get_key();

/*******
Function Description: this function maps keypad buttons to the equivalent ascii and integer
parameter: num: number from coming from keypad
return: equivalent ascii and integer of the keypad button
*/
uint8_t keypad_4x4_mapping(uint8_t num);

/*******
Function Description: this function enable internal pullup and switch between row pins
parameter: shift_value: number of shifts in port pins to set a specific pin
return: none
*/
void keypad_port(uint8_t shift_value);




#endif /* KEYPAD_H_ */