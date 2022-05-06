#include "utils.h"
#include "defines.h"
#include "ocpwm.h"

unsigned int mod(unsigned int value, unsigned int divi)
{
    return (value % divi + divi) % divi;
}

unsigned char tablaCarac[] = "0123456789ABCDEF";

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

void conversionDeci(unsigned char* dir, unsigned int val, unsigned int length)
{
    unsigned int i = 1;

    for (; i <= length; i++)
    {
        dir[length - i] = (char)((val % 10) + '0');
        val /= 10;
    }
}

unsigned int conversionAnalogicoAServo(unsigned int valorAnalogico)
{
    return DUTY_MIN + ((valorAnalogico / 1023.0) * (DUTY_MAX - DUTY_MIN));
}