/*
 * Dio.h
 *
 * Created: 8/10/2022 3:28:30 AM
 *  Author: Abdelrahman Hesham
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Registers.h"
#include "../../types.h"

// all internal driver typedef
//all drivers macros 
 #define PORT_A 'A'
 #define PORT_B 'B'
 #define PORT_C 'C'
 #define PORT_D 'D'
 #define IN 0
 #define OUT 1
 #define LOW 0
 #define HIGH 1
 
// all driver functions prototypes 
void DIO_init(uint8_t pinumber,  uint8_t portNumber, uint8_t direction); // Initialize dio direction
void DIO_write(uint8_t pinumber, uint8_t portumber, uint8_t value); // write data to dio
void DIO_toggle(uint8_t pinumber, uint8_t portNumber); // toggle Dio
void DIO_read(uint8_t pinumber, uint8_t portNumber,  uint8_t *value); // Read dio
#endif /* DIO_H_ */