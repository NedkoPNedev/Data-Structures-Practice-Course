#include "application.h"
#include "parser.h"

void Application::startApp()
{
	Parser parser;
	string command;
	do
	{
		cin >> command;
		parser.parse(command);
	} while (command != "exit");
}
