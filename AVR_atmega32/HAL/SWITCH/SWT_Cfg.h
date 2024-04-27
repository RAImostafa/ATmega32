/*
 * SWT_Cfg.h
 *
 * Created: 07/02/2024 14:37:29
 *  Author: Rania
 */ 


#ifndef SWT_CFG_H_
#define SWT_CFG_H_


#define Num_Switches      3


typedef enum {
	
	/* The ports Type of the AVR Atmega32*/
	DIO_enumPort_A,
	DIO_enumPort_B,
	DIO_enumPort_C,
	DIO_enumPort_D
	
}DIO_enumPortst;


typedef enum {

	PORT_strInput_PU,
	PORT_strInput_PD,
	PORT_strOutput_High_Active,
	PORT_strOutput_LOW_Active,
	PORT_strOutput_OFF,
	PORT_strOutput_ON
	
}Port_strState_t;

typedef enum
{
	/*Pins Type */
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
	
}DIO_enumPins_t;



typedef struct{
	DIO_enumPortst port;
	DIO_enumPins_t pin;
	Port_strState_t Switch_strState;
	
}SWCH_strState_t;




#endif /* SWT_CFG_H_ */