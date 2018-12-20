#include "bin-tree.h"

void BinTree::copyTree(Node *& dest, Node * src)
{
	dest = nullptr;
	if (src)
	{
		dest = new Node;
		dest->data = src->data;
		copyTree(dest->left, src->left);
		copyTree(dest->right, src->right);
	}
}

void BinTree::deleteTree(Node *& root)
{
	if (!root)
	{
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
	root = nullptr;
}

unsigned long long BinTree::getMax(Node * root)
{
	if (!root)
	{
		return 0;
	}
	while (root->right)
	{
		root = root->right;
	}
	return root->data.getFacNum();
}

void BinTree::insert(Node *& root, const Student & newStudent)
{
	if (!root)
	{
		root = new Node;
		root->data = newStudent;
		root->left = nullptr;
		root->right = nullptr;
		return;
	}
	if (newStudent < root->data)
	{
		insert(root->left, newStudent);
	}
	else
	{
		insert(root->right, newStudent);
	}
}

void BinTree::update(Node *& root, const Student & newStudent)
{
	if (!root)
	{
		return;
	}
	if (root->data.getFacNum() == newStudent.getFacNum())
	{
		root->data = newStudent;
		return;
	}
	if (newStudent < root->data)
	{
		update(root->left, newStudent);
	}
	else
	{
		update(root->right, newStudent);
	}
}

bool BinTree::del(Node *& root, unsigned long long facNum)
{
	if (!root)
	{
		return false;
	}
	if (root->data.getFacNum() == facNum)
	{
		if (!root->left && !root->right)
		{
			delete root;
			root = nullptr;
			return true;
		}
		else if (!root->right)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
			return true;
		}
		else if (!root->left)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
			return true;
		}
		else
		{
			Node* temp = root->right;
			while (temp->left)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			return del(root->right, temp->data.getFacNum());
		}
	}
	else if (facNum < root->data.getFacNum())
	{
		return del(root->left, facNum);
	}
	return del(root->right, facNum);
}

bool BinTree::checkIfExists(Node * root, unsigned long long facNum)
{
	if (!root)
	{
		return false;
	}
	if (facNum == root->data.getFacNum())
	{
		return true;
	}
	else if (facNum < root->data.getFacNum())
	{
		return checkIfExists(root->left, facNum);
	}
	return checkIfExists(root->right, facNum);
}

Student BinTree::find(Node * root, unsigned long long facNum)
{
	if (!root)
	{
		return Student();
	}
	if (facNum == root->data.getFacNum())
	{
		return root->data;
	}
	else if (facNum < root->data.getFacNum())
	{
		return find(root->left, facNum);
	}
	return find(root->right, facNum);
}

void BinTree::traverse(Node * root, unsigned long long maxNum)
{
	if (!root)
	{
		return;
	}
	traverse(root->left, maxNum);
	if (root->data.getFacNum() == maxNum)
	{
		cout << root->data.getFacNum() << endl;
	}
	else
	{
		cout << root->data.getFacNum() << ", ";
	}
	traverse(root->right, maxNum);
}

BinTree::BinTree() : root(nullptr)
{
}

BinTree::BinTree(const BinTree & other)
{
	copyTree(root, other.root);
}

BinTree & BinTree::operator=(const BinTree & other)
{
	if (this != &other)
	{
		deleteTree(root);
		copyTree(root, other.root);
	}
	return *this;
}

BinTree::~BinTree()
{
	deleteTree(root);
}

void BinTree::insertElem(const Student & newStudent)
{
	if (checkIfExists(root, newStudent.getFacNum()))
	{
		update(root, newStudent);
		return;
	}
	insert(root, newStudent);
}

bool BinTree::deleteElem(unsigned long long facNum)
{
	return del(root, facNum);
}

Student BinTree::findElem(unsigned long long facNum)
{
	return find(root, facNum);
}

void BinTree::traverseInorder()
{
	traverse(root, getMax(root));
}

