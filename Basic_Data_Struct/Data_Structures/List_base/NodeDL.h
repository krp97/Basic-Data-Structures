#pragma once
#include "Node.h"
class NodeDL : public Node
{
	friend class DLListIterator;
	friend class DoublyLinkedList;

private:
	NodeDL * prev;	
	NodeDL * next;
public:
	NodeDL(int value, NodeDL * prev, NodeDL * next);

	virtual std::string toString() override;

	~NodeDL();
};

