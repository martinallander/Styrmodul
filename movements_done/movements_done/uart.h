#ifndef UART_H_
#define UART_H_

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>

#include "definitions.h"

void recieve_mode(void);

void send_mode(void);

void uart_init(void);

void uart_transmit(unsigned char data);

unsigned char uart_recieve(void);

#endif /* UART_H_ */