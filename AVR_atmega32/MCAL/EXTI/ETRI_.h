/*
 * ETRI_.h
 *
 * Created: 29/01/2024 13:57:26
 *  Author: Rania
 */ 

#include "ETRI_Cfg.h"
#include "EXTRI_REG.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO_RegAdd.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\Bit_Math.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\LIB\std_types.h"
#include "C:\Users\HP\Documents\Atmel Studio\7.0\concepts of Embedded\MCAL\DIO\DIO.h"


#ifndef ETRI__H_
#define ETRI__H_


/*array of function pointers to hold callback functions for the 3 external interrupts*/

EXTI_strCfg_t EXTI_INT_ARRAY[EXTI_INT_PINS_NUM];

	
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function Performed Correctly.
	 */
	EXTI_enumOk,             

	/**
	 *@brief : something wrong .
	 */     
	EXTI_enumNok    
	
}EXTI_enumError_t;



/*
 * Description: ISR for  (INT0) 
 * Input: void
 * output :void
 */
void __vector_1(void) __attribute__((signal));



/*
 * Description: ISR for  (INT1) 
 * Input: void
 * output :void
 */
void __vector_2(void) __attribute__((signal));




/*
 * Description: ISR for  (INT2) 
 * Input: void
 * output :void
 */
void __vector_3(void) __attribute__((signal));



/*
 * Description: Function to set customer configuration *post order* 
 * Input: void
 * output :Error handler 
 */
EXTI_enumError_t EXTI_enumInit (void);



/*
 * Description: Function to set a callback function for a specific external interrupt line
 * Input: 
 *   - Copy_pvoidCallBack: Pointer to the callback function that will be executed when the interrupt occurs.
 *   - Copy_u8EXTILine: The external interrupt line number for which the callback function is being set.
 * Output: 
 *   - Error state 
 */
EXTI_enumError_t EXTI_voidCallBack(void (*Copy_pvoidCallBack)(void), uint8_t Copy_u8EXTILine);


#endif /* ETRI__H_ */