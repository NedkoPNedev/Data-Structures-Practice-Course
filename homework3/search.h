#ifndef _SEARCH_H_
#define _SEARCH_H_

#include "icommand.h"

class Search : public ICommand
{
public:
	void execute();
	string toString();
};

#endif // !_SEARCH_H_

