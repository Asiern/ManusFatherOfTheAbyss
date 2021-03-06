/**
 * @file uart.c
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "uart.h"
#include "defines.h"
#include "lcd.h"
#include "ocpwm.h"
#include "p24HJ256GP610A.h"
#include "timers.h"
#include "utils.h"

unsigned int controlServos = CONTROL_TECLADO;

/**
 * @brief Inicializar registros de la UART para permitir el envío y recepción mediante interrupciones
 *
 */
void inicUART()
{

    // Velocidad de transmision
    U2BRG = BAUD_RATEREG_2_BRGH0;

    // U2MODE: habilitar el modulo (UARTEN), 8 bits, paridad par (PDSEL),
    // 1 bit de stop (STSEL), BRGH ...
    U2MODE = 0;
    U2MODEbits.PDSEL1 = 1; // Paridad par

    // U2STA: modo de interrupcion en el envio (UTXISEL), habilitacion del
    // envio (UTXEN), modo de interrupcion en la recepcion (URXISEL)
    U2STA = 0;

    // inicializacion de los bits IE e IF relacionados (IP si se quiere modificar)
    IFS1bits.U2RXIF = 0;
    IFS1bits.U2TXIF = 0;
    IEC1bits.U2RXIE = 1;
    IEC1bits.U2TXIE = 1;

    // IPC7bits.U2RXIP=xx;
    // IPC7bits.U2TXIP=xx;

    // interrupciones debidas a errores + bug
    IEC4bits.U2EIE = 0;
    U2STAbits.OERR = 0;

    // Habilitar el modulo y la linea TX.
    // Siempre al final y en ese orden!!!

    U2MODEbits.UARTEN = 1; // habilitar UART2
    U2STAbits.UTXEN = 1;   // habilitar transmision tras habilitar modulo

    Delay_us(T_1BIT_US); // Esperar tiempo de 1 bit
    U2TXREG = 0;
}

/**
 * @brief Recibir datos por UART
 *
 * CAMBIAR CONTROL
 * -------------------
 * UART => pulsar cualquier tecla del teclado
 * ANALÓGICO => tecla 1
 *
 * MOVIMENTO SERVOS
 * -------------------
 * Numero | + | - |
 *   1    | m | n |
 *   2    | v | b |
 *   3    | c | x |
 *   4    | l | k |
 *   5    | j | h |
 *
 */
void _ISR_NO_PSV _U2RXInterrupt()
{
    // Activar control por teclado cuando se reciva cualquier tecla por UART
    if (controlServos == CONTROL_ANALOGICO)
    {
        controlServos = CONTROL_TECLADO;
        IFS1bits.U2RXIF = 0;
        return;
    }

    switch (U2RXREG)
    {
    case '1':
        controlServos = CONTROL_ANALOGICO;
        break;
    case 'm': // Servo 1
        duty1 = duty1 + 50 < DUTY_MAX ? duty1 + 50 : DUTY_MAX;
        break;
    case 'n': // Servo 1
        duty1 = duty1 - 50 > DUTY_MIN ? duty1 - 50 : DUTY_MIN;
        break;
    case 'v': // Servo 2
        duty2 = duty2 + 50 < DUTY_MAX ? duty2 + 50 : DUTY_MAX;
        break;
    case 'b': // Servo 2
        duty2 = duty2 - 50 > DUTY_MIN ? duty2 - 50 : DUTY_MIN;
        break;
    case 'c': // Servo 3
        duty3 = duty3 + 50 < DUTY_MAX ? duty3 + 50 : DUTY_MAX;
        break;
    case 'x': // Servo 3
        duty3 = duty3 - 50 > DUTY_MIN ? duty3 - 50 : DUTY_MIN;
        break;
    case 'l': // Servo 4
        duty4 = duty4 + 50 < DUTY_MAX ? duty4 + 50 : DUTY_MAX;
        break;
    case 'k': // Servo 4
        duty4 = duty4 - 50 > DUTY_MIN ? duty4 - 50 : DUTY_MIN;
        break;
    case 'j': // Servo 5
        duty5 = duty5 + 50 < DUTY_MAX ? duty5 + 50 : DUTY_MAX;
        break;
    case 'h': // Servo 5
        duty5 = duty5 - 50 > DUTY_MIN ? duty5 - 50 : DUTY_MIN;
        break;
    }
    IFS1bits.U2RXIF = 0;
}

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

// Estados utilizados en la rutina de atencion del UART
enum
{
    L,           // Estado de escritura de la linea
    HOME,        // Estado de mover el cursor a la posicion inicial
    JP           // Estado de escritura de salto de linea
} estado = HOME; // Estado inicial L1

int nLinea = 0;
int TPos = 0; // Posicion del caracter a enviar por UART de la ventanaLCD

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