#ifndef _UPDATE_H_
#define _UPDATE_H_

#include "icommand.h"

class Update : public ICommand 
{
public:
	void execute();
	string toString();
};

#endif // !_UPDATE_H_

