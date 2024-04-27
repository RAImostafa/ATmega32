/*
 * LED.c
 *
 * Created: 11/12/2023 01:30:39
 *  Author: Rania
 */ 

#include "Port_Cfg.h"
#include "Port.h"
#include "LED.h"
usint8_t i=0;

extern LED_strState_t LEDS [Num_Leds];
PortCfg_t currentPort [Num_Leds ];
usint8_t counter = 0;

void Led_Init(void){
	for(i =0 ; i<Num_Leds  ;i++){
		currentPort[i].port = LEDS[i].port;
		currentPort[i].pin = LEDS[i].pin;
		currentPort[i].State = LEDS[i].LED_strStatus;
		currentPort[i].Config = LEDS[i].LED_strActive;
		counter++;
	}
	PORT_setCfg(&currentPort , counter);
}