/*
 * KeyPad.h
 *
 * Created: 08/01/2024 18:52:52
 *  Author: Rania
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO_RegAdd.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\Bit_Math.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\std_types.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO.h"
#include "KeyPad_Cfg.h"
#include <util/delay.h>


#define NOT_Pressed  0xff
typedef enum
{
	KeyPad_enumNOK,
	KeyPad_enumInvalidConfig,
	KeyPad_NULL_Pointer, 
	KeyPad_enumOK
}KeyPad_enuErrorStatus;


/**
 *brief  : Function to initialize the KeyPad.
 *param  : Nothing
 *return : Nothing                                                                     
 */
void _KeyPad_init(void);


/**
 *brief  : Function to To Know which key is pressed.
 *param  : command itself
 *return : Error State                                                                     
 */

KeyPad_enuErrorStatus _KeyPad_GetPressedKey(usint8_t *Copy_pu8Key);





#endif /* KEYPAD_H_ */