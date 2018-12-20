#ifndef _PARSER_H_
#define _PARSER_H_

#include <vector>
#include "icommand.h"
#include "bin-tree.h"

class Parser
{
private:
	vector<ICommand*> commandsList;
public:
	Parser();
	~Parser();
	void parse(const string, BinTree&);
};

#endif // !_PARSER_H_



