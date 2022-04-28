#include "defines.h"
#include "lcd.h"
#include "p24HJ256GP610A.h"
#include "timers.h"
#include "utils.h"

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

// Rutina de atencion a las interrupciones del T7
void _ISR_NO_PSV _T7Interrupt()
{
    cronoFlag = 1;
    IFS3bits.T7IF = 0; // Apagar el flag de petición de interrupción
}

////////////////////////////////////
////////       UART      ///////////
////////////////////////////////////

// Estados utilizados en la rutina de atencion del UART
enum
{
    L,           // Estado de escritura de la linea
    HOME,        // Estado de mover el cursor a la posicion inicial
    JP           // Estado de escritura de salto de linea
} estado = HOME; // Estado inicial L1

int nLinea = 0;
int TPos = 0; // Posicion del caracter a enviar por UART de la ventanaLCD

// void _ISR_NO_PSV _U2RXInterrupt()
// {
//     switch (U2RXREG)
//     {
//     case 'p':
//         T7CONbits.TON = 0; // Deshabilitar interrupciones del Temporizador T7
//         flag = 0;
//         break;
//     case 'c':
//         T7CONbits.TON = 1; // Habilitar interrupciones del Temporizador T7
//         flag = 0;
//         break;
//     case 'i': // Resetear Temporizador T7
//         flag = 0;
//         reset = 1;
//         TMR7 = 0;
//         break;
//     case 'n':
//         if (servomode == UART_MODE)
//         {
//             duty = duty + 50 < T20ms / 20 * MAXPWM ? duty + 50 : T20ms / 20 * MAXPWM;
//             imprimir_valor_pot_lcd();
//         }
//         break;
//     case 'm':
//         if (servomode == UART_MODE)
//         {
//             duty = duty - 50 > T20ms / 20 * MINPWM ? duty - 50 : T20ms / 20 * MINPWM;
//             imprimir_valor_pot_lcd();
//         }
//         break;
//     default:
//         break;
//     }
//     IFS1bits.U2RXIF = 0;
// }

/**
 * Funcion para atender a las interrupciones del UART
 *
 * Mediante una máquina de estados (con los estados definidos en el enum llamado estado),
 * gestionamos el envio de caracteres por UART para la correcta visualización.
 *
 * En el estado L, escribimos en su línea correspondiente
 * Mediante el estado JP, escribimos el salto de línea.
 * Mediante el estado HOME, movemos el cursor al principio
 *
 * Se utiliza la variable TPos para indicar la posición en la que está escribiendo
 * Se utiliza la variable nLinea para indicar la linea que se está escribiendo
 */
void _ISR_NO_PSV _U2TXInterrupt()
{
    switch (estado)
    {
    case L:
        U2TXREG = ventanaLCD[nLinea][TPos];
        if (TPos == 15)
        {
            estado = JP;
            TPos = 0;
        }
        else
            TPos++;
        break;
    case JP:
        if (TPos == 1)
        {
            estado = nLinea == LCD_ROWS - 1 ? HOME : L;
            nLinea = nLinea == LCD_ROWS - 1 ? 0 : nLinea + 1;
            TPos = 0;
            U2TXREG = LF;
        }
        else
        {
            TPos++;
            U2TXREG = CR;
        }
        break;
    case HOME:
        U2TXREG = home[TPos];
        if (TPos == 2)
        {
            TPos = 0;
            estado = L;
        }
        else
            TPos++;
        break;
    default:
        break;
    }
    IFS1bits.U2TXIF = 0; // Apagar flag de interrupciones
}