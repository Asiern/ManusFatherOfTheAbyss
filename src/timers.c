/**
 * @file timers.c
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "timers.h"
#include "adc.h"
#include "defines.h"
#include "lcd.h"
#include "ocpwm.h"
#include "p24HJ256GP610A.h"
#include "uart.h"
#include "utils.h"

unsigned int mili, deci, min, seg;
unsigned int cronoFlag = 0;
unsigned int estado_pwm = 0;
unsigned int PWM_acumula = 0;

void Delay_ms(int delay)
{
    TMR9 = 0;            // Inicializar registro contador
    T9CONbits.TCKPS = 0; // preescaler	1:1

    if (delay > 2)
    {
        T9CONbits.TCKPS = 1; // preescaler	1:8
        PR9 = delay * (20000 / 8);
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

// Interrumpir cada 20ms
void inicT2()
{
    TMR2 = 0;
    PR2 = T20ms;
    T2CONbits.TCKPS = 1;
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    T2CONbits.TON = 1;
}

void _ISR_NO_PSV _T2Interrupt()
{
    switch (estado_pwm)
    {
    case 0:
        LATDbits.LATD0 = 1;
        PR2 = duty1;
        PWM_acumula = duty1;
        estado_pwm = 1;
        break;
    case 1:
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        PR2 = duty2;
        PWM_acumula += duty2;
        estado_pwm = 2;
        break;
    case 2:
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;
        PR2 = duty3;
        PWM_acumula += duty3;
        estado_pwm = 3;
        break;
    case 3:
        LATDbits.LATD2 = 0;
        LATDbits.LATD3 = 1;
        PR2 = duty4;
        PWM_acumula += duty4;
        estado_pwm = 4;
        break;
    case 4:
        LATDbits.LATD3 = 0;
        LATDbits.LATD8 = 1;
        PR2 = duty5;
        PWM_acumula += duty5;
        estado_pwm = 5;
        break;
    case 5:
        LATDbits.LATD8 = 0;
        PR2 = T20ms - PWM_acumula;
        estado_pwm = 0;
        break;
    }
    IFS0bits.T2IF = 0;
}

// Interrumpir cada 1ms
void inicT3()
{
    TMR3 = 0;
    PR3 = 20000 - 1;
    T3CONbits.TCKPS = 0;
    T3CONbits.TCS = 0;
    T3CONbits.TGATE = 0;
    IEC0bits.T3IE = 1;
    IFS0bits.T3IF = 0;
    T3CONbits.TON = 1;
}

// Rutina de atencion a las interrupciones del T3
void _ISR_NO_PSV _T3Interrupt()
{
    AD1CON1bits.SAMP = 1; // Habilitar muestreo
    IFS0bits.T3IF = 0;    // Apagar el flag de petición de interrupción
}

void inicT4()
{
    TMR4 = 0;
    PR4 = 20000 - 1;
    T4CONbits.TCKPS = 0;
    T4CONbits.TCS = 0;
    T4CONbits.TGATE = 0;
    IEC1bits.T4IE = 1;
    IFS1bits.T4IF = 0;
    T4CONbits.TON = 1;
}

void _ISR_NO_PSV _T4Interrupt()
{
    if (controlServos == CONTROL_ANALOGICO)
    {
        if (duty1objetivo < duty1)
            duty1 -= DUTY_AUGMENT;
        else
            duty1 += DUTY_AUGMENT;

        if (duty2objetivo < duty2)
            duty2 -= DUTY_AUGMENT;
        else
            duty2 += DUTY_AUGMENT;

        if (duty3objetivo < duty3)
            duty3 -= DUTY_AUGMENT;
        else
            duty3 += DUTY_AUGMENT;

        if (duty4objetivo < duty4)
            duty4 -= DUTY_AUGMENT;
        else
            duty4 += DUTY_AUGMENT;

        if (duty5objetivo < duty5)
            duty5 -= DUTY_AUGMENT;
        else
            duty5 += DUTY_AUGMENT;
    }
    IFS1bits.T4IF = 0;
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
    IFS1bits.T5IF = 0;
    T5CONbits.TON = 1;
}

/**
 * Funcion para atender a las interrupciones del T5
 *
 * Mediante una máquina de estados (con los estados definidos en el enum llamado estadoLCD),
 * gestionamos el envio de caracteres a la pantalla LCD.
 *
 * En los estados L1 y L2, escribimos en su línea correspondiente
 * Mediante el estado HOME1, movemos el cursor al principio de la línea 1
 * Mediante el estado HOME2, movemos el cursor al principio de la línea 2
 *
 * Se utiliza la variable LPos para indicar la posición en la que está escribiendo
 */
enum // Estados utilizados en la rutina de atencion del T5
{
    L1, // Estado de escritura en la linea1
    L2, // Estado de escritura en la linea2
    HOME1,
    HOME2,
} estadoLCD = HOME1; // Estado inicial L1

unsigned int LPos = 0; // Posicion del caracter a enviar a la ventanaLCD

void _ISR_NO_PSV _T5Interrupt()
{
    switch (estadoLCD)
    {
    case HOME1:
        lcdCmd(0x80);
        estadoLCD = L1;
        break;
    case HOME2:
        lcdCmd(0xC0);
        estadoLCD = L2;
        break;
    case L1:
        lcdData(ventanaLCD[currentDisplayLine][LPos]);
        if (LPos == 15)
        {
            estadoLCD = HOME2;
            LPos = 0;
        }
        else
            LPos++;
        break;
    case L2:
        lcdData(ventanaLCD[mod(currentDisplayLine + 1, LCD_ROWS)][LPos]);
        if (LPos == 15)
        {
            estadoLCD = HOME1;
            LPos = 0;
        }
        else
            LPos++;
        break;
    default:
        break;
    }
    IFS1bits.T5IF = 0; // Apagar flag de interrupciones
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

// Rutina de atencion a las interrupciones del T7
void _ISR_NO_PSV _T7Interrupt()
{
    cronoFlag = 1;
    IFS3bits.T7IF = 0; // Apagar el flag de petición de interrupción
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
            if (deci == 10)
            {
                deci = 0;
                seg++;
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