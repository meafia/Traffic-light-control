/*
 * LED.c
 *
 * Created: 11/09/2022 06:19:58 PM
 *  Author: Mohamed
 */ 

#include "LED.h"



DIOError_t LED_init(Port_t port, uint8_t pinNumber){
	return setPinDirection(port, pinNumber, DIO_OUT);
}
DIOError_t LED_off(Port_t port, uint8_t pinNumber){
	return setPinValue(port, pinNumber, DIO_LOW);
}
DIOError_t LED_on(Port_t port, uint8_t pinNumber){
	return setPinValue(port, pinNumber, DIO_HIGH);
}
DIOError_t LED_toggle(Port_t port, uint8_t pinNumber){
	return togglePinValue(port, pinNumber);
}