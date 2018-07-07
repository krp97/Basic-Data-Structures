#pragma once
#include "Node.h"
class NodeDL : private Node
{
	friend class DoublyLinkedList;
	friend class Heap;

private:
	NodeDL * prev;	
	NodeDL * next;

public:
	NodeDL(int value, NodeDL * prev, NodeDL * next);

	virtual std::string toString() override;
	int getvalue();

	~NodeDL();
};

