#include "find.h"

const string FIND = "find";
const string RECORD_NOT_FOUND = "Record not found!";

void Find::execute(BinTree& studentsTree)
{
	unsigned long long facNum;
	cin >> facNum;
	Student st = studentsTree.findElem(facNum);
	if (st.getFirstName() == "" && st.getLastName() == "")
	{
		cout << RECORD_NOT_FOUND << endl;
		return;
	}
	cout << st << endl;
}

string Find::toString()
{
	return FIND;
}
