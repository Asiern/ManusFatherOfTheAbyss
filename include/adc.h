#ifndef _ADC_H
#define _ADH_H

// Joystick pequeño
// VERT RB8 => AN8
// HORZ RB9 => AN9
// SEL RB10 => AN10

// Joystick grande
// Px      RB0 => AN0
// Py      RB1 => AN1
// Palanca RB2 => AN2

// Variables
extern unsigned int muestrasActuales;  // Numero de muestras que se han recogido
extern unsigned int calcularMedias;    // Flag para indicar que es necesario calcular las medias
extern unsigned int tempAcumulada;     // Acumulación de las muestras de temperatura
extern unsigned int potenAcumulado;    // Acumulación de las muestras del potenciometro
extern unsigned int jpHoriAcumulado;   // Acumulación de las muestras del eje Horizontal (joystick pequeño)
extern unsigned int jpVertAcumulado;   // Acumulación de las muestras del eje Vertical (joystick pequeño)
extern unsigned int jXAcumulado;       // Acumulación de las muestras del eje X (joystick grande)
extern unsigned int jYAcumulado;       // Acumulación de las muestras del eje Y (joystick grande)
extern unsigned int jPalancaAcumulado; // Acumulación de la palanca (joystick grande)

void inicADC();
void calcularMediaMuestras();

#endif