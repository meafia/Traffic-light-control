/*
 * Timer.h
 *
 * Created: 11/09/2022 06:13:38 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/types.h"

#define TIMER0_OVF_vect  __vector_11

#define TCCR0 (*(volatile uint8_t*) 0x53)
#define TCNT0 (*(volatile uint8_t*) 0x52)
#define TIMSK0 (*(volatile uint8_t*) 0x59)
#define TIFR0 (*(volatile uint8_t*) 0x58)
#define OCR0 (*(volatile uint8_t*) 0x5C)

typedef enum
{
	TIMER0_Prescaler_0,
	TIMER0_Prescaler_1,
	TIMER0_Prescaler_8,
	TIMER0_Prescaler_64,
	TIMER0_Prescaler_256,
	TIMER0_Prescaler_1024
}TIMER0Prescaler_t;

typedef enum
{
	Normal_Mode,
	CTC_Mode,
	PWM_Mode,
	Phase_Correct_PWM_Mode
}TIMER0Mode_t;

typedef enum
{
	PIN_Disconnected,
	PIN_Toggle ,
	PIN_Clear,
	PIN_Set
}TIMER0PinMode_t;

void Timer0_Start(TIMER0Prescaler_t prescaler);
void Timer0_with_interrupt_initialization(TIMER0PinMode_t pin_mode);
void Timer0_with_interrupt_set_delay(uint32_t delay);
void Timer0_Stop(void);

#endif /* TIMER_H_ */