#ifndef _UTILS_H
#define _UTILS_H

extern unsigned char tablaCarac[16];

unsigned int mod(unsigned int value, unsigned int divi);
void conversionTiempo(unsigned char* dir, unsigned int val);
void conversionDeci(unsigned char* dir, unsigned int val, unsigned int length);
unsigned int conversionAnalogicoAServo(unsigned int valorAnalogico);

#endif