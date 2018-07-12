#pragma once
#include "NodeDL.h"
#include "DLListIterator.h"
#include <string>

class DoublyLinkedList
{
	using iterator = DLListIterator;

	NodeDL * head;
	NodeDL * tail;
	int size;

	DoublyLinkedList::iterator begin() const;
	DoublyLinkedList::iterator end() const;
	DoublyLinkedList::iterator rbegin() const;
	DoublyLinkedList::iterator rend() const;

	DoublyLinkedList::iterator iteratorAt(int index);

public:

	struct EmptyListException : public std::exception {
		const char * description() const throw () {
			return "Operation on an empty list."; 
		}
	};

	DoublyLinkedList();

	
	virtual void pushFront(int value);
	virtual void pushBack(int value);
	virtual void pushAt(int value, int index);

	virtual void popFront();
	virtual void popBack();
	virtual void popAt(int index);	

	virtual std::string toString();

	~DoublyLinkedList();
};
