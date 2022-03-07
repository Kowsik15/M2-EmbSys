void lcd_cmd(char);
void lcd_data(char);
void lcd_init();
void lcd_print(char*);
void lcd_cmd(char cmd)
{
	PORTA=cmd;
	PORTC&=~(1<<0);//makes RS pin low
	PORTC&=~(1<<1);//makes RW pin low
	PORTC|=(1<<2);//makes EN pin high to send a pulse
	_delay_ms(10);
	PORTC&=~(1<<2);//makes EN pin low to end the pulse
	_delay_ms(10);
}
void lcd_data(char data)
{
	PORTA=data;
	PORTC|=(1<<0);//makes RS pin high
	PORTC&=~(1<<1);//makes RW pin low
	PORTC|=(1<<2);//makes EN pin high to send a pulse
	_delay_ms(10);
	PORTC&=~(1<<2);//makes EN pin low to end the pulse
	_delay_ms(10);
}
void lcd_init()
{
	lcd_cmd(0x38);//decides the bit mode of operation
	lcd_cmd(0x0E);//LCD on cursor on
	lcd_cmd(0x80);//forces cursor on first row first column
	lcd_cmd(0x06);//auto increment of cursor
	lcd_cmd(0x01);//to clear the display during each initialization 
}
void lcd_print(char*str)
{
	int c=0;
	while (*str!='\0')
	{lcd_data(*str);
	str++;
	c++;
	if (c==16){
	lcd_cmd(0xC0);
	lcd_cmd(0x06);}
}
}
