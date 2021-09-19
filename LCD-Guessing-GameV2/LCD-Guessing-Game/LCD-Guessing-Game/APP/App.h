/*
 * App.h
 *
 * Created: 9/15/2021 11:38:52 PM
 *  Author: Omar
 */ 


#ifndef APP_H_
#define APP_H_
#include <stdlib.h>
#include "../ECUAL/LCD.h"
#include "../ECUAL/keypad.h"
#include "../ECUAL/timers_HAL.h"
#define button 0x00
#define ticks (float)3906.25 // 4 seconds
#define ctrl_pins 0x07 // fist 3 pins
#define data_pins 0xf0 //higher data pins
#define min 1
#define max 15
#define compare_match_flag 0x10
#define random_num(min,max) (((rand()) %((max) - (min) + (1))) + (min))
#define enter 13
/**************************************GLOBAL VARIABLES***************************************/
uint8_t user_number;
uint8_t random_variable;
uint8_t key;
/**************************************FUNCTIONS PROTOTYPES**********************************/

/*******
Function Description: this function initiates timer and LCD and Button pins
parameter: none
return: none
*/
void app_init();

/*******
Function Description: this function gets the number entered by user
parameter: none
return: none
*/
void get_user_press();

/*******
Function Description: this function checks the user input if it within range or not and in case it was in the range it out the result of the game
parameter: none
return: none
*/
void check_user_number();

/*******
Function Description: this function displays the home screen of the game every trial
parameter: none
return: none
*/
void home_screen();

/*******
Function Description: this function organizes the flow of the program
parameter: none
return: none
*/
void app();


#endif /* APP_H_ */