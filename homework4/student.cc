#include "student.h"

Student::Student() : facNum(0), firstName(""), lastName("")
{
}

Student::Student(unsigned long long facNum, string firstName, string lastName)
{
	this->facNum = facNum;
	this->firstName = firstName;
	this->lastName = lastName;
}

Student::~Student()
{
}

istream & operator>>(istream & is, Student & student)
{
	is >> student.facNum >> student.firstName >> student.lastName;
	return is;
}

ostream & operator<<(ostream & os, Student & student)
{
	os << student.facNum << " " << student.firstName << " " << student.lastName;
	return os;
}

bool operator<(const Student & s1, const Student & s2)
{
	return s1.facNum < s2.facNum;
}

bool operator==(Student & first, Student & second)
{
	return first.facNum == second.facNum;
}
