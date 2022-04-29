#include "adc.h"
#include "defines.h"
#include "lcd.h"
#include "p24HJ256GP610A.h"
#include "utils.h"

#define NUM_MUESTRAS 8
#define NUM_PUERTOS 4

unsigned int listaPuertos[NUM_PUERTOS] = {4, 5, 8, 9};
unsigned int indicePuerto = 0;

// Variables
unsigned int muestrasActuales = 0;
unsigned int calcularMedias = 0;
unsigned int tempAcumulada = 0;
unsigned int potenAcumulado = 0;
unsigned int jpHoriAcumulado = 0;
unsigned int jpVertAcumulado = 0;

void inicADC()
{
    muestrasActuales = 0;
    calcularMedias = 0;
    // Inicializacion registro control AD1CON1
    AD1CON1 = 0; // todos los campos a 0

    // Salida de 12 bits o 10 bits
    // AD1CON1bits.AD12B = 0;

    // Comienzo digitalizacion automatico
    // 111=Auto-convert / 010=TMR3 ADC1 y TMR5 ADC2 / 001=INT0 / 000= SAMP
    AD1CON1bits.SSRC = 7;

    // Muestreo simultaneo o secuencial
    // AD1CON1bits.SIMSAM = 0;

    // Comienzo muestreo automático o por programa (SAMP=1)
    // AD1CON1bits.ASAM = 0;

    // Inicializacion registro control AD1CON2
    AD1CON2 = 0; // todos los campos a 0

    // Inicializacion registro control AD1CON3
    AD1CON3 = 0; // todos los campos a 0
    // Reloj con el que funciona el ADC:  0= reloj CPU; 1= RC erlojua
    // AD1CON3bits.ADRC = 0;  //
    AD1CON3bits.SAMC = 31; // Tiempo muestreo = numero de Tad
    AD1CON3bits.ADCS = 1;  // Relacion entre TAD y Tcy TAD = Tcy(ADCS+1)

    // Inicializacion registro control AD1CON4
    AD1CON4 = 0;

    // Inicializacion registro AD1CHS123
    AD1CHS123 = 0; // seleccion del canal 1,2 eta 3

    // Inicializacion registro AD1CHS0
    AD1CHS0 = 0;
    AD1CHS0bits.CH0SA = 5; // elige la entrada analogica conectada

    // AD1CHS0bits.CH0SB = 0;

    // Inicializacion registros AD1CSS
    // Si escaneo secuencial 1, si no 0

    AD1CSSH = 0; // 16-31
    AD1CSSL = 0; // 0-15

    // Inicializacion registros AD1PCFG. Inicialmente todas AN como digitales
    AD1PCFGH = 0xFFFF; // 1= digital / 0= Analog
    AD1PCFGL = 0xFFFF; // Puerto B, todos digitales
    // Inicializar como analogicas solo las que vayamos a usar
    AD1PCFGLbits.PCFG4 = 0; // potenciometro
    AD1PCFGLbits.PCFG5 = 0; // sensor temperatura
    AD1PCFGLbits.PCFG8 = 0;
    AD1PCFGLbits.PCFG9 = 0;

    // Bits y campos relacionados con las interrupciones
    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = 1;
    // IPC3bits.AD1IP=xx;

    // AD1CON
    AD1CON1bits.ADON = 1; // Habilitar el modulo ADC
}

// TODO convertir valores a decimal
void calcularMediaMuestras()
{
    // Temperatura
    int Temp = tempAcumulada / 8;
    tempAcumulada = 0;
    ventanaLCD[LCD_TEMP][13] = tablaCarac[(Temp & 0x0F00) >> 8];
    ventanaLCD[LCD_TEMP][14] = tablaCarac[(Temp & 0x00F0) >> 4];
    ventanaLCD[LCD_TEMP][15] = tablaCarac[(Temp & 0x000F)];

    // Potenciometro
    int Pot = potenAcumulado / 8;
    potenAcumulado = 0;
    ventanaLCD[LCD_POT][13] = tablaCarac[(Pot & 0x0F00) >> 8];
    ventanaLCD[LCD_POT][14] = tablaCarac[(Pot & 0x00F0) >> 4];
    ventanaLCD[LCD_POT][15] = tablaCarac[(Pot & 0x000F)];

    // TODO Joystick Pequeño Horizontal
    Pot = jpHoriAcumulado / 8;
    jpHoriAcumulado = 0;
    ventanaLCD[LCD_JPHORI][13] = tablaCarac[(Pot & 0x0F00) >> 8];
    ventanaLCD[LCD_JPHORI][14] = tablaCarac[(Pot & 0x00F0) >> 4];
    ventanaLCD[LCD_JPHORI][15] = tablaCarac[(Pot & 0x000F)];
}

void _ISR_NO_PSV _ADC1Interrupt()
{
    unsigned int ADCValue = ADC1BUF0;
    switch (AD1CHS0bits.CH0SA)
    {
    case 4: // Guardar valor del sensor del temperatura
        tempAcumulada += ADCValue;
        break;
    case 5: // Guardar valor del sensor de potenciometro
        potenAcumulado += ADCValue;
        break;
    case 8: // Guardar valor del joystick pequeño VERT
        jpVertAcumulado += ADCValue;
        break;
    case 9: // Guardar valor del joystick pequeño HORI
        jpHoriAcumulado += ADCValue;
        break;
    }
    // Cambiar CHOSA para alternar lecturas entre Potenciometro y Sensor de temperatura
    indicePuerto = mod(indicePuerto + 1, NUM_PUERTOS);
    AD1CHS0bits.CH0SA = listaPuertos[indicePuerto];
    muestrasActuales++; // Aumentar valor del contador de muestras
    if (muestrasActuales == NUM_PUERTOS * NUM_MUESTRAS)
    {
        calcularMedias = 1; // Habilitar flag para calcular medias
        muestrasActuales = 0;
    }
    IFS0bits.AD1IF = 0;   // Apagar flag de interrupcion
    AD1CON1bits.SAMP = 0; // Apagar flag de sampleo
}