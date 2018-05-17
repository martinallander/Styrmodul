#ifndef WALK_H_
#define WALK_H_

#ifndef F_CPU
#define F_CPU 16000000UL							//Sätter CPU-klockan till 16 MHz
#endif

#include <stdlib.h>
#include <stdbool.h>

#include "spi_slave.h"
#include "led.h"
#include "servo.h"

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
void forward_new(void);
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

void turn_left(void);
void turn_right(void);

void execute_command(void); 
void set_data_sending(bool value);

#endif /* WALK_H_ */