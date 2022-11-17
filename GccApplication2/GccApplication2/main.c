/*
 * GccApplication2.c
 *
 * Created: 9/6/2022 2:28:44 PM
 * Author : User
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
void usart_init()
{
	UCSRA=0b00000000;
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	UBRRL=51;
	UBRRH=0;
	
}
int usart_receive()
{
	while((UCSRA & (1<<RXC))==0);
	int temp;
	if (UCSRB & (1<<RXB8))
	temp=1<<8;
	else
	temp=0;
	if (UCSRA & (1<<FE | 1<<PE | 1<<DOR))
	return 0;
	return temp|UDR;
}

int main(void)
{
	/* Replace with your application code */
	DDRB=0b11111111;
	usart_init();
	while(1)
	{
		PORTB=usart_receive()>>1;
	}
}

