#ifndef F_CPU
#define F_CPU 16000000UL							//Sätter CPU-klockan till 16 MHz       
#endif

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include "main.h"
#include "alfred_monkaS.h"

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


