void SPIsl_init()
{
	DDRB &= ~((1<<6)|(1<<8)|(1<<5));
	DDRB |=(1<<7);
	SPCR=(1<<SPE);
}
char SPI_Receive()			
{
	while(!(SPSR & (1<<SPIF)));	
	return(SPDR);			
}
