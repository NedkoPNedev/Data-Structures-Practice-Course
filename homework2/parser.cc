#include "parser.h"
#include "update.h"
#include "delete.h"
#include "sequential-search.h"

Parser::Parser()
{
	ICommand* updateCommand = new Update();
	commandsList.push_back(updateCommand);
	ICommand* deleteCommand = new Delete();
	commandsList.push_back(deleteCommand);
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




