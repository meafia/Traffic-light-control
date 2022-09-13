/*
 * Interrupt.c
 *
 * Created: 11/09/2022 06:13:09 PM
 *  Author: Mohamed
 */ 

#include "Interrupt.h"

void INT0_init(void){
	
	
	sei(); // enable global interrupt
	
	MCUCR |= (1<<0) | (1<<1); // sense on rising edge
	
	GICR |= (1<<6); // enable external interrupt 0
}