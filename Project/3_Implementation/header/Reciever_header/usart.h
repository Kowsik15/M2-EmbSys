#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)
void USART_init(long);
unsigned char USART_rxc();
void USART_txc(char);
void USART_send(char *);
void USART_init(long USART_BAUDRATE)
{
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=BAUD_PRESCALE;
	UBRRH=(BAUD_PRESCALE>>8);
}
unsigned char  USART_rxc()
{
	while (UCSRA&(1<<RXC)==0);
	return UDR;
}
void USART_txc(char ch)
{
	while (!(UCSRA&(1<<UDRE)));
	UDR=ch;
}
void USART_send(char *str)
{
	while (*str!='\0')
	{
		USART_txc(*str);
		str++;
	}
}
