#include "parser.h"
#include "insert.h"
#include "delete.h"
#include "find.h"
#include "traverse.h"
#include "bin-tree.h"

Parser::Parser()
{
	ICommand* insertCommand = new Insert();
	commandsList.push_back(insertCommand);
	ICommand* deleteCommand = new Delete();
	commandsList.push_back(deleteCommand);
	ICommand* findCommand = new Find();
	commandsList.push_back(findCommand);
	ICommand* traverseCommand = new Traverse();
	commandsList.push_back(traverseCommand);
}

Parser::~Parser()
{
	for (ICommand* icommand : commandsList)
	{
		delete icommand;
	}
	commandsList.clear();
}

void Parser::parse(const string commmand, BinTree& studentsTree)
{
	for (ICommand* icommand : commandsList)
	{
		if (icommand->toString().find(commmand) != string::npos)
		{
			icommand->execute(studentsTree);
		}
	}
}




