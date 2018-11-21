#ifndef _CREATE_H_
#define _CREATE_H_

#include "icommand.h"
#include "student.h"

class Create : public ICommand
{
public:
	void execute();
	string toString();
};

#endif // !_CREATE_H_
