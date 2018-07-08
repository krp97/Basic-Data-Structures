#include "stdafx.h"
/*
#include "SingleLinkedList.h"


SingleLinkedList::SingleLinkedList()
{

}

void SingleLinkedList::pushFront(int value, Node *& head)
{
	Node * p = new Node(value, head);
	this->setHead(p);

	return;
}
void SingleLinkedList::pushBack(int value, Node *& head)
{
	Node * it;
	it = getHead();

	while (it->getNext!=NULL)	// iterate over the array until the last element
	{
		it = it->getNext();
	}
	
	Node * newElement = new Node(value, NULL);	// new tail
	it->setNext(newElement);						// set the 'next' value of a previous tail
	
	return ;
}
void SingleLinkedList::popFront()
{
	Node * p = this->getHead(); // get the current head address
	this->setHead(p->getNext);	  // change the head address to the next element in the array
	delete p;					  // delete previous head

	return;
}
void SingleLinkedList::popBack()
{
	return;
}
Node* SingleLinkedList::getHead()
{
	return this->head;
}
void SingleLinkedList::setHead(Node *& head)
{
	this->head = head;
}

SingleLinkedList::~SingleLinkedList()
{
}*/
