/*
 * LED.c
 *
 * Created: 8/10/2022 4:43:46 AM
 *  Author: Abdelrahman Hesham
 */ 
#include "LED.h"
//initializing the led state
void LED_init(uint8_t ledPort, uint8_t ledPin){
	DIO_init(ledPin, ledPort, OUT);
	
	}
//turn on led
void LED_on(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPin, ledPort, HIGH);
}
//turn off led
void LED_off(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPin, ledPort, LOW);
}
//toggle the led state
void LED_toggle(uint8_t ledPort, uint8_t ledPin){
	DIO_toggle(ledPin, ledPort);
}