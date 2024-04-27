/*
 * KeyPad.c
 *
 * Created: 08/01/2024 18:52:36
 *  Author: Rania
 */ 

#include "KeyPad.h"


extern _KeyPad_str_t _KeyPad_Array[  _KeyPad_Num ];
extern usint8_t _KeyPad_KEYS[_MAX_KPROW][_MAX_KPCOL];


void _KeyPad_init(void)
{
	
	for(usint8_t i =0 ; i < _KeyPad_Num ; i++){
		
	for(usint8_t R =0 ; R < _MAX_KPROW ; R++){
			 DIO_enumSetPinConfig(_KeyPad_Array[i].ROWs[R].port_1,_KeyPad_Array[i].ROWs[R].pin_1, DIO_enumInputInternalPU);
			
			 }
	for(usint8_t C =0 ; C < _MAX_KPCOL ; C++){
			 DIO_enumSetPinConfig(_KeyPad_Array[i].COLs[C].port_1,_KeyPad_Array[i].COLs[C].pin_1, DIO_enumOutput);
			 DIO_enumSetPin(_KeyPad_Array[i].COLs[C].port_1,_KeyPad_Array[i].COLs[C].pin_1,DIO_enumLogicHigh);
	}
	
	
}
}



KeyPad_enuErrorStatus KeyPad_GetPressedKey(usint8_t *Copy_pu8Key)
{
	KeyPad_enuErrorStatus loc_enumReturnStatus = KeyPad_enumNOK;
	
	usint8_t row;/* to scan rows */
	usint8_t col; /* to scan cols  */
	//usint8_t Loc_u8IsPressed=DIO_enumLogicHigh ;  
	//*Copy_pu8Key =NOT_Pressed; 
	usint8_t Loc_u8IsPressed= NOT_Pressed;                    
	
	if(Copy_pu8Key == NULL){
	loc_enumReturnStatus = KeyPad_NULL_Pointer;}
	
	else {

		for (col = 0; col < _MAX_KPCOL; col++)
		{
			DIO_enumSetPin(_KeyPad_Array[0].COLs[col].port_1,_KeyPad_Array[0].COLs[col].pin_1,DIO_enumLogicLow); /*set one pin low and scan rows */
			for(row = 0 ; row <_MAX_KPROW ;row++)
			{
				/* scanning rows and read state of each pin */
				DIO_enumReadState(_KeyPad_Array[0].ROWs[row].port_1,_KeyPad_Array[0].ROWs[row].pin_1,&Loc_u8IsPressed);
				_delay_ms(25);
				if (Loc_u8IsPressed == DIO_enumLogicLow) /* 0x00 != 0xff*/
				{
					
					/* to prevent redundancy of sent data */
					while(!Loc_u8IsPressed)
					{
						DIO_enumReadState(_KeyPad_Array[0].ROWs[row].port_1,_KeyPad_Array[0].ROWs[row].pin_1,&Loc_u8IsPressed);
					}
					/* make sure button is released */
					if (Loc_u8IsPressed == DIO_enumLogicHigh) {
						*Copy_pu8Key=_KeyPad_KEYS[row][col];
						//break;
						
					}
					//else{ /* MISRA rules */}
				}
				
			}

			/*Returns that pin to it's default high */
			DIO_enumSetPin(_KeyPad_Array[0].COLs[col].port_1,_KeyPad_Array[0].COLs[col].pin_1,DIO_enumLogicHigh);
		}
	}
	return 	loc_enumReturnStatus ;
}
