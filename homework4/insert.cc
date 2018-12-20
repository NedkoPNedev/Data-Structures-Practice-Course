#include "insert.h"
#include <iostream>
using namespace std;

const string INSERT = "insert";
const string RECORD_INSERTED = "Record inserted!";

void Insert::execute(BinTree& studentsTree)
{
	Student st;
	cin >> st;
	studentsTree.insertElem(st);
	cout << RECORD_INSERTED << endl;
}

string Insert::toString()
{
	return INSERT;
}
