#ifndef F_CPU
#define F_CPU 16000000UL					//S�tt CPU-klockan till 16 MHz                    
#endif

#include "styrmodul_halv_duplex.h"

/************************************************************************************************************
*******************************************  FUNKTIONER F�R UART  *******************************************
************************************************************************************************************/

//Startar Recieve Mode
void recieve_mode(void) 
{
	UCSR0B = (0<<TXEN0)|(1<<RXEN0);
}

//Startar Send Mode
void send_mode(void)
{
	UCSR0B = (1<<TXEN0)|(0<<RXEN0);
}

//Initiera UART
void uart_init(void)
{
	UBRR0H = (unsigned char)(BAUDRATE>>8);							//Skifta registret 8 bitar �t h�ger
	UBRR0L = (unsigned char)BAUDRATE;								//S�tt baudrate
	UCSR0C = (0<<USBS0)|(1<<UCSZ00)|(1<<UCSZ01)|(0<<UPM01);			//S�tter 1 stoppbit, samt 8-bitars dataformat
	recieve_mode();	 
}

//Skicka med UART
void uart_transmit(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));									//V�ntar p� att "transmit-buffern" ska bli tom genom att kolla UDREn-flaggan
	UDR0 = data;												    //Ladda in datan i registret (UDR = Uart Data Register)
}

//H�mta/Ta emot med UART
unsigned char uart_recieve(void)
{
	while(!(UCSR0A & (1<<RXC0)));									//V�ntar p� att data ska finnas i "receive-buffern" genom att kolla RXCn-flaggan
	return UDR0;													//Returnera data
}

/************************************************************************************************************
**************************************  FUNKTIONER F�R GET-KOMMANDON  **************************************
************************************************************************************************************/

//L�ser igenom hela statuspaketet i servot och returnerar efterfr�gat parameterv�rde 
uint16_t servo_read_status_packet(void)
{
	uint16_t ValueOfParameters = 0;
	uint8_t Start1 = uart_recieve();								//L�ser igenom de olika delarna av statuspaketet och sparar i variabler. Varje del �r 1 byte stor
	uint8_t Start2 = uart_recieve();								//Statuspaketet inleds med tv� stycken startbytes
	uint8_t ID = uart_recieve();
	uint8_t Length = uart_recieve();
	uint8_t Error = uart_recieve();
	uint8_t HelpVariable = 0;
	
	while(Length > 2)												//L�ser av parameterv�rdena och sparar v�rdet i ValueOfParameters
	{
		ValueOfParameters = ValueOfParameters + (uart_recieve() << (8*HelpVariable));
		HelpVariable++;
		Length--;
	}
	
	uint8_t CheckSum = uart_recieve();
	led_blink(1);													//Signalerar att �verf�ringen �r klar
	return ValueOfParameters;										//Om det �r vinklar som h�mtas s� m�ste ValueOfParameters multipliceras med (uint16_t)300/1023
}

/************************************************************************************************************
**************************************  FUNKTIONER F�R SET-KOMMANDON  **************************************
************************************************************************************************************/

//Skicka ett kommando till ett servo
void send_servo_command(const uint8_t servoId, const ServoCommand commandByte, const uint8_t numParams, const uint8_t *params)
{
	send_mode(); 
	UCSR0A = UCSR0A | (0 << 6);										//Gjorde s� att vi kunde skicka en instruktion efter en instruktion/read.
	uart_transmit(0xff);											//Skickar 2 stycken startbytes
	uart_transmit(0xff);											
	
	uart_transmit(servoId);											//Skickar servo-ID
	uint8_t checksum = servoId;
	
	uart_transmit(numParams + 2);									//Skickar antal parametrar + 2
	uart_transmit((uint8_t)commandByte);							//Skickar sj�lva kommandot
	checksum += numParams + 2 + commandByte;
	
	for(uint8_t i = 0; i < numParams; i++)
	{
		uart_transmit(params[i]);									//Skickar parametrarna
		checksum += params[i];
	}
	
	cli();															//Blockerar avbrott
	uart_transmit(~checksum);										//Skickar checksum med inverterade bitar
	while(!TXD0_FINISHED) {}										//TXD0 s�tts till 1 d� all data shiftats ut ifr�n USART:en. V�ntar tills den s�nt klart det sista
	recieve_mode();
	sei();															//Till�ter avbrott igen
}

//S�tt vinkel f�r ett servon
void set_servo_angle (const uint8_t servoId, const float angle)
{
	const uint16_t angleValue = (uint16_t)(angle * (1023.0 / 300.0));
	const uint8_t highByte = (uint8_t)((angleValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(angleValue & 0xff);
	const uint8_t params[3] = {GOAL_ANGLE, lowByte, highByte};
	send_servo_command (servoId, WRITE, 3, params);
}

//V�lj n�r ett servo ska skicka tillbaka data. returnlevel kan ha tre olika v�rden:
//0 - Svara inte p� n�gra instruktioner
//1 - Svara bara p� READ_DATA-instruktioner
//2 - Svara p� alla instruktioner
void set_servo_status_return_level (const uint8_t servoId, const uint8_t returnlevel)
{
	const uint8_t params[2] = {RETURN_LEVEL, returnlevel};
	send_servo_command (servoId, WRITE, 2, params);
}

//S�tt maximal vinkalhastighet f�r ett servo
void set_servo_max_speed (const uint8_t servoId, const uint16_t speedValue)
{
	const uint8_t highByte = (uint8_t)((speedValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(speedValue & 0xff);
	const uint8_t params[3] = {MAX_SPEED, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

//S�tter gr�ns f�r till�ten belastning f�r ett servo 
void set_servo_torque (const uint8_t servoId, const uint16_t torqueValue)
{
	const uint8_t highByte = (uint8_t)((torqueValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(torqueValue & 0xff);
	const uint8_t params[3] = {TORQUE, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

//S�tter gr�nser f�r till�tna servovinklar
void set_servo_angle_limit (const uint8_t servoId, const uint16_t lowerLimit, const uint16_t higherLimit)
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

//Laddar ett servo med en vinkel
void reg_servo_angle (const uint8_t servoId, const float angle)
{
	const uint16_t angleValue = (uint16_t)(angle * (1023.0 / 300.0));
	const uint8_t highByte = (uint8_t)((angleValue >> 8) & 0xff);
	const uint8_t lowByte = (uint8_t)(angleValue & 0xff);
	const uint8_t params[3] = {GOAL_ANGLE, lowByte, highByte};
	send_servo_command (servoId, REG, 3, params);
}

//Utf�r de instruktioner som servona har laddats med
void action(void)
{
	const uint8_t params[1] = {0};
	send_servo_command (0xfe, ACTION, 0, params);
}

/************************************************************************************************************
************************************************  R�RELSEFUNKTIONER  ****************************************
************************************************************************************************************/

//Funktion f�r att roboten ska st�lla sig upp
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
************************************************  FRAM�T OCH BAK�T  *****************************************
************************************************************************************************************/

//Funktioner som utg�r g�ngstilarna f�r r�relse fram�t och bak�t
void one(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void two(void)
{
	int scale = 3;

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
	
	_delay_ms(50*scale);
	action();
}

void three(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void four(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void five(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void six(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void seven(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void eight(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

//Funktion f�r g�ng fram�t
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

//Funktion f�r g�ng bak�t
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
*********************************************  ROTERA H�GER OCH V�NSTER  ************************************
************************************************************************************************************/

//Funktionerna som utg�r g�ngstilarna rotera h�ger och rotera v�nster
void one_rot(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void two_rot(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void three_rot(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void four_rot(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void five_rot(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void six_rot(void)
{
	int scale = 3;

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
	
	_delay_ms(50*scale);
	action();
}

void seven_rot(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

void eight_rot(void)
{
	int scale = 3;
	
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
	
	_delay_ms(50*scale);
	action();
}

//Funktion f�r att rotera �t h�ger (medurs)
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

//Funktion f�r at rotera �t v�nster (moturs)
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
*********************************************  SNETT FRAM�T  ************************************************
************************************************************************************************************/

//Funktion f�r att g� fram�t-v�nster
void forward_left(void)
{
	for(int i = 0; i < 4; i++)
	{
		forward();
	}
	rot_left();
}

//Funktion f�r att g� fram�t-h�ger
void forward_right(void)
{
	for(int i = 0; i < 4; i++)
	{
		forward();
	}
	rot_right();
}

/************************************************************************************************************
********************************************  �VRIGA FUNKTIONER  ********************************************
************************************************************************************************************/

//Initiera standardinst�llningar f�r servona
void servo_init(void)
{
	set_servo_status_return_level(0xfe, 0x01);
	set_servo_torque(0xfe, 1023);
	set_servo_max_speed(0xfe, 150);			
}						

//Funktion f�r att f� LED:en p� virkortet att blinka
void led_blink(uint16_t i)
{
	while(i > 0)
	{
		PORTB |= (1 << 1);
		_delay_ms(200);
		PORTB = (0 << 1);
		_delay_ms(200);
		i--;
	}
}

void main_init(void)
{
	DDRB |= 0x03;
	led_blink(3);
	uart_init();
	LCD_Init();
	LCD_Clear();
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

	return 0;
}