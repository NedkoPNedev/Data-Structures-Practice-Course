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
public:
	Student();
	Student(unsigned long long, string, string);
	~Student();

	friend istream& operator>>(istream& is, Student&);
	friend ostream& operator<<(ostream& os, Student&);
	friend bool operator<(const Student&, const Student&);
	friend bool operator==(Student&, Student&);

	unsigned long long getFacNum() const { return facNum; }
	string getFirstName() const { return firstName; }
	string getLastName() const { return lastName; }
	void setFacNum(unsigned long long facNum) { this->facNum = facNum; }
	void setFirstName(string firstName) { this->firstName = firstName; }
	void setLastName(string lastName) { this->lastName = lastName; }
};

#endif