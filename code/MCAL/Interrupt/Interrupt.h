/*
 * Interrupt.h
 *
 * Created: 11/09/2022 06:13:21 PM
 *  Author: Mohamed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/types.h"

/* External Interrupt registers */
#define MCUCR (*(volatile uint8_t*) 0x55)
#define MCUCSR (*(volatile uint8_t*) 0x54)
#define GICR (*(volatile uint8_t*) 0x5B)
#define GIFR (*(volatile uint8_t*) 0x5A)
#define SREG (*(volatile uint8_t*) 0x5F)


/* External Interrupt Vectors */
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3

// set global interrupts - set bit in status register 
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// clear global interrupts - clear bit in status register
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR definition
#define  ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

void INT0_init(void);

#endif /* INTERRUPT_H_ */