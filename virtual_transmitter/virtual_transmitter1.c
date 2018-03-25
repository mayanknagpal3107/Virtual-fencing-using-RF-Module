#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>

#include "uart.h"
#include "uart.c"
#include <avr/interrupt.h>





void forward()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		sbi(PORTD,2);
		cbi(PORTD,3);
		sbi(PORTD,7);
		cbi(PORTD,6);
		
		
}

void reverse()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		cbi(PORTD,2);
		sbi(PORTD,3);
		cbi(PORTD,7);
		sbi(PORTD,6);
		
}

void left()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		cbi(PORTD,2);
		sbi(PORTD,3);
		sbi(PORTD,7);
		cbi(PORTD,6);	

}


void right()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		sbi(PORTD,2);
		cbi(PORTD,3);
		cbi(PORTD,7);
		sbi(PORTD,6);
}

void rightforward()
{
		sbi(PORTD,4);
		sbi(PORTD,5);

		cbi(PORTD,2);
		cbi(PORTD,3);
		sbi(PORTD,7);
		cbi(PORTD,6);
}



void leftforward()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		sbi(PORTD,2);
		cbi(PORTD,3);
		cbi(PORTD,7);
		cbi(PORTD,6);

}

void stop()
{
	cbi(PORTD,4);
	cbi(PORTD,5);

	cbi(PORTD,2);
	cbi(PORTD,3);
	cbi(PORTD,7);
	cbi(PORTD,6);
}

motorinit()
{

	sbi(DDRD,2);
	sbi(DDRD,3);
	
	sbi(DDRD,4);
	sbi(DDRD,5);
	
	sbi(DDRD,6);
	sbi(DDRD,7);


}


void main()
{
   
	uart_init(UART_BAUD_SELECT(115200,F_CPU));
	sei();
	//uart_puts("welcome");
	
	sbi(DDRC,0);
	sbi(DDRC,1);
	sbi(DDRC,2);
	sbi(DDRC,3);
	
	motorinit();
	char c;
	
	_delay_ms(500);
	
	while(1)
	{
		c= uart_getc();
		if(c!=0)
			{
			//	softuart_putchar(c);
				//uart_putc(c);
				
				if(c=='w')
				{
				forward();
				sbi(PORTC,1);
				
				
				}
				if(c=='s')
				{
				cbi(PORTC,1);
				cbi(PORTC,2);
				cbi(PORTC,3);
				stop();
				
				}
				if(c=='a')
				{
				sbi(PORTC,2);
				left();
				
				}
				if(c=='d')
				{
				
				right();
				sbi(PORTC,3);

				
				}
	
			}
	
	
		
			sbi(PORTC,0);
			uart_putc('a');		
			_delay_ms(300);
			cbi(PORTC,0);
			_delay_ms(300);
		
	}
}
	
	
	
	
	
	
	
	
	