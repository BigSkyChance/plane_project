# plane_project
C++ Final Semester project, Created by Chancellor Griffin

COSC1436.3S1
SEMESTER PROJECT

ASSIGNMENT:

Your employer has determined a market for a simple airline ticketing system for a very simple airline (Tree Top Airways - TTA). The airline only has two aircraft, named ALFA and BRAVO. Initially, the ticket system will determine the number of seats on each plane and in the lounge. The ticketing system is to be installed at the airport ticket booth for the airline and will operate under the following rules:

1)	If a party arrives and there is enough room on the plane requested, they are allowed to board and a message to that effect is printed.

2)	If a party arrives and there is not enough room on the plane requested due to people already being on the plane, the party is directed to wait in the lounge and a message to that effect is printed.

3)	If a party arrives and there is not enough room on the plane requested because the plane is just too small, the party is turned away and a message to that effect is printed.

4)	If a party is directed to the lounge and there is not enough room in the lounge, the party is turned away.

5)	Parties are never split.

6)	A plane will fly whenever it becomes full and a list of all parties on board will be printed.

7)	A plane may fly upon a command from the ticket clerk. Again a list of all parties on board will be printed.

8)	The ticket clerk will enter when a plane flys and upon the return of the plane the system will move people from the lounge to the plane in the order in which the parties arrived, but will skip parties that cannot fit and search for those which can fit. A list of those parties boarding the plane will be printed.

9)	When the airline shuts down for the night, the airplanes will continue to fly and return (without the ticket clerk performing any action) until all parties in the lounge have flown with appropriate messages being printed.

10)	Party names do not have a maximum size so they must be handled as C-type strings and dynamically allocated.

 
The commands the system will accept are the following:

ALFA		<size>
BRAVO	<size>
LOUNGE	<size>
FLY		<airplane>
ARRIVE	<airplane> <party> <size>
SHUTDOWN

where:	<airplane> is either ALFA or BRAVO.
		<party> is a name of unlimited length.
		<size> is an integer number

Fields in the input will be separated by some amount of whitespace.

The ticket clerk is a terrible typist.

DUE: 4 August 2016
 
1)	An electronic copy of the .cpp and .h files in the project folder as created by Visual Studio. This will be emailed to the instructor with the subject line “COSC 1436.3S1 – Project”.
2)	If you wish any feedback on your work, turn in a printed listing of the .cpp and .h files that you created.


