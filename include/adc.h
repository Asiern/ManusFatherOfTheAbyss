/**
 * @file adc.h
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

// Joystick pequeño
// VERT RB8 => AN8
// HORZ RB9 => AN9
// SEL RB15 => AN15 => CN12

// Joystick grande
// Px      RB0 => AN0
// Py      RB1 => AN1
// Palanca RB2 => AN2

#ifndef _ADC_H
#define _ADH_H

typedef struct
{
    unsigned int x;
    unsigned int y;
    float acceleration;
} axis;

// Variables
extern unsigned int muestrasActuales; // Numero de muestras que se han recogido
extern unsigned int calcularMedias;   // Flag para indicar que es necesario calcular las medias
extern unsigned int tempVec[8];       // Acumulación de las muestras de temperatura
extern unsigned int potenVec[8];      // Acumulación de las muestras del potenciometro
extern axis jpVec[8];                 // Acumulación de las muestras del eje (joystick pequeño)
extern axis jgVec[8];                 // Acumulación de las muestras del eje (joystick grande)
extern unsigned int jPalancaVec[8];   // Acumulación de la palanca (joystick grande)

extern axis valoresFinalesJGrande;
extern axis valoresFinalesJPeq;
extern unsigned int tempFinal;
extern unsigned int potenFinal;
extern unsigned int palancaFinal;

void inicADC();
void calcularMediaMuestras();

#endif