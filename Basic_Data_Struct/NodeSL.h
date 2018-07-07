#pragma once
class NodeSL
{
private:

	int value;
	NodeSL * next;

public:

	NodeSL(int value, NodeSL*);

	//Getters
	NodeSL * getNext();
	int getValue();

	//Setters
	void setNext(NodeSL*& next);
	void setValue(int value);

	~NodeSL();
};

