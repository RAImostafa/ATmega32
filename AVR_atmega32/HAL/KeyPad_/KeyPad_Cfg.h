/*
 * KeyPad_Cfg.h
 *
 * Created: 08/01/2024 18:54:40
 *  Author: Rania
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define _MAX_KPROW               4
#define _MAX_KPCOL               4
#define _KeyPad_Num              1


typedef enum{
	KeyPad_enumPORTA,
	KeyPad_enumPORTB,
	KeyPad_enumPORTC,
	KeyPad_enumPORTD
}
_KeyPad_enumPort_t;


/*you can modify the following struct to align with your HW */
/* NUMs are for Columns numbers "OUTPUT" , Letters are for ROWs "input" */
typedef struct
{
	usint8_t pin_1;
	_KeyPad_enumPort_t port_1;

}_KeyPad_strState_t;

typedef struct{
	_KeyPad_strState_t ROWs[_MAX_KPROW]; //4
	_KeyPad_strState_t COLs[_MAX_KPCOL]; //4
	
}_KeyPad_str_t;

_KeyPad_str_t _KeyPad_Array[  _KeyPad_Num ];

#endif /* KEYPAD_CFG_H_ */