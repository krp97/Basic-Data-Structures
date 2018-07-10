#pragma once
#include <string>
class Node
{
	friend class ListIterator;
	friend class List;

	Node * next;

protected:

	int value;

public:

	Node();
	Node(int value, Node* next);

	virtual std::string toString() { return std::string(std::to_string(value)); };

	~Node();
};

