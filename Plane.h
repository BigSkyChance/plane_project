#ifndef PLANE_H
#define PLANE_H

#include "Party.h"

struct Plane
	{
	UINT	NumSeats;
	UINT	NumSeatsEmpty;
	UINT	NumParties;
	Party *	Parties;
	};

Planes	GetPlane	();

#endif

