#include "stdafx.h"

#include "List.h"
#include <iterator>
#include "ListIterator.h"
List::List()
{
	head = nullptr;
	size = 0;
}

ListIterator List::iteratorAt(int index)
{
	int counter = 0;

	for (auto list_iter = begin(); list_iter != end(); ++list_iter, ++counter)
	{
		if (counter == index)
		{
			return list_iter;
		}
	}
	return ListIterator(nullptr);
}

void List::pushFront(int value)
{
	Node * p = new Node(value, head);
	head = p;
	size++;
}

void List::pushBack(int value)
{
	// Find the last element of the list and attach a new one to the "next" address.
	auto temp_it = iteratorAt(size - 1);

	if (temp_it.node != nullptr)
		(*temp_it).next = new Node(value, NULL);
	else
		head = new Node(value, NULL);
	size++;
}

void List::pushAt(int value, int index)
{
	if (size == 0 && index == 0)
		pushFront(value);
	else if (size > 0 && index > 0 && index <= size)
	{
		// Create a node that points to the current node at "index",
		// and update the address of a field "next" that pointed to it.
		ListIterator list_iter = iteratorAt(index - 1);

		if (list_iter.node != nullptr)
		{
			(*list_iter).next = new Node(value, (*list_iter).next);
			size++;
			return;
		}
		else
			throw std::invalid_argument("Incorrect input index.");
	}
	else
	{
		throw EmptyListException();
	}
}

void List::popFront()
{
	if (size == 0)
		throw EmptyListException();
	else
	{
		Node * tmp = head->next;
		delete head;
		head = tmp;
		size--;
	}
}

void List::popBack()
{
	if (size == 0)
		throw EmptyListException();
	else
	{
		// Two cases with different behaviour after deleting a node:
		// 1) Delete node was a head -> update the head pointer.
		// 2) In any other case -> update the "next" field of a previous node.

		auto list_it = iteratorAt(size - 1);
		delete list_it.node;

		if (size == 1)
			head = nullptr;
		else
		{
			auto list_it = iteratorAt(size - 2);
			(*list_it).next = nullptr;
		}
		size--;
	}
}

void List::popAt(int index)
{
	if (size == 0)
		throw EmptyListException();
	else if (index > size || index < 0)
		throw std::invalid_argument("Incorrect input index.");
	else
	{
		// Quite similar as above with the difference being that:
		// 1) The left and right neighbours have to be connected before removal.
		if (size == 1)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			ListIterator list_iter = iteratorAt(index);
			Node * tmp = (*list_iter).next->next;
			delete (*list_iter).next;
			(*list_iter).next = tmp;
		}
		size--;
	}
}

std::string List::toString()
{
	std::string list_to_string;
	for (auto list_iter = begin(); list_iter != end(); ++list_iter)
	{
		list_to_string += (*list_iter).toString + " -> ";
	}
	return list_to_string;
}

List::~List()
{
	if (head != nullptr)
	{
		for (int size_it = 0; size_it < size;)
			popBack();
	}
}
