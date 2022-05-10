/**
 * @file timers.h
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

// T2 se utiliza para simular el pwm
// T3 se utiliza para el modulo ADC
// T5 se utiliza para escribir en la ventanaLCD
// T7 se utiliza para el cronometro
// T9 se utiliza para las funciones de Delay

#ifndef _TIMERS_H
#define _TIMERS_H

// Variables
extern unsigned int cronoFlag; // Flag que indica que han pasado 10 ms

// Delays
void Delay_ms(int delay);
void Delay_us(int delay);

// Timers
void inicT2();
void inicT3();
void inicT5();
void inicT7();

void cronometro();

#endif