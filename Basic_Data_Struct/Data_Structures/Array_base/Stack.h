#pragma once
#include "Array.h"
#include <string>
class Stack : public Array
{

public:

	int peek() { return arrPtr[0]; };
	void pop();
	void push(int value) { pushFront(value); };

	int extract();	// peek + pop
	void clear();	// clears the whole stack

	int peekAddress(int stack_index) { return arrPtr[stack_index]; };
	int find(int value) { return lookUpValue(value); };

	virtual std::string toString();
	virtual void loadFromFile(std::string fileName);

	Stack();
	~Stack();
};

