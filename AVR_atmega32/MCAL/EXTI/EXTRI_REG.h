/*
 * EXTRI_REG.h
 *
 * Created: 07/02/2024 11:19:32
 *  Author: Rania
 */ 


#ifndef EXTRI_REG_H_
#define EXTRI_REG_H_
#include <avr/io.h>

#define MCUCR_REG   *((volatile usint8_t*)0x55)
#define MCUCSR_REG  *((volatile usint8_t*)0x54)
#define GICR_REG    *((volatile usint8_t*)0x5B)
#define GIFR_REG    *((volatile usint8_t*)0x5A)



#endif /* EXTRI_REG_H_ */