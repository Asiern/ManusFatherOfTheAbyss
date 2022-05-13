/**
 * @file main.c
 * @author Joseba Uranga & Asier Nuñez
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "adc.h"
#include "cn.h"
#include "gpio.h"
#include "lcd.h"
#include "ocpwm.h"
#include "oscilator.h"
#include "p24HJ256GP610A.h"
#include "timers.h"
#include "uart.h"
#include "utils.h"

unsigned int end = 0;

int main(int argc, char const* argv[])
{
    // Inicializar pines
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

    // Inicializar PWM
    inicDuty();
    inicPWM();
    inicT2();

    inicT4();

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

    while (!end)
    {
        cronometro();
        if (calcularMedias)
        {
            calcularMediaMuestras();
            calcularMedias = 0;
        }
        if (controlServos == CONTROL_ANALOGICO)
        {
            duty1objetivo = conversionAnalogicoAServo(valoresFinalesJPeq.x);
            duty2objetivo = conversionAnalogicoAServo(valoresFinalesJPeq.y);
            duty3objetivo = conversionAnalogicoAServo(valoresFinalesJGrande.x);
            duty4objetivo = conversionAnalogicoAServo(valoresFinalesJGrande.y);
            duty5objetivo = conversionAnalogicoAServo(palancaFinal);
        }
        conversionDeci(&(ventanaLCD[LCD_S1_S2][3]), duty1, 4);
        conversionDeci(&(ventanaLCD[LCD_S1_S2][11]), duty2, 4);
        conversionDeci(&(ventanaLCD[LCD_S3_S4][3]), duty3, 4);
        conversionDeci(&(ventanaLCD[LCD_S3_S4][11]), duty4, 4);
        conversionDeci(&(ventanaLCD[LCD_S5][3]), duty5, 4);
    }

    moverPosicionSegura();
    while (abs(duty1 - duty1objetivo) > DUTY_AUGMENT || abs(duty2 - duty2objetivo) > DUTY_AUGMENT ||
           abs(duty3 - duty3objetivo) > DUTY_AUGMENT || abs(duty4 - duty4objetivo) > DUTY_AUGMENT ||
           abs(duty5 - duty5objetivo) > DUTY_AUGMENT)
    {
        conversionDeci(&(ventanaLCD[LCD_S1_S2][3]), duty1, 4);
        conversionDeci(&(ventanaLCD[LCD_S1_S2][11]), duty2, 4);
        conversionDeci(&(ventanaLCD[LCD_S3_S4][3]), duty3, 4);
        conversionDeci(&(ventanaLCD[LCD_S3_S4][11]), duty4, 4);
        conversionDeci(&(ventanaLCD[LCD_S5][3]), duty5, 4);
    }

    return 0;
}
