#ifndef F_CPU
#define F_CPU 16000000UL                    // S�tt CPU-klockan till 16 MHz
#endif

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include "main.h"
#include "alfred_monkaS.h"

// -- USART definitioner
#define TXD0_READY bit_is_set(UCSR0A,5)
#define TXD0_FINISHED bit_is_set(UCSR0A,6)
#define RXD0_READY bit_is_set(UCSR0A,7)
#define TXD0_DATA (UDR0)
#define RXD0_DATA (UDR0)

#define BAUD 1000000
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)    //S�tt baudrate f�r UBRR enligt formel i databladet

//Olika kommandon f�r servona
typedef enum ServoCommand
{
	PING = 1,
	READ = 2,
	WRITE = 3,
	REG = 4,
	ACTION = 5
} ServoCommand;

/************************************************************************************************************
*******************************************  FUNKTIONER F�R UART  *******************************************
************************************************************************************************************/

void UART0RecieveMode(void) 
{
	UCSR0B = (0<<TXEN0)|(1<<RXEN0);
}

void UART0SendMode(void)
{
	UCSR0B = (1<<TXEN0)|(0<<RXEN0);
}

//Initiera UART
void uart_init (void)
{
	UBRR0H = (unsigned char)(BAUDRATE>>8);			//Skifta registret �t h�ger med 8 bitar
	UBRR0L = (unsigned char)BAUDRATE;				//S�tt baudrate
	//UCSR0B = (1<<TXEN0)|(1<<RXEN0);					//Enable receiver and transmitter
	UCSR0C = (0<<USBS0)|(1<<UCSZ00)|(1<<UCSZ01)|(0<<UPM01);	//S�tter 1 stoppbit, samt 8bit dataformat
	UART0RecieveMode();	 
}

//Skicka med UART
void uart_transmit (unsigned char data)
{
	while(!( UCSR0A & (1<<UDRE0)));		//V�ntar p� att "transmit-buffern" ska bli tom genom att kolla UDRE-flaggan
	UDR0 = data;                        //Ladda in datan i registret (UDR = Uart Data Register)
}

//Ta emot med UART
unsigned char uart_recieve (void)
{
	while(!(UCSR0A & (1<<RXC0)));           //V�ntar p� att data ska finnas i "receive-buffern" genom att kolla RXCn-flaggan
	return UDR0;                             // return 8-bit data
}

/************************************************************************************************************
**************************************  FUNKTIONER F�R GET-KOMMANDON  **************************************
************************************************************************************************************/

uint16_t servo_read_status_packet()
{
	uint16_t ValueOfParameters = 0;
	uint8_t Start1 = uart_recieve();
	uint8_t Start2 = uart_recieve();
	uint8_t ID = uart_recieve();
	uint8_t Length = uart_recieve();
	uint8_t Error = uart_recieve();
	uint8_t HelpVariable = 0;
	//L�ser av parameterv�rdena och sparar v�rdet i ValueOfParameters
	while (Length > 2)
	{
		ValueOfParameters = ValueOfParameters + (uart_recieve() << (8*HelpVariable));
		HelpVariable++;
		Length--;
	}
	
	//uint8_t	data1 = uart_recieve();
	//uint8_t	data2 = uart_recieve();
	//uint16_t data = data1 + data2*256;
	uint8_t CheckSum = uart_recieve();
	led_blink(1);
	return ValueOfParameters;//*(uint16_t)300/1023;
}


/************************************************************************************************************
**************************************  FUNKTIONER F�R SET-KOMMANDON  **************************************
************************************************************************************************************/
//Skicka ett kommando till servon
void send_servo_command (const uint8_t servoId, const ServoCommand commandByte, const uint8_t numParams, const uint8_t *params)
{
	UART0SendMode();
	UCSR0A = UCSR0A | (0 << 6); // Gjorde s� att vi kunde skicka en instruktion efter en instruktion/read.
	uart_transmit(0xff);
	uart_transmit(0xff);  // 2 stycken startbytes
	
	uart_transmit(servoId);  // servo-ID
	uint8_t checksum = servoId;
	
	uart_transmit(numParams + 2);  //Antal parametrar + 2
	uart_transmit((uint8_t)commandByte);  //Kommandot
	checksum += numParams + 2 + commandByte;
	
	for (uint8_t i = 0; i < numParams; i++)
	{
		uart_transmit(params[i]);  //Parametrar
		checksum += params[i];
	}
	cli(); // Blockera avbrott
	uart_transmit(~checksum);  // checksum
	while(!TXD0_FINISHED) //TXD0 s�tts till 1 d� all data shiftats ut ifr�n usarten
	{
		// V�nta tills den s�nt klart det sista
	}
	UART0RecieveMode();
	sei(); // Till�t interrupts igen
}

//S�tt vinkel f�r servon
void set_servo_angle (const uint8_t servoId, const float angle)
{
	//if (angle < 0 || angle > 300)
	//return false;
	// angle values go from 0 to 0x3ff (1023)
	const uint16_t angleValue = (uint16_t)(angle * (1023.0 / 300.0));
	const uint8_t highByte = (uint8_t)((angleValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(angleValue & 0xff);
	const uint8_t params[3] = {GOAL_ANGLE, lowByte, highByte};
	send_servo_command (servoId, WRITE, 3, params);
}

//V�lj n�r ett servo ska skicka tillbaka data.
void set_servo_status_return_level (const uint8_t servoId, const uint8_t returnlevel)
{
	/*  0 Do not respond to any instructions
		1 Respond only to READ_DATA instructions
		2 Respond to all instructions	*/
	const uint8_t params[2] = {RETURN_LEVEL, returnlevel};
	send_servo_command (servoId, WRITE, 2, params);
}

void set_servo_max_speed (const uint8_t servoId, const uint16_t speedValue)
{
	const uint8_t highByte = (uint8_t)((speedValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(speedValue & 0xff);
	const uint8_t params[3] = {MAX_SPEED, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

//S�tter gr�ns f�r till�ten belastning
void set_servo_torque (const uint8_t servoId,
const uint16_t torqueValue)
{
	const uint8_t highByte = (uint8_t)((torqueValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(torqueValue & 0xff);
	const uint8_t params[3] = {TORQUE, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
	//if (!getAndCheckResponse (servoId))
	//return false;
}

//S�tter gr�nser f�r till�tna servovinklar
void set_servo_angle_limit (const uint8_t servoId, const uint16_t lowerLimit, 
							const uint16_t higherLimit)
{
	const uint8_t highByte1 = (uint8_t)((lowerLimit >> 8) & 0xff);
	const uint8_t lowByte1 = (uint8_t)(lowerLimit & 0xff);
	const uint8_t params1[3] = {LOWER_ANGLE_LIMIT, lowByte1, highByte1};
	send_servo_command(servoId, WRITE, 3, params1);

	const uint8_t highByte2 = (uint8_t)((higherLimit >> 8) & 0xff);
	const uint8_t lowByte2 = (uint8_t)(higherLimit & 0xff);
	const uint8_t params2[3] = {HIGHER_ANGLE_LIMIT, lowByte2, highByte2};
	send_servo_command(servoId, WRITE, 3, params2);
}

//Laddar ett servo med en vinkel som sedan utf�rs med "action();"
void reg_servo_angle (const uint8_t servoId, const float angle)
{
	const uint16_t angleValue = (uint16_t)(angle * (1023.0 / 300.0));
	const uint8_t highByte = (uint8_t)((angleValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(angleValue & 0xff);
	const uint8_t params[3] = {GOAL_ANGLE, lowByte, highByte};
	send_servo_command (servoId, REG, 3, params);
}

//Utf�r de REG_WRITE-instruktioner som servona har laddats med
void action(void)
{
	const uint8_t params[1] = {0};
	send_servo_command (0xfe, ACTION, 0, params);
}

/************************************************************************************************************
*******************************************  INITIERING  ***************************************************
************************************************************************************************************/

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
*******************************************  FUNKTIONER F�R ENKSKILDA BEN ***********************************
************************************************************************************************************/

//Funktioner f�r att f�rflytta det v�nstra fr�mre benet
//void front_left_forward_start(void)
//{
	//reg_servo_angle(0, (STAND_DEG_00 + 5));
	//reg_servo_angle(1, (STAND_DEG_01 - 20));
	//reg_servo_angle(2, (STAND_DEG_02 + 30));
//}
//
//void front_left_forward_end(void)
//{
	//reg_servo_angle(0, (STAND_DEG_00 - 5));
	//reg_servo_angle(1, (STAND_DEG_01 + 60));
	//reg_servo_angle(2, (STAND_DEG_02 - 10));
//}
//
//
////Funktioner f�r att f�rflytta det h�gra fr�mre benet
//void front_right_forward_start(void)
//{
	//reg_servo_angle(15, (STAND_DEG_15 + 5));
	//reg_servo_angle(16, (STAND_DEG_16 - 20));
	//reg_servo_angle(17, (STAND_DEG_17 + 30));
//}
//void front_right_forward_end(void)
//{
	//reg_servo_angle(15, (STAND_DEG_15 - 5));
	//reg_servo_angle(16, (STAND_DEG_16 + 60));
	//reg_servo_angle(17, (STAND_DEG_17 - 10));
//}
//
////Funktioner f�r att f�rflytta det v�nstra mellersta benet
//void middle_left_forward_start(void)
//{
	//reg_servo_angle(3, (STAND_DEG_03 - 5));
	//reg_servo_angle(4, (STAND_DEG_04 + 10));
	//reg_servo_angle(5, STAND_DEG_05);
//}
//
//void middle_left_forward_end(void)
//{
	//reg_servo_angle(3, (STAND_DEG_03 + 5));
	//reg_servo_angle(4, (STAND_DEG_04 - 20));
	//reg_servo_angle(5, (STAND_DEG_05 + 30)); //tidigare 230
//}
//
////Funktioner f�r att f�rflytta det h�gra mellersta benet
//void middle_right_forward_start(void)
//{
	//reg_servo_angle(12, (STAND_DEG_12 - 5));
	//reg_servo_angle(13, (STAND_DEG_13 + 10));
	//reg_servo_angle(14, STAND_DEG_14);
//}
//
//void middle_right_forward_end(void)
//{
	//reg_servo_angle(12, (STAND_DEG_12 + 5));
	//reg_servo_angle(13, (STAND_DEG_13 - 20));
	//reg_servo_angle(14, (STAND_DEG_14 + 30));
//}
//
////Funktioner f�r att f�rflytta det bakre v�nstra benet
//void back_left_forward_start(void)
//{
	//reg_servo_angle(6, (STAND_DEG_06 + 5));
	//reg_servo_angle(7, (STAND_DEG_07 + 20));
	//reg_servo_angle(8, (STAND_DEG_08 - 5));
//}
//
//void back_left_forward_end(void)
//{
	//reg_servo_angle(6, (STAND_DEG_06 - 5));
	//reg_servo_angle(7, (STAND_DEG_07 - 5));
	//reg_servo_angle(8, (STAND_DEG_08 + 10));
//}
//
////Funktioner f�r att f�rflytta det h�gra bakre benet
//void back_right_forward_start(void)
//{
	//reg_servo_angle(9, (STAND_DEG_09 + 5));
	//reg_servo_angle(10, (STAND_DEG_10 + 20));
	//reg_servo_angle(11, (STAND_DEG_11 - 5));
//}
//
//void back_right_forward_end(void)
//{
	//reg_servo_angle(9, (STAND_DEG_09 - 5));
	//reg_servo_angle(10, (STAND_DEG_10 - 5));
	//reg_servo_angle(11, (STAND_DEG_11 + 10));
//}

/************************************************************************************************************
*******************************************  Funktioner �r enskilda ben v.2  ********************************
************************************************************************************************************/
/*
//Funktioner f�r att f�rflytta det v�nstra fr�mre benet
void front_left_forward_start(void)
{
	reg_servo_angle(0, 155);
	reg_servo_angle(1, 70);
	reg_servo_angle(2, 260);
}

void front_left_forward_end(void)
{
	reg_servo_angle(0, 145);
	reg_servo_angle(1, 150);
	reg_servo_angle(2, 220);
}


//Funktioner f�r att f�rflytta det h�gra fr�mre benet
void front_right_forward_start(void)
{
	reg_servo_angle(15, 155);
	reg_servo_angle(16, 190);
	reg_servo_angle(17, 100);
}
void front_right_forward_end(void)
{
	reg_servo_angle(15, 145);
	reg_servo_angle(16, 270);
	reg_servo_angle(17, 60);
}

//Funktioner f�r att f�rflytta det v�nstra mellersta benet
void middle_left_forward_start(void)
{
	reg_servo_angle(3, 145);
	reg_servo_angle(4, 100);
	reg_servo_angle(5, 230);
}

void middle_left_forward_end(void)
{
	reg_servo_angle(3, 155);
	reg_servo_angle(4, 70);
	reg_servo_angle(5, 260); //tidigare 230
}

//Funktioner f�r att f�rflytta det h�gra mellersta benet
void middle_right_forward_start(void)
{
	reg_servo_angle(12, 145);
	reg_servo_angle(13, 230);
	reg_servo_angle(14, 70);
}

void middle_right_forward_end(void)
{
	reg_servo_angle(12, 155);
	reg_servo_angle(13, 200);
	reg_servo_angle(14, 100);
}

//Funktioner f�r att f�rflytta det bakre v�nstra benet
void back_left_forward_start(void)
{
	reg_servo_angle(6, 155);
	reg_servo_angle(7, 85);
	reg_servo_angle(8, 225);
}

void back_left_forward_end(void)
{
	reg_servo_angle(6, 145);
	reg_servo_angle(7, 110);
	reg_servo_angle(8, 245);
}

//Funktioner f�r att f�rflytta det h�gra bakre benet
void back_right_forward_start(void)
{
	reg_servo_angle(9, 155);
	reg_servo_angle(10, 205);
	reg_servo_angle(11, 65);
}

void back_right_forward_end(void)
{
	reg_servo_angle(9, 145);
	reg_servo_angle(10, 230);
	reg_servo_angle(11, 85);
}
*/

/************************************************************************************************************
******************************************benfunktioner v. 0.3************************************************
*************************************************************************************************************/

void front_right_leg_forward(void)
{
	int scale = 4;
	//forward x = 15, z = 9 
	//y = 10
	_delay_ms(20*scale);
	reg_servo_angle(0x06, 139);
	reg_servo_angle(0x07, 112);
	reg_servo_angle(0x08, 199);
	action();
	
	//y = 8
	_delay_ms(130*scale);
	reg_servo_angle(0x06, 133);
	reg_servo_angle(0x07, 108);
	reg_servo_angle(0x08, 207);
	action();
	
	//y = 4
	_delay_ms(20*scale);
	reg_servo_angle(0x06, 120);
	reg_servo_angle(0x07, 103);
	reg_servo_angle(0x08, 217);
	action();
	
	//y = 0
	_delay_ms(20*scale);
	reg_servo_angle(0x06, 105);
	reg_servo_angle(0x07, 101);
	reg_servo_angle(0x08, 221);
	action();
	
	//back z = 6
	//y = 4
	_delay_ms(130*scale);
	reg_servo_angle(0x06, 120);
	reg_servo_angle(0x07, 77);
	reg_servo_angle(0x08, 233);
	action();
	
	//y = 8
	_delay_ms(20*scale);
	reg_servo_angle(0x06, 133);
	reg_servo_angle(0x07, 84);
	reg_servo_angle(0x08, 222);
	action();
}

void front_left_leg_forward(void)
{
	int scale = 4;
	//forward x = -15, z = 9
	//y = 10
	_delay_ms(20*scale);
	reg_servo_angle(9, 161);
	reg_servo_angle(10, 188);
	reg_servo_angle(11, 101);
	action();
	
	//y = 8
	_delay_ms(130*scale);
	reg_servo_angle(9, 167);
	reg_servo_angle(10, 142);
	reg_servo_angle(11, 207);
	action();
	
	//y = 4
	_delay_ms(20*scale);
	reg_servo_angle(9, 180);
	reg_servo_angle(10, 147);
	reg_servo_angle(11, 217);
	action();
	
	//y = 0
	_delay_ms(20*scale);
	reg_servo_angle(9, 195);
	reg_servo_angle(10, 149);
	reg_servo_angle(11, 221);
	action();
	
	//back z = 6
	//y = 4
	_delay_ms(130*scale);
	reg_servo_angle(9, 180);
	reg_servo_angle(10, 173);
	reg_servo_angle(11, 233);
	action();
	
	//y = 8
	_delay_ms(20*scale);
	reg_servo_angle(9, 167);
	reg_servo_angle(10, 166);
	reg_servo_angle(11, 222);
	action();
}

void middle_right_leg_forward(void)
{
	int scale = 4;
	//back x = 15, z = 9
	//y = -5
	_delay_ms(20*scale);
	reg_servo_angle(0x03, 132);
	reg_servo_angle(0x04, 104);
	reg_servo_angle(0x05, 215);
	action();
	
	// y = -3, z=6
	_delay_ms(130*scale);
	reg_servo_angle(0x03, 139);
	reg_servo_angle(0x04, 75);
	reg_servo_angle(0x05, 235);
	action();
	
	//y=1, z=6
	_delay_ms(20*scale);
	reg_servo_angle(0x03, 154);
	reg_servo_angle(0x04, 74);
	reg_servo_angle(0x05, 237);
	action();
	
	// y= 5
	_delay_ms(20*scale);
	reg_servo_angle(0x03, 168);
	reg_servo_angle(0x04, 104);
	reg_servo_angle(0x05, 215);
	action();
	
	//y=1, z=9
	_delay_ms(130*scale);
	reg_servo_angle(0x03, 154);
	reg_servo_angle(0x04, 101);
	reg_servo_angle(0x05, 220);
	action();
	
	//y=-3, z=9
	_delay_ms(20*scale);
	reg_servo_angle(0x03, 139);
	reg_servo_angle(0x04, 102);
	reg_servo_angle(0x05, 219);
	action();
}

void back_right_leg_forward(void)
{
	int scale = 4;
	//forward x = 15, z = 9
	//y = 0
	_delay_ms(20*scale);
	reg_servo_angle(0x00, 195);
	reg_servo_angle(0x01, 101);
	reg_servo_angle(0x02, 221);
	action();
	
	//y = -2
	_delay_ms(130*scale);
	reg_servo_angle(0x00, 187);
	reg_servo_angle(0x01, 101);
	reg_servo_angle(0x02, 220);
	action();
	
	//y = -6
	_delay_ms(20*scale);
	reg_servo_angle(0x00, 173);
	reg_servo_angle(0x01, 105);
	reg_servo_angle(0x02, 213);
	action();
	
	//y = -10
	_delay_ms(20*scale);
	reg_servo_angle(0x00, 161);
	reg_servo_angle(0x01, 112);
	reg_servo_angle(0x02, 199);
	action();
	
	//back Z = 6
	//y = -6
	_delay_ms(130*scale);
	reg_servo_angle(0x00, 173);
	reg_servo_angle(0x01, 80);
	reg_servo_angle(0x02, 228);
	action();
	
	//y = -2
	_delay_ms(20*scale);
	reg_servo_angle(0x00, 187);
	reg_servo_angle(0x01, 75);
	reg_servo_angle(0x02, 236);
	action();
}



/************************************************************************************************************
*******************************************  H�RDKODAD G�NG  ***********************************************
************************************************************************************************************/

void theos_forward_walk_start(void)
{
	back_left_forward_start();
	middle_right_forward_start();
	front_left_forward_start();
	
	back_right_forward_start();
	middle_left_forward_start();
	front_right_forward_start();
}

void theos_forward_walk_end(void)
{
	back_left_forward_end();
	middle_right_forward_end();
	front_left_forward_end();
	
	back_right_forward_end();
	middle_left_forward_end();
	front_right_forward_end();
}

/************************************************************************************************************
********************************************  �VRIGA FUNKTIONER  ********************************************
************************************************************************************************************/
void servo_init(void)
{
	set_servo_max_speed(0xfe, 100);
	set_servo_status_return_level(0xfe, 0x01); //Skicka bara return-packet n�r READ anv�nds
}

void led_blink(uint16_t i)
{
	if (i< 0)
	return;
	//Blink LED "i" number of times
	for (; i>0; --i)
	{
		PORTB|=(1<<1);
		_delay_ms(200);
		PORTB=(0<<1);
		_delay_ms(200);
	}
}

	/*===========================================================================
			Id�er f�r att fixa inverskinematik och mjuka, korrekta steg
	-----------------------------------------------------------------------------
	- Att koppla vinklar mellan varandra s� att n�r en vinkel �ndras �ndras en annan
	
	- Att stega igenom vinkeln f�r z medans man �ndrar horisontellvinkeln.
	
	- Om det �r m�jligt koppla �ndringen av "inverskinematikpunkten" till en 
	  andragradare.
	  
	- Finns det en funktion som laddar flera vinklar till
	
	- lyft f�rst sedan fram�t, sen ned.
	
	-! Vi kanske b�r fixa s� att servona f�r r�relse i z-led har en l�gre hastighet
	  l�gre d� benet r�r sig fram�t(?) f�r att benet ska dra sig l�ngs marken p� v�g tillbaka.
	============================================================================*/
	
	/*============================================================================
									Att g�ra
	------------------------------------------------------------------------------	
	- Fixa inverskinematikfunktionen
	
	- best�mma riktning och nollniv� f�r z-axeln
	
	- ta fram v�rden f�r vinklar f�r �nskade positioner i en steg f�r varje ben
	
	- F�r in v�rdena i en (hash-(?))tabell
	============================================================================*/
	
	/*============================================================================
								F�rslag till Affe H.	
	------------------------------------------------------------------------------
	- Unders�k inverskinematikfunktionen. Jag kan ha hittat ett: theta_2 b�r vara
	  "theta_2 = round(150 - (alpha_1 + alpha_2));" (kan vara n�n nolla p� slutet, 
	  beroende p� version p� matlab).
	
	- g�r m�tningar d�:
			reg_servo_angle(0x06, 105);
			reg_servo_angle(0x07, 150);
			reg_servo_angle(0x08, 100);
	  (finns i main)
	  vilket ska g�ra s� att slutpunkten hamnar p� x-axeln. 
	 
	- kolla v�rdena p� alpha_1 och alpha_2 i matlab, alpha_2 blir imagin�ra...
	 
	- tror att utg�ngs v�rdet p� theta_3 �r fel, det ska inte vara 202. Kan ox�
		vara fel p� round(90 - beta), kanske inte ska vara 90...
	
	- Misst�nker att z=0 �r vid origo, kanske halvv�gs ned p� f�rsta servot.
	=============================================================================*/

int main (void)
{
	DDRB |= 0x03;
	led_blink(3);
	uart_init();
	LCD_Init();

	set_servo_status_return_level(0xfe, 0x01);
	set_servo_torque(0xfe, 1023);
	set_servo_max_speed(0xfe, 130);
	_delay_ms(2000);
	
	const uint8_t params[2] = {PRESENT_ANGLE, 0x02};

	char *lcd_value = "0";
	uint16_t return_packet;
	LCD_Clear();
	
	while(1)
	{
		
	reg_servo_angle(9, 195);
	reg_servo_angle(10, 199);
	reg_servo_angle(11, 79);
	action();
	
	reg_servo_angle(12, 150);
	reg_servo_angle(13, 199);
	reg_servo_angle(14, 79);
	action();
	
	reg_servo_angle(15, 105);
	reg_servo_angle(16, 199);
	reg_servo_angle(17, 79);
	action();
	
		//set_servo_angle(0x06, 80);
		//_delay_ms(2000);
		//for(int i = 0; i <= 125; i+=5)
		//{
			//set_servo_angle(0x06, (80 + i));
			//_delay_ms(50);
			//send_servo_command (0x06, READ, 2, params);
			//return_packet = servo_read_status_packet();
			//_delay_ms(30);
			//LCD_Clear();
			//LCD_String("PRESENT ANGLE:");
			//LCD_Command(0xc0);
			//itoa(return_packet*0.293255, lcd_value, 10);						//Konvertera return_packet till string. Spara i lcd_value. Talbas 10
			//LCD_String(lcd_value);									// Write string on 2nd line
			//_delay_ms(140);
		//}
	}
	return 0;
}

/*
int main (void)
{
	DDRB |= 0x03;
	led_blink(3);
	uart_init();
	LCD_Init();

	set_servo_status_return_level(0xfe, 0x01);
	set_servo_torque(0xfe, 1023);
	set_servo_max_speed(0xfe, 130);
	_delay_ms(2000);
	
	const uint8_t *high_voltage_para[2] = {HIGHEST_VOLTAGE_LIMIT, 0x02};
	const uint8_t *low_voltage_para[2] = {LOWEST_VOLTAGE_LIMIT, 0x01};
	const uint8_t *temperature_para[2] = {HIGHEST_TEMPERATURE_LIMIT, 0x01};

	char *lcd_value1 = "0";
	char *lcd_value2 = "0";
	char *lcd_value3 = "0";
	uint16_t return_packet6;
	uint16_t return_packet7;
	uint16_t return_packet8;
	LCD_Clear();
	_delay_ms(2000);
	
	while(1)
	{	
		send_servo_command(8, READ, 2, high_voltage_para);
		uint16_t high_volt = servo_read_status_packet();
		itoa(high_volt, lcd_value1, 10);

		send_servo_command(8, READ, 2, low_voltage_para);
		uint16_t low_volt = servo_read_status_packet();
		itoa(low_volt, lcd_value2, 10);
		
		send_servo_command(8, READ, 2, temperature_para);
		uint16_t high_temp = servo_read_status_packet();
		itoa(high_temp, lcd_value3, 10);
		
		LCD_String(lcd_value1);
		LCD_Command(0x14);
		LCD_Command(0x14);
		LCD_Command(0x14);
		LCD_String(lcd_value2);
		LCD_Command(0x14);
		LCD_Command(0x14);
		LCD_Command(0x14);
		LCD_String(lcd_value3);
		_delay_ms(1000);
		LCD_Clear();
		
		//
		//reg_servo_angle(0, 150);
		//reg_servo_angle(3, 150);
		//reg_servo_angle(6, 150);
		//reg_servo_angle(1, STAND_DEG_01);
		//reg_servo_angle(4, STAND_DEG_01);
		//reg_servo_angle(7, STAND_DEG_01);
		//reg_servo_angle(2, STAND_DEG_02);
		//reg_servo_angle(5, STAND_DEG_02);
		//reg_servo_angle(8, STAND_DEG_02);
		//action();
		//_delay_ms(1000);
		//reg_servo_angle(0, 120);
		//reg_servo_angle(3, 120);
		//reg_servo_angle(6, 120);
		//reg_servo_angle(1, (STAND_DEG_01 + 30));
		//reg_servo_angle(4, (STAND_DEG_01 + 30));
		//reg_servo_angle(7, (STAND_DEG_01 + 30));
		//reg_servo_angle(2, (STAND_DEG_02 - 30));
		//reg_servo_angle(5, (STAND_DEG_02 - 30));
		//reg_servo_angle(8, (STAND_DEG_02 - 30));
		//action();
		//_delay_ms(1000);
	}

	return 0;
}


*/
