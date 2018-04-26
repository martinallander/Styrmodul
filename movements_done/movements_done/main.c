#ifndef F_CPU
#define F_CPU 16000000UL					//Sätt CPU-klockan till 16 MHz
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "servo.h"
#include "uart.h"
#include "walk.h"
#include "lcd.h"
#include "led.h"


void main_init(void)
{
	DDRB |= 0x03;
	uart_init();
	led_blink_green(1);
	//spi_init();
	//data_direction_init();
	//LCD_Init();
	//LCD_Clear();
	servo_init();
	led_blink_green(1);
	//sei();
	stand();
	led_blink_green(1);
}

/************************************************************************************************************
************************************************  HUVUDFUNKTION  ********************************************
************************************************************************************************************/


int main(void)
{
	main_init();
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
