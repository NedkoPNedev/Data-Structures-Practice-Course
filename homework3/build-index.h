#ifndef _BUILD_INDEX_H_
#define _BUILD_INDEX_H_

#include "icommand.h"

class BuildIndex : public ICommand
{
public:
	void execute();
	string toString();
};

#endif // !_BUILD_INDEX_H_

