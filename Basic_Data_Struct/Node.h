#pragma once
#include <iostream>
class Node
{
	// Abstract class serving as a base class for all nodes.
protected:
	int value;
public:
	virtual std::string toString() = 0;
};

