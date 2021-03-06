/**
 * @file utils.c
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "utils.h"
#include "defines.h"
#include "ocpwm.h"

unsigned char tablaCarac[] = "0123456789ABCDEF";

/**
 * @brief Calcular módulo a mod b
 *
 * @param value a
 * @param divi b
 * @return unsigned int módulo
 */
unsigned int mod(unsigned int value, unsigned int divi)
{
    return (value % divi + divi) % divi;
}

/**
 * @brief Conversión deltimepo a char
 *
 * @param dir Puntero inicial
 * @param val valor a convertir
 */
void conversionTiempo(unsigned char* dir, unsigned int val)
{
    unsigned char dig;
    if (val > 99)
    {
        while (1)
            ;
    }
    else
    {
        dig = val / 10;
        dig = tablaCarac[dig];
        *dir = dig;
        dir++;
        dig = val % 10;
        dig = tablaCarac[dig];
        *dir = dig;
    }
}

/**
 * @brief Conversión de número en decimal a chars
 *
 * @param dir Dirección de inicio
 * @param val valor
 * @param length número de chars a convertir
 */
void conversionDeci(unsigned char* dir, unsigned int val, unsigned int length)
{
    unsigned int i = 1;

    for (; i <= length; i++)
    {
        dir[length - i] = (char)((val % 10) + '0');
        val /= 10;
    }
}

/**
 * @brief Conversión del valor de los joystick a duty
 *
 * @param valorAnalogico
 * @return unsigned int duty equivalente
 */
unsigned int conversionAnalogicoAServo(unsigned int valorAnalogico)
{
    return DUTY_MIN + ((valorAnalogico / 1023.0) * (DUTY_MAX - DUTY_MIN));
}

/**
 * @brief Calcular valor absoluto |x|
 *
 * @param val x
 * @return int valor absoluto de x = |x|
 */
int abs(int val)
{
    return (val < 0 ? (-val) : val);
}