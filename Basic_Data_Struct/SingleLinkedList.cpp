#include "stdafx.h"
/*
#include "SingleLinkedList.h"


SingleLinkedList::SingleLinkedList()
{

}

void SingleLinkedList::pushFront(int value, NodeSL *& head)
{
	NodeSL * p = new NodeSL(value, head);
	this->setHead(p);

	return;
}
void SingleLinkedList::pushBack(int value, NodeSL *& head)
{
	NodeSL * it;
	it = getHead();

	while (it->getNext!=NULL)	// iterate over the array until the last element
	{
		it = it->getNext();
	}
	
	NodeSL * newElement = new NodeSL(value, NULL);	// new tail
	it->setNext(newElement);						// set the 'next' value of a previous tail
	
	return ;
}
void SingleLinkedList::popFront()
{
	NodeSL * p = this->getHead(); // get the current head address
	this->setHead(p->getNext);	  // change the head address to the next element in the array
	delete p;					  // delete previous head

	return;
}
void SingleLinkedList::popBack()
{
	return;
}
NodeSL* SingleLinkedList::getHead()
{
	return this->head;
}
void SingleLinkedList::setHead(NodeSL *& head)
{
	this->head = head;
}

SingleLinkedList::~SingleLinkedList()
{
}*/
