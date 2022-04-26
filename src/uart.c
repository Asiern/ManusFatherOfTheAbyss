#include "uart.h"
#include "defines.h"
#include "p24HJ256GP610A.h"
#include "timers.h"

void inicUART()
{

    // Velocidad de transmision
    // Hay que hacer solo una de las dos asignaciones siguientes
    // U2BRG = BAUD_RATEREG_2_BRGH1;
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