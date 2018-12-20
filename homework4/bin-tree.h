#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_

#include <iostream>
#include "student.h"
using namespace std;

struct Node
{
	Student data;
	Node* left;
	Node* right;
};

class BinTree
{
private:
	Node* root;
	void copyTree(Node*&, Node*);
	void deleteTree(Node*&);
	unsigned long long getMax(Node*);
	void insert(Node*&, const Student&);
	void update(Node*&, const Student&);
	bool del(Node*&, unsigned long long);
	bool checkIfExists(Node*, unsigned long long);
	Student find(Node*, unsigned long long);
	void traverse(Node*, unsigned long long);
public:
	BinTree();
	BinTree(const BinTree&);
	BinTree& operator=(const BinTree&);
	~BinTree();

	void insertElem(const Student&);
	bool deleteElem(unsigned long long);
	Student findElem(unsigned long long);
	void traverseInorder();
};

#endif // !_BIN_TREE_H_


