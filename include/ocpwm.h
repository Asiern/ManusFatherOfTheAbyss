// Servo 1 => RD0
// Servo 2 => RD1
// Servo 3 => RD2
// Servo 4 => RD3
// Servo 5 => RD4

#ifndef _OCPWM_H
#define _OCPWM_H

extern unsigned int DUTY_MIN; // valor minimo de DUTY
extern unsigned int DUTY_MAX; // valor maximo de DUTY

#define NUM_MOTORES 1

extern unsigned int duty1, duty2, duty3, duty4, duty5;

void inicDuty();

#endif