#include "search.h"
#include "build-index.h"
#include "index.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

const string SEARCH = "search";
const string RECORD_NOT_FOUND_MESSAGE = "Record not found!";
const string FILE_NAME = "FacultyNumber.ids";
const string GRADES = "StudentsGrades.db";

void Search::execute()
{
	ifstream iFile(FILE_NAME);
	if (!iFile.good()) 
	{
		ICommand* buildCom = new BuildIndex();
		buildCom->execute();
	}
	iFile.close();
	ifstream binFile(FILE_NAME, ios::in | ios::binary);
	unsigned int numStudentsIndex;
	binFile.read((char*)&numStudentsIndex, sizeof(unsigned int));
	Index studentIndex;
	ifstream fin(GRADES);
	Student st;
	unsigned long long searchedFacNum;
	cin >> searchedFacNum;
	int from = 0, to = numStudentsIndex - 1, mid;
	bool isFound = false;
	while (abs(to - from) > 1)
	{
		mid = (from + to) / 2;
		binFile.seekg(mid * sizeof(Index) + sizeof(unsigned int), ios::beg);
		binFile.read((char*)&studentIndex, sizeof(Index));
		if (searchedFacNum == studentIndex.getFacNum())
		{
			isFound = true;
			fin.seekg(studentIndex.getOffset());
			fin >> st;
			break;
		}
		else if (searchedFacNum > studentIndex.getFacNum())
		{
			from = mid + 1;
		}
		else
		{
			to = mid - 1;
		}
	}
	binFile.seekg(from * sizeof(Index) + sizeof(unsigned int), ios::beg);
	binFile.read((char*)&studentIndex, sizeof(Index));
	if (searchedFacNum == studentIndex.getFacNum())
	{
		isFound = true;
		fin.seekg(studentIndex.getOffset());
		fin >> st;
	}
	binFile.seekg(to * sizeof(Index) + sizeof(unsigned int), ios::beg);
	binFile.read((char*)&studentIndex, sizeof(Index));
	if (to != from && searchedFacNum == studentIndex.getFacNum())
	{
		isFound = true;
		fin.seekg(studentIndex.getOffset());
		fin >> st;
	}

	if (!isFound)
	{
		cout << RECORD_NOT_FOUND_MESSAGE << endl;
	}
	else
	{
		cout << st << endl;
	}
	binFile.close();
	fin.close();
}

string Search::toString()
{
	return SEARCH;
}
