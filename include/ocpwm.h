/**
 * @file ocpwm.h
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

// Servo 1 => RD0
// Servo 2 => RD1
// Servo 3 => RD2
// Servo 4 => RD3
// Servo 5 => RD4

#ifndef _OCPWM_H
#define _OCPWM_H

extern unsigned int DUTY_MIN; // valor minimo de DUTY
extern unsigned int DUTY_MAX; // valor maximo de DUTY

// Safe positions
#define S1_SAFE 3650
#define S2_SAFE 5800
#define S3_SAFE 6250
#define S4_SAFE 2900
#define S5_SAFE 3750

extern unsigned int duty1, duty2, duty3, duty4, duty5;

void inicDuty();
void inicPWM();
void moverPosicionSegura();

#endif