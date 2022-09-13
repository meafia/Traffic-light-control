/*
 * app.h
 *
 * Created: 11/09/2022 06:04:45 PM
 *  Author: Mohamed
 */ 


#ifndef APP_H_
#define APP_H_

#include "../EUAL/LED/LED.h"

typedef enum 
{
	normal,
	pedestriansPiriority
}appMode_t;


void TrafficLightApp_init(void);
void TrafficLightApp(void);


#endif /* APP_H_ */