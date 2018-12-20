#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int SIZE = 257;

class Student {
private:
	unsigned long long facNum;
	char firstName[SIZE];
	char lastName[SIZE];
	unsigned short grade;
public:
	Student();
	Student(unsigned long long, char*, char*, unsigned short);
	~Student();

	friend istream& operator>>(istream& is, Student&);
	friend ostream& operator<<(ostream& os, Student&);
	friend bool operator<(Student&, Student&);

	unsigned long long getFacNum() const { return facNum; }
};

#endif // !_STUDENT_H_

