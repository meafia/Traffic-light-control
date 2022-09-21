/*
 * app.c
 *
 * Created: 11/09/2022 06:04:26 PM
 *  Author: Mohamed
 */ 
#include "app.h"
#include <util/delay.h>

appMode_t mode = normal;
trafficLightState_t currentState = carReady;
int numberOfOverflow = 0; 


void resetAllLEDs(void){
	LED_off(PORT_A, 0);
	LED_off(PORT_A, 1);
	LED_off(PORT_A, 2);
	LED_off(PORT_B, 0);
	LED_off(PORT_B, 1);
	LED_off(PORT_B, 2);
}

void TrafficLightApp_init(void){
	// button initialization
	button_init(PORT_D, 2);
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
	Timer0_with_interrupt_initialization();
	Timer0_with_interrupt_set_delay(20);
	
}
void TrafficLightApp(void){
	switch(mode){
		case normal:
			resetAllLEDs();
			if( mode != pedestriansPiriority){
				currentState = carReady;
				for(int i = 0; i <= 5; i++){
					LED_toggle(PORT_A, 1);
					LED_toggle(PORT_B, 1);
					//_delay_ms(1000);
				}
			}
			if( mode != pedestriansPiriority){
				currentState = carstop;
				LED_on(PORT_A, 2);
				LED_on(PORT_B, 0);
				//_delay_ms(5000);
				LED_off(PORT_A, 2);
				LED_off(PORT_B, 0);
			}
			if( mode != pedestriansPiriority){
				currentState = carReady;
				for(int i = 0; i <= 5; i++){
					LED_toggle(PORT_A, 1);
					LED_toggle(PORT_B, 1);
					//_delay_ms(1000);
				}
			}
			if( mode != pedestriansPiriority){
				currentState = carGo;
				LED_on(PORT_A, 0);
				LED_on(PORT_B, 2);
				//_delay_ms(5000);
				LED_off(PORT_A, 0);
				LED_off(PORT_B, 2);
			}
			break;
		case pedestriansPiriority:
			resetAllLEDs();
			if(currentState == carReady || currentState == carstop){
				LED_on(PORT_A, 2); // keep car red led on
				LED_on(PORT_B, 0); // pedestrians green led
				//_delay_ms(1000);
			}
			if(currentState == carGo){
				mode = normal;
			}
			break;
	}
}



ISR(EXT_INT_0){
	mode = pedestriansPiriority;
	Timer0_Start(TIMER0_Prescaler_1024);
}

ISR(TIMER0_OVF_vect){
	numberOfOverflow++;
	if(numberOfOverflow >= 20){
		mode = normal;
		Timer0_Stop();
		numberOfOverflow = 0;
	}	
}