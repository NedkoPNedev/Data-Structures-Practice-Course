#ifndef _DELETE_H_
#define _DELETE_H_

#include "icommand.h"

class Delete : public ICommand
{
public:
	void execute();
	string toString();
};

#endif // !_DELETE_H_

