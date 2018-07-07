#include "stdafx.h"
#include "NodeDL.h"


NodeDL::NodeDL(int value, NodeDL* prev, NodeDL * next)
{
	this->value = value;
	this->prev = prev;
	this->next = next;
}
NodeDL::~NodeDL()
{

}
