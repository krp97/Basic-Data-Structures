#pragma once
#include "Node.h"
#include <string>
#include "ListIterator.h"
#include "..\DataStructure.h"
class List : public DataStructure
{
	using iterator = ListIterator;

	Node * head;
	int size;

	List::iterator begin() const { return ListIterator(this->head); };
	List::iterator end() const { return ListIterator(nullptr); };
	List::iterator iteratorAt(int index);

public:

	struct EmptyListException : public std::exception {
		const char * description() const throw () {
			return "Operation on an empty list.";
		}
	};

	List();

	virtual void pushFront(int value);
	virtual void pushBack(int value);
	virtual void pushAt(int value, int index);

	virtual void popFront();
	virtual void popBack();
	virtual void popAt(int index);
	
	virtual std::string toString();

	void loadFromFile(std::string fileName);
	void saveToFile(std::string fileName);

	~List();
};

