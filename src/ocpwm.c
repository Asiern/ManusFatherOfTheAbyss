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

unsigned int duty1, duty2, duty3, duty4, duty5;                                         // Dutys de los servos
unsigned int duty1objetivo, duty2objetivo, duty3objetivo, duty4objetivo, duty5objetivo; // Dutys objetivo de los servos

/**
 * @brief Inicializar los valores de los duty a un valor intermedio
 *
 */
void inicDuty()
{
    duty1 = duty1objetivo = (DUTY_MAX + DUTY_MIN) / 2;
    duty2 = duty2objetivo = (DUTY_MAX + DUTY_MIN) / 2;
    duty3 = duty3objetivo = (DUTY_MAX + DUTY_MIN) / 2;
    duty4 = duty4objetivo = (DUTY_MAX + DUTY_MIN) / 2;
    duty5 = duty5objetivo = (DUTY_MAX + DUTY_MIN) / 2;
}

/**
 * @brief Mover los servos a la posición segura
 */
void moverPosicionSegura()
{
    duty1objetivo = S1_SAFE;
    duty2objetivo = S2_SAFE;
    duty3objetivo = S3_SAFE;
    duty4objetivo = S4_SAFE;
    duty5objetivo = S5_SAFE;
}

/**
 * @brief Inicializar los puertos de los servos como salida
 *
 */
void inicPWM()
{
    TRISDbits.TRISD0 = 0; // Servo 1
    TRISDbits.TRISD1 = 0; // Servo 2
    TRISDbits.TRISD2 = 0; // Servo 3
    TRISDbits.TRISD3 = 0; // Servo 4
    TRISDbits.TRISD8 = 0; // Servo 5
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
    LATDbits.LATD3 = 0;
    LATDbits.LATD8 = 0;
}