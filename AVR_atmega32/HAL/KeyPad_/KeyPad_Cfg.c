/*
 * KeyPad_Cfg.c
 *
 * Created: 08/01/2024 18:54:56
 *  Author: Rania
 */ 

#include "KeyPad.h"
#include "KeyPad_Cfg.h"

usint8_t _KeyPad_KEYS[_MAX_KPROW][_MAX_KPCOL]={
	                            {'7','8','9','/'},
	                            {'4','5','6','*'},
								{'1','2','3','-'},
								{'A','0','=','+'}};
									
_KeyPad_str_t _KeyPad_Array[_KeyPad_Num] = {
	[0] = {
		.COLs = {
			[0] = {.pin_1 = 3, .port_1 = KeyPad_enumPORTA},
			[1] = {.pin_1 = 2, .port_1 = KeyPad_enumPORTA},
			[2] = {.pin_1 = 1, .port_1 = KeyPad_enumPORTA},
			[3] = {.pin_1 = 0, .port_1 = KeyPad_enumPORTA}
		},
		.ROWs = {
			[0] = {.pin_1 = 0, .port_1 = KeyPad_enumPORTB},
			[1] = {.pin_1 = 1, .port_1 = KeyPad_enumPORTB},
			[2] = {.pin_1 = 2, .port_1 = KeyPad_enumPORTB},
			[3] = {.pin_1 = 3, .port_1 = KeyPad_enumPORTB}
		}
	},
};