/*
 * GccApplication3.c
 *
 * Created: 9/7/2022 2:54:02 PM
 * Author : User
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
void slave_init()
{
	DDRB=0b01000000;
	SPCR=0b01000000;
	
	
}
void slave_receive()
{
	
	while(!(SPSR & (1<<SPIF)));
	PORTD=SPDR;
	
}
int main(void)
{
	/* Replace with your application code */
	DDRD=0xFF;
	slave_init();
	while(1)
	{
		slave_receive();
		
	}
}

