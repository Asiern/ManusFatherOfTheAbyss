/**
 * @file gpio.c
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "gpio.h"
#include "p24HJ256GP610A.h"

/**
 * @brief Inicializar pulsadores
 *
 */
void inicPulsadores()
{
    // Definir pines AN16 - AN31 como pines digitales para evitar problemas
    AD1PCFGH = 0xffff;

    TRISDbits.TRISD6 = 1; // Definir los pines del pulsador S3 como entrada
}

/**
 * @brief Inicializar puertos
 *
 */
void inicPuertos()
{
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB8 = 1;
    TRISBbits.TRISB9 = 1;
    TRISDbits.TRISD13 = 1;
}