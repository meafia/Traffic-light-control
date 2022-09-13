/*
 * Traffic light control.c
 *
 * Created: 11/09/2022 10:30:33 AM
 * Author : Mohamed
 */ 

// #include <avr/io.h>

#include "Application/app.h"

int main(void)
{
    /* Replace with your application code */
	
	TrafficLightApp_init();
    while (1) 
    {
		TrafficLightApp();
    }
}

