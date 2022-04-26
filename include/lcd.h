#ifndef _LCD_H
#define _LCD_H

// Definicion de la ventana LCD
#define LCD_ROWS 2  // Número de filas
#define LCD_COLS 16 // Número de columnas
extern unsigned char ventanaLCD[LCD_ROWS][LCD_COLS];

void lcdCmd(char cmd);
void lcdData(char data);
void inicLCD();
void copiar_FLASH_RAM(const unsigned char* texto, unsigned int fila);

#endif