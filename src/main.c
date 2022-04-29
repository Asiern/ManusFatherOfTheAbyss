#include "adc.h"
#include "cn.h"
#include "gpio.h"
#include "lcd.h"
#include "oscilator.h"
#include "p24HJ256GP610A.h"
#include "timers.h"
#include "uart.h"

int main(int argc, char const* argv[])
{
    inicPulsadores();
    inicPuertos();

    // Inicializar Oscilador
    inicOscilator();

    // Inicializar UART
    inicUART();

    // Inicializar LCD
    inicLCD();
    inicT5();

    // Inicializar modulo CN
    inicCN();

    inicT7();

    // Configurar ADC y T3 para realizar muestreos
    inicADC();
    inicT3();

    // Copiar mensajes en la ventana LCD
    copiarFlashRam(Mens_LCD_1, 0);
    copiarFlashRam(Mens_LCD_2, 1);
    copiarFlashRam(Mens_LCD_3, 2);
    copiarFlashRam(Mens_LCD_4, 3);
    copiarFlashRam(Mens_LCD_5, 4);
    copiarFlashRam(Mens_LCD_6, 5);
    copiarFlashRam(Mens_LCD_7, 6);
    copiarFlashRam(Mens_LCD_8, 7);
    copiarFlashRam(Mens_LCD_9, 8);
    copiarFlashRam(Mens_LCD_10, 9);
    copiarFlashRam(Mens_LCD_11, 10);
    copiarFlashRam(Mens_LCD_12, 11);
    copiarFlashRam(Mens_LCD_13, 12);
    copiarFlashRam(Mens_LCD_14, 13);

    while (1)
    {
        cronometro();
        if (calcularMedias)
        {
            calcularMediaMuestras();
            calcularMedias = 0;
        }
    }

    return 0;
}
