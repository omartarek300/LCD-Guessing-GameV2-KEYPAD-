/*
 * LCD-Guessing-Game.c
 *
 * Created: 9/14/2021 4:42:29 PM
 * Author : Omar
 */ 

#include "APP/App.h"
#define ctrl_pins 0x07 // fist 3 pins
#define data_pins 0xf0 //higher data pins
int main(void)
{
	app_init();
	home_screen();
    while (1) 
    {
		app();
		
	}
}


