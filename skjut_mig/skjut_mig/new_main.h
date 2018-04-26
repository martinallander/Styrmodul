#ifndef NEW_MAIN_H_
#define NEW_MAIN_H_


#ifndef F_CPU
#define F_CPU 16000000UL							//Sätter CPU-klockan till 16 MHz
#endif

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include "lcd.h"
#include "spi_slave.h"
#include "definitions.h"


//USART-definitioner
#define TXD0_READY bit_is_set(UCSR0A,5)
#define TXD0_FINISHED bit_is_set(UCSR0A,6)
#define RXD0_READY bit_is_set(UCSR0A,7)
#define TXD0_DATA (UDR0)
#define RXD0_DATA (UDR0)

//Definiera baudrate
#define BAUD 1000000
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)			//Sätt baudrate för UBRR enligt formel i databladet

//Definitioner för olika kommandon för servona
typedef enum ServoCommand
{
	PING = 1,
	READ = 2,
	WRITE = 3,
	REG = 4,
	ACTION = 5
} ServoCommand;

//Adresser i EEPROM dit olika data skrivs
#define MAX_SPEED				   0x20
#define GOAL_ANGLE				   0x1e
#define TORQUE					   0x22
#define RETURN_LEVEL			   0x10				//När servot ska skicka tillbaka data
#define LOWER_ANGLE_LIMIT    	   0x06
#define HIGHER_ANGLE_LIMIT         0x08
#define PRESENT_ANGLE			   0X24
#define LOWEST_VOLTAGE_LIMIT	   0X0c
#define HIGHEST_VOLTAGE_LIMIT	   0x0d
#define HIGHEST_TEMPERATURE_LIMIT  0x0b
#define SERVO_ID                   0x03
#define GLOBAL_ID				   0xfe

//Startvinklar då roboten står upp
#define STAND_DEG_00				150
#define STAND_DEG_03				150
#define STAND_DEG_06				150
#define STAND_DEG_09				150
#define STAND_DEG_12				150
#define STAND_DEG_15				150

#define STAND_DEG_01				 90
#define STAND_DEG_04				 90
#define STAND_DEG_07				 90
#define STAND_DEG_10				210
#define STAND_DEG_13				210
#define STAND_DEG_16				210

#define STAND_DEG_02				230
#define STAND_DEG_05				230
#define STAND_DEG_08				230
#define STAND_DEG_11				 70
#define STAND_DEG_14				 70
#define STAND_DEG_17				 70

void recieve_mode(void);
void send_mode(void);

void uart_init(void);
void uart_transmit(unsigned char data);
unsigned char uart_recieve(void);

uint16_t servo_read_status_packet(void);

void send_servo_command(const uint8_t servoId, const ServoCommand commandByte, const uint8_t numParams, const uint8_t *params);

void set_servo_angle (const uint8_t servoId, const float angle);
void set_servo_status_return_level (const uint8_t servoId, const uint8_t returnlevel);
void set_servo_max_speed (const uint8_t servoId, const uint16_t speedValue);
void set_servo_torque (const uint8_t servoId, const uint16_t torqueValue);
void set_servo_angle_limit (const uint8_t servoId, const uint16_t lowerLimit, const uint16_t higherLimit);

void reg_servo_angle (const uint8_t servoId, const float angle);

void action(void);

void stand(void);

void one(void);
void two(void);
void three(void);
void four(void);
void five(void);
void six(void);
void seven(void);
void eight(void);

void forward(void);
void backward(void);

void one_rot(void);
void two_rot(void);
void three_rot(void);
void four_rot(void);
void five_rot(void);
void six_rot(void);
void seven_rot(void);
void eight_rot(void);

void rot_left(void);
void rot_right(void);

void forward_left(void);
void forward_right(void);

void led_blink(uint16_t i);

void servo_init(void);
void main_init(void);

int main(void);


#endif /* NEW_MAIN_H_ */