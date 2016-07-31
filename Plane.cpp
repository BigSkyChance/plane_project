#include <iostream>

using namespace std;

#include <string.h>

#include "Plane.h"
#include "ReadString.h"

char *	PlaneNames []=	{
						"Alfa",
						"Bravo"
						};

Planes GetPlane ()
	{
	char *	WhichPlane;
	Planes	i;

	WhichPlane = ReadString ();
	for (i = PlaneAlfa; i < NumPlanes; i = (Planes) (i + 1))
		if (_strcmpi (WhichPlane, PlaneNames [i]) == 0)
				{
				delete [] WhichPlane;
				return i;
				}
			else;
	delete [] WhichPlane;
	return InvalidPlane;
	}
