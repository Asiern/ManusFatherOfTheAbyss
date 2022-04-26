#include "lcd.h"
#include "oscilator.h"
#include "p24HJ256GP610A.h"
#include "timers.h"
#include "uart.h"

int main(int argc, char const* argv[])
{
    // TODO mover mensajes a otro sitio
    const unsigned char Mens_LCD_1[] = {"- DSE 2021-22 --"};
    const unsigned char Mens_LCD_2[] = {"--- Pulsa S3  --"};
    // Inicializar Oscilador
    inicOscilator();

    // Inicializar UART
    inicUART();

    // Inicializar LCD
    inicLCD();
    inicT5();

    copiar_FLASH_RAM(Mens_LCD_1, 0);
    copiar_FLASH_RAM(Mens_LCD_2, 1);

    while (1)
        ;

    return 0;
}
