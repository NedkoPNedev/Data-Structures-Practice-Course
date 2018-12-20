#ifndef _INSERT_H_
#define _INSERT_H_

#include "icommand.h"

class Insert : public ICommand
{
public:
	void execute(BinTree&);
	string toString();
};

#endif // !_INSERT_H_

