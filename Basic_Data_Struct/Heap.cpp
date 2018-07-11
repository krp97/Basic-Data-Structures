#include "stdafx.h"
#include "Heap.h"
#include <Math.h>
#include <iostream>


void Heap::insert(int value) 
{
	pushBack(value);	
	size++;

	if (size > 1)
		fixUp(size - 1);
}

void Heap::remove(int value)
{

}

void Heap::popRoot()
 {
	// Delete the root and put the lowest key in it's place
	swap(0, size - 1);
	popBack();
	fixDown(0);
}

void Heap::fixDown(int index)
{
	int leftChild = getLeftChild(index);
	int rightChild = getRightChild(index);

	int toSwap = index;

	if (leftChild >= size - 1)
	{
		return; //nullptr
	}
	if (arrPtr[toSwap] < arrPtr[leftChild])
		toSwap = leftChild;
	if ((arrPtr[toSwap] < arrPtr[rightChild]) && (rightChild < size))
		toSwap = rightChild;
	if (toSwap != index)
	{
		swap(index, toSwap);
		fixDown(toSwap);
	}
}

void Heap::fixUp(int index)
{

}

std::string Heap::toString()
{
	return std::string();
}

Heap::Heap()
{
	size = 0;
	arrPtr = nullptr;
}

Heap::~Heap()
{

}