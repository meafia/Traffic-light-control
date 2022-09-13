/*
 * LED.h
 *
 * Created: 11/09/2022 06:20:12 PM
 *  Author: Mohamed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"

DIOError_t LED_init(Port_t port, uint8_t pinNumber);
DIOError_t LED_off(Port_t port, uint8_t pinNumber);
DIOError_t LED_on(Port_t port, uint8_t pinNumber);
DIOError_t LED_toggle(Port_t port, uint8_t pinNumber);

#endif /* LED_H_ */