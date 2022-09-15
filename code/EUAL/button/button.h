/*
 * button.h
 *
 * Created: 12/09/2022 02:12:15 PM
 *  Author: Mohamed
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"

void button_init(Port_t port, uint8_t pinNumber);

#endif /* BUTTON_H_ */