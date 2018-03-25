#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>

#include "uart.h"
#include "uart.c"
#include "softuart.c"
#include "softuart.h"
#include <avr/interrupt.h>

void main()
{
   
	uart_init(UART_BAUD_SELECT(115200,F_CPU));
	softuart_init();
	sei();
	
	softuart_puts("welcome");
	sbi(DDRC,0);
	sbi(DDRC,1);
	sbi(DDRC,2);
	sbi(DDRC,3);

	int c;
	int i=0;
	_delay_ms(200);
	
	while(1)
	{
		
			c= uart_getc();
			//if(!(c&UART_NO_DATA))
			if(c!=0)
			{
			softuart_putchar(c);
			uart_putc(c);
			
				if(c=='a')
				{
				
					//i++;
					//sbi(PORTC,0);
					//if(i==4)
				//	{
					softuart_puts("Vehicle is in range\n\r");
					cbi(PORTC,0);
					cbi(PORTC,1);
					sbi(PORTC,2);
					sbi(PORTC,3);
					i=0;
					_delay_ms(10);
					
				//	}
				}
				
				else
				{
				softuart_puts("Vehicle is out  of range\n\r");
				softuart_puts("system alert\n\r");
				sbi(PORTC,0);
				sbi(PORTC,1);
				cbi(PORTC,2);
				cbi(PORTC,3);
				_delay_ms(10);
				
				}
			}
			
			
			
			/*if(c!='a')
			{
			softuart_puts("vehicle is out  of range\n\r");
			softuart_puts("system alert\n\r");
			sbi(PORTC,0);
			sbi(PORTC,1);
			sbi(PORTC,2);
			sbi(PORTC,3);

			_delay_ms(10);
			
			}*/
			
			_delay_ms(600);
		
			
	}
}
	
	
	
	
	
	
	
	
	