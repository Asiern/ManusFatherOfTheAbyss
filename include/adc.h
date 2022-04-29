#ifndef _ADC_H
#define _ADH_H

// Joystick pequeño
// VERT RB8 => AN8
// HORZ RB9 => AN9
// SEL RB10 => AN10

// Variables
extern unsigned int muestrasActuales; // Numero de muestras que se han recogido
extern unsigned int calcularMedias;   // Flag para indicar que es necesario calcular las medias
extern unsigned int tempAcumulada;    // Acumulación de las muestras de temperatura
extern unsigned int potenAcumulado;   // Acumulación de las muestras del potenciometro
extern unsigned int jpHoriAcumulado;  // Acumulación de las muestras del eje Horizontal
extern unsigned int jpVertAcumulado;  // Acumulación de las muestras del eje Vertical

void inicADC();
void calcularMediaMuestras();

#endif