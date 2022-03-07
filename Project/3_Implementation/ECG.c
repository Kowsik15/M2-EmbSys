#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "usart.h"
#include "lcd.h"
#include "keypad.h"
#include "spi_sl.h"
unsigned char  key[4][4]={"789/","456X","123-","N0=+"};
int is_available(char  ch)
{
	int i,j,flag=0;
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			if (ch==key[i][j])
			{
				flag=1;
				break;
			}
		}
		if (flag==1)
		break;
	}
	return flag;
}
int main()
{
	DDRC=0xF0;
	PORTC=0xFF;
	int i=0;
	char ch[2];
	unsigned char cmd_1[10]="AT";
	unsigned char cmd_2[10]="\0";
	unsigned char cmd_3[11]="AT+CMGF=1";
	unsigned char cmd_4[11]="AT+CMGS=";
	unsigned char cmd_5[20]="NULL";
	ch[1]='\0';
	DDRA=0xFF;
	DDRB=0xFF;
	DDRD=0xFF;
	USART_init(9600);
	lcd_init();
	SPIsl_init();
	lcd_print("enter the number");
	lcd_cmd(0xC0);
	while (1)
	{
		_delay_ms(40);
		ch[0]=keypad();
		if (is_available(ch[0])==0)
		goto end;
		else if(ch[0]=='X')
		{
			lcd_cmd(0x01);
			lcd_print("enter the number");
			lcd_cmd(0xC0);
			i=0;
		}
		else
		{
			lcd_print(ch);
			cmd_2[i]=ch[0];
			i++;
		}
		if (i==10)
		break;
		end:;
	}
	begin:;
	lcd_cmd(0x01);
	i=0;
	while (1)
	{
		cmd_5[i]=SPI_Receive();
		i++;
		if (i==18)
		break;
	}
	while (1){
		{
			lcd_print("sending message");
			_delay_ms(1000);
			lcd_init();
			for (i=0;cmd_1[i]!='\0';i++)
			{
				USART_txc(cmd_1[i]);
				_delay_ms(100);
			}
			USART_txc('\r');
			_delay_ms(500);
			for (i=0;cmd_3[i]!='\0';i++)
			{
				USART_txc(cmd_3[i]);
				_delay_ms(100);
			}
			USART_txc('\r');
			_delay_ms(500);
			for (i=0;cmd_4[i]!='\0';i++)
			{
				USART_txc(cmd_4[i]);
				_delay_ms(100);
			}
			UDR='"';
			_delay_ms(100);
			for (i=0;i<10;i++)
			{
				USART_txc(cmd_2[i]);
				_delay_ms(100);
			}
			UDR='"';
			_delay_ms(100);
			UDR='\r';
			_delay_ms(500);
			for (i=0;cmd_5[i]!='\0';i++)
			{
				USART_txc(cmd_5[i]);
				_delay_ms(100);
			}
			USART_txc(26);
			_delay_ms(500);
			lcd_print("message sent");
			_delay_ms(1000);
			lcd_init();
			goto begin;
		}
	}
}
