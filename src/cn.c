#include "cn.h"
#include "defines.h"
#include "lcd.h"
#include "p24HJ256GP610A.h"
#include "utils.h"

void inicCN()
{
    CNEN1bits.CN15IE = 1; // Habilitar interrupciones del pulsador S3
    IEC1bits.CNIE = 1;    // Habilitar interrupciones del módulo CN
    IFS1bits.CNIF = 0;    // Apagar flag de interrupcion del módulo CN
}

void _ISR_NO_PSV _CNInterrupt()
{
    // Interrupcion S3
    if (!PORTDbits.RD6)
        currentDisplayLine = mod(currentDisplayLine + 1, LCD_ROWS); // Actualizar valor de currentDisplayLine
    IFS1bits.CNIF = 0;                                              // Apagar el flag de petición de interrupción
}
