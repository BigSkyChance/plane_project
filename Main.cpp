#include <iostream>

using namespace std;

#include "Commands.h"
#include "Plane.h"
#include "ReadInteger.h"
#include "ReadString.h"

void main ()
	{
	Plane	Alfa;
	Plane	Bravo;
	Plane	Lounge;
	Party	Temp;

	while (true)	// loop
		{
			cout << "ENTER A COMMAND: ";
		switch (GetCommand ())
			{
			case InvalidCmd:
								cout << "Invalid Command Entered" << endl;
								break;
			case CmdAlfa:
								cout << "Configuring Plane Alfa" << endl;
								cout << "Enter Number of Seats on the Plane: "; // Unsure why professor wants attendant to enter the total number of seats on the plane...
								Alfa.NumSeats		= ReadInteger ();
								Alfa.NumParties		= 0;
								Alfa.NumSeatsEmpty	= Alfa.NumSeats;
								Alfa.Parties		= new Party [Alfa.NumSeats];
								cout << "\nThePlane has been configured and is ready for takeoff, there are currently no parties on the plane" << endl;
								break;
			case CmdBravo:
								cout << "Command Bravo Entered" << endl;
								break;
			case CmdLounge:
								cout << "Command Lounge Entered" << endl;
								break;
			case CmdFly:
								cout << "Command Fly Entered" << endl;
								break;
			case CmdArrive:
								cout << "Arive Entered." << endl;
								cout << "Please enter the plane they wish to board: ";
								Temp.WhichPlane	= GetPlane ();
								cout << "\nPlane: " << Temp.WhichPlane << " \tEnter name: ";
								Temp.Name		= ReadString ();
								cout << "\nName: " << Temp.Name << " \tEnter Size: ";
								Temp.Size		= ReadInteger ();
								cout << Temp.Name << " party of " << Temp.Size << " wishes to board: " << Temp.WhichPlane << endl;
								for (Temp.WhichPlane == 0;;) // This for loop does not work, must figure out how to trigger it.
								// The following should be compared to Alfa.NumSeats
								//	does party fit on the requested plane?
								//			yes -	put them on the plane
								//					subtract size from num empty seats
								//					is num empty seats now zero?
								//							yes - fly plane
								//							no - done with arrive
								//			no -	will it ever fit on the plane
								//							yes -	will they fit in the lounge?
								//											yes -	put them in lounge
								//											no -	party goes home
								//							no -	party goes home
								// Repeat the same as above for plane bravo here
								break;
			case CmdShutdown:
								cout << "Command Shutdown Entered" << endl;
								break;
			default:
								cout << "Internal error, please contact customer support" << endl;
			}
		}
	}