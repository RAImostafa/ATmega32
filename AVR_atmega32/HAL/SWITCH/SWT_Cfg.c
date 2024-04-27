/*
 * SWT_Cfg.c
 *
 * Created: 07/02/2024 14:37:06
 *  Author: Rania
 */ 

#include "SWITCH.h"
#include "SWT_Cfg.h"

SWCH_strState_t switches [Num_Switches]={

	[0]= {.port = DIO_enumPort_A,
		.pin = DIO_enumPin1,
		.Switch_strState = PORT_strInput_PD //active high,
	},
	[1]= {.port = DIO_enumPort_D,
		.pin = DIO_enumPin2,
		.Switch_strState = PORT_strInput_PU,
	},
	
	[2]= {.port = DIO_enumPort_D,
		.pin = DIO_enumPin3,
		.Switch_strState= PORT_strInput_PU,
	}
	
};