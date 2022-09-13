/*
 * DIO.c
 *
 * Created: 11/09/2022 06:09:46 PM
 *  Author: Mohamed
 */ 

#include "DIO.h"

DIOError_t setPinDirection(Port_t port, uint8_t pinNumber, DIODirection_t direction){
	switch(direction){
		case DIO_IN:
			switch(port){
				case PORT_A:
					DDRA &= ~(1<<pinNumber);
					break;
				case PORT_B:
					DDRB &= ~(1<<pinNumber);
					break;
				case PORT_C:
					DDRC &= ~(1<<pinNumber);
					break;
				case PORT_D:
					DDRD &= ~(1<<pinNumber);
					break;
			}
			break;
		case DIO_OUT:
			switch(port){
				case PORT_A:
					DDRA |= (1<<pinNumber);
					break;
				case PORT_B:
					DDRB |= (1<<pinNumber);
					break;
				case PORT_C:
					DDRC |= (1<<pinNumber);
					break;
				case PORT_D:
					DDRD |= (1<<pinNumber);
					break;
			}
			break;
	}
	return DIO_OK;
}
DIOError_t setPinValue(Port_t port, uint8_t pinNumber, DIOValue_t value){
	switch(value){
		case DIO_LOW:
		switch(port){
			case PORT_A:
				PORTA &= ~(1<<pinNumber);
				break;
			case PORT_B:
				PORTB &= ~(1<<pinNumber);
				break;
			case PORT_C:
				PORTC &= ~(1<<pinNumber);
				break;
			case PORT_D:
				PORTD &= ~(1<<pinNumber);
				break;
		}
		break;
		case DIO_HIGH:
		switch(port){
			case PORT_A:
				PORTA |= (1<<pinNumber);
				break;
			case PORT_B:
				PORTB |= (1<<pinNumber);
				break;
			case PORT_C:
				PORTC |= (1<<pinNumber);
				break;
			case PORT_D:
				PORTD |= (1<<pinNumber);
				break;
		}
		break;
	}
	return DIO_OK;
}
DIOError_t togglePinValue(Port_t port, uint8_t pinNumber){
	switch(port){
		case PORT_A:
			PORTA ^= (1<<pinNumber);
			break;
		case PORT_B:
			PORTB ^= (1<<pinNumber);
			break;
		case PORT_C:
			PORTC ^= (1<<pinNumber);
			break;
		case PORT_D:
			PORTD ^= (1<<pinNumber);
			break;
	}
	return DIO_OK;
}