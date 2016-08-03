#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "Commands.h"
#include "Plane.h"
#include "ReadInteger.h"
#include "ReadString.h"
#include "Party.h"

void main ()
	{
	Plane	Alfa;
	Plane	Bravo;
	Plane	Lounge;
	Party	Temp;
	UINT	z = 0;
	UINT	a = 0;
	UINT	b = 0;
	UINT	l = 0;
	UINT	i;
	UINT	j;

	cout << "Welome to MasterTicket Version 3.0, built for Tree Top Airways!" << endl;
	cout << "Please enter 'Startup' to initialize planes.\nEnter 'Help' for a list of commands." << endl;
	while (true)	
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
								cout << "This airports' Lounge has 50 seats" << endl;
								Lounge.NumSeats		= 50;
								Lounge.NumSeatsEmpty = Lounge.NumSeats;
								Lounge.NumParties	 = 0;
								Lounge.Parties		 = new Party[Lounge.NumSeats];
								break;
			case CmdHelp:
								cout << "Here's a list of Commands!";
								cout << "\nStartup, This should only be entered at the start of the day to configure Plane Alfa & Bravo!";
								cout << "\nHangar, This is if theres a change in aircraft size, only to be used for empty planes!";
								cout << "\nAlfa, This will display the current status of plane Alfa.";
								cout << "\nBravo, This will display the current status of plane Bravo";
								cout << "\nLounge, This will show the curren status of the Airport Lounge.";
								cout << "\nFly, This will start the manual process of takeoff, this will fly the plane before boarding the lounge!";
								cout << "\nArrive, Your most important command! Use this to gather customer information.";
								cout << "\nShutdown, Shuts down ticketing terminal. Passengers will still be served in the order they arrived!";
								cout << "\nEnter 'Help' at any time to display this message";
								break;
			case CmdHangar: // this command is to edit the Number of Seats on the planes!
								cout << "Only use this in case of a plane change!" << endl;
								cout << "Accessing the hangar, which plane would you like to change? ";
								Temp.WhichPlane = GetPlane();
								if (Temp.WhichPlane == 0)
								{
									cout << "You can now choose a larger or smaller aircraft to function as Plane Alfa" << endl;
									if (Alfa.NumParties > 0)
									{
										cout << "This plane already has passengers, please fly Alfa before changing aircraft." << endl;
										break;
									}
									delete[] Alfa.Parties;
									cout << "Enter Number of Seats on Alfa: ";
									Alfa.NumSeats = ReadInteger();
									Alfa.NumParties = 0;
									Alfa.NumSeatsEmpty = Alfa.NumSeats;
									Alfa.Parties = new Party[Alfa.NumSeats];
									break;
								}
								if (Temp.WhichPlane == 1)
								{
									cout << "You can now choose a larger or smaller aircraft to function as Plane Bravo" << endl;
									if (Bravo.NumParties > 0)
									{
										cout << "This plane already has passengers, please fly Bravo before changing aircraft." << endl;
										break;
									}
									delete[] Bravo.Parties;
									cout << "Enter Number of Seats on Bravo: ";
									Bravo.NumSeats = ReadInteger();
									Bravo.NumParties = 0;
									Bravo.NumSeatsEmpty = Bravo.NumSeats;
									Bravo.Parties = new Party[Bravo.NumSeats];
									break;
								}
								if (Temp.WhichPlane == -1)
								{
									cout << "Invalid Plane" << endl;
									break;
								}
			case CmdAlfa:
								cout << "Status of Plane Alfa" << endl;
								cout << "Number of Seats: " << Alfa.NumSeats << endl;
								cout << "Number of Empty Seats: " << Alfa.NumSeatsEmpty << endl;
								cout << "Number of Parties: " << Alfa.NumParties << endl;
								for (z = 0; z < Alfa.NumParties; z++)
								{
									cout << Alfa.Parties[z].Name << " party of " << Alfa.Parties[z].Size << endl;
								}
								break;
			case CmdBravo:
								cout << "Status of Plane Bravo" << endl;
								cout << "Number of Seats: " << Bravo.NumSeats << endl;
								cout << "Number of Empty Seats: " << Bravo.NumSeatsEmpty << endl;
								cout << "Number of Parties: " << Bravo.NumParties << endl;
								for (z = 0; z < Bravo.NumParties; z++)
								{
									cout << Bravo.Parties[z].Name << " party of " << Bravo.Parties[z].Size << endl;
								}
								break;
			case CmdLounge:
								cout << "Status of the Lounge" << endl;
								cout << "Number of chairs in lounge: " << Lounge.NumSeats << endl;
								cout << "Number of chairs left: " << Lounge.NumSeatsEmpty << endl;
								cout << "Number of Parties: " << Lounge.NumParties << endl;
								for (z = 0; z < Lounge.NumParties; z++)
								{
									cout << Lounge.Parties[z].Name << " party of " << Lounge.Parties[z].Size;
									cout << " waiting for plane: ";
									if (Lounge.Parties[z].WhichPlane == 0)
										cout << "alfa" << endl;
									if (Lounge.Parties[z].WhichPlane == 1)
										cout << "bravo" << endl;
								}
								break;
			case CmdFly:
								cout << "Command Fly Entered" << endl;
								cout << "Which plane would you like to fly? ";
								Temp.WhichPlane = GetPlane();
								if (Temp.WhichPlane == -1)
								{
									cout << "Can't fly a plane that's not in the hangar." << endl;
									break;
								}
								if (Temp.WhichPlane == 0)
								{
									cout << "Alfa is cleared for takeoff" << endl;
									cout << "Parties on this flight.." << endl;
									for (z = 0; z < Alfa.NumParties; z++)
									{
										cout << Alfa.Parties[z].Name << " party of " << Alfa.Parties[z].Size << endl;
									}
									Alfa.NumSeatsEmpty = Alfa.NumSeats;
									Alfa.NumParties = 0;
									a = 0;
									delete[] Alfa.Parties;
									Alfa.Parties = new Party[Alfa.NumSeats];
									for (i = 0; i < Lounge.NumParties; i++) // Load waiting customers
									{
										if ((Lounge.Parties[i].WhichPlane == 0) && (Lounge.Parties[i].Size <= Alfa.NumSeatsEmpty))
										{
											Alfa.NumSeatsEmpty = Alfa.NumSeatsEmpty - Lounge.Parties[i].Size;
											Alfa.NumParties++;
											Alfa.Parties[a] = Lounge.Parties[i];
											a++;
											Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty + Lounge.Parties[i].Size;
											l--;
											for (j = i + 1; j < Lounge.NumParties; j++)
											{
												Lounge.Parties[i] = Lounge.Parties[j];
											}
										}
									}
									Lounge.NumParties = Lounge.NumParties - a;
									break;
								}
								if (Temp.WhichPlane == 1)
								{
									cout << "Bravo is cleared for takeoff" << endl;
									cout << "List of Parties on this flight.." << endl;
									for (z = 0; z < Bravo.NumParties; z++)
									{
										cout << Bravo.Parties[z].Name << " party of " << Bravo.Parties[z].Size << endl;
									}
									Bravo.NumSeatsEmpty = Bravo.NumSeats;
									Bravo.NumParties = 0;
									delete[] Bravo.Parties;
									Bravo.Parties = new Party[Bravo.NumSeats];
									b = 0;
									cout << "Bravo has flown at the speed of light and has returned... Loading the parties in Lounge." << endl;
									for (i = 0; i < Lounge.NumParties; i++) // Load Customers that are waiting.
									{
										if ((Lounge.Parties[i].WhichPlane == 1) && (Lounge.Parties[i].Size <= Bravo.NumSeatsEmpty))
										{
											Bravo.NumSeatsEmpty = Bravo.NumSeatsEmpty - Lounge.Parties[i].Size;
											Bravo.NumParties++;
											Bravo.Parties[b] = Lounge.Parties[i];
											b++;
											Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty + Lounge.Parties[i].Size;
											l--;
											for (j = i + 1; j < Lounge.NumParties; j++)
											{
												Lounge.Parties[i] = Lounge.Parties[j];
											}
										}
									}
									Lounge.NumParties = Lounge.NumParties - b;
									break;
								}
								else
									cout << "Invalid plane" << endl;
								break;
			case CmdArrive:
								cout << "Arrive Entered." << endl;
								cout << "Please enter the plane they wish to board: ";
								Temp.WhichPlane	= GetPlane ();
								if (Temp.WhichPlane == -1) // -1 == Invalid Plane
								{
									cout << "We don't have that plane in the hangar" << endl;
									break;
								}
								cout << "Enter name: ";
								Temp.Name		= ReadString ();
								cout << "Name: " << Temp.Name << " \tEnter Size: ";
								Temp.Size		= ReadInteger ();
								cout << Temp.Name << " party of " << Temp.Size << " wishes to board: ";
								if (Temp.WhichPlane == 0) // Alfa Boarding Process
								{
									cout << " Plane Alfa" << endl;
									if (Temp.Size <= Alfa.NumSeatsEmpty)
									{
										Alfa.NumSeatsEmpty = Alfa.NumSeatsEmpty - Temp.Size;
										Alfa.NumParties++;
										Alfa.Parties[a] = Temp;
										a++;
										cout << Temp.Name << " is cleared to board plane Alfa, there are " << Alfa.NumSeatsEmpty << " seats left" << endl;
										if (Alfa.NumSeatsEmpty == 0)
										{
											cout << "Alfa is full, and is cleared for takeoff..." << endl;
											cout << "Parties on this flight.." << endl;
											for (z = 0; z < Alfa.NumParties; z++)
											{
												cout << Alfa.Parties[z].Name << " party of " << Alfa.Parties[z].Size << endl;
											}
											Alfa.NumSeatsEmpty = Alfa.NumSeats;
											Alfa.NumParties = 0;
											delete[] Alfa.Parties;
											Alfa.Parties = new Party[Alfa.NumSeats];
											a = 0;
											cout << "Alfa has flown at the speed of light and has returned... Loading the parties in Lounge." << endl;
											for (i = 0; i < Lounge.NumParties; i++)
											{
												if ((Lounge.Parties[i].WhichPlane == 0) && (Lounge.Parties[i].Size <= Alfa.NumSeatsEmpty))
												{
													Alfa.NumSeatsEmpty = Alfa.NumSeatsEmpty - Lounge.Parties[i].Size;
													Alfa.NumParties++;
													Alfa.Parties[a] = Lounge.Parties[i];
													a++;
													Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty + Lounge.Parties[i].Size;
													l--;
													for (j = i + 1; j < Lounge.NumParties; j++)
													{
														Lounge.Parties[j - 1] = Lounge.Parties[j];
													}
												}
											}
											Lounge.NumParties = Lounge.NumParties - a;
											break;
										}
										else
											break;
									}
									else
										if (Temp.Size > Alfa.NumSeats)
										{
											cout << "This party is too big for this plane, please direct customer to our private jet service." << endl;
											break;
										}
										if (Temp.Size <= Lounge.NumSeatsEmpty)
										{
											cout << "There's not enough seats on this flight, sending to lounge." << endl;
											Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty - Temp.Size;
											Lounge.NumParties++;
											Lounge.Parties[l] = Temp;
											l++;
											break;
										}
											else
											{
												cout << "There is no room on the flight, or in the lounge, unfortunately they must go home" << endl;
												break;
											}
									break;
								}
								if (Temp.WhichPlane == 1) // Plane Bravo Boarding Process.
								{
									cout << " Plane Bravo" << endl;
									if (Temp.Size <= Bravo.NumSeatsEmpty)
									{
										Bravo.NumSeatsEmpty = Bravo.NumSeatsEmpty - Temp.Size;
										Bravo.NumParties++;
										Bravo.Parties[b] = Temp;
										b++;
										cout << Temp.Name << " is cleared to board plane Bravo, there are " << Bravo.NumSeatsEmpty << " seats left" << endl;
										if (Bravo.NumSeatsEmpty == 0)
										{
											cout << "Bravo is full, and is cleared for takeoff" << endl;
											cout << "List of Parties on this flight.." << endl;
											for (z = 0; z < Bravo.NumParties; z++)
											{
												cout << Bravo.Parties[z].Name << " party of " << Bravo.Parties[z].Size << endl;
											}
											Bravo.NumSeatsEmpty = Bravo.NumSeats;
											Bravo.NumParties = 0;
											delete[] Bravo.Parties;
											Bravo.Parties = new Party[Bravo.NumSeats];
											b = 0;
											cout << "Bravo has flown at the speed of light and has returned... Loading the parties in Lounge." << endl;
											for (i = 0; i < Lounge.NumParties; i++) // Gets People waiting for Bravo out of the Lounge.
											{
												if ((Lounge.Parties[i].WhichPlane == 1) && (Lounge.Parties[i].Size <= Bravo.NumSeatsEmpty))
												{
													Bravo.NumSeatsEmpty = Bravo.NumSeatsEmpty - Lounge.Parties[i].Size;
													Bravo.NumParties++;
													Bravo.Parties[b] = Lounge.Parties[i];
													b++;
													Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty + Lounge.Parties[i].Size;
													l--;
													for (j = i + 1; j < Lounge.NumParties; j++)
													{
														Lounge.Parties[i] = Lounge.Parties[j];
													}
												}
											}
											Lounge.NumParties = Lounge.NumParties - b;
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
												Lounge.Parties[l] = Temp;
												l++;
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
								cout << "Shutting down...\n";
								cout << "The Program will continue to direct customers to there gates until all have boarded." << endl;
								if (Lounge.NumParties == 0 && Alfa.NumParties == 0 && Bravo.NumParties == 0) 
								{ // If This is true then we don't need to do the do loop below.
									cout << "The Airport and Airplanes are empty. SHUTTING DOWN TERMINAL\n" << endl;
									exit(0);
								}
								do // This is the loop that will keep boarding and flying customers until they are all gone.
								{
									cout << "Boarding Call for Customers waiting for Alfa, boarding in order of arrival...\n" << endl;
									for (i = 0; i < Lounge.NumParties; i++)
									{
										if ((Lounge.Parties[i].WhichPlane == 0) && (Lounge.Parties[i].Size <= Alfa.NumSeatsEmpty))
										{
											Alfa.NumSeatsEmpty = Alfa.NumSeatsEmpty - Lounge.Parties[i].Size;
											Alfa.NumParties++;
											Alfa.Parties[a] = Lounge.Parties[i];
											a++;
											Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty + Lounge.Parties[i].Size;
											l--;
											for (j = i + 1; j < Lounge.NumParties; j++)
											{
												Lounge.Parties[j - 1] = Lounge.Parties[j];
											}
										}
									} // Boarded all the customers waiting for Alfa.
									cout << "Boarding Call for Customers waiting for Bravo, boarding in order of arrival...\n" << endl;
									for (i = 0; i < Lounge.NumParties; i++)
									{
										if ((Lounge.Parties[i].WhichPlane == 1) && (Lounge.Parties[i].Size <= Bravo.NumSeatsEmpty))
										{
											Bravo.NumSeatsEmpty = Bravo.NumSeatsEmpty - Lounge.Parties[i].Size;
											Bravo.NumParties++;
											Bravo.Parties[b] = Lounge.Parties[i];
											b++;
											Lounge.NumSeatsEmpty = Lounge.NumSeatsEmpty + Lounge.Parties[i].Size;
											l--;
											for (j = i + 1; j < Lounge.NumParties; j++)
											{
												Lounge.Parties[j - 1] = Lounge.Parties[j];
											}
										}
									} // Boarded all Parties waiting for Bravo

									Lounge.NumParties = Lounge.NumParties - (a + b); // This takes away the ammount of parties
									// that were boarded from parties in lounge.

									if (Alfa.NumParties > 0) // Keep flying alfa if there's parties on it.
									{
										cout << "Alfa is cleared for takeoff...\n" << endl;
										cout << "Parties on this flight.." << endl;
										for (z = 0; z < Alfa.NumParties; z++)
										{
											cout << Alfa.Parties[z].Name << " party of " << Alfa.Parties[z].Size << endl;
										}
										Alfa.NumSeatsEmpty = Alfa.NumSeats;
										Alfa.NumParties = 0;
										delete[] Alfa.Parties;
										Alfa.Parties = new Party[Alfa.NumSeats];
										a = 0;
										cout << "Alfa has flown at the speed of light and has returned..." << endl;
									}
									
									if (Bravo.NumParties > 0) // Keep flying Bravo if there's parties on it.
									{
										cout << "Bravo is cleared for takeoff...\n" << endl;
										cout << "List of Parties on this flight.." << endl;
										for (z = 0; z < Bravo.NumParties; z++)
										{
											cout << Bravo.Parties[z].Name << " party of " << Bravo.Parties[z].Size << endl;
										}
										Bravo.NumSeatsEmpty = Bravo.NumSeats;
										Bravo.NumParties = 0;
										delete[] Bravo.Parties;
										Bravo.Parties = new Party[Bravo.NumSeats];
										b = 0;
										cout << "Bravo has flown at the speed of light and has returned..." << endl;
									}
								} while (Alfa.NumParties != 0 && Bravo.NumParties != 0 && Lounge.NumParties != 0); // Go until everything is empty.

								cout << "\nAll customers have been served, contact Chancellor Griffin to congratulate him on a great semester!\n" << endl;
								exit(0);			
								break;
			default:
								cout << "Internal error, please contact customer support" << endl;
			}
		}
	}
