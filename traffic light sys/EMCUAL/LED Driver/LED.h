/*
 * LED.h
 *
 * Created: 8/10/2022 4:43:27 AM
 *  Author: Abdelrahman Hesham
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"
void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);



#endif /* LED_H_ */