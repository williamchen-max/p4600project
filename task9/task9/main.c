/*
 * task9.c
 *
 * Created: 14/11/2019 10:37:15 AM
 * Author : Advanced Student
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>



   ISR(TIMER0_OVF_vect)
   {
	   PORTD ^= (1 << PD1); // turn off
   }
   
   ISR(TIMER0_COMPA_vect)
   {
	   PORTD ^= (1 << PD1); // turn on
	   
   }

   void loop()
   {
	   
   }

   void setup()
   {
	   DDRD |= (1 << PD1); // SET PORT D AS OUTPUT PIN
	   PORTD &= ~(1 << PD1);  // START PIN AS 0

	   TCCR0B = 0x11; // choose normal mode with no clock prescale
	   TIMSK0 |=(1<<OCIE0A)|(1<<TOIE0) ;// Enables timer 0 overflow interrupt
	   
	   OCR0A = 200;
	   
	   sei();
   }

   int main()
   {
	   setup();
	   while(1) loop();

   }

