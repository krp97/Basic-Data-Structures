#include "stdafx.h"
#include "Node.h"

Node::Node()
{}
Node::Node(int value, Node * next)
{
	this->value = value;
	this->next = next;
}

std::string Node::toString()
{
	return std::string();
}


Node::~Node()
{

}
