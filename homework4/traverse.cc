#include "traverse.h"

const string TRAVERSE = "traverseInorder";

void Traverse::execute(BinTree& studentsTree)
{
	studentsTree.traverseInorder();
}

string Traverse::toString()
{
	return TRAVERSE;
}
