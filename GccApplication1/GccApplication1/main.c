#include <avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 1000000
#include<util/delay.h>
#include<stdio.h>
#include<math.h>
void usart_init()
{
	UCSRA=0b00000000;
	UCSRB=0b00011100;
	UCSRC=0b10000110;
	UBRRL=51;
	UBRRH=0;
	
}
void usart_send(int data)
{
	while((UCSRA & (1<<UDRE))==0);
	if (data & (1<<8))
	{
		UCSRB|=(1<<TXB8);
	}
	else
	UCSRB=UCSRB & ~(1<<TXB8);
	UDR=data;
	
}
int main(void)
{  

	usart_init();
	while(1)
	{
		usart_send(255);
	}
	/* Replace with your application code */

}
