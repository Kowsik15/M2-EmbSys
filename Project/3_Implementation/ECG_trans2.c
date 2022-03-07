#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "lcd.h"
#include "spi_mstr.h"
int i=00;
int j=0;
char s[3];
char msg[20]="1 Heart Rate is ";
ISR (TIMER1_OVF_vect)
{
	TIFR|=(1<<TOV1);
	TCNT1=57723;
	i++;
	if (i==60)
	{
		i=0;
		if ((TCNT0<60)|(TCNT0>100))
		{
		lcd_print(itoa(TCNT0,s,10));
		PORTB&=~(1<<PB4);
		for (j=0;msg[j]!='\0';j++)
		{
			SPI_write(msg[j]);
		}
		PORTB&=~(1<<PB4);
		for (j=0;s[j]!='\0';j++)
		{
			SPI_write(s[j]);
		}
		}
		TCNT0=0x00;}
}
int main()
{
	DDRC=0xFF;
	DDRA=0xFF;
	lcd_init();
	SPImstr_init();
	TCNT0=0x00;
	TCCR0=0x06;
	TCNT1=57723;
	sei();
	TIMSK|=(1<<TOIE1);
	TCCR1B=0x05;
	while (1)
	{
		
	}
}
