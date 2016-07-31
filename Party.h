#ifndef PARTY_H
#define PARTY_H

typedef unsigned int	UINT;

enum Planes	{
			InvalidPlane = -1,
			PlaneAlfa,
			PlaneBravo,
			
			NumPlanes
			};

struct Party
	{
	char *	Name;
	Planes	WhichPlane;
	UINT	Size;
	};

#endif

