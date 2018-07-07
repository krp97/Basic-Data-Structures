#include "stdafx.h"
#include "DoublyLinkedList.h"
#include <iostream>


DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void DoublyLinkedList::pushFront(int value)
{
	NodeDL* p = new NodeDL(value, nullptr, head);

	if (getCount() == 0)	// pierwsze dodanie
	{
		head = p;
		tail = p;
		p->value = value;
		return;
	}

	head->prev = p;			// ustawienie poprzednika w poprzedniej glowie
	head = p;				// ustawienie nowej glowy listy
}

void DoublyLinkedList::pushBack(int value)
{
	NodeDL* p = new NodeDL(value, tail, nullptr);

	if (getCount() == 0)	// pierwsze dodanie
	{
		head = p;		
		tail = p;
		p->value = value;
		return;
	}

	tail->next = p;			// ustawienie nastepnika w poprzednim ogonie
	tail = p;				// ustawienie nowego ogona
}

void DoublyLinkedList::pushAt(int value, int index)		// wstawienie przed podanym indeksem
{
	if (index == 0)					
		pushFront(value);
	else if (index == getCount())
		pushBack(value);
	else
	{
		int counter = 0;
		NodeDL* it = head;			// iterator listy

		while (index > counter)	
		{
			counter++;
			it = it->next;
		}

		NodeDL* p = new NodeDL(value, it->prev, it);	// nowy element miedzy poprzednikiem iteratora, a iteratorem
		it->prev->next = p;								// ustawienie "next" poprzednika na nowy element
		it->prev = p;									// ustawienie "prev" iteratora na nowy element
	}
}

void DoublyLinkedList::popFront()
{
	if (getCount() > 0)
	{
		if (getCount() == 1)			// tylko jeden element w liscie
		{
			delete head;
			head = nullptr;
			tail = nullptr;

			return;
		}

		head = head->next;				// przesuniecie dotychczasowej glowy na nastepny element					
		delete head->prev;				// usuniecie poprzednika aktualnej glowy
		head->prev = nullptr;			
	}
}

void DoublyLinkedList::popBack()
{
	if (getCount() > 0)
	{
		if (getCount() == 1)			// tylko jeden element w liscie
		{
			delete tail;
			head = nullptr;
			tail = nullptr;

			return;
		}

		tail = tail->prev;				// przesuniecie dotychczasowego ogona na poprzedni element
		delete tail->next;				// usuniecie nastepnika aktualnego ogona
		tail->next = nullptr;
	}
}

void DoublyLinkedList::popAt(int index)		// usuniecie przed podanym indeksem
{
	if (index == 0)						
		popFront();
	else if (index == getCount())
		popBack();
	else
	{
		NodeDL* it = head;					// iterator listy
		int counter = 0;

		while (counter != index)			// ustawienie iteratora na zadany indeks
		{
			counter++;
			it = it->next;
		}

		it->next->prev = it->prev;			// ustawienie pola "prev" nastepnika na poprzednik iteratora
		it->prev->next = it->next;			// ustawienie pola "next" poprzednika na nastepnik iteratora
		delete it;
	}
}

int DoublyLinkedList::find(int value)
{
	NodeDL* p = head;
	int index = 0;

	while (p != nullptr)					// wyluskanie pierwszego adresu pod ktorym znajduje sie value
	{
		if (value == p->value)
		{
			return index;
		}
		p = p->next;
	}
	return 0; 
}

void DoublyLinkedList::display()
{
	NodeDL* p = head;

	while (p != nullptr)
	{
		std::cout << (p->value) << "<->";
		p = p->next;
	}
}
int DoublyLinkedList::getCount()
{
	int count = 0;
	NodeDL* p = head;

	while (p != nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

DoublyLinkedList::~DoublyLinkedList()
{
}
