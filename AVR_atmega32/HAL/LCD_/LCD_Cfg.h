/*
 * LCD_Cfg.h
 *
 * Created: 03/01/2024 08:57:18
 *  Author: Rania
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define Num_LCDs   2
#define NUMBER_OF_LCD_COLOUMNS       16
#define LCD_NUMBER_OF_CGRAM_BYTES    8

typedef enum{
	LCD_enumPORTA,
	LCD_enumPORTB,
	LCD_enumPORTC,
	LCD_enumPORTD
}
LCD_enumPort_t;


typedef struct
{
	usint8_t pin_RS;
	LCD_enumPort_t port_RS;
	usint8_t pin_RW;
	LCD_enumPort_t port_RW;
	usint8_t pin_EN;
	LCD_enumPort_t port_EN;
	usint8_t pin_D0;
	LCD_enumPort_t port_D0;
	usint8_t pin_D1;
	LCD_enumPort_t port_D1;
	usint8_t pin_D2;
	LCD_enumPort_t port_D2;
	usint8_t pin_D3;
	LCD_enumPort_t port_D3;
	usint8_t pin_D4;
	LCD_enumPort_t port_D4;
	usint8_t pin_D5;
	LCD_enumPort_t port_D5;
	usint8_t pin_D6;
	LCD_enumPort_t port_D6;
	usint8_t pin_D7;
	LCD_enumPort_t port_D7;

}_LCD_strState_t;


_LCD_strState_t LCD_Array[ Num_LCDs];
#endif /* LCD_CFG_H_ */