#include "stdafx.h"
#include "Node.h"

Node::Node()
{}

Node::Node(int value, Node * next)
{
	this->value = value;
	this->next = next;
}

Node::~Node()
{}
