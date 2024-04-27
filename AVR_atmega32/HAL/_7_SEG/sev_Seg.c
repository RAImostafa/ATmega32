/*
 * sev_Seg.c
 *
 * Created: 07/02/2024 13:59:07
 *  Author: Rania
 */ 

#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO_RegAdd.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\Bit_Math.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\std_types.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO.h"
#include "sev_Seg.h"


extern  _7_SE7_strState_t _7_SEG_Array  [Num_7_SEG];
_7_SE7_strState_t * temporary_seg;

void _7_SEG_init(void){
	for(usint8_t i =0 ; i < Num_7_SEG ; i++){
		switch( _7_SEG_Array[i].connectionType){
			case _7_SEG_Com_Anode: // needs 5v
			/* for loop to config every single pin in the 7 seg*/
			for(usint8_t i =0 ; i < 8 ; i++){
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_a,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_b,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_c,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_d,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_e,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_f,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_g,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_dp,DIO_enumOutput);

				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
			}//end of internal for
			break;
			case _7_SEG_Com_Cathode: // needs 0v
			/* for loop to config every single pin in the 7 seg*/
			for(usint8_t i =0 ; i < 8 ; i++){
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_a,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_b,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_c,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_d,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_e,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_f,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_g,DIO_enumOutput);
				DIO_enumSetPortConfig (_7_SEG_Array[i].port_dp,DIO_enumOutput);
				
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp,  DIO_enumLogicHigh);
			}// end of internal for
			break;
			default: break;
			
		}
	}
	
}

void _7_SEG_enuSetValue( usint8_t value)
{

	usint8_t value1 =value%10;
	for(usint8_t i =0 ; i < Num_7_SEG ; i++){ //2 num of 7 seg
		switch( _7_SEG_Array[i].connectionType)
		{
			case _7_SEG_Com_Cathode:
			switch(value1)
			{
				case 0:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 1:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 2:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 3:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 4:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 5:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 6:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 7:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 8:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 9:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				//default: break;
			}//end of switch for first seg
			break;
			
			case _7_SEG_Com_Anode:
			switch(value1)
			{
				case 0:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
				case 1:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
				case 2:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
				case 3:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
				case 4:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 5:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicLow);
				break;
				case 6:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
				case 7:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
				case 8:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
				case 9:
				DIO_enumSetPin( _7_SEG_Array[i].port_a, _7_SEG_Array[i].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_b, _7_SEG_Array[i].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_c, _7_SEG_Array[i].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_d, _7_SEG_Array[i].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_e, _7_SEG_Array[i].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[i].port_f, _7_SEG_Array[i].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_g, _7_SEG_Array[i].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[i].port_dp, _7_SEG_Array[i].pin_dp, DIO_enumLogicHigh);
				break;
			}//end of switch for sec seg
			break;
		}// switch
		value1=value/10;
	}//for

}

void _7_SEG_enuSetValue_(usint8_t Copy_u8SegNum , usint8_t value)
{

	/*making sure it's a valid number */
	if (Copy_u8SegNum < Num_7_SEG)
	{

		switch(  _7_SEG_Array[Copy_u8SegNum].connectionType)
		{
			case _7_SEG_Com_Cathode:
			
			switch(value)
			{
				case 0:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 1:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 2:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 3:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 4:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 5:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 6:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 7:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 8:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 9:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				//default: break;
			}//end of switch for first seg
			break;
			
			case _7_SEG_Com_Anode:
			switch(value)
			{
				case 0:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
				case 1:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
				case 2:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
				case 3:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
				case 4:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 5:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicLow);
				break;
				case 6:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
				case 7:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
				case 8:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
				case 9:
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_a, _7_SEG_Array[Copy_u8SegNum].pin_a,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_b, _7_SEG_Array[Copy_u8SegNum].pin_b,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_c, _7_SEG_Array[Copy_u8SegNum].pin_c,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_d, _7_SEG_Array[Copy_u8SegNum].pin_d,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_e, _7_SEG_Array[Copy_u8SegNum].pin_e,  DIO_enumLogicHigh);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_f, _7_SEG_Array[Copy_u8SegNum].pin_f,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_g, _7_SEG_Array[Copy_u8SegNum].pin_g,  DIO_enumLogicLow);
				DIO_enumSetPin( _7_SEG_Array[Copy_u8SegNum].port_dp, _7_SEG_Array[Copy_u8SegNum].pin_dp, DIO_enumLogicHigh);
				break;
			}//end of switch for sec seg
			break;
		}// switch
		
		
	}

	else { _7_SEG_init;}

}