#ifndef COMMANDS_H
#define COMMANDS_H

enum Commands	{
				InvalidCmd = -1,
				CmdStartup,
				CmdAlfa,
				CmdBravo,
				CmdLounge,
				CmdFly,
				CmdArrive,
				CmdShutdown,

				NumCommands
				};

Commands GetCommand ();

#endif

