#include "application.h"
#include "parser.h"

const string END_OF_PROGRAM = "exit";

void Application::startApp()
{
	Parser parser;
	string command;
	do
	{
		cin >> command;
		parser.parse(command);
	} while (command != END_OF_PROGRAM);
}

