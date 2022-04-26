#include "timers.h"
#include "p24HJ256GP610A.h"

void Delay_ms(int delay)
{
    TMR9 = 0;            // Inicializar registro contador
    T9CONbits.TCKPS = 0; // preescaler	1:1

    if (delay > 2)
    {
        T9CONbits.TCKPS = 1; // preescaler	1:8
        PR9 = delay * (125000 / 8);
    }

    T9CONbits.TCS = 0;
    T9CONbits.TGATE = 0; // Apagar modo gate
    T9CONbits.TON = 1;   // Encender temporizador

    // Esperar a que pase el tiempo
    while (IFS3bits.T9IF == 0)
        ;

    IFS3bits.T9IF = 0; // Apagar flag de interrupcion

    // Apagar timer
    T9CONbits.TON = 0;
}

void Delay_us(int delay)
{
    TMR9 = 0;            // Inicializar registro contador
    T9CONbits.TCKPS = 1; // preescaler	1:8
    T9CONbits.TCS = 0;
    T9CONbits.TON = 1;

    PR9 = (delay * 2000 / 8);

    // Esperar a que pase el tiempo
    while (IFS3bits.T9IF == 0)
        ;

    IFS3bits.T9IF = 0; // Apagar flag de interrupcion

    // Apagar timer
    T9CONbits.TON = 0;
}

// Inicializar el temporizador 5 (escribe en la ventana LCD) cada 2.5ms
void inicT5()
{
    TMR5 = 0;
    PR5 = 50000 - 1;
    T5CONbits.TCKPS = 0;
    T5CONbits.TCS = 0;
    IEC1bits.T5IE = 1;
    T5CONbits.TGATE = 0;
    T5CONbits.TON = 1;
    IFS1bits.T5IF = 0;
}