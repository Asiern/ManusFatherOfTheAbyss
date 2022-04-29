#ifndef _LCD_H
#define _LCD_H

// Definicion de la ventana LCD
#define LCD_ROWS 14 // Número de filas
#define LCD_COLS 16 // Número de columnas
extern unsigned char ventanaLCD[LCD_ROWS][LCD_COLS];

// Mensajes LCD
extern const unsigned char Mens_LCD_1[LCD_COLS], Mens_LCD_2[LCD_COLS], Mens_LCD_3[LCD_COLS], Mens_LCD_4[LCD_COLS],
    Mens_LCD_5[LCD_COLS], Mens_LCD_6[LCD_COLS], Mens_LCD_7[LCD_COLS], Mens_LCD_8[LCD_COLS], Mens_LCD_9[LCD_COLS],
    Mens_LCD_10[LCD_COLS], Mens_LCD_11[LCD_COLS], Mens_LCD_12[LCD_COLS], Mens_LCD_13[LCD_COLS], Mens_LCD_14[LCD_COLS];

#define LCD_CRONO 1
#define LCD_POT 3
#define LCD_TEMP 4

extern unsigned int currentDisplayLine;

void lcdCmd(char cmd);
void lcdData(char data);
void inicLCD();
void copiarFlashRam(const unsigned char* texto, unsigned int fila);

#endif