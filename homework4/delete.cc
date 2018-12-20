#include "delete.h"

const string DELETE = "delete";
const string RECORD_NOT_FOUND = "Record not found!";
const string RECORD_DELETED = "Record deleted!";

void Delete::execute(BinTree& studentsTree)
{
	unsigned long long facNum;
	cin >> facNum;
	if (studentsTree.deleteElem(facNum))
	{
		cout << RECORD_DELETED << endl;
		return;
	}
	cout << RECORD_NOT_FOUND << endl;
}

string Delete::toString()
{
	return DELETE;
}


