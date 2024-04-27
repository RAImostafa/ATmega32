/*
 * ETRI_Cfg.h
 *
 * Created: 29/01/2024 13:57:42
 *  Author: Rania
 */ 


#ifndef ETRI_CFG_H_
#define ETRI_CFG_H_

#define EXTI_INT_PINS_NUM 3


/* customer can put another interrupt pins */
typedef enum
{

	EXTI_enumEXTI0,
	EXTI_enumEXTI1,
	EXTI_enumEXTI2,

}EXTI_enumID_t;

typedef enum
{

	EXTI_enumLowLevel,
	
	EXTI_enumHighLevel, /* not used in ATMEGA32*/
	
	EXTI_enumOnChange,
	
	EXTI_enumFallEdge,

	EXTI_enumRiseEdge,
	
}EXTI_enumConfig_t;

typedef enum
{
	EXTI_enumEnabled,
	EXTI_enumDisabled,

}EXTI_enumState_t;

typedef struct
{
	EXTI_enumID_t enumName;
	EXTI_enumConfig_t enumConfig;
	EXTI_enumState_t enumState;
}
EXTI_strCfg_t;



#endif /* ETRI_CFG_H_ */