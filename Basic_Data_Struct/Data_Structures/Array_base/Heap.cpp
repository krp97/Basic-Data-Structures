#include "stdafx.h"
#include "Heap.h"
#include <Math.h>
#include <iostream>
#include <fstream>

void Heap::insert(int value) 
{
	pushBack(value);	

	if (size > 1)
	{
		try { fixUp(size - 1); } 
		catch (std::invalid_argument) { throw; }
	}
}

void Heap::remove(int value)
{
	int index = lookUpValue(value);
	try
	{
		swap(index, size - 1);
		popBack();
		fixDown(index);
	}
	catch (std::invalid_argument) { throw; }
}

void Heap::popRoot()
 {
	// Delete the root and put the lowest key in it's place
	if (size > 0)
	{
		swap(0, size - 1);
		popBack();
		fixDown(0);
	}
	else
		throw std::out_of_range("Empty array opertaion.");
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
		try {
			swap(index, toSwap);
			fixDown(toSwap);
		}
		catch (std::invalid_argument) { throw; }
	}
}

void Heap::fixUp(int index)
{
	int parent = getParent(index);
	int leftChild = getLeftChild(parent);
	int rightChild = getRightChild(parent);

	int toSwap = leftChild;

	if (parent == index)
		return;
	// If the rightChild exists, checking if it's bigger the leftChild.

	if (rightChild < size)
	{
		if (arrPtr[rightChild] > arrPtr[leftChild])
			toSwap = rightChild;
	}
	if (arrPtr[toSwap] < arrPtr[parent])
		return;

	if (toSwap < size)
	{
		try {
			swap(parent, toSwap);
			fixUp(parent);
		}
		catch (std::invalid_argument) { throw; }
	}
}

std::string Heap::toString()
{
	std::string output = "|"; // First character

	if (size > 0)
		for (int arrIt = 0; arrIt < size; arrIt++)
			output += std::to_string(arrPtr[arrIt]) + '|';
	else
		return std::string();
	return output;
}

void Heap::loadFromFile(std::string fileName)
{
	std::ifstream fileToRead;
	std::string line;
	int value = 0;

	// All exceptions are rethrown for the caller to handle, or call apropriate handlers.
	// In case of any error the input data is unusable, so there is no point in continuing.

	try {

		fileToRead.open(fileName);

		while (fileToRead.good())
		{
			fileToRead >> line;
			try
			{
				value = stoi(line);
			}
			catch (std::invalid_argument& e)
			{
				fileToRead.close();
				throw;
			}
			this->insert(value);
		}
	}
	catch (std::ios_base::failure &fail)
	{
		throw;
	}

	fileToRead.close();
}

Heap::Heap()
{

}

Heap::~Heap()
{

}