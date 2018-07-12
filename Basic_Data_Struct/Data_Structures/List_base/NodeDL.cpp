#include "stdafx.h"
#include "NodeDL.h"
#include <string>

NodeDL::NodeDL(int value, NodeDL* prev, NodeDL * next)
{
	this->value = value;
	this->prev = prev;
	this->next = next;
}
std::string NodeDL::toString() {

	return std::string(std::to_string(value));
						
}
NodeDL::~NodeDL()
{

}
