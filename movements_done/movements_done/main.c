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
	
	_delay_ms(2000);
	stand();
	_delay_ms(5000);
	led_blink_red(1);
	
	while(1){set_data_sending(false);}
	/*
	while(1)
	{
		for(int i = 0; i < 10; i++)
		{
			forward_new();
		}
		
		for(int i = 0; i < 5; i++)
		{
			backward();
		}
		
		for(int i = 0; i < 5; i++)
		{
			rot_left();
		}
		
		for(int i = 0; i < 5; i++)
		{
			rot_right();
		}
		
		for(int i = 0; i < 3; i++)
		{
			forward_left();
		}
		
		for(int i = 0; i < 3; i++)
		{
			forward_right();
		}
		
	}	
*/
	return 0;
}
