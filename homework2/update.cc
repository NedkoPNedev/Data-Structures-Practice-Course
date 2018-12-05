#include "update.h"

const string UPDATE = "update";
const string RECORD_NOT_FOUND = "Record not found!";
const string RECORD_SAVED = "Record saved!";
const string FILE_NAME = "StudentsGrades.db";

void Update::execute()
{
	fstream file(FILE_NAME, ios::in | ios::out);
	bool isFound = false;
	unsigned long long facNum;
	unsigned short newGrade;
	Student st;
	streamoff offset = -1;
	file.seekg(0, ios::beg);

	cin >> facNum >> newGrade;

	while (file >> st)
	{
		if (st.getFacNum() == facNum)
		{
			isFound = true;
			file.seekp(file.tellg() + offset, ios::beg);
			file << newGrade;
			break;
		}
	}
	if (isFound) 
	{
		cout << RECORD_SAVED << endl;
	} 
	else
	{
		cout << RECORD_NOT_FOUND << endl;
	}
	file.close();
}

string Update::toString()
{
	return UPDATE;
}
