#ifndef _INDEX_H_
#define _INDEX_H_

class Index
{
private:
	unsigned long long facNum;
	unsigned int offset;
public:
	Index(unsigned long long = 0, unsigned int = 0);
	unsigned long long getFacNum() const { return facNum; }
	unsigned int getOffset() const { return offset; }
	bool operator<(Index&);
};

#endif // !_INDEX_H_

