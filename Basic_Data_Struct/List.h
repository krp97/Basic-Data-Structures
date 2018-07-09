#pragma once
#include "Node.h"
#include <string>
#include "ListIterator.h"
class List
{
	using iterator = ListIterator;
private:
	Node * head;
	int size;

	List::iterator begin() const;
	List::iterator end() const;
	List::iterator iteratorAt(int index);

public:
	List();



	void pushFront(int value);
	void pushBack(int value);
	void pushAt(int value, int index);

	void popFront();
	void popBack();
	void popAt(int index);
	
	virtual std::string toString();

	~List();
};

