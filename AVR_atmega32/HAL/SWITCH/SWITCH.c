/*
 * SWITCH.c
 *
 * Created: 17/12/2023 10:59:46
 *  Author: Rania
 */ 



#include "SWITCH.h"



extern SWCH_strState_t switches [Num_Switches];
 PortCfg_t currentPort [Num_Switches ];
usint8_t counter2 = 0;

void Switch_Init(void){
	
  for(usint8_t i =0 ; i<Num_Switches ;i++){
		currentPort [i].port =   switches[i].port;
		currentPort [i].pin  =    switches[i].pin;
		currentPort [i].State =  switches[i].Switch_strState;
		counter2++;				
	}
	PORT_setCfg(&currentPort , counter2);
}



void PORT_setCfg(PortCfg_t * port_state ,  usint8_t size){
	
	for(unsigned i =0 ; i <size ; i++){
		switch(port_state[i].State ){
			
			case PORT_strOutput_ON:
			switch(port_state[i].Config)
			{
				case PORT_strOutput_High_Active:  /* output ON , High active */
				switch(port_state[i].port)
				{
					case DIO_enumPort_A:
					SET_BIT(DDRA , port_state[i].pin);
					SET_BIT(PORTA ,port_state[i].pin);
					break;
					case DIO_enumPort_B:
					SET_BIT(DDRB , port_state[i].pin);
					SET_BIT(PORTB ,port_state[i].pin);
					break;
					case DIO_enumPort_C:
					SET_BIT(DDRC , port_state[i].pin);
					SET_BIT(PORTC ,port_state[i].pin);
					break;
					case DIO_enumPort_D:
					SET_BIT(DDRD , port_state[i].pin);
					SET_BIT(PORTD ,port_state[i].pin);
					break;
				}
				break;
				case PORT_strOutput_LOW_Active:  /* output ON , LOW active */
				switch(port_state[i].port)
				{
					case DIO_enumPort_A:
					SET_BIT(DDRA , port_state[i].pin);
					CLR_BIT(PORTA ,port_state[i].pin);
					break;
					case DIO_enumPort_B:
					SET_BIT(DDRB , port_state[i].pin);
					CLR_BIT(PORTB ,port_state[i].pin);
					break;
					case DIO_enumPort_C:
					SET_BIT(DDRC , port_state[i].pin);
					CLR_BIT(PORTC ,port_state[i].pin);
					break;
					case DIO_enumPort_D:
					SET_BIT(DDRD , port_state[i].pin);
					CLR_BIT(PORTD ,port_state[i].pin);
					break;
				}
				break;
				
			}
			break;
			case PORT_strOutput_OFF:
			switch(port_state[i].Config)
			{
				case PORT_strOutput_High_Active: /* output OFF , HIGH active */
				switch(port_state[i].port){
					case DIO_enumPort_A:
					SET_BIT(DDRA , port_state[i].pin);
					CLR_BIT(PORTA ,port_state[i].pin);
					break;
					case DIO_enumPort_B:
					SET_BIT(DDRB , port_state[i].pin);
					CLR_BIT(PORTB ,port_state[i].pin);
					break;
					case DIO_enumPort_C:
					SET_BIT(DDRC , port_state[i].pin);
					CLR_BIT(PORTC ,port_state[i].pin);
					break;
					case DIO_enumPort_D:
					SET_BIT(DDRD , port_state[i].pin);
					CLR_BIT(PORTD ,port_state[i].pin);
					break;
					default: break;
				}
				break;
				case PORT_strOutput_LOW_Active:  /* output OFF , LOW active */
				switch(port_state[i].port){
					case DIO_enumPort_A:
					SET_BIT(DDRA , port_state[i].pin);
					SET_BIT(PORTA ,port_state[i].pin);
					break;
					case DIO_enumPort_B:
					SET_BIT(DDRB , port_state[i].pin);
					SET_BIT(PORTB ,port_state[i].pin);
					break;
					case DIO_enumPort_C:
					SET_BIT(DDRC , port_state[i].pin);
					SET_BIT(PORTC ,port_state[i].pin);
					break;
					case DIO_enumPort_D:
					SET_BIT(DDRD , port_state[i].pin);
					SET_BIT(PORTD ,port_state[i].pin);
					break;
					default: break;
				}
				break;
				default: break;
				
			}
			break;
			
			case PORT_strInput_PD: // INPUT pin PULL DOWN
			switch(port_state[i].port){
				case DIO_enumPort_A:
				CLR_BIT(DDRA , port_state[i].pin);
				CLR_BIT(PORTA ,port_state[i].pin);
				break;
				case DIO_enumPort_B:
				CLR_BIT(DDRB , port_state[i].pin);
				CLR_BIT(PORTB ,port_state[i].pin);
				break;
				case DIO_enumPort_C:
				CLR_BIT(DDRC , port_state[i].pin);
				CLR_BIT(PORTC ,port_state[i].pin);
				break;
				case DIO_enumPort_D:
				CLR_BIT(DDRD , port_state[i].pin);
				CLR_BIT(PORTD ,port_state[i].pin);
				break;
			}
			break; // BREAK FOR INPUT_PD
			
			case PORT_strInput_PU:
			switch(port_state[i].port){
				case DIO_enumPort_A:
				CLR_BIT(DDRA , port_state[i].pin);
				SET_BIT(PORTA ,port_state[i].pin);
				break;
				case DIO_enumPort_B:
				CLR_BIT(DDRB , port_state[i].pin);
				SET_BIT(PORTB ,port_state[i].pin);
				break;
				case DIO_enumPort_C:
				CLR_BIT(DDRC , port_state[i].pin);
				SET_BIT(PORTC ,port_state[i].pin);
				break;
				case DIO_enumPort_D:
				CLR_BIT(DDRD , port_state[i].pin);
				SET_BIT(PORTD ,port_state[i].pin);
				break;
			}
			break;
			default: break;
			
		} //state
	}
	
	
}