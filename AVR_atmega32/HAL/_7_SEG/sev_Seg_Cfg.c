/*
 * sev_Seg_Cfg.c
 *
 * Created: 07/02/2024 13:59:35
 *  Author: Rania
 */ 


#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO.h"
#include "sev_Seg.h"
#include "sev_Seg_Cfg.h"

_7_SE7_strState_t _7_SEG_Array  [Num_7_SEG]={

	/*[0]= { .pin_a  = DIO_enumPin0,
		.port_a = DIO_enumPortB,
		.pin_b  = DIO_enumPin1,
		.port_b = DIO_enumPortB,
		.pin_c  = DIO_enumPin2,
		.port_c = DIO_enumPortB,
		.pin_d  = DIO_enumPin3,
		.port_d = DIO_enumPortB,
		.pin_e  = DIO_enumPin4,
		.port_e = DIO_enumPortB,
		.pin_f  = DIO_enumPin5,
		.port_f = DIO_enumPortB,
		.pin_g  = DIO_enumPin6,
		.port_g = DIO_enumPortB,
		.pin_dp = DIO_enumPin7,
		.port_dp =DIO_enumPortB,
		.connectionType = _7_SEG_Com_Anode
		
	},
	*/
	[0]={
		.pin_a  = DIO_enumPin0,
		.port_a = DIO_enumPortC,
		.pin_b  = DIO_enumPin1,
		.port_b = DIO_enumPortC,
		.pin_c  = DIO_enumPin2,
		.port_c = DIO_enumPortC,
		.pin_d  = DIO_enumPin3,
		.port_d = DIO_enumPortC,
		.pin_e  = DIO_enumPin4,
		.port_e = DIO_enumPortC,
		.pin_f  = DIO_enumPin5,
		.port_f = DIO_enumPortC,
		.pin_g  = DIO_enumPin6,
		.port_g = DIO_enumPortC,
		.pin_dp = DIO_enumPin7,
		.port_dp =DIO_enumPortC,
		.connectionType = _7_SEG_Com_Cathode
		
	},

	
	
};