/*
 * LCD_Cfg.c
 *
 * Created: 03/01/2024 08:56:30
 *  Author: Rania
 */ 

#include "LCD.h"
#include "LCD_Cfg.h"


 _LCD_strState_t LCD_Array[Num_LCDs]=
{
	/* first LCD*/
	[0]=
	{
		.pin_RS = 0,    .port_RS = LCD_enumPORTD,
		.pin_RW = 1, 	.port_RW = LCD_enumPORTD,
		.pin_EN = 2, 	.port_EN = LCD_enumPORTD,		   
		.pin_D0 = 0, 	.port_D0 = LCD_enumPORTC,
		.pin_D1 = 1, 	.port_D1 = LCD_enumPORTC,
		.pin_D2 = 2, 	.port_D2 = LCD_enumPORTC,
		.pin_D3 = 3, 	.port_D3 = LCD_enumPORTC,
		.pin_D4 = 4, 	.port_D4 = LCD_enumPORTC,
		.pin_D5 = 5, 	.port_D5 = LCD_enumPORTC,
		.pin_D6 = 6, 	.port_D6 = LCD_enumPORTC,
		.pin_D7 = 7, 	.port_D7 = LCD_enumPORTC
	}
};
