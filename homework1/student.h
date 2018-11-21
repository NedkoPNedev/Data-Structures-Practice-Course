#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Student {
private:
	unsigned long long facNum;
	string firstName;
	string lastName;
	unsigned short grade;
public:
	Student();
	Student(unsigned long long, string, string, unsigned short);
	~Student();
	friend istream& operator>>(istream& is, Student&);
	friend ostream& operator<<(ostream& os, Student&);
	unsigned long long getFacNum() const { return facNum; }
};

#endif // !_STUDENT_H_
