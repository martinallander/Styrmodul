#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "definitions.h"

void spi_init(void);

void data_direction_init();

//Function to send and receive data
unsigned char spi_tranceiver (unsigned char indata);