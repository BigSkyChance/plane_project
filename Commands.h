#ifndef COMMANDS_H
#define COMMANDS_H

enum Commands	{
				InvalidCmd = -1,
				CmdStartup,
				CmdHelp,
				CmdHangar,
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

