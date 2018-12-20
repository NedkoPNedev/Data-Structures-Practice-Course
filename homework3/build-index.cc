#include "build-index.h"
#include "index.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

const string BUILD_INDEX = "buildIndex";
const string INDEX_BUILT = "Index is built!";
const string FILE_NAME = "StudentsGrades.db";
const string DEST_NAME = "FacultyNumber.ids";

void BuildIndex::execute()
{
	ifstream iFile(FILE_NAME);
	Student currStudent;
	unsigned int index = 0;
	unsigned int numStudents = 0;
	vector<Index> studentsIndex;
	while (iFile >> currStudent)
	{
		studentsIndex.push_back(Index(currStudent.getFacNum(), index));
		iFile.ignore();
		index = iFile.tellg();
		numStudents++;
	}
	sort(studentsIndex.begin(), studentsIndex.end());
	ofstream oFile(DEST_NAME, ios::out | ios::binary);
	oFile.write((char*)&numStudents, sizeof(unsigned int));
	for (Index studentIndex : studentsIndex)
	{
		oFile.write((char*)&studentIndex, sizeof(Index));
	}
	iFile.close();
	oFile.close();
	cout << INDEX_BUILT << endl;
}

string BuildIndex::toString()
{
	return BUILD_INDEX;
}


