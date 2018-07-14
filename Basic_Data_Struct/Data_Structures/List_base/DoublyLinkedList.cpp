#include "stdafx.h"
#include "DoublyLinkedList.h"
#include <iostream>


DoublyLinkedList::iterator DoublyLinkedList::begin() const
{
	return DoublyLinkedList::iterator(head);
}

DoublyLinkedList::iterator DoublyLinkedList::end() const
{
	return DoublyLinkedList::iterator(nullptr);
}

DoublyLinkedList::iterator DoublyLinkedList::rbegin() const
{	
	return DoublyLinkedList::iterator(tail);
}

DoublyLinkedList::iterator DoublyLinkedList::rend() const
{
	return DoublyLinkedList::iterator(nullptr);
}

DoublyLinkedList::iterator DoublyLinkedList::iteratorAt(int index)
{
	NodeDL * tmp = head;
	for (int list_it = 0; tmp != nullptr; ++list_it)
	{
		if(list_it == index)
			return DoublyLinkedList::iterator(tmp);
		tmp = tmp->next;
	}
	return DoublyLinkedList::iterator(nullptr);
}

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

void DoublyLinkedList::pushFront(int value)
{
	NodeDL* p = new NodeDL(value, nullptr, head);
	size++;
	
	if (head == nullptr)	
		tail = p;
	else
		head->prev = p;

	head = p;
}

void DoublyLinkedList::pushBack(int value)
{
	NodeDL* p = new NodeDL(value, tail, nullptr);
	size++;

	if (head == nullptr)	
		head = p;		
	else
		tail->next = p;

	tail = p;
}

void DoublyLinkedList::pushAt(int value, int index)
{
	if (size == 0)
		throw EmptyListException();
	else if(index >= 0 && index <= size)
	{
		// Reusing the existing methods for similar actions.
		if (index == 0)
			pushFront(value);
		else if (index == size)
			pushBack(value);
		else
		{
			DLListIterator list_it = iteratorAt(index);
			NodeDL* p = new NodeDL(value, (*list_it).prev, list_it.node);	
			size++;

			(*list_it).prev->next = p;								
			(*list_it).prev = p;
		}
	}
}

void DoublyLinkedList::popFront()
{
	if (size == 0)
		throw std::out_of_range("Empty list.");
	else
	{
		// When the list isn't empty, 
		// the pointer of a neighbouring node has to be updated.

		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->next;									
			delete head->prev;				
			head->prev = nullptr;
		}
		size--;
	}
}

void DoublyLinkedList::popBack()
{
	if (size == 0)
		throw std::out_of_range("Empty list.");
	else
	{
		// Similar as in the case of popFront().
		if (head == tail)		
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail = tail->prev;				
			delete tail->next;
			tail->next = nullptr;
		}
		size--;
	}
}

void DoublyLinkedList::popAt(int index)
{
	if (size == 0)
		throw std::out_of_range("Empty list.");
	else if (index >= 0 && index <= size)
	{
		// Resuing existing methods for similar actions.
		if (index == 0)
			popFront();
		else if (index == size)
			popBack();
		else
		{
			// Updating the pointers of neighbouring nodes before removal,
			// in order to prevent data loss and undefined references.

			DLListIterator list_it = iteratorAt(index);

			(*list_it).next->prev = (*list_it).prev;			
			(*list_it).prev->next = (*list_it).next;			

			delete list_it.node;
			size--;
		}
	}
	else
		throw "Invalid input index.";
}

std::string DoublyLinkedList::toString()
{
	std::string list_to_string;

	for (auto list_it = begin(); list_it != end(); ++list_it)
	{
		list_to_string += (*list_it).toString();
		if ((*list_it).next == nullptr)
			continue;
		list_to_string += "<->";
	}
	return list_to_string;
}

std::string DoublyLinkedList::forwardTravers()
{
	std::string output;
	for (auto list_it = begin(); list_it != end(); ++list_it)
	{
		output += (*list_it).toString();
		if ((*list_it).next == nullptr)
			continue;
		output += "->";
	}
	return output;
}

std::string DoublyLinkedList::backwardTravers()
{
	std::string output;
	for (auto list_it = rbegin(); list_it != rend(); --list_it)
	{
		output += (*list_it).toString();
		if ((*list_it).prev == nullptr)
			continue;
		output += "->";
	}
	return output;
}

DoublyLinkedList::~DoublyLinkedList()
{
	for (int size_it = 0; size_it < size;)
		popBack();
}