#pragma once
#include <string>
class Node
{
	friend class ListIterator;
	friend class List;
protected:

	int value;
	Node * next;

public:
	Node();
	Node(int value, Node* next);
	virtual std::string toString();
	~Node();
};

