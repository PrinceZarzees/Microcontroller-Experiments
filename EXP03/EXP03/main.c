/*
 * EXP03.c
 *
 * Created: 7/30/2022 11:34:53 PM
 * Author : User
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7
#include "lcd.h"
#include <stdio.h>
int main(void)
{
    
	DDRC=0b11111111;
	DDRD=0b11111111;
	ADMUX=0b01100000;
	ADCSRA=0b10000001;
	/* Replace with your application code */
	Lcd4_Init();
    while (1) 
    {
		Lcd4_Set_Cursor(1,1);
		ADCSRA|=(1<<ADSC);
		while(ADCSRA & 1<<ADSC) {}
		float result=(ADCL>>6|ADCH<<2)*5.0/1024;
		char ch[8];
		int temp=result;
		ch[0]=temp%10+'0';
		ch[1]='.';	
		for(int i=2;i<=4;i++)
		{
		result=result*10;
		temp=result;
		ch[i]=temp%10+'0';
		}
		ch[5]='\0';
		Lcd4_Write_String(ch);
		
    }
}

