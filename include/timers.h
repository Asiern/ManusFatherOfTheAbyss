// T5 se utiliza para escribir en la ventanaLCD
// T9 se utiliza para las funciones de Delay

#ifndef _TIMERS_H
#define _TIMERS_H

// Variables
extern unsigned int cronoFlag; // Flag que indica que han pasado 10 ms

// Delays
void Delay_ms(int delay);
void Delay_us(int delay);

// Timers
void inicT5();
void inicT7();

void cronometro();

#endif