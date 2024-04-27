/*
 * SWITCH.h
 *
 * Created: 17/12/2023 11:00:04
 *  Author: Rania
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "SWT_Cfg.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO_RegAdd.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\Bit_Math.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\std_types.h"


void Switch_Init(void);

SWCH_strState_t switches [Num_Switches];
typedef struct {
	DIO_enumPortst port;
	DIO_enumPins_t pin;
	Port_strState_t State;
	Port_strState_t Config;
	
}PortCfg_t;


void PORT_setCfg(PortCfg_t * port_state ,  usint8_t size);


#endif /* SWITCH_H_ */