/*
 * ETRI_.c
 *
 * Created: 29/01/2024 13:56:26
 * Author : Rania
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include "ETRI_.h"
usint8_t count =0;
void Interrupt_INC_BUTTON(void);
void Interrupt_DEC_BUTTON(void);


int main(void)
{
	
		    EXTI_voidCallBack(Interrupt_INC_BUTTON , 0);
		    EXTI_voidCallBack(Interrupt_DEC_BUTTON , 1);
	EXTI_enumInit();
	_7_SEG_init();
	

	Switch_Init();
	
		
   

    /* Replace with your application code */
    while (1) 
    {
		
		_7_SEG_enuSetValue(count);
		_delay_ms(1000);
		
		
    
    }
}

void Interrupt_INC_BUTTON(void){
			
			if (count > 9) {
				count = 0;
			}
			else{count++;}
				
}

void Interrupt_DEC_BUTTON(void){
	
	if(count < 0){
		count =9;
	}
	else {count -- ;}
	
}