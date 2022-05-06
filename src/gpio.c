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
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB8 = 1;
    TRISBbits.TRISB9 = 1;
    TRISBbits.TRISB10 = 1;
    TRISDbits.TRISD0 = 0; // Servo 1
    TRISDbits.TRISD1 = 0; // Servo 2
    TRISDbits.TRISD2 = 0; // Servo 3
    TRISDbits.TRISD3 = 0; // Servo 4
    TRISDbits.TRISD8 = 0; // Servo 5
}