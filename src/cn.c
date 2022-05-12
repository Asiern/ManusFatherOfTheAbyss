/**
 * @file cn.c
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "cn.h"
#include "defines.h"
#include "lcd.h"
#include "p24HJ256GP610A.h"
#include "utils.h"

void inicCN()
{
    CNEN1bits.CN15IE = 1; // Habilitar interrupciones del pulsador S3
    CNEN2bits.CN19IE = 1; // Habilitar interrupciones del pulsador del joystick pequeño
    IEC1bits.CNIE = 1;    // Habilitar interrupciones del módulo CN
    IFS1bits.CNIF = 0;    // Apagar flag de interrupcion del módulo CN
}

void _ISR_NO_PSV _CNInterrupt()
{
    int a;
    // Interrupcion S3
    if (!PORTDbits.RD6)
        currentDisplayLine = mod(currentDisplayLine + 1, LCD_ROWS); // Actualizar valor de currentDisplayLine
    // Interrupcion pulsador joystick pequeño
    if (!PORTDbits.RD13)
        end = 1; // Encender flag de finalizado

    IFS1bits.CNIF = 0; // Apagar el flag de petición de interrupción
}
