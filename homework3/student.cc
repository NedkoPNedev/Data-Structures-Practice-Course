#include "student.h"
#pragma warning( disable : 4996)
Student::Student() : facNum(1), firstName(""), lastName(""), grade(2)
{
}

Student::Student(unsigned long long facNum, char* firstName, char* lastName, unsigned short grade)
{
	this->facNum = facNum;
	strcpy(this->firstName, firstName);
	strcpy(this->lastName, lastName);
	this->grade = grade;
}

Student::~Student()
{
}

istream & operator>>(istream & is, Student & student)
{
	is >> student.facNum >> student.firstName >> student.lastName >> student.grade;
	return is;
}

ostream & operator<<(ostream & os, Student & student)
{
	os << student.facNum << " " << student.firstName << " " << student.lastName << " " << student.grade;
	return os;
}

bool operator<(Student & s1, Student & s2)
{
	return s1.facNum < s2.facNum;
}
