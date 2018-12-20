#include "index.h"

Index::Index(unsigned long long facNum, unsigned int offset)
{
	this->facNum = facNum;
	this->offset = offset;
}

bool Index::operator<(Index & other)
{
	return facNum < other.facNum;
}
