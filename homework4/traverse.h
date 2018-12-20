#ifndef _TRAVERSE_H_
#define _TRAVERSE_H_

#include "icommand.h"

class Traverse : public ICommand
{
public:
	void execute(BinTree&);
	string toString();
};

#endif // !_TRAVERSE_H_

