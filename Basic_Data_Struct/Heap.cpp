#include "stdafx.h"
#include "Heap.h"
#include <Math.h>
#include <iostream>


void Heap::insert(int value) 
{
	pushBack(value);	

	if (size > 1)
		fixUp(size - 1);
}

void Heap::remove(int value)
{
	int index = lookUpValue(value);
	swap(index, size - 1);
	fixDown(index);
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
		return;

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
	int parent = getParent(index);
	int otherChild = getLeftChild(parent);
	int toSwap = index;

	if (parent == index)
		return;

	if (otherChild == index && otherChild + 1 < size)
	{
		otherChild++;
		if (arrPtr[toSwap] < arrPtr[otherChild])
			toSwap = otherChild;
	}
	
	if (toSwap < size)
	{
		swap(parent, toSwap);
		fixUp(parent);
	}
}

std::string Heap::toString()
{
	std::string output = "|"; // First character

	if (size > 0)
		for (int arrIt = 0; arrIt < size; arrIt++)
			output += std::to_string(arrPtr[arrIt]) + '|';

	else
		throw EmptyArrException();
	return output;
}

Heap::Heap()
{
}

Heap::Heap(Array arr)
{
	this->arrPtr = arr.arrPtr;
	fixDown(0);
}

Heap::~Heap()
{

}