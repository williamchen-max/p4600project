/*
 * task8.c
 *
 * Created: 11/7/2019 11:28:36 AM
 * Author : technician
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t keep_going = 1;

void loop()
{
	PORTD |= (1 << PD1);
	_delay_ms(500);
	PORTD &= ~(1 << PD1);
	_delay_ms(500);
}

void setup()
{
setup();
	while(keep_going) loop();
}

int main()
{
	TCNT0 = 0;
	TCCR0B = (1 << CS00)|(1 << CS02);
	
	while(1)
	{
		
		while(( TIFR0 & 1 ) == 0); // DELAYS THE PROGRAM
		PORTD ^= (1<< PD1);
	}
	
	
	
	
	
	
	
	return 0;
}

