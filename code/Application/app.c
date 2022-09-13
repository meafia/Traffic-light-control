/*
 * app.c
 *
 * Created: 11/09/2022 06:04:26 PM
 *  Author: Mohamed
 */ 
#include "app.h"
#include "../MCAL/Interrupt/Interrupt.h"
#include "../MCAL/Timer/Timer.h"

appMode_t mode = normal;

void TrafficLightApp_init(void){
	// button initialization
	// DDRD |= (1<<2);
	/* initialization of car's traffic lights */
	LED_init(PORT_A, 0);
	LED_init(PORT_A, 1);
	LED_init(PORT_A, 2);
	
	
	/* initialization of pedestrians' traffic lights */
	LED_init(PORT_B, 0);
	LED_init(PORT_B, 1);
	LED_init(PORT_B, 2);
	
	/* initialization of interrupt 0 */
	INT0_init();
	
	/* initialization of interrupt 0 */
	Timer0_with_interrupt_initialization(PIN_Set);
	Timer0_with_interrupt_set_delay(10);
	
}
void TrafficLightApp(void){
	switch(mode){
		case normal:
			LED_on(PORT_A, 2);
			LED_off(PORT_A, 1);
			break;
		case pedestriansPiriority:
			LED_on(PORT_A, 2);
			LED_on(PORT_B, 0);
			break;
	}
}

ISR(EXT_INT_0){
	mode = pedestriansPiriority;
	Timer0_Start(TIMER0_Prescaler_256);
}

ISR(TIMER0_OVF_vect){
	mode = normal;
	Timer0_Stop();
}