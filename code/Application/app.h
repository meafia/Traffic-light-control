/*
 * app.h
 *
 * Created: 11/09/2022 06:04:45 PM
 *  Author: Mohamed
 */ 


#ifndef APP_H_
#define APP_H_

#include "../EUAL/LED/LED.h"
#include "../MCAL/Interrupt/Interrupt.h"
#include "../MCAL/Timer/Timer.h"
#include "../EUAL/button/button.h"

typedef enum 
{
	normal,
	pedestriansPiriority
}appMode_t;

typedef enum 
{
	carGo,
	carReady,
	carstop
}trafficLightState_t;


void TrafficLightApp_init(void);
void TrafficLightApp(void);

void resetAllLEDs(void);


#endif /* APP_H_ */