#pragma once
#include "Array.h"
#include "NodeDL.h"
#include <iostream>
#include <string>
class Heap: public Array
{
public:

	void insert(int value);
	void remove(int value);		// Deletes the first encountered key that is equal to "value"

	int peekRoot() { return arrPtr[0]; };
	void popRoot();							

	void fixUp(int index);					
	void fixDown(int index);

	int getLeftChild(int index) { return arrPtr[2 * index + 1]; };
	int getRightChild(int index) { return arrPtr[2 * index + 2]; };
	int getParent(int index) { return arrPtr[floor(index / 2)]; }

	virtual std::string toString();

	Heap();
	~Heap();
};

