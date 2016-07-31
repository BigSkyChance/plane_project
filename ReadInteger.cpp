#include <iostream>

using namespace std;

#include "ReadInteger.h"

int ReadInteger ()
	{
	char	c;
	bool	IsNeg;
	int		Num;
	int		NumCharsEntered;

	IsNeg			= false;
	Num				= 0;
	NumCharsEntered	= 0;
	while ((c = cin.get ()) != '\n')		// read a character, stop loop if some hits the enter key (\r when using _getch)
		{
		switch (c)
			{
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
						Num = (Num * 10) + (c - '0');
						NumCharsEntered++;
						break;
			default:;
			}
		}
	return Num;
	}