

#include <avr/io.h>


int main(void)
{
    uint16_t lowbyte; // unsingn int of 16 bit
    uint16_t highbyte;
	uint16_t finalvalue;
	ADCSRA |= (1<<ADEN);


	DDRD |= (1<<PD1); // SET PORT D 1 to 3 AS OUTPUT PIN
	
	DDRD |= (1<<PD2);
	
	DDRD |= (1<<PD3);
	
	ADMUX |= (1<<MUX2)|(1<<MUX0)|(1<<REFS0); // Set ADC05 on
	
while(1){
ADCSRA |=(1<<ADSC); // START data collection
    while(! ADCSRA & (1<<ADIF)); // LOOP until ADC complete
       
	     lowbyte = ADCL;  
		 highbyte = ADCH;  
		 
		 finalvalue = (highbyte << 8)| lowbyte;

	if(finalvalue < 300)
	{
		PORTD &= ~(1 << PD1);
		PORTD &= ~(1 << PD2);
		PORTD &= ~(1 << PD3);
		PORTD |= (1 << PD1);
	}
	if(finalvalue < 600 & finalvalue > 300)
	{
		PORTD &= ~(1 << PD1);
		PORTD &= ~(1 << PD2);
		PORTD &= ~(1 << PD3);		
		PORTD |= (1 << PD2);
	}
	if(finalvalue < 900 & finalvalue > 600)
	{
		PORTD &= ~(1 << PD1);
		PORTD &= ~(1 << PD2);
		PORTD &= ~(1 << PD3);
		PORTD |= (1 << PD3);
	}
	}

	return 0;
}


    

 

