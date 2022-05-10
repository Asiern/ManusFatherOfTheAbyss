/**
 * @file uart.h
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _UART_H
#define _UART_H

#define CONTROL_TECLADO 0
#define CONTROL_ANALOGICO 1

extern unsigned int controlServos;

void inicUART();

#endif