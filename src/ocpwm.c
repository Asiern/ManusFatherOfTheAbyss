/**
 * @file ocpwm.c
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "ocpwm.h"
#include "defines.h"
#include "p24HJ256GP610A.h"

unsigned int DUTY_MIN = T20ms / 20 * MINPWM; // valor minimo de DUTY
unsigned int DUTY_MAX = T20ms / 20 * MAXPWM; // valor maximo de DUTY

unsigned int duty1, duty2, duty3, duty4, duty5;

void inicDuty()
{
    duty1 = DUTY_MAX / 2;
    duty2 = DUTY_MAX / 2;
    duty3 = DUTY_MAX / 2;
    duty4 = DUTY_MAX / 2;
    duty5 = DUTY_MAX / 2;
}

/**
 * @brief Mover los servos a la posición segura
 */
void moverPosicionSegura()
{
    duty1 = S1_SAFE;
    duty2 = S2_SAFE;
    duty3 = S3_SAFE;
    duty4 = S4_SAFE;
    duty5 = S5_SAFE;
}