/*
 * keypad.c
 *
 * Created: 9/17/2021 7:31:01 PM
 *  Author: Omar
 */ 
#include "keypad.h"
void keypad_init(uint8_t port_var)
{
	port_name = port_var;
	DIO_init(port_name, initialze_rows); //initialize rows as output pins
}
uint8_t get_key()
{	
	while(1)
	{
		for(uint8_t row_iterator =0; row_iterator < rows; row_iterator++) //loop for rows
		{
			keypad_port(row_iterator); // enable internal pullup and switch between row pins
			for(uint8_t col_iterator =0; col_iterator < cols; col_iterator++) // loop for columns
			{
				if(GETBIT(PINC,col_iterator)==0) // if key is pressed
				{
					return keypad_4x4_mapping((col_iterator * rows) + row_iterator + 1);
				}
			}
			
		}
	}
}
uint8_t keypad_4x4_mapping(uint8_t num)
{
	switch(num)
	{
		case 1: return 7;
		break;
		case 2: return 4;
		break;
		case 3: return 1;
		break;
		case 4: return 13; 
		break;
		case 5: return 8;
		break;
		case 6: return 5;
		break;
		case 7: return 2;
		break;
		case 8: return 0; 
		break;
		case 9: return 9;
		break;
		case 10: return 6;
		break;
		case 11: return 3;
		break;
		case 12: return '='; /* ASCII Code of '=' */
		break;
		case 13: return '/';  /* ASCII of / */
		break;
		case 14: return '*';/* ASCII Code of '*' */
		break;
		case 15: return '-'; /* ASCII Code of '-' */
		break;
		case 16: return '+'; 
		break;
		default: return num;
	}
}
void keypad_port(uint8_t shift_value)
{
	switch(port_name)
	{
		case PA:
		{	
			DDRA = enable_row << shift_value;
			PORTA = (~(enable_row<< shift_value));
		}
		break;
		case PB:
		{
			DDRB = enable_row << shift_value;
			PORTB = (~(enable_row<< shift_value));
		}
		break;
		case PC:
		{
			DDRC = enable_row << shift_value;
			PORTC = (~(enable_row<< shift_value));
		}
		break;
		case PD:
		{
			DDRD = enable_row << shift_value;
			PORTD = (~(enable_row<< shift_value));
		}
		break;
	}
}