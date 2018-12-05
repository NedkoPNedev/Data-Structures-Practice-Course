#include "delete.h"
#include <stdio.h>

const string DELETE = "delete";
const string RECORD_NOT_FOUND = "Record not found!";
const string RECORD_DELETED = "Record deleted!";
const char* FILE_NAME = "StudentsGrades.db";
const char* TEMP_FILE_NAME = "tempFile.db";

void Delete::execute()
{
	ifstream fin(FILE_NAME, ios::in);
	ofstream fout(TEMP_FILE_NAME, ios::out);
	Student st;
	unsigned long long facNum;
	bool isFound = false;

	cin >> facNum;
	while (fin >> st)
	{
		if (st.getFacNum() == facNum) { isFound = true; }
		else { fout << st << endl; }
	}
	if (isFound)
	{
		cout << RECORD_DELETED << endl;
	}
	else 
	{
		cout << RECORD_NOT_FOUND << endl;
	}
	fin.close();
	fout.close();
	remove(FILE_NAME);
	rename(TEMP_FILE_NAME, FILE_NAME);
}

string Delete::toString()
{
	return DELETE;
}


