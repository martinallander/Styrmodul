#include "walk.h"
#include <stdbool.h>

void main_init(void)
{
	spi_init();
	data_direction_init();
	uart_init();
	servo_init();
}

/************************************************************************************************************
************************************************  HUVUDFUNKTION  ********************************************
************************************************************************************************************/


int main(void)
{
	main_init();
	_delay_ms(1000);
	stand();
	_delay_ms(1000);
	led_blink_red(1);
	led_blink_green(1);



	while(1)
	{
		set_data_sending(false);
	}
	
/*

		for (int i = 0; i < 18; i++)
		{
			walk_forward_left();
		}
		

	
    
	
	for (int i = 0; i < 18; i++)
	{
		reg_servo_angle(i, 150);
		action();
		_delay_ms(1000);
	}
	
	
    while(1)
	{
		set_data_sending(false);
	}
	
	
	while(1)
	{
		for(int i = 0; i < 3; i++)
		{
			forward_new();
		}
			
		for(int i = 0; i < 3; i++)
		{
			backward();
		}
			
		for(int i = 0; i < 3; i++)
		{
			rot_left();
		}
			
		for(int i = 0; i < 3; i++)
		{
			rot_right();
		}
			
		for(int i = 0; i < 3; i++)
		{
			turn_left();
		}
			
		for(int i = 0; i < 3; i++)
		{
			turn_right();
		}
		
		const uint8_t params1[2] = {SERVO_ID, 16};
		send_servo_command(1, WRITE, 2, params1);
			
	}
	


	for (int i = 0; i < 18; i++)
	{
		set_servo_angle(i, 150);
		_delay_ms(1000);
	}
	
	

	
*/
	return 0;
}
