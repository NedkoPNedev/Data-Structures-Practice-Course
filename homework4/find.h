#ifndef _FIND_H_
#define _FIND_H_

#include "icommand.h"

class Find : public ICommand
{
public:
	void execute(BinTree&);
	string toString();
};

#endif // !_FIND_H_

