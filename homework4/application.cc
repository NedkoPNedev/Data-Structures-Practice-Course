#include "application.h"
#include "parser.h"
#include "bin-tree.h"

const string END_OF_PROGRAM = "exit";

void Application::startApp()
{
	Parser parser;
	BinTree studentsTree;
	string command;
	do
	{
		cin >> command;
		parser.parse(command, studentsTree);
	} while (command != END_OF_PROGRAM);
}

