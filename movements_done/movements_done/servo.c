#include "servo.h"

/************************************************************************************************************
**************************************  FUNKTIONER FÖR GET-KOMMANDON  **************************************
************************************************************************************************************/

//Läser igenom hela statuspaketet i servot och returnerar efterfrågat parametervärde
uint16_t servo_read_status_packet(void)
{
	uint16_t ValueOfParameters = 0;
	uint8_t Start1 = uart_recieve();								//Läser igenom de olika delarna av statuspaketet och sparar i variabler. Varje del är 1 byte stor
	uint8_t Start2 = uart_recieve();								//Statuspaketet inleds med två stycken startbytes
	uint8_t ID = uart_recieve();
	uint8_t Length = uart_recieve();
	uint8_t Error = uart_recieve();
	uint8_t HelpVariable = 0;
	
	while(Length > 2)												//Läser av parametervärdena och sparar värdet i ValueOfParameters
	{
		ValueOfParameters = ValueOfParameters + (uart_recieve() << (8*HelpVariable));
		HelpVariable++;
		Length--;
	}
	
	uint8_t CheckSum = uart_recieve();
	return ValueOfParameters;										//Om det är vinklar som hämtas så måste ValueOfParameters multipliceras med (uint16_t)300/1023
}

/************************************************************************************************************
**************************************  FUNKTIONER FÖR SET-KOMMANDON  **************************************
************************************************************************************************************/

//Skicka ett kommando till ett servo
void send_servo_command(const uint8_t servoId, const ServoCommand commandByte, const uint8_t numParams, const uint8_t *params)
{
	cli();															//Blockerar avbrott
	send_mode();
	UCSR0A = UCSR0A | (0 << 6);										//Gjorde så att vi kunde skicka en instruktion efter en instruktion/read.
	uart_transmit(0xff);											//Skickar 2 stycken startbytes
	uart_transmit(0xff);
	
	uart_transmit(servoId);											//Skickar servo-ID
	uint8_t checksum = servoId;
	
	uart_transmit(numParams + 2);									//Skickar antal parametrar + 2
	uart_transmit((uint8_t)commandByte);							//Skickar själva kommandot
	checksum += numParams + 2 + commandByte;
	
	for(uint8_t i = 0; i < numParams; i++)
	{
		uart_transmit(params[i]);									//Skickar parametrarna
		checksum += params[i];
	}
	
	uart_transmit(~checksum);										//Skickar checksum med inverterade bitar
	while(!TXD0_FINISHED) {}										//TXD0 sätts till 1 då all data shiftats ut ifrån USART:en. Väntar tills den sänt klart det sista
	recieve_mode();
	sei();															//Tillåter avbrott igen
}

//Sätt vinkel för ett servon
void set_servo_angle (const uint8_t servoId, const float angle)
{
	uint16_t angleValue = (uint16_t)(angle * (1023.0 / 300.0));
	uint8_t highByte = (uint8_t)((angleValue >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(angleValue & 0xff);
	uint8_t params[3] = {GOAL_ANGLE, lowByte, highByte};
	send_servo_command (servoId, WRITE, 3, params);
}

//Välj när ett servo ska skicka tillbaka data. returnlevel kan ha tre olika värden:
//0 - Svara inte på några instruktioner
//1 - Svara bara på READ_DATA-instruktioner
//2 - Svara på alla instruktioner
void set_servo_status_return_level (const uint8_t servoId, const uint8_t returnlevel)
{
	uint8_t params[2] = {RETURN_LEVEL, returnlevel};
	send_servo_command (servoId, WRITE, 2, params);
}

//Sätt maximal vinkalhastighet för ett servo
void set_servo_max_speed (const uint8_t servoId, const uint16_t speedValue)
{
	uint8_t highByte = (uint8_t)((speedValue >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(speedValue & 0xff);
	uint8_t params[3] = {MAX_SPEED, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

//Sätter gräns för tillåten belastning för ett servo
void set_servo_torque (const uint8_t servoId, const uint16_t torqueValue)
{
	uint8_t highByte = (uint8_t)((torqueValue >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(torqueValue & 0xff);
	uint8_t params[3] = {TORQUE, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

//Sätter gränser för tillåtna servovinklar
void set_servo_angle_limit (const uint8_t servoId, const uint16_t lowerLimit, const uint16_t higherLimit)
{
	uint8_t highByte1 = (uint8_t)((lowerLimit >> 8) & 0xff);
	uint8_t lowByte1 = (uint8_t)(lowerLimit & 0xff);
	uint8_t params1[3] = {LOWER_ANGLE_LIMIT, lowByte1, highByte1};
	send_servo_command(servoId, WRITE, 3, params1);

	uint8_t highByte2 = (uint8_t)((higherLimit >> 8) & 0xff);
	uint8_t lowByte2 = (uint8_t)(higherLimit & 0xff);
	uint8_t params2[3] = {HIGHER_ANGLE_LIMIT, lowByte2, highByte2};
	send_servo_command(servoId, WRITE, 3, params2);
}

//Laddar ett servo med en vinkel
void reg_servo_angle (const uint8_t servoId, float angle)
{
	uint16_t angleValue = (uint16_t)(angle * (1023.0 / 300.0));
	uint8_t highByte = (uint8_t)((angleValue >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(angleValue & 0xff);
	uint8_t params[3] = {GOAL_ANGLE, lowByte, highByte};
	send_servo_command (servoId, REG, 3, params);
}


void set_servo_max_temp(const uint8_t servoId, const uint16_t tempValue)
{
	uint8_t highByte = (uint8_t)((tempValue >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(tempValue & 0xff);
	uint8_t params[3] = {HIGHEST_TEMPERATURE_LIMIT, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

void set_servo_max_volt(const uint8_t servoId, const uint16_t voltValue)
{
	uint8_t highByte = (uint8_t)((voltValue >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(voltValue & 0xff);
	uint8_t params[3] = {HIGHEST_TEMPERATURE_LIMIT, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

void set_alarm_shutdown(const uint8_t servoId, const uint16_t alarmBits)
{
	uint8_t highByte = (uint8_t)((alarmBits >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(alarmBits & 0xff);
	uint8_t params[3] = {SHUTDOWN_ID, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

void set_alarm_led(const uint8_t servoId, const uint16_t alarmBits)
{
	uint8_t highByte = (uint8_t)((alarmBits >> 8) & 0xff);
	uint8_t lowByte = (uint8_t)(alarmBits & 0xff);
	uint8_t params[3] = {ALARM_LED_ID, lowByte, highByte};
	send_servo_command(servoId, WRITE, 3, params);
}

//Utför de instruktioner som servona har laddats med
void action(void)
{
	uint8_t params[1] = {0};
	send_servo_command (0xfe, ACTION, 0, params);
}

/************************************************************************************************************
********************************************  ÖVRIGA FUNKTIONER  ********************************************
************************************************************************************************************/

//Initiera standardinställningar för servona
void servo_init(void)
{
	set_servo_status_return_level(0xfe, 0x00);
	set_servo_torque(0xfe, 1023);
	set_servo_max_speed(0xfe, 150);
	set_servo_max_temp(0xfe, 70);
	set_alarm_shutdown(0xfe, 7); 
	set_alarm_led(0xfe, 4);
}
