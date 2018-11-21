#include "parser.h"
#include "create.h"
#include "sequential-search.h"

Parser::Parser()
{
	ICommand* createCommand = new Create();
	commandsList.push_back(createCommand);
	ICommand* sequentialCommand = new SequentialSearch();
	commandsList.push_back(sequentialCommand);
}

Parser::~Parser()
{
	for (ICommand* icommand : commandsList)
	{
		delete icommand;
	}
	commandsList.clear();
}

void Parser::parse(const string commmand)
{
	for (ICommand* icommand : commandsList)
	{
		if (icommand->toString().find(commmand) != string::npos)
		{
			icommand->execute();
		}
	}
}




