void SPImstr_init()
{
	DDRB |= (1<<PB4)|(1<<PB5)|(1<<PB7);
	DDRB &= ~(1<<PB6);	
	PORTB |= (1<<PB4);	
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	
	SPSR &= ~(1<<SPI2X);	
}
void SPI_write(char data)
{
	char flush_buffer;
	SPDR=data;
	while (!(SPSR & (1<<SPIF)));
	flush_buffer=SPDR;
}
char SPI_read()
{
	SPDR=0xFF;
	while(!(SPSR & (1<<SPIF)));
	return(SPDR);
}
