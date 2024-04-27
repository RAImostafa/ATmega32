/*
 * ETRI_.c
 *
 * Created: 29/01/2024 13:56:49
 *  Author: Rania
 */ 


#include "ETRI_.h"

void (*EXTI_CallBack[EXTI_INT_PINS_NUM])(void) = {NULL};
extern EXTI_strCfg_t EXTI_INT_ARRAY [ EXTI_INT_PINS_NUM];


EXTI_enumError_t EXTI_enumInit (void)
{
	
	EXTI_enumError_t Ret_enuErrorStatus = EXTI_enumNok;
	
	
	for(usint8_t i =0 ;i <  EXTI_INT_PINS_NUM ; i++){
		switch(EXTI_INT_ARRAY[i].enumName)
		{
			case EXTI_enumEXTI0:
				switch (EXTI_INT_ARRAY[i].enumConfig){
					case EXTI_enumLowLevel:
					CLR_BIT(MCUCR_REG,0);
					CLR_BIT(MCUCR_REG,1);
					break;
					case EXTI_enumOnChange:
					SET_BIT(MCUCR_REG,0);
					CLR_BIT(MCUCR_REG,1);
					break;
					case EXTI_enumFallEdge:
					CLR_BIT(MCUCR_REG,0);
					SET_BIT(MCUCR_REG,1);
					break;
					case EXTI_enumRiseEdge:
					SET_BIT(MCUCR_REG,0);
					SET_BIT(MCUCR_REG,1);
					break;
				}
			   switch(EXTI_INT_ARRAY[i].enumState){
					case EXTI_enumEnabled:
					SET_BIT(GICR_REG,6);
					SET_BIT(SREG,7);
					break;
				    case EXTI_enumDisabled:
				    CLR_BIT(GICR_REG,6);
				    break;
				
			}
	      break;
			case EXTI_enumEXTI1:
				switch (EXTI_INT_ARRAY[i].enumConfig){
					case EXTI_enumLowLevel:
					CLR_BIT(MCUCR_REG,2);
					CLR_BIT(MCUCR_REG,3);
					break;
					case EXTI_enumOnChange:
					SET_BIT(MCUCR_REG,2);
					CLR_BIT(MCUCR_REG,3);
					break;
					case EXTI_enumFallEdge:
					CLR_BIT(MCUCR_REG,2);
					SET_BIT(MCUCR_REG,3);
					break;
					case EXTI_enumRiseEdge:
					SET_BIT(MCUCR_REG,2);
					SET_BIT(MCUCR_REG,3);
					break;
				}
				switch(EXTI_INT_ARRAY[i].enumState)
				{
					case EXTI_enumEnabled:
					SET_BIT(GICR_REG ,7);
					SET_BIT(SREG,7);
				    break;
				    case EXTI_enumDisabled:
				    CLR_BIT(GICR_REG ,7);
				    break;
				
			}
			break;
			case EXTI_enumEXTI2:
				switch (EXTI_INT_ARRAY[i].enumConfig){
					case EXTI_enumFallEdge:
					/*If ISC2 is written to zero, a falling edge on INT2 activates the interrupt*/
					CLR_BIT(MCUCSR_REG,6);
					break;
					case EXTI_enumRiseEdge:
					/*If ISC2 is written to one, a rising edge on INT2 activates the interrupt*/
					SET_BIT(MCUCSR_REG,6);
					break;
				}
				switch(EXTI_INT_ARRAY[i].enumState){
					case EXTI_enumEnabled:
					SET_BIT(GICR_REG ,5);
					SET_BIT(SREG,7);
				    break;
				    case EXTI_enumDisabled:
				    CLR_BIT(GICR_REG ,5);
				    break;
				
			         }
			break;
			
			default:  Ret_enuErrorStatus = EXTI_enumNok;
			break;
			
		}
	}
	
	
}


EXTI_enumError_t EXTI_voidCallBack(void (*Copy_pvoidCallBack)(void), usint8_t Copy_u8EXTILine)
{
	
	EXTI_enumError_t Ret_enuErrorCallBack = EXTI_enumNok;
		
		if (Copy_pvoidCallBack != NULL) {
			Ret_enuErrorCallBack = EXTI_enumOk;
			EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack;
		}
	return  Ret_enuErrorCallBack;
	
}

void __vector_1(void) {
	if (EXTI_CallBack[0] != NULL) {
		EXTI_CallBack[0]();
		
	}
}


void __vector_2(void) {
	if (EXTI_CallBack[1] != NULL) {
		EXTI_CallBack[1]();
		
	}
}

void __vector_3(void) {
	if (EXTI_CallBack[2] != NULL) {
		EXTI_CallBack[2]();

	}
}