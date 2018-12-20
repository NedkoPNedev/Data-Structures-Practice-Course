#include "parser.h"
#include "sequential-search.h"
#include "build-index.h"
#include "search.h"

Parser::Parser()
{
	ICommand* buildCommand = new BuildIndex();
	commandsList.push_back(buildCommand);
	ICommand* searchCommand = new Search();
	commandsList.push_back(searchCommand);
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




