/*
 * Button.h
 *
 * Created: 8/10/2022 4:56:00 AM
 *  Author: Abdelrahman Hesham
 */ 

 
#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"
// button state 
#define LOW 0
#define HIGH 1

#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN2
// initialize
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
// button read
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);

#endif /* BUTTON_H_ */