/*
 * DIO.h
 *
 * Created: 11/09/2022 06:09:33 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/types.h"

/* DIO registers */
#define PORTA (*(volatile uint8_t*) 0x3B)
#define DDRA (*(volatile uint8_t*) 0x3A)
#define PINA (*(volatile uint8_t*) 0x39)

#define PORTB (*(volatile uint8_t*) 0x38)
#define DDRB (*(volatile uint8_t*) 0x37)
#define PINB (*(volatile uint8_t*) 0x36)

#define PORTC (*(volatile uint8_t*) 0x35)
#define DDRC (*(volatile uint8_t*) 0x34)
#define PINC (*(volatile uint8_t*) 0x33)

#define PORTD (*(volatile uint8_t*) 0x32)
#define DDRD (*(volatile uint8_t*) 0x31)
#define PIND (*(volatile uint8_t*) 0x30)

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}Port_t;


typedef enum
{
	DIO_LOW,
	DIO_HIGH
}DIOValue_t;

typedef enum 
{
	DIO_IN,
	DIO_OUT
}DIODirection_t;

typedef enum
{
	DIO_OK,
	DIO_FAILD
}DIOError_t;

DIOError_t setPinDirection(Port_t port, uint8_t pinNumber, DIODirection_t direction);
DIOError_t setPinValue(Port_t port, uint8_t pinNumber, DIOValue_t value);
DIOError_t togglePinValue(Port_t port, uint8_t pinNumber);




#endif /* DIO_H_ */