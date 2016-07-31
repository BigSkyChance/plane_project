#include <iostream>

using namespace std;

#include "Commands.h"
#include "ReadString.h"

char * CmdStrings [NumCommands] =	{
									"Alfa",
									"Bravo",
									"Lounge",
									"Fly",
									"Arrive",
									"Shutdown"
									};

Commands GetCommand ()
	{
	Commands	i;
	char *		pCmd;

	pCmd	= ReadString ();
	for (i = CmdAlfa; i < NumCommands; i = (Commands) (i + 1))
		if (_strcmpi (pCmd, CmdStrings[i]) == 0)
				{
				delete [] pCmd;
				return i;
				}
			else;
	delete [] pCmd;
	return InvalidCmd;
	}