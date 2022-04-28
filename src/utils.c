#include "utils.h"

unsigned int mod(unsigned int value, unsigned int divi)
{
    return (value % divi + divi) % divi;
}

unsigned char tablaCarac[16] = "0123456789ABCDEF";
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