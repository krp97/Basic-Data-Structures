#include "stdafx.h"
#include "NodeSL.h"


NodeSL::NodeSL(int value, NodeSL * next)
{
	this->value = value;
	this->next = next;
}


NodeSL::~NodeSL()
{

}
