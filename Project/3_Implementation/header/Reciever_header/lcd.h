void lcd_cmd(char);
void lcd_data(char);
void lcd_init();
void lcd_print(char*);
void lcd_cmd(char cmd)
{
	PORTA=cmd;
	PORTB&=~(1<<0);
	PORTB&=~(1<<1);
	PORTB|=(1<<2);
	_delay_ms(10);
	PORTB&=~(1<<2);
	_delay_ms(10);
}
void lcd_data(char data)
{
	PORTA=data;
	PORTB|=(1<<0);
	PORTB&=~(1<<1);
	PORTB|=(1<<2);
	_delay_ms(10);
	PORTB&=~(1<<2);
	_delay_ms(10);
}
void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x80);
	lcd_cmd(0x06);
	lcd_cmd(0x01); 
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
