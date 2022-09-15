/*
 * Timer.c
 *
 * Created: 13/09/2022 11:10:26 AM
 *  Author: Mohamed
 */

#include "Timer.h"
#include "../Interrupt/Interrupt.h"
#include "../../Utilities/types.h"


uint32_t globalPrescaler = 0;
uint32_t OVFNum = 0;
uint32_t initval = 0;

void Timer0_with_interrupt_initialization(){
	cli();
	/* normal mode */
	TCCR0 &= ~(1<<3); //clear WGM01
	TCCR0 &= ~(1<<6); //clear WGM00
	
	/* enable interrupt */
	TIMSK0 |= (1<<0); // set TOIE0 
	
	sei();
}

void Timer0_with_interrupt_set_delay(uint32_t delay){
	uint32_t tick = (1 * globalPrescaler) / 8;
	uint32_t Count = (delay * 1000) / tick;
	OVFNum = Count / 256;
	if( Count % 256 )
	OVFNum++;
	
	initval = 256 - (Count % 256);
	TCNT0 = initval;
}


void Timer0_Start(TIMER0Prescaler_t prescaler)
{
	switch(prescaler)
	{
		case TIMER0_Prescaler_0:
			TCCR0 &= ~(1<<0); //clear CS00
			TCCR0 &= ~(1<<1); //clear CS01
			TCCR0 &= ~(1<<2); //clear CS02
			globalPrescaler = 0;
		break;
		case TIMER0_Prescaler_1:
			TCCR0 |= (1<<0); //set SC00
			TCCR0 &= ~(1<<1); //clear CS01
			TCCR0 &= ~(1<<2); //clear CS02
			globalPrescaler = 1;
			break;
		case TIMER0_Prescaler_8:
			TCCR0 &= ~(1<<0); //clear CS00
			TCCR0 |= (1<<1); //set CS01
			TCCR0 &= ~(1<<2); //clear CS02
			globalPrescaler = 8;
			break;
		case TIMER0_Prescaler_64:
			TCCR0 |= (1<<0); //set SC00
			TCCR0 |= (1<<1); //set CS01
			TCCR0 &= ~(1<<2); //clear CS02
			globalPrescaler = 64;
			break;
		case TIMER0_Prescaler_256:
			TCCR0 &= ~(1<<0); //clear CS00
			TCCR0 &= ~(1<<1); //clear CS01
			TCCR0 |= (1<<2); //set CS02
			break;
		case TIMER0_Prescaler_1024:
			TCCR0 |= (1<<0); //set CS00
			TCCR0 &= ~(1<<1); //clear CS01
			TCCR0 |= (1<<2); //set CS02
			break;
	}
}



void Timer0_Stop(void)
{
	TCCR0 &= ~(1<<0); //clear CS00
	TCCR0 &= ~(1<<1); //clear CS01
	TCCR0 &= ~(1<<2); //clear CS02

	globalPrescaler = 0;
}