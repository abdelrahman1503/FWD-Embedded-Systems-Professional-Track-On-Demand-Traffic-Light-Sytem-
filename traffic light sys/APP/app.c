/*
 * app.c
 *
 * Created: 8/10/2022 10:00:21 AM
 *  Author: Abdelrahman Hesham
 */
#include "app.h"
#include <avr/interrupt.h>
void APP_init(void)
{
	//initializing pin 2 in port D to input
	BUTTON_init(2, 'D');
	//initializing all pin 0,1,2 in port A, port B to output
	LED_init(0, 'A');
	LED_init(1, 'A');
	LED_init(2, 'A');
	LED_init(0, 'B');
	LED_init(1, 'B');
	LED_init(2, 'B');
}
void APP_start(void)
{
	//Two variables used as counters for timer
	unsigned int overflow = 0;
	unsigned int counter = 0;
	//enable global interrupt
	sei();
	// set interrupt sense to raising edge
	MCUCR |= (1<<ISC00) | (1<<ISC01);
	//enable external interrupt
	GICR |= (1<<INT0);
	TCCR0 = 0x00; //Normal Mode
	TCNT0 = 0x00; //set initial value to 0
	TCCR0 |= (1<<0); //no prescalar
	while (1)
	{
		//Cars red led and pedestrian green led are initially on
		LED_on('A', 0);
		LED_on('B', 2);
		//Using the timer to delay 5 seconds
		while (overflow < 19532)
		{
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0);
			overflow++;
		}
		//reseting the counter to 0
		overflow = 0;
		TCNT0 = 0x00;
		//Cars red led and pedestrian green led are off
		LED_off('A', 0);
		LED_off('B', 2);
		//Blinking the yellow leds for both
		while (overflow < 20)
		{

				LED_toggle('A', 1);
				LED_toggle('B', 1);
			while (counter < 1000)
			{
				while ((TIFR & (1<<0)) == 0);
				TIFR |= (1<<0);
				counter++;
			}
			counter = 0;
			TCNT0 = 0x00;
			overflow ++;
		}
		overflow = 0;
		TCNT0 = 0x00;
		//The yellow leds are off
		LED_off('A', 1);
		LED_off('B', 1);
		//Cars green led and pedestrian red led are on
		LED_on('A', 2);
		LED_on('B', 0);
		//timer to delay by 5 seconds
		while (overflow < 19532)
		{
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0);
			overflow++;
		}
		//reseting the counter and timer
		overflow = 0;
		TCNT0 = 0x00;
		//Cars green led and pedestrian red led are off
		LED_off('A', 2);
		LED_off('B', 0);
		//Blinking the yellow leds for 5 seconds
		while (overflow < 20)
		{

			LED_toggle('A', 1);
			LED_toggle('B', 1);
			while (counter < 1000)
			{
				while ((TIFR & (1<<0)) == 0);
				TIFR |= (1<<0);
				counter++;
			}
			counter = 0;
			TCNT0 = 0x00;
			overflow ++;
		}
		//reseting the counter and timer
		overflow = 0;
		TCNT0 = 0x00;
		//Both yellow leds are off
		LED_off('A', 1);
		LED_off('B', 1);
		}
}
