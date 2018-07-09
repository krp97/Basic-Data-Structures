#include "stdafx.h"

#include "List.h"
#include <iterator>
#include "ListIterator.h"
List::List()
{
	head = nullptr;
	size = 0;
}
List::iterator List::begin() const
{
	return ListIterator(this->head);
}
List::iterator List::end() const
{
	return ListIterator(nullptr);
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
	auto temp_it = begin();

	if (temp_it.node != nullptr)
	{
		for (auto list_iter = begin(); list_iter != end(); ++list_iter)
		{
			temp_it = list_iter;
		}

		Node * lastNode = new Node(value, NULL);
		(*temp_it).next = lastNode;
	}
	else
	{
		head = new Node(value, NULL);
	}
	size++;
}
void List::pushAt(int value, int index)
{
	if (size == 0 && index == 0)
		pushFront(value);
	else if (size > 0)
	{
		ListIterator list_iter = iteratorAt(index);

		if (list_iter.node != nullptr)
		{
			list_iter.node->next = new Node(value, list_iter.node->next);
			size++;
			return;
		}
		else
			throw "custom iterator expression here";
	}
	else
	{
		throw "custom expression here";
	}
}
void List::popFront()
{
	if (size == 0)
		throw "custom expression here boi";
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
		throw "custom expression here boi";
	else
	{
		auto tmp_it = begin();
		for (auto list_iter = begin(); list_iter != end(); ++list_iter)
		{
			tmp_it = list_iter;
		}
		delete tmp_it.node;
		size--;
	}
}
void List::popAt(int index)
{
	if (size == 0)
		throw "custom expression here";
	else
	{
		ListIterator list_iter = iteratorAt(index - 1);

		if (list_iter.node != nullptr)
		{
			Node * tmp = list_iter.node->next->next;
			delete list_iter.node->next;
			list_iter.node->next = tmp;
			size--;
		}
	}
}

std::string List::toString()
{
	for (auto list_iter = begin(); list_iter != end(); ++list_iter)
	{
		std::cout << list_iter.node->value << " -> ";
	}
	return std::string();
}

List::~List()
{
	// Delete all nodes if size > 0
}
