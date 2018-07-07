#include "stdafx.h"
#include "DArray.h"
//---toString-------
#include <iostream>	
#include <string>        
//------------------
#include <exception>
#include <fstream>

struct EmptyArrException : public std::exception {
	const char * description() const throw () {
		return "Empty array exception.";
	}
};

DArray::DArray(int size)
{
	this->size = size;
	this->dArray = nullptr;
}

void DArray::pushFront(int value)
{
	size++;
	int *tempArray = new int[size];
	
	// Copy the contents of the old array into the new array,
	// keeping in mind that the first element is already assigned.
	*tempArray = value;					
	memcpy(tempArray + 1, dArray, (size - 1) * sizeof(int));

	// Updating the current array pointer.
	delete[] dArray;					
	dArray = tempArray;					
}

void DArray::pushBack(int value)
{
	size++;
	int *tempArray = new int[size];
	
	// Copy the contents of the old array into the new array.
	// New element is added at the last position.
	*(tempArray + (size - 1)) = value;	
	memcpy(tempArray, dArray, (size - 1) * sizeof(int));

	// Updating the current array pointer.
	delete[] dArray;				
	dArray = tempArray;					
}

void DArray::pushAt(int value, int index)
{
	if (dArray == nullptr)
		throw EmptyArrException();
	if (index < size && index >= 0)					
	{
		if (index == 0)			// Reusing existing methods for boundary cases.
			pushFront(value);
		else if (index == size)
			pushBack(value);
		else
		{
			size++;
			int *tempArray = new int[size]; 

			*(tempArray + index) = value;
			
			// Copying contents of the old array in two parts:
			// 1) Elements: 0->index (left inclusive right exclusive)
			// 2) Rest of the array
			memcpy(tempArray, dArray, index * sizeof(int));		
			memcpy(tempArray + index + 1, dArray + index, (size - index) * sizeof(int));	

			// Updating the array pointer.
			delete[] dArray;				
			dArray = tempArray;				

			return;
		}
	}
}
void DArray::popFront()
{
	if (size > 0)
	{
		// Copying elements from the old array into the new shrinked array.
		// The first element is left out, hence dArray + 1 in memcpy.
		size--;
		int *tempArray = new int[size];

		memcpy(tempArray, dArray + 1, size * sizeof(int));

		// Updating the array pointer.
		delete[] dArray;
		dArray = tempArray;

		return;
	}
	else
		throw EmptyArrException();
}
void DArray::popBack()
{
	if (size > 0)
	{
		// Copying elements from the old array into the new shrinked array.
		// The updated size is passed into memcpy, since the last element is left out.

		size--;
		int *tempArray = new int[size];

		memcpy(tempArray, dArray, size * sizeof(int));

		delete[] dArray;
		dArray = tempArray;

		return;
	}
	else
		throw EmptyArrException();
}
void DArray::popAt(int index)
{
	if (dArray == nullptr)
		throw EmptyArrException();
	// Reusing existing methods for boundary cases.
	if (index == 0)				
		popFront();
	else if (index == size - 1)
		popBack();
	else if (index < size && index > 0)
	{
		size--;
		int *tempArray = new int[size];					
		
		// Important bit: second memcpy contains (size - index + 1) to compensate for size shrinking.
		// Without it the last element of the array is left out.
		memcpy(tempArray, dArray, index * sizeof(int));
		memcpy(tempArray + index + 1, dArray, (size - index + 1) * sizeof(int));
		
		delete[] dArray;	
		dArray = tempArray;	
	}
}
std::string DArray::toString()
{
	std::string output = "|"; // First character

	if (size > 0)
		for (auto arrIt = dArray; (int*)arrIt - (int*)dArray < size; ++arrIt)
			output += *arrIt + '|';
	else
		throw EmptyArrException();
}
int DArray::lookUpIndex(int index)
{
	if (size == 0)
		throw EmptyArrException();
	else if (index <size && index > 0)
	{
		return *((this->dArray) + index);
	}
}
int DArray::lookUpValue(int value)
{
	if (size == 0)
		throw EmptyArrException();
	else
	{
		int counter = 0;
		while (counter < size)
		{
			if (*((this->dArray) + counter) == value)
				return counter;
		}
	}
}
void DArray::loadFromFile(std::string fileName)
{
	std::ifstream fileToRead;
	std::string line;
	int value = 0;
	
	// All exceptions are rethrown for the caller to handle it or call apropriate handlers.
	// In case of any error the input data is unusable, so there is no point in continuing.

	try {

		fileToRead.open(fileName);

		while (!fileToRead.eof())
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
			catch (...)
			{
				fileToRead.close();
				throw;
			}
			this->pushBack(value);
		}
	}
	catch (std::ios_base::failure &fail)
	{
		throw;
	}

	fileToRead.close();
}
void DArray::saveToFile(std::string fileName)
{
	std::ofstream fileToWrite;
	int * ptr = this->dArray;

	try
	{
		fileToWrite.open(fileName);

		for (int arrIt = 0; arrIt < this->size; ++arrIt)
			fileToWrite << *(ptr + arrIt);
	}
	catch (std::ios_base::failure &fail)
	{
		throw;
	}
	fileToWrite.close();
}
DArray::~DArray()
{
	delete [] this->dArray;
}
