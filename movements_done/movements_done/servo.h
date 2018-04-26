#ifndef SERVO_H_
#define SERVO_H_

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>

#include "definitions.h"

uint16_t servo_read_status_packet(void);

void send_servo_command(const uint8_t servoId, const ServoCommand commandByte, const uint8_t numParams, const uint8_t *params);

void set_servo_angle (const uint8_t servoId, const float angle);

void set_servo_status_return_level (const uint8_t servoId, const uint8_t returnlevel);

void set_servo_max_speed (const uint8_t servoId, const uint16_t speedValue);

void set_servo_torque (const uint8_t servoId, const uint16_t torqueValue);

void set_servo_angle_limit (const uint8_t servoId, const uint16_t lowerLimit, const uint16_t higherLimit);

void reg_servo_angle (const uint8_t servoId, const float angle);

void action(void);

void servo_init(void);

#endif /* SERVO_H_ */