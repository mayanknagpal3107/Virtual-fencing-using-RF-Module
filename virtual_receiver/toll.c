#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>
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
		uart_puts("\n\r");
		uart_puts("FOR");
		
}

void reverse()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		cbi(PORTD,2);
		sbi(PORTD,3);
		cbi(PORTD,7);
		sbi(PORTD,6);
		uart_puts("\n\r");
		uart_puts("rev");

}

void left()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		cbi(PORTD,2);
		sbi(PORTD,3);
		sbi(PORTD,7);
		cbi(PORTD,6);	
		uart_puts("\n\r");
		uart_puts("L");

}


void right()
{
		sbi(PORTD,4);
		sbi(PORTD,5);
		
		sbi(PORTD,2);
		cbi(PORTD,3);
		cbi(PORTD,7);
		sbi(PORTD,6);
		uart_puts("\n\r");
		uart_puts("R");


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
	uart_puts("\n\r");
	uart_puts("stop");

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
   
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
	int count=1;
	cbi(DDRA,7);
	
	sbi(DDRC,0);
	sbi(DDRC,1);
	sbi(DDRC,2);
	sbi(DDRC,3);
	
	motorinit();
	
	_delay_ms(5000);
	
	while(1)
	{
		if(bit_is_set(PINA,7))
		{
			
			
		
			if(count==1)//only one time if condition set so count is used
			{
				forward();
				sbi(PORTC,1);
				_delay_ms(1000);
				
				stop();
				sbi(PORTC,2);
				_delay_ms(2500);
				
				reverse();
				sbi(PORTC,3);
				_delay_ms(1000);
				stop();
				count++;
			}
			
		
	
		}

		else
		{
		cbi(PORTC,1);
		cbi(PORTC,2);
		cbi(PORTC,3);
		count=1;
		//_delay_ms(1000);
		
		
		
		}
	}
	
	
}
	
	
	
	
	
	
	
	
	