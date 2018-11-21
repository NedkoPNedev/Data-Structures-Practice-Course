#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_

#include <iostream>
#include <fstream>
#include "student.h"

using namespace std;

class ICommand
{
public:
	virtual void execute() = 0;
	virtual string toString() = 0;
};

#endif // !_ICOMMAND_H_
