/*
 * LCD.h
 *
 * Created: 03/01/2024 08:56:59
 *  Author: Rania
 */ 


#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO_RegAdd.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\Bit_Math.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\std_types.h"
#include <util/delay.h>
#include "LCD_Cfg.h"

#define LCD_CLEAR_DISPLAY       0x01 
#define LCD_SET_DDRAM_ADDRESS   0x80   /* accessing DDRAM 0b1xxxxxxx*/
#define LCD_SET_CGRAM_ADDRESS   0x40
#define CLCD_SHIFT_DISPLAY_RIGH 0x1c
#define CLCD_SHIFT_DISPLAY_LEFT	0x18


typedef enum
{
	LCD_enumNOK,
	LCD_enumInvalidConfig,
	LCD_enumOK
}LCD_enuErrorStatus;




/**
 *brief  : Function to initialize the LCD.
 *param  : Nothing
 *return : Nothing                                                                     
 */
void LCD_init(void);


/**
 *brief  : Function to write commands on the LCD.
 *param  : command itself
 *return : Error State                                                                     
 */

LCD_enuErrorStatus LCD_WriteCommand(usint8_t Copy_u8Command);


/**
 *brief  : Function to write data on the LCD.
 *param  : the data itself
 *return : Error State                                                                     
 */

LCD_enuErrorStatus LCD_WriteData(usint8_t Copy_u8Data);


/**
 *brief  : Function to print on specific location on the LCD.
 *param  : the position X ,Y .
 *return : Error State                                                                     
 */
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(usint8_t Copy_u8X, usint8_t Copy_u8Y);


/**
 *brief  : Function to Number display it on the LCD.
 *param  : Number to be printed (must be less than 4 digits).
 *return : Error State                                                                     
 */
LCD_enuErrorStatus LCD_enuWriteNumber(usint8_t Copy_u8Number);


/**
 *brief  : Function to display an entire string on the LCD.
 *param  : String to be printed.
 *return : Error State                                                                     
 */
LCD_enuErrorStatus LCD_enuWriteString(char* Copy_pchPattern);


/**
 *brief  : Function to print a special character created by the user on specific position.
 *param  : the pattern , the block number where it will get stored, the position X ,Y.
 *return : Error State                                                                     
*/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(usint8_t* Copy_pu8Pattern, usint8_t Copy_u8CGRAMBlockNumber, usint8_t Copy_u8X, usint8_t Copy_u8Y);