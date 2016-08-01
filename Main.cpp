#include <iostream>
#include <string>

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

	cout << "Welome to MasterTicket Version 1.0" << endl;
	cout << "Please enter 'Startup' to initialize planes" << endl;
	while (true)	// loop
		{
			cout << "\nENTER A COMMAND: ";
		switch (GetCommand ())
			{
			case InvalidCmd:
								cout << "Invalid Command Entered" << endl;
								break;
			case CmdStartup:
								cout << "Starting up MasterTicket" << endl;
								cout << "Enter Number of Seats on Alfa: ";
								Alfa.NumSeats		= ReadInteger();
								Alfa.NumParties		= 0;
								Alfa.NumSeatsEmpty	= Alfa.NumSeats;
								Alfa.Parties		= new Party[Alfa.NumSeats];
								cout << "Enter Number of Seats on Bravo: ";
								Bravo.NumSeats		= ReadInteger();
								Bravo.NumParties	= 0;
								Bravo.NumSeatsEmpty = Bravo.NumSeats;
								Bravo.Parties		= new Party[Bravo.NumSeats];
								cout << "Planes are set up!" << endl;
								Lounge.NumSeats		= 50;
								Lounge.NumSeatsEmpty = Lounge.NumSeats;
								Lounge.NumParties	 = 0;
								break;

			case CmdAlfa:
								cout << "Status of Plane Alfa" << endl;
								cout << "Number of Seats: " << Alfa.NumSeats << endl;
								cout << "Number of Empty Seats: " << Alfa.NumSeatsEmpty << endl;
								cout << "Number of Parties: " << Alfa.NumParties << endl;
								// display parties on the plane
								break;
			case CmdBravo:
								cout << "Status of Plane Bravo" << endl;
								cout << "Number of Seats: " << Bravo.NumSeats << endl;
								cout << "Number of Empty Seats: " << Bravo.NumSeatsEmpty << endl;
								cout << "Number of Parties: " << Bravo.NumParties << endl;
								//display parties on plane
								break;
			case CmdLounge:
								cout << "Command Lounge Entered" << endl;
								break;
			case CmdFly:
								cout << "Command Fly Entered" << endl;
								cout << "Which plane would you like to fly? ";
								Temp.WhichPlane = GetPlane();
								cout << "\n";
								if (Temp.WhichPlane == 0)
								{
									cout << "Alfa is cleared for takeoff" << endl;
									Alfa.NumSeatsEmpty = Alfa.NumSeats;
									Alfa.NumParties = 0;
									// delete party array
									break;
								}
								if (Temp.WhichPlane == 1)
								{
									cout << "Bravo is cleared for takeoff" << endl;
									Bravo.NumSeatsEmpty = Bravo.NumSeats;
									Bravo.NumParties = 0;
									// delete party array
									break;
								}
								else
									cout << "Invalid plane" << endl;
								break;
			case CmdArrive:
								cout << "Arrive Entered." << endl;
								cout << "Please enter the plane they wish to board: ";
								Temp.WhichPlane	= GetPlane ();
								cout << "Enter name: ";
								Temp.Name		= ReadString ();
								cout << "Name: " << Temp.Name << " \tEnter Size: ";
								Temp.Size		= ReadInteger ();
								cout << Temp.Name << " party of " << Temp.Size << " wishes to board: ";
								if (Temp.WhichPlane == 0)
								{
									cout << " Plane Alfa" << endl;
									if (Temp.Size <= Alfa.NumSeatsEmpty)
									{
										Alfa.NumSeatsEmpty = Alfa.NumSeatsEmpty - Temp.Size; // Takes away those seats
										Alfa.NumParties++;
										// How to store the name into an array?
										cout << Temp.Name << " is cleared to board plane Alfa, there are " << Alfa.NumSeatsEmpty << " seats left" << endl;
										if (Alfa.NumSeatsEmpty == 0)
										{
											cout << "TIME FOR TAKEOFF" << endl;
											break;
										}
										else
											break;
									}
									else
										if (Temp.Size > Alfa.NumSeats)
										{
											cout << "This party is too big for this plane, tell customer too bad." << endl;
											break;
										}
										if (Temp.Size <= Lounge.NumSeatsEmpty)
										{
											cout << "There's not enough seats on this flight, sending to lounge." << endl;
											Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty - Temp.Size;
											Lounge.NumParties++;
											// Store name in array for that party
											break;
										}
											else
											{
												cout << "There is no room on the flight, or in the lounge, unfortunately they must go home" << endl;
												break;
											}
									break;
								}
								if (Temp.WhichPlane == 1)
								{
									cout << " Plane Bravo" << endl;
									if (Temp.Size <= Bravo.NumSeatsEmpty)
									{
										Bravo.NumSeatsEmpty = Bravo.NumSeatsEmpty - Temp.Size; // Takes away those seats
										Bravo.NumParties++;
										// How to store the name into an array?
										cout << Temp.Name << " is cleared to board plane Bravo, there are " << Bravo.NumSeatsEmpty << " seats left" << endl;
										if (Bravo.NumSeatsEmpty == 0)
										{
											cout << "TIME FOR TAKEOFF" << endl;
											break;
										}
										else
											break;
									}
									else
										if (Temp.Size > Bravo.NumSeats)
										{
											cout << "This party is too big for this plane, tell customer too bad." << endl;
											break;
										}
										else
											if (Temp.Size <= Lounge.NumSeatsEmpty)
											{
												cout << "There's not enough seats on this flight, sending to lounge." << endl;
												Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty - Temp.Size;
												Lounge.NumParties++;
												// Store name in array for that party
												break;
											}
											else
											{
												cout << "There is no room on the flight, or in the lounge, unfortunately they must go home" << endl;
												break;
											}
								}
								else
									cout << "Invalid plane" << endl;
								break;
			case CmdShutdown:
								cout << "Command Shutdown Entered" << endl;
								// Closes the airport, but possibly load the remaining passengers from the lounge onto planes that could fit them?
								break;
			default:
								cout << "Internal error, please contact customer support" << endl;
			}
		}
	}