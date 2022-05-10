/**
 * @file defines.h
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#define Nop() __builtin_nop()

#define _ISR_NO_PSV __attribute__((interrupt, no_auto_psv))

/////////////////////////////////////
// definiciones para la pantalla LCD
/////////////////////////////////////

// For Explorer 16 board, here are the data and control signal definitions
// RS -> RB15
// E  -> RD4
// RW -> RD5
// DATA -> RE0 - RE7

// Control signal data pins
#define RW LATDbits.LATD5  // LCD R/W signal
#define RS LATBbits.LATB15 // LCD RS signal
#define E LATDbits.LATD4   // LCD E signal

// Control signal pin direction
#define RW_TRIS TRISDbits.TRISD5
#define RS_TRIS TRISBbits.TRISB15
#define E_TRIS TRISDbits.TRISD4

// Data signals and pin direction
#define DATA LATE // Port for LCD data
#define DATAPORT PORTE
#define TRISDATA TRISE // I/O setup for data Port

////////////////////////////////////
// definiciones posiciones cronometro
///////////////////////////////////
#define posds 13
#define posseg 10
#define posmin 7

// Definiciones ligadas a la velocidad de transmision de UART2

#define Fosc 40000000                       // Frecuencia de reloj de la CPU (oscillator)
#define Fcy Fosc / 2                        // Velocidad de ejecucion de las instrucciones
#define BAUDRATE2 19200                     // Velocidad de transmision de UART2 (baudios)
#define T_1BIT_US (1000000 / BAUDRATE2) + 1 // Duracion de 1 bit

#define BAUD_RATEREG_2_BRGH1 ((Fcy / BAUDRATE2) / 4) - 1  // valor U2BRG si BRGH=1
#define BAUD_RATEREG_2_BRGH0 ((Fcy / BAUDRATE2) / 16) - 1 // valor U2BRG si BRGH=0

// Definiciones relacionadas con la pantalla del terminal del PC

#define clrscr "\x1b[2J" // 4 character: \x1b, [, 2, J
#define home "\x1b[H"    // 3 character: \x1b, [, H

#define CR 0x0D // carriage return
#define LF 0x0A // line feed

// Definiciones relacionadas con los servos y PWM
//=========================================================
#define T20ms 50000 // Periodo adecuado para conseguir 20 ms
// teniendo en cuenta un prescaler de xxx.
#define MINPWM 0.3 // Duracion minima pulso PWM (en milisegundos)
#define MAXPWM 2.3 // Duracion maxima pulso PWM (en milisegundos)