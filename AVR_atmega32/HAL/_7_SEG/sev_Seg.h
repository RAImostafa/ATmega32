/*
 * sev_Seg.h
 *
 * Created: 07/02/2024 13:59:58
 *  Author: Rania
 */ 


#ifndef SEV_SEG_H_
#define SEV_SEG_H_


#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO_RegAdd.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\Bit_Math.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\std_types.h"

#include "sev_Seg_Cfg.h"




typedef enum {
	_7_SEG_Com_Anode,
	_7_SEG_Com_Cathode
}SEG_enuStates;

typedef struct
{
	usint8_t pin_a;
	usint8_t port_a;
	usint8_t pin_b;
	usint8_t port_b;
	usint8_t pin_c;
	usint8_t port_c;
	usint8_t pin_d;
	usint8_t port_d;
	usint8_t pin_e;
	usint8_t port_e;
	usint8_t pin_f;
	usint8_t port_f;
	usint8_t pin_g;
	usint8_t port_g;
	usint8_t pin_dp;
	usint8_t port_dp;
	SEG_enuStates connectionType;

}_7_SE7_strState_t;


_7_SE7_strState_t _7_SEG_Array  [Num_7_SEG];


/*
Initializes the Seven segments configured in Port_Cfg.c
Parameters: Void                                                                                                                                                                                                                                                                                                                                                                  
RETURN: Void
*/                                                                                                                                  
void _7_SEG_init(void);

/*
Initializes the Seven segments with the value entered by the user
Parameters: integer
RETURN:     Void
*/
void _7_SEG_enuSetValue( usint8_t value);


/*
Initializes pick the seven segment and assign its value
Parameters: -seven segment name
            -value(integer)
RETURN: Void
*/
void _7_SEG_enuSetValue_(usint8_t Copy_u8SegNum , usint8_t value);




#endif /* SEV_SEG_H_ */