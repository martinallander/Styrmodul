#include "walk.h"

bool is_moving = false;
bool data_sending = false;

const float delay_scale = 4;

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

void one_forward(void)
{
	//Right front
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 206);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 227);
	reg_servo_angle(11, 62);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 212);
	reg_servo_angle(17, 85);
	_delay_ms(20*delay_scale);
	action();
}

void two_forward(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 218);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 220);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 74);
	reg_servo_angle(5, 237);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 208);
	reg_servo_angle(14, 73);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 220);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void three_forward(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 212);
	reg_servo_angle(11, 85);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 227);
	reg_servo_angle(17, 62);
	_delay_ms(20*delay_scale);
	action();
}

void four_forward(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 94);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void five_forward(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 73);
	reg_servo_angle(8, 238);
	//Left front
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 94);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 88);
	reg_servo_angle(2, 215);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void six_forward(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 80);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 82);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 92);
	reg_servo_angle(5, 227);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 226);
	reg_servo_angle(14, 63);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 80);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void seven_forward(void)
{
	//Right front
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 88);
	reg_servo_angle(8, 215);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 73);
	reg_servo_angle(2, 238);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void eight_forward(void)
{
	//Right front
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 206);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void walk_forward(void) 
{
	eight_forward();
	one_forward();
	two_forward();
	three_forward();
	four_forward();
	four_forward();
	five_forward();
	six_forward();
	seven_forward();
	eight_forward();
}

void one_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 148);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 207);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 220);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 82);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 210);
	reg_servo_angle(14, 70);
	//Right back
	reg_servo_angle(0, 152);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 207);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 220);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void two_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 100);
	reg_servo_angle(8, 212);
	//Left front
	reg_servo_angle(9, 145);
	reg_servo_angle(10, 223);
	reg_servo_angle(11, 68);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 87);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 206);
	reg_servo_angle(14, 77);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 100);
	reg_servo_angle(2, 212);
	//Left back
	reg_servo_angle(15, 155);
	reg_servo_angle(16, 223);
	reg_servo_angle(17, 68);
	_delay_ms(20*delay_scale);
	action();
}

void three_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 218);
	//Left front
	reg_servo_angle(9, 142);
	reg_servo_angle(10, 226);
	reg_servo_angle(11, 63);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 92);
	reg_servo_angle(5, 209);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 202);
	reg_servo_angle(14, 84);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 158);
	reg_servo_angle(16, 226);
	reg_servo_angle(17, 63);
	_delay_ms(20*delay_scale);
	action();
}

void four_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 218);
	//Left front
	reg_servo_angle(9, 142);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 107);
	reg_servo_angle(5, 200);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 202);
	reg_servo_angle(14, 84);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 158);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void five_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 80);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 142);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 107);
	reg_servo_angle(5, 200);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 218);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 80);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 158);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void six_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 84);
	reg_servo_angle(8, 222);
	//Left front
	reg_servo_angle(9, 145);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 78);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 102);
	reg_servo_angle(5, 208);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 224);
	reg_servo_angle(14, 67);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 84);
	reg_servo_angle(2, 222);
	//Left back
	reg_servo_angle(15, 155);
	reg_servo_angle(16, 206);
	reg_servo_angle(17, 78);
	_delay_ms(20*delay_scale);
	action();
}

void seven_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 148);
	reg_servo_angle(7, 88);
	reg_servo_angle(8, 216);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 82);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 98);
	reg_servo_angle(5, 216);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 229);
	reg_servo_angle(14, 59);
	//Right back
	reg_servo_angle(0, 152);
	reg_servo_angle(1, 88);
	reg_servo_angle(2, 216);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void eight_krabba_right(void)
{
	//Right front
	reg_servo_angle(6, 148);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 207);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 82);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 98);
	reg_servo_angle(5, 216);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 210);
	reg_servo_angle(14, 70);
	//Right back
	reg_servo_angle(0, 152);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 207);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void walk_krabba_right(void)
{
	eight_krabba_right();
	one_krabba_right();
	two_krabba_right();
	three_krabba_right();
	four_krabba_right();
	four_krabba_right();
	five_krabba_right();
	six_krabba_right();
	seven_krabba_right();
	eight_krabba_right();
}

void one_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 158);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 220);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 82);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 193);
	reg_servo_angle(14, 100);
	//Right back
	reg_servo_angle(0, 142);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 220);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void two_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 155);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 222);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 216);
	reg_servo_angle(11, 78);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 76);
	reg_servo_angle(5, 233);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 198);
	reg_servo_angle(14, 92);
	//Right back
	reg_servo_angle(0, 145);
	reg_servo_angle(1, 94);
	reg_servo_angle(2, 222);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 216);
	reg_servo_angle(17, 78);
	_delay_ms(20*delay_scale);
	action();
}

void three_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 218);
	//Left front
	reg_servo_angle(9, 152);
	reg_servo_angle(10, 212);
	reg_servo_angle(11, 84);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 71);
	reg_servo_angle(5, 241);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 202);
	reg_servo_angle(14, 84);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 148);
	reg_servo_angle(16, 212);
	reg_servo_angle(17, 84);
	_delay_ms(20*delay_scale);
	action();
}

void four_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 218);
	//Left front
	reg_servo_angle(9, 152);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 93);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 90);
	reg_servo_angle(5, 230);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 202);
	reg_servo_angle(14, 84);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 148);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 93);
	_delay_ms(20*delay_scale);
	action();
}

void five_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 80);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 152);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 93);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 90);
	reg_servo_angle(5, 230);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 218);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 80);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 148);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 93);
	_delay_ms(20*delay_scale);
	action();
}

void six_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 155);
	reg_servo_angle(7, 77);
	reg_servo_angle(8, 232);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 200);
	reg_servo_angle(11, 88);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 94);
	reg_servo_angle(5, 223);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 213);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 145);
	reg_servo_angle(1, 77);
	reg_servo_angle(2, 232);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 200);
	reg_servo_angle(17, 88);
	_delay_ms(20*delay_scale);
	action();
}

void seven_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 158);
	reg_servo_angle(7, 74);
	reg_servo_angle(8, 237);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 82);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 98);
	reg_servo_angle(5, 216);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 208);
	reg_servo_angle(14, 91);
	//Right back
	reg_servo_angle(0, 142);
	reg_servo_angle(1, 74);
	reg_servo_angle(2, 237);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void eight_krabba_left(void)
{
	//Right front
	reg_servo_angle(6, 158);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 82);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 98);
	reg_servo_angle(5, 216);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 193);
	reg_servo_angle(14, 100);
	//Right back
	reg_servo_angle(0, 142);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void walk_krabba_left(void)
{
	eight_krabba_left();
	one_krabba_left();
	two_krabba_left();
	three_krabba_left();
	four_krabba_left();
	four_krabba_left();
	five_krabba_left();
	six_krabba_left();
	seven_krabba_left();
	eight_krabba_left();
}

void one_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 162);
	reg_servo_angle(7, 98);
	reg_servo_angle(8, 215);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 227);
	reg_servo_angle(11, 62);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 212);
	reg_servo_angle(17, 85);
	_delay_ms(20*delay_scale);
	action();
}

void two_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 155);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 222);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 216);
	reg_servo_angle(11, 78);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 74);
	reg_servo_angle(5, 237);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 208);
	reg_servo_angle(14, 73);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 220);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void three_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 204);
	reg_servo_angle(11, 96);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 227);
	reg_servo_angle(17, 62);
	_delay_ms(20*delay_scale);
	action();
}

void four_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 190);
	reg_servo_angle(11, 105);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void five_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 73);
	reg_servo_angle(8, 238);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 190);
	reg_servo_angle(11, 105);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 88);
	reg_servo_angle(2, 215);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void six_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 155);
	reg_servo_angle(7, 77);
	reg_servo_angle(8, 232);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 200);
	reg_servo_angle(11, 88);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 92);
	reg_servo_angle(5, 227);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 226);
	reg_servo_angle(14, 63);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 80);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void seven_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 162);
	reg_servo_angle(7, 82);
	reg_servo_angle(8, 225);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 73);
	reg_servo_angle(2, 238);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void eight_forward_left(void)
{
	//Right front
	reg_servo_angle(6, 162);
	reg_servo_angle(7, 98);
	reg_servo_angle(8, 215);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void walk_forward_left(void)
{
	eight_forward_left();
	one_forward_left();
	two_forward_left();
	three_forward_left();
	four_forward_left();
	four_forward_left();
	five_forward_left();
	six_forward_left();
	seven_forward_left();
	eight_forward_left();
}

void one_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 95);
	reg_servo_angle(8, 221);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 222);
	reg_servo_angle(11, 69);
	//Right middle
	reg_servo_angle(3, 165);
	reg_servo_angle(4, 80);
	reg_servo_angle(5, 228);
	//Left middle
	reg_servo_angle(12, 135);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 120);
	reg_servo_angle(1, 94);
	reg_servo_angle(2, 223);
	//Left back
	reg_servo_angle(15, 180);
	reg_servo_angle(16, 223);
	reg_servo_angle(17, 67);
	_delay_ms(20*delay_scale);
	action();
}

void two_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 165);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 224);
	//Left front
	reg_servo_angle(9, 135);
	reg_servo_angle(10, 224);
	reg_servo_angle(11, 66);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 79);
	reg_servo_angle(5, 229);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 204);
	reg_servo_angle(14, 80);
	//Right back
	reg_servo_angle(0, 135);
	reg_servo_angle(1, 94);
	reg_servo_angle(2, 224);
	//Left back
	reg_servo_angle(15, 165);
	reg_servo_angle(16, 224);
	reg_servo_angle(17, 66);
	_delay_ms(20*delay_scale);
	action();
}

void three_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 180);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 223);
	//Left front
	reg_servo_angle(9, 120);
	reg_servo_angle(10, 223);
	reg_servo_angle(11, 67);
	//Right middle
	reg_servo_angle(3, 135);
	reg_servo_angle(4, 80);
	reg_servo_angle(5, 228);
	//Left middle
	reg_servo_angle(12, 165);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 95);
	reg_servo_angle(2, 221);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 222);
	reg_servo_angle(17, 69);
	_delay_ms(20*delay_scale);
	action();
}

void four_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 180);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 223);
	//Left front
	reg_servo_angle(9, 120);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 77);
	//Right middle
	reg_servo_angle(3, 135);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 165);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 95);
	reg_servo_angle(2, 221);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 205);
	reg_servo_angle(17, 79);
	_delay_ms(20*delay_scale);
	action();
}

void five_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 180);
	reg_servo_angle(7, 77);
	reg_servo_angle(8, 233);
	//Left front
	reg_servo_angle(9, 120);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 77);
	//Right middle
	reg_servo_angle(3, 135);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 165);
	reg_servo_angle(13, 220);
	reg_servo_angle(14, 72);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 78);
	reg_servo_angle(2, 231);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 205);
	reg_servo_angle(17, 79);
	_delay_ms(20*delay_scale);
	action();
}

void six_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 165);
	reg_servo_angle(7, 76);
	reg_servo_angle(8, 234);
	//Left front
	reg_servo_angle(9, 135);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 76);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 96);
	reg_servo_angle(5, 220);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 221);
	reg_servo_angle(14, 71);
	//Right back
	reg_servo_angle(0, 135);
	reg_servo_angle(1, 76);
	reg_servo_angle(2, 234);
	//Left back
	reg_servo_angle(15, 165);
	reg_servo_angle(16, 206);
	reg_servo_angle(17, 76);
	_delay_ms(20*delay_scale);
	action();
}

void seven_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 78);
	reg_servo_angle(8, 231);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 205);
	reg_servo_angle(11, 79);
	//Right middle
	reg_servo_angle(3, 165);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 135);
	reg_servo_angle(13, 220);
	reg_servo_angle(14, 72);
	//Right back
	reg_servo_angle(0, 120);
	reg_servo_angle(1, 77);
	reg_servo_angle(2, 233);
	//Left back
	reg_servo_angle(15, 180);
	reg_servo_angle(16, 206);
	reg_servo_angle(17, 77);
	_delay_ms(20*delay_scale);
	action();
}

void eight_rot_left60(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 95);
	reg_servo_angle(8, 221);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 205);
	reg_servo_angle(11, 79);
	//Right middle
	reg_servo_angle(3, 165);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 135);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 120);
	reg_servo_angle(1, 94);
	reg_servo_angle(2, 223);
	//Left back
	reg_servo_angle(15, 180);
	reg_servo_angle(16, 206);
	reg_servo_angle(17, 77);
	_delay_ms(20*delay_scale);
	action();
}

void rotate_rot_left60(void)
{
	eight_rot_left60();
	one_rot_left60();
	two_rot_left60();
	three_rot_left60();
	four_rot_left60();
	four_rot_left60();
	five_rot_left60();
	six_rot_left60();
	seven_rot_left60();
	eight_rot_left60();
}

void one_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 180);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 223);
	//Left front
	reg_servo_angle(9, 120);
	reg_servo_angle(10, 223);
	reg_servo_angle(11, 67);
	//Right middle
	reg_servo_angle(3, 135);
	reg_servo_angle(4, 80);
	reg_servo_angle(5, 228);
	//Left middle
	reg_servo_angle(12, 165);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 95);
	reg_servo_angle(2, 221);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 222);
	reg_servo_angle(17, 69);
	_delay_ms(20*delay_scale);
	action();
}

void two_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 165);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 224);
	//Left front
	reg_servo_angle(9, 135);
	reg_servo_angle(10, 224);
	reg_servo_angle(11, 66);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 79);
	reg_servo_angle(5, 229);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 204);
	reg_servo_angle(14, 80);
	//Right back
	reg_servo_angle(0, 135);
	reg_servo_angle(1, 94);
	reg_servo_angle(2, 224);
	//Left back
	reg_servo_angle(15, 165);
	reg_servo_angle(16, 224);
	reg_servo_angle(17, 66);
	_delay_ms(20*delay_scale);
	action();
}

void three_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 95);
	reg_servo_angle(8, 221);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 222);
	reg_servo_angle(11, 69);
	//Right middle
	reg_servo_angle(3, 165);
	reg_servo_angle(4, 80);
	reg_servo_angle(5, 228);
	//Left middle
	reg_servo_angle(12, 135);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 120);
	reg_servo_angle(1, 94);
	reg_servo_angle(2, 223);
	//Left back
	reg_servo_angle(15, 180);
	reg_servo_angle(16, 223);
	reg_servo_angle(17, 67);
	_delay_ms(20*delay_scale);
	action();
}

void four_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 95);
	reg_servo_angle(8, 221);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 205);
	reg_servo_angle(11, 79);
	//Right middle
	reg_servo_angle(3, 165);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 135);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 120);
	reg_servo_angle(1, 94);
	reg_servo_angle(2, 223);
	//Left back
	reg_servo_angle(15, 180);
	reg_servo_angle(16, 206);
	reg_servo_angle(17, 77);
	_delay_ms(20*delay_scale);
	action();
}

void five_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 78);
	reg_servo_angle(8, 231);
	//Left front
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 205);
	reg_servo_angle(11, 79);
	//Right middle
	reg_servo_angle(3, 165);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 135);
	reg_servo_angle(13, 220);
	reg_servo_angle(14, 72);
	//Right back
	reg_servo_angle(0, 120);
	reg_servo_angle(1, 77);
	reg_servo_angle(2, 233);
	//Left back
	reg_servo_angle(15, 180);
	reg_servo_angle(16, 206);
	reg_servo_angle(17, 77);
	_delay_ms(20*delay_scale);
	action();
}

void six_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 165);
	reg_servo_angle(7, 76);
	reg_servo_angle(8, 234);
	//Left front
	reg_servo_angle(9, 135);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 76);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 96);
	reg_servo_angle(5, 220);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 221);
	reg_servo_angle(14, 71);
	//Right back
	reg_servo_angle(0, 135);
	reg_servo_angle(1, 76);
	reg_servo_angle(2, 234);
	//Left back
	reg_servo_angle(15, 165);
	reg_servo_angle(16, 206);
	reg_servo_angle(17, 76);
	_delay_ms(20*delay_scale);
	action();
}

void seven_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 180);
	reg_servo_angle(7, 77);
	reg_servo_angle(8, 233);
	//Left front
	reg_servo_angle(9, 120);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 77);
	//Right middle
	reg_servo_angle(3, 135);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 165);
	reg_servo_angle(13, 220);
	reg_servo_angle(14, 72);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 78);
	reg_servo_angle(2, 231);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 205);
	reg_servo_angle(17, 79);
	_delay_ms(20*delay_scale);
	action();
}

void eight_rot_right60(void)
{
	//Right front
	reg_servo_angle(6, 180);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 223);
	//Left front
	reg_servo_angle(9, 120);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 77);
	//Right middle
	reg_servo_angle(3, 135);
	reg_servo_angle(4, 97);
	reg_servo_angle(5, 218);
	//Left middle
	reg_servo_angle(12, 165);
	reg_servo_angle(13, 203);
	reg_servo_angle(14, 82);
	//Right back
	reg_servo_angle(0, 150);
	reg_servo_angle(1, 95);
	reg_servo_angle(2, 221);
	//Left back
	reg_servo_angle(15, 150);
	reg_servo_angle(16, 205);
	reg_servo_angle(17, 79);
	_delay_ms(20*delay_scale);
	action();
}

void rotate_rot_right60(void)
{
	eight_rot_right60();
	one_rot_right60();
	two_rot_right60();
	three_rot_right60();
	four_rot_right60();
	four_rot_right60();
	five_rot_right60();
	six_rot_right60();
	seven_rot_right60();
	eight_rot_right60();
}

void one_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 110);
	reg_servo_angle(8, 195);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 227);
	reg_servo_angle(11, 62);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 212);
	reg_servo_angle(17, 85);
	_delay_ms(20*delay_scale);
	action();
}

void two_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 100);
	reg_servo_angle(8, 212);
	//Left front
	reg_servo_angle(9, 145);
	reg_servo_angle(10, 223);
	reg_servo_angle(11, 68);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 74);
	reg_servo_angle(5, 237);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 208);
	reg_servo_angle(14, 73);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 220);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void three_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 138);
	reg_servo_angle(10, 218);
	reg_servo_angle(11, 75);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 227);
	reg_servo_angle(17, 62);
	_delay_ms(20*delay_scale);
	action();
}

void four_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 138);
	reg_servo_angle(10, 202);
	reg_servo_angle(11, 85);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void five_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 73);
	reg_servo_angle(8, 238);
	//Left front
	reg_servo_angle(9, 138);
	reg_servo_angle(10, 202);
	reg_servo_angle(11, 85);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 88);
	reg_servo_angle(2, 215);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void six_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 84);
	reg_servo_angle(8, 222);
	//Left front
	reg_servo_angle(9, 145);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 78);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 92);
	reg_servo_angle(5, 227);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 226);
	reg_servo_angle(14, 63);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 80);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void seven_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 96);
	reg_servo_angle(8, 204);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 73);
	reg_servo_angle(2, 238);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void eight_forward_right(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 110);
	reg_servo_angle(8, 195);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void walk_forward_right(void)
{
	eight_forward_right();
	one_forward_right();
	two_forward_right();
	three_forward_right();
	four_forward_right();
	four_forward_right();
	five_forward_right();
	six_forward_right();
	seven_forward_right();
	eight_forward_right();
}

void one_backward(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 212);
	reg_servo_angle(11, 85);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 227);
	reg_servo_angle(17, 62);
	_delay_ms(20*delay_scale);
	action();
}

void two_backward(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 97);
	reg_servo_angle(8, 218);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 220);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 74);
	reg_servo_angle(5, 237);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 208);
	reg_servo_angle(14, 73);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 97);
	reg_servo_angle(2, 218);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 220);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void three_backward(void)
{
	//Right front
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 206);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 227);
	reg_servo_angle(11, 62);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 75);
	reg_servo_angle(5, 236);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 212);
	reg_servo_angle(17, 85);
	_delay_ms(20*delay_scale);
	action();
}

void four_backward(void)
{
	//Right front
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 206);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 92);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void five_backward(void)
{
	//Right front
	reg_servo_angle(6, 157);
	reg_servo_angle(7, 88);
	reg_servo_angle(8, 215);
	//Left front
	reg_servo_angle(9, 153);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	//Right middle
	reg_servo_angle(3, 142);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 142);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 153);
	reg_servo_angle(1, 73);
	reg_servo_angle(2, 238);
	//Left back
	reg_servo_angle(15, 157);
	reg_servo_angle(16, 197);
	reg_servo_angle(17, 94);
	_delay_ms(20*delay_scale);
	action();
}

void six_backward(void)
{
	//Right front
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 80);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 203);
	reg_servo_angle(11, 82);
	//Right middle
	reg_servo_angle(3, 150);
	reg_servo_angle(4, 92);
	reg_servo_angle(5, 227);
	//Left middle
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 226);
	reg_servo_angle(14, 63);
	//Right back
	reg_servo_angle(0, 148);
	reg_servo_angle(1, 80);
	reg_servo_angle(2, 227);
	//Left back
	reg_servo_angle(15, 152);
	reg_servo_angle(16, 203);
	reg_servo_angle(17, 82);
	_delay_ms(20*delay_scale);
	action();
}

void seven_backward(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 73);
	reg_servo_angle(8, 238);
	//Left front
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 94);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 225);
	reg_servo_angle(14, 64);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 88);
	reg_servo_angle(2, 215);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void eight_backward(void)
{
	//Right front
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	//Left front
	reg_servo_angle(9, 143);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 94);
	//Right middle
	reg_servo_angle(3, 158);
	reg_servo_angle(4, 93);
	reg_servo_angle(5, 226);
	//Left middle
	reg_servo_angle(12, 158);
	reg_servo_angle(13, 207);
	reg_servo_angle(14, 74);
	//Right back
	reg_servo_angle(0, 143);
	reg_servo_angle(1, 103);
	reg_servo_angle(2, 206);
	//Left back
	reg_servo_angle(15, 147);
	reg_servo_angle(16, 208);
	reg_servo_angle(17, 73);
	_delay_ms(20*delay_scale);
	action();
}

void walk_backward(void)
{
	eight_backward();
	one_backward();
	two_backward();
	three_backward();
	four_backward();
	four_backward();
	five_backward();
	six_backward();
	seven_backward();
	eight_backward();
}


/**********GAMMALT*********************************************/


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

void onen(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 223);
	
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

void twon(void)
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

void threen(void)
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

void fourn(void)
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

void fiven(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 77);
	reg_servo_angle(8, 233);
	
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

void sixn(void)
{
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 88);
	reg_servo_angle(8, 216);
	
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

void sevenn(void)
{
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 207);
	
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

void eightn(void)
{
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 207);
	
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

void forward_new(void)
{
	eightn();
	onen();
	twon();
	threen();
	fourn();
	fiven();
	sixn();
	sevenn();
}

//Funktion för gång bakåt
void backward(void)
{
	six();
	five();
	four();
	three();
	two();
	one();
	eight();
	seven();
}

/************************************************************************************************************
*********************************************  SVÄNGA HÖGER OCH VÄNSTER  ************************************
************************************************************************************************************/

void one_turnl(void)
{
	reg_servo_angle(6, 153);
	reg_servo_angle(7, 92);
	reg_servo_angle(8, 227);
	
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 240);
	reg_servo_angle(11, 67);
	
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

void two_turnl(void)
{
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 87);
	reg_servo_angle(8, 237);
	
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 235);
	reg_servo_angle(11, 73);
	
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

void three_turnl(void)
{
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 87);
	reg_servo_angle(8, 237);
	
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 93);
	
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

void four_turnl(void)
{
	reg_servo_angle(6, 147);
	reg_servo_angle(7, 60);
	reg_servo_angle(8, 240);
	
	reg_servo_angle(9, 148);
	reg_servo_angle(10, 197);
	reg_servo_angle(11, 93);
	
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

void five_turnl(void)
{
	reg_servo_angle(6, 153);
	reg_servo_angle(7, 60);
	reg_servo_angle(8, 238);
	
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 77);
	
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

void six_turnl(void)
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

void seven_turnl(void)
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

void eight_turnl(void)
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

void one_turnr(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 94);
	reg_servo_angle(8, 223);
	
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 240);
	reg_servo_angle(11, 67);
	
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

void two_turnr(void)
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

void three_turnr(void)
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

void four_turnr(void)
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

void five_turnr(void)
{
	reg_servo_angle(6, 150);
	reg_servo_angle(7, 68);
	reg_servo_angle(8, 233);
	
	reg_servo_angle(9, 150);
	reg_servo_angle(10, 206);
	reg_servo_angle(11, 77);
	
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

void six_turnr(void)
{
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 68);
	reg_servo_angle(8, 216);
	
	reg_servo_angle(9, 158);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	
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

void seven_turnr(void)
{
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 207);
	
	reg_servo_angle(9, 158);
	reg_servo_angle(10, 208);
	reg_servo_angle(11, 73);
	
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

void eight_turnr(void)
{
	reg_servo_angle(6, 152);
	reg_servo_angle(7, 103);
	reg_servo_angle(8, 207);
	
	reg_servo_angle(9, 158);
	reg_servo_angle(10, 235);
	reg_servo_angle(11, 63);
	
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

void turn_left(void)
{
	eight_turnl();
	one_turnl();
	two_turnl();
	three_turnl();
	four_turnl();
	five_turnl();
	six_turnl();
	seven_turnl();
}

void turn_right(void)
{
	eight_turnr();
	one_turnr();
	two_turnr();
	three_turnr();
	four_turnr();
	five_turnr();
	six_turnr();
	seven_turnr();
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
	switch(data)
	{
		case WALK_FORWARD :
			spi_tranceiver(READY);
			is_moving = true;
			walk_forward();
			_delay_ms(10);
			is_moving = false;
			break;
		
		case WALK_BACKWARD :
			spi_tranceiver(READY);
			is_moving = true;
			walk_backward();
			_delay_ms(10);
			is_moving = false;
			break;
		
		case ROTATE_LEFT :
			spi_tranceiver(READY);
			is_moving = true;
			rotate_rot_left60();
			_delay_ms(10);
			is_moving = false;
			break;
		
		case ROTATE_RIGHT :
			spi_tranceiver(READY);
			is_moving = true;
			rotate_rot_right60();
			_delay_ms(10);
			is_moving = false;
			break;
			
		case TURN_LEFT :
			spi_tranceiver(READY);
			is_moving = true;
			walk_forward_left();
			_delay_ms(10);
			is_moving = false;
			break;
			
		case TURN_RIGHT :
			spi_tranceiver(READY);
			is_moving = true;
			walk_forward_right();
			_delay_ms(10);
			is_moving = false;
			break;
			
		case STAND_UP :
			spi_tranceiver(READY);
			is_moving = true;
			stand();
			_delay_ms(10);
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
