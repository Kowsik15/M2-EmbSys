char keypad();
char keypad()
{
	unsigned char  keys[4][4]={"789/","456X","123-","N0=+"};
	uint8_t col;
	int col_no;
	PORTC=0xFF;
	DDRC=0xF0;
	PORTC=0xEF;
	col=(PINC&0x0F);
	if (col!=0x0F)
	{
		col_no=0;
		_delay_ms(100);
		goto next;
	}
	PORTC=0xDF;
	col=(PINC&0x0F);
	if (col!=0x0F)
	{
		col_no=1;
		_delay_ms(100);
		goto next;
	}
	PORTC=0xBF;
	col=(PINC&0x0F);
	if (col!=0x0F)
	{
		col_no=2;
		_delay_ms(100);
		goto next;
	}
	PORTC=0x7F;
	col=(PINC&0x0F);
	if (col!=0x0F)
	{
		col_no=3;
		_delay_ms(100);
		goto next;
	}
	next : _delay_ms(100);
	if (col==0x0E)
	{
		_delay_ms(100);
		return keys[0][col_no];
	}
	else if (col==0x0D)
	{
		_delay_ms(100);
		return keys[1][col_no];
	}
	else if (col==0x0B)
	{
		_delay_ms(100);
		return keys[2][col_no];
	}
	else if (col==0x07)
	{
		_delay_ms(100);
		return keys[3][col_no];
	}
}
