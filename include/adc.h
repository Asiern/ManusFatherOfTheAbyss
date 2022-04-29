#ifndef _ADC_H
#define _ADH_H

// Variables
extern unsigned int muestrasActuales; // Numero de muestras que se han recogido
extern unsigned int calcularMedias;   // Flag para indicar que es necesario calcular las medias
extern unsigned int tempAcumulada;    // Acumulación de ls muestras de temperatura
extern unsigned int potenAcumulado;   // Acumulación de ls muestras del potenciometro

void inicADC();
void calcularMediaMuestras();

#endif