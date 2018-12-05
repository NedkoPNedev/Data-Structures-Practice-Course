#ifndef _SEQUENTIAL_SEARCH_H_
#define _SEQUENTIAL_SEARCH_H_

#include "icommand.h"

class SequentialSearch : public ICommand
{
public:
	void execute();
	string toString();
};
#endif // !_SEQUENTIAL_SEARCH_H_


