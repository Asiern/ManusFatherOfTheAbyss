#include "gpio.h"
#include "p24HJ256GP610A.h"

void inicPulsadores()
{
    // Definir pines AN16 - AN31 como pines digitales para evitar problemas
    AD1PCFGH = 0xffff;

    TRISDbits.TRISD6 = 1; // Definir los pines del pulsador S3 como entrada
}

void inicPuertos()
{
    // Definir pines AN16 - AN31 como pines digitales para evitar problemas
    AD1PCFGH = 0xffff;

    TRISDbits.TRISD6 = 1; // Definir los pines del pulsador S3 como entrada
    TRISBbits.TRISB8 = 1;
    TRISBbits.TRISB9 = 1;
    TRISBbits.TRISB10 = 1;
}