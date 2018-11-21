#include "create.h"

const string CREATE = "create";
const string RECORD_SAVED_MESSAGE = "Record saved!";
const string FILE_NAME = "StudentsGrades.db";

void Create::execute()
{
	ofstream oFile;
	oFile.open(FILE_NAME, ios::out | ios::app);
	Student st;
	cin >> st;
	oFile << st;
	cout << RECORD_SAVED_MESSAGE << endl;
	oFile.close();
}

string Create::toString()
{
	return CREATE;
}
