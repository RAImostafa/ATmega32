/*
 * lab1_led.c
 *
 * Created: 25/11/2023 13:17:18
 * Author : Rania
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "DIO.h"


void custom_delay_ms(uint16_t ms) {
	uint32_t cycles = ((uint32_t)ms * F_CPU) / 4000;
	for (uint32_t i = 0; i < cycles; ++i) {
		asm volatile("  ");
	}
}
int main(void)
{
usint8_t count =0;

DIO_enumSetPortConfig (DIO_enumPortB,DIO_enumInputInternalPU); //DDRB =0X00 //PORTB=0XFF;
DIO_enumSetPortConfig (DIO_enumPortA,DIO_enumOutput); //DDRA=0XFF
//DIO_enumSetPort(DIO_enumPortA,DIO_enumLogicLow); //PORTA=0X00;


	/* Replace with your application code */
	while (1)
	{
		if(!READ_BIT(PINB,0)){
			count++;
			PORTA=count;
			custom_delay_ms(100);

		}
	
	}
	return 0;
}
