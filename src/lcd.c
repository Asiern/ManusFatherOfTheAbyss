#include "lcd.h"
#include "defines.h"
#include "p24HJ256GP610A.h"
#include "timers.h"

// Ventana LCD
unsigned char ventanaLCD[LCD_ROWS][LCD_COLS];
unsigned int currentDisplayLine = 0;

// Mensajes LCD
const unsigned char Mens_LCD_1[] = {"---- MANUS -----"};
const unsigned char Mens_LCD_2[] = {"Crono: --:--,-  "};
const unsigned char Mens_LCD_3[] = {"----------------"};
const unsigned char Mens_LCD_4[] = {"Potenciomet  ---"};
const unsigned char Mens_LCD_5[] = {"Temperatura  ---"};
const unsigned char Mens_LCD_6[] = {"JP X:____ Y:____"};
const unsigned char Mens_LCD_7[] = {"JG X:____ Y:____"};
const unsigned char Mens_LCD_8[] = {"Palanca ____    "};
const unsigned char Mens_LCD_9[] = {"9---------------"};
const unsigned char Mens_LCD_10[] = {"10--------------"};
const unsigned char Mens_LCD_11[] = {"11--------------"};
const unsigned char Mens_LCD_12[] = {"12--------------"};
const unsigned char Mens_LCD_13[] = {"13--------------"};
const unsigned char Mens_LCD_14[] = {"14--------------"};

void copiarFlashRam(const unsigned char* texto, unsigned int fila)
{
    unsigned int j;
    for (j = 0; j < LCD_COLS; j++)
        ventanaLCD[fila][j] = texto[j];
}

void lcdCmd(char cmd) // subroutine for lcd commands
{
    RW = 0;         // RW=0, para escribir
    RS = 0;         // RS=0, se va a escribir un comando
    DATA &= 0xFF00; // pines RD0-RD7 (dato que se envía): poner a 0
    DATA |= cmd;    // copiar a esos pines el parametro cmd
    E = 1;          // E=1. Debe permanecer activado al menos 230 ns.
    // Completad
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    E = 0;  // desactivar E
    RW = 1; // desactivar escritura
}

void lcdData(char data)
{
    RW = 0;         // RW=0, para escribir
    RS = 1;         // RS=1, se va a escribir un caracter
    DATA &= 0xFF00; // pines RD0-RD7 (dato que se envía): poner a 0
    DATA |= data;   // copiar a esos pines el parametro data
    E = 1;          // E=1. Debe permanecer activado al menos 230 ns
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    E = 0;  // desactivar E
    RS = 0; // desactivar RS
    RW = 1; // desactivar escritura
}

void inicLCD()
{
    // 15mS delay after Vdd reaches nnVdc before proceeding
    // with LCD initialization
    // not always required and is based on system Vdd rise rate
    Delay_ms(15); // 15 ms delay

    /* set initial states for the data and control pins */
    DATA &= 0xFF00;
    RW = 0; // R/W state set low
    RS = 0; // RS state set low
    E = 0;  // E state set low

    /* set data and control pins to outputs */
    TRISDATA &= 0xFF00;
    RW_TRIS = 0; // RW pin set as output
    RS_TRIS = 0; // RS pin set as output
    E_TRIS = 0;  // E pin set as output

    /* LCD initialization sequence */
    lcdCmd(0x38); // function set (3 veces)
    Delay_ms(5);  // 5 ms delay
    lcdCmd(0x38);
    Delay_us(100); // 100 us delay
    lcdCmd(0x38);
    Delay_us(40); // 40ms delay (mirar tabla en los apuntes)
    lcdCmd(0x38);
    Delay_us(40); // 40ms delay (mirar tabla en los apuntes)
    lcdCmd(0x0C); // Display on/off control, cursor blink off (0x0C)
    Delay_us(40); // 40ms delay (mirar tabla en los apuntes)
    lcdCmd(0x06); // Entry mode set (0x06)
    Delay_us(40); // 40ms delay (mirar tabla en los apuntes)
}