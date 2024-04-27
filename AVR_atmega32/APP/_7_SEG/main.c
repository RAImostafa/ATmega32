/*
 * _7_SEG.c
 *
 * Created: 20/12/2023 22:55:22
 * Author : Rania
 */ 

#include <avr/io.h>
#include "_7_SEG.h"


int main(void)
{
	_7_SEG_init();
	//_7_SEG_enuSetValue(8);
	_7_SEG_enuSetValue_(1, 7);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

