/*
 * ETRI_Cfg.c
 *
 * Created: 29/01/2024 13:58:09
 *  Author: Rania
 */ 


#include "ETRI_.h"

EXTI_strCfg_t EXTI_INT_ARRAY [ EXTI_INT_PINS_NUM]=
{
	[0]=
	    {.enumName   = EXTI_enumEXTI0, 
		 .enumState  = EXTI_enumEnabled,
		 .enumConfig = EXTI_enumFallEdge
		},
		
	[1]={
		.enumName   = EXTI_enumEXTI1,
		.enumState  = EXTI_enumEnabled,
		.enumConfig = EXTI_enumFallEdge
		},
    [2]={}
	
	
	
};