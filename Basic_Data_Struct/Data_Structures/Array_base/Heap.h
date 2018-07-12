#pragma once
#include "Array.h"
#include <iostream>
#include <string>

class Heap: private Array
{
	int getLeftChild(int index) { return 2 * index + 1; };
	int getRightChild(int index) { return 2 * index + 2; };
	int getParent(int index) { return (int)floor((index - 1) / 2); }
	
	void fixUp(int index);
	void fixDown(int index);
	
public:

	void insert(int value);
	void remove(int value);		// Deletes the first encountered key that is equal to "value"

	int peekRoot() { return arrPtr[0]; };
	void popRoot();							

	virtual std::string toString();

	Heap();
	explicit Heap(Array arr);

	~Heap();
};

