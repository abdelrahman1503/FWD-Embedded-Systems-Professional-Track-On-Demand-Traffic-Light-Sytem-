/*
 * traffic light sys.c
 *
 * Created: 8/10/2022 8:15:31 AM
 * Author : Abdelrahman Hesham
 */ 

#include <avr/interrupt.h>
#include "APP/app.h"
int main(void)
{
    /* Replace with your application code */
    
	APP_init();
	APP_start();
}

ISR(INT0_vect)
{
	// Variable to store the value of the pin
	static int value;
	// two variables used as counters to control the timer overflow
	int overflow = 0, counter = 0;
	//reading the value of pin 0 in port A (cars red light)
	DIO_read(0, 'A', &value);
	if(value == 1)
	{
		// if the cars red light is on nothing will happen
	}
	else if (value == 0)
	{
		//if the yellow or green is on it will be turned off
		LED_off('A', 1);
		LED_off('A', 2);
		LED_off('B', 1);
		LED_off('B', 0);
		//blinking the yellow light for both cars and pedestrian
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
	}
	//disable the external interrupt to return to normal mode
	GICR&=~(1<<INT0);
	//returning to normal mode
	APP_start();
}
