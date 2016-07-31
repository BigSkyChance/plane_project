#include <iostream>

using namespace std;

#include <ctype.h>		// needed to use isspace below
#include <memory.h>

#include "ReadString.h"

void SkipSpaces ()
	{
	char	c;

	while (isspace (c = cin.get ()));
	cin.putback (c);
	}

char * ReadString ()
	{
	const	int		FirstGuess (50);
			char	c;
			char *	pChars;
			char *	pTemp;
			int		MaxNumChars;
			int		NumCharsEntered;

	MaxNumChars		= FirstGuess;
	NumCharsEntered	= 0;
	pChars			= new char [MaxNumChars + 1];
	SkipSpaces ();
	while (!isspace (c = cin.get ()))
		{
		pChars [NumCharsEntered++]	= c;
		if (NumCharsEntered >= MaxNumChars)
				{
				MaxNumChars	+= FirstGuess;
				pTemp		= new char [MaxNumChars + 1];
				memcpy (pTemp, pChars, NumCharsEntered);
				delete [] pChars;
				pChars		= pTemp;
				}
			else;
		}
	pChars [NumCharsEntered] = '\0';
	return pChars;
	}