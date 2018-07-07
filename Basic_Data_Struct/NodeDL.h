#pragma once
class NodeDL
{
	friend class DoubleLinkedList;
	friend class Heap;

private:
	int value;		// wartosc
	NodeDL * prev;	// poprzedni wezel
	NodeDL * next;	// nastepny wezel

public:
	NodeDL(int value, NodeDL * prev, NodeDL * next);
	~NodeDL();
};

