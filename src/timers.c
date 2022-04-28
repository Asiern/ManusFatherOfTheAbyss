#include "timers.h"
#include "lcd.h"
#include "p24HJ256GP610A.h"

unsigned int mili, deci, min, seg;
unsigned int cronoFlag = 0;

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

void inicT7()
{
    TMR7 = 0;            // Inicializar el registro de cuenta
    PR7 = 25000 - 1;     // Periodo del temporizador
                         // Queremos que cuente 10 ms.
                         // Fosc= 40 MHz (vease Inic_oscilator()) de modo que
                         // Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
                         // Por tanto, Tcy= 50 ns para ejecutar una instruccion
                         // Para contar 10 ms se necesitan 200000 ciclos.
    T7CONbits.TCKPS = 1; // escala del prescaler
    T7CONbits.TCS = 0;   // reloj interno
    IFS3bits.T7IF = 0;
    IEC3bits.T7IE = 1;   // habilitar interrupciones del temporizador t7
    T7CONbits.TGATE = 0; // Deshabilitar el modo Gate
    T7CONbits.TON = 1;   // puesta en marcha del temporizador
}

void cronometro() // control del tiempo mediante el temporizador 7
{

    if (cronoFlag)
    {
        mili += 10;
        if (mili == 100)
        {
            mili = 0;
            deci++;
            LATAbits.LATA7 = !LATAbits.LATA7;
            if (deci == 10)
            {
                deci = 0;
                seg++;
                LATAbits.LATA6 = !LATAbits.LATA6;
                if (seg == 60)
                {
                    seg = 0;
                    min++;
                    conversionTiempo(&(ventanaLCD[LCD_CRONO][7]), min);
                }
                conversionTiempo(&(ventanaLCD[LCD_CRONO][10]), seg == 60 ? 0 : seg);
            }
            unsigned char c[2];
            conversionTiempo(&(c[0]), deci);
            ventanaLCD[LCD_CRONO][13] = c[1];
        }
        cronoFlag = 0;
    }
}