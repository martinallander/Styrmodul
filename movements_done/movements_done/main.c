#include "walk.h"
#include "lcd.h"

void main_init(void)
{
	spi_init();
	data_direction_init();
	led_blink_green(1);
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
	_delay_ms(2000);
	//DDRB |= 0x03;
	//uart_init();
	////led_blink_red(1);
	////spi_init();
	////data_direction_init();
	////LCD_Init();
	////LCD_Clear();
	//servo_init();
	////sei();
	//stand();
	////led_blink_red(1);
	//_delay_ms(1000);
	
	while(1)
	{
		led_blink_red(1);
	}
	
	/*
	char *lcdstring = "t(-_-t)";
	char *lcdstring2 = "CRINGEBOT xD";
	LCD_Command(0x14);
	LCD_Command(0x14);
	LCD_Command(0x14);
	LCD_Command(0x14);
	LCD_String(lcdstring);
	LCD_Command(0xc0);
	LCD_Command(0x14);
	LCD_Command(0x14);
	LCD_String(lcdstring2);

	stand();
	_delay_ms(2000);

	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			forward();
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
