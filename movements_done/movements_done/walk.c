#include "walk.h"

bool is_moving = false;
bool data_sending = false;

const int delay_scale = 2;

/************************************************************************************************************
************************************************  RÖRELSEFUNKTIONER  ****************************************
************************************************************************************************************/

//Funktion för att roboten ska ställa sig upp
void stand(void)
{
	reg_servo_angle(0, STAND_DEG_00);
	reg_servo_angle(3, STAND_DEG_03);
	reg_servo_angle(6, STAND_DEG_06);
	reg_servo_angle(9, STAND_DEG_09);
	reg_servo_angle(12, STAND_DEG_12);
	reg_servo_angle(15, STAND_DEG_15);
	
	reg_servo_angle(1, STAND_DEG_01);
	reg_servo_angle(4, STAND_DEG_04);
	reg_servo_angle(7, STAND_DEG_07);
	reg_servo_angle(10, STAND_DEG_10);
	reg_servo_angle(13, STAND_DEG_13);
	reg_servo_angle(16, STAND_DEG_16);
	
	reg_servo_angle(2, STAND_DEG_02);
	reg_servo_angle(5, STAND_DEG_05);
	reg_servo_angle(8, STAND_DEG_08);
	reg_servo_angle(11, STAND_DEG_11);
	reg_servo_angle(14, STAND_DEG_14);
	reg_servo_angle(17, STAND_DEG_17);
	action();
}

/************************************************************************************************************
************************************************  FRAMÅT OCH BAKÅT  *****************************************
************************************************************************************************************/

//Funktioner som utgör gångstilarna för rörelse framåt och bakåt
void one(void)
{
	reg_servo_angle(6, 153);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	
	reg_servo_angle(9, 147);
	reg_servo_angle(10, 240);
	reg_servo_angle(11, 62);
	
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 64);
	reg_servo_angle(5, 237);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 208);
	reg_servo_angle(14, 73);
	
	reg_servo_angle(0, 147);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	
	reg_servo_angle(15, 153);
	reg_servo_angle(16, 240);
	reg_servo_angle(17, 62);
	
	_delay_ms(50*delay_scale);
	action();
}

void two(void)
{
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 87);
	reg_servo_angle(8, 237);
	
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 235);
	reg_servo_angle(11, 74);
	
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 70);
	reg_servo_angle(5, 236);
	
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 217);
	
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 240);
	reg_servo_angle(17, 60);
	
	_delay_ms(50*delay_scale);
	action();
}

void three(void)
{
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 87);
	reg_servo_angle(8, 237);
	
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 83);
	
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 217);
	
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 213);
	reg_servo_angle(17, 63);
	
	_delay_ms(50*delay_scale);
	action();
}

void four(void)
{
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 60);
	reg_servo_angle(8, 240);
	
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 83);
	
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 234);
	reg_servo_angle(14, 64);
	
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 60);
	reg_servo_angle(2, 226);
	
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 213);
	reg_servo_angle(17, 63);
	
	_delay_ms(50*delay_scale);
	action();
}

void five(void)
{
	reg_servo_angle(6, 153);
	reg_servo_angle(7, 60);
	reg_servo_angle(8, 238);
	
	reg_servo_angle(9, 147);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 92);
	reg_servo_angle(5, 227);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 235);
	reg_servo_angle(14, 63);
	
	reg_servo_angle(0, 147);
	reg_servo_angle(1, 60);
	reg_servo_angle(2, 238);
	
	reg_servo_angle(15, 153);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	
	_delay_ms(50*delay_scale);
	action();
}

void six(void)
{
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 60);
	reg_servo_angle(8, 226);
	
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 213);
	reg_servo_angle(11, 63);
	
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 235);
	reg_servo_angle(14, 64);
	
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 60);
	reg_servo_angle(2, 240);
	
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 83);
	
	_delay_ms(50*delay_scale);
	action();
}

void seven(void)
{
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 217);
	
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 213);
	reg_servo_angle(11, 63);
	
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 87);
	reg_servo_angle(2, 237);
	
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 83);
	
	_delay_ms(50*delay_scale);
	action();
}

void eight(void)
{
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 217);
	
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 240);
	reg_servo_angle(11, 60);
	
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 65);
	reg_servo_angle(5, 236);
	
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 87);
	reg_servo_angle(2, 237);
	
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 240);
	reg_servo_angle(17, 74);
	
	_delay_ms(50*delay_scale);
	action();
}

//Funktion för gång framåt
void forward(void)
{
	eight();
	one();
	two();
	three();
	four();
	five();
	six();
	seven();
}

//Funktion för gång bakåt
void backward(void)
{
	seven();
	six();
	five();
	four();
	three();
	two();
	one();
	eight();
}

/************************************************************************************************************
*********************************************  ROTERA HÖGER OCH VÄNSTER  ************************************
************************************************************************************************************/

//Funktionerna som utgör gångstilarna rotera höger och rotera vänster
void one_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 90);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 165);
	reg_servo_angle(10, 221);
	reg_servo_angle(11, 82);
	
	reg_servo_angle(3, 164);
	reg_servo_angle(4, 73);
	reg_servo_angle(5, 227);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 210);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 90);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 165);
	reg_servo_angle(16, 221);
	reg_servo_angle(17, 82);
	
	_delay_ms(50*delay_scale);
	action();
}

void two_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 90);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 178);
	reg_servo_angle(10, 211);
	reg_servo_angle(11, 95);
	
	reg_servo_angle(3, 176);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 224);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 210);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 90);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 178);
	reg_servo_angle(16, 211);
	reg_servo_angle(17, 95);
	
	_delay_ms(50*delay_scale);
	action();
}

void three_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 90);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 178);
	reg_servo_angle(10, 199);
	reg_servo_angle(11, 102);
	
	reg_servo_angle(3, 176);
	reg_servo_angle(4, 89);
	reg_servo_angle(5, 217);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 210);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 90);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 178);
	reg_servo_angle(16, 199);
	reg_servo_angle(17, 102);
	
	_delay_ms(50*delay_scale);
	action();
}

void four_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 70);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 178);
	reg_servo_angle(10, 199);
	reg_servo_angle(11, 102);
	
	reg_servo_angle(3, 176);
	reg_servo_angle(4, 89);
	reg_servo_angle(5, 217);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 230);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 70);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 178);
	reg_servo_angle(16, 199);
	reg_servo_angle(17, 102);
	
	_delay_ms(50*delay_scale);
	action();
}

void five_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 70);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 165);
	reg_servo_angle(10, 210);
	reg_servo_angle(11, 85);
	
	reg_servo_angle(3, 161);
	reg_servo_angle(4, 86);
	reg_servo_angle(5, 222);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 230);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 70);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 165);
	reg_servo_angle(16, 210);
	reg_servo_angle(17, 85);
	
	_delay_ms(50*delay_scale);
	action();
}

void six_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 70);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 211);
	reg_servo_angle(11, 82);
	
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 89);
	reg_servo_angle(5, 218);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 230);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 70);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 211);
	reg_servo_angle(17, 82);
	
	_delay_ms(50*delay_scale);
	action();
}

void seven_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 90);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 211);
	reg_servo_angle(11, 82);
	
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 89);
	reg_servo_angle(5, 218);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 210);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 90);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 211);
	reg_servo_angle(17, 82);
	
	_delay_ms(50*delay_scale);
	action();
}

void eight_rot(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 90);
	reg_servo_angle(8, 220);
	
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 226);
	reg_servo_angle(11, 75);
	
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 74);
	reg_servo_angle(5, 225);
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 210);
	reg_servo_angle(14, 80);
	
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 90);
	reg_servo_angle(2, 220);
	
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 226);
	reg_servo_angle(17, 75);
	
	_delay_ms(50*delay_scale);
	action();
}

//Funktion för att rotera åt höger (medurs)
void rot_right(void)
{
	seven_rot();
	six_rot();
	five_rot();
	four_rot();
	three_rot();
	two_rot();
	one_rot();
	eight_rot();
}

//Funktion för at rotera åt vänster (moturs)
void rot_left(void)
{
	seven_rot();
	eight_rot();
	one_rot();
	two_rot();
	three_rot();
	four_rot();
	five_rot();
	six_rot();
}

/************************************************************************************************************
*********************************************  SNETT FRAMÅT  ************************************************
************************************************************************************************************/

//Funktion för att gå framåt-vänster
void forward_left(void)
{
	for(int i = 0; i < 4; i++)
	{
		forward();
	}
	rot_left();
}

//Funktion för att gå framåt-höger
void forward_right(void)
{
	for(int i = 0; i < 4; i++)
	{
		forward();
	}
	rot_right();
}

/************************************************************************************************************
*********************************************  AVBROTT  *****************************************************
************************************************************************************************************/

void execute_command(void)
{
	unsigned char data = 0;
	data = SPDR;
	if (is_moving)
	{
		spi_tranceiver(NOT_READY);
		data_sending = false;
		return;
	}
	spi_tranceiver(READY);
	switch(data)
	{
		case WALK_FORWARD :
			is_moving = true;
			forward();
			is_moving = false;
			break;
		
		case WALK_BACKWARD :
			is_moving = true;
			backward();
			is_moving = false;
			break;
		
		case ROTATE_LEFT :
			is_moving = true;
			rot_left();
			is_moving = false;
			break;
		
		case ROTATE_RIGHT :
			is_moving = true;
			rot_right();
			is_moving = false;
			break;
			
		case TURN_LEFT :
			is_moving = true;
			forward_left();
			is_moving = false;
			break;
			
		case TURN_RIGHT :
			is_moving = true;
			forward_right();
			is_moving = false;
			break;
			
		case STAND_UP :
			is_moving = true;
			stand();
			is_moving = false;
			break;
		
		default :
			break;
	}
	data_sending = false;
	return;
}

void set_data_sending(bool value)
{
	data_sending = value;
}

ISR(SPI_STC_vect)  
{  
	if (!(data_sending))
	{
		data_sending = true;
		execute_command();
	}
}
