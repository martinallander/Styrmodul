#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>

#include "definitions.h"
#include "spi_slave.h"

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

void execute_command(void); 
