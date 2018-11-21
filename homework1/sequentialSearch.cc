#include "sequential-search.h"

const string SEQUENTIAL_SEARCH = "sequentialSearch";
const string RECORD_NOT_FOUND_MESSAGE = "Record not found!";
const string FILE_NAME = "StudentsGrades.db";

void SequentialSearch::execute()
{
	ifstream iFile;
	iFile.open(FILE_NAME);
	Student st;
	unsigned long long facultyNumber;
	cin >> facultyNumber;
	bool studentFound = false;
	while (iFile >> st)
	{
		if (st.getFacNum() == facultyNumber)
		{
			cout << st << endl;
			studentFound = true;
			break;
		}
	}
	if (!studentFound)
	{
		cout << RECORD_NOT_FOUND_MESSAGE << endl;
	}
	iFile.close();
}

string SequentialSearch::toString()
{
	return SEQUENTIAL_SEARCH;
}


