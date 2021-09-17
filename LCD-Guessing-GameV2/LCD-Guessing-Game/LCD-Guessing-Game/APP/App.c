/*
 * App.c
 *
 * Created: 9/15/2021 11:38:38 PM
 *  Author: Omar
 */ 
#include "App.h"
void app_init()
{
	config timer_conf = {timer1, compare, f_cpu_clk_1024, ticks}; // initialize timer1
	Timer_init(&timer_conf);
	lcd_config lcd_conf = {PD,PA,ctrl_pins,data_pins}; // initialize LCD
	DIO_init(PC,button);  // initialize Button pin
	LCD_init(lcd_conf);
	user_number = 0; //initial value
	keypad_init(PC);
	random_variable = random_num(min,max);
}

void get_user_press()
{
	/*if (GETBIT(TIFR,bit4) != compare_match_flag)
	{
		if(GETBIT(PINC, button))
		{
			delay_ms(300); // for debuncing
			if(GETBIT(PINC, button))
			{
				user_number++;
				go_to_row_column(1,7);
				LCD_intgerToString(user_number);
				config timer_conf = {timer1, compare, f_cpu_clk_1024, ticks};
				Timer_init(&timer_conf);
			}
		}
	}*/
	 key = get_key();
	if(key != enter)
	{
		user_number *= 10;
		user_number += key;
		go_to_row_column(second_row,7);
		LCD_intgerToString(user_number);	
	}
}
void check_user_number()
{
	/*if(GETBIT(TIFR,bit4) == compare_match_flag)
	{
		if(user_number < min)
		{
			send_cmd(CLEAR_COMMAND); // LCD at the beginning 
			go_to_row_column(0,0);
			send_string("YOU DIDN'T");
			go_to_row_column(1,0);
			send_string("CHOOSE A NUMBER");
		}
		else if(user_number > max)
		{
			send_cmd(CLEAR_COMMAND); //clear LCD at the beginning 
			go_to_row_column(0,0);
			send_string("THE VALID");
			go_to_row_column(1,0);
			send_string("NUMB WITHIN 1:15");
		}
		else
		{
			if(user_number == random_num(min,max))
			{
				send_cmd(CLEAR_COMMAND); //clear LCD at the beginning 
				go_to_row_column(0,0);
				send_string("YOU WON");
			}
			else
			{
				send_cmd(CLEAR_COMMAND); //clear LCD at the beginning 
				go_to_row_column(0,0);
				send_string("YOU LOS");
			}
			
		}
		user_number = 0;
		delay_ms(2000);
		home_screen();
		SETBIT(TIFR,bit4); // re-enable entering number
	}*/
	
	
	delay_ms(1000);
	if(key == enter)
	{
		go_to_row_column(second_row,7);
		LCD_intgerToString(user_number);
		if(user_number < min)
		{
			send_cmd(CLEAR_COMMAND); // LCD at the beginning
			go_to_row_column(first_row,0);
			send_string("YOU DIDN'T");
			go_to_row_column(second_row,0);
			send_string("CHOOSE A NUMBER");
		}
		else if(user_number > max)
		{
			send_cmd(CLEAR_COMMAND); //clear LCD at the beginning
			go_to_row_column(first_row,0);
			send_string("THE VALID");
			go_to_row_column(second_row,0);
			send_string("NUMB WITHIN 1:15");
		}
		else
		{
			if(user_number == random_variable)
			{
				send_cmd(CLEAR_COMMAND); //clear LCD at the beginning
				go_to_row_column(first_row,0);
				send_string("YOU WON");
			}
			else
			{
				send_cmd(CLEAR_COMMAND); //clear LCD at the beginning
				go_to_row_column(first_row,0);
				send_string("YOU LOS");
			}
			
		}
		user_number = 0;
		delay_ms(1000);
		home_screen();
	}
	
}
void home_screen()
{
	send_cmd(CLEAR_COMMAND); /* clear LCD at the beginning */
	go_to_row_column(first_row,0);
	send_string("please guess the");
	go_to_row_column(second_row,0);
	send_string("number:");
}
void app()
{
	get_user_press();
	check_user_number();
	/*go_to_row_column(1,7);
	user_number = get_key();
	LCD_intgerToString(user_number);*/
}