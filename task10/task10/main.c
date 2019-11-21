/*
 * task10.c
 *
 * Created: 18/11/2019 10:29:09 AM
 * Author : Advanced Student
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void setup()
{
	DDRD |= (1<<PD6); // SET PORT D 6 AS OUTPUT PIN
	
	DDRD |= (1<<PD5);
	
	TCCR0A |= (1<<COM0B0)|(1<<COM0B1)|(1<<COM0A0)| (1<<COM0A1);
	
	TCCR0A |=  (1<<WGM00);
	TCCR0B |= (1<<CS00);


	OCR0A = 200;
	OCR0B = 600;


}

int main()
{
	setup();
	while(1);
	
	return 0;
}
