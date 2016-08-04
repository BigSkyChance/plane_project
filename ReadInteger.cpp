#include <iostream>
#include <conio.h>
#include <ctype.h>

using namespace std;

#include "ReadInteger.h"

static void BackSpace()	// static means this function can only be used by other functions in this file
{
	_putch('\b');
	_putch(' ');
}

int ReadInteger()
{
	char	c;
	bool	Digits(false);
	int		Num(0);
	int		Sign(0);

	while (!isspace(c = static_cast <char> (_getch())))
	{
		switch (c)
		{
		case '+':
		case '\b':
			if (Digits)
			{
				BackSpace();
				Num /= 10;
				if (Num == 0)
					Digits = false;
				else;
			}
			else
				if (Sign != 0)
				{
					BackSpace();
					Sign = 0;
				}
				else
					c = '\a';
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			Digits = true;
			Num = (Num * 10) + (c - '0');
			break;
		default:
			c = '\a';
		}
		_putch(c);
	}
	if (c == '\r')
		c = '\n';
	else;
	_putch(c);
	if (Sign < 0)
		Num = -Num;
	else;
	return Num;
}