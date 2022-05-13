/**
 * @file utils.h
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _UTILS_H
#define _UTILS_H

extern unsigned char tablaCarac[16];

unsigned int mod(unsigned int value, unsigned int divi);
void conversionTiempo(unsigned char* dir, unsigned int val);
void conversionDeci(unsigned char* dir, unsigned int val, unsigned int length);
unsigned int conversionAnalogicoAServo(unsigned int valorAnalogico);
int abs(int val);

#endif