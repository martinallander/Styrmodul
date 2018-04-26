//Sätter CPU-klockan till 16 MHz
#ifndef F_CPU
#define F_CPU 16000000UL                 
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

#define BAUD 1000000
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)    //Sätt baudrate för UBRR enligt formel i databladet

//Olika kommandon för servona
typedef enum ServoCommand
{
	PING = 1,
	READ = 2,
	WRITE = 3,
	REG = 4,
	ACTION = 5
} ServoCommand;
