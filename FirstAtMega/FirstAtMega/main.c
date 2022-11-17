/*
 * FirstAtMega.c
 *
 * Created: 6/15/2022 10:04:01 PM
 * Author : User
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
int mat[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,0,0,0,1,1,0},
	{0,0,0,0,1,1,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,1,1,0,0,0,0},
	{0,1,1,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
};
void f()
{
	for(int i=0;i<8;i++)
	{PORTD=1<<i;
		int s=(1<<8)-1;
		for(int j=0;j<8;j++)
	{
		if (mat[i][j])
		s=s^(1<<j);
	}
	
	PORTC=s;
	_delay_ms(5);
	}
	
	
}
void rotate()
{
	for(int i=0;i<8;i++)
	{ int temp=mat[i][0];
		for(int j=0;j<7;j++)
		mat[i][j]=mat[i][j+1];
		mat[i][7]=temp;
		
	}
	
}
int main(void)
{
    /* Replace with your application code */
	DDRC=0b00000000;
	PORTC=0b00000001;
	
    while (1) 
    {  
    }
}

